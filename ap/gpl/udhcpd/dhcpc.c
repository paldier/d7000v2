/* dhcpc.c
 *
 * udhcp DHCP client
 *
 * Russ Dill <Russ.Dill@asu.edu> July 2001
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/file.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <sys/sysinfo.h>

#include "dhcpd.h"
#include "dhcpc.h"
#include "options.h"
#include "clientpacket.h"
#include "packet.h"
#include "script.h"
#include "socket.h"
#include "debug.h"
#include "pidfile.h"


#define cprintf(fmt, args...) do { \
  FILE *fp = fopen("/dev/console", "w"); \
  if (fp) { \
    fprintf(fp, fmt , ## args); \
    fclose(fp); \
  } \
} while (0)


static int state;
static unsigned long requested_ip; /* = 0 */
static unsigned long server_addr;
static unsigned long timeout = 0;;
static int packet_num; /* = 0 */
static int fd;
static int signal_pipe[2];

static unsigned long packet_num_Fox=0; /* = 0 */

#define LISTEN_NONE 0
#define LISTEN_KERNEL 1
#define LISTEN_RAW 2
//static int listen_mode;
static int listen_mode = LISTEN_NONE;/* Foxconn modified by Max Ding, 04/12/2008 @dhcp_issue_of_KO */
static int run_on_lan = 0;	/* Foxconn added pling 02/24/2011 */

char option60_venderId[64] = "";/* Foxconn modified by Silver, 09/19/2014 @option60 */

#define DEFAULT_SCRIPT	"/usr/share/udhcpc/default.script"

struct client_config_t client_config = {
	/* Default options. */
	abort_if_no_lease: 0,
	foreground: 0,
	quit_after_lease: 0,
	background_if_no_lease: 0,
	interface: "eth0",
	pidfile: NULL,
	script: DEFAULT_SCRIPT,
	clientid: NULL,
	hostname: NULL,
	ifindex: 0,
	arp: "\0\0\0\0\0\0",		/* appease gcc-3.0 */
};

/* Foxconn add start, Max Ding, 04/12/2008 for @dhcp_issue_of_KO */
#define MAJOR_NUM 100
#define AG_MAX_ARG_CNT	    32
#define DEVICE_FILE_NAME "acos_nat_cli"
#define DEV_FILE_NAME_W_PATH    "/dev/"DEVICE_FILE_NAME
#define IOCTL_AG_FW_LISTEN_PORT_SET         _IOR(MAJOR_NUM, 61, char *)
#define DEV_LISTEN_PORT_DHCPC   5       /* DHCP listen port: 68 */

typedef struct agIoctlParamPackage
{  
    int        paramCnt; 
    int       paramLen[AG_MAX_ARG_CNT];  
    void*   param[AG_MAX_ARG_CNT];
    
} T_agIoctlParamPkg;

static int agApi_setDeviceListenPort(int port_idx, int port_num, int enable)
{
   	int ret_val=0, file_desc;
	T_agIoctlParamPkg paramPkg;

    file_desc = open(DEV_FILE_NAME_W_PATH, O_RDWR);
	if (file_desc < 0) 
	{
        return 0;
	}
    
    memset(&paramPkg, 0, sizeof(paramPkg));
    paramPkg.paramCnt = 3;
    paramPkg.param[0] = (void *)port_idx;
    paramPkg.param[1] = (void *)port_num;
    paramPkg.param[2] = (void *)enable;
    
	ret_val = ioctl(file_desc, IOCTL_AG_FW_LISTEN_PORT_SET, &paramPkg);

    close(file_desc);
    
    if (paramPkg.paramCnt <= -1)
        return paramPkg.paramCnt;
    
    return ret_val; 
}
/* Foxconn add end, Max Ding, 04/12/2008 */


#ifndef BB_VER
static void show_usage(void)
{
	printf(
"Usage: udhcpc [OPTIONS]\n\n"
"  -c, --clientid=CLIENTID         Client identifier\n"
"  -H, --hostname=HOSTNAME         Client hostname\n"
"  -h                              Alias for -H\n"
"  -f, --foreground                Do not fork after getting lease\n"
"  -b, --background                Fork to background if lease cannot be\n"
"                                  immediately negotiated.\n"
"  -i, --interface=INTERFACE       Interface to use (default: eth0)\n"
"  -n, --now                       Exit with failure if lease cannot be\n"
"                                  immediately negotiated.\n"
"  -p, --pidfile=file              Store process ID of daemon in file\n"
"  -q, --quit                      Quit after obtaining lease\n"
"  -r, --request=IP                IP address to request (default: none)\n"
"  -s, --script=file               Run file at dhcp events (default:\n"
"                                  " DEFAULT_SCRIPT ")\n"
"  -v, --version                   Display version\n"
	);
	exit(0);
}
#endif


/* just a little helper */
static void change_mode(int new_mode)
{
	DEBUG(LOG_INFO, "entering %s listen mode",
		new_mode ? (new_mode == 1 ? "kernel" : "raw") : "none");
	close(fd);
	fd = -1;
	/* Foxconn add start, Max Ding, 04/12/2008 for @dhcp_issue_of_KO */
	if (new_mode == LISTEN_NONE)
	{
	    if (listen_mode != LISTEN_NONE)
	        agApi_setDeviceListenPort(DEV_LISTEN_PORT_DHCPC, 68, 0);
	}
	else
	{
	    if (listen_mode == LISTEN_NONE)
	        agApi_setDeviceListenPort(DEV_LISTEN_PORT_DHCPC, 68, 1);
	}
	/* Foxconn add end, Max Ding, 04/12/2008 */
	listen_mode = new_mode;
}


/* perform a renew */
static void perform_renew(void)
{
	LOG(LOG_INFO, "Performing a DHCP renew");
	switch (state) {
	case BOUND:
		change_mode(LISTEN_KERNEL);
	case RENEWING:
	case REBINDING:
		state = RENEW_REQUESTED;
		break;
	case RENEW_REQUESTED: /* impatient are we? fine, square 1 */
		run_script(NULL, "deconfig");
	case REQUESTING:
	case RELEASED:
		change_mode(LISTEN_RAW);
		state = INIT_SELECTING;
		break;
	case INIT_SELECTING:
		break;
	}

	/* start things over */
	packet_num = 0;
  packet_num_Fox = 0;
	/* Kill any timeouts because the user wants this to hurry along */
	timeout = 0;
}


/* perform a release */
static void perform_release(void)
{
	char buffer[16];
	struct in_addr temp_addr;

	/* send release packet */
	if (state == BOUND || state == RENEWING || state == REBINDING || state == RENEW_REQUESTED) {
		temp_addr.s_addr = server_addr;
		sprintf(buffer, "%s", inet_ntoa(temp_addr));
		temp_addr.s_addr = requested_ip;
		LOG(LOG_INFO, "Unicasting a release of %s to %s", 
				inet_ntoa(temp_addr), buffer);
		send_release(server_addr, requested_ip); /* unicast */
		run_script(NULL, "deconfig");
	}
	LOG(LOG_INFO, "Entering released state");

	change_mode(LISTEN_NONE);
	state = RELEASED;
	timeout = 0x7fffffff;
}


/* Exit and cleanup */
static void exit_client(int retval)
{
	/* Foxconn added start pling 02/07/2012 */
	/* WNDR4000 #TD53: GRC test port 68 is not closed.
	 * Force disable NAT device list port for port 68, before we termiante */
	if (listen_mode != LISTEN_NONE)
		change_mode(LISTEN_NONE);
	/* Foxconn added end pling 02/07/2012 */

	pidfile_delete(client_config.pidfile);
	CLOSE_LOG();
	exit(retval);
}


/* Signal handler */
static void signal_handler(int sig)
{
	if (write(signal_pipe[1], &sig, sizeof(sig)) < 0) {
		LOG(LOG_ERR, "Could not send signal: %s",
			strerror(errno));
	}
}


static void background(void)
{
	int pid_fd;

	pid_fd = pidfile_acquire(client_config.pidfile); /* hold lock during fork. */
	while (pid_fd >= 0 && pid_fd < 3) pid_fd = dup(pid_fd); /* don't let daemon close it */
	if (daemon(0, 0) == -1) {
		perror("fork");
		exit_client(1);
	}
	client_config.foreground = 1; /* Do not fork again. */
	pidfile_write_release(pid_fd);
}


#ifdef COMBINED_BINARY
int udhcpc_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
	unsigned char *temp, *message;
	unsigned long t1 = 0, t2 = 0, xid = 0;
	unsigned long start = 0, lease;
	fd_set rfds;
	int retval;
	struct timeval tv;
	int c, len;
	/* Foxconn modify start, Max Ding, 06/11/2010 fix memory overwrite issue */
	/* struct dhcpMessage packet; */
	struct udp_dhcp_packet_rcv packet;
	/* Foxconn modify end, Max Ding, 06/11/2010 */
	struct in_addr temp_addr;
	int pid_fd;
	time_t now;
	int max_fd;
	int sig;
    unsigned long curr_time;
    struct sysinfo info;

	/* Foxconn added start pling 08/06/2012 */
	/* WNDR4500v2 Mantis 2303, per Router Spec,
	 *  restart DHCP client retry process every 5 minutes.
	 */
#define DHCPC_TIMEOUT_RESTART_INTERVAL		300
	int packet_timeout = 1;
	int accumulated_timeout = 0;
	/* Foxconn added end pling 08/06/2012 */

	static struct option arg_options[] = {
		{"clientid",	required_argument,	0, 'c'},
		{"foreground",	no_argument,		0, 'f'},
		{"background",	no_argument,		0, 'b'},
		{"hostname",	required_argument,	0, 'H'},
		{"hostname",    required_argument,      0, 'h'},
		{"interface",	required_argument,	0, 'i'},
		{"now", 	no_argument,		0, 'n'},
		{"pidfile",	required_argument,	0, 'p'},
		{"quit",	no_argument,		0, 'q'},
		{"request",	required_argument,	0, 'r'},
		{"script",	required_argument,	0, 's'},
		{"version",	no_argument,		0, 'v'},
		{"help",	no_argument,		0, '?'},
		{0, 0, 0, 0}
	};

	//memset(option60_venderId, 0, sizeof(option60_venderId)); /* Foxconn modified by Silver, 09/19/2014 @option60 */

	/* get options */
	while (1) {
		int option_index = 0;
		/* Foxconn modified start pling 02/24/2011 */
		/* Add option '-l' to tell this runs on LAN (LAN auto ip) */
		c = getopt_long(argc, argv, "c:fbH:h:i:np:qr:s:o:vl", arg_options, &option_index);
		if (c == -1) break;
		
		switch (c) {
		case 'c':
			len = strlen(optarg) > 255 ? 255 : strlen(optarg);
			if (client_config.clientid) free(client_config.clientid);
			client_config.clientid = xmalloc(len + 2);
			client_config.clientid[OPT_CODE] = DHCP_CLIENT_ID;
			client_config.clientid[OPT_LEN] = len;
			client_config.clientid[OPT_DATA] = '\0';
			strncpy(client_config.clientid + OPT_DATA, optarg, len);
			break;
		case 'f':
			client_config.foreground = 1;
			break;
		case 'b':
			client_config.background_if_no_lease = 1;
			break;
		case 'h':
		case 'H':
			len = strlen(optarg) > 255 ? 255 : strlen(optarg);
			if (client_config.hostname) free(client_config.hostname);
			client_config.hostname = xmalloc(len + 2);
			client_config.hostname[OPT_CODE] = DHCP_HOST_NAME;
			client_config.hostname[OPT_LEN] = len;
			strncpy(client_config.hostname + 2, optarg, len);
			break;
		case 'i':
			client_config.interface =  optarg;
			break;
		case 'n':
			client_config.abort_if_no_lease = 1;
			break;
		case 'p':
			client_config.pidfile = optarg;
			break;
		case 'q':
			client_config.quit_after_lease = 1;
			break;
		case 'r':
			requested_ip = inet_addr(optarg);
			break;
		case 's':
		    LOG(LOG_INFO, "script (%s)\n", optarg);
			client_config.script = optarg;
			break;
/* Foxconn modified start by Silver, 09/19/2014 @option60 */
		case 'o':
			len = strlen(optarg) > 63 ? 63 : strlen(optarg);
			strncpy(option60_venderId, optarg, len);
			break;
/* Foxconn modified ebd by Silver, 09/19/2014 @option60 */			
		case 'v':
			printf("udhcpcd, version %s\n\n", VERSION);
			exit_client(0);
			break;
		/* Foxconn added start pling 02/24/2011 */
		/* LAN Auto IP changes */
		case 'l':
			run_on_lan = 1;
			LOG(LOG_INFO, "run on LAN!\n");
			break;
		/* Foxconn added end pling 02/24/2011 */
		default:
			show_usage();
		}
	}

	OPEN_LOG("udhcpc");
	LOG(LOG_INFO, "udhcp client (v%s) started", VERSION);

	pid_fd = pidfile_acquire(client_config.pidfile);
	pidfile_write_release(pid_fd);

	if (read_interface(client_config.interface, &client_config.ifindex, 
			   NULL, client_config.arp) < 0)
		exit_client(1);
		
	if (!client_config.clientid) {
		client_config.clientid = xmalloc(6 + 3);
		client_config.clientid[OPT_CODE] = DHCP_CLIENT_ID;
		client_config.clientid[OPT_LEN] = 7;
		client_config.clientid[OPT_DATA] = 1;
		memcpy(client_config.clientid + 3, client_config.arp, 6);
	}

	/* ensure that stdin/stdout/stderr are never returned by pipe() */
	if (fcntl(STDIN_FILENO, F_GETFL) == -1)
		(void) open("/dev/null", O_RDONLY);
	if (fcntl(STDOUT_FILENO, F_GETFL) == -1)
		(void) open("/dev/null", O_WRONLY);
	if (fcntl(STDERR_FILENO, F_GETFL) == -1)
		(void) open("/dev/null", O_WRONLY);	

	/* setup signal handlers */
	pipe(signal_pipe);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGTERM, signal_handler);
	
	state = INIT_SELECTING;
	run_script(NULL, "deconfig");
	change_mode(LISTEN_RAW);

	for (;;) {

        sysinfo(&info);
        curr_time = (unsigned long)(info.uptime);
        
        if (timeout > curr_time)
    		tv.tv_sec = timeout - curr_time;
        else
    		tv.tv_sec = 0;
		tv.tv_usec = 0;
		FD_ZERO(&rfds);

		if (listen_mode != LISTEN_NONE && fd < 0) {
			if (listen_mode == LISTEN_KERNEL)
				fd = listen_socket(INADDR_ANY, CLIENT_PORT, client_config.interface);
			else
				fd = raw_socket(client_config.ifindex);
			if (fd < 0) {
				LOG(LOG_ERR, "FATAL: couldn't listen on socket, %s", strerror(errno));
				exit_client(0);
			}
		}
		if (fd >= 0) FD_SET(fd, &rfds);
		FD_SET(signal_pipe[0], &rfds);		

		if (tv.tv_sec > 0) {
			DEBUG(LOG_INFO, "Waiting on select...\n");
			max_fd = signal_pipe[0] > fd ? signal_pipe[0] : fd;
			retval = select(max_fd + 1, &rfds, NULL, NULL, &tv);
		} else retval = 0; /* If we already timed out, fall through */

        sysinfo(&info);
		now = (unsigned long)(info.uptime);
		if (retval == 0) {
			/* timeout dropped to zero */
			switch (state) {
			case INIT_SELECTING:
				if (packet_num < 3) {
					if (packet_num == 0)
						xid = random_xid();

					/* send discover packet */
					send_discover(xid, requested_ip); /* broadcast */

          /* foxconn Silver modified start, 10/14/2016 @Foxtel */
					/* foxconn James modified start, 11/12/2008 @new_internet_detection */
					if( packet_num_Fox == 0 )
						  timeout = now + 4;
					else if( packet_num_Fox == 1 )
						  timeout = now + 8;	  
					else if( packet_num_Fox == 2 )
						  timeout = now + 16;	  
					else if( packet_num_Fox == 3 )
						  timeout = now + 32;	  
					else	 
						  timeout = now + 64; 
/*					
#ifdef NEW_WANDETECT
					timeout = now + ((packet_num == 2) ? 4 : 3);
#else
					timeout = now + ((packet_num == 2) ? 4 : 2);
#endif
*/
					/* foxconn James modified end, 11/12/2008 @new_internet_detection */
          /* foxconn Silver modified end, 10/14/2016 @Foxtel */
          
					packet_num++;
					packet_num_Fox++;
				} else {
					if (client_config.background_if_no_lease) {
						LOG(LOG_INFO, "No lease, forking to background.");
						background();
					} else if (client_config.abort_if_no_lease) {
						LOG(LOG_INFO, "No lease, failing.");
						exit_client(1);
				  	}
					/* wait to try again */
					/* Foxconn modified start pling 08/06/2012 */
					/* WNDR4500v2 Mantis 2303.
					 * Per Router Spec, restart DHCP client retry process every 5 minutes.
					 * However, AP mode DHCP client is not changed. 
					 */
					if (!run_on_lan) {
						send_discover(xid, requested_ip); /* broadcast */

						packet_timeout <<= 1;
						if (accumulated_timeout + packet_timeout >= DHCPC_TIMEOUT_RESTART_INTERVAL) {
							packet_timeout = DHCPC_TIMEOUT_RESTART_INTERVAL - accumulated_timeout;
							packet_num = 0;
						} 
						timeout = now + packet_timeout;
						accumulated_timeout += packet_timeout;
					} else {
						packet_num = 0;
						timeout = now + 60;
					}
					/* Foxconn modified end pling 08/06/2012 */

					/* Foxconn added start pling 02/24/2011 */
					/* No lease found yet, signal 'autoipd'
					 * to start Auto IP process */
					if (run_on_lan) {
						system("killall -SIGUSR1 autoipd 2>/dev/null");
						/* Per Netgear Router Spec 2.0, need to resend
						 * DHCP Discover every 4 minutes.
						 */
						timeout = now + 240;
					}
					/* Foxconn added end pling 02/24/2011 */
				}
				break;
			case RENEW_REQUESTED:
			case REQUESTING:
				if (packet_num < 3) {
					/* send request packet */
					if (state == RENEW_REQUESTED)
						send_renew(xid, server_addr, requested_ip); /* unicast */
					else send_selecting(xid, server_addr, requested_ip); /* broadcast */
					
					timeout = now + ((packet_num == 2) ? 10 : 2);
					packet_num++;
				} else {
					/* timed out, go back to init state */
					if (state == RENEW_REQUESTED) run_script(NULL, "deconfig");
					state = INIT_SELECTING;
					timeout = now;
					packet_num = 0;
					change_mode(LISTEN_RAW);
				}
				break;
			case BOUND:
				/* Lease is starting to run out, time to enter renewing state */
				state = RENEWING;
				change_mode(LISTEN_KERNEL);
				DEBUG(LOG_INFO, "Entering renew state");
				/* fall right through */
			case RENEWING:
				/* Either set a new T1, or enter REBINDING state */
				if ((t2 - t1) <= (lease / 14400 + 1)) {
					/* timed out, enter rebinding state */
					state = REBINDING;
					timeout = now + (t2 - t1);
					DEBUG(LOG_INFO, "Entering rebinding state");
				} else {
					/* send a request packet */
					send_renew(xid, server_addr, requested_ip); /* unicast */
					
					t1 = (t2 - t1) / 2 + t1;
					timeout = t1 + start;
				}
				break;
			case REBINDING:
				/* Either set a new T2, or enter INIT state */
				if ((lease - t2) <= (lease / 14400 + 1)) {
					/* timed out, enter init state */
					state = INIT_SELECTING;
					LOG(LOG_INFO, "Lease lost, entering init state");
					run_script(NULL, "deconfig");
					timeout = now;
					packet_num = 0;
					change_mode(LISTEN_RAW);
				} else {
					/* send a request packet */
					send_renew(xid, 0, requested_ip); /* broadcast */

					t2 = (lease - t2) / 2 + t2;
					timeout = t2 + start;
				}
				break;
			case RELEASED:
				/* yah, I know, *you* say it would never happen */
				timeout = 0x7fffffff;
				break;
			}
		} else if (retval > 0 && listen_mode != LISTEN_NONE && FD_ISSET(fd, &rfds)) {
			/* a packet is ready, read it */
			
			/* Foxconn modify start, Max Ding, 06/11/2010 */
			if (listen_mode == LISTEN_KERNEL)
				/* len = get_packet(&packet, fd); */
				len = get_packet(&packet.data, fd);
			/* else len = get_raw_packet(&packet, fd); */
			else len = get_raw_packet(&packet.data, fd);
			/* Foxconn modify start, Max Ding, 06/11/2010 */
			
			if (len == -1 && errno != EINTR) {
				DEBUG(LOG_INFO, "error on read, %s, reopening socket", strerror(errno));
				change_mode(listen_mode); /* just close and reopen */
			}
			if (len < 0) continue;
			
			/* Foxconn modify start, Max Ding, 06/11/2010 */
			/* if (packet.xid != xid) { */
			if (packet.data.xid != xid) {
				DEBUG(LOG_INFO, "Ignoring XID %lx (our xid is %lx)",
					/* (unsigned long) packet.xid, xid); */
					(unsigned long) packet.data.xid, xid);
				continue;
			}
			
			/* if ((message = get_option(&packet, DHCP_MESSAGE_TYPE)) == NULL) { */
			if ((message = get_option(&packet.data, DHCP_MESSAGE_TYPE)) == NULL) {
				DEBUG(LOG_ERR, "couldnt get option from packet -- ignoring");
				continue;
			}
			/* Foxconn modify end, Max Ding, 06/11/2010 */
			
			switch (state) {
			case INIT_SELECTING:
				/* Must be a DHCPOFFER to one of our xid's */
				/* Foxconn modify start, Max Ding, 06/11/2010 */
				if (*message == DHCPOFFER) {
					/* if ((temp = get_option(&packet, DHCP_SERVER_ID))) { */
					if ((temp = get_option(&packet.data, DHCP_SERVER_ID))) {
						memcpy(&server_addr, temp, 4);
						/* xid = packet.xid;
						requested_ip = packet.yiaddr; */
						xid = packet.data.xid;
						requested_ip = packet.data.yiaddr;
						/* enter requesting state */
						state = REQUESTING;
						timeout = now;
						packet_num = 0;
					} else {
						DEBUG(LOG_ERR, "No server ID in message");
					}
				}
				/* Foxconn modify end, Max Ding, 06/11/2010 */
				break;
			case RENEW_REQUESTED:
			case REQUESTING:
			case RENEWING:
			case REBINDING:
				if (*message == DHCPACK) {
					/* Foxconn modify start, Max Ding, 06/11/2010 */
					/* if (!(temp = get_option(&packet, DHCP_LEASE_TIME))) { */
					if (!(temp = get_option(&packet.data, DHCP_LEASE_TIME))) {
					/* Foxconn modify end, Max Ding, 06/11/2010 */
						LOG(LOG_ERR, "No lease time with ACK, using 1 hour lease");
						lease = 60 * 60;
					} else {
						memcpy(&lease, temp, 4);
						lease = ntohl(lease);
					}
						
					/* wklin added start, 08/10/2007 */
					/* check before entering requesting state */
					/* Foxconn modify start, Max Ding, 06/11/2010 */
					/* Foxconn modified start pling 05/27/2010 */
					u_int32_t addr_to_arp;
					if (state == REQUESTING)
						addr_to_arp = 0;
					else
						addr_to_arp = requested_ip;
					/* if (arpping(packet.yiaddr, 0, */
					if (arpping(packet.data.yiaddr, addr_to_arp, 
					/* Foxconn modified end pling 05/27/2010 */
								client_config.arp, client_config.interface)==0) {
						/* send_decline(packet.xid, server_addr, packet.yiaddr); *//* broadcast */
						send_decline(packet.data.xid, server_addr, packet.data.yiaddr); /* broadcast */
						/* return to init state */
						state = INIT_SELECTING;
						timeout = now;
						requested_ip = 0;
						packet_num = 0;
						change_mode(LISTEN_RAW);
						sleep(10); /* per the RFC, avoid excessive network traffic */
						break;
					}
					/* Foxconn modify end, Max Ding, 06/11/2010 */
					/* wklin added end, 08/10/2007 */
					/* enter bound state */
					t1 = lease / 2;
					
					/* little fixed point for n * .875 */
					t2 = (lease * 0x7) >> 3;
					/* Foxconn modify start, Max Ding, 06/11/2010 */
					/* temp_addr.s_addr = packet.yiaddr; */
					temp_addr.s_addr = packet.data.yiaddr;
					LOG(LOG_INFO, "Lease of %s obtained, lease time %ld", 
						inet_ntoa(temp_addr), lease);
					start = now;
					timeout = t1 + start;
					/* requested_ip = packet.yiaddr; */
					requested_ip = packet.data.yiaddr;
					remove("/tmp/udhcpc.routes");/*foxconn added, water, 03/08/10, @option249*/
					/* run_script(&packet, */
					run_script(&packet.data,
						   ((state == RENEWING || state == REBINDING) ? "renew" : "bound"));
					/* Foxconn modify end, Max Ding, 06/11/2010 */

					state = BOUND;
					change_mode(LISTEN_NONE);
					if (client_config.quit_after_lease) 
						exit_client(0);
					if (!client_config.foreground)
						background();

				} else if (*message == DHCPNAK) {
					/* return to init state */
					LOG(LOG_INFO, "Received DHCP NAK");
					/* run_script(&packet, "nak"); */
					run_script(&packet.data, "nak");/* Foxconn modified by Max Ding, 06/11/2010 */
					if (state != REQUESTING)
						run_script(NULL, "deconfig");
					state = INIT_SELECTING;
					timeout = now;
					requested_ip = 0;
					packet_num = 0;
					change_mode(LISTEN_RAW);
					sleep(3); /* avoid excessive network traffic */
				}
				break;
			/* case BOUND, RELEASED: - ignore all packets */
			}	
		} else if (retval > 0 && FD_ISSET(signal_pipe[0], &rfds)) {
			if (read(signal_pipe[0], &sig, sizeof(sig)) < 0) {
				DEBUG(LOG_ERR, "Could not read signal: %s", 
					strerror(errno));
				continue; /* probably just EINTR */
			}
			switch (sig) {
			case SIGUSR1: 
				perform_renew();
				break;
			case SIGUSR2:
				perform_release();
				break;
			case SIGTERM:
				LOG(LOG_INFO, "Received SIGTERM");
				exit_client(0);
			}
		} else if (retval == -1 && errno == EINTR) {
			/* a signal was caught */		
		} else {
			/* An error occured */
			DEBUG(LOG_ERR, "Error on select");
		}
		
	}
	return 0;
}


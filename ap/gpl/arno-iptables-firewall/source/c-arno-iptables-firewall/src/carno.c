//**************************************************************
//* Automatically generated from arno-iptables-firewall_2.0.0a 
//* Mon Feb 25 13:57:46 IST 2013
//* License - same as original
//**************************************************************
//ExcludeFunc - main_start,load_modules,sanity_check,check_for_base_chains,plugins_start,plugins_stop,plugins_status,show_status,show_help,main_stop,main_restart,sysctl_multi,sysctl,sysctl_set_all
//Excluded func - sanity_check
//Excluded func - load_modules
//Excluded func - check_for_base_chains
//Excluded func - plugins_start
//Excluded func - plugins_stop
//Excluded func - plugins_status
//Excluded func - show_status
//Excluded func - show_help
//Excluded func - main_stop
//Excluded func - main_start
//Excluded func - main_restart
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carnoutils.h"

/* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>


extern char *get_ifs(char *, char *);
extern char *get_ips(char *, char *);
extern char *get_hosts_ih(char *, char *);
extern char *get_hosts_ihp(char *, char *);
extern char *get_ports_ihp(char *, char *);
extern char *get_hosts_hp(char *, char *);
extern char *get_ports_hp(char *, char *);
extern char *get_ports_ip(char *, char *);
extern char *ip_range(char *, char *);
extern char *show_if_ip(char *, char *);
extern char *show_hosts_ports(char *, char *);
extern char *partial_ip4(char *, int, int, int, int);
extern int check_interface(char *in_ifc);
extern int ip4tables(char *inarg, ...);
extern int ip6tables(char *inarg, ...);
extern int iptables(char *inarg, ...);
extern int ip4tables_batch(char *inarg, ...);
extern int ip6tables_batch(char *inarg, ...);
extern int iptables_batch(char *inarg, ...);
extern void create_user_chains(void);
extern int get_numeric_ip_version(char *arg1);
extern void plugins_start(void);
extern void source(char *filename);
extern void sysctl_multi(char *inarg1, ...);
extern int sysctl(char *inarg1, ...);
extern int sysctl_set_all(char *prefix, char *variable, char *value);
char *IFS = " ";
char *INDENT = NULL;
char *FIREWALL_LOG = NULL;
FILE *FIREWALL_LOG_FILE = NULL;
char *ANYHOST = NULL;
char *ANYPORT = NULL;
char *BAD_FLAGS_LOG = NULL;
char *BLOCKED_HOST_LOG = NULL;
char *BLOCK_HOSTS = NULL;
char *BLOCK_HOSTS_BIDIRECTIONAL = NULL;
char *BLOCK_HOSTS_FILE = NULL;
char *BROADCAST_TCP_NOLOG = NULL;
char *BROADCAST_UDP_NOLOG = NULL;
char *CONNTRACK = NULL;
char *COUNT = NULL;
char *CUSTOM_RULES = NULL;
char *DATE = NULL;
char *DEFAULT_POLICY_DROP = NULL;
char *DEFAULT_TTL = NULL;
char *DENY_IP_OUTPUT = NULL;
char *DENY_TCP = NULL;
char *DENY_TCP_NOLOG = NULL;
char *DENY_TCP_OUTPUT = NULL;
char *DENY_UDP = NULL;
char *DENY_UDP_NOLOG = NULL;
char *DENY_UDP_OUTPUT = NULL;
char *DMESG_PANIC_ONLY = NULL;
char *DMZ_HOST_OPEN_IP = NULL;
char *DMZ_HOST_OPEN_TCP = NULL;
char *DMZ_HOST_OPEN_UDP = NULL;
char *DMZ_IF = NULL;
char *DMZ_INET_DENY_IP = NULL;
char *DMZ_INET_DENY_TCP = NULL;
char *DMZ_INET_DENY_UDP = NULL;
char *DMZ_INET_HOST_DENY_IP = NULL;
char *DMZ_INET_HOST_DENY_TCP = NULL;
char *DMZ_INET_HOST_DENY_UDP = NULL;
char *DMZ_INET_HOST_OPEN_IP = NULL;
char *DMZ_INET_HOST_OPEN_TCP = NULL;
char *DMZ_INET_HOST_OPEN_UDP = NULL;
char *DMZ_INET_OPEN_ICMP = NULL;
char *DMZ_INET_OPEN_IP = NULL;
char *DMZ_INET_OPEN_TCP = NULL;
char *DMZ_INET_OPEN_UDP = NULL;
char *DMZ_INPUT_DENY_LOG = NULL;
char *DMZ_LAN_HOST_OPEN_IP = NULL;
char *DMZ_LAN_HOST_OPEN_TCP = NULL;
char *DMZ_LAN_HOST_OPEN_UDP = NULL;
char *DMZ_LAN_OPEN_ICMP = NULL;
char *DMZ_NET = NULL;
char *DMZ_NET_ANTISPOOF = NULL;
char *DMZ_OPEN_ICMP = NULL;
char *DMZ_OPEN_IP = NULL;
char *DMZ_OPEN_TCP = NULL;
char *DMZ_OPEN_UDP = NULL;
char *DMZ_OUTPUT_DENY_LOG = NULL;
char *DRDOS_PROTECT = NULL;
char *DROP_PRIVATE_ADDRESSES = NULL;
char *ECHO_IGNORE = NULL;
char *ECN = NULL;
char *EOL = NULL;
char *EXTERNAL_DHCPV6_SERVER = NULL;
char *EXTERNAL_DHCP_SERVER = NULL;
char *EXTERNAL_NET = NULL;
char *EXTIF_NET = NULL;
char *EXT_IF = NULL;
char *EXT_IF_DHCP_IP = NULL;
char *EXT_NET_BCAST_ADDRESS = NULL;
char *FORWARD_DROP_LOG = NULL;
char *FORWARD_LINK_LOCAL = NULL;
char *FRAG_LOG = NULL;
char *FULL_ACCESS_HOSTS = NULL;
char *HOST_DENY_ICMP = NULL;
char *HOST_DENY_ICMP_NOLOG = NULL;
char *HOST_DENY_IP = NULL;
char *HOST_DENY_IP_NOLOG = NULL;
char *HOST_DENY_IP_OUTPUT = NULL;
char *HOST_DENY_TCP = NULL;
char *HOST_DENY_TCP_NOLOG = NULL;
char *HOST_DENY_TCP_OUTPUT = NULL;
char *HOST_DENY_UDP = NULL;
char *HOST_DENY_UDP_NOLOG = NULL;
char *HOST_DENY_UDP_OUTPUT = NULL;
char *HOST_OPEN_ICMP = NULL;
char *HOST_OPEN_IP = NULL;
char *HOST_OPEN_TCP = NULL;
char *HOST_OPEN_UDP = NULL;
char *HOST_REJECT_TCP = NULL;
char *HOST_REJECT_TCP_NOLOG = NULL;
char *HOST_REJECT_UDP = NULL;
char *HOST_REJECT_UDP_NOLOG = NULL;
char *ICMPV6_SPECIAL_TYPES = NULL;
char *ICMP_DROP_LOG = NULL;
char *ICMP_FLOOD_LOG = NULL;
char *ICMP_OTHER_LOG = NULL;
char *ICMP_REDIRECT = NULL;
char *ICMP_REQUEST_LOG = NULL;
char *IF_TRUSTS = NULL;
char *IGMP_LOG = NULL;
char *INET_DMZ_DENY_IP = NULL;
char *INET_DMZ_DENY_TCP = NULL;
char *INET_DMZ_DENY_UDP = NULL;
char *INET_DMZ_HOST_DENY_IP = NULL;
char *INET_DMZ_HOST_DENY_TCP = NULL;
char *INET_DMZ_HOST_DENY_UDP = NULL;
char *INET_DMZ_HOST_OPEN_IP = NULL;
char *INET_DMZ_HOST_OPEN_TCP = NULL;
char *INET_DMZ_HOST_OPEN_UDP = NULL;
char *INET_DMZ_OPEN_ICMP = NULL;
char *INET_DMZ_OPEN_IP = NULL;
char *INET_DMZ_OPEN_TCP = NULL;
char *INET_DMZ_OPEN_UDP = NULL;
char *INET_FORWARD_IP = NULL;
char *INET_FORWARD_TCP = NULL;
char *INET_FORWARD_UDP = NULL;
char *INET_OUTPUT_DENY_LOG = NULL;
char *INTERNAL_NET = NULL;
char *INTERNAL_NET_ANTISPOOF = NULL;
char *INT_IF = NULL;
char *INVALID_ICMP_LOG = NULL;
char *INVALID_TCP_LOG = NULL;
char *INVALID_UDP_LOG = NULL;
char *IPTABLES_ERROR = NULL;
char *IPV6_AUTO_CONFIGURATION = NULL;
char *IPV6_DETECTED = NULL;
char *IPV6_SUPPORT = NULL;
char *IP_FORWARDING = NULL;
char *LAN_DENY_IP = NULL;
char *LAN_DENY_TCP = NULL;
char *LAN_DENY_UDP = NULL;
char *LAN_HOST_DENY_IP = NULL;
char *LAN_HOST_DENY_TCP = NULL;
char *LAN_HOST_DENY_UDP = NULL;
char *LAN_HOST_OPEN_IP = NULL;
char *LAN_HOST_OPEN_TCP = NULL;
char *LAN_HOST_OPEN_UDP = NULL;
char *LAN_INET_DENY_IP = NULL;
char *LAN_INET_DENY_TCP = NULL;
char *LAN_INET_DENY_UDP = NULL;
char *LAN_INET_HOST_DENY_IP = NULL;
char *LAN_INET_HOST_DENY_TCP = NULL;
char *LAN_INET_HOST_DENY_UDP = NULL;
char *LAN_INET_HOST_OPEN_IP = NULL;
char *LAN_INET_HOST_OPEN_TCP = NULL;
char *LAN_INET_HOST_OPEN_UDP = NULL;
char *LAN_INET_OPEN_ICMP = NULL;
char *LAN_INET_OPEN_IP = NULL;
char *LAN_INET_OPEN_TCP = NULL;
char *LAN_INET_OPEN_UDP = NULL;
char *LAN_INPUT_DENY_LOG = NULL;
char *LAN_OPEN_ICMP = NULL;
char *LAN_OPEN_IP = NULL;
char *LAN_OPEN_TCP = NULL;
char *LAN_OPEN_UDP = NULL;
char *LAN_OUTPUT_DENY_LOG = NULL;
char *LINK_LOCAL_DROP_LOG = NULL;
char *LOCAL_PORT_RANGE = NULL;
char *LOGLEVEL = NULL;
char *LOG_HOST_INPUT = NULL;
char *LOG_HOST_INPUT_IP = NULL;
char *LOG_HOST_INPUT_TCP = NULL;
char *LOG_HOST_INPUT_UDP = NULL;
char *LOG_HOST_OUTPUT = NULL;
char *LOG_HOST_OUTPUT_IP = NULL;
char *LOG_HOST_OUTPUT_TCP = NULL;
char *LOG_HOST_OUTPUT_UDP = NULL;
char *LOG_INPUT_IP = NULL;
char *LOG_INPUT_TCP = NULL;
char *LOG_INPUT_UDP = NULL;
char *LOG_MARTIANS = NULL;
char *LOG_OUTPUT_IP = NULL;
char *LOG_OUTPUT_TCP = NULL;
char *LOG_OUTPUT_UDP = NULL;
char *LOOSE_FORWARD = NULL;
char *LOST_CONNECTION_LOG = NULL;
char *MANGLE_TOS = NULL;
char *MY_VERSION = NULL;
char *NAT = NULL;
char *NAT_FORWARD_IP = NULL;
char *NAT_FORWARD_TCP = NULL;
char *NAT_FORWARD_UDP = NULL;
char *NAT_INTERNAL_NET = NULL;
char *NAT_LOCAL_REDIRECT = NULL;
char *NAT_STATIC_IP = NULL;
char *NMB_BROADCAST_FIX = NULL;
char *NO_PMTU_DISCOVERY = NULL;
char *OPEN_ICMP = NULL;
char *OPEN_ICMPV6 = NULL;
char *OPEN_IP = NULL;
char *OPEN_TCP = NULL;
char *OPEN_UDP = NULL;
char *OTHER_IP_LOG = NULL;
char *PACKET_TTL = NULL;
char *PLUGIN_BIN_PATH = NULL;
char *PLUGIN_CONF_PATH = NULL;
char *PLUGIN_LOAD_FILE_RESTART = NULL;
char *POSSIBLE_SCAN_LOG = NULL;
char *PRIV_TCP_LOG = NULL;
char *PRIV_UDP_LOG = NULL;
char *REDUCE_DOS_ABILITY = NULL;
char *REJECT_TCP = NULL;
char *REJECT_TCP_NOLOG = NULL;
char *REJECT_UDP = NULL;
char *REJECT_UDP_NOLOG = NULL;
char *RESERVED_NET_LOG = NULL;
char *RP_FILTER = NULL;
char *SCAN_LOG = NULL;
char *SEP = NULL;
char *SEP2 = NULL;
char *SEP3 = NULL;
char *SET_MSS = NULL;
char *SOURCE_ROUTE_PROTECTION = NULL;
char *STATIC_IP = NULL;
char *SYN_PROT = NULL;
char *SYSCTL = NULL;
char *TRAFFIC_SHAPING = NULL;
char *TRUSTED_IF = NULL;
char *TTL_INC = NULL;
char *UNPRIV_TCP_LOG = NULL;
char *UNPRIV_UDP_LOG = NULL;

#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
char *DMZ_TCP = NULL;
char *DMZ_UDP = NULL;
char *DMZ_NAT_IP = NULL;
char *PORT_SCAN_DOS_DISABLE = NULL;
char *TRIGGER_TIMEOUT = NULL;
char *FIREWALL_ENABLE = NULL; // Mos 2014/08/20, modify behavior of disable firewall

int getNvValue(char* nvTag, char* nvValue)
{
	int fields[2];
	pid_t pid;

	if (pipe(fields) == -1)
	{
		perror("pipe faied!");
		return 0;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("pipe faied!");
		return 0;
	}
	else if (pid == 0)//child
	{
		close(fields[0]);	
		dup2(fields[1], STDOUT_FILENO);
#if defined(BCA_HNDROUTER) || defined(CONFIG_INTEL_SDK)
		execl("/usr/sbin/nvram", "nvram", "get", nvTag, NULL); // execute ifconfig -a
#else /* !BCA_HNDROUTER */
		execl("/usr/bin/nvram", "nvram", "get", nvTag, NULL); // execute ifconfig -a	
#endif /* !BCA_HNROUTER */		
		perror("execl failed\n");
		close(fields[1]);	
		return 0;
	}
	else	//parent
	{
		char buf[1025];	
		int len;	
		close(fields[1]);	
		dup2(fields[0], STDIN_FILENO);	
		while((len = read(fields[0], buf, 1024)) > 0)  	// read output of ifconfig	
		{	   
			buf[len] = '\0';	    
			//printf("%s", buf);
			//remove newline
			if (len >0 && buf[len-1] == 0x0a)
				buf[len-1] = '\0';

			strcpy(nvValue, buf);
		}	
		wait(NULL);	
		close(fields[0]);	
	}
	return 1;
}
#endif

int ISDIR(char *fname)
{
  struct stat statbuf;

  if ((stat(fname, &statbuf) == 0) && S_ISDIR(statbuf.st_mode))
    return 1;
  else
    return 0;
}

void //config_check()
config_check(void)
//{
{
char *r_INT_IF2 = NULL;;
char *local1IFS = NULL;;
char *r_INT_IF3 = NULL;;
char *local6IFS = NULL;;
char *strtok3_FREE = NULL;;
char *r_EXT_IF1 = NULL;;
char *interface = NULL;;
char *r_EXT_IF2 = NULL;;
char *local2IFS = NULL;;
char *local7IFS = NULL;;
char *r_EXT_IF3 = NULL;;
char *strtok2_FREE = NULL;;
char *iif = NULL;;
char *local8IFS = NULL;;
char *r_TRUSTED_IF1 = NULL;;
char *strtok1_FREE = NULL;;
char *strtok8_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *local3IFS = NULL;;
char *r_DMZ_IF1 = NULL;;
char *strtok7_FREE = NULL;;
char *strtok5_FREE = NULL;;
char *eif = NULL;;
char *local4IFS = NULL;;
char *local5IFS = NULL;;
char *strtok4_FREE = NULL;;
char *r_INT_IF1 = NULL;;

  //# Make sure EXT_IF != ""
  //########################
  //if [ -z "$EXT_IF" ]; then
  if  (  ((EXT_IF==NULL)||(strlen(EXT_IF)==0))  )
  {
    //printf "\033[40m\033[1;31mERROR: The required variable EXT_IF is empty!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: The required variable EXT_IF is empty!\033[0m\n ");
    //printf "\033[40m\033[1;31m       Please, check the configuration file.\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       Please, check the configuration file.\033[0m\n ");
    //exit 2
    exit(2);
  //fi
  }

  //# Check whether EXT_IF exists
  //#############################
  //IFS=' ,'
  IFS=" ,";
  //for interface in $EXT_IF; do
  local1IFS = IFS;
  if (EXT_IF != NULL) strtok1_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (interface = strtok_r(strtok1_FREE, local1IFS, &r_EXT_IF1); interface != NULL; interface = strtok_r(NULL, local1IFS, &r_EXT_IF1))
  {
    //if ! check_interface $interface; then
    if  ( ! check_interface(interface) )
    {
      //printf "\033[40m\033[1;31mWARNING: External interface $interface does NOT exist (yet?)\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mWARNING: External interface %s does NOT exist (yet?)\033[0m\n ", interface);
    //fi
    }
  //done
  }

  //# Check whether INT_IF exists
  //#############################
  //IFS=' ,'
  IFS=" ,";
  //for interface in $INT_IF; do
  local2IFS = IFS;
  if (INT_IF != NULL) strtok2_FREE = strdup(INT_IF);
  if (INT_IF != NULL) for (interface = strtok_r(strtok2_FREE, local2IFS, &r_INT_IF1); interface != NULL; interface = strtok_r(NULL, local2IFS, &r_INT_IF1))
  {
    //if ! check_interface $interface; then
    if  ( ! check_interface(interface) )
    {
      //printf "\033[40m\033[1;31mWARNING: Internal interface $interface does NOT exist (yet?)\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mWARNING: Internal interface %s does NOT exist (yet?)\033[0m\n ", interface);
    //fi
    }
  //done
  }

  //# Check whether DMZ_IF exists
  //#############################
  //IFS=' ,'
  IFS=" ,";
  //for interface in $DMZ_IF; do
  local3IFS = IFS;
  if (DMZ_IF != NULL) strtok3_FREE = strdup(DMZ_IF);
  if (DMZ_IF != NULL) for (interface = strtok_r(strtok3_FREE, local3IFS, &r_DMZ_IF1); interface != NULL; interface = strtok_r(NULL, local3IFS, &r_DMZ_IF1))
  {
    //if ! check_interface $interface; then
    if  ( ! check_interface(interface) )
    {
      //printf "\033[40m\033[1;31mWARNING: DMZ interface $interface does NOT exist (yet?)\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mWARNING: DMZ interface %s does NOT exist (yet?)\033[0m\n ", interface);
    //fi
    }
  //done
  }

  //# Check whether TRUSTED_IF exists
  //#################################
  //IFS=' ,'
  IFS=" ,";
  //for interface in $TRUSTED_IF; do
  local4IFS = IFS;
  if (TRUSTED_IF != NULL) strtok4_FREE = strdup(TRUSTED_IF);
  if (TRUSTED_IF != NULL) for (interface = strtok_r(strtok4_FREE, local4IFS, &r_TRUSTED_IF1); interface != NULL; interface = strtok_r(NULL, local4IFS, &r_TRUSTED_IF1))
  {
    //if ! check_interface $interface; then
    if  ( ! check_interface(interface) )
    {
      //printf "\033[40m\033[1;31mWARNING: Trusted interface $interface does NOT exist (yet?)\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mWARNING: Trusted interface %s does NOT exist (yet?)\033[0m\n ", interface);
    //fi
    }
  //done
  }

  //# Make sure INT_IF != EXT_IF
  //############################
  //IFS=' ,'
  IFS=" ,";
  //for eif in $EXT_IF; do
  local5IFS = IFS;
  if (EXT_IF != NULL) strtok5_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (eif = strtok_r(strtok5_FREE, local5IFS, &r_EXT_IF2); eif != NULL; eif = strtok_r(NULL, local5IFS, &r_EXT_IF2))
  {
    //for iif in $INT_IF; do
    local6IFS = IFS;
    if (INT_IF != NULL) strtok6_FREE = strdup(INT_IF);
    if (INT_IF != NULL) for (iif = strtok_r(strtok6_FREE, local6IFS, &r_INT_IF2); iif != NULL; iif = strtok_r(NULL, local6IFS, &r_INT_IF2))
    {
      //if [ "$iif" = "$eif" ]; then
      if  (  (strcmp(iif,eif)==0)  )
      {
        //printf "\033[40m\033[1;31mERROR: One or more interfaces specified in EXT_IF is the same as one in\033[0m\n" >&2
        fprintf(stderr, "\033[40m\033[1;31mERROR: One or more interfaces specified in EXT_IF is the same as one in\033[0m\n ");
        //printf "\033[40m\033[1;31m       INT_IF! Please, check the configuration file.\033[0m\n" >&2
        fprintf(stderr, "\033[40m\033[1;31m       INT_IF! Please, check the configuration file.\033[0m\n ");
        //exit 3
        exit(3);
      //fi
      }
    //done
    }
  //done
  }

  //# Make sure EXT_IF != lo / 127.0.0.1
  //####################################
  //IFS=' ,'
  IFS=" ,";
  //for eif in $EXT_IF; do
  local7IFS = IFS;
  if (EXT_IF != NULL) strtok7_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (eif = strtok_r(strtok7_FREE, local7IFS, &r_EXT_IF3); eif != NULL; eif = strtok_r(NULL, local7IFS, &r_EXT_IF3))
  {
    //if [ "$eif" = "lo" -o "$eif" = "127.0.0.1" ]; then
    if  (  ((strcmp(eif,"lo")==0)||(strcmp(eif,"127.0.0.1")==0)) )
    {
      //printf "\033[40m\033[1;31mERROR: One or more interfaces specified in EXT_IF has the address or name of the\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mERROR: One or more interfaces specified in EXT_IF has the address or name of the\033[0m\n ");
      //printf "\033[40m\033[1;31m       local loopback device! Please, check the configuration file.\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m       local loopback device! Please, check the configuration file.\033[0m\n ");
      //exit 6
      exit(6);
    //fi
    }
  //done
  }

  //# Make sure INT_IF != lo / 127.0.0.1
  //####################################
  //IFS=' ,'
  IFS=" ,";
  //for iif in $INT_IF; do
  local8IFS = IFS;
  if (INT_IF != NULL) strtok8_FREE = strdup(INT_IF);
  if (INT_IF != NULL) for (iif = strtok_r(strtok8_FREE, local8IFS, &r_INT_IF3); iif != NULL; iif = strtok_r(NULL, local8IFS, &r_INT_IF3))
  {
    //if [ "$iif" = "lo" -o "$iif" = "127.0.0.1" ]; then
    if  (  ((strcmp(iif,"lo")==0)||(strcmp(iif,"127.0.0.1")==0)) )
    {
      //printf "\033[40m\033[1;31mERROR: At least one of the interfaces specified in INT_IF has the address or\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mERROR: At least one of the interfaces specified in INT_IF has the address or\033[0m\n ");
      //printf "\033[40m\033[1;31m       name of the local loopback device! Please, check the configuration file.\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m       name of the local loopback device! Please, check the configuration file.\033[0m\n ");
      //exit 7
      exit(7);
    //fi
    }
  //done
  }

  //# If support for an DHCP server serving an external net is enabled, we
  //# also need to know what the external net is.
  //##########################################################################
  //if [ "$EXTERNAL_DHCP_SERVER" = "1" -a -z "$EXTERNAL_NET" ]; then
  if  (  ((strcmp(EXTERNAL_DHCP_SERVER,"1")==0)&&((EXTERNAL_NET==NULL)||(strlen(EXTERNAL_NET)==0))) )
  {
    //printf "\033[40m\033[1;31mERROR: You have enabled external DHCP server support but required variable\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: You have enabled external DHCP server support but required variable\033[0m\n ");
    //printf "\033[40m\033[1;31m       EXTERNAL_NET has NOT been defined!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       EXTERNAL_NET has NOT been defined!\033[0m\n ");
    //exit 10
    exit(10);
  //fi
  }

  //# We can only perform NAT if NAT_INTERNAL_NET is defined
  //if [ "$NAT" = "1" -a -z "$NAT_INTERNAL_NET" ]; then
  if  (  ((strcmp(NAT,"1")==0)&&((NAT_INTERNAL_NET==NULL)||(strlen(NAT_INTERNAL_NET)==0))) )
  {
    //printf "\033[40m\033[1;31mERROR: Unable to enable NAT because there's no (NAT_)INTERNAL_NET specified!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: Unable to enable NAT because there's no (NAT_)INTERNAL_NET specified!\033[0m\n ");
    //exit 11
    exit(11);
  //fi
  }

  //# If support the nmb_broadcast_fix is enabled we need the EXTERNAL_NET set
  //##########################################################################
  //if [ "$NMB_BROADCAST_FIX" = "1" -a -z "$EXTERNAL_NET" ]; then
  if  (  ((strcmp(NMB_BROADCAST_FIX,"1")==0)&&((EXTERNAL_NET==NULL)||(strlen(EXTERNAL_NET)==0))) )
  {
    //printf "\033[40m\033[1;31mERROR: You have enabled the NMB_BROADCAST_FIX but required variable\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: You have enabled the NMB_BROADCAST_FIX but required variable\033[0m\n ");
    //printf "\033[40m\033[1;31m       EXTERNAL_NET has NOT been defined!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       EXTERNAL_NET has NOT been defined!\033[0m\n ");
    //exit 12
    exit(12);
  //fi
  }

  //# Warn if no_broadcast variables are used and external net is NOT defined
  //##########################################################################
  //if [ -n "$BROADCAST_TCP_NOLOG" -o -n "$BROADCAST_UDP_NOLOG" ]; then
  if  (  (((BROADCAST_TCP_NOLOG!=NULL)&&(strlen(BROADCAST_TCP_NOLOG)!=0))||((BROADCAST_UDP_NOLOG!=NULL)&&(strlen(BROADCAST_UDP_NOLOG)!=0))) )
  {
    //if [ -z "$EXTERNAL_NET" -a -z "$EXT_NET_BCAST_ADDRESS" ]; then
    if  (  (((EXTERNAL_NET==NULL)||(strlen(EXTERNAL_NET)==0))&&((EXT_NET_BCAST_ADDRESS==NULL)||(strlen(EXT_NET_BCAST_ADDRESS)==0))) )
    {
      //printf "\033[40m\033[1;31mWARNING: You are using the BROADCAST_xxx_NOLOG variables but EXTERNAL_NET and EXT_NET_BCAST_ADDRESS\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31mWARNING: You are using the BROADCAST_xxx_NOLOG variables but EXTERNAL_NET and EXT_NET_BCAST_ADDRESS\033[0m\n ");
      //printf "\033[40m\033[1;31m         have NOT been defined!\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m         have NOT been defined!\033[0m\n ");
    //fi
    }
  //fi
  }

  //# Check whether we know the plugin binary path
  //##############################################
  //if [ ! -d "$PLUGIN_BIN_PATH" ]; then
  if  ( !  (ISDIR(PLUGIN_BIN_PATH))  )
  {
    //printf "\033[40m\033[1;31mERROR: The PLUGIN_BIN_PATH ($PLUGIN_BIN_PATH) does not exist!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: The PLUGIN_BIN_PATH (%s) does not exist!\033[0m\n ", PLUGIN_BIN_PATH);
    //printf "\033[40m\033[1;31m       Please check your installation and/or configuration file.\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       Please check your installation and/or configuration file.\033[0m\n ");
    //exit 2
    exit(2);
  //fi
  }

  //# Check whether we know the plugin config path
  //##############################################
  //if [ ! -d "$PLUGIN_CONF_PATH" ]; then
  if  ( !  (ISDIR(PLUGIN_CONF_PATH))  )
  {
    //printf "\033[40m\033[1;31mERROR: The PLUGIN_CONF_PATH ($PLUGIN_CONF_PATH) does not exist!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: The PLUGIN_CONF_PATH (%s) does not exist!\033[0m\n ", PLUGIN_CONF_PATH);
    //printf "\033[40m\033[1;31m       Please check your installation and/or configuration file.\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       Please check your installation and/or configuration file.\033[0m\n ");
    //exit 2
    exit(2);
  //fi
  }
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);

//}
}


void //setup_misc()
setup_misc(void)
//{
{
  //# Remove any stale plugin restart file
  //rm -f "$PLUGIN_LOAD_FILE_RESTART"
  remove(PLUGIN_LOAD_FILE_RESTART);
  
  //# Most people don't want to get any firewall logs being spit to the console
  //# This option makes the kernel ring buffer to only log messages with level "panic"
  //if [ "$DMESG_PANIC_ONLY" = "1" ]; then
  if  (  (strcmp(DMESG_PANIC_ONLY,"1")==0)  )
  {
    //echo "Setting the kernel ring buffer to only log panic messages to the console"
    printf("Setting the kernel ring buffer to only log panic messages to the console" "\n");
//#    dmesg -c    # Clear ring buffer
    //dmesg -n 1  # Only show panic messages on the console
    system("dmesg -n 1  # Only show panic messages on the console");
  //fi
  }
//}
}


void //setup_kernel_settings()
setup_kernel_settings(void)
//{
{
char *tr1_FREE = NULL;;

  //# Set INDENT value for functions
  //INDENT='  '
  INDENT = "  ";
  
  //echo "Configuring general kernel parameters:"
  printf("Configuring general kernel parameters:" "\n");

  //# Set the maximum number of connections to track.
  //# The kernel "default" depends on the available amount of RAM, 128 MB of RAM -> 8192
  //# possible entries, 256 MB of RAM --> 16376 possible entries, etc...
  //#######################################################################################
  //if [ -n "$CONNTRACK" -a "$CONNTRACK" != "0" ]; then
  if  (  (((CONNTRACK!=NULL)&&(strlen(CONNTRACK)!=0))&&(strcmp(CONNTRACK,"0")!=0)) )
  {
    //echo " Setting the max. amount of simultaneous connections to $CONNTRACK"
    printf(" Setting the max. amount of simultaneous connections to %s" "\n", CONNTRACK);
    //sysctl_multi -w net.nf_conntrack_max=$CONNTRACK  net.ipv4.netfilter.ip_conntrack_max=$CONNTRACK  net.ipv4.ip_conntrack_max=$CONNTRACK
    sysctl_multi("-w", "net.nf_conntrack_max=", CONNTRACK, "net.ipv4.netfilter.ip_conntrack_max=", CONNTRACK, "net.ipv4.ip_conntrack_max=", CONNTRACK, NULL);

  //fi
  }
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
//# Nicl 20130504, add comment for migration
  //if [ $NAT = "1" ] && [ ! -z "$TRIGGER_TIMEOUT" ] ; then
  if ((strcmp(NAT,"1")==0) && (strlen(TRIGGER_TIMEOUT)>0))
  {
    //echo "$TRIGGER_TIMEOUT" > /proc/porttrigger_timeout
    FILE* fp = fopen("/proc/porttrigger_timeout", "w");
    if (fp)
    {
        //Mos 2013/08/10, fix #8933: The timer of port-triggering can not work properly.
	    fprintf(fp, "%s\n", TRIGGER_TIMEOUT);
	    fclose(fp);
    }
  //fi
  }
  #endif

  //# Change some default timings to fix false logs generated by "lost connections"
  //# Defaults:
  //#          echo 60 > /proc/sys/net/ipv4/netfilter/ip_conntrack_udp_timeout
  //#          echo 180 > /proc/sys/net/ipv4/netfilter/ip_conntrack_udp_timeout_stream
  //#          echo 10 >/proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_close
  //#          echo 300 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_max_retrans
  //#          echo 120 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_time_wait
  //#          echo 30 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_last_ack
  //#          echo 60 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_close_wait
  //#          echo 120 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_fin_wait
  //#          echo 60 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_syn_recv
  //#          echo 120 > /proc/sys/net/ipv4/netfilter/ip_conntrack_tcp_timeout_syn_sent
  //#          echo 30 > /proc/sys/net/ipv4/netfilter/ip_conntrack_icmp_timeout
  //#          echo 1200 > /proc/sys/net/ipv4/netfilter/ip_conntrack_generic_timeout
  //###############################################################################
//#  echo " Setting default conntrack timeouts"

  //# This is to fix issues with DNS:
//#  sysctl_multi -w net.netfilter.nf_conntrack_udp_timeout=60  #                  net.ipv4.netfilter.ip_conntrack_udp_timeout=60

//#  sysctl_multi -w net.netfilter.nf_conntrack_udp_timeout_stream=180  #                  net.ipv4.netfilter.ip_conntrack_udp_timeout_stream=180

  //# Enable Conntrack Accounting (kernel config CONFIG_NF_CT_ACCT)
  //# CONFIG_NF_CT_ACCT is deprecated and will be removed sometime after kernel 2.6.27
  //sysctl -w net.netfilter.nf_conntrack_acct=1 2>/dev/null
  sysctl("-w", "net.netfilter.nf_conntrack_acct=", "1", "", NULL);


  //# Always set IPv4 options for IPv4 or IPv4/IPv6
  //######################################################
  //echo "Configuring kernel parameters:"
  printf("Configuring kernel parameters:" "\n");

  //# Disable ICMP send_redirect
  //############################
  //echo " Disabling send redirects"
  printf(" Disabling send redirects" "\n");
  //sysctl_set_all "net.ipv4.conf" "send_redirects" 0
  sysctl_set_all("net.ipv4.conf", "send_redirects", "0");
  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //sysctl_set_all "net.ipv6.conf" "send_redirects" 0
    sysctl_set_all("net.ipv6.conf", "send_redirects", "0");
  //fi
  }

  //# Don't accept source routed packets.
  //# Attackers can use source routing to generate
  //# traffic pretending to be from inside your network, but which is routed back along
  //# the path from which it came, namely outside, so attackers can compromise your
  //# network. Source routing is rarely used for legitimate purposes.
  //###################################################################################
  //if [ "$SOURCE_ROUTE_PROTECTION" = "0" ]; then
  if  (  (strcmp(SOURCE_ROUTE_PROTECTION,"0")==0)  )
  {
    //echo " DISABLING protection against source routed packets"
    printf(" DISABLING protection against source routed packets" "\n");
    //sysctl_set_all "net.ipv4.conf" "accept_source_route" 1
    sysctl_set_all("net.ipv4.conf", "accept_source_route", "1");
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "accept_source_route" 1
      sysctl_set_all("net.ipv6.conf", "accept_source_route", "1");
    //fi
    }
  //else
  }
  else
  {
    //echo " Enabling protection against source routed packets"
    printf(" Enabling protection against source routed packets" "\n");
    //sysctl_set_all "net.ipv4.conf" "accept_source_route" 0
    sysctl_set_all("net.ipv4.conf", "accept_source_route", "0");
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "accept_source_route" 0
      sysctl_set_all("net.ipv6.conf", "accept_source_route", "0");
    //fi
    }
  //fi
  }

  //# ICMP Broadcasting protection (smurf amplifier protection)
  //###########################################################
  //sysctl -w net.ipv4.icmp_echo_ignore_broadcasts=1
  sysctl("-w", "net.ipv4.icmp_echo_ignore_broadcasts=", "1", NULL);


  //# ICMP Dead Error Messages protection
  //#####################################
  //sysctl -w net.ipv4.icmp_ignore_bogus_error_responses=1
  sysctl("-w", "net.ipv4.icmp_ignore_bogus_error_responses=", "1", NULL);


  //# IP forwarding (need it to perform for example NAT)
  //####################################################
  //if [ "$IP_FORWARDING" != "0" ]; then
  if  (  (strcmp(IP_FORWARDING,"0")!=0)  )
  {
    //echo " Enabling packet forwarding"
    printf(" Enabling packet forwarding" "\n");
    //sysctl_set_all "net.ipv4.conf" "forwarding" 1 || sysctl -w net.ipv4.ip_forward=1 ||
    if (    sysctl_set_all("net.ipv4.conf", "forwarding", "1") != 0)if ( sysctl("-w", "net.ipv4.ip_forward=", "1", "", NULL)
 != 0)
    //{
    {
      //printf "\033[40m\033[1;31m WARNING: net.ipv4.conf.*.forwarding (or net.ipv4.ip_forward) could not be set! If you're using\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m WARNING: net.ipv4.conf.*.forwarding (or net.ipv4.ip_forward) could not be set! If you're using\033[0m\n ");
      //printf "\033[40m\033[1;31m          NAT or any other type of forwarding this may be a problem.\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m          NAT or any other type of forwarding this may be a problem.\033[0m\n ");
    //}
    }
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "forwarding" 1
      sysctl_set_all("net.ipv6.conf", "forwarding", "1");
      //echo " Disabling Local IPv6 Auto-Configuration"
      printf(" Disabling Local IPv6 Auto-Configuration" "\n");
      //sysctl_set_all "net.ipv6.conf" "autoconf" 0
      sysctl_set_all("net.ipv6.conf", "autoconf", "0");
      //sysctl_set_all "net.ipv6.conf" "accept_ra" 0
      sysctl_set_all("net.ipv6.conf", "accept_ra", "0");
    //fi
    }
  //else
  }
  else
  {
    //echo " DISABLING packet forwarding"
    printf(" DISABLING packet forwarding" "\n");
    //sysctl_set_all "net.ipv4.conf" "forwarding" 0 2>/dev/null || sysctl -w -e net.ipv4.ip_forward=0 2>/dev/null
    if (    sysctl_set_all("net.ipv4.conf", "forwarding", "0") != 0) sysctl("-w", "-e", "net.ipv4.ip_forward=", "0", "", NULL);

    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "forwarding" 0 2>/dev/null
      sysctl_set_all("net.ipv6.conf", "forwarding", "0");
      //if [ "$IPV6_AUTO_CONFIGURATION" != "0" ]; then
      if  (  (strcmp(IPV6_AUTO_CONFIGURATION,"0")!=0)  )
      {
        //echo " Enabling IPv6 Auto-Configuration"
        printf(" Enabling IPv6 Auto-Configuration" "\n");
        //sysctl_set_all "net.ipv6.conf" "autoconf" 1
        sysctl_set_all("net.ipv6.conf", "autoconf", "1");
        //sysctl_set_all "net.ipv6.conf" "accept_ra" 1
        sysctl_set_all("net.ipv6.conf", "accept_ra", "1");
      //else
      }
      else
      {
        //echo " DISABLING IPv6 Auto-Configuration"
        printf(" DISABLING IPv6 Auto-Configuration" "\n");
        //sysctl_set_all "net.ipv6.conf" "autoconf" 0
        sysctl_set_all("net.ipv6.conf", "autoconf", "0");
        //sysctl_set_all "net.ipv6.conf" "accept_ra" 0
        sysctl_set_all("net.ipv6.conf", "accept_ra", "0");
      //fi
      }
    //fi
    }
  //fi
  }

  //# Enable some general settings
  //##############################
  //echo " Setting some kernel performance options"
  printf(" Setting some kernel performance options" "\n");
  //sysctl -w net.ipv4.tcp_window_scaling=1
  sysctl("-w", "net.ipv4.tcp_window_scaling=", "1", NULL);

  //sysctl -w net.ipv4.tcp_timestamps=1
  sysctl("-w", "net.ipv4.tcp_timestamps=", "1", NULL);

  //sysctl -w net.ipv4.tcp_sack=1
  sysctl("-w", "net.ipv4.tcp_sack=", "1", NULL);

  //sysctl -w net.ipv4.tcp_dsack=1
  sysctl("-w", "net.ipv4.tcp_dsack=", "1", NULL);

  //sysctl -w net.ipv4.tcp_fack=1
  sysctl("-w", "net.ipv4.tcp_fack=", "1", NULL);

  //sysctl -w net.ipv4.tcp_low_latency=0
  sysctl("-w", "net.ipv4.tcp_low_latency=", "0", NULL);


  //# Reduce DoS'ing ability by reducing timeouts
  //#############################################################
  //if [ "$REDUCE_DOS_ABILITY" = "1" ]; then
  if  (  (strcmp(REDUCE_DOS_ABILITY,"1")==0)  )
  {
    //echo " Enabling reduction of the DoS'ing ability"
    printf(" Enabling reduction of the DoS'ing ability" "\n");

    //sysctl -w net.ipv4.tcp_fin_timeout=30
    sysctl("-w", "net.ipv4.tcp_fin_timeout=", "30", NULL);

    //sysctl -w net.ipv4.tcp_keepalive_time=1800
    sysctl("-w", "net.ipv4.tcp_keepalive_time=", "1800", NULL);


    //# Set number of times to retry SYN in a new connection
    //sysctl -w net.ipv4.tcp_syn_retries=3
    sysctl("-w", "net.ipv4.tcp_syn_retries=", "3", NULL);


    //# Set number of times to retry a SYN-ACK in a half-open new connections
    //sysctl -w net.ipv4.tcp_synack_retries=2
    sysctl("-w", "net.ipv4.tcp_synack_retries=", "2", NULL);


    //# Enable a fix for RFC1337 - time-wait assassination hazards in TCP
    //sysctl -w net.ipv4.tcp_rfc1337=1
    sysctl("-w", "net.ipv4.tcp_rfc1337=", "1", NULL);

  //else
  }
  else
  {
    //echo " Disabling reduction of the DoS'ing ability"
    printf(" Disabling reduction of the DoS'ing ability" "\n");

    //# Defaults:
    //sysctl -w net.ipv4.tcp_fin_timeout=60
    sysctl("-w", "net.ipv4.tcp_fin_timeout=", "60", NULL);

    //sysctl -w net.ipv4.tcp_keepalive_time=7200
    sysctl("-w", "net.ipv4.tcp_keepalive_time=", "7200", NULL);

    //sysctl -w net.ipv4.tcp_syn_retries=5
    sysctl("-w", "net.ipv4.tcp_syn_retries=", "5", NULL);

    //sysctl -w net.ipv4.tcp_synack_retries=5
    sysctl("-w", "net.ipv4.tcp_synack_retries=", "5", NULL);

    //sysctl -w net.ipv4.tcp_rfc1337=0
    sysctl("-w", "net.ipv4.tcp_rfc1337=", "0", NULL);

  //fi
  }

  //# Set out local port range. Kernel default = "1024 4999"
  //########################################################
  //if [ -z "$LOCAL_PORT_RANGE" ]; then
  if  (  ((LOCAL_PORT_RANGE==NULL)||(strlen(LOCAL_PORT_RANGE)==0))  )
  {
    //LOCAL_PORT_RANGE="32768 61000"
    LOCAL_PORT_RANGE="32768 61000";
  //fi
  }
  //sysctl -w net.ipv4.ip_local_port_range="$LOCAL_PORT_RANGE"
  sysctl("-w", "net.ipv4.ip_local_port_range=", LOCAL_PORT_RANGE, NULL);


  //# Now we change the LOCAL_PORT_RANGE for further use by iptables (replace space with :)
  //LOCAL_PORT_RANGE="$(echo "$LOCAL_PORT_RANGE" |tr ' ' ':')"
  tr1_FREE = tr(LOCAL_PORT_RANGE, " ", ":");
  LOCAL_PORT_RANGE=tr1_FREE;;

  //# Use rp_filter to drop connections from non-routable IPs
  //######################################################################
  //if [ "$RP_FILTER" = "1" ]; then
  if  (  (strcmp(RP_FILTER,"1")==0)  )
  {
    //echo " Enabling anti-spoof with rp_filter"
    printf(" Enabling anti-spoof with rp_filter" "\n");
    //sysctl_set_all "net.ipv4.conf" "rp_filter" 1
    sysctl_set_all("net.ipv4.conf", "rp_filter", "1");
  //else
  }
  else
  {
    //echo " Disabling anti-spoof with rp_filter"
    printf(" Disabling anti-spoof with rp_filter" "\n");
    //sysctl_set_all "net.ipv4.conf" "rp_filter" 0
    sysctl_set_all("net.ipv4.conf", "rp_filter", "0");
  //fi
  }

  //# Block ALL ICMP echo requests?
  //###############################
  //if [ "$ECHO_IGNORE" = "1" ]; then
  if  (  (strcmp(ECHO_IGNORE,"1")==0)  )
  {
    //echo " Blocking all ICMP echo-requests"
    printf(" Blocking all ICMP echo-requests" "\n");
    //sysctl -w net.ipv4.icmp_echo_ignore_all=1
    sysctl("-w", "net.ipv4.icmp_echo_ignore_all=", "1", NULL);

  //else
  }
  else
  {
    //sysctl -w net.ipv4.icmp_echo_ignore_all=0
    sysctl("-w", "net.ipv4.icmp_echo_ignore_all=", "0", NULL);

  //fi
  }

  //# Add synflood protection?
  //##########################
  //if [ "$SYN_PROT" != 0 ]; then
  if  ( "SYN_PROT" != 0 )
  {
    //echo " Enabling SYN-flood protection via SYN-cookies"
    printf(" Enabling SYN-flood protection via SYN-cookies" "\n");
    //sysctl -w net.ipv4.tcp_syncookies=1
    sysctl("-w", "net.ipv4.tcp_syncookies=", "1", NULL);

  //else
  }
  else
  {
    //echo " Disabling SYN-flood protection via SYN-cookies"
    printf(" Disabling SYN-flood protection via SYN-cookies" "\n");
    //sysctl -w net.ipv4.tcp_syncookies=0
    sysctl("-w", "net.ipv4.tcp_syncookies=", "0", NULL);

  //fi
  }

  //# Log martians?
  //###############
  //if [ "$LOG_MARTIANS" = "1" ]; then
  if  (  (strcmp(LOG_MARTIANS,"1")==0)  )
  {
    //echo " Enabling the logging of martians"
    printf(" Enabling the logging of martians" "\n");
    //sysctl_set_all "net.ipv4.conf" "log_martians" 1
    sysctl_set_all("net.ipv4.conf", "log_martians", "1");
  //else
  }
  else
  {
    //echo " Disabling the logging of martians"
    printf(" Disabling the logging of martians" "\n");
    //sysctl_set_all "net.ipv4.conf" "log_martians" 0
    sysctl_set_all("net.ipv4.conf", "log_martians", "0");
  //fi
  }

  //# Accept ICMP redirect messages?
  //################################
  //if [ "$ICMP_REDIRECT" = "1" ]; then
  if  (  (strcmp(ICMP_REDIRECT,"1")==0)  )
  {
    //echo " Enabling the acception of ICMP-redirect messages"
    printf(" Enabling the acception of ICMP-redirect messages" "\n");
    //sysctl_set_all "net.ipv4.conf" "accept_redirects" 1
    sysctl_set_all("net.ipv4.conf", "accept_redirects", "1");
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "accept_redirects" 1
      sysctl_set_all("net.ipv6.conf", "accept_redirects", "1");
    //fi
    }
  //else
  }
  else
  {
    //echo " Disabling the acception of ICMP-redirect messages"
    printf(" Disabling the acception of ICMP-redirect messages" "\n");
    //sysctl_set_all "net.ipv4.conf" "accept_redirects" 0
    sysctl_set_all("net.ipv4.conf", "accept_redirects", "0");
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //sysctl_set_all "net.ipv6.conf" "accept_redirects" 0
      sysctl_set_all("net.ipv6.conf", "accept_redirects", "0");
    //fi
    }
  //fi
  }

  //# Time To Live (TTL) is the term for a data field in the internet protocol.
  //# TTL is today interpreted to indicate the maximum number of routers a packet may transit.
  //# Each router that handles a packet will decrement the TTL field by 1.
  //# Raise if you have a huge network.
  //# Set the default ttl. (Kernel Default: 64)
  //###########################################################################################
  //if [ -z "$DEFAULT_TTL" ]; then
  if  (  ((DEFAULT_TTL==NULL)||(strlen(DEFAULT_TTL)==0))  )
  {
    //DEFAULT_TTL="64"
    DEFAULT_TTL="64";
  //fi
  }

  //if [ $DEFAULT_TTL -gt 9 -a $DEFAULT_TTL -lt 256 ]; then
  if  ( ((atoi(DEFAULT_TTL)>9)&&(atoi(DEFAULT_TTL)<256)))
  {
    //echo " Setting default TTL=$DEFAULT_TTL"
    printf(" Setting default TTL=%s" "\n", DEFAULT_TTL);
    //sysctl -w net.ipv4.ip_default_ttl=$DEFAULT_TTL
    sysctl("-w", "net.ipv4.ip_default_ttl=", DEFAULT_TTL, NULL);

  //else
  }
  else
  {
    //printf "\033[40m\033[1;31m WARNING: Ingoring invalid value for DEFAULT_TTL ($DEFAULT_TTL), it should be between 10 and 255!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m WARNING: Ingoring invalid value for DEFAULT_TTL (%s), it should be between 10 and 255!\033[0m\n ", DEFAULT_TTL);
  //fi
  }

  //# Increase the default queuelength. (Kernel Default: 1024)
  //##########################################################
  //# sysctl -w -e net.ipv4.ip_queue_maxlen=2048

  //# Enable ECN? (Explicit Congestion Notification)
  //################################################
  //if [ "$ECN" = "1" ]; then
  if  (  (strcmp(ECN,"1")==0)  )
  {
    //echo " Enabling ECN (Explicit Congestion Notification)"
    printf(" Enabling ECN (Explicit Congestion Notification)" "\n");
    //sysctl -w net.ipv4.tcp_ecn=1
    sysctl("-w", "net.ipv4.tcp_ecn=", "1", NULL);

  //else
  }
  else
  {
    //echo " Disabling ECN (Explicit Congestion Notification)"
    printf(" Disabling ECN (Explicit Congestion Notification)" "\n");
    //sysctl -w net.ipv4.tcp_ecn=0
    sysctl("-w", "net.ipv4.tcp_ecn=", "0", NULL);

  //fi
  }

  //# This enables dynamic-address hacking which makes the
  //# life with Diald and similar programs much easier.
  //######################################################
  //if [ "$EXT_IF_DHCP_IP" = "1" ]; then
  if  (  (strcmp(EXT_IF_DHCP_IP,"1")==0)  )
  {
    //echo " Enabling kernel support for dynamic IPs"
    printf(" Enabling kernel support for dynamic IPs" "\n");
    //sysctl -w net.ipv4.ip_dynaddr=1
    sysctl("-w", "net.ipv4.ip_dynaddr=", "1", NULL);

  //else
  }
  else
  {
    //echo " Disabling kernel support for dynamic IPs"
    printf(" Disabling kernel support for dynamic IPs" "\n");
    //sysctl -w net.ipv4.ip_dynaddr=0
    sysctl("-w", "net.ipv4.ip_dynaddr=", "0", NULL);

  //fi
  }

  //# In most cases pmtu discovery is ok, but in some rare cases (when having problems)
  //# you might want to disable it.
  //if [ "$NO_PMTU_DISCOVERY" = "1" ]; then
  if  (  (strcmp(NO_PMTU_DISCOVERY,"1")==0)  )
  {
    //echo " Disabling PMTU discovery"
    printf(" Disabling PMTU discovery" "\n");
    //sysctl -w net.ipv4.ip_no_pmtu_disc=1
    sysctl("-w", "net.ipv4.ip_no_pmtu_disc=", "1", NULL);

  //else
  }
  else
  {
    //echo " Enabling PMTU discovery"
    printf(" Enabling PMTU discovery" "\n");
    //sysctl -w net.ipv4.ip_no_pmtu_disc=0
    sysctl("-w", "net.ipv4.ip_no_pmtu_disc=", "0", NULL);

  //fi
  }

  //echo " Flushing route table"
  printf(" Flushing route table" "\n");
  //sysctl -w net.ipv4.route.flush=1
  sysctl("-w", "net.ipv4.route.flush=", "1", NULL);

  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //sysctl -w net.ipv6.route.flush=1
    sysctl("-w", "net.ipv6.route.flush=", "1", NULL);

  //fi
  }

  //echo " Kernel setup done..."
  printf(" Kernel setup done..." "\n");

  //# Return "no error"
  //#return 0
if (tr1_FREE != NULL) free(tr1_FREE);

//}
}


void //init_firewall_chains()
init_firewall_chains(void)
//{
{
  //echo "Initializing firewall chains"
  printf("Initializing firewall chains" "\n");

  //# Set INDENT for functions
  //INDENT='  '
  INDENT = "  ";

  //# Attempt to flush all IPv4 chains
  //##################################
  //ip4tables -F
  ip4tables("-F");
  //ip4tables -X
  ip4tables("-X");

  //# Flush builtin IPv4 chains
  //###########################
  //ip4tables -F INPUT
  ip4tables("-F INPUT");
  //ip4tables -F OUTPUT
  ip4tables("-F OUTPUT");
  //ip4tables -F FORWARD
  ip4tables("-F FORWARD");

  //# Flush rules in nat/mangle tables
  //##################################
  //ip4tables -t nat -F
  ip4tables("-t nat -F");
  //ip4tables -t nat -X
  ip4tables("-t nat -X");
  //ip4tables -t mangle -F
  ip4tables("-t mangle -F");
  //ip4tables -t mangle -X
  ip4tables("-t mangle -X");
  
  //if [ "$IPV6_DETECTED" = "1" ]; then
  if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //# Attempt to flush all IPv6 chains
    //##################################
    //ip6tables -F
    ip6tables("-F");
    //ip6tables -X
    ip6tables("-X");

    //# Flush builtin IPv6 chains
    //###########################
    //ip6tables -F INPUT
    ip6tables("-F INPUT");
    //ip6tables -F OUTPUT
    ip6tables("-F OUTPUT");
    //ip6tables -F FORWARD
    ip6tables("-F FORWARD");

    //# Flush rules in mangle table
    //#############################
    //ip6tables -t mangle -F
    ip6tables("-t mangle -F");
    //ip6tables -t mangle -X
    ip6tables("-t mangle -X");
  //fi
  }
  
  //# Create our "base" chains
  //##########################
  //iptables -N BASE_INPUT_CHAIN
  iptables("-N BASE_INPUT_CHAIN");
  //iptables -N BASE_FORWARD_CHAIN
  iptables("-N BASE_FORWARD_CHAIN");
  //iptables -N BASE_OUTPUT_CHAIN
  iptables("-N BASE_OUTPUT_CHAIN");

  //# Accept packets of ESTABLISHED connections
  //###########################################
  //iptables -A BASE_INPUT_CHAIN -m state --state ESTABLISHED -j ACCEPT
  iptables("-A BASE_INPUT_CHAIN -m state --state ESTABLISHED -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -m state --state ESTABLISHED -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -m state --state ESTABLISHED -j ACCEPT");
  //iptables -A BASE_OUTPUT_CHAIN -m state --state ESTABLISHED -j ACCEPT
  iptables("-A BASE_OUTPUT_CHAIN -m state --state ESTABLISHED -j ACCEPT");

  //# Accept packets of RELATED connections
  //#######################################
  //iptables -A BASE_INPUT_CHAIN -m state --state RELATED -p tcp --dport 1024: -j ACCEPT
  iptables("-A BASE_INPUT_CHAIN -m state --state RELATED -p tcp --dport 1024: -j ACCEPT");
  //iptables -A BASE_INPUT_CHAIN -m state --state RELATED -p udp --dport 1024: -j ACCEPT
  iptables("-A BASE_INPUT_CHAIN -m state --state RELATED -p udp --dport 1024: -j ACCEPT");
  //iptables -A BASE_INPUT_CHAIN -m state --state RELATED -p icmp -j ACCEPT
  iptables("-A BASE_INPUT_CHAIN -m state --state RELATED -p icmp -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -m state --state RELATED -p tcp --dport 1024: -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -m state --state RELATED -p tcp --dport 1024: -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -m state --state RELATED -p udp --dport 1024: -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -m state --state RELATED -p udp --dport 1024: -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -m state --state RELATED -p icmp -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -m state --state RELATED -p icmp -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -m state --state RELATED -p gre -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -m state --state RELATED -p gre -j ACCEPT");

  //# Accept all packets for the loopback device
  //############################################
  //iptables -A BASE_INPUT_CHAIN -i lo -j ACCEPT
  iptables("-A BASE_INPUT_CHAIN -i lo -j ACCEPT");
  //iptables -A BASE_FORWARD_CHAIN -i lo -j ACCEPT
  iptables("-A BASE_FORWARD_CHAIN -i lo -j ACCEPT");
  //iptables -A BASE_OUTPUT_CHAIN -o lo -j ACCEPT
  iptables("-A BASE_OUTPUT_CHAIN -o lo -j ACCEPT");

  //# Insert our base chains
  //########################
  //iptables -A INPUT -j BASE_INPUT_CHAIN
  iptables("-A INPUT -j BASE_INPUT_CHAIN");
  //iptables -A FORWARD -j BASE_FORWARD_CHAIN
  iptables("-A FORWARD -j BASE_FORWARD_CHAIN");
  //iptables -A OUTPUT -j BASE_OUTPUT_CHAIN
  iptables("-A OUTPUT -j BASE_OUTPUT_CHAIN");

  iptables("-A FORWARD -j OPENVPN_FORWARD_CHAIN");

  

  //# Create several chains that we will use later on
  //#################################################
  //create_user_chains;
  create_user_chains();

  //# Reset the iptables counters
  //iptables -Z
  iptables("-Z");
  //iptables -t mangle -Z
  iptables("-t mangle -Z");
  //ip4tables -t nat -Z
  ip4tables("-t nat -Z");
//}
}


void //setup_default_policies()
setup_default_policies(void)
//{
{
  //# Set the default policies for the builtin INPUT & FORWARD tables. The
  //# default for other chains (eg. OUTPUT) is always set to ACCEPT.
  //#######################################################################
  //if [ "$DEFAULT_POLICY_DROP" != "0" ]; then
  if  (  (strcmp(DEFAULT_POLICY_DROP,"0")!=0)  )
  {
    //echo " Setting all default policies to DROP while \"setting up firewall rules\""
    printf(" Setting all default policies to DROP while \"setting up firewall rules\"" "\n");
    //iptables -P INPUT DROP
    iptables("-P INPUT DROP");
    //iptables -P FORWARD DROP
    iptables("-P FORWARD DROP");
    //# Accept all OUTPUT bound traffic. 
    //# Necessary to allow DOCSIS management (DHCP/TOD/TFTP/...) at power-up.
    //#iptables -P OUTPUT DROP
    //iptables -P OUTPUT ACCEPT
    iptables("-P OUTPUT ACCEPT");
  //else
  }
  else
  {
    //echo " WARNING: Setting all default policies to ACCEPT while \"setting up firewall rules\""
    printf(" WARNING: Setting all default policies to ACCEPT while \"setting up firewall rules\"" "\n");
    //iptables -P INPUT ACCEPT
    iptables("-P INPUT ACCEPT");
    //iptables -P FORWARD ACCEPT
    iptables("-P FORWARD ACCEPT");
    //iptables -P OUTPUT ACCEPT
    iptables("-P OUTPUT ACCEPT");
  //fi
  }

  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //echo "IPv4/IPv6 mixed mode selected"
    printf("IPv4/IPv6 mixed mode selected" "\n");
  //elif [ "$IPV6_DETECTED" = "1" ]; then
  }
  else if (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //echo "IPv4 mode selected but IPv6 available, DROP all IPv6 packets"
    printf("IPv4 mode selected but IPv6 available, DROP all IPv6 packets" "\n");
    //ip6tables -P INPUT DROP
    ip6tables("-P INPUT DROP");
    //ip6tables -P FORWARD DROP
    ip6tables("-P FORWARD DROP");
    //# Accept all OUTPUT bound traffic. 
    //# Necessary to allow DOCSIS management (DHCP/TOD/TFTP/...) at power-up.
    //#ip6tables -P OUTPUT DROP
    //ip6tables -P OUTPUT ACCEPT
    ip6tables("-P OUTPUT ACCEPT");

    //# Allow IPv6 traffic from the loopback (localhost)
    //ip6tables -A INPUT -i lo -j ACCEPT
    ip6tables("-A INPUT -i lo -j ACCEPT");
    //ip6tables -A FORWARD -i lo -j ACCEPT
    ip6tables("-A FORWARD -i lo -j ACCEPT");
    //ip6tables -A OUTPUT -o lo -j ACCEPT
    ip6tables("-A OUTPUT -o lo -j ACCEPT");

    //# DROP all IPv6 traffic
    //ip6tables -A INPUT -j DROP
    ip6tables("-A INPUT -j DROP");
    //ip6tables -A FORWARD -j DROP
    ip6tables("-A FORWARD -j DROP");
    //ip6tables -A OUTPUT -j DROP
    ip6tables("-A OUTPUT -j DROP");
  //else
  }
  else
  {
    //echo "IPv4 mode selected, no IPv6 available"
    printf("IPv4 mode selected, no IPv6 available" "\n");
  //fi
  }

  //# The POST_INPUT_DROP_CHAIN should temporarily DROP for now
  //# We'll change this once the rules are in place
  //###########################################################
  //iptables -A POST_INPUT_DROP_CHAIN -j DROP
  iptables("-A POST_INPUT_DROP_CHAIN -j DROP");

  //# The HOST_BLOCK_DROP chain should always DROP
  //###########################################################
  //if [ "$BLOCKED_HOST_LOG" != "0" ]; then
  if  (  (strcmp(BLOCKED_HOST_LOG,"0")!=0)  )
  {
    //iptables -A HOST_BLOCK_DROP -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Blocked host(s): "
    iptables("-A HOST_BLOCK_DROP -m limit --limit 1/m --limit-burst 1 -j LOG  --log-prefix \"AIF:Blocked host(s): \" --log-level %s", LOGLEVEL);
  //fi
  }
  //iptables -A HOST_BLOCK_DROP -j DROP
  iptables("-A HOST_BLOCK_DROP -j DROP");

  //# The LINK_LOCAL_DROP chain should always DROP
  //###########################################################
  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //if [ "$LINK_LOCAL_DROP_LOG" != "0" ]; then
    if  (  (strcmp(LINK_LOCAL_DROP_LOG,"0")!=0)  )
    {
      //ip6tables -A LINK_LOCAL_DROP -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Dropped Link-Local: "
      ip6tables("-A LINK_LOCAL_DROP -m limit --limit 1/m --limit-burst 1 -j LOG  --log-prefix \"AIF:Dropped Link-Local: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //ip6tables -A LINK_LOCAL_DROP -j DROP
    ip6tables("-A LINK_LOCAL_DROP -j DROP");
  //fi
  }
//}
}


//##################################################################################################################
//## Chain VALID_CHK - Check packets for invalid flags etc.                                                       ##
//##################################################################################################################
void //setup_valid_chk_chain()
setup_valid_chk_chain(void)
//{
{
  //## Log scanning of nmap etc.
  //############################
  //if [ "$SCAN_LOG" != "0" ]; then
  if  (  (strcmp(SCAN_LOG,"0")!=0)  )
  {
    //echo "Logging of stealth scans (nmap probes etc.) enabled"
    printf("Logging of stealth scans (nmap probes etc.) enabled" "\n");

    //# (NMAP) FIN/URG/PSH
    //####################
    //iptables -A VALID_CHK -p tcp --tcp-flags ALL FIN,URG,PSH  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth XMAS scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags ALL FIN,URG,PSH  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan:Stealth XMAS scan: \" --log-level %s", LOGLEVEL);

    //# SYN/RST/ACK/FIN/URG
    //#####################
    //iptables -A VALID_CHK -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth XMAS-PSH scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan:Stealth XMAS-PSH scan: \" --log-level %s", LOGLEVEL);

    //# ALL/ALL
    //#########
    //iptables -A VALID_CHK -p tcp --tcp-flags ALL ALL  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth XMAS-ALL scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags ALL ALL  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan XMAS-ALL scan: \" --log-level %s", LOGLEVEL);

    //# NMAP FIN Stealth
    //##################
    //iptables -A VALID_CHK -p tcp --tcp-flags ALL FIN  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth FIN scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags ALL FIN  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan: FIN scan: \" --log-level %s", LOGLEVEL);

    //# SYN/RST
    //#########
    //iptables -A VALID_CHK -p tcp --tcp-flags SYN,RST SYN,RST  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth SYN/RST scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags SYN,RST SYN,RST  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan: SYN/RST scan: \" --log-level %s", LOGLEVEL);

    //# SYN/FIN (probably)
    //####################
    //iptables -A VALID_CHK -p tcp --tcp-flags SYN,FIN SYN,FIN  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth SYN/FIN scan?: "
    iptables("-A VALID_CHK -p tcp --tcp-flags SYN,FIN SYN,FIN  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan: SYN/FIN scan?: \" --log-level %s", LOGLEVEL);

    //# Null scan
    //###########
    //iptables -A VALID_CHK -p tcp --tcp-flags ALL NONE  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth Null scan: "
    iptables("-A VALID_CHK -p tcp --tcp-flags ALL NONE  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan: Null scan: \" --log-level %s", LOGLEVEL);

  //else
  }
  else
  {
    //echo "Logging of stealth scans (nmap probes etc.) disabled"
    printf("Logging of stealth scans (nmap probes etc.) disabled" "\n");
  //fi
  }

//Mos 2013/09/12, fix SYN Flood not take effect when DMZ is on
//move here, keep log and drop in carno, move return to arno-interface
#if 1 // Richard 20130902 fix port scan log
  if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
  {
//Mos 2013/09/17, fix TD#206: Port fowarding and DMZ doesn't work for the application using TCP
//move syn flood into SYN_FLOOD_CHK, add RETURN before LOG and DROP
    iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 10/sec --limit-burst 10 -j RETURN");
    iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSPortScan: SYN scan?: \" --log-level %s", LOGLEVEL);
//    iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 10/sec --limit-burst 80 -j RETURN");
//    iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level %s --log-prefix \"DoSSYNFlood:SYN flood?: \"", LOGLEVEL);
//    iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j POST_INPUT_DROP_CHAIN");
    iptables("-A VALID_CHK -p tcp -j SYN_FLOOD_CHK");
    iptables("-A SYN_FLOOD_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 20/sec --limit-burst 80 -j RETURN");
    iptables("-A SYN_FLOOD_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSSYNFlood:SYN flood?: \" --log-level %s", LOGLEVEL);
    iptables("-A SYN_FLOOD_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j POST_INPUT_DROP_CHAIN");
  }
#endif


  //# Drop (NMAP) scan packets:
  //###########################

  //# NMAP FIN/URG/PSH
  //##################
  //iptables -A VALID_CHK -p tcp --tcp-flags ALL FIN,URG,PSH -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags ALL FIN,URG,PSH -j POST_INPUT_DROP_CHAIN");

  //# SYN/RST/ACK/FIN/URG
  //#####################
  //iptables -A VALID_CHK -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j POST_INPUT_DROP_CHAIN");

  //# ALL/ALL Scan
  //##############
  //iptables -A VALID_CHK -p tcp --tcp-flags ALL ALL -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags ALL ALL -j POST_INPUT_DROP_CHAIN");

  //# NMAP FIN Stealth
  //##################
  //iptables -A VALID_CHK -p tcp --tcp-flags ALL FIN -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags ALL FIN -j POST_INPUT_DROP_CHAIN");

  //# SYN/RST
  //#########
  //iptables -A VALID_CHK -p tcp --tcp-flags SYN,RST SYN,RST -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags SYN,RST SYN,RST -j POST_INPUT_DROP_CHAIN");

  //# SYN/FIN -- Scan(probably)
  //###########################
  //iptables -A VALID_CHK -p tcp --tcp-flags SYN,FIN SYN,FIN -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags SYN,FIN SYN,FIN -j POST_INPUT_DROP_CHAIN");

  //# NMAP Null Scan
  //################
  //iptables -A VALID_CHK -p tcp --tcp-flags ALL NONE -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-flags ALL NONE -j POST_INPUT_DROP_CHAIN");

#if 0 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a // Richard 20130902 move to EXT_INPUT_CHAIN
  //# Teidor add start, 2013/03/14, SYN, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable
  //################

  //# Mos 2013/05/27, fix #7504: CM always allow all external IP addresses to access when turning Remote Management on
  //#modify ACCEPT -> RETURN
  //iptables -A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 10/sec --limit-burst 80 -j RETURN
  iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 10/sec --limit-burst 80 -j RETURN");

  //iptables -A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth SYN scan?: "
  iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -m limit --limit 3/m --limit-burst 5 -j LOG --log-level %s --log-prefix \"DoSPortScan: SYN scan?: \"", LOGLEVEL);
  //iptables -A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -j POST_INPUT_DROP_CHAIN");
  //# Teidor add end, 2013/03/14
#endif

  //# Log packets with bad flags?
  //#############################
  //if [ "$BAD_FLAGS_LOG" != "0" ]; then
  if  (  (strcmp(BAD_FLAGS_LOG,"0")!=0)  )
  {
    //echo "Logging of packets with bad TCP-flags enabled"
    printf("Logging of packets with bad TCP-flags enabled" "\n");
    //iptables -A VALID_CHK -p tcp --tcp-option 64  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Bad TCP flag(64): "
    iptables("-A VALID_CHK -p tcp --tcp-option 64  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:Bad TCP flag(64): \" --log-level %s", LOGLEVEL);

    //iptables -A VALID_CHK -p tcp --tcp-option 128  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Bad TCP flag(128): "
    iptables("-A VALID_CHK -p tcp --tcp-option 128  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:Bad TCP flag(128): \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo "Logging of packets with bad TCP-flags disabled"
    printf("Logging of packets with bad TCP-flags disabled" "\n");
  //fi
  }

  //# Drop packets with bad tcp flags
  //#################################
  //iptables -A VALID_CHK -p tcp --tcp-option 64 -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-option 64 -j POST_INPUT_DROP_CHAIN");
  //iptables -A VALID_CHK -p tcp --tcp-option 128 -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -p tcp --tcp-option 128 -j POST_INPUT_DROP_CHAIN");

  //# These packets are normally from "lost connection" and thus can generate false alarms
  //# So we might want to ignore such packets
  //######################################################################################
//#  if [ "$LOST_CONNECTION_LOG" != "1" ]; then
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST ACK -j POST_INPUT_DROP_CHAIN
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST FIN -j POST_INPUT_DROP_CHAIN
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST RST -j POST_INPUT_DROP_CHAIN
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST ACK,FIN -j POST_INPUT_DROP_CHAIN
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST ACK,RST -j POST_INPUT_DROP_CHAIN
//#    iptables -A VALID_CHK -p tcp --tcp-flags SYN,ACK,FIN,RST SYN,ACK -j POST_INPUT_DROP_CHAIN
//#  fi

  //# Here we add some protection from random packets we receive, such as random sweeps from other
  //# (possible) hacked computers, or just packets who are invalid, not belonging to ANY connection
  //###############################################################################################
  //if [ "$INVALID_TCP_LOG" = "1" ]; then
  if  (  (strcmp(INVALID_TCP_LOG,"1")==0)  )
  {
    //echo "Logging of INVALID TCP packets enabled"
    printf("Logging of INVALID TCP packets enabled" "\n");

    //iptables -A VALID_CHK -p tcp -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INVALID TCP: "
    iptables("-A VALID_CHK -p tcp -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-prefix \"AIF:INVALID TCP: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo "Logging of INVALID TCP packets disabled"
    printf("Logging of INVALID TCP packets disabled" "\n");
  //fi
  }

  //if [ "$INVALID_UDP_LOG" = "1" ]; then
  if  (  (strcmp(INVALID_UDP_LOG,"1")==0)  )
  {
    //echo "Logging of INVALID UDP packets enabled"
    printf("Logging of INVALID UDP packets enabled" "\n");

    //iptables -A VALID_CHK -p udp -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INVALID UDP: "
    iptables("-A VALID_CHK -p udp -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-prefix \"AIF:INVALID UDP: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo "Logging of INVALID UDP packets disabled"
    printf("Logging of INVALID UDP packets disabled" "\n");
  //fi
  }

  //if [ "$INVALID_ICMP_LOG" = "1" ]; then
  if  (  (strcmp(INVALID_ICMP_LOG,"1")==0)  )
  {
    //echo "Logging of INVALID ICMP packets enabled"
    printf("Logging of INVALID ICMP packets enabled" "\n");

    //# Only log INVALID ICMP-request packets when we also want to log "normal" ICMP-request packets
    //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
    if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
    {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
      //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
	  //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
        if ((strcmp(PORT_SCAN_DOS_DISABLE,"0")==0 ))
      //# Teidor add end, 2013/03/14 
#endif
      {
      //iptables -A VALID_CHK -p icmp --icmp-type echo-request -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INVALID ICMP-request: "
      iptables("-A VALID_CHK -p icmp --icmp-type echo-request -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-prefix \"AIF:INVALID ICMP-request: \" --log-level %s", LOGLEVEL);
      }
    //fi
    }

    //# Only log INVALID ICMP-other when enabled in the config
    //if [ "$ICMP_OTHER_LOG" != "0" ]; then
    if  (  (strcmp(ICMP_OTHER_LOG,"0")!=0)  )
    {
      #if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
      //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
      //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
      if ((strcmp(PORT_SCAN_DOS_DISABLE,"0")==0 ))
      #endif
      {
      //iptables -A VALID_CHK -p icmp ! --icmp-type echo-request -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INVALID ICMP-other: "
      iptables("-A VALID_CHK -p icmp ! --icmp-type echo-request -m state --state INVALID  -m limit --limit 1/m --limit-burst 2 -j LOG --log-prefix \"AIF:INVALID ICMP-other: \" --log-level %s", LOGLEVEL);
      }	  
    //fi
    }
  //else
  }
  else
  {
    //echo "Logging of INVALID ICMP packets disabled"
    printf("Logging of INVALID ICMP packets disabled" "\n");
  //fi
  }

  //# Drop invalid packets
  //######################
  //iptables -A VALID_CHK -m state --state INVALID -j POST_INPUT_DROP_CHAIN
  iptables("-A VALID_CHK -m state --state INVALID -j POST_INPUT_DROP_CHAIN");

  //# Fragmentation cannot happen with IPV6 (and maybe even not with iptables/ipv4?)
  //## Log fragmented packets
  //#########################
  //if [ "$FRAG_LOG" = "1" ]; then
  if  (  (strcmp(FRAG_LOG,"1")==0)  )
  {
    //echo "Logging of fragmented packets enabled"
    printf("Logging of fragmented packets enabled" "\n");
    //ip4tables -A VALID_CHK -f -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix "AIF:Fragment packet: "
    ip4tables("-A VALID_CHK -f -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:Fragment packet: \"");
  //else
  }
  else
  {
    //echo "Logging of IPv4 fragmented packets disabled"
    printf("Logging of IPv4 fragmented packets disabled" "\n");
  //fi
  }
  //# Drop fragmented packets
  //#########################
  //ip4tables -A VALID_CHK -f -j DROP
  ip4tables("-A VALID_CHK -f -j DROP");
//}
}


//################################################################################################################
//## Chain RESERVED_NET_CHK - Check if the source addresses of the packets are (in)valid                        ##
//################################################################################################################
void //setup_reserved_net_chk_chain()
setup_reserved_net_chk_chain(void)
//{
{
  //# Log access from reserved addresses
  //####################################
  //if [ "$RESERVED_NET_LOG" = "1" ]; then
  if  (  (strcmp(RESERVED_NET_LOG,"1")==0)  )
  {
    //echo "Logging of access from reserved addresses enabled"
    printf("Logging of access from reserved addresses enabled" "\n");
    //ip4tables -A RESERVED_NET_CHK -s 10.0.0.0/8  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Private address: "
    ip4tables("-A RESERVED_NET_CHK -s 10.0.0.0/8  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Private address: \" --log-level %s", LOGLEVEL);

    //ip4tables -A RESERVED_NET_CHK -s 172.16.0.0/12  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Private address: "
    ip4tables("-A RESERVED_NET_CHK -s 172.16.0.0/12  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Private address: \" --log-level %s", LOGLEVEL);

    //ip4tables -A RESERVED_NET_CHK -s 192.168.0.0/16  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Private address: "
    ip4tables("-A RESERVED_NET_CHK -s 192.168.0.0/16  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Private address: \" --log-level %s", LOGLEVEL);

    //ip4tables -A RESERVED_NET_CHK -s 169.254.0.0/16  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Link-local address: "
    ip4tables("-A RESERVED_NET_CHK -s 169.254.0.0/16  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Link-local address: \" --log-level %s", LOGLEVEL);
    
    //ip4tables -A RESERVED_NET_CHK -s 224.0.0.0/24  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Multicast address: "
    ip4tables("-A RESERVED_NET_CHK -s 224.0.0.0/24  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Multicast address: \" --log-level %s", LOGLEVEL);
    
    //ip4tables -A RESERVED_NET_CHK -s 239.0.0.0/24  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv4 Multicast address: "
    ip4tables("-A RESERVED_NET_CHK -s 239.0.0.0/24  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv4 Multicast address: \" --log-level %s", LOGLEVEL);

    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //# IPv6 not 2000::/3 is non-Global Unicast
      //ip6tables -A RESERVED_NET_CHK ! -s 2000::/3  -m limit --limit 1/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IPv6 non-Global address: "
      ip6tables("-A RESERVED_NET_CHK ! -s 2000::/3  -m limit --limit 1/m --limit-burst 1 -j LOG --log-prefix \"AIF:IPv6 non-Global address: \" --log-level %s", LOGLEVEL);
    //fi
    }
  //else
  }
  else
  {
    //echo "Logging of access from reserved addresses disabled"
    printf("Logging of access from reserved addresses disabled" "\n");
  //fi
  }

  //if [ "$DROP_PRIVATE_ADDRESSES" = "1" ]; then
  if  (  (strcmp(DROP_PRIVATE_ADDRESSES,"1")==0)  )
  {
    //# rp_filter drops some of these addresses, but just to be sure :)
    //################################################################
    //#echo "Denying access from reserved addresses..."
    //ip4tables -A RESERVED_NET_CHK -s 10.0.0.0/8 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 10.0.0.0/8 -j POST_INPUT_DROP_CHAIN");
    //ip4tables -A RESERVED_NET_CHK -s 172.16.0.0/12 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 172.16.0.0/12 -j POST_INPUT_DROP_CHAIN");
    //ip4tables -A RESERVED_NET_CHK -s 192.168.0.0/16 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 192.168.0.0/16 -j POST_INPUT_DROP_CHAIN");
    //ip4tables -A RESERVED_NET_CHK -s 169.254.0.0/16 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 169.254.0.0/16 -j POST_INPUT_DROP_CHAIN");
    //ip4tables -A RESERVED_NET_CHK -s 224.0.0.0/24 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 224.0.0.0/24 -j POST_INPUT_DROP_CHAIN");
    //ip4tables -A RESERVED_NET_CHK -s 239.0.0.0/24 -j POST_INPUT_DROP_CHAIN
    ip4tables("-A RESERVED_NET_CHK -s 239.0.0.0/24 -j POST_INPUT_DROP_CHAIN");

    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //# IPv6 not 2000::/3 is non-Global Unicast
      //ip6tables -A RESERVED_NET_CHK ! -s 2000::/3 -j POST_INPUT_DROP_CHAIN
      ip6tables("-A RESERVED_NET_CHK ! -s 2000::/3 -j POST_INPUT_DROP_CHAIN");
    //fi
    }
  //fi
  }
//}
}


//################################################################################################################
//## Chain SPOOF_CHK - Check if the source address is not spoofed                                               ##
//################################################################################################################
void //setup_spoof_chk_chain()
setup_spoof_chk_chain(void)
//{
{
char *local1IFS = NULL;;
char *r_INTERNAL_NET1 = NULL;;
char *net = NULL;;
char *strtok3_FREE = NULL;;
char *interface = NULL;;
char *local2IFS = NULL;;
char *strtok2_FREE = NULL;;
char *strtok1_FREE = NULL;;
char *local3IFS = NULL;;
char *r_DMZ_NET1 = NULL;;
char *r_DMZ_IF1 = NULL;;
char *local4IFS = NULL;;
char *strtok4_FREE = NULL;;
char *r_INT_IF1 = NULL;;

  //# Anti-spoof protection for the internal net
  //if [ -n "$INT_IF" -a -n "$INTERNAL_NET" ]; then
  if  (  (((INT_IF!=NULL)&&(strlen(INT_IF)!=0))&&((INTERNAL_NET!=NULL)&&(strlen(INTERNAL_NET)!=0))) )
  {
    //if [ "$INTERNAL_NET_ANTISPOOF" != "0" ]; then
    if  (  (strcmp(INTERNAL_NET_ANTISPOOF,"0")!=0)  )
    {
      //printf "Setting up antispoof for INTERNAL net(s): "
      printf("Setting up antispoof for INTERNAL net(s): ");
      //IFS=' ,'
      IFS=" ,";
      //for net in $INTERNAL_NET; do
      local1IFS = IFS;
      if (INTERNAL_NET != NULL) strtok1_FREE = strdup(INTERNAL_NET);
      if (INTERNAL_NET != NULL) for (net = strtok_r(strtok1_FREE, local1IFS, &r_INTERNAL_NET1); net != NULL; net = strtok_r(NULL, local1IFS, &r_INTERNAL_NET1))
      {
        //printf "$net "
        printf("%s ", net);
        //for interface in $INT_IF; do
        local2IFS = IFS;
        if (INT_IF != NULL) strtok2_FREE = strdup(INT_IF);
        if (INT_IF != NULL) for (interface = strtok_r(strtok2_FREE, local2IFS, &r_INT_IF1); interface != NULL; interface = strtok_r(NULL, local2IFS, &r_INT_IF1))
        {
          //# Any internal net is valid
          //iptables -A SPOOF_CHK -i $interface -s $net -j RETURN
          iptables("-A SPOOF_CHK -i %s -s %s -j RETURN", interface, net);
        //done
        }
        //iptables -A SPOOF_CHK -s $net -m limit --limit 3/m -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Spoofed packet: "
        iptables("-A SPOOF_CHK -s %s -m limit --limit 3/m -j LOG --log-prefix \"AIF:Spoofed packet: \" --log-level %s", net, LOGLEVEL);
        //iptables -A SPOOF_CHK -s $net -j POST_INPUT_DROP_CHAIN
        iptables("-A SPOOF_CHK -s %s -j POST_INPUT_DROP_CHAIN", net);
      //done
      }
      //echo ""
      printf("" "\n");
    //else
    }
    else
    {
      //echo "Antispoof for INTERNAL net(s) DISABLED!"
      printf("Antispoof for INTERNAL net(s) DISABLED!" "\n");
    //fi
    }
  //fi
  }

  //# Anti-spoof protection for the DMZ net
  //if [ -n "$DMZ_IF" -a -n "$DMZ_NET" ]; then
  if  (  (((DMZ_IF!=NULL)&&(strlen(DMZ_IF)!=0))&&((DMZ_NET!=NULL)&&(strlen(DMZ_NET)!=0))) )
  {
    //if [ "$DMZ_NET_ANTISPOOF" != "0" ]; then
    if  (  (strcmp(DMZ_NET_ANTISPOOF,"0")!=0)  )
    {
      //printf "Setting up antispoof for DMZ net(s): "
      printf("Setting up antispoof for DMZ net(s): ");
      //IFS=' ,'
      IFS=" ,";
      //for net in $DMZ_NET; do
      local3IFS = IFS;
      if (DMZ_NET != NULL) strtok3_FREE = strdup(DMZ_NET);
      if (DMZ_NET != NULL) for (net = strtok_r(strtok3_FREE, local3IFS, &r_DMZ_NET1); net != NULL; net = strtok_r(NULL, local3IFS, &r_DMZ_NET1))
      {
        //printf "$net "
        printf("%s ", net);
        //for interface in $DMZ_IF; do
        local4IFS = IFS;
        if (DMZ_IF != NULL) strtok4_FREE = strdup(DMZ_IF);
        if (DMZ_IF != NULL) for (interface = strtok_r(strtok4_FREE, local4IFS, &r_DMZ_IF1); interface != NULL; interface = strtok_r(NULL, local4IFS, &r_DMZ_IF1))
        {
          //# Any dmz net is valid
          //iptables -A SPOOF_CHK -i $interface -s $net -j RETURN
          iptables("-A SPOOF_CHK -i %s -s %s -j RETURN", interface, net);
        //done
        }
        //iptables -A SPOOF_CHK -s $net -m limit --limit 3/m -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Spoofed packet: "
        iptables("-A SPOOF_CHK -s %s -m limit --limit 3/m -j LOG --log-prefix \"AIF:Spoofed packet: \" --log-level %s", net, LOGLEVEL);
        //iptables -A SPOOF_CHK -s $net -j POST_INPUT_DROP_CHAIN
        iptables("-A SPOOF_CHK -s %s -j POST_INPUT_DROP_CHAIN", net);
      //done
      }
      //echo ""
      printf("" "\n");
    //else
    }
    else
    {
      //echo "Antispoof for DMZ net(s) DISABLED!"
      printf("Antispoof for DMZ net(s) DISABLED!" "\n");
    //fi
    }
  //fi
  }

  //# Everything else is valid
  //iptables -A SPOOF_CHK -j RETURN
  iptables("-A SPOOF_CHK -j RETURN");
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);

//}
}


//################################################################
//# Setup rules to forward INET IPv6 and non-NAT'ed IPv4 traffic #
//################################################################
void //setup_inet_forward_rules()
setup_inet_forward_rules(void)
//{
{
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *dhosts1_FREE = NULL;;
char *local15IFS = NULL;;
char *if_shosts6_FREE = NULL;;
char *r_dhosts1_FREE1 = NULL;;
char *strtok10_FREE = NULL;;
char *dhosts_ports5_FREE = NULL;;
char *local5IFS = NULL;;
char *if_shosts1_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *r_interfaces3 = NULL;;
char *strtok9_FREE = NULL;;
char *dhosts_ports = NULL;;
char *local13IFS = NULL;;
char *if_shosts5_FREE = NULL;;
char *dhosts_ports4_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *r_INET_FORWARD_IP1 = NULL;;
char *shost = NULL;;
char *strtok13_FREE = NULL;;
char *rule6_FREE = NULL;;
char *rule = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *if_shosts = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *strtok8_FREE = NULL;;
char *dhosts3_FREE = NULL;;
char *dhost = NULL;;
char *interface = NULL;;
char *if_shosts4_FREE = NULL;;
char *dhosts_ports3_FREE = NULL;;
char *r_dhosts2_FREE1 = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *shosts3_FREE = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *local11IFS = NULL;;
char *show_if_ip1_FREE = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *dhosts2_FREE = NULL;;
char *if_shosts3_FREE = NULL;;
char *r_INET_FORWARD_TCP1 = NULL;;
char *local10IFS = NULL;;
char *dhosts_ports2_FREE = NULL;;
char *shosts = NULL;;
char *dhosts_ports6_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *rule4_FREE = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *r_INET_FORWARD_UDP1 = NULL;;
char *strtok11_FREE = NULL;;
char *local7IFS = NULL;;
char *if_shosts2_FREE = NULL;;
char *dhosts_ports1_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *dhosts = NULL;;
char *r_dhosts3_FREE1 = NULL;;
char *shosts1_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *r_shosts2_FREE1 = NULL;;
char *rule3_FREE = NULL;;

  //# TCP ports to ALLOW for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_FORWARD_TCP; do
  local1IFS = IFS;
  if (INET_FORWARD_TCP != NULL) strtok1_FREE = strdup(INET_FORWARD_TCP);
  if (INET_FORWARD_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_INET_FORWARD_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_INET_FORWARD_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts" "$EXT_IF"`
    if_shosts1_FREE = get_ifs(if_shosts, EXT_IF);
    interfaces=if_shosts1_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts2_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts2_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule2_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports1_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports1_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports2_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports2_FREE;;

    //echo "$(show_if_ip "$interfaces")Forwarding(non-NAT) TCP port(s): $ports from $shosts(INET) to $dhosts"
    show_if_ip1_FREE = show_if_ip(interfaces, NULL);
    printf("%s Forwarding(non-NAT) TCP port(s): %s from %s(INET) to %s;" "\n", show_if_ip1_FREE, ports, shosts, dhosts);

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local2IFS = IFS;
    if (shosts1_FREE != NULL) strtok2_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok2_FREE, local2IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local2IFS, &r_shosts1_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts1_FREE = ip_range(dhosts, NULL);
      local3IFS = IFS;
      if (dhosts1_FREE != NULL) strtok3_FREE = strdup(dhosts1_FREE);
      if (dhosts1_FREE != NULL) for (dhost = strtok_r(strtok3_FREE, local3IFS, &r_dhosts1_FREE1); dhost != NULL; dhost = strtok_r(NULL, local3IFS, &r_dhosts1_FREE1))
      {
        //for port in $ports; do
        local4IFS = IFS;
        if (ports != NULL) strtok4_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok4_FREE, local4IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local4IFS, &r_ports1))
        {
          //for interface in $interfaces; do
          local5IFS = IFS;
          if (interfaces != NULL) strtok5_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok5_FREE, local5IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local5IFS, &r_interfaces1))
          {
            //iptables -A EXT_FORWARD_IN_CHAIN -i $interface ! -o $interface -s $shost -d $dhost -p tcp --dport $port -j ACCEPT
            iptables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p tcp --dport %s -j ACCEPT", interface, interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to ALLOW for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_FORWARD_UDP; do
  local6IFS = IFS;
  if (INET_FORWARD_UDP != NULL) strtok6_FREE = strdup(INET_FORWARD_UDP);
  if (INET_FORWARD_UDP != NULL) for (rule = strtok_r(strtok6_FREE, local6IFS, &r_INET_FORWARD_UDP1); rule != NULL; rule = strtok_r(NULL, local6IFS, &r_INET_FORWARD_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts" "$EXT_IF"`
    if_shosts3_FREE = get_ifs(if_shosts, EXT_IF);
    interfaces=if_shosts3_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts4_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts4_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule4_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports3_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports3_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports4_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports4_FREE;;

    //echo "$(show_if_ip "$interfaces")Forwarding(non-NAT) UDP port(s): $ports from $shosts(INET) to $dhosts"
    show_if_ip2_FREE = show_if_ip(interfaces, NULL);
    printf("%s Forwarding(non-NAT) UDP port(s): %s from %s(INET) to %s;" "\n", show_if_ip2_FREE, ports, shosts, dhosts);

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local7IFS = IFS;
    if (shosts2_FREE != NULL) strtok7_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok7_FREE, local7IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local7IFS, &r_shosts2_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts2_FREE = ip_range(dhosts, NULL);
      local8IFS = IFS;
      if (dhosts2_FREE != NULL) strtok8_FREE = strdup(dhosts2_FREE);
      if (dhosts2_FREE != NULL) for (dhost = strtok_r(strtok8_FREE, local8IFS, &r_dhosts2_FREE1); dhost != NULL; dhost = strtok_r(NULL, local8IFS, &r_dhosts2_FREE1))
      {
        //for port in $ports; do
        local9IFS = IFS;
        if (ports != NULL) strtok9_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok9_FREE, local9IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local9IFS, &r_ports2))
        {
          //for interface in $interfaces; do
          local10IFS = IFS;
          if (interfaces != NULL) strtok10_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok10_FREE, local10IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local10IFS, &r_interfaces2))
          {
            //iptables -A EXT_FORWARD_IN_CHAIN -i $interface ! -o $interface -s $shost -d $dhost -p udp --dport $port -j ACCEPT
            iptables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s -j ACCEPT", interface, interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to ALLOW for certain INET hosts
  //######################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_FORWARD_IP; do
  local11IFS = IFS;
  if (INET_FORWARD_IP != NULL) strtok11_FREE = strdup(INET_FORWARD_IP);
  if (INET_FORWARD_IP != NULL) for (rule = strtok_r(strtok11_FREE, local11IFS, &r_INET_FORWARD_IP1); rule != NULL; rule = strtok_r(NULL, local11IFS, &r_INET_FORWARD_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts" "$EXT_IF"`
    if_shosts5_FREE = get_ifs(if_shosts, EXT_IF);
    interfaces=if_shosts5_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts6_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts6_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule6_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports5_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports5_FREE;;
    //protos=`get_ports_hp "$dhosts_ports"`
    dhosts_ports6_FREE = get_ports_hp(dhosts_ports, NULL);
    protos=dhosts_ports6_FREE;;

    //echo "$(show_if_ip "$interfaces")Forwarding(non-NAT) IP protocol(s): $protos from $shosts(INET) to $dhosts"
    show_if_ip3_FREE = show_if_ip(interfaces, NULL);
    printf("%s Forwarding(non-NAT) IP protocol(s): %s from %s(INET) to %s;" "\n", show_if_ip3_FREE, protos, shosts, dhosts);

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local12IFS = IFS;
    if (shosts3_FREE != NULL) strtok12_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok12_FREE, local12IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local12IFS, &r_shosts3_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts3_FREE = ip_range(dhosts, NULL);
      local13IFS = IFS;
      if (dhosts3_FREE != NULL) strtok13_FREE = strdup(dhosts3_FREE);
      if (dhosts3_FREE != NULL) for (dhost = strtok_r(strtok13_FREE, local13IFS, &r_dhosts3_FREE1); dhost != NULL; dhost = strtok_r(NULL, local13IFS, &r_dhosts3_FREE1))
      {
        //for proto in $protos; do
        local14IFS = IFS;
        if (protos != NULL) strtok14_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok14_FREE, local14IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local14IFS, &r_protos1))
        {
          //for interface in $interfaces; do
          local15IFS = IFS;
          if (interfaces != NULL) strtok15_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok15_FREE, local15IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local15IFS, &r_interfaces3))
          {
            //iptables -A EXT_FORWARD_IN_CHAIN -i $interface ! -o $interface -s $shost -d $dhost -p $proto -j ACCEPT
            iptables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p %s -j ACCEPT", interface, interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (dhosts1_FREE != NULL) free(dhosts1_FREE);
if (if_shosts6_FREE != NULL) free(if_shosts6_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (dhosts_ports5_FREE != NULL) free(dhosts_ports5_FREE);
if (if_shosts1_FREE != NULL) free(if_shosts1_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (if_shosts5_FREE != NULL) free(if_shosts5_FREE);
if (dhosts_ports4_FREE != NULL) free(dhosts_ports4_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (dhosts3_FREE != NULL) free(dhosts3_FREE);
if (if_shosts4_FREE != NULL) free(if_shosts4_FREE);
if (dhosts_ports3_FREE != NULL) free(dhosts_ports3_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (dhosts2_FREE != NULL) free(dhosts2_FREE);
if (if_shosts3_FREE != NULL) free(if_shosts3_FREE);
if (dhosts_ports2_FREE != NULL) free(dhosts_ports2_FREE);
if (dhosts_ports6_FREE != NULL) free(dhosts_ports6_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (if_shosts2_FREE != NULL) free(if_shosts2_FREE);
if (dhosts_ports1_FREE != NULL) free(dhosts_ports1_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//##################################################
//# Setup chain for the DMZ input traffic          #
//##################################################
void //setup_dmz_input_chain()
setup_dmz_input_chain(void)
//{
{
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *host = NULL;;
char *r_DMZ_HOST_OPEN_UDP1 = NULL;;
char *r_DMZ_HOST_OPEN_IP1 = NULL;;
char *strtok10_FREE = NULL;;
char *icmpv6_type = NULL;;
char *local5IFS = NULL;;
char *protos = NULL;;
char *r_DMZ_OPEN_TCP1 = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_ICMPV6_SPECIAL_TYPES1 = NULL;;
char *strtok9_FREE = NULL;;
char *local13IFS = NULL;;
char *r_DMZ_OPEN_UDP1 = NULL;;
char *local3IFS = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *strtok13_FREE = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *hosts1_FREE = NULL;;
char *r_ports1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *strtok8_FREE = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *hosts = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *local11IFS = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *r_DMZ_OPEN_IP1 = NULL;;
char *local10IFS = NULL;;
char *rule4_FREE = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *hosts3_FREE = NULL;;
char *strtok11_FREE = NULL;;
char *r_DMZ_HOST_OPEN_TCP1 = NULL;;
char *local7IFS = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *strtok6_FREE = NULL;;
char *rule3_FREE = NULL;;

  //# Add TCP ports to allow for certain hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (DMZ_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(DMZ_HOST_OPEN_TCP);
  if (DMZ_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_DMZ_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_DMZ_HOST_OPEN_TCP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule1_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule1_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule2_FREE = get_ports_ihp(rule, NULL);
    ports=rule2_FREE;;

    //echo " Allowing $hosts(DMZ) for TCP port(s): $ports"
    printf(" Allowing %s(DMZ) for TCP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local2IFS = IFS;
    if (hosts1_FREE != NULL) strtok2_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok2_FREE, local2IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local2IFS, &r_hosts1_FREE1))
    {
      //for port in $ports; do
      local3IFS = IFS;
      if (ports != NULL) strtok3_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok3_FREE, local3IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local3IFS, &r_ports1))
      {
        //iptables -A DMZ_INPUT_CHAIN -s $host -p tcp --dport $port -j ACCEPT
        iptables("-A DMZ_INPUT_CHAIN -s %s -p tcp --dport %s -j ACCEPT", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# Add UDP ports to allow for certain hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_HOST_OPEN_UDP; do
  local4IFS = IFS;
  if (DMZ_HOST_OPEN_UDP != NULL) strtok4_FREE = strdup(DMZ_HOST_OPEN_UDP);
  if (DMZ_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok4_FREE, local4IFS, &r_DMZ_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local4IFS, &r_DMZ_HOST_OPEN_UDP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule3_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule3_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule4_FREE = get_ports_ihp(rule, NULL);
    ports=rule4_FREE;;

    //echo " Allowing $hosts(DMZ) for UDP port(s): $ports"
    printf(" Allowing %s(DMZ) for UDP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local5IFS = IFS;
    if (hosts2_FREE != NULL) strtok5_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok5_FREE, local5IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local5IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local6IFS = IFS;
      if (ports != NULL) strtok6_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok6_FREE, local6IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local6IFS, &r_ports2))
      {
        //iptables -A DMZ_INPUT_CHAIN -s $host -p udp --dport $port -j ACCEPT
        iptables("-A DMZ_INPUT_CHAIN -s %s -p udp --dport %s -j ACCEPT", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# Add IP protocols to allow for certain hosts
  //#############################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_HOST_OPEN_IP; do
  local7IFS = IFS;
  if (DMZ_HOST_OPEN_IP != NULL) strtok7_FREE = strdup(DMZ_HOST_OPEN_IP);
  if (DMZ_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok7_FREE, local7IFS, &r_DMZ_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local7IFS, &r_DMZ_HOST_OPEN_IP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule5_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule5_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule6_FREE = get_ports_ihp(rule, NULL);
    protos=rule6_FREE;;

    //echo " Allowing $hosts(DMZ) for IP protocol(s): $protos"
    printf(" Allowing %s(DMZ) for IP protocol(s): %s" "\n", hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local8IFS = IFS;
    if (hosts3_FREE != NULL) strtok8_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok8_FREE, local8IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local8IFS, &r_hosts3_FREE1))
    {
      //for proto in $protos; do
      local9IFS = IFS;
      if (protos != NULL) strtok9_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok9_FREE, local9IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local9IFS, &r_protos1))
      {
        //iptables -A DMZ_INPUT_CHAIN -s $host -p $proto -j ACCEPT
        iptables("-A DMZ_INPUT_CHAIN -s %s -p %s -j ACCEPT", host, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Adding TCP ports NOT to be firewalled
  //#######################################
  //if [ -n "$DMZ_OPEN_TCP" ]; then
  if  (  ((DMZ_OPEN_TCP!=NULL)&&(strlen(DMZ_OPEN_TCP)!=0))  )
  {
    //echo " Allowing TCP port(s): $DMZ_OPEN_TCP"
    printf(" Allowing TCP port(s): %s" "\n", DMZ_OPEN_TCP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $DMZ_OPEN_TCP; do
    local10IFS = IFS;
    if (DMZ_OPEN_TCP != NULL) strtok10_FREE = strdup(DMZ_OPEN_TCP);
    if (DMZ_OPEN_TCP != NULL) for (port = strtok_r(strtok10_FREE, local10IFS, &r_DMZ_OPEN_TCP1); port != NULL; port = strtok_r(NULL, local10IFS, &r_DMZ_OPEN_TCP1))
    {
      //iptables -A DMZ_INPUT_CHAIN -p tcp --dport $port -j ACCEPT
      iptables("-A DMZ_INPUT_CHAIN -p tcp --dport %s -j ACCEPT", port);
    //done
    }
  //fi
  }

  //# Adding UDP ports NOT to be firewalled
  //#######################################
  //if [ -n "$DMZ_OPEN_UDP" ]; then
  if  (  ((DMZ_OPEN_UDP!=NULL)&&(strlen(DMZ_OPEN_UDP)!=0))  )
  {
    //echo " Allowing UDP port(s): $DMZ_OPEN_UDP"
    printf(" Allowing UDP port(s): %s" "\n", DMZ_OPEN_UDP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $DMZ_OPEN_UDP; do
    local11IFS = IFS;
    if (DMZ_OPEN_UDP != NULL) strtok11_FREE = strdup(DMZ_OPEN_UDP);
    if (DMZ_OPEN_UDP != NULL) for (port = strtok_r(strtok11_FREE, local11IFS, &r_DMZ_OPEN_UDP1); port != NULL; port = strtok_r(NULL, local11IFS, &r_DMZ_OPEN_UDP1))
    {
      //iptables -A DMZ_INPUT_CHAIN -p udp --dport $port -j ACCEPT
      iptables("-A DMZ_INPUT_CHAIN -p udp --dport %s -j ACCEPT", port);
    //done
    }
  //fi
  }

  //# Adding IP protocols NOT to be firewalled
  //##########################################
  //if [ -n "$DMZ_OPEN_IP" ]; then
  if  (  ((DMZ_OPEN_IP!=NULL)&&(strlen(DMZ_OPEN_IP)!=0))  )
  {
    //echo " Allowing IP protocol(s): $DMZ_OPEN_IP"
    printf(" Allowing IP protocol(s): %s" "\n", DMZ_OPEN_IP);
    //IFS=' ,'
    IFS=" ,";
    //for proto in $DMZ_OPEN_IP; do
    local12IFS = IFS;
    if (DMZ_OPEN_IP != NULL) strtok12_FREE = strdup(DMZ_OPEN_IP);
    if (DMZ_OPEN_IP != NULL) for (proto = strtok_r(strtok12_FREE, local12IFS, &r_DMZ_OPEN_IP1); proto != NULL; proto = strtok_r(NULL, local12IFS, &r_DMZ_OPEN_IP1))
    {
      //iptables -A DMZ_INPUT_CHAIN -p $proto -j ACCEPT
      iptables("-A DMZ_INPUT_CHAIN -p %s -j ACCEPT", proto);
    //done
    }
  //fi
  }

  //# Allow to send ICMP packets?
  //#############################
  //if [ "$DMZ_OPEN_ICMP" != "0" ]; then
  if  (  (strcmp(DMZ_OPEN_ICMP,"0")!=0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
    //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ((strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif
    {
    //echo " Allowing ICMP-requests(ping)"
    printf(" Allowing ICMP-requests(ping)" "\n");
    //iptables -A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    }
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //for icmpv6_type in $ICMPV6_SPECIAL_TYPES; do
      local13IFS = IFS;
      if (ICMPV6_SPECIAL_TYPES != NULL) strtok13_FREE = strdup(ICMPV6_SPECIAL_TYPES);
      if (ICMPV6_SPECIAL_TYPES != NULL) for (icmpv6_type = strtok_r(strtok13_FREE, local13IFS, &r_ICMPV6_SPECIAL_TYPES1); icmpv6_type != NULL; icmpv6_type = strtok_r(NULL, local13IFS, &r_ICMPV6_SPECIAL_TYPES1))
      {
        //ip6tables -A DMZ_INPUT_CHAIN -p icmpv6 --icmpv6-type $icmpv6_type -m hl --hl-eq 255 -j ACCEPT
        ip6tables("-A DMZ_INPUT_CHAIN -p icmpv6 --icmpv6-type %s -m hl --hl-eq 255 -j ACCEPT", icmpv6_type);
      //done
      }
    //fi
    }
  //fi
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
    //iptables -A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop ICMP packets
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
  //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
  if ((strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif
{
  //iptables -A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A DMZ_INPUT_CHAIN -p icmp --icmp-type echo-request -j DROP");
}
  //# Log everything else
  //iptables -A DMZ_INPUT_CHAIN -m limit --limit 3/m -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ-INPUT denied: "
  iptables("-A DMZ_INPUT_CHAIN -m limit --limit 3/m -j LOG --log-prefix \"AIF:DMZ-INPUT denied: \" --log-level %s", LOGLEVEL);

  //# Everything else is denied
  //iptables -A DMZ_INPUT_CHAIN -j DROP
  iptables("-A DMZ_INPUT_CHAIN -j DROP");
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//##################################################
//# Setup chain for the DMZ-to-LAN forward traffic #
//##################################################
void //setup_dmz_lan_forward_chain()
setup_dmz_lan_forward_chain(void)
//{
{
char *r_DMZ_LAN_HOST_OPEN_UDP1 = NULL;;
char *local6IFS = NULL;;
char *strtok1_FREE = NULL;;
char *dhosts1_FREE = NULL;;
char *r_dhosts1_FREE1 = NULL;;
char *strtok10_FREE = NULL;;
char *rule8_FREE1_FREE = NULL;;
char *local5IFS = NULL;;
char *protos = NULL;;
char *rule7_FREE = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *strtok9_FREE = NULL;;
char *rule6_FREE1_FREE = NULL;;
char *local3IFS = NULL;;
char *rule4_FREE1_FREE = NULL;;
char *shost = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *local12IFS = NULL;;
char *rule2_FREE1_FREE = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *r_ports1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *strtok8_FREE = NULL;;
char *dhosts3_FREE = NULL;;
char *dhost = NULL;;
char *r_dhosts2_FREE1 = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *r_DMZ_LAN_HOST_OPEN_IP1 = NULL;;
char *shosts3_FREE = NULL;;
char *rule9_FREE1_FREE = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *local11IFS = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *dhosts2_FREE = NULL;;
char *local10IFS = NULL;;
char *rule7_FREE1_FREE = NULL;;
char *shosts = NULL;;
char *rule9_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *rule4_FREE = NULL;;
char *local8IFS = NULL;;
char *rule5_FREE1_FREE = NULL;;
char *strtok2_FREE = NULL;;
char *rule3_FREE1_FREE = NULL;;
char *r_DMZ_LAN_HOST_OPEN_TCP1 = NULL;;
char *strtok11_FREE = NULL;;
char *local7IFS = NULL;;
char *rule1_FREE1_FREE = NULL;;
char *dhosts = NULL;;
char *r_dhosts3_FREE1 = NULL;;
char *rule8_FREE = NULL;;
char *shosts1_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *rule3_FREE = NULL;;
char *r_shosts2_FREE1 = NULL;;

  //echo " Setting up DMZ->LAN policy"
  printf(" Setting up DMZ->LAN policy" "\n");

  //# TCP ports to ALLOW for certain DMZ hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_LAN_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (DMZ_LAN_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(DMZ_LAN_HOST_OPEN_TCP);
  if (DMZ_LAN_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_DMZ_LAN_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_DMZ_LAN_HOST_OPEN_TCP1))
  {
    //shosts=`get_hosts_ih $(echo "$rule" |cut -s -d'>' -f1) "$ANYHOST"`
    rule1_FREE = getfield(rule, ">", 1);
    rule1_FREE1_FREE = get_hosts_ih(rule1_FREE, ANYHOST);
    shosts=rule1_FREE1_FREE;;
    //dhosts=`get_hosts_hp $(echo "$rule" |cut -s -d'>' -f2)`
    rule2_FREE = getfield(rule, ">", 2);
    rule2_FREE1_FREE = get_hosts_hp(rule2_FREE, NULL);
    dhosts=rule2_FREE1_FREE;;
    //ports=`get_ports_hp $(echo "$rule" |cut -s -d'>' -f2) "$ANYPORT"`
    rule3_FREE = getfield(rule, ">", 2);
    rule3_FREE1_FREE = get_ports_hp(rule3_FREE, ANYPORT);
    ports=rule3_FREE1_FREE;;

    //echo "  Allowing $shosts(DMZ) to $dhosts(LAN) for TCP port(s): $ports"
    printf("  Allowing %s(DMZ) to %s(LAN) for TCP port(s): %s" "\n", shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local2IFS = IFS;
    if (shosts1_FREE != NULL) strtok2_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok2_FREE, local2IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local2IFS, &r_shosts1_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts1_FREE = ip_range(dhosts, NULL);
      local3IFS = IFS;
      if (dhosts1_FREE != NULL) strtok3_FREE = strdup(dhosts1_FREE);
      if (dhosts1_FREE != NULL) for (dhost = strtok_r(strtok3_FREE, local3IFS, &r_dhosts1_FREE1); dhost != NULL; dhost = strtok_r(NULL, local3IFS, &r_dhosts1_FREE1))
      {
        //for port in $ports; do
        local4IFS = IFS;
        if (ports != NULL) strtok4_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok4_FREE, local4IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local4IFS, &r_ports1))
        {
          //iptables -A DMZ_LAN_FORWARD_CHAIN -s $shost -d $dhost -p tcp --dport $port -j ACCEPT
          iptables("-A DMZ_LAN_FORWARD_CHAIN -s %s -d %s -p tcp --dport %s -j ACCEPT", shost, dhost, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to ALLOW for certain DMZ hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_LAN_HOST_OPEN_UDP; do
  local5IFS = IFS;
  if (DMZ_LAN_HOST_OPEN_UDP != NULL) strtok5_FREE = strdup(DMZ_LAN_HOST_OPEN_UDP);
  if (DMZ_LAN_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok5_FREE, local5IFS, &r_DMZ_LAN_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local5IFS, &r_DMZ_LAN_HOST_OPEN_UDP1))
  {
    //shosts=`get_hosts_ih $(echo "$rule" |cut -s -d'>' -f1) "$ANYHOST"`
    rule4_FREE = getfield(rule, ">", 1);
    rule4_FREE1_FREE = get_hosts_ih(rule4_FREE, ANYHOST);
    shosts=rule4_FREE1_FREE;;
    //dhosts=`get_hosts_hp $(echo "$rule" |cut -s -d'>' -f2)`
    rule5_FREE = getfield(rule, ">", 2);
    rule5_FREE1_FREE = get_hosts_hp(rule5_FREE, NULL);
    dhosts=rule5_FREE1_FREE;;
    //ports=`get_ports_hp $(echo "$rule" |cut -s -d'>' -f2) "$ANYPORT"`
    rule6_FREE = getfield(rule, ">", 2);
    rule6_FREE1_FREE = get_ports_hp(rule6_FREE, ANYPORT);
    ports=rule6_FREE1_FREE;;

    //echo "  Allowing $shosts(DMZ) to $dhosts(LAN) for UDP port(s): $ports"
    printf("  Allowing %s(DMZ) to %s(LAN) for UDP port(s): %s" "\n", shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local6IFS = IFS;
    if (shosts2_FREE != NULL) strtok6_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok6_FREE, local6IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local6IFS, &r_shosts2_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts2_FREE = ip_range(dhosts, NULL);
      local7IFS = IFS;
      if (dhosts2_FREE != NULL) strtok7_FREE = strdup(dhosts2_FREE);
      if (dhosts2_FREE != NULL) for (dhost = strtok_r(strtok7_FREE, local7IFS, &r_dhosts2_FREE1); dhost != NULL; dhost = strtok_r(NULL, local7IFS, &r_dhosts2_FREE1))
      {
        //for port in $ports; do
        local8IFS = IFS;
        if (ports != NULL) strtok8_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok8_FREE, local8IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local8IFS, &r_ports2))
        {
          //iptables -A DMZ_LAN_FORWARD_CHAIN -s $shost -d $dhost -p udp --dport $port -j ACCEPT
          iptables("-A DMZ_LAN_FORWARD_CHAIN -s %s -d %s -p udp --dport %s -j ACCEPT", shost, dhost, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# IP protocol(s) to ALLOW for certain DMZ hosts
  //###############################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_LAN_HOST_OPEN_IP; do
  local9IFS = IFS;
  if (DMZ_LAN_HOST_OPEN_IP != NULL) strtok9_FREE = strdup(DMZ_LAN_HOST_OPEN_IP);
  if (DMZ_LAN_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok9_FREE, local9IFS, &r_DMZ_LAN_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local9IFS, &r_DMZ_LAN_HOST_OPEN_IP1))
  {
    //shosts=`get_hosts_ih $(echo "$rule" |cut -s -d'>' -f1) "$ANYHOST"`
    rule7_FREE = getfield(rule, ">", 1);
    rule7_FREE1_FREE = get_hosts_ih(rule7_FREE, ANYHOST);
    shosts=rule7_FREE1_FREE;;
    //dhosts=`get_hosts_hp $(echo "$rule" |cut -s -d'>' -f2)`
    rule8_FREE = getfield(rule, ">", 2);
    rule8_FREE1_FREE = get_hosts_hp(rule8_FREE, NULL);
    dhosts=rule8_FREE1_FREE;;
    //protos=`get_ports_hp $(echo "$rule" |cut -s -d'>' -f2)`
    rule9_FREE = getfield(rule, ">", 2);
    rule9_FREE1_FREE = get_ports_hp(rule9_FREE, NULL);
    protos=rule9_FREE1_FREE;;

    //echo "  Allowing $shosts(DMZ) to $dhosts(LAN) for IP protocol(s): $protos"
    printf("  Allowing %s(DMZ) to %s(LAN) for IP protocol(s): %s" "\n", shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local10IFS = IFS;
    if (shosts3_FREE != NULL) strtok10_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok10_FREE, local10IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local10IFS, &r_shosts3_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts3_FREE = ip_range(dhosts, NULL);
      local11IFS = IFS;
      if (dhosts3_FREE != NULL) strtok11_FREE = strdup(dhosts3_FREE);
      if (dhosts3_FREE != NULL) for (dhost = strtok_r(strtok11_FREE, local11IFS, &r_dhosts3_FREE1); dhost != NULL; dhost = strtok_r(NULL, local11IFS, &r_dhosts3_FREE1))
      {
        //for proto in $protos; do
        local12IFS = IFS;
        if (protos != NULL) strtok12_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok12_FREE, local12IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local12IFS, &r_protos1))
        {
          //iptables -A DMZ_LAN_FORWARD_CHAIN -s $shost -d $dhost -p $proto -j ACCEPT
          iptables("-A DMZ_LAN_FORWARD_CHAIN -s %s -d %s -p %s -j ACCEPT", shost, dhost, proto);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow ICMP-requests(ping) for DMZ->LAN?
  //##########################################
  //if [ "$DMZ_LAN_OPEN_ICMP" = "1" ]; then
  if  (  (strcmp(DMZ_LAN_OPEN_ICMP,"1")==0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
  //  if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
  if ((strcmp(PORT_SCAN_DOS_DISABLE,"0")==0) )
#endif
    {
    //echo "  Allowing ICMP-requests(ping)"
    printf("  Allowing ICMP-requests(ping)" "\n");
    //iptables -A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    }
  //fi
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
    //iptables -A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop ICMP packets
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
  //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
 if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif
{
  //iptables -A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A DMZ_LAN_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP");
}
  //# Log everything else
  //iptables -A DMZ_LAN_FORWARD_CHAIN -m limit --limit 3/m -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->LAN denied: "
  iptables("-A DMZ_LAN_FORWARD_CHAIN -m limit --limit 3/m -j LOG --log-prefix \"AIF:DMZ->LAN denied: \" --log-level %s", LOGLEVEL);

  //# Everything else is denied
  //iptables -A DMZ_LAN_FORWARD_CHAIN -j DROP
  iptables("-A DMZ_LAN_FORWARD_CHAIN -j DROP");
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (dhosts1_FREE != NULL) free(dhosts1_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (rule8_FREE1_FREE != NULL) free(rule8_FREE1_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (rule6_FREE1_FREE != NULL) free(rule6_FREE1_FREE);
if (rule4_FREE1_FREE != NULL) free(rule4_FREE1_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (rule2_FREE1_FREE != NULL) free(rule2_FREE1_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (dhosts3_FREE != NULL) free(dhosts3_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (rule9_FREE1_FREE != NULL) free(rule9_FREE1_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (dhosts2_FREE != NULL) free(dhosts2_FREE);
if (rule7_FREE1_FREE != NULL) free(rule7_FREE1_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (rule5_FREE1_FREE != NULL) free(rule5_FREE1_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (rule3_FREE1_FREE != NULL) free(rule3_FREE1_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (rule1_FREE1_FREE != NULL) free(rule1_FREE1_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//###################################################
//# Setup chain for the INET-to-DMZ forward traffic #
//###################################################
void //setup_inet_dmz_forward_chain()
setup_inet_dmz_forward_chain(void)
//{
{
char *show_if_ip9_FREE = NULL;;
char *r_INET_DMZ_HOST_DENY_IP1 = NULL;;
char *strtok42_FREE = NULL;;
char *strtok39_FREE = NULL;;
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *dhosts1_FREE = NULL;;
char *show_if_ip4_FREE = NULL;;
char *rule15_FREE = NULL;;
char *shosts5_FREE = NULL;;
char *strtok54_FREE = NULL;;
char *rule10_FREE = NULL;;
char *rule27_FREE = NULL;;
char *local40IFS = NULL;;
char *local37IFS = NULL;;
char *dhosts5_FREE = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *if_shosts10_FREE = NULL;;
char *if_shosts6_FREE = NULL;;
char *r_dhosts1_FREE1 = NULL;;
char *strtok10_FREE = NULL;;
char *dhosts_ports5_FREE = NULL;;
char *local5IFS = NULL;;
char *if_shosts1_FREE = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *r_INET_DMZ_HOST_DENY_TCP1 = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *strtok34_FREE = NULL;;
char *dhosts_ports9_FREE = NULL;;
char *local36IFS = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok46_FREE = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *show_if_ip8_FREE = NULL;;
char *strtok41_FREE = NULL;;
char *strtok38_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *local50IFS = NULL;;
char *local47IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *rule14_FREE = NULL;;
char *local25IFS = NULL;;
char *r_interfaces3 = NULL;;
char *strtok53_FREE = NULL;;
char *r_INET_DMZ_OPEN_IP1 = NULL;;
char *r_INET_DMZ_HOST_DENY_UDP1 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *destips = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *rule26_FREE = NULL;;
char *local35IFS = NULL;;
char *r_interfaces7 = NULL;;
char *r_interfaces8 = NULL;;
char *dhosts4_FREE = NULL;;
char *dhosts_ports = NULL;;
char *r_interfaces9 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *if_shosts5_FREE = NULL;;
char *r_INET_DMZ_HOST_OPEN_UDP1 = NULL;;
char *r_INET_DMZ_HOST_OPEN_TCP1 = NULL;;
char *dhosts_ports4_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *local46IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *if_shosts9_FREE = NULL;;
char *shost = NULL;;
char *show_if_ip12_FREE = NULL;;
char *strtok13_FREE = NULL;;
char *strtok33_FREE = NULL;;
char *shosts4_FREE = NULL;;
char *dhosts_ports8_FREE = NULL;;
char *local34IFS = NULL;;
char *rule6_FREE = NULL;;
char *rule = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok45_FREE = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *r_dhosts4_FREE1 = NULL;;
char *if_shosts = NULL;;
char *strtok40_FREE = NULL;;
char *strtok37_FREE = NULL;;
char *r_dhosts6_FREE1 = NULL;;
char *local45IFS = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *rule13_FREE = NULL;;
char *local23IFS = NULL;;
char *r_shosts5_FREE1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *strtok52_FREE = NULL;;
char *strtok49_FREE = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_protos3 = NULL;;
char *destip = NULL;;
char *r_ports4 = NULL;;
char *r_protos4 = NULL;;
char *r_ports5 = NULL;;
char *rule25_FREE = NULL;;
char *r_ports6 = NULL;;
char *r_ports7 = NULL;;
char *dhosts3_FREE = NULL;;
char *r_ports8 = NULL;;
char *dhost = NULL;;
char *interface = NULL;;
char *r_INET_DMZ_DENY_IP1 = NULL;;
char *rule20_FREE = NULL;;
char *if_shosts4_FREE = NULL;;
char *dhosts_ports3_FREE = NULL;;
char *local44IFS = NULL;;
char *r_dhosts2_FREE1 = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *show_if_ip11_FREE = NULL;;
char *strtok32_FREE = NULL;;
char *strtok29_FREE = NULL;;
char *dhosts_ports7_FREE = NULL;;
char *shosts3_FREE = NULL;;
char *local9IFS = NULL;;
char *dhosts_ports12_FREE = NULL;;
char *rule5_FREE = NULL;;
char *strtok44_FREE = NULL;;
char *local33IFS = NULL;;
char *strtok3_FREE = NULL;;
char *r_destips1 = NULL;;
char *r_destips2 = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *r_destips3 = NULL;;
char *rule17_FREE = NULL;;
char *r_destips4 = NULL;;
char *local43IFS = NULL;;
char *r_destips5 = NULL;;
char *show_if_ip1_FREE = NULL;;
char *r_destips6 = NULL;;
char *rule12_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *local1IFS = NULL;;
char *rule29_FREE = NULL;;
char *strtok51_FREE = NULL;;
char *strtok7_FREE = NULL;;
char *rule24_FREE = NULL;;
char *if_shosts12_FREE = NULL;;
char *if_shosts8_FREE = NULL;;
char *local54IFS = NULL;;
char *strtok12_FREE = NULL;;
char *dhosts2_FREE = NULL;;
char *r_INET_DMZ_DENY_TCP1 = NULL;;
char *local32IFS = NULL;;
char *local29IFS = NULL;;
char *if_shosts3_FREE = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *dhosts_ports2_FREE = NULL;;
char *r_INET_DMZ_OPEN_TCP1 = NULL;;
char *strtok16_FREE = NULL;;
char *strtok36_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *r_INET_DMZ_HOST_OPEN_IP1 = NULL;;
char *shosts = NULL;;
char *show_if_ip10_FREE = NULL;;
char *rule9_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *dhosts_ports6_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *strtok48_FREE = NULL;;
char *local53IFS = NULL;;
char *dhosts_ports11_FREE = NULL;;
char *rule4_FREE = NULL;;
char *strtok43_FREE = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *r_INET_DMZ_DENY_UDP1 = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *shosts6_FREE = NULL;;
char *rule11_FREE = NULL;;
char *rule28_FREE = NULL;;
char *strtok50_FREE = NULL;;
char *local42IFS = NULL;;
char *local39IFS = NULL;;
char *r_INET_DMZ_OPEN_UDP1 = NULL;;
char *dhosts6_FREE = NULL;;
char *r_shosts4_FREE1 = NULL;;
char *rule23_FREE = NULL;;
char *r_shosts6_FREE1 = NULL;;
char *if_shosts11_FREE = NULL;;
char *if_shosts7_FREE = NULL;;
char *local52IFS = NULL;;
char *local49IFS = NULL;;
char *strtok11_FREE = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *if_shosts2_FREE = NULL;;
char *r_interfaces10 = NULL;;
char *strtok23_FREE = NULL;;
char *dhosts_ports1_FREE = NULL;;
char *r_interfaces11 = NULL;;
char *r_interfaces12 = NULL;;
char *rule30_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *dhosts = NULL;;
char *strtok35_FREE = NULL;;
char *local41IFS = NULL;;
char *local38IFS = NULL;;
char *rule8_FREE = NULL;;
char *r_dhosts3_FREE1 = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *r_dhosts5_FREE1 = NULL;;
char *local16IFS = NULL;;
char *shosts1_FREE = NULL;;
char *strtok47_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *local51IFS = NULL;;
char *local48IFS = NULL;;
char *dhosts_ports10_FREE = NULL;;
char *r_shosts2_FREE1 = NULL;;
char *rule3_FREE = NULL;;

  //echo " Setting up INET->DMZ policy"
  printf(" Setting up INET->DMZ policy" "\n");

  //# TCP ports to ALLOW for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (INET_DMZ_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(INET_DMZ_HOST_OPEN_TCP);
  if (INET_DMZ_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_INET_DMZ_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_INET_DMZ_HOST_OPEN_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts1_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts1_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts2_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts2_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule2_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports1_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports1_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports2_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports2_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(INET) to $dhosts(DMZ) for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(INET) to %s(DMZ) for TCP port(s): %s;" "\n", show_if_ip1_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local2IFS = IFS;
    if (shosts1_FREE != NULL) strtok2_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok2_FREE, local2IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local2IFS, &r_shosts1_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts1_FREE = ip_range(dhosts, NULL);
      local3IFS = IFS;
      if (dhosts1_FREE != NULL) strtok3_FREE = strdup(dhosts1_FREE);
      if (dhosts1_FREE != NULL) for (dhost = strtok_r(strtok3_FREE, local3IFS, &r_dhosts1_FREE1); dhost != NULL; dhost = strtok_r(NULL, local3IFS, &r_dhosts1_FREE1))
      {
        //for port in $ports; do
        local4IFS = IFS;
        if (ports != NULL) strtok4_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok4_FREE, local4IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local4IFS, &r_ports1))
        {
          //for interface in $interfaces; do
          local5IFS = IFS;
          if (interfaces != NULL) strtok5_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok5_FREE, local5IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local5IFS, &r_interfaces1))
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p tcp --dport $port -j ACCEPT
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to ALLOW for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_OPEN_UDP; do
  local6IFS = IFS;
  if (INET_DMZ_HOST_OPEN_UDP != NULL) strtok6_FREE = strdup(INET_DMZ_HOST_OPEN_UDP);
  if (INET_DMZ_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok6_FREE, local6IFS, &r_INET_DMZ_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local6IFS, &r_INET_DMZ_HOST_OPEN_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts3_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts3_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts4_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts4_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule4_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports3_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports3_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports4_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports4_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(INET) to $dhosts(DMZ) for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(INET) to %s(DMZ) for UDP port(s): %s;" "\n", show_if_ip2_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local7IFS = IFS;
    if (shosts2_FREE != NULL) strtok7_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok7_FREE, local7IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local7IFS, &r_shosts2_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts2_FREE = ip_range(dhosts, NULL);
      local8IFS = IFS;
      if (dhosts2_FREE != NULL) strtok8_FREE = strdup(dhosts2_FREE);
      if (dhosts2_FREE != NULL) for (dhost = strtok_r(strtok8_FREE, local8IFS, &r_dhosts2_FREE1); dhost != NULL; dhost = strtok_r(NULL, local8IFS, &r_dhosts2_FREE1))
      {
        //for port in $ports; do
        local9IFS = IFS;
        if (ports != NULL) strtok9_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok9_FREE, local9IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local9IFS, &r_ports2))
        {
          //for interface in $interfaces; do
          local10IFS = IFS;
          if (interfaces != NULL) strtok10_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok10_FREE, local10IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local10IFS, &r_interfaces2))
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p udp --dport $port -j ACCEPT
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p udp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to ALLOW for certain INET hosts
  //######################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_OPEN_IP; do
  local11IFS = IFS;
  if (INET_DMZ_HOST_OPEN_IP != NULL) strtok11_FREE = strdup(INET_DMZ_HOST_OPEN_IP);
  if (INET_DMZ_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok11_FREE, local11IFS, &r_INET_DMZ_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local11IFS, &r_INET_DMZ_HOST_OPEN_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts5_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts5_FREE;;
    //shosts=`get_hosts_ih "$if_shosts"`
    if_shosts6_FREE = get_hosts_ih(if_shosts, NULL);
    shosts=if_shosts6_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule6_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports5_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports5_FREE;;
    //protos=`get_ports_hp "$dhosts_ports"`
    dhosts_ports6_FREE = get_ports_hp(dhosts_ports, NULL);
    protos=dhosts_ports6_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(INET) to $dhosts(DMZ) for IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(INET) to %s(DMZ) for IP protocol(s): %s;" "\n", show_if_ip3_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local12IFS = IFS;
    if (shosts3_FREE != NULL) strtok12_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok12_FREE, local12IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local12IFS, &r_shosts3_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts3_FREE = ip_range(dhosts, NULL);
      local13IFS = IFS;
      if (dhosts3_FREE != NULL) strtok13_FREE = strdup(dhosts3_FREE);
      if (dhosts3_FREE != NULL) for (dhost = strtok_r(strtok13_FREE, local13IFS, &r_dhosts3_FREE1); dhost != NULL; dhost = strtok_r(NULL, local13IFS, &r_dhosts3_FREE1))
      {
        //for proto in $protos; do
        local14IFS = IFS;
        if (protos != NULL) strtok14_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok14_FREE, local14IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local14IFS, &r_protos1))
        {
          //for interface in $interfaces; do
          local15IFS = IFS;
          if (interfaces != NULL) strtok15_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok15_FREE, local15IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local15IFS, &r_interfaces3))
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p $proto -j ACCEPT
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p %s -j ACCEPT", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# TCP ports to DENY for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_DENY_TCP; do
  local16IFS = IFS;
  if (INET_DMZ_HOST_DENY_TCP != NULL) strtok16_FREE = strdup(INET_DMZ_HOST_DENY_TCP);
  if (INET_DMZ_HOST_DENY_TCP != NULL) for (rule = strtok_r(strtok16_FREE, local16IFS, &r_INET_DMZ_HOST_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local16IFS, &r_INET_DMZ_HOST_DENY_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule7_FREE = getfield(rule, ">", 1);
    if_shosts=rule7_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts7_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts7_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts8_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts8_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule8_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule8_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports7_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports7_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports8_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports8_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(INET) to $dhosts(DMZ) for TCP port(s): $ports"
    show_if_ip4_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(INET) to %s(DMZ) for TCP port(s): %s;" "\n", show_if_ip4_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts4_FREE = ip_range(shosts, NULL);
    local17IFS = IFS;
    if (shosts4_FREE != NULL) strtok17_FREE = strdup(shosts4_FREE);
    if (shosts4_FREE != NULL) for (shost = strtok_r(strtok17_FREE, local17IFS, &r_shosts4_FREE1); shost != NULL; shost = strtok_r(NULL, local17IFS, &r_shosts4_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts4_FREE = ip_range(dhosts, NULL);
      local18IFS = IFS;
      if (dhosts4_FREE != NULL) strtok18_FREE = strdup(dhosts4_FREE);
      if (dhosts4_FREE != NULL) for (dhost = strtok_r(strtok18_FREE, local18IFS, &r_dhosts4_FREE1); dhost != NULL; dhost = strtok_r(NULL, local18IFS, &r_dhosts4_FREE1))
      {
        //for port in $ports; do
        local19IFS = IFS;
        if (ports != NULL) strtok19_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local19IFS, &r_ports3))
        {
          //for interface in $interfaces; do
          local20IFS = IFS;
          if (interfaces != NULL) strtok20_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok20_FREE, local20IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local20IFS, &r_interfaces4))
          {
            //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET->DMZ denied: "
              iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET->DMZ denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p tcp --dport $port -j DROP
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for certain INET hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_DENY_UDP; do
  local21IFS = IFS;
  if (INET_DMZ_HOST_DENY_UDP != NULL) strtok21_FREE = strdup(INET_DMZ_HOST_DENY_UDP);
  if (INET_DMZ_HOST_DENY_UDP != NULL) for (rule = strtok_r(strtok21_FREE, local21IFS, &r_INET_DMZ_HOST_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local21IFS, &r_INET_DMZ_HOST_DENY_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule9_FREE = getfield(rule, ">", 1);
    if_shosts=rule9_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts9_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts9_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts10_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts10_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule10_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule10_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports9_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports9_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports10_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports10_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(INET) to $dhosts(DMZ) for UDP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(INET) to %s(DMZ) for UDP port(s): %s;" "\n", show_if_ip5_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts5_FREE = ip_range(shosts, NULL);
    local22IFS = IFS;
    if (shosts5_FREE != NULL) strtok22_FREE = strdup(shosts5_FREE);
    if (shosts5_FREE != NULL) for (shost = strtok_r(strtok22_FREE, local22IFS, &r_shosts5_FREE1); shost != NULL; shost = strtok_r(NULL, local22IFS, &r_shosts5_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts5_FREE = ip_range(dhosts, NULL);
      local23IFS = IFS;
      if (dhosts5_FREE != NULL) strtok23_FREE = strdup(dhosts5_FREE);
      if (dhosts5_FREE != NULL) for (dhost = strtok_r(strtok23_FREE, local23IFS, &r_dhosts5_FREE1); dhost != NULL; dhost = strtok_r(NULL, local23IFS, &r_dhosts5_FREE1))
      {
        //for port in $ports; do
        local24IFS = IFS;
        if (ports != NULL) strtok24_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports4))
        {
          //for interface in $interfaces; do
          local25IFS = IFS;
          if (interfaces != NULL) strtok25_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok25_FREE, local25IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local25IFS, &r_interfaces5))
          {
            //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET->DMZ denied: "
              iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET->DMZ denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p udp --dport $port -j DROP
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p udp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to DENY for certain INET hosts
  //#####################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_HOST_DENY_IP; do
  local26IFS = IFS;
  if (INET_DMZ_HOST_DENY_IP != NULL) strtok26_FREE = strdup(INET_DMZ_HOST_DENY_IP);
  if (INET_DMZ_HOST_DENY_IP != NULL) for (rule = strtok_r(strtok26_FREE, local26IFS, &r_INET_DMZ_HOST_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local26IFS, &r_INET_DMZ_HOST_DENY_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule11_FREE = getfield(rule, ">", 1);
    if_shosts=rule11_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts11_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts11_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts12_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts12_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule12_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule12_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports11_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports11_FREE;;
    //protos=`get_ports_hp "$dhosts_ports"`
    dhosts_ports12_FREE = get_ports_hp(dhosts_ports, NULL);
    protos=dhosts_ports12_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(INET) to $dhosts(DMZ) for IP protocol(s): $protos"
    show_if_ip6_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(INET) to %s(DMZ) for IP protocol(s): %s;" "\n", show_if_ip6_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts6_FREE = ip_range(shosts, NULL);
    local27IFS = IFS;
    if (shosts6_FREE != NULL) strtok27_FREE = strdup(shosts6_FREE);
    if (shosts6_FREE != NULL) for (shost = strtok_r(strtok27_FREE, local27IFS, &r_shosts6_FREE1); shost != NULL; shost = strtok_r(NULL, local27IFS, &r_shosts6_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts6_FREE = ip_range(dhosts, NULL);
      local28IFS = IFS;
      if (dhosts6_FREE != NULL) strtok28_FREE = strdup(dhosts6_FREE);
      if (dhosts6_FREE != NULL) for (dhost = strtok_r(strtok28_FREE, local28IFS, &r_dhosts6_FREE1); dhost != NULL; dhost = strtok_r(NULL, local28IFS, &r_dhosts6_FREE1))
      {
        //for proto in $protos; do
        local29IFS = IFS;
        if (protos != NULL) strtok29_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_protos2))
        {
          //for interface in $interfaces; do
          local30IFS = IFS;
          if (interfaces != NULL) strtok30_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok30_FREE, local30IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local30IFS, &r_interfaces6))
          {
            //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p $proto  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET->DMZ denied: "
              iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET->DMZ denied: \" --log-level %s", interface, shost, dhost, proto, LOGLEVEL);
            //fi
            }
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -s $shost -d $dhost -p $proto -j DROP
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -s %s -d %s -p %s -j DROP", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain TCP ports to be used from the INET->DMZ?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_OPEN_TCP; do
  local31IFS = IFS;
  if (INET_DMZ_OPEN_TCP != NULL) strtok31_FREE = strdup(INET_DMZ_OPEN_TCP);
  if (INET_DMZ_OPEN_TCP != NULL) for (rule = strtok_r(strtok31_FREE, local31IFS, &r_INET_DMZ_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local31IFS, &r_INET_DMZ_OPEN_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //destips=`get_ips "$rule"`
    rule14_FREE = get_ips(rule, NULL);
    destips=rule14_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule15_FREE = get_ports_ip(rule, NULL);
    ports=rule15_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing TCP port(s): $ports"
    show_if_ip7_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing TCP port(s): %s;" "\n", show_if_ip7_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local32IFS = IFS;
    if (ports != NULL) strtok32_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok32_FREE, local32IFS, &r_ports5); port != NULL; port = strtok_r(NULL, local32IFS, &r_ports5))
    {
      //for destip in $destips; do
      local33IFS = IFS;
      if (destips != NULL) strtok33_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok33_FREE, local33IFS, &r_destips1); destip != NULL; destip = strtok_r(NULL, local33IFS, &r_destips1))
      {
        //for interface in $interfaces; do
        local34IFS = IFS;
        if (interfaces != NULL) strtok34_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok34_FREE, local34IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local34IFS, &r_interfaces7))
        {
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p tcp --dport $port -j ACCEPT
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p tcp --dport %s -j ACCEPT", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain UDP ports to be used from the INET->DMZ?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_OPEN_UDP; do
  local35IFS = IFS;
  if (INET_DMZ_OPEN_UDP != NULL) strtok35_FREE = strdup(INET_DMZ_OPEN_UDP);
  if (INET_DMZ_OPEN_UDP != NULL) for (rule = strtok_r(strtok35_FREE, local35IFS, &r_INET_DMZ_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local35IFS, &r_INET_DMZ_OPEN_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule16_FREE = get_ifs(rule, NULL);
    interfaces=rule16_FREE;;
    //destips=`get_ips "$rule"`
    rule17_FREE = get_ips(rule, NULL);
    destips=rule17_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule18_FREE = get_ports_ip(rule, NULL);
    ports=rule18_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing UDP port(s): $ports"
    show_if_ip8_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing UDP port(s): %s;" "\n", show_if_ip8_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local36IFS = IFS;
    if (ports != NULL) strtok36_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok36_FREE, local36IFS, &r_ports6); port != NULL; port = strtok_r(NULL, local36IFS, &r_ports6))
    {
      //for destip in $destips; do
      local37IFS = IFS;
      if (destips != NULL) strtok37_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok37_FREE, local37IFS, &r_destips2); destip != NULL; destip = strtok_r(NULL, local37IFS, &r_destips2))
      {
        //for interface in $interfaces; do
        local38IFS = IFS;
        if (interfaces != NULL) strtok38_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok38_FREE, local38IFS, &r_interfaces8); interface != NULL; interface = strtok_r(NULL, local38IFS, &r_interfaces8))
        {
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p udp --dport $port -j ACCEPT
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p udp --dport %s -j ACCEPT", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain IP protocols to be used from the INET->DMZ?
  //################################################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_OPEN_IP; do
  local39IFS = IFS;
  if (INET_DMZ_OPEN_IP != NULL) strtok39_FREE = strdup(INET_DMZ_OPEN_IP);
  if (INET_DMZ_OPEN_IP != NULL) for (rule = strtok_r(strtok39_FREE, local39IFS, &r_INET_DMZ_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local39IFS, &r_INET_DMZ_OPEN_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule19_FREE = get_ifs(rule, NULL);
    interfaces=rule19_FREE;;
    //destips=`get_ips "$rule"`
    rule20_FREE = get_ips(rule, NULL);
    destips=rule20_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule21_FREE = get_ports_ip(rule, NULL);
    protos=rule21_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing IP protocol(s): $protos"
    show_if_ip9_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing IP protocol(s): %s;" "\n", show_if_ip9_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local40IFS = IFS;
    if (protos != NULL) strtok40_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok40_FREE, local40IFS, &r_protos3); proto != NULL; proto = strtok_r(NULL, local40IFS, &r_protos3))
    {
      //for destip in $destips; do
      local41IFS = IFS;
      if (destips != NULL) strtok41_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok41_FREE, local41IFS, &r_destips3); destip != NULL; destip = strtok_r(NULL, local41IFS, &r_destips3))
      {
        //for interface in $interfaces; do
        local42IFS = IFS;
        if (interfaces != NULL) strtok42_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok42_FREE, local42IFS, &r_interfaces9); interface != NULL; interface = strtok_r(NULL, local42IFS, &r_interfaces9))
        {
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p $proto -j ACCEPT
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p %s -j ACCEPT", interface, destip, proto);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow ICMP-requests(ping) for INET->DMZ?
  //##########################################
  //if [ "$INET_DMZ_OPEN_ICMP" = "1" ]; then
  if  (  (strcmp(INET_DMZ_OPEN_ICMP,"1")==0)  )
  {
    //echo "  Allowing ICMP-requests(ping)"
    printf("  Allowing ICMP-requests(ping)" "\n");
    //iptables -A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
  //fi
  }

  //# TCP ports to DENY for INET->DMZ
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_DENY_TCP; do
  local43IFS = IFS;
  if (INET_DMZ_DENY_TCP != NULL) strtok43_FREE = strdup(INET_DMZ_DENY_TCP);
  if (INET_DMZ_DENY_TCP != NULL) for (rule = strtok_r(strtok43_FREE, local43IFS, &r_INET_DMZ_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local43IFS, &r_INET_DMZ_DENY_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule22_FREE = get_ifs(rule, NULL);
    interfaces=rule22_FREE;;
    //destips=`get_ips "$rule"`
    rule23_FREE = get_ips(rule, NULL);
    destips=rule23_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule24_FREE = get_ports_ip(rule, NULL);
    ports=rule24_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying TCP port(s): $ports"
    show_if_ip10_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying TCP port(s): %s;" "\n", show_if_ip10_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local44IFS = IFS;
    if (ports != NULL) strtok44_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok44_FREE, local44IFS, &r_ports7); port != NULL; port = strtok_r(NULL, local44IFS, &r_ports7))
    {
      //for destip in $destips; do
      local45IFS = IFS;
      if (destips != NULL) strtok45_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok45_FREE, local45IFS, &r_destips4); destip != NULL; destip = strtok_r(NULL, local45IFS, &r_destips4))
      {
        //for interface in $interfaces; do
        local46IFS = IFS;
        if (interfaces != NULL) strtok46_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok46_FREE, local46IFS, &r_interfaces10); interface != NULL; interface = strtok_r(NULL, local46IFS, &r_interfaces10))
        {
          //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p tcp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET->DMZ denied: "
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p tcp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET->DMZ denied: \" --log-level %s", interface, destip, port, LOGLEVEL);
          //fi
          }
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p tcp --dport $port -j DROP
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p tcp --dport %s -j DROP", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for INET->DMZ
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_DENY_UDP; do
  local47IFS = IFS;
  if (INET_DMZ_DENY_UDP != NULL) strtok47_FREE = strdup(INET_DMZ_DENY_UDP);
  if (INET_DMZ_DENY_UDP != NULL) for (rule = strtok_r(strtok47_FREE, local47IFS, &r_INET_DMZ_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local47IFS, &r_INET_DMZ_DENY_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule25_FREE = get_ifs(rule, NULL);
    interfaces=rule25_FREE;;
    //destips=`get_ips "$rule"`
    rule26_FREE = get_ips(rule, NULL);
    destips=rule26_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule27_FREE = get_ports_ip(rule, NULL);
    ports=rule27_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying UDP port(s): $ports"
    show_if_ip11_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying UDP port(s): %s;" "\n", show_if_ip11_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local48IFS = IFS;
    if (ports != NULL) strtok48_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok48_FREE, local48IFS, &r_ports8); port != NULL; port = strtok_r(NULL, local48IFS, &r_ports8))
    {
      //for destip in $destips; do
      local49IFS = IFS;
      if (destips != NULL) strtok49_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok49_FREE, local49IFS, &r_destips5); destip != NULL; destip = strtok_r(NULL, local49IFS, &r_destips5))
      {
        //for interface in $interfaces; do
        local50IFS = IFS;
        if (interfaces != NULL) strtok50_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok50_FREE, local50IFS, &r_interfaces11); interface != NULL; interface = strtok_r(NULL, local50IFS, &r_interfaces11))
        {
          //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p udp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET->DMZ denied: "
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p udp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET->DMZ denied: \" --log-level %s", interface, destip, port, LOGLEVEL);
          //fi
          }
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p udp --dport $port -j DROP
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p udp --dport %s -j DROP", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# IP protocols to DENY for INET->DMZ
  //####################################
  //unset IFS
  IFS = " ";
  //for rule in $INET_DMZ_DENY_IP; do
  local51IFS = IFS;
  if (INET_DMZ_DENY_IP != NULL) strtok51_FREE = strdup(INET_DMZ_DENY_IP);
  if (INET_DMZ_DENY_IP != NULL) for (rule = strtok_r(strtok51_FREE, local51IFS, &r_INET_DMZ_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local51IFS, &r_INET_DMZ_DENY_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule28_FREE = get_ifs(rule, NULL);
    interfaces=rule28_FREE;;
    //destips=`get_ips "$rule"`
    rule29_FREE = get_ips(rule, NULL);
    destips=rule29_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule30_FREE = get_ports_ip(rule, NULL);
    protos=rule30_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying IP protocol(s): $protos"
    show_if_ip12_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying IP protocol(s): %s;" "\n", show_if_ip12_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local52IFS = IFS;
    if (protos != NULL) strtok52_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok52_FREE, local52IFS, &r_protos4); proto != NULL; proto = strtok_r(NULL, local52IFS, &r_protos4))
    {
      //for destip in $destips; do
      local53IFS = IFS;
      if (destips != NULL) strtok53_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok53_FREE, local53IFS, &r_destips6); destip != NULL; destip = strtok_r(NULL, local53IFS, &r_destips6))
      {
        //for interface in $interfaces; do
        local54IFS = IFS;
        if (interfaces != NULL) strtok54_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok54_FREE, local54IFS, &r_interfaces12); interface != NULL; interface = strtok_r(NULL, local54IFS, &r_interfaces12))
        {
          //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p $proto -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET->DMZ denied: "
            iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET->DMZ denied: \" --log-level %s", interface, destip, proto, LOGLEVEL);
          //fi
          }
          //iptables -A INET_DMZ_FORWARD_CHAIN -i $interface -d $destip -p $proto -j DROP
          iptables("-A INET_DMZ_FORWARD_CHAIN -i %s -d %s -p %s -j DROP", interface, destip, proto);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
    //iptables -A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //echo "  Denying all other INET->DMZ packets"
  printf("  Denying all other INET->DMZ packets" "\n");

  //# Drop ICMP packets
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
  //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
  if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif
 {
  //iptables -A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A INET_DMZ_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP");
 }
  //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
  if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
  {
    //iptables -A INET_DMZ_FORWARD_CHAIN  -m limit --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET->DMZ denied: "
    iptables("-A INET_DMZ_FORWARD_CHAIN  -m limit --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET->DMZ denied: \" --log-level %s", LOGLEVEL);
  //fi
  }
  //iptables -A INET_DMZ_FORWARD_CHAIN -j DROP
  iptables("-A INET_DMZ_FORWARD_CHAIN -j DROP");
if (show_if_ip9_FREE != NULL) free(show_if_ip9_FREE);
if (strtok42_FREE != NULL) free(strtok42_FREE);
if (strtok39_FREE != NULL) free(strtok39_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (dhosts1_FREE != NULL) free(dhosts1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (shosts5_FREE != NULL) free(shosts5_FREE);
if (strtok54_FREE != NULL) free(strtok54_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (rule27_FREE != NULL) free(rule27_FREE);
if (dhosts5_FREE != NULL) free(dhosts5_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (if_shosts10_FREE != NULL) free(if_shosts10_FREE);
if (if_shosts6_FREE != NULL) free(if_shosts6_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (dhosts_ports5_FREE != NULL) free(dhosts_ports5_FREE);
if (if_shosts1_FREE != NULL) free(if_shosts1_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok34_FREE != NULL) free(strtok34_FREE);
if (dhosts_ports9_FREE != NULL) free(dhosts_ports9_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok46_FREE != NULL) free(strtok46_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip8_FREE != NULL) free(show_if_ip8_FREE);
if (strtok41_FREE != NULL) free(strtok41_FREE);
if (strtok38_FREE != NULL) free(strtok38_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok53_FREE != NULL) free(strtok53_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (rule26_FREE != NULL) free(rule26_FREE);
if (dhosts4_FREE != NULL) free(dhosts4_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (if_shosts5_FREE != NULL) free(if_shosts5_FREE);
if (dhosts_ports4_FREE != NULL) free(dhosts_ports4_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (if_shosts9_FREE != NULL) free(if_shosts9_FREE);
if (show_if_ip12_FREE != NULL) free(show_if_ip12_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (strtok33_FREE != NULL) free(strtok33_FREE);
if (shosts4_FREE != NULL) free(shosts4_FREE);
if (dhosts_ports8_FREE != NULL) free(dhosts_ports8_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok45_FREE != NULL) free(strtok45_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (strtok40_FREE != NULL) free(strtok40_FREE);
if (strtok37_FREE != NULL) free(strtok37_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok52_FREE != NULL) free(strtok52_FREE);
if (strtok49_FREE != NULL) free(strtok49_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (rule25_FREE != NULL) free(rule25_FREE);
if (dhosts3_FREE != NULL) free(dhosts3_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (if_shosts4_FREE != NULL) free(if_shosts4_FREE);
if (dhosts_ports3_FREE != NULL) free(dhosts_ports3_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (show_if_ip11_FREE != NULL) free(show_if_ip11_FREE);
if (strtok32_FREE != NULL) free(strtok32_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (dhosts_ports7_FREE != NULL) free(dhosts_ports7_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (dhosts_ports12_FREE != NULL) free(dhosts_ports12_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok44_FREE != NULL) free(strtok44_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (rule29_FREE != NULL) free(rule29_FREE);
if (strtok51_FREE != NULL) free(strtok51_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (if_shosts12_FREE != NULL) free(if_shosts12_FREE);
if (if_shosts8_FREE != NULL) free(if_shosts8_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (dhosts2_FREE != NULL) free(dhosts2_FREE);
if (if_shosts3_FREE != NULL) free(if_shosts3_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (dhosts_ports2_FREE != NULL) free(dhosts_ports2_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (strtok36_FREE != NULL) free(strtok36_FREE);
if (show_if_ip10_FREE != NULL) free(show_if_ip10_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (dhosts_ports6_FREE != NULL) free(dhosts_ports6_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (strtok48_FREE != NULL) free(strtok48_FREE);
if (dhosts_ports11_FREE != NULL) free(dhosts_ports11_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok43_FREE != NULL) free(strtok43_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (shosts6_FREE != NULL) free(shosts6_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (rule28_FREE != NULL) free(rule28_FREE);
if (strtok50_FREE != NULL) free(strtok50_FREE);
if (dhosts6_FREE != NULL) free(dhosts6_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (if_shosts11_FREE != NULL) free(if_shosts11_FREE);
if (if_shosts7_FREE != NULL) free(if_shosts7_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (if_shosts2_FREE != NULL) free(if_shosts2_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (dhosts_ports1_FREE != NULL) free(dhosts_ports1_FREE);
if (rule30_FREE != NULL) free(rule30_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (strtok35_FREE != NULL) free(strtok35_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (strtok47_FREE != NULL) free(strtok47_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (dhosts_ports10_FREE != NULL) free(dhosts_ports10_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//###################################################
//# Setup chain for the DMZ-to-INET forward traffic #
//###################################################
void //setup_dmz_inet_forward_chain()
setup_dmz_inet_forward_chain(void)
//{
{
char *show_if_ip9_FREE = NULL;;
char *strtok42_FREE = NULL;;
char *strtok39_FREE = NULL;;
char *dhosts_protos3_FREE = NULL;;
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *r_DMZ_INET_DENY_UDP1 = NULL;;
char *dhosts1_FREE = NULL;;
char *r_DMZ_INET_DENY_TCP1 = NULL;;
char *show_if_ip4_FREE = NULL;;
char *rule15_FREE = NULL;;
char *shosts5_FREE = NULL;;
char *r_DMZ_INET_HOST_DENY_TCP1 = NULL;;
char *rule10_FREE = NULL;;
char *dhosts_protos = NULL;;
char *local40IFS = NULL;;
char *local37IFS = NULL;;
char *r_DMZ_INET_OPEN_TCP1 = NULL;;
char *dhosts5_FREE = NULL;;
char *r_DMZ_INET_HOST_DENY_IP1 = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *if_shosts10_FREE = NULL;;
char *if_shosts6_FREE = NULL;;
char *r_dhosts1_FREE1 = NULL;;
char *strtok10_FREE = NULL;;
char *r_DMZ_INET_HOST_OPEN_TCP1 = NULL;;
char *dhosts_ports5_FREE = NULL;;
char *local5IFS = NULL;;
char *if_shosts1_FREE = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *strtok34_FREE = NULL;;
char *local36IFS = NULL;;
char *r_DMZ_INET_HOST_DENY_UDP1 = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok46_FREE = NULL;;
char *r_DMZ_INET_OPEN_UDP1 = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *show_if_ip8_FREE = NULL;;
char *strtok41_FREE = NULL;;
char *strtok38_FREE = NULL;;
char *proto = NULL;;
char *dhosts_protos2_FREE = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_DMZ_INET_HOST_OPEN_UDP1 = NULL;;
char *local47IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *rule14_FREE = NULL;;
char *local25IFS = NULL;;
char *r_interfaces3 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *local35IFS = NULL;;
char *r_interfaces7 = NULL;;
char *r_interfaces8 = NULL;;
char *dhosts4_FREE = NULL;;
char *dhosts_ports = NULL;;
char *r_interfaces9 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *if_shosts5_FREE = NULL;;
char *dhosts_ports4_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *local46IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *if_shosts9_FREE = NULL;;
char *shost = NULL;;
char *show_if_ip12_FREE = NULL;;
char *strtok13_FREE = NULL;;
char *strtok33_FREE = NULL;;
char *dhosts_ports8_FREE = NULL;;
char *shosts4_FREE = NULL;;
char *local34IFS = NULL;;
char *rule6_FREE = NULL;;
char *rule = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok45_FREE = NULL;;
char *r_DMZ_INET_OPEN_IP1 = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *r_dhosts4_FREE1 = NULL;;
char *if_shosts = NULL;;
char *strtok40_FREE = NULL;;
char *strtok37_FREE = NULL;;
char *r_dhosts6_FREE1 = NULL;;
char *dhosts_protos1_FREE = NULL;;
char *local45IFS = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *rule13_FREE = NULL;;
char *local23IFS = NULL;;
char *r_shosts5_FREE1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_protos3 = NULL;;
char *r_ports4 = NULL;;
char *r_protos4 = NULL;;
char *r_ports5 = NULL;;
char *r_ports6 = NULL;;
char *r_ports7 = NULL;;
char *dhosts3_FREE = NULL;;
char *r_ports8 = NULL;;
char *dhost = NULL;;
char *interface = NULL;;
char *rule20_FREE = NULL;;
char *if_shosts4_FREE = NULL;;
char *dhosts_ports3_FREE = NULL;;
char *local44IFS = NULL;;
char *r_dhosts2_FREE1 = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *show_if_ip11_FREE = NULL;;
char *strtok32_FREE = NULL;;
char *strtok29_FREE = NULL;;
char *dhosts_ports7_FREE = NULL;;
char *shosts3_FREE = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok44_FREE = NULL;;
char *local33IFS = NULL;;
char *strtok3_FREE = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *rule17_FREE = NULL;;
char *local43IFS = NULL;;
char *show_if_ip1_FREE = NULL;;
char *r_DMZ_INET_DENY_IP1 = NULL;;
char *rule12_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *rule24_FREE = NULL;;
char *if_shosts12_FREE = NULL;;
char *if_shosts8_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *dhosts2_FREE = NULL;;
char *local32IFS = NULL;;
char *local29IFS = NULL;;
char *if_shosts3_FREE = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *dhosts_ports2_FREE = NULL;;
char *strtok16_FREE = NULL;;
char *strtok36_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *shosts = NULL;;
char *show_if_ip10_FREE = NULL;;
char *rule9_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *dhosts_ports6_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *strtok48_FREE = NULL;;
char *rule4_FREE = NULL;;
char *strtok43_FREE = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *dhosts_protos4_FREE = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *shosts6_FREE = NULL;;
char *r_DMZ_INET_HOST_OPEN_IP1 = NULL;;
char *rule11_FREE = NULL;;
char *local42IFS = NULL;;
char *local39IFS = NULL;;
char *dhosts6_FREE = NULL;;
char *r_shosts4_FREE1 = NULL;;
char *rule23_FREE = NULL;;
char *r_shosts6_FREE1 = NULL;;
char *if_shosts11_FREE = NULL;;
char *if_shosts7_FREE = NULL;;
char *strtok11_FREE = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *if_shosts2_FREE = NULL;;
char *r_interfaces10 = NULL;;
char *strtok23_FREE = NULL;;
char *dhosts_ports1_FREE = NULL;;
char *r_interfaces11 = NULL;;
char *r_interfaces12 = NULL;;
char *strtok15_FREE = NULL;;
char *dhosts = NULL;;
char *strtok35_FREE = NULL;;
char *local41IFS = NULL;;
char *local38IFS = NULL;;
char *rule8_FREE = NULL;;
char *r_dhosts3_FREE1 = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *r_dhosts5_FREE1 = NULL;;
char *local16IFS = NULL;;
char *shosts1_FREE = NULL;;
char *strtok47_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *local48IFS = NULL;;
char *r_shosts2_FREE1 = NULL;;
char *rule3_FREE = NULL;;

  //echo " Setting up DMZ->INET policy"
  printf(" Setting up DMZ->INET policy" "\n");

  //# TCP ports to ALLOW for certain DMZ hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (DMZ_INET_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(DMZ_INET_HOST_OPEN_TCP);
  if (DMZ_INET_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_DMZ_INET_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_DMZ_INET_HOST_OPEN_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts1_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts1_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts2_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts2_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule2_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports1_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports1_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports2_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports2_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(DMZ) to $dhosts(INET) for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(DMZ) to %s(INET) for TCP port(s): %s;" "\n", show_if_ip1_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local2IFS = IFS;
    if (shosts1_FREE != NULL) strtok2_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok2_FREE, local2IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local2IFS, &r_shosts1_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts1_FREE = ip_range(dhosts, NULL);
      local3IFS = IFS;
      if (dhosts1_FREE != NULL) strtok3_FREE = strdup(dhosts1_FREE);
      if (dhosts1_FREE != NULL) for (dhost = strtok_r(strtok3_FREE, local3IFS, &r_dhosts1_FREE1); dhost != NULL; dhost = strtok_r(NULL, local3IFS, &r_dhosts1_FREE1))
      {
        //for port in $ports; do
        local4IFS = IFS;
        if (ports != NULL) strtok4_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok4_FREE, local4IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local4IFS, &r_ports1))
        {
          //for interface in $interfaces; do
          local5IFS = IFS;
          if (interfaces != NULL) strtok5_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok5_FREE, local5IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local5IFS, &r_interfaces1))
          {
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port -j ACCEPT
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to ALLOW for certain DMZ hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_OPEN_UDP; do
  local6IFS = IFS;
  if (DMZ_INET_HOST_OPEN_UDP != NULL) strtok6_FREE = strdup(DMZ_INET_HOST_OPEN_UDP);
  if (DMZ_INET_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok6_FREE, local6IFS, &r_DMZ_INET_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local6IFS, &r_DMZ_INET_HOST_OPEN_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts3_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts3_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts4_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts4_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule4_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports3_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports3_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports4_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports4_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(DMZ) to $dhosts(INET) for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(DMZ) to %s(INET) for UDP port(s): %s;" "\n", show_if_ip2_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local7IFS = IFS;
    if (shosts2_FREE != NULL) strtok7_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok7_FREE, local7IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local7IFS, &r_shosts2_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts2_FREE = ip_range(dhosts, NULL);
      local8IFS = IFS;
      if (dhosts2_FREE != NULL) strtok8_FREE = strdup(dhosts2_FREE);
      if (dhosts2_FREE != NULL) for (dhost = strtok_r(strtok8_FREE, local8IFS, &r_dhosts2_FREE1); dhost != NULL; dhost = strtok_r(NULL, local8IFS, &r_dhosts2_FREE1))
      {
        //for port in $ports; do
        local9IFS = IFS;
        if (ports != NULL) strtok9_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok9_FREE, local9IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local9IFS, &r_ports2))
        {
          //for interface in $interfaces; do
          local10IFS = IFS;
          if (interfaces != NULL) strtok10_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok10_FREE, local10IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local10IFS, &r_interfaces2))
          {
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port -j ACCEPT
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to ALLOW for certain DMZ hosts
  //#####################################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_OPEN_IP; do
  local11IFS = IFS;
  if (DMZ_INET_HOST_OPEN_IP != NULL) strtok11_FREE = strdup(DMZ_INET_HOST_OPEN_IP);
  if (DMZ_INET_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok11_FREE, local11IFS, &r_DMZ_INET_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local11IFS, &r_DMZ_INET_HOST_OPEN_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts5_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts5_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts6_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts6_FREE;;
    //dhosts_protos=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhosts_protos=rule6_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_protos"`
    dhosts_protos1_FREE = get_hosts_hp(dhosts_protos, NULL);
    dhosts=dhosts_protos1_FREE;;
    //protos=`get_ports_hp "$dhosts_protos"`
    dhosts_protos2_FREE = get_ports_hp(dhosts_protos, NULL);
    protos=dhosts_protos2_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(DMZ) to $dhosts(INET) for IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(DMZ) to %s(INET) for IP protocol(s): %s;" "\n", show_if_ip3_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local12IFS = IFS;
    if (shosts3_FREE != NULL) strtok12_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok12_FREE, local12IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local12IFS, &r_shosts3_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts3_FREE = ip_range(dhosts, NULL);
      local13IFS = IFS;
      if (dhosts3_FREE != NULL) strtok13_FREE = strdup(dhosts3_FREE);
      if (dhosts3_FREE != NULL) for (dhost = strtok_r(strtok13_FREE, local13IFS, &r_dhosts3_FREE1); dhost != NULL; dhost = strtok_r(NULL, local13IFS, &r_dhosts3_FREE1))
      {
        //for proto in $protos; do
        local14IFS = IFS;
        if (protos != NULL) strtok14_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok14_FREE, local14IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local14IFS, &r_protos1))
        {
          //for interface in $interfaces; do
          local15IFS = IFS;
          if (interfaces != NULL) strtok15_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok15_FREE, local15IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local15IFS, &r_interfaces3))
          {
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto -j ACCEPT
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s -j ACCEPT", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# TCP ports to DENY for certain DMZ hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_DENY_TCP; do
  local16IFS = IFS;
  if (DMZ_INET_HOST_DENY_TCP != NULL) strtok16_FREE = strdup(DMZ_INET_HOST_DENY_TCP);
  if (DMZ_INET_HOST_DENY_TCP != NULL) for (rule = strtok_r(strtok16_FREE, local16IFS, &r_DMZ_INET_HOST_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local16IFS, &r_DMZ_INET_HOST_DENY_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule7_FREE = getfield(rule, ">", 1);
    if_shosts=rule7_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts7_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts7_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts8_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts8_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule8_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule8_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports5_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports5_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports6_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports6_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(DMZ) to $dhosts(INET) for TCP port(s): $ports"
    show_if_ip4_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(DMZ) to %s(INET) for TCP port(s): %s;" "\n", show_if_ip4_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts4_FREE = ip_range(shosts, NULL);
    local17IFS = IFS;
    if (shosts4_FREE != NULL) strtok17_FREE = strdup(shosts4_FREE);
    if (shosts4_FREE != NULL) for (shost = strtok_r(strtok17_FREE, local17IFS, &r_shosts4_FREE1); shost != NULL; shost = strtok_r(NULL, local17IFS, &r_shosts4_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts4_FREE = ip_range(dhosts, NULL);
      local18IFS = IFS;
      if (dhosts4_FREE != NULL) strtok18_FREE = strdup(dhosts4_FREE);
      if (dhosts4_FREE != NULL) for (dhost = strtok_r(strtok18_FREE, local18IFS, &r_dhosts4_FREE1); dhost != NULL; dhost = strtok_r(NULL, local18IFS, &r_dhosts4_FREE1))
      {
        //for port in $ports; do
        local19IFS = IFS;
        if (ports != NULL) strtok19_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local19IFS, &r_ports3))
        {
          //for interface in $interfaces; do
          local20IFS = IFS;
          if (interfaces != NULL) strtok20_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok20_FREE, local20IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local20IFS, &r_interfaces4))
          {
            //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host DMZ->INET denied: "
              iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host DMZ->INET denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port -j DROP
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for certain DMZ hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_DENY_UDP; do
  local21IFS = IFS;
  if (DMZ_INET_HOST_DENY_UDP != NULL) strtok21_FREE = strdup(DMZ_INET_HOST_DENY_UDP);
  if (DMZ_INET_HOST_DENY_UDP != NULL) for (rule = strtok_r(strtok21_FREE, local21IFS, &r_DMZ_INET_HOST_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local21IFS, &r_DMZ_INET_HOST_DENY_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule9_FREE = getfield(rule, ">", 1);
    if_shosts=rule9_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts9_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts9_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts10_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts10_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule10_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule10_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports7_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports7_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports8_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports8_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(DMZ) to $dhosts(INET) for UDP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(DMZ) to %s(INET) for UDP port(s): %s;" "\n", show_if_ip5_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts5_FREE = ip_range(shosts, NULL);
    local22IFS = IFS;
    if (shosts5_FREE != NULL) strtok22_FREE = strdup(shosts5_FREE);
    if (shosts5_FREE != NULL) for (shost = strtok_r(strtok22_FREE, local22IFS, &r_shosts5_FREE1); shost != NULL; shost = strtok_r(NULL, local22IFS, &r_shosts5_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts5_FREE = ip_range(dhosts, NULL);
      local23IFS = IFS;
      if (dhosts5_FREE != NULL) strtok23_FREE = strdup(dhosts5_FREE);
      if (dhosts5_FREE != NULL) for (dhost = strtok_r(strtok23_FREE, local23IFS, &r_dhosts5_FREE1); dhost != NULL; dhost = strtok_r(NULL, local23IFS, &r_dhosts5_FREE1))
      {
        //for port in $ports; do
        local24IFS = IFS;
        if (ports != NULL) strtok24_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports4))
        {
          //for interface in $interfaces; do
          local25IFS = IFS;
          if (interfaces != NULL) strtok25_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok25_FREE, local25IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local25IFS, &r_interfaces5))
          {
            //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host DMZ->INET denied: "
              iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host DMZ->INET denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port -j DROP
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to DENY for certain DMZ hosts
  //#####################################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_HOST_DENY_IP; do
  local26IFS = IFS;
  if (DMZ_INET_HOST_DENY_IP != NULL) strtok26_FREE = strdup(DMZ_INET_HOST_DENY_IP);
  if (DMZ_INET_HOST_DENY_IP != NULL) for (rule = strtok_r(strtok26_FREE, local26IFS, &r_DMZ_INET_HOST_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local26IFS, &r_DMZ_INET_HOST_DENY_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule11_FREE = getfield(rule, ">", 1);
    if_shosts=rule11_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts11_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts11_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts12_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts12_FREE;;
    //dhosts_protos=`echo "$rule" |cut -s -d'>' -f2`
    rule12_FREE = getfield(rule, ">", 2);
    dhosts_protos=rule12_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_protos"`
    dhosts_protos3_FREE = get_hosts_hp(dhosts_protos, NULL);
    dhosts=dhosts_protos3_FREE;;
    //protos=`get_ports_hp "$dhosts_protos"`
    dhosts_protos4_FREE = get_ports_hp(dhosts_protos, NULL);
    protos=dhosts_protos4_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(DMZ) to $dhosts(INET) for IP protocol(s): $protos"
    show_if_ip6_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(DMZ) to %s(INET) for IP protocol(s): %s;" "\n", show_if_ip6_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts6_FREE = ip_range(shosts, NULL);
    local27IFS = IFS;
    if (shosts6_FREE != NULL) strtok27_FREE = strdup(shosts6_FREE);
    if (shosts6_FREE != NULL) for (shost = strtok_r(strtok27_FREE, local27IFS, &r_shosts6_FREE1); shost != NULL; shost = strtok_r(NULL, local27IFS, &r_shosts6_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts6_FREE = ip_range(dhosts, NULL);
      local28IFS = IFS;
      if (dhosts6_FREE != NULL) strtok28_FREE = strdup(dhosts6_FREE);
      if (dhosts6_FREE != NULL) for (dhost = strtok_r(strtok28_FREE, local28IFS, &r_dhosts6_FREE1); dhost != NULL; dhost = strtok_r(NULL, local28IFS, &r_dhosts6_FREE1))
      {
        //for proto in $protos; do
        local29IFS = IFS;
        if (protos != NULL) strtok29_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_protos2))
        {
          //for interface in $interfaces; do
          local30IFS = IFS;
          if (interfaces != NULL) strtok30_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok30_FREE, local30IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local30IFS, &r_interfaces6))
          {
            //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host DMZ->INET denied: "
              iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host DMZ->INET denied: \" --log-level %s", interface, shost, dhost, proto, LOGLEVEL);
            //fi
            }
            //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto -j DROP
            iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s -j DROP", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain TCP ports to be used from the DMZ->INET?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_OPEN_TCP; do
  local31IFS = IFS;
  if (DMZ_INET_OPEN_TCP != NULL) strtok31_FREE = strdup(DMZ_INET_OPEN_TCP);
  if (DMZ_INET_OPEN_TCP != NULL) for (rule = strtok_r(strtok31_FREE, local31IFS, &r_DMZ_INET_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local31IFS, &r_DMZ_INET_OPEN_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule14_FREE = get_ports_ip(rule, NULL);
    ports=rule14_FREE;;

    //echo " $(show_if_ip "$interfaces")Allowing TCP port(s): $ports"
    show_if_ip7_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Allowing TCP port(s): %s;" "\n", show_if_ip7_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local32IFS = IFS;
    if (ports != NULL) strtok32_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok32_FREE, local32IFS, &r_ports5); port != NULL; port = strtok_r(NULL, local32IFS, &r_ports5))
    {
      //for interface in $interfaces; do
      local33IFS = IFS;
      if (interfaces != NULL) strtok33_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok33_FREE, local33IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local33IFS, &r_interfaces7))
      {
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -j ACCEPT
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -j ACCEPT", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain UDP ports to be used from the DMZ->INET?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_OPEN_UDP; do
  local34IFS = IFS;
  if (DMZ_INET_OPEN_UDP != NULL) strtok34_FREE = strdup(DMZ_INET_OPEN_UDP);
  if (DMZ_INET_OPEN_UDP != NULL) for (rule = strtok_r(strtok34_FREE, local34IFS, &r_DMZ_INET_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local34IFS, &r_DMZ_INET_OPEN_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule15_FREE = get_ifs(rule, NULL);
    interfaces=rule15_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule16_FREE = get_ports_ip(rule, NULL);
    ports=rule16_FREE;;

    //echo " $(show_if_ip "$interfaces")Allowing UDP port(s): $ports"
    show_if_ip8_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Allowing UDP port(s): %s;" "\n", show_if_ip8_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local35IFS = IFS;
    if (ports != NULL) strtok35_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok35_FREE, local35IFS, &r_ports6); port != NULL; port = strtok_r(NULL, local35IFS, &r_ports6))
    {
      //for interface in $interfaces; do
      local36IFS = IFS;
      if (interfaces != NULL) strtok36_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok36_FREE, local36IFS, &r_interfaces8); interface != NULL; interface = strtok_r(NULL, local36IFS, &r_interfaces8))
      {
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -j ACCEPT
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p udp --dport %s -j ACCEPT", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain IP protocols to be used from the DMZ->INET?
  //################################################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_OPEN_IP; do
  local37IFS = IFS;
  if (DMZ_INET_OPEN_IP != NULL) strtok37_FREE = strdup(DMZ_INET_OPEN_IP);
  if (DMZ_INET_OPEN_IP != NULL) for (rule = strtok_r(strtok37_FREE, local37IFS, &r_DMZ_INET_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local37IFS, &r_DMZ_INET_OPEN_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule17_FREE = get_ifs(rule, NULL);
    interfaces=rule17_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule18_FREE = get_ports_ip(rule, NULL);
    protos=rule18_FREE;;

    //echo " $(show_if_ip "$interfaces")Allowing IP protocol(s): $protos"
    show_if_ip9_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Allowing IP protocol(s): %s;" "\n", show_if_ip9_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local38IFS = IFS;
    if (protos != NULL) strtok38_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok38_FREE, local38IFS, &r_protos3); proto != NULL; proto = strtok_r(NULL, local38IFS, &r_protos3))
    {
      //for interface in $interfaces; do
      local39IFS = IFS;
      if (interfaces != NULL) strtok39_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok39_FREE, local39IFS, &r_interfaces9); interface != NULL; interface = strtok_r(NULL, local39IFS, &r_interfaces9))
      {
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p $proto -j ACCEPT
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p %s -j ACCEPT", interface, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Allow ICMP-requests(ping) for DMZ->INET?
  //##########################################
  //if [ "$DMZ_INET_OPEN_ICMP" != "0" ]; then
  if  (  (strcmp(DMZ_INET_OPEN_ICMP,"0")!=0)  )
  {
    //echo "  Allowing ICMP-requests(ping)"
    printf("  Allowing ICMP-requests(ping)" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
  //fi
  }

  //# TCP ports to DENY for DMZ->INET
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_DENY_TCP; do
  local40IFS = IFS;
  if (DMZ_INET_DENY_TCP != NULL) strtok40_FREE = strdup(DMZ_INET_DENY_TCP);
  if (DMZ_INET_DENY_TCP != NULL) for (rule = strtok_r(strtok40_FREE, local40IFS, &r_DMZ_INET_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local40IFS, &r_DMZ_INET_DENY_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule19_FREE = get_ifs(rule, NULL);
    interfaces=rule19_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule20_FREE = get_ports_ip(rule, NULL);
    ports=rule20_FREE;;

    //echo " $(show_if_ip "$interfaces")Denying TCP port(s): $ports"
    show_if_ip10_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Denying TCP port(s): %s;" "\n", show_if_ip10_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local41IFS = IFS;
    if (ports != NULL) strtok41_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok41_FREE, local41IFS, &r_ports7); port != NULL; port = strtok_r(NULL, local41IFS, &r_ports7))
    {
      //for interface in $interfaces; do
      local42IFS = IFS;
      if (interfaces != NULL) strtok42_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok42_FREE, local42IFS, &r_interfaces10); interface != NULL; interface = strtok_r(NULL, local42IFS, &r_interfaces10))
      {
        //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
          iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", interface, port, LOGLEVEL);
        //fi
        }
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -j DROP
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for DMZ->INET
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_DENY_UDP; do
  local43IFS = IFS;
  if (DMZ_INET_DENY_UDP != NULL) strtok43_FREE = strdup(DMZ_INET_DENY_UDP);
  if (DMZ_INET_DENY_UDP != NULL) for (rule = strtok_r(strtok43_FREE, local43IFS, &r_DMZ_INET_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local43IFS, &r_DMZ_INET_DENY_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule21_FREE = get_ifs(rule, NULL);
    interfaces=rule21_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule22_FREE = get_ports_ip(rule, NULL);
    ports=rule22_FREE;;

    //echo " $(show_if_ip "$interfaces")Denying UDP port(s): $ports"
    show_if_ip11_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Denying UDP port(s): %s;" "\n", show_if_ip11_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local44IFS = IFS;
    if (ports != NULL) strtok44_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok44_FREE, local44IFS, &r_ports8); port != NULL; port = strtok_r(NULL, local44IFS, &r_ports8))
    {
      //for interface in $interfaces; do
      local45IFS = IFS;
      if (interfaces != NULL) strtok45_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok45_FREE, local45IFS, &r_interfaces11); interface != NULL; interface = strtok_r(NULL, local45IFS, &r_interfaces11))
      {
        //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
          iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p udp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", interface, port, LOGLEVEL);
        //fi
        }
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -j DROP
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p udp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# IP protocols to DENY for DMZ->INET
  //####################################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_INET_DENY_IP; do
  local46IFS = IFS;
  if (DMZ_INET_DENY_IP != NULL) strtok46_FREE = strdup(DMZ_INET_DENY_IP);
  if (DMZ_INET_DENY_IP != NULL) for (rule = strtok_r(strtok46_FREE, local46IFS, &r_DMZ_INET_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local46IFS, &r_DMZ_INET_DENY_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule23_FREE = get_ifs(rule, NULL);
    interfaces=rule23_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule24_FREE = get_ports_ip(rule, NULL);
    protos=rule24_FREE;;

    //echo " $(show_if_ip "$interfaces")Denying IP protocol(s): $protos"
    show_if_ip12_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Denying IP protocol(s): %s;" "\n", show_if_ip12_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local47IFS = IFS;
    if (protos != NULL) strtok47_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok47_FREE, local47IFS, &r_protos4); proto != NULL; proto = strtok_r(NULL, local47IFS, &r_protos4))
    {
      //for interface in $interfaces; do
      local48IFS = IFS;
      if (interfaces != NULL) strtok48_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok48_FREE, local48IFS, &r_interfaces12); interface != NULL; interface = strtok_r(NULL, local48IFS, &r_interfaces12))
      {
        //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p $proto -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
          iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", interface, proto, LOGLEVEL);
        //fi
        }
        //iptables -A DMZ_INET_FORWARD_CHAIN -o $interface -p $proto -j DROP
        iptables("-A DMZ_INET_FORWARD_CHAIN -o %s -p %s -j DROP", interface, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif
    {
    //iptables -A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
    }
  //fi
  }

  //# Drop ICMP packets
  //iptables -A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A DMZ_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP");

  //# Set the default policy (switch to DROP for a protocol when xxx_OPEN_xxx variable is used)
  //###########################################################################################
  //if [ -z "$DMZ_INET_OPEN_TCP" ]; then
  if  (  ((DMZ_INET_OPEN_TCP==NULL)||(strlen(DMZ_INET_OPEN_TCP)==0))  )
  {
    //echo "  Allowing all (other) TCP ports"
    printf("  Allowing all (other) TCP ports" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -p tcp -j ACCEPT
    iptables("-A DMZ_INET_FORWARD_CHAIN -p tcp -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A DMZ_INET_FORWARD_CHAIN -p tcp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
      iptables("-A DMZ_INET_FORWARD_CHAIN -p tcp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) TCP ports"
    printf("  Denying all (other) TCP ports" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -p tcp -j DROP
    iptables("-A DMZ_INET_FORWARD_CHAIN -p tcp -j DROP");
  //fi
  }

  //if [ -z "$DMZ_INET_OPEN_UDP" ]; then
  if  (  ((DMZ_INET_OPEN_UDP==NULL)||(strlen(DMZ_INET_OPEN_UDP)==0))  )
  {
    //echo "  Allowing all (other) UDP ports"
    printf("  Allowing all (other) UDP ports" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -p udp -j ACCEPT
    iptables("-A DMZ_INET_FORWARD_CHAIN -p udp -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A DMZ_INET_FORWARD_CHAIN -p udp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
      iptables("-A DMZ_INET_FORWARD_CHAIN -p udp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) UDP ports"
    printf("  Denying all (other) UDP ports" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -p udp -j DROP
    iptables("-A DMZ_INET_FORWARD_CHAIN -p udp -j DROP");
  //fi
  }

  //if [ -z "$DMZ_INET_OPEN_IP" ]; then
  if  (  ((DMZ_INET_OPEN_IP==NULL)||(strlen(DMZ_INET_OPEN_IP)==0))  )
  {
    //echo "  Allowing all (other) protocols"
    printf("  Allowing all (other) protocols" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -j ACCEPT
    iptables("-A DMZ_INET_FORWARD_CHAIN -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A DMZ_INET_FORWARD_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:DMZ->INET denied: "
      iptables("-A DMZ_INET_FORWARD_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:DMZ->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) protocols"
    printf("  Denying all (other) protocols" "\n");
    //iptables -A DMZ_INET_FORWARD_CHAIN -j DROP
    iptables("-A DMZ_INET_FORWARD_CHAIN -j DROP");
  //fi
  }
if (show_if_ip9_FREE != NULL) free(show_if_ip9_FREE);
if (strtok42_FREE != NULL) free(strtok42_FREE);
if (strtok39_FREE != NULL) free(strtok39_FREE);
if (dhosts_protos3_FREE != NULL) free(dhosts_protos3_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (dhosts1_FREE != NULL) free(dhosts1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (shosts5_FREE != NULL) free(shosts5_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (dhosts5_FREE != NULL) free(dhosts5_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (if_shosts10_FREE != NULL) free(if_shosts10_FREE);
if (if_shosts6_FREE != NULL) free(if_shosts6_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (dhosts_ports5_FREE != NULL) free(dhosts_ports5_FREE);
if (if_shosts1_FREE != NULL) free(if_shosts1_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok34_FREE != NULL) free(strtok34_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok46_FREE != NULL) free(strtok46_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip8_FREE != NULL) free(show_if_ip8_FREE);
if (strtok41_FREE != NULL) free(strtok41_FREE);
if (strtok38_FREE != NULL) free(strtok38_FREE);
if (dhosts_protos2_FREE != NULL) free(dhosts_protos2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (dhosts4_FREE != NULL) free(dhosts4_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (if_shosts5_FREE != NULL) free(if_shosts5_FREE);
if (dhosts_ports4_FREE != NULL) free(dhosts_ports4_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (if_shosts9_FREE != NULL) free(if_shosts9_FREE);
if (show_if_ip12_FREE != NULL) free(show_if_ip12_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (strtok33_FREE != NULL) free(strtok33_FREE);
if (dhosts_ports8_FREE != NULL) free(dhosts_ports8_FREE);
if (shosts4_FREE != NULL) free(shosts4_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok45_FREE != NULL) free(strtok45_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (strtok40_FREE != NULL) free(strtok40_FREE);
if (strtok37_FREE != NULL) free(strtok37_FREE);
if (dhosts_protos1_FREE != NULL) free(dhosts_protos1_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (dhosts3_FREE != NULL) free(dhosts3_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (if_shosts4_FREE != NULL) free(if_shosts4_FREE);
if (dhosts_ports3_FREE != NULL) free(dhosts_ports3_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (show_if_ip11_FREE != NULL) free(show_if_ip11_FREE);
if (strtok32_FREE != NULL) free(strtok32_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (dhosts_ports7_FREE != NULL) free(dhosts_ports7_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok44_FREE != NULL) free(strtok44_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (if_shosts12_FREE != NULL) free(if_shosts12_FREE);
if (if_shosts8_FREE != NULL) free(if_shosts8_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (dhosts2_FREE != NULL) free(dhosts2_FREE);
if (if_shosts3_FREE != NULL) free(if_shosts3_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (dhosts_ports2_FREE != NULL) free(dhosts_ports2_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (strtok36_FREE != NULL) free(strtok36_FREE);
if (show_if_ip10_FREE != NULL) free(show_if_ip10_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (dhosts_ports6_FREE != NULL) free(dhosts_ports6_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (strtok48_FREE != NULL) free(strtok48_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok43_FREE != NULL) free(strtok43_FREE);
if (dhosts_protos4_FREE != NULL) free(dhosts_protos4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (shosts6_FREE != NULL) free(shosts6_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (dhosts6_FREE != NULL) free(dhosts6_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (if_shosts11_FREE != NULL) free(if_shosts11_FREE);
if (if_shosts7_FREE != NULL) free(if_shosts7_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (if_shosts2_FREE != NULL) free(if_shosts2_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (dhosts_ports1_FREE != NULL) free(dhosts_ports1_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (strtok35_FREE != NULL) free(strtok35_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (strtok47_FREE != NULL) free(strtok47_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//#########################################
//# Setup chain for the LAN input traffic #
//#########################################
void //setup_int_input_chain()
setup_int_input_chain(void)
//{
{
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *host = NULL;;
char *rule10_FREE = NULL;;
char *local15IFS = NULL;;
char *strtok10_FREE = NULL;;
char *local5IFS = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *rule7_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_hosts5_FREE1 = NULL;;
char *strtok9_FREE = NULL;;
char *hosts6_FREE = NULL;;
char *local13IFS = NULL;;
char *local3IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *strtok13_FREE = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *hosts1_FREE = NULL;;
char *r_ports1 = NULL;;
char *local23IFS = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_ports4 = NULL;;
char *hosts5_FREE = NULL;;
char *r_LAN_DENY_TCP1 = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *hosts = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *local11IFS = NULL;;
char *r_LAN_DENY_UDP1 = NULL;;
char *r_LAN_HOST_DENY_TCP1 = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *rule12_FREE = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *hosts4_FREE = NULL;;
char *r_LAN_HOST_OPEN_IP1 = NULL;;
char *r_hosts6_FREE1 = NULL;;
char *r_LAN_OPEN_TCP1 = NULL;;
char *strtok12_FREE = NULL;;
char *r_LAN_HOST_OPEN_TCP1 = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *r_LAN_OPEN_IP1 = NULL;;
char *strtok16_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *r_LAN_HOST_DENY_UDP1 = NULL;;
char *rule9_FREE = NULL;;
char *rule4_FREE = NULL;;
char *r_hosts4_FREE1 = NULL;;
char *r_LAN_OPEN_UDP1 = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *r_LAN_HOST_OPEN_UDP1 = NULL;;
char *r_LAN_DENY_IP1 = NULL;;
char *rule11_FREE = NULL;;
char *hosts3_FREE = NULL;;
char *strtok11_FREE = NULL;;
char *local7IFS = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *strtok23_FREE = NULL;;
char *r_LAN_HOST_DENY_IP1 = NULL;;
char *strtok15_FREE = NULL;;
char *rule8_FREE = NULL;;
char *local16IFS = NULL;;
char *strtok6_FREE = NULL;;
char *rule3_FREE = NULL;;

  //# TCP ports to OPEN for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (LAN_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(LAN_HOST_OPEN_TCP);
  if (LAN_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_LAN_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_LAN_HOST_OPEN_TCP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule1_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule1_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule2_FREE = get_ports_ihp(rule, NULL);
    ports=rule2_FREE;;

    //echo " Allowing $hosts(LAN) for TCP port(s): $ports"
    printf(" Allowing %s(LAN) for TCP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local2IFS = IFS;
    if (hosts1_FREE != NULL) strtok2_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok2_FREE, local2IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local2IFS, &r_hosts1_FREE1))
    {
      //for port in $ports; do
      local3IFS = IFS;
      if (ports != NULL) strtok3_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok3_FREE, local3IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local3IFS, &r_ports1))
      {
        //iptables -A INT_INPUT_CHAIN -s $host -p tcp --dport $port -j ACCEPT
        iptables("-A INT_INPUT_CHAIN -s %s -p tcp --dport %s -j ACCEPT", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to OPEN for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_OPEN_UDP; do
  local4IFS = IFS;
  if (LAN_HOST_OPEN_UDP != NULL) strtok4_FREE = strdup(LAN_HOST_OPEN_UDP);
  if (LAN_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok4_FREE, local4IFS, &r_LAN_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local4IFS, &r_LAN_HOST_OPEN_UDP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule3_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule3_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule4_FREE = get_ports_ihp(rule, NULL);
    ports=rule4_FREE;;

    //echo " Allowing $hosts(LAN) for UDP port(s): $ports"
    printf(" Allowing %s(LAN) for UDP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local5IFS = IFS;
    if (hosts2_FREE != NULL) strtok5_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok5_FREE, local5IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local5IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local6IFS = IFS;
      if (ports != NULL) strtok6_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok6_FREE, local6IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local6IFS, &r_ports2))
      {
        //iptables -A INT_INPUT_CHAIN -s $host -p udp --dport $port -j ACCEPT
        iptables("-A INT_INPUT_CHAIN -s %s -p udp --dport %s -j ACCEPT", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# IP protocols to OPEN for certain LAN hosts
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_OPEN_IP; do
  local7IFS = IFS;
  if (LAN_HOST_OPEN_IP != NULL) strtok7_FREE = strdup(LAN_HOST_OPEN_IP);
  if (LAN_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok7_FREE, local7IFS, &r_LAN_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local7IFS, &r_LAN_HOST_OPEN_IP1))
  {
    //hosts=`get_hosts_ihp "$rule"`
    rule5_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule5_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule6_FREE = get_ports_ihp(rule, NULL);
    protos=rule6_FREE;;

    //echo " Allowing $hosts(LAN) for IP protocol(s): $protos"
    printf(" Allowing %s(LAN) for IP protocol(s): %s" "\n", hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local8IFS = IFS;
    if (hosts3_FREE != NULL) strtok8_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok8_FREE, local8IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local8IFS, &r_hosts3_FREE1))
    {
      //for proto in $protos; do
      local9IFS = IFS;
      if (protos != NULL) strtok9_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok9_FREE, local9IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local9IFS, &r_protos1))
      {
        //iptables -A INT_INPUT_CHAIN -s $host -p $proto -j ACCEPT
        iptables("-A INT_INPUT_CHAIN -s %s -p %s -j ACCEPT", host, proto);
      //done
      }
    //done
    }
  //done
  }

  //# TCP ports to DENY for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_DENY_TCP; do
  local10IFS = IFS;
  if (LAN_HOST_DENY_TCP != NULL) strtok10_FREE = strdup(LAN_HOST_DENY_TCP);
  if (LAN_HOST_DENY_TCP != NULL) for (rule = strtok_r(strtok10_FREE, local10IFS, &r_LAN_HOST_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local10IFS, &r_LAN_HOST_DENY_TCP1))
  {
    //hosts=`get_hosts_ihp "$rule" "$ANYHOST"`
    rule7_FREE = get_hosts_ihp(rule, ANYHOST);
    hosts=rule7_FREE;;
    //ports=`get_ports_ihp "$rule" "$ANYPORT"`
    rule8_FREE = get_ports_ihp(rule, ANYPORT);
    ports=rule8_FREE;;

    //echo " Denying $hosts(LAN) for TCP port(s): $ports"
    printf(" Denying %s(LAN) for TCP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts4_FREE = ip_range(hosts, NULL);
    local11IFS = IFS;
    if (hosts4_FREE != NULL) strtok11_FREE = strdup(hosts4_FREE);
    if (hosts4_FREE != NULL) for (host = strtok_r(strtok11_FREE, local11IFS, &r_hosts4_FREE1); host != NULL; host = strtok_r(NULL, local11IFS, &r_hosts4_FREE1))
    {
      //for port in $ports; do
      local12IFS = IFS;
      if (ports != NULL) strtok12_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok12_FREE, local12IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local12IFS, &r_ports3))
      {
        //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A INT_INPUT_CHAIN -s $host -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN denied: "
          iptables("-A INT_INPUT_CHAIN -s %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN denied: \" --log-level %s", host, port, LOGLEVEL);
        //fi
        }
        //iptables -A INT_INPUT_CHAIN -s $host -p tcp --dport $port -j DROP
        iptables("-A INT_INPUT_CHAIN -s %s -p tcp --dport %s -j DROP", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_DENY_UDP; do
  local13IFS = IFS;
  if (LAN_HOST_DENY_UDP != NULL) strtok13_FREE = strdup(LAN_HOST_DENY_UDP);
  if (LAN_HOST_DENY_UDP != NULL) for (rule = strtok_r(strtok13_FREE, local13IFS, &r_LAN_HOST_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local13IFS, &r_LAN_HOST_DENY_UDP1))
  {
    //hosts=`get_hosts_ihp "$rule" "$ANYHOST"`
    rule9_FREE = get_hosts_ihp(rule, ANYHOST);
    hosts=rule9_FREE;;
    //ports=`get_ports_ihp "$rule" "$ANYPORT"`
    rule10_FREE = get_ports_ihp(rule, ANYPORT);
    ports=rule10_FREE;;

    //echo " Denying $hosts(LAN) for UDP port(s): $ports"
    printf(" Denying %s(LAN) for UDP port(s): %s" "\n", hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts5_FREE = ip_range(hosts, NULL);
    local14IFS = IFS;
    if (hosts5_FREE != NULL) strtok14_FREE = strdup(hosts5_FREE);
    if (hosts5_FREE != NULL) for (host = strtok_r(strtok14_FREE, local14IFS, &r_hosts5_FREE1); host != NULL; host = strtok_r(NULL, local14IFS, &r_hosts5_FREE1))
    {
      //for port in $ports; do
      local15IFS = IFS;
      if (ports != NULL) strtok15_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok15_FREE, local15IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local15IFS, &r_ports4))
      {
        //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A INT_INPUT_CHAIN -s $host -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN denied: "
          iptables("-A INT_INPUT_CHAIN -s %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN denied: \" --log-level %s", host, port, LOGLEVEL);
        //fi
        }
        //iptables -A INT_INPUT_CHAIN -s $host -p udp --dport $port -j DROP
        iptables("-A INT_INPUT_CHAIN -s %s -p udp --dport %s -j DROP", host, port);
      //done
      }
    //done
    }
  //done
  }

  //# IP protocols to DENY for certain LAN hosts
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_HOST_DENY_IP; do
  local16IFS = IFS;
  if (LAN_HOST_DENY_IP != NULL) strtok16_FREE = strdup(LAN_HOST_DENY_IP);
  if (LAN_HOST_DENY_IP != NULL) for (rule = strtok_r(strtok16_FREE, local16IFS, &r_LAN_HOST_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local16IFS, &r_LAN_HOST_DENY_IP1))
  {
    //hosts=`get_hosts_ihp "$rule" "$ANYHOST"`
    rule11_FREE = get_hosts_ihp(rule, ANYHOST);
    hosts=rule11_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule12_FREE = get_ports_ihp(rule, NULL);
    protos=rule12_FREE;;

    //echo " Denying $hosts(LAN) for IP protocol(s): $protos"
    printf(" Denying %s(LAN) for IP protocol(s): %s" "\n", hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts6_FREE = ip_range(hosts, NULL);
    local17IFS = IFS;
    if (hosts6_FREE != NULL) strtok17_FREE = strdup(hosts6_FREE);
    if (hosts6_FREE != NULL) for (host = strtok_r(strtok17_FREE, local17IFS, &r_hosts6_FREE1); host != NULL; host = strtok_r(NULL, local17IFS, &r_hosts6_FREE1))
    {
      //for proto in $protos; do
      local18IFS = IFS;
      if (protos != NULL) strtok18_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok18_FREE, local18IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local18IFS, &r_protos2))
      {
        //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A INT_INPUT_CHAIN -s $host -p $proto  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN denied: "
          iptables("-A INT_INPUT_CHAIN -s %s -p %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN denied: \" --log-level %s", host, proto, LOGLEVEL);
        //fi
        }
        //iptables -A INT_INPUT_CHAIN -s $host -p $proto -j DROP
        iptables("-A INT_INPUT_CHAIN -s %s -p %s -j DROP", host, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain TCP ports to be used from the LAN?
  //#######################################################
  //if [ -n "$LAN_OPEN_TCP" ]; then
  if  (  ((LAN_OPEN_TCP!=NULL)&&(strlen(LAN_OPEN_TCP)!=0))  )
  {
    //echo " Allowing TCP port(s): $LAN_OPEN_TCP"
    printf(" Allowing TCP port(s): %s" "\n", LAN_OPEN_TCP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $LAN_OPEN_TCP; do
    local19IFS = IFS;
    if (LAN_OPEN_TCP != NULL) strtok19_FREE = strdup(LAN_OPEN_TCP);
    if (LAN_OPEN_TCP != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_LAN_OPEN_TCP1); port != NULL; port = strtok_r(NULL, local19IFS, &r_LAN_OPEN_TCP1))
    {
      //iptables -A INT_INPUT_CHAIN -p tcp --dport $port -j ACCEPT
      iptables("-A INT_INPUT_CHAIN -p tcp --dport %s -j ACCEPT", port);
    //done
    }
  //fi
  }

  //# Allow only certain UDP ports to be used from the LAN?
  //#######################################################
  //if [ -n "$LAN_OPEN_UDP" ]; then
  if  (  ((LAN_OPEN_UDP!=NULL)&&(strlen(LAN_OPEN_UDP)!=0))  )
  {
    //echo " Allowing UDP port(s): $LAN_OPEN_UDP"
    printf(" Allowing UDP port(s): %s" "\n", LAN_OPEN_UDP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $LAN_OPEN_UDP; do
    local20IFS = IFS;
    if (LAN_OPEN_UDP != NULL) strtok20_FREE = strdup(LAN_OPEN_UDP);
    if (LAN_OPEN_UDP != NULL) for (port = strtok_r(strtok20_FREE, local20IFS, &r_LAN_OPEN_UDP1); port != NULL; port = strtok_r(NULL, local20IFS, &r_LAN_OPEN_UDP1))
    {
      //iptables -A INT_INPUT_CHAIN -p udp --dport $port -j ACCEPT
      iptables("-A INT_INPUT_CHAIN -p udp --dport %s -j ACCEPT", port);
    //done
    }
  //fi
  }

  //# Allow only certain IP protocols to be used from the LAN?
  //##########################################################
  //if [ -n "$LAN_OPEN_IP" ]; then
  if  (  ((LAN_OPEN_IP!=NULL)&&(strlen(LAN_OPEN_IP)!=0))  )
  {
    //echo " Allowing IP protocol(s): $LAN_OPEN_IP"
    printf(" Allowing IP protocol(s): %s" "\n", LAN_OPEN_IP);
    //IFS=' ,'
    IFS=" ,";
    //for proto in $LAN_OPEN_IP; do
    local21IFS = IFS;
    if (LAN_OPEN_IP != NULL) strtok21_FREE = strdup(LAN_OPEN_IP);
    if (LAN_OPEN_IP != NULL) for (proto = strtok_r(strtok21_FREE, local21IFS, &r_LAN_OPEN_IP1); proto != NULL; proto = strtok_r(NULL, local21IFS, &r_LAN_OPEN_IP1))
    {
      //iptables -A INT_INPUT_CHAIN -p $proto -j ACCEPT
      iptables("-A INT_INPUT_CHAIN -p %s -j ACCEPT", proto);
    //done
    }
  //fi
  }

  //# Allow world to send ICMP packets?
  //###################################
  //if [ "$LAN_OPEN_ICMP" != "0" ]; then
  if  (  (strcmp(LAN_OPEN_ICMP,"0")!=0)  )
  {
//Mos 2014/04/15, fix cannot ping 192.168.100.1 and 192.168.0.1 when disable port scan  
#if 0 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif    
    {
    //echo " Allowing ICMP-requests(ping)"
    printf(" Allowing ICMP-requests(ping)" "\n");
    //iptables -A INT_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A INT_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    }
  //fi
  }

  //# TCP ports to DENY for LAN hosts
  //#################################
  //if [ -n "$LAN_DENY_TCP" ]; then
  if  (  ((LAN_DENY_TCP!=NULL)&&(strlen(LAN_DENY_TCP)!=0))  )
  {
    //echo " Denying TCP port(s): $LAN_DENY_TCP"
    printf(" Denying TCP port(s): %s" "\n", LAN_DENY_TCP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $LAN_DENY_TCP; do
    local22IFS = IFS;
    if (LAN_DENY_TCP != NULL) strtok22_FREE = strdup(LAN_DENY_TCP);
    if (LAN_DENY_TCP != NULL) for (port = strtok_r(strtok22_FREE, local22IFS, &r_LAN_DENY_TCP1); port != NULL; port = strtok_r(NULL, local22IFS, &r_LAN_DENY_TCP1))
    {
      //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
      if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
      {
        //iptables -A INT_INPUT_CHAIN -p tcp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN-INPUT denied: "
        iptables("-A INT_INPUT_CHAIN -p tcp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN-INPUT denied: \" --log-level %s", port, LOGLEVEL);
      //fi
      }
      //iptables -A INT_INPUT_CHAIN -p tcp --dport $port -j DROP
      iptables("-A INT_INPUT_CHAIN -p tcp --dport %s -j DROP", port);
    //done
    }
  //fi
  }

  //# UDP ports to DENY for LAN hosts
  //#################################
  //if [ -n "$LAN_DENY_UDP" ]; then
  if  (  ((LAN_DENY_UDP!=NULL)&&(strlen(LAN_DENY_UDP)!=0))  )
  {
    //echo " Denying UDP port(s): $LAN_DENY_UDP"
    printf(" Denying UDP port(s): %s" "\n", LAN_DENY_UDP);
    //IFS=' ,'
    IFS=" ,";
    //for port in $LAN_DENY_UDP; do
    local23IFS = IFS;
    if (LAN_DENY_UDP != NULL) strtok23_FREE = strdup(LAN_DENY_UDP);
    if (LAN_DENY_UDP != NULL) for (port = strtok_r(strtok23_FREE, local23IFS, &r_LAN_DENY_UDP1); port != NULL; port = strtok_r(NULL, local23IFS, &r_LAN_DENY_UDP1))
    {
      //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
      if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
      {
        //iptables -A INT_INPUT_CHAIN -p udp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN-INPUT denied: "
        iptables("-A INT_INPUT_CHAIN -p udp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN-INPUT denied: \" --log-level %s", port, LOGLEVEL);
      //fi
      }
      //iptables -A INT_INPUT_CHAIN -p udp --dport $port -j DROP
      iptables("-A INT_INPUT_CHAIN -p udp --dport %s -j DROP", port);
    //done
    }
  //fi
  }

  //# IP protocols to DENY for LAN hosts
  //####################################
  //if [ -n "$LAN_DENY_IP" ]; then
  if  (  ((LAN_DENY_IP!=NULL)&&(strlen(LAN_DENY_IP)!=0))  )
  {
    //echo " Denying IP protocol(s): $LAN_DENY_IP"
    printf(" Denying IP protocol(s): %s" "\n", LAN_DENY_IP);
    //IFS=' ,'
    IFS=" ,";
    //for proto in $LAN_DENY_IP; do
    local24IFS = IFS;
    if (LAN_DENY_IP != NULL) strtok24_FREE = strdup(LAN_DENY_IP);
    if (LAN_DENY_IP != NULL) for (proto = strtok_r(strtok24_FREE, local24IFS, &r_LAN_DENY_IP1); proto != NULL; proto = strtok_r(NULL, local24IFS, &r_LAN_DENY_IP1))
    {
      //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
      if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
      {
        //iptables -A INT_INPUT_CHAIN -p $proto -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN-INPUT denied: "
        iptables("-A INT_INPUT_CHAIN -p %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN-INPUT denied: \" --log-level %s", proto, LOGLEVEL);
      //fi
      }
      //iptables -A INT_INPUT_CHAIN -p $proto -j DROP
      iptables("-A INT_INPUT_CHAIN -p %s -j DROP", proto);
    //done
    }
  //fi
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
    //iptables -A INT_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A INT_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop ICMP packets
  //iptables -A INT_INPUT_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A INT_INPUT_CHAIN -p icmp --icmp-type echo-request -j DROP");

  //# Set the default policy
  //########################
  //if [ -z "$LAN_OPEN_TCP" -a -z "$LAN_HOST_OPEN_TCP" -a  -z "$LAN_OPEN_UDP" -a -z "$LAN_HOST_OPEN_UDP" -a  -z "$LAN_OPEN_IP" -a -z "$LAN_HOST_OPEN_IP" ]; then
  if  (  (((((((LAN_OPEN_TCP==NULL)||(strlen(LAN_OPEN_TCP)==0))&&((LAN_HOST_OPEN_TCP==NULL)||(strlen(LAN_HOST_OPEN_TCP)==0)))&&((LAN_OPEN_UDP==NULL)||(strlen(LAN_OPEN_UDP)==0)))&&((LAN_HOST_OPEN_UDP==NULL)||(strlen(LAN_HOST_OPEN_UDP)==0)))&&((LAN_OPEN_IP==NULL)||(strlen(LAN_OPEN_IP)==0)))&&((LAN_HOST_OPEN_IP==NULL)||(strlen(LAN_HOST_OPEN_IP)==0))) )
  {
    //echo " Allowing all (other) ports/protocols"
    printf(" Allowing all (other) ports/protocols" "\n");
    //iptables -A INT_INPUT_CHAIN -j ACCEPT
    iptables("-A INT_INPUT_CHAIN -j ACCEPT");
  //else
  }
  else
  {
    //echo " Denying all (other) ports/protocols"
    printf(" Denying all (other) ports/protocols" "\n");
    //if [ "$LAN_INPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(LAN_INPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A INT_INPUT_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN-INPUT denied: "
      iptables("-A INT_INPUT_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN-INPUT denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //iptables -A INT_INPUT_CHAIN -j DROP
    iptables("-A INT_INPUT_CHAIN -j DROP");
  //fi
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (hosts6_FREE != NULL) free(hosts6_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (hosts5_FREE != NULL) free(hosts5_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (hosts4_FREE != NULL) free(hosts4_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//###################################################
//# Setup chain for the LAN-to-INET forward traffic #
//###################################################
void //setup_lan_inet_forward_chain()
setup_lan_inet_forward_chain(void)
//{
{
char *show_if_ip9_FREE = NULL;;
char *strtok42_FREE = NULL;;
char *strtok39_FREE = NULL;;
char *dhosts_protos3_FREE = NULL;;
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *r_LAN_INET_HOST_DENY_TCP1 = NULL;;
char *dhosts1_FREE = NULL;;
char *show_if_ip4_FREE = NULL;;
char *r_LAN_INET_OPEN_IP1 = NULL;;
char *rule15_FREE = NULL;;
char *shosts5_FREE = NULL;;
char *rule10_FREE = NULL;;
char *dhosts_protos = NULL;;
char *local40IFS = NULL;;
char *local37IFS = NULL;;
char *dhosts5_FREE = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *if_shosts10_FREE = NULL;;
char *if_shosts6_FREE = NULL;;
char *r_dhosts1_FREE1 = NULL;;
char *strtok10_FREE = NULL;;
char *dhosts_ports5_FREE = NULL;;
char *local5IFS = NULL;;
char *if_shosts1_FREE = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *r_LAN_INET_HOST_DENY_UDP1 = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *strtok34_FREE = NULL;;
char *local36IFS = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *r_LAN_INET_HOST_OPEN_UDP1 = NULL;;
char *strtok46_FREE = NULL;;
char *r_LAN_INET_HOST_OPEN_TCP1 = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *show_if_ip8_FREE = NULL;;
char *strtok41_FREE = NULL;;
char *strtok38_FREE = NULL;;
char *proto = NULL;;
char *dhosts_protos2_FREE = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *local47IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *rule14_FREE = NULL;;
char *local25IFS = NULL;;
char *r_interfaces3 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *local35IFS = NULL;;
char *r_interfaces7 = NULL;;
char *r_interfaces8 = NULL;;
char *dhosts4_FREE = NULL;;
char *dhosts_ports = NULL;;
char *r_LAN_INET_DENY_IP1 = NULL;;
char *r_interfaces9 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *if_shosts5_FREE = NULL;;
char *dhosts_ports4_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *local46IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *if_shosts9_FREE = NULL;;
char *shost = NULL;;
char *show_if_ip12_FREE = NULL;;
char *strtok13_FREE = NULL;;
char *strtok33_FREE = NULL;;
char *dhosts_ports8_FREE = NULL;;
char *shosts4_FREE = NULL;;
char *local34IFS = NULL;;
char *rule6_FREE = NULL;;
char *rule = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok45_FREE = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *r_dhosts4_FREE1 = NULL;;
char *if_shosts = NULL;;
char *strtok40_FREE = NULL;;
char *strtok37_FREE = NULL;;
char *r_dhosts6_FREE1 = NULL;;
char *dhosts_protos1_FREE = NULL;;
char *local45IFS = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *rule13_FREE = NULL;;
char *local23IFS = NULL;;
char *r_shosts5_FREE1 = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *r_LAN_INET_HOST_OPEN_IP1 = NULL;;
char *strtok8_FREE = NULL;;
char *r_protos3 = NULL;;
char *r_ports4 = NULL;;
char *r_protos4 = NULL;;
char *r_ports5 = NULL;;
char *r_ports6 = NULL;;
char *r_ports7 = NULL;;
char *dhosts3_FREE = NULL;;
char *r_ports8 = NULL;;
char *dhost = NULL;;
char *interface = NULL;;
char *rule20_FREE = NULL;;
char *if_shosts4_FREE = NULL;;
char *dhosts_ports3_FREE = NULL;;
char *local44IFS = NULL;;
char *r_dhosts2_FREE1 = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *show_if_ip11_FREE = NULL;;
char *strtok32_FREE = NULL;;
char *strtok29_FREE = NULL;;
char *dhosts_ports7_FREE = NULL;;
char *shosts3_FREE = NULL;;
char *r_LAN_INET_HOST_DENY_IP1 = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok44_FREE = NULL;;
char *local33IFS = NULL;;
char *strtok3_FREE = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *rule17_FREE = NULL;;
char *local43IFS = NULL;;
char *show_if_ip1_FREE = NULL;;
char *rule12_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *rule24_FREE = NULL;;
char *if_shosts12_FREE = NULL;;
char *if_shosts8_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *dhosts2_FREE = NULL;;
char *local32IFS = NULL;;
char *local29IFS = NULL;;
char *if_shosts3_FREE = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *dhosts_ports2_FREE = NULL;;
char *strtok16_FREE = NULL;;
char *strtok36_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *shosts = NULL;;
char *show_if_ip10_FREE = NULL;;
char *rule9_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *dhosts_ports6_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *strtok48_FREE = NULL;;
char *rule4_FREE = NULL;;
char *strtok43_FREE = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *dhosts_protos4_FREE = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *r_LAN_INET_DENY_TCP1 = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *shosts6_FREE = NULL;;
char *rule11_FREE = NULL;;
char *local42IFS = NULL;;
char *local39IFS = NULL;;
char *r_LAN_INET_OPEN_TCP1 = NULL;;
char *dhosts6_FREE = NULL;;
char *r_shosts4_FREE1 = NULL;;
char *rule23_FREE = NULL;;
char *r_shosts6_FREE1 = NULL;;
char *if_shosts11_FREE = NULL;;
char *if_shosts7_FREE = NULL;;
char *strtok11_FREE = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *if_shosts2_FREE = NULL;;
char *r_interfaces10 = NULL;;
char *strtok23_FREE = NULL;;
char *dhosts_ports1_FREE = NULL;;
char *r_interfaces11 = NULL;;
char *r_LAN_INET_DENY_UDP1 = NULL;;
char *r_interfaces12 = NULL;;
char *strtok15_FREE = NULL;;
char *dhosts = NULL;;
char *strtok35_FREE = NULL;;
char *local41IFS = NULL;;
char *local38IFS = NULL;;
char *rule8_FREE = NULL;;
char *r_dhosts3_FREE1 = NULL;;
char *r_LAN_INET_OPEN_UDP1 = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *r_dhosts5_FREE1 = NULL;;
char *local16IFS = NULL;;
char *shosts1_FREE = NULL;;
char *strtok47_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *local48IFS = NULL;;
char *r_shosts2_FREE1 = NULL;;
char *rule3_FREE = NULL;;

  //echo " Setting up LAN->INET policy"
  printf(" Setting up LAN->INET policy" "\n");

  //# udp ports to ALLOW for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_OPEN_TCP; do
  local1IFS = IFS;
  if (LAN_INET_HOST_OPEN_TCP != NULL) strtok1_FREE = strdup(LAN_INET_HOST_OPEN_TCP);
  if (LAN_INET_HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_LAN_INET_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_LAN_INET_HOST_OPEN_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts1_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts1_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts2_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts2_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule2_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports1_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports1_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports2_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports2_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(LAN) to $dhosts(INET) for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(LAN) to %s(INET) for TCP port(s): %s;" "\n", show_if_ip1_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local2IFS = IFS;
    if (shosts1_FREE != NULL) strtok2_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok2_FREE, local2IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local2IFS, &r_shosts1_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts1_FREE = ip_range(dhosts, NULL);
      local3IFS = IFS;
      if (dhosts1_FREE != NULL) strtok3_FREE = strdup(dhosts1_FREE);
      if (dhosts1_FREE != NULL) for (dhost = strtok_r(strtok3_FREE, local3IFS, &r_dhosts1_FREE1); dhost != NULL; dhost = strtok_r(NULL, local3IFS, &r_dhosts1_FREE1))
      {
        //for port in $ports; do
        local4IFS = IFS;
        if (ports != NULL) strtok4_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok4_FREE, local4IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local4IFS, &r_ports1))
        {
          //for interface in $interfaces; do
          local5IFS = IFS;
          if (interfaces != NULL) strtok5_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok5_FREE, local5IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local5IFS, &r_interfaces1))
          {
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port -j ACCEPT
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to ALLOW for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_OPEN_UDP; do
  local6IFS = IFS;
  if (LAN_INET_HOST_OPEN_UDP != NULL) strtok6_FREE = strdup(LAN_INET_HOST_OPEN_UDP);
  if (LAN_INET_HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok6_FREE, local6IFS, &r_LAN_INET_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local6IFS, &r_LAN_INET_HOST_OPEN_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts3_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts3_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts4_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts4_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule4_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports3_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports3_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports4_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports4_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(LAN) to $dhosts(INET) for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(LAN) to %s(INET) for UDP port(s): %s;" "\n", show_if_ip2_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local7IFS = IFS;
    if (shosts2_FREE != NULL) strtok7_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok7_FREE, local7IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local7IFS, &r_shosts2_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts2_FREE = ip_range(dhosts, NULL);
      local8IFS = IFS;
      if (dhosts2_FREE != NULL) strtok8_FREE = strdup(dhosts2_FREE);
      if (dhosts2_FREE != NULL) for (dhost = strtok_r(strtok8_FREE, local8IFS, &r_dhosts2_FREE1); dhost != NULL; dhost = strtok_r(NULL, local8IFS, &r_dhosts2_FREE1))
      {
        //for port in $ports; do
        local9IFS = IFS;
        if (ports != NULL) strtok9_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok9_FREE, local9IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local9IFS, &r_ports2))
        {
          //for interface in $interfaces; do
          local10IFS = IFS;
          if (interfaces != NULL) strtok10_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok10_FREE, local10IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local10IFS, &r_interfaces2))
          {
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port -j ACCEPT
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s -j ACCEPT", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to ALLOW for certain LAN hosts
  //#####################################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_OPEN_IP; do
  local11IFS = IFS;
  if (LAN_INET_HOST_OPEN_IP != NULL) strtok11_FREE = strdup(LAN_INET_HOST_OPEN_IP);
  if (LAN_INET_HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok11_FREE, local11IFS, &r_LAN_INET_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local11IFS, &r_LAN_INET_HOST_OPEN_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts5_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts5_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts6_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts6_FREE;;
    //dhosts_protos=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhosts_protos=rule6_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_protos"`
    dhosts_protos1_FREE = get_hosts_hp(dhosts_protos, NULL);
    dhosts=dhosts_protos1_FREE;;
    //protos=`get_ports_hp "$dhosts_protos"`
    dhosts_protos2_FREE = get_ports_hp(dhosts_protos, NULL);
    protos=dhosts_protos2_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing $shosts(LAN) to $dhosts(INET) for IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing %s(LAN) to %s(INET) for IP protocol(s): %s;" "\n", show_if_ip3_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local12IFS = IFS;
    if (shosts3_FREE != NULL) strtok12_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok12_FREE, local12IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local12IFS, &r_shosts3_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts3_FREE = ip_range(dhosts, NULL);
      local13IFS = IFS;
      if (dhosts3_FREE != NULL) strtok13_FREE = strdup(dhosts3_FREE);
      if (dhosts3_FREE != NULL) for (dhost = strtok_r(strtok13_FREE, local13IFS, &r_dhosts3_FREE1); dhost != NULL; dhost = strtok_r(NULL, local13IFS, &r_dhosts3_FREE1))
      {
        //for proto in $protos; do
        local14IFS = IFS;
        if (protos != NULL) strtok14_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok14_FREE, local14IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local14IFS, &r_protos1))
        {
          //for interface in $interfaces; do
          local15IFS = IFS;
          if (interfaces != NULL) strtok15_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok15_FREE, local15IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local15IFS, &r_interfaces3))
          {
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto -j ACCEPT
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s -j ACCEPT", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# udp ports to DENY for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_DENY_TCP; do
  local16IFS = IFS;
  if (LAN_INET_HOST_DENY_TCP != NULL) strtok16_FREE = strdup(LAN_INET_HOST_DENY_TCP);
  if (LAN_INET_HOST_DENY_TCP != NULL) for (rule = strtok_r(strtok16_FREE, local16IFS, &r_LAN_INET_HOST_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local16IFS, &r_LAN_INET_HOST_DENY_TCP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule7_FREE = getfield(rule, ">", 1);
    if_shosts=rule7_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts7_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts7_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts8_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts8_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule8_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule8_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports5_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports5_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports6_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports6_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(LAN) to $dhosts(INET) for TCP port(s): $ports"
    show_if_ip4_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(LAN) to %s(INET) for TCP port(s): %s;" "\n", show_if_ip4_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts4_FREE = ip_range(shosts, NULL);
    local17IFS = IFS;
    if (shosts4_FREE != NULL) strtok17_FREE = strdup(shosts4_FREE);
    if (shosts4_FREE != NULL) for (shost = strtok_r(strtok17_FREE, local17IFS, &r_shosts4_FREE1); shost != NULL; shost = strtok_r(NULL, local17IFS, &r_shosts4_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts4_FREE = ip_range(dhosts, NULL);
      local18IFS = IFS;
      if (dhosts4_FREE != NULL) strtok18_FREE = strdup(dhosts4_FREE);
      if (dhosts4_FREE != NULL) for (dhost = strtok_r(strtok18_FREE, local18IFS, &r_dhosts4_FREE1); dhost != NULL; dhost = strtok_r(NULL, local18IFS, &r_dhosts4_FREE1))
      {
        //for port in $ports; do
        local19IFS = IFS;
        if (ports != NULL) strtok19_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local19IFS, &r_ports3))
        {
          //for interface in $interfaces; do
          local20IFS = IFS;
          if (interfaces != NULL) strtok20_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok20_FREE, local20IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local20IFS, &r_interfaces4))
          {
            //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN->INET denied: "
              iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN->INET denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p tcp --dport $port -j DROP
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p tcp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for certain LAN hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_DENY_UDP; do
  local21IFS = IFS;
  if (LAN_INET_HOST_DENY_UDP != NULL) strtok21_FREE = strdup(LAN_INET_HOST_DENY_UDP);
  if (LAN_INET_HOST_DENY_UDP != NULL) for (rule = strtok_r(strtok21_FREE, local21IFS, &r_LAN_INET_HOST_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local21IFS, &r_LAN_INET_HOST_DENY_UDP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule9_FREE = getfield(rule, ">", 1);
    if_shosts=rule9_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts9_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts9_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts10_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts10_FREE;;
    //dhosts_ports=`echo "$rule" |cut -s -d'>' -f2`
    rule10_FREE = getfield(rule, ">", 2);
    dhosts_ports=rule10_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_ports"`
    dhosts_ports7_FREE = get_hosts_hp(dhosts_ports, NULL);
    dhosts=dhosts_ports7_FREE;;
    //ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
    dhosts_ports8_FREE = get_ports_hp(dhosts_ports, ANYPORT);
    ports=dhosts_ports8_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(LAN) to $dhosts(INET) for UDP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(LAN) to %s(INET) for UDP port(s): %s;" "\n", show_if_ip5_FREE, shosts, dhosts, ports);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts5_FREE = ip_range(shosts, NULL);
    local22IFS = IFS;
    if (shosts5_FREE != NULL) strtok22_FREE = strdup(shosts5_FREE);
    if (shosts5_FREE != NULL) for (shost = strtok_r(strtok22_FREE, local22IFS, &r_shosts5_FREE1); shost != NULL; shost = strtok_r(NULL, local22IFS, &r_shosts5_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts5_FREE = ip_range(dhosts, NULL);
      local23IFS = IFS;
      if (dhosts5_FREE != NULL) strtok23_FREE = strdup(dhosts5_FREE);
      if (dhosts5_FREE != NULL) for (dhost = strtok_r(strtok23_FREE, local23IFS, &r_dhosts5_FREE1); dhost != NULL; dhost = strtok_r(NULL, local23IFS, &r_dhosts5_FREE1))
      {
        //for port in $ports; do
        local24IFS = IFS;
        if (ports != NULL) strtok24_FREE = strdup(ports);
        if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports4))
        {
          //for interface in $interfaces; do
          local25IFS = IFS;
          if (interfaces != NULL) strtok25_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok25_FREE, local25IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local25IFS, &r_interfaces5))
          {
            //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN->INET denied: "
              iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN->INET denied: \" --log-level %s", interface, shost, dhost, port, LOGLEVEL);
            //fi
            }
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p udp --dport $port -j DROP
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p udp --dport %s -j DROP", interface, shost, dhost, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# (Other) IP protocols to DENY for certain LAN hosts
  //#####################################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_HOST_DENY_IP; do
  local26IFS = IFS;
  if (LAN_INET_HOST_DENY_IP != NULL) strtok26_FREE = strdup(LAN_INET_HOST_DENY_IP);
  if (LAN_INET_HOST_DENY_IP != NULL) for (rule = strtok_r(strtok26_FREE, local26IFS, &r_LAN_INET_HOST_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local26IFS, &r_LAN_INET_HOST_DENY_IP1))
  {
    //if_shosts=`echo "$rule" |cut -s -d'>' -f1`
    rule11_FREE = getfield(rule, ">", 1);
    if_shosts=rule11_FREE;;
    //interfaces=`get_ifs "$if_shosts"`
    if_shosts11_FREE = get_ifs(if_shosts, NULL);
    interfaces=if_shosts11_FREE;;
    //shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
    if_shosts12_FREE = get_hosts_ih(if_shosts, ANYHOST);
    shosts=if_shosts12_FREE;;
    //dhosts_protos=`echo "$rule" |cut -s -d'>' -f2`
    rule12_FREE = getfield(rule, ">", 2);
    dhosts_protos=rule12_FREE;;
    //dhosts=`get_hosts_hp "$dhosts_protos"`
    dhosts_protos3_FREE = get_hosts_hp(dhosts_protos, NULL);
    dhosts=dhosts_protos3_FREE;;
    //protos=`get_ports_hp "$dhosts_protos"`
    dhosts_protos4_FREE = get_ports_hp(dhosts_protos, NULL);
    protos=dhosts_protos4_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying $shosts(LAN) to $dhosts(INET) for IP protocol(s): $protos"
    show_if_ip6_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying %s(LAN) to %s(INET) for IP protocol(s): %s;" "\n", show_if_ip6_FREE, shosts, dhosts, protos);

    //IFS=','
    IFS=",";
    //for shost in `ip_range "$shosts"`; do
    shosts6_FREE = ip_range(shosts, NULL);
    local27IFS = IFS;
    if (shosts6_FREE != NULL) strtok27_FREE = strdup(shosts6_FREE);
    if (shosts6_FREE != NULL) for (shost = strtok_r(strtok27_FREE, local27IFS, &r_shosts6_FREE1); shost != NULL; shost = strtok_r(NULL, local27IFS, &r_shosts6_FREE1))
    {
      //for dhost in `ip_range "$dhosts"`; do
      dhosts6_FREE = ip_range(dhosts, NULL);
      local28IFS = IFS;
      if (dhosts6_FREE != NULL) strtok28_FREE = strdup(dhosts6_FREE);
      if (dhosts6_FREE != NULL) for (dhost = strtok_r(strtok28_FREE, local28IFS, &r_dhosts6_FREE1); dhost != NULL; dhost = strtok_r(NULL, local28IFS, &r_dhosts6_FREE1))
      {
        //for proto in $protos; do
        local29IFS = IFS;
        if (protos != NULL) strtok29_FREE = strdup(protos);
        if (protos != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_protos2))
        {
          //for interface in $interfaces; do
          local30IFS = IFS;
          if (interfaces != NULL) strtok30_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok30_FREE, local30IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local30IFS, &r_interfaces6))
          {
            //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host LAN->INET denied: "
              iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host LAN->INET denied: \" --log-level %s", interface, shost, dhost, proto, LOGLEVEL);
            //fi
            }
            //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -s $shost -d $dhost -p $proto -j DROP
            iptables("-A LAN_INET_FORWARD_CHAIN -o %s -s %s -d %s -p %s -j DROP", interface, shost, dhost, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain udp ports to be used from the LAN->INET?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_OPEN_TCP; do
  local31IFS = IFS;
  if (LAN_INET_OPEN_TCP != NULL) strtok31_FREE = strdup(LAN_INET_OPEN_TCP);
  if (LAN_INET_OPEN_TCP != NULL) for (rule = strtok_r(strtok31_FREE, local31IFS, &r_LAN_INET_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local31IFS, &r_LAN_INET_OPEN_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule14_FREE = get_ports_ihp(rule, NULL);
    ports=rule14_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing TCP port(s): $ports"
    show_if_ip7_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing TCP port(s): %s;" "\n", show_if_ip7_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local32IFS = IFS;
    if (ports != NULL) strtok32_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok32_FREE, local32IFS, &r_ports5); port != NULL; port = strtok_r(NULL, local32IFS, &r_ports5))
    {
      //for interface in $interfaces; do
      local33IFS = IFS;
      if (interfaces != NULL) strtok33_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok33_FREE, local33IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local33IFS, &r_interfaces7))
      {
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -j ACCEPT
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -j ACCEPT", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain UDP ports to be used from the LAN->INET?
  //#############################################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_OPEN_UDP; do
  local34IFS = IFS;
  if (LAN_INET_OPEN_UDP != NULL) strtok34_FREE = strdup(LAN_INET_OPEN_UDP);
  if (LAN_INET_OPEN_UDP != NULL) for (rule = strtok_r(strtok34_FREE, local34IFS, &r_LAN_INET_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local34IFS, &r_LAN_INET_OPEN_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule15_FREE = get_ifs(rule, NULL);
    interfaces=rule15_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule16_FREE = get_ports_ihp(rule, NULL);
    ports=rule16_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing UDP port(s): $ports"
    show_if_ip8_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing UDP port(s): %s;" "\n", show_if_ip8_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local35IFS = IFS;
    if (ports != NULL) strtok35_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok35_FREE, local35IFS, &r_ports6); port != NULL; port = strtok_r(NULL, local35IFS, &r_ports6))
    {
      //for interface in $interfaces; do
      local36IFS = IFS;
      if (interfaces != NULL) strtok36_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok36_FREE, local36IFS, &r_interfaces8); interface != NULL; interface = strtok_r(NULL, local36IFS, &r_interfaces8))
      {
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -j ACCEPT
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p udp --dport %s -j ACCEPT", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# Allow only certain IP protocols to be used from the LAN->INET?
  //################################################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_OPEN_IP; do
  local37IFS = IFS;
  if (LAN_INET_OPEN_IP != NULL) strtok37_FREE = strdup(LAN_INET_OPEN_IP);
  if (LAN_INET_OPEN_IP != NULL) for (rule = strtok_r(strtok37_FREE, local37IFS, &r_LAN_INET_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local37IFS, &r_LAN_INET_OPEN_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule17_FREE = get_ifs(rule, NULL);
    interfaces=rule17_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule18_FREE = get_ports_ihp(rule, NULL);
    protos=rule18_FREE;;

    //echo "  $(show_if_ip "$interfaces")Allowing IP protocol(s): $protos"
    show_if_ip9_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Allowing IP protocol(s): %s;" "\n", show_if_ip9_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local38IFS = IFS;
    if (protos != NULL) strtok38_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok38_FREE, local38IFS, &r_protos3); proto != NULL; proto = strtok_r(NULL, local38IFS, &r_protos3))
    {
      //for interface in $interfaces; do
      local39IFS = IFS;
      if (interfaces != NULL) strtok39_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok39_FREE, local39IFS, &r_interfaces9); interface != NULL; interface = strtok_r(NULL, local39IFS, &r_interfaces9))
      {
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p $proto -j ACCEPT
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p %s -j ACCEPT", interface, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Allow ICMP-requests(ping) for LAN->INET?
  //##########################################
  //if [ "$LAN_INET_OPEN_ICMP" != "0" ]; then
  if  (  (strcmp(LAN_INET_OPEN_ICMP,"0")!=0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
    //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.    
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then    
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif    
    {
    //echo "  Allowing ICMP-requests(ping)"
    printf("  Allowing ICMP-requests(ping)" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    iptables("-A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    }
  //fi
  }

  //# TCP ports to DENY for LAN->INET
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_DENY_TCP; do
  local40IFS = IFS;
  if (LAN_INET_DENY_TCP != NULL) strtok40_FREE = strdup(LAN_INET_DENY_TCP);
  if (LAN_INET_DENY_TCP != NULL) for (rule = strtok_r(strtok40_FREE, local40IFS, &r_LAN_INET_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local40IFS, &r_LAN_INET_DENY_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule19_FREE = get_ifs(rule, NULL);
    interfaces=rule19_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule20_FREE = get_ports_ihp(rule, NULL);
    ports=rule20_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying TCP port(s): $ports"
    show_if_ip10_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying TCP port(s): %s;" "\n", show_if_ip10_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local41IFS = IFS;
    if (ports != NULL) strtok41_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok41_FREE, local41IFS, &r_ports7); port != NULL; port = strtok_r(NULL, local41IFS, &r_ports7))
    {
      //for interface in $interfaces; do
      local42IFS = IFS;
      if (interfaces != NULL) strtok42_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok42_FREE, local42IFS, &r_interfaces10); interface != NULL; interface = strtok_r(NULL, local42IFS, &r_interfaces10))
      {
        //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
          iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", interface, port, LOGLEVEL);
        //fi
        }
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p tcp --dport $port -j DROP
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p tcp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY for LAN->INET
  //#################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_DENY_UDP; do
  local43IFS = IFS;
  if (LAN_INET_DENY_UDP != NULL) strtok43_FREE = strdup(LAN_INET_DENY_UDP);
  if (LAN_INET_DENY_UDP != NULL) for (rule = strtok_r(strtok43_FREE, local43IFS, &r_LAN_INET_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local43IFS, &r_LAN_INET_DENY_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule21_FREE = get_ifs(rule, NULL);
    interfaces=rule21_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule22_FREE = get_ports_ihp(rule, NULL);
    ports=rule22_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying UDP port(s): $ports"
    show_if_ip11_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying UDP port(s): %s;" "\n", show_if_ip11_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local44IFS = IFS;
    if (ports != NULL) strtok44_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok44_FREE, local44IFS, &r_ports8); port != NULL; port = strtok_r(NULL, local44IFS, &r_ports8))
    {
      //for interface in $interfaces; do
      local45IFS = IFS;
      if (interfaces != NULL) strtok45_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok45_FREE, local45IFS, &r_interfaces11); interface != NULL; interface = strtok_r(NULL, local45IFS, &r_interfaces11))
      {
        //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
          iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p udp --dport %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", interface, port, LOGLEVEL);
        //fi
        }
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p udp --dport $port -j DROP
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p udp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# IP protocols to DENY for LAN->INET
  //####################################
  //unset IFS
  IFS = " ";
  //for rule in $LAN_INET_DENY_IP; do
  local46IFS = IFS;
  if (LAN_INET_DENY_IP != NULL) strtok46_FREE = strdup(LAN_INET_DENY_IP);
  if (LAN_INET_DENY_IP != NULL) for (rule = strtok_r(strtok46_FREE, local46IFS, &r_LAN_INET_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local46IFS, &r_LAN_INET_DENY_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule23_FREE = get_ifs(rule, NULL);
    interfaces=rule23_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule24_FREE = get_ports_ihp(rule, NULL);
    protos=rule24_FREE;;

    //echo "  $(show_if_ip "$interfaces")Denying IP protocol(s): $protos"
    show_if_ip12_FREE = show_if_ip(interfaces, NULL);
    printf("  %s Denying IP protocol(s): %s;" "\n", show_if_ip12_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local47IFS = IFS;
    if (protos != NULL) strtok47_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok47_FREE, local47IFS, &r_protos4); proto != NULL; proto = strtok_r(NULL, local47IFS, &r_protos4))
    {
      //for interface in $interfaces; do
      local48IFS = IFS;
      if (interfaces != NULL) strtok48_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok48_FREE, local48IFS, &r_interfaces12); interface != NULL; interface = strtok_r(NULL, local48IFS, &r_interfaces12))
      {
        //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
        if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
        {
          //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p $proto -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
          iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p %s -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", interface, proto, LOGLEVEL);
        //fi
        }
        //iptables -A LAN_INET_FORWARD_CHAIN -o $interface -p $proto -j DROP
        iptables("-A LAN_INET_FORWARD_CHAIN -o %s -p %s -j DROP", interface, proto);
      //done
      }
    //done
    }
  //done
  }

  //# Log incoming ICMP-request packets?
  //####################################
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
    //iptables -A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"AIF:ICMP-request: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop ICMP packets
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))
#endif		
  {
  //iptables -A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP
  iptables("-A LAN_INET_FORWARD_CHAIN -p icmp --icmp-type echo-request -j DROP");
  }

  //# Set the default policy (switch to DROP for a protocol when xxx_OPEN_xxx variable is used)
  //###########################################################################################
  //if [ -z "$LAN_INET_OPEN_TCP" ]; then
  if  (  ((LAN_INET_OPEN_TCP==NULL)||(strlen(LAN_INET_OPEN_TCP)==0))  )
  {
    //echo "  Allowing all (other) TCP ports"
    printf("  Allowing all (other) TCP ports" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -p tcp -j ACCEPT
    iptables("-A LAN_INET_FORWARD_CHAIN -p tcp -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A LAN_INET_FORWARD_CHAIN -p tcp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
      iptables("-A LAN_INET_FORWARD_CHAIN -p tcp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) TCP ports"
    printf("  Denying all (other) TCP ports" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -p tcp -j DROP
    iptables("-A LAN_INET_FORWARD_CHAIN -p tcp -j DROP");
  //fi
  }

  //if [ -z "$LAN_INET_OPEN_UDP" ]; then
  if  (  ((LAN_INET_OPEN_UDP==NULL)||(strlen(LAN_INET_OPEN_UDP)==0))  )
  {
    //echo "  Allowing all (other) UDP ports"
    printf("  Allowing all (other) UDP ports" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -p udp -j ACCEPT
    iptables("-A LAN_INET_FORWARD_CHAIN -p udp -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A LAN_INET_FORWARD_CHAIN -p udp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
      iptables("-A LAN_INET_FORWARD_CHAIN -p udp -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) UDP ports"
    printf("  Denying all (other) UDP ports" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -p udp -j DROP
    iptables("-A LAN_INET_FORWARD_CHAIN -p udp -j DROP");
  //fi
  }

  //if [ -z "$LAN_INET_OPEN_IP" ]; then
  if  (  ((LAN_INET_OPEN_IP==NULL)||(strlen(LAN_INET_OPEN_IP)==0))  )
  {
    //echo "  Allowing all (other) protocols"
    printf("  Allowing all (other) protocols" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -j ACCEPT
    iptables("-A LAN_INET_FORWARD_CHAIN -j ACCEPT");
  //else
  }
  else
  {
    //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //iptables -A LAN_INET_FORWARD_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:LAN->INET denied: "
      iptables("-A LAN_INET_FORWARD_CHAIN -m limit  --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:LAN->INET denied: \" --log-level %s", LOGLEVEL);
    //fi
    }
    //echo "  Denying all (other) protocols"
    printf("  Denying all (other) protocols" "\n");
    //iptables -A LAN_INET_FORWARD_CHAIN -j DROP
    iptables("-A LAN_INET_FORWARD_CHAIN -j DROP");
  //fi
  }
if (show_if_ip9_FREE != NULL) free(show_if_ip9_FREE);
if (strtok42_FREE != NULL) free(strtok42_FREE);
if (strtok39_FREE != NULL) free(strtok39_FREE);
if (dhosts_protos3_FREE != NULL) free(dhosts_protos3_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (dhosts1_FREE != NULL) free(dhosts1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (shosts5_FREE != NULL) free(shosts5_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (dhosts5_FREE != NULL) free(dhosts5_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (if_shosts10_FREE != NULL) free(if_shosts10_FREE);
if (if_shosts6_FREE != NULL) free(if_shosts6_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (dhosts_ports5_FREE != NULL) free(dhosts_ports5_FREE);
if (if_shosts1_FREE != NULL) free(if_shosts1_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok34_FREE != NULL) free(strtok34_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok46_FREE != NULL) free(strtok46_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip8_FREE != NULL) free(show_if_ip8_FREE);
if (strtok41_FREE != NULL) free(strtok41_FREE);
if (strtok38_FREE != NULL) free(strtok38_FREE);
if (dhosts_protos2_FREE != NULL) free(dhosts_protos2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (dhosts4_FREE != NULL) free(dhosts4_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (if_shosts5_FREE != NULL) free(if_shosts5_FREE);
if (dhosts_ports4_FREE != NULL) free(dhosts_ports4_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (if_shosts9_FREE != NULL) free(if_shosts9_FREE);
if (show_if_ip12_FREE != NULL) free(show_if_ip12_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (strtok33_FREE != NULL) free(strtok33_FREE);
if (dhosts_ports8_FREE != NULL) free(dhosts_ports8_FREE);
if (shosts4_FREE != NULL) free(shosts4_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok45_FREE != NULL) free(strtok45_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (strtok40_FREE != NULL) free(strtok40_FREE);
if (strtok37_FREE != NULL) free(strtok37_FREE);
if (dhosts_protos1_FREE != NULL) free(dhosts_protos1_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (dhosts3_FREE != NULL) free(dhosts3_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (if_shosts4_FREE != NULL) free(if_shosts4_FREE);
if (dhosts_ports3_FREE != NULL) free(dhosts_ports3_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (show_if_ip11_FREE != NULL) free(show_if_ip11_FREE);
if (strtok32_FREE != NULL) free(strtok32_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (dhosts_ports7_FREE != NULL) free(dhosts_ports7_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok44_FREE != NULL) free(strtok44_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (if_shosts12_FREE != NULL) free(if_shosts12_FREE);
if (if_shosts8_FREE != NULL) free(if_shosts8_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (dhosts2_FREE != NULL) free(dhosts2_FREE);
if (if_shosts3_FREE != NULL) free(if_shosts3_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (dhosts_ports2_FREE != NULL) free(dhosts_ports2_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (strtok36_FREE != NULL) free(strtok36_FREE);
if (show_if_ip10_FREE != NULL) free(show_if_ip10_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (dhosts_ports6_FREE != NULL) free(dhosts_ports6_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (strtok48_FREE != NULL) free(strtok48_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok43_FREE != NULL) free(strtok43_FREE);
if (dhosts_protos4_FREE != NULL) free(dhosts_protos4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (shosts6_FREE != NULL) free(shosts6_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (dhosts6_FREE != NULL) free(dhosts6_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (if_shosts11_FREE != NULL) free(if_shosts11_FREE);
if (if_shosts7_FREE != NULL) free(if_shosts7_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (if_shosts2_FREE != NULL) free(if_shosts2_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (dhosts_ports1_FREE != NULL) free(dhosts_ports1_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (strtok35_FREE != NULL) free(strtok35_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (strtok47_FREE != NULL) free(strtok47_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//######################################################################################################################
//## Chain EXT_INPUT_CHAIN - Checks all incoming packets for the EXTERNAL interface(s)                                ##
//######################################################################################################################
void //setup_ext_input_chain()
setup_ext_input_chain(void)
//{
{
char *strtok95_FREE = NULL;;
char *strtok36_FREE = NULL;;
char *r_destips15 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_destips16 = NULL;;
char *r_destips17 = NULL;;
char *r_destips18 = NULL;;
char *r_destips19 = NULL;;
char *strtok119_FREE = NULL;;
char *local78IFS = NULL;;
char *rule41_FREE = NULL;;
char *port = NULL;;
char *rule67_FREE = NULL;;
char *strtok45_FREE = NULL;;
char *awk2_FREE = NULL;;
char *r_HOST_DENY_IP_NOLOG1 = NULL;;
char *strtok128_FREE = NULL;;
char *local124IFS = NULL;;
char *local120IFS = NULL;;
char *rule50_FREE = NULL;;
char *show_if_ip27_FREE = NULL;;
char *local43IFS = NULL;;
char *strtok54_FREE = NULL;;
char *r_interfaces10 = NULL;;
char *r_hosts16_FREE1 = NULL;;
char *r_interfaces11 = NULL;;
char *show_if_ip6_FREE = NULL;;
char *rule = NULL;;
char *r_interfaces12 = NULL;;
char *r_interfaces13 = NULL;;
char *r_interfaces14 = NULL;;
char *r_interfaces15 = NULL;;
char *r_interfaces16 = NULL;;
char *r_interfaces17 = NULL;;
char *strtok120_FREE = NULL;;
char *r_interfaces18 = NULL;;
char *strtok63_FREE = NULL;;
char *r_interfaces19 = NULL;;
char *local125IFS = NULL;;
char *local121IFS = NULL;;
char *local48IFS = NULL;;
char *local44IFS = NULL;;
char *r_hosts11_FREE1 = NULL;;
char *local40IFS = NULL;;
char *strtok13_FREE = NULL;;
char *strtok58_FREE = NULL;;
char *local126IFS = NULL;;
char *local122IFS = NULL;;
char *rule63_FREE = NULL;;
char *r_hosts8_FREE1 = NULL;;
char *local41IFS = NULL;;
char *local49IFS = NULL;;
char *local45IFS = NULL;;
char *strtok7_FREE = NULL;;
char *rule89_FREE = NULL;;
char *strtok67_FREE = NULL;;
char *rule72_FREE = NULL;;
char *rule13_FREE = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *local127IFS = NULL;;
char *local123IFS = NULL;;
char *strtok17_FREE = NULL;;
char *strtok76_FREE = NULL;;
char *r_ports20 = NULL;;
char *local42IFS = NULL;;
char *local46IFS = NULL;;
char *rule81_FREE = NULL;;
char *rule22_FREE = NULL;;
char *r_HOST_DENY_TCP1 = NULL;;
char *strtok26_FREE = NULL;;
char *strtok85_FREE = NULL;;
char *local91IFS = NULL;;
char *hosts5_FREE = NULL;;
char *rule90_FREE = NULL;;
char *rule31_FREE = NULL;;
char *hosts15_FREE = NULL;;
char *local128IFS = NULL;;
char *local47IFS = NULL;;
char *rule76_FREE = NULL;;
char *rule17_FREE = NULL;;
char *rule3_FREE = NULL;;
char *r_REJECT_TCP_NOLOG1 = NULL;;
char *show_if_ip17_FREE = NULL;;
char *local92IFS = NULL;;
char *strtok3_FREE = NULL;;
char *strtok101_FREE = NULL;;
char *rule85_FREE = NULL;;
char *rule26_FREE = NULL;;
char *host = NULL;;
char *local129IFS = NULL;;
char *local12IFS = NULL;;
char *strtok89_FREE = NULL;;
char *strtok110_FREE = NULL;;
char *hosts9_FREE = NULL;;
char *rule94_FREE = NULL;;
char *rule35_FREE = NULL;;
char *strtok72_FREE = NULL;;
char *strtok98_FREE = NULL;;
char *local97IFS = NULL;;
char *local93IFS = NULL;;
char *protos = NULL;;
char *strtok39_FREE = NULL;;
char *rule7_FREE = NULL;;
char *rule44_FREE = NULL;;
char *local17IFS = NULL;;
char *local13IFS = NULL;;
char *strtok22_FREE = NULL;;
char *strtok81_FREE = NULL;;
char *strtok105_FREE = NULL;;
char *hosts1_FREE = NULL;;
char *hosts11_FREE = NULL;;
char *r_hosts7_FREE1 = NULL;;
char *strtok90_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *local98IFS = NULL;;
char *local94IFS = NULL;;
char *local90IFS = NULL;;
char *r_HOST_REJECT_UDP1 = NULL;;
char *strtok114_FREE = NULL;;
char *rule39_FREE = NULL;;
char *local10IFS = NULL;;
char *local18IFS = NULL;;
char *local14IFS = NULL;;
char *show_if_ip13_FREE = NULL;;
char *strtok40_FREE = NULL;;
char *strtok123_FREE = NULL;;
char *rule48_FREE = NULL;;
char *proto = NULL;;
char *show_if_ip22_FREE = NULL;;
char *local99IFS = NULL;;
char *local95IFS = NULL;;
char *strtok109_FREE = NULL;;
char *r_EXTERNAL_NET1 = NULL;;
char *r_EXTERNAL_NET2 = NULL;;
char *r_EXTERNAL_NET3 = NULL;;
char *local11IFS = NULL;;
char *local19IFS = NULL;;
char *local15IFS = NULL;;
char *rule57_FREE = NULL;;
char *strtok94_FREE = NULL;;
char *strtok35_FREE = NULL;;
char *show_if_ip1_FREE = NULL;;
char *r_destips20 = NULL;;
char *strtok118_FREE = NULL;;
char *r_destips21 = NULL;;
char *r_destips22 = NULL;;
char *r_destips23 = NULL;;
char *rule40_FREE = NULL;;
char *r_destips24 = NULL;;
char *r_destips25 = NULL;;
char *local60IFS = NULL;;
char *r_destips26 = NULL;;
char *r_destips27 = NULL;;
char *r_destips28 = NULL;;
char *local96IFS = NULL;;
char *rule66_FREE = NULL;;
char *strtok44_FREE = NULL;;
char *awk1_FREE = NULL;;
char *strtok127_FREE = NULL;;
char *local16IFS = NULL;;
char *r_hosts15_FREE1 = NULL;;
char *show_if_ip26_FREE = NULL;;
char *strtok53_FREE = NULL;;
char *r_OPEN_UDP1 = NULL;;
char *local65IFS = NULL;;
char *local61IFS = NULL;;
char *r_hosts10_FREE1 = NULL;;
char *show_if_ip5_FREE = NULL;;
char *strtok62_FREE = NULL;;
char *r_interfaces20 = NULL;;
char *r_interfaces21 = NULL;;
char *r_interfaces22 = NULL;;
char *r_interfaces23 = NULL;;
char *r_interfaces24 = NULL;;
char *r_interfaces25 = NULL;;
char *r_interfaces26 = NULL;;
char *r_interfaces27 = NULL;;
char *strtok48_FREE = NULL;;
char *r_interfaces28 = NULL;;
char *local66IFS = NULL;;
char *local62IFS = NULL;;
char *rule53_FREE = NULL;;
char *r_DENY_TCP1 = NULL;;
char *rule79_FREE = NULL;;
char *strtok57_FREE = NULL;;
char *rule62_FREE = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *show_if_ip9_FREE = NULL;;
char *strtok66_FREE = NULL;;
char *local63IFS = NULL;;
char *local67IFS = NULL;;
char *r_HOST_DENY_IP1 = NULL;;
char *rule71_FREE = NULL;;
char *rule12_FREE = NULL;;
char *net = NULL;;
char *strtok16_FREE = NULL;;
char *strtok75_FREE = NULL;;
char *rule80_FREE = NULL;;
char *rule21_FREE = NULL;;
char *r_HOST_DENY_UDP_NOLOG1 = NULL;;
char *local64IFS = NULL;;
char *local68IFS = NULL;;
char *strtok25_FREE = NULL;;
char *hosts4_FREE = NULL;;
char *rule30_FREE = NULL;;
char *r_HOST_OPEN_TCP1 = NULL;;
char *local110IFS = NULL;;
char *rule75_FREE = NULL;;
char *rule16_FREE = NULL;;
char *rule2_FREE = NULL;;
char *r_hosts14_FREE1 = NULL;;
char *local69IFS = NULL;;
char *strtok79_FREE = NULL;;
char *show_if_ip16_FREE = NULL;;
char *strtok2_FREE = NULL;;
char *strtok100_FREE = NULL;;
char *rule84_FREE = NULL;;
char *rule25_FREE = NULL;;
char *local111IFS = NULL;;
char *strtok29_FREE = NULL;;
char *strtok88_FREE = NULL;;
char *local30IFS = NULL;;
char *local34IFS = NULL;;
char *hosts8_FREE = NULL;;
char *rule93_FREE = NULL;;
char *rule34_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *strtok71_FREE = NULL;;
char *strtok97_FREE = NULL;;
char *strtok38_FREE = NULL;;
char *rule6_FREE = NULL;;
char *rule43_FREE = NULL;;
char *r_hosts6_FREE1 = NULL;;
char *strtok21_FREE = NULL;;
char *strtok80_FREE = NULL;;
char *local116IFS = NULL;;
char *local112IFS = NULL;;
char *strtok6_FREE = NULL;;
char *strtok104_FREE = NULL;;
char *rule88_FREE = NULL;;
char *local31IFS = NULL;;
char *rule29_FREE = NULL;;
char *local35IFS = NULL;;
char *hosts10_FREE = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *strtok30_FREE = NULL;;
char *interfaces = NULL;;
char *strtok113_FREE = NULL;;
char *rule97_FREE = NULL;;
char *rule38_FREE = NULL;;
char *r_protos1 = NULL;;
char *r_protos2 = NULL;;
char *r_protos3 = NULL;;
char *r_protos4 = NULL;;
char *show_if_ip12_FREE = NULL;;
char *local117IFS = NULL;;
char *local113IFS = NULL;;
char *local32IFS = NULL;;
char *local36IFS = NULL;;
char *strtok122_FREE = NULL;;
char *rule47_FREE = NULL;;
char *strtok84_FREE = NULL;;
char *show_if_ip21_FREE = NULL;;
char *strtok108_FREE = NULL;;
char *hosts14_FREE = NULL;;
char *local118IFS = NULL;;
char *local114IFS = NULL;;
char *rule56_FREE = NULL;;
char *strtok93_FREE = NULL;;
char *strtok34_FREE = NULL;;
char *local33IFS = NULL;;
char *local37IFS = NULL;;
char *strtok117_FREE = NULL;;
char *r_HOST_REJECT_UDP_NOLOG1 = NULL;;
char *r_REJECT_UDP1 = NULL;;
char *strtok43_FREE = NULL;;
char *strtok126_FREE = NULL;;
char *local119IFS = NULL;;
char *local115IFS = NULL;;
char *show_if_ip25_FREE = NULL;;
char *local38IFS = NULL;;
char *strtok52_FREE = NULL;;
char *r_HOST_DENY_TCP_NOLOG1 = NULL;;
char *show_if_ip4_FREE = NULL;;
char *local83IFS = NULL;;
char *strtok61_FREE = NULL;;
char *rule69_FREE = NULL;;
char *strtok47_FREE = NULL;;
char *local39IFS = NULL;;
char *local3IFS = NULL;;
char *rule52_FREE = NULL;;
char *rule78_FREE = NULL;;
char *rule19_FREE = NULL;;
char *local80IFS = NULL;;
char *local88IFS = NULL;;
char *local84IFS = NULL;;
char *strtok56_FREE = NULL;;
char *r_HOST_OPEN_ICMP1 = NULL;;
char *rule61_FREE = NULL;;
char *show_if_ip8_FREE = NULL;;
char *local4IFS = NULL;;
char *strtok65_FREE = NULL;;
char *rule11_FREE = NULL;;
char *rule70_FREE = NULL;;
char *local89IFS = NULL;;
char *local85IFS = NULL;;
char *local81IFS = NULL;;
char *strtok15_FREE = NULL;;
char *strtok74_FREE = NULL;;
char *hosts = NULL;;
char *rule20_FREE = NULL;;
char *local1IFS = NULL;;
char *local9IFS = NULL;;
char *local5IFS = NULL;;
char *r_HOST_REJECT_TCP1 = NULL;;
char *rule65_FREE = NULL;;
char *strtok9_FREE = NULL;;
char *local86IFS = NULL;;
char *local82IFS = NULL;;
char *hosts3_FREE = NULL;;
char *r_hosts13_FREE1 = NULL;;
char *strtok69_FREE = NULL;;
char *rule74_FREE = NULL;;
char *rule15_FREE = NULL;;
char *rule1_FREE = NULL;;
char *local2IFS = NULL;;
char *local6IFS = NULL;;
char *strtok19_FREE = NULL;;
char *strtok78_FREE = NULL;;
char *local51IFS = NULL;;
char *destip = NULL;;
char *strtok1_FREE = NULL;;
char *local87IFS = NULL;;
char *rule83_FREE = NULL;;
char *rule24_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *strtok87_FREE = NULL;;
char *local7IFS = NULL;;
char *hosts7_FREE = NULL;;
char *rule92_FREE = NULL;;
char *hosts17_FREE = NULL;;
char *rule33_FREE = NULL;;
char *r_hosts5_FREE1 = NULL;;
char *strtok11_FREE = NULL;;
char *strtok70_FREE = NULL;;
char *local52IFS = NULL;;
char *strtok96_FREE = NULL;;
char *strtok37_FREE = NULL;;
char *rule5_FREE = NULL;;
char *interface = NULL;;
char *address = NULL;;
char *rule42_FREE = NULL;;
char *strtok20_FREE = NULL;;
char *show_if_ip19_FREE = NULL;;
char *r_OPEN_TCP1 = NULL;;
char *strtok5_FREE = NULL;;
char *strtok103_FREE = NULL;;
char *rule87_FREE = NULL;;
char *rule28_FREE = NULL;;
char *local8IFS = NULL;;
char *r_destips1 = NULL;;
char *r_destips2 = NULL;;
char *r_destips3 = NULL;;
char *r_destips4 = NULL;;
char *r_destips5 = NULL;;
char *local53IFS = NULL;;
char *r_destips6 = NULL;;
char *local57IFS = NULL;;
char *r_destips7 = NULL;;
char *show_if_ip28_FREE = NULL;;
char *r_destips8 = NULL;;
char *r_destips9 = NULL;;
char *r_DENY_UDP_NOLOG1 = NULL;;
char *strtok112_FREE = NULL;;
char *rule96_FREE = NULL;;
char *rule37_FREE = NULL;;
char *show_if_ip11_FREE = NULL;;
char *rule9_FREE = NULL;;
char *rule46_FREE = NULL;;
char *strtok24_FREE = NULL;;
char *strtok83_FREE = NULL;;
char *local54IFS = NULL;;
char *local50IFS = NULL;;
char *local58IFS = NULL;;
char *show_if_ip20_FREE = NULL;;
char *strtok107_FREE = NULL;;
char *destips = NULL;;
char *hosts13_FREE = NULL;;
char *rule55_FREE = NULL;;
char *strtok92_FREE = NULL;;
char *strtok33_FREE = NULL;;
char *r_HOST_DENY_UDP1 = NULL;;
char *strtok116_FREE = NULL;;
char *show_if_ip15_FREE = NULL;;
char *local55IFS = NULL;;
char *local59IFS = NULL;;
char *strtok42_FREE = NULL;;
char *strtok125_FREE = NULL;;
char *show_if_ip24_FREE = NULL;;
char *strtok51_FREE = NULL;;
char *local20IFS = NULL;;
char *rule59_FREE = NULL;;
char *local56IFS = NULL;;
char *r_HOST_REJECT_TCP_NOLOG1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_ports1 = NULL;;
char *r_ports2 = NULL;;
char *r_ports3 = NULL;;
char *r_ports4 = NULL;;
char *r_ports5 = NULL;;
char *r_ports6 = NULL;;
char *r_ports7 = NULL;;
char *r_ports8 = NULL;;
char *r_ports9 = NULL;;
char *r_HOST_DENY_ICMP_NOLOG1 = NULL;;
char *rule68_FREE = NULL;;
char *local102IFS = NULL;;
char *strtok46_FREE = NULL;;
char *awk3_FREE = NULL;;
char *local21IFS = NULL;;
char *strtok129_FREE = NULL;;
char *rule51_FREE = NULL;;
char *rule18_FREE = NULL;;
char *strtok55_FREE = NULL;;
char *rule60_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *local107IFS = NULL;;
char *local103IFS = NULL;;
char *strtok121_FREE = NULL;;
char *local22IFS = NULL;;
char *strtok64_FREE = NULL;;
char *local26IFS = NULL;;
char *r_hosts17_FREE1 = NULL;;
char *rule10_FREE = NULL;;
char *strtok14_FREE = NULL;;
char *strtok73_FREE = NULL;;
char *local108IFS = NULL;;
char *local104IFS = NULL;;
char *local100IFS = NULL;;
char *r_hosts12_FREE1 = NULL;;
char *strtok59_FREE = NULL;;
char *local27IFS = NULL;;
char *local23IFS = NULL;;
char *rule64_FREE = NULL;;
char *strtok8_FREE = NULL;;
char *strtok68_FREE = NULL;;
char *local109IFS = NULL;;
char *local105IFS = NULL;;
char *local101IFS = NULL;;
char *rule73_FREE = NULL;;
char *r_ports10 = NULL;;
char *rule14_FREE = NULL;;
char *r_hosts9_FREE1 = NULL;;
char *r_ports11 = NULL;;
char *r_ports12 = NULL;;
char *r_ports13 = NULL;;
char *r_ports14 = NULL;;
char *r_ports15 = NULL;;
char *local28IFS = NULL;;
char *local24IFS = NULL;;
char *r_ports16 = NULL;;
char *r_ports17 = NULL;;
char *r_ports18 = NULL;;
char *strtok18_FREE = NULL;;
char *strtok77_FREE = NULL;;
char *r_ports19 = NULL;;
char *r_FULL_ACCESS_HOSTS1 = NULL;;
char *rule82_FREE = NULL;;
char *rule23_FREE = NULL;;
char *r_hosts4_FREE1 = NULL;;
char *strtok60_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *strtok86_FREE = NULL;;
char *local106IFS = NULL;;
char *hosts6_FREE = NULL;;
char *rule91_FREE = NULL;;
char *local29IFS = NULL;;
char *rule32_FREE = NULL;;
char *hosts16_FREE = NULL;;
char *local25IFS = NULL;;
char *r_REJECT_TCP1 = NULL;;
char *strtok10_FREE = NULL;;
char *r_HOST_DENY_ICMP1 = NULL;;
char *ports = NULL;;
char *rule77_FREE = NULL;;
char *rule4_FREE = NULL;;
char *local74IFS = NULL;;
char *local70IFS = NULL;;
char *show_if_ip18_FREE = NULL;;
char *strtok4_FREE = NULL;;
char *strtok102_FREE = NULL;;
char *rule86_FREE = NULL;;
char *rule27_FREE = NULL;;
char *r_DENY_UDP1 = NULL;;
char *strtok111_FREE = NULL;;
char *rule95_FREE = NULL;;
char *local75IFS = NULL;;
char *rule36_FREE = NULL;;
char *local71IFS = NULL;;
char *local79IFS = NULL;;
char *r_EXT_NET_BCAST_ADDRESS1 = NULL;;
char *show_if_ip10_FREE = NULL;;
char *strtok99_FREE = NULL;;
char *rule8_FREE = NULL;;
char *r_interfaces1 = NULL;;
char *r_interfaces2 = NULL;;
char *rule45_FREE = NULL;;
char *r_interfaces3 = NULL;;
char *r_HOST_OPEN_IP1 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok23_FREE = NULL;;
char *strtok82_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *r_interfaces7 = NULL;;
char *r_OPEN_IP1 = NULL;;
char *r_interfaces8 = NULL;;
char *r_interfaces9 = NULL;;
char *strtok106_FREE = NULL;;
char *strtok49_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *hosts12_FREE = NULL;;
char *local76IFS = NULL;;
char *local72IFS = NULL;;
char *r_DENY_TCP_NOLOG1 = NULL;;
char *rule54_FREE = NULL;;
char *strtok91_FREE = NULL;;
char *strtok32_FREE = NULL;;
char *strtok115_FREE = NULL;;
char *show_if_ip14_FREE = NULL;;
char *strtok41_FREE = NULL;;
char *r_REJECT_UDP_NOLOG1 = NULL;;
char *r_HOST_OPEN_UDP1 = NULL;;
char *local77IFS = NULL;;
char *local73IFS = NULL;;
char *strtok124_FREE = NULL;;
char *rule49_FREE = NULL;;
char *show_if_ip23_FREE = NULL;;
char *strtok50_FREE = NULL;;
char *r_destips10 = NULL;;
char *r_destips11 = NULL;;
char *r_destips12 = NULL;;
char *r_destips13 = NULL;;
char *rule58_FREE = NULL;;
char *r_destips14 = NULL;;

  //## Log scanning of port 0 fingerprinting
  //########################################
  //if [ "$SCAN_LOG" != "0" ]; then
  if  (  (strcmp(SCAN_LOG,"0")!=0)  )
  {
    //iptables -A EXT_INPUT_CHAIN -p tcp --dport 0  -m limit --limit 6/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Port 0 OS fingerprint: "
    iptables("-A EXT_INPUT_CHAIN -p tcp --dport 0  -m limit --limit 6/h --limit-burst 1 -j LOG --log-prefix \"AIF:Port 0 OS fingerprint: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_INPUT_CHAIN -p udp --dport 0  -m limit --limit 6/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Port 0 OS fingerprint: "
    iptables("-A EXT_INPUT_CHAIN -p udp --dport 0  -m limit --limit 6/h --limit-burst 1 -j LOG --log-prefix \"AIF:Port 0 OS fingerprint: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop port 0 scan packets
  //##########################
  //iptables -A EXT_INPUT_CHAIN -p tcp --dport 0 -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p tcp --dport 0 -j POST_INPUT_DROP_CHAIN");
  //iptables -A EXT_INPUT_CHAIN -p udp --dport 0 -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p udp --dport 0 -j POST_INPUT_DROP_CHAIN");

  //## Log scanning of source port 0
  //################################
  //if [ "$SCAN_LOG" != "0" ]; then
  if  (  (strcmp(SCAN_LOG,"0")!=0)  )
  {
    //iptables -A EXT_INPUT_CHAIN -p tcp --sport 0  -m limit --limit 6/h --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:TCP source port 0: "
    iptables("-A EXT_INPUT_CHAIN -p tcp --sport 0  -m limit --limit 6/h --limit-burst 5 -j LOG --log-prefix \"AIF:TCP source port 0: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_INPUT_CHAIN -p udp --sport 0  -m limit --limit 6/h --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UDP source port 0: "
    iptables("-A EXT_INPUT_CHAIN -p udp --sport 0  -m limit --limit 6/h --limit-burst 5 -j LOG --log-prefix \"AIF:UDP source port 0: \" --log-level %s", LOGLEVEL);
  //fi
  }

  //# Drop source port 0 packets
  //############################
  //iptables -A EXT_INPUT_CHAIN -p tcp --sport 0 -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p tcp --sport 0 -j POST_INPUT_DROP_CHAIN");
  //iptables -A EXT_INPUT_CHAIN -p udp --sport 0 -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p udp --sport 0 -j POST_INPUT_DROP_CHAIN");

  //# Here we add support for DHCP assigned IP
  //##########################################
  //if [ "$EXT_IF_DHCP_IP" = "1" ]; then
  if  (  (strcmp(EXT_IF_DHCP_IP,"1")==0)  )
  {
    //echo " Enabling support for DHCP-assigned-IP (DHCP client)"
    printf(" Enabling support for DHCP-assigned-IP (DHCP client)" "\n");
    //# Allow this host to be an DHCP client:
    //ip4tables -A EXT_INPUT_CHAIN -p udp --sport 67 --dport 68 -j ACCEPT
    ip4tables("-A EXT_INPUT_CHAIN -p udp --sport 67 --dport 68 -j ACCEPT");
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //# Allow this host to be an DHCPv6 client:
      //ip6tables -A EXT_INPUT_CHAIN -p udp --sport 547 --dport 546 -j ACCEPT
      ip6tables("-A EXT_INPUT_CHAIN -p udp --sport 547 --dport 546 -j ACCEPT");
    //fi
    }
  //fi
  }

  //# Support for a DHCP/BootP service on the EXTERNAL interface
  //############################################################
  //if [ "$EXTERNAL_DHCP_SERVER" = "1" ]; then
  if  (  (strcmp(EXTERNAL_DHCP_SERVER,"1")==0)  )
  {
    //echo " Enabling support for DHCP/BOOTP (DHCP server) for subnet(s): $EXTERNAL_NET"
    printf(" Enabling support for DHCP/BOOTP (DHCP server) for subnet(s): %s" "\n", EXTERNAL_NET);
    //IFS=' ,'
    IFS=" ,";
    //for net in $EXTERNAL_NET; do
    local1IFS = IFS;
    if (EXTERNAL_NET != NULL) strtok1_FREE = strdup(EXTERNAL_NET);
    if (EXTERNAL_NET != NULL) for (net = strtok_r(strtok1_FREE, local1IFS, &r_EXTERNAL_NET1); net != NULL; net = strtok_r(NULL, local1IFS, &r_EXTERNAL_NET1))
    {
      //# Allow this host to be a DHCP/BOOTP-server:
      //ip4tables -A EXT_INPUT_CHAIN -d 255.255.255.255 -p udp --dport 67 -j ACCEPT
      ip4tables("-A EXT_INPUT_CHAIN -d 255.255.255.255 -p udp --dport 67 -j ACCEPT");
      //ip4tables -A EXT_INPUT_CHAIN -s $net -p udp --dport 67 -j ACCEPT
      ip4tables("-A EXT_INPUT_CHAIN -s %s -p udp --dport 67 -j ACCEPT", net);
//#      ip4tables -A EXT_INPUT_CHAIN -d 255.255.255.255 -p udp --sport 68 --dport 67 -j ACCEPT
//#      ip4tables -A EXT_INPUT_CHAIN -s $net -p udp --sport 68 --dport 67 -j ACCEPT

      //# Extra rules to allow packets from other dhcp servers in the same segment
      //ip4tables -A EXT_INPUT_CHAIN -s $net -d 255.255.255.255 -p udp --sport 67 --dport 68 -j ACCEPT
      ip4tables("-A EXT_INPUT_CHAIN -s %s -d 255.255.255.255 -p udp --sport 67 --dport 68 -j ACCEPT", net);
    //done
    }
  //fi
  }

  //# Support for a DHCPv6 service on the EXTERNAL interface
  //########################################################
  //if [ "$IPV6_SUPPORT" = "1" -a "$EXTERNAL_DHCPV6_SERVER" = "1" ]; then
  if  (  ((strcmp(IPV6_SUPPORT,"1")==0)&&(strcmp(EXTERNAL_DHCPV6_SERVER,"1")==0)) )
  {
    //echo " Enabling support for DHCPv6 server on external interface(s)"
    printf(" Enabling support for DHCPv6 server on external interface(s)" "\n");
    //# Allow only Link-Local clients
    //ip6tables -A EXT_INPUT_CHAIN -s fe80::/10 -p udp --dport 547 -j ACCEPT
    ip6tables("-A EXT_INPUT_CHAIN -s fe80::/10 -p udp --dport 547 -j ACCEPT");
    //# Additionally, multicast packets in EXT_MULTICAST_CHAIN must be handled
  //fi
  }

  //# This is the fix(hack) for nmb broadcast packets (nmblookup/Samba)
  //###################################################################
  //if [ "$NMB_BROADCAST_FIX" = "1" ]; then
  if  (  (strcmp(NMB_BROADCAST_FIX,"1")==0)  )
  {
    //echo " Enabling support for NMB-broadcasts(Samba) for subnet(s): $EXTERNAL_NET"
    printf(" Enabling support for NMB-broadcasts(Samba) for subnet(s): %s" "\n", EXTERNAL_NET);
    //IFS=' ,'
    IFS=" ,";
    //for net in $EXTERNAL_NET; do
    local2IFS = IFS;
    if (EXTERNAL_NET != NULL) strtok2_FREE = strdup(EXTERNAL_NET);
    if (EXTERNAL_NET != NULL) for (net = strtok_r(strtok2_FREE, local2IFS, &r_EXTERNAL_NET2); net != NULL; net = strtok_r(NULL, local2IFS, &r_EXTERNAL_NET2))
    {
      //ip4tables -A EXT_INPUT_CHAIN -s $net -p udp --sport 137 --dport "$LOCAL_PORT_RANGE" -j ACCEPT
      ip4tables("-A EXT_INPUT_CHAIN -s %s -p udp --sport 137 --dport \"%s\" -j ACCEPT", net, LOCAL_PORT_RANGE);
    //done
    }
  //fi
  }

  //# Enable logging of blocked hosts?
  //##################################
  //if [ "$BLOCKED_HOST_LOG" != "0" ]; then
  if  (  (strcmp(BLOCKED_HOST_LOG,"0")!=0)  )
  {
    //echo " Logging of explicitly blocked hosts enabled"
    printf(" Logging of explicitly blocked hosts enabled" "\n");
  //else
  }
  else
  {
    //echo " Logging of explicitly blocked hosts disabled"
    printf(" Logging of explicitly blocked hosts disabled" "\n");
  //fi
  }

  //# Enable logging of denied output connections?
  //##############################################
  //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
  if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
  {
    //echo " Logging of denied local output connections enabled"
    printf(" Logging of denied local output connections enabled" "\n");
  //else
  }
  else
  {
    //echo " Logging of denied local output connections disabled"
    printf(" Logging of denied local output connections disabled" "\n");
  //fi
  }

  //# Add TCP ports to allow for certain hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_OPEN_TCP; do
  local3IFS = IFS;
  if (HOST_OPEN_TCP != NULL) strtok3_FREE = strdup(HOST_OPEN_TCP);
  if (HOST_OPEN_TCP != NULL) for (rule = strtok_r(strtok3_FREE, local3IFS, &r_HOST_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local3IFS, &r_HOST_OPEN_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule1_FREE = get_ifs(rule, NULL);
    interfaces=rule1_FREE;;
    //destips=`get_ips "$rule"`
    rule2_FREE = get_ips(rule, NULL);
    destips=rule2_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule3_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule3_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule4_FREE = get_ports_ihp(rule, NULL);
    ports=rule4_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing $hosts for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing %s for TCP port(s): %s;" "\n", show_if_ip1_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local4IFS = IFS;
    if (hosts1_FREE != NULL) strtok4_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok4_FREE, local4IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local4IFS, &r_hosts1_FREE1))
    {
      //for port in $ports; do
      local5IFS = IFS;
      if (ports != NULL) strtok5_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok5_FREE, local5IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local5IFS, &r_ports1))
      {
        //for destip in $destips; do
        local6IFS = IFS;
        if (destips != NULL) strtok6_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok6_FREE, local6IFS, &r_destips1); destip != NULL; destip = strtok_r(NULL, local6IFS, &r_destips1))
        {
          //for interface in $interfaces; do
          local7IFS = IFS;
          if (interfaces != NULL) strtok7_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok7_FREE, local7IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local7IFS, &r_interfaces1))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port -j ACCEPT
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j ACCEPT", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add UDP ports to allow for certain hosts
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_OPEN_UDP; do
  local8IFS = IFS;
  if (HOST_OPEN_UDP != NULL) strtok8_FREE = strdup(HOST_OPEN_UDP);
  if (HOST_OPEN_UDP != NULL) for (rule = strtok_r(strtok8_FREE, local8IFS, &r_HOST_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local8IFS, &r_HOST_OPEN_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule5_FREE = get_ifs(rule, NULL);
    interfaces=rule5_FREE;;
    //destips=`get_ips "$rule"`
    rule6_FREE = get_ips(rule, NULL);
    destips=rule6_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule7_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule7_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule8_FREE = get_ports_ihp(rule, NULL);
    ports=rule8_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing $hosts for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing %s for UDP port(s): %s;" "\n", show_if_ip2_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local9IFS = IFS;
    if (hosts2_FREE != NULL) strtok9_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok9_FREE, local9IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local9IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local10IFS = IFS;
      if (ports != NULL) strtok10_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok10_FREE, local10IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local10IFS, &r_ports2))
      {
        //for destip in $destips; do
        local11IFS = IFS;
        if (destips != NULL) strtok11_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok11_FREE, local11IFS, &r_destips2); destip != NULL; destip = strtok_r(NULL, local11IFS, &r_destips2))
        {
          //for interface in $interfaces; do
          local12IFS = IFS;
          if (interfaces != NULL) strtok12_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok12_FREE, local12IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local12IFS, &r_interfaces2))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port -j ACCEPT
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s -j ACCEPT", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add IP protocols to allow for certain hosts
  //#############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_OPEN_IP; do
  local13IFS = IFS;
  if (HOST_OPEN_IP != NULL) strtok13_FREE = strdup(HOST_OPEN_IP);
  if (HOST_OPEN_IP != NULL) for (rule = strtok_r(strtok13_FREE, local13IFS, &r_HOST_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local13IFS, &r_HOST_OPEN_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule9_FREE = get_ifs(rule, NULL);
    interfaces=rule9_FREE;;
    //destips=`get_ips "$rule"`
    rule10_FREE = get_ips(rule, NULL);
    destips=rule10_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule11_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule11_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule12_FREE = get_ports_ihp(rule, NULL);
    protos=rule12_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing $hosts for IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing %s for IP protocol(s): %s;" "\n", show_if_ip3_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local14IFS = IFS;
    if (hosts3_FREE != NULL) strtok14_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok14_FREE, local14IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local14IFS, &r_hosts3_FREE1))
    {
      //IFS=','
      IFS=",";
      //for proto in $protos; do
      local15IFS = IFS;
      if (protos != NULL) strtok15_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok15_FREE, local15IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local15IFS, &r_protos1))
      {
        //for destip in $destips; do
        local16IFS = IFS;
        if (destips != NULL) strtok16_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok16_FREE, local16IFS, &r_destips3); destip != NULL; destip = strtok_r(NULL, local16IFS, &r_destips3))
        {
          //for interface in $interfaces; do
          local17IFS = IFS;
          if (interfaces != NULL) strtok17_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok17_FREE, local17IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local17IFS, &r_interfaces3))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p $proto -j ACCEPT
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p %s -j ACCEPT", interface, host, destip, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add ICMP to allow for certain hosts
  //#####################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_OPEN_ICMP; do
  local18IFS = IFS;
  if (HOST_OPEN_ICMP != NULL) strtok18_FREE = strdup(HOST_OPEN_ICMP);
  if (HOST_OPEN_ICMP != NULL) for (rule = strtok_r(strtok18_FREE, local18IFS, &r_HOST_OPEN_ICMP1); rule != NULL; rule = strtok_r(NULL, local18IFS, &r_HOST_OPEN_ICMP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //destips=`get_ips "$rule"`
    rule14_FREE = get_ips(rule, NULL);
    destips=rule14_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule15_FREE = get_hosts_ih(rule, NULL);
    hosts=rule15_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing $hosts for ICMP-requests(ping)"
    show_if_ip4_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing %s for ICMP-requests(ping);" "\n", show_if_ip4_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts4_FREE = ip_range(hosts, NULL);
    local19IFS = IFS;
    if (hosts4_FREE != NULL) strtok19_FREE = strdup(hosts4_FREE);
    if (hosts4_FREE != NULL) for (host = strtok_r(strtok19_FREE, local19IFS, &r_hosts4_FREE1); host != NULL; host = strtok_r(NULL, local19IFS, &r_hosts4_FREE1))
    {
      //for destip in $destips; do
      local20IFS = IFS;
      if (destips != NULL) strtok20_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok20_FREE, local20IFS, &r_destips4); destip != NULL; destip = strtok_r(NULL, local20IFS, &r_destips4))
      {
        //for interface in $interfaces; do
        local21IFS = IFS;
        if (interfaces != NULL) strtok21_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok21_FREE, local21IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local21IFS, &r_interfaces4))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p icmp --icmp-type echo-request -j ACCEPT
          iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p icmp --icmp-type echo-request -j ACCEPT", interface, host, destip);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add TCP ports to REJECT for certain hosts but NOT logged
  //##########################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_REJECT_TCP_NOLOG; do
  local22IFS = IFS;
  if (HOST_REJECT_TCP_NOLOG != NULL) strtok22_FREE = strdup(HOST_REJECT_TCP_NOLOG);
  if (HOST_REJECT_TCP_NOLOG != NULL) for (rule = strtok_r(strtok22_FREE, local22IFS, &r_HOST_REJECT_TCP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local22IFS, &r_HOST_REJECT_TCP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule16_FREE = get_ifs(rule, NULL);
    interfaces=rule16_FREE;;
    //destips=`get_ips "$rule"`
    rule17_FREE = get_ips(rule, NULL);
    destips=rule17_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule18_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule18_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule19_FREE = get_ports_ihp(rule, NULL);
    ports=rule19_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting $hosts for TCP port(s) (NO LOG): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting %s for TCP port(s) (NO LOG): %s;" "\n", show_if_ip5_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts5_FREE = ip_range(hosts, NULL);
    local23IFS = IFS;
    if (hosts5_FREE != NULL) strtok23_FREE = strdup(hosts5_FREE);
    if (hosts5_FREE != NULL) for (host = strtok_r(strtok23_FREE, local23IFS, &r_hosts5_FREE1); host != NULL; host = strtok_r(NULL, local23IFS, &r_hosts5_FREE1))
    {
      //for port in $ports; do
      local24IFS = IFS;
      if (ports != NULL) strtok24_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports3))
      {
        //for destip in $destips; do
        local25IFS = IFS;
        if (destips != NULL) strtok25_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok25_FREE, local25IFS, &r_destips5); destip != NULL; destip = strtok_r(NULL, local25IFS, &r_destips5))
        {
          //for interface in $interfaces; do
          local26IFS = IFS;
          if (interfaces != NULL) strtok26_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok26_FREE, local26IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local26IFS, &r_interfaces5))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port -j REJECT --reject-with tcp-reset
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j REJECT --reject-with tcp-reset", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add UDP ports to REJECT for certain hosts NOT logged
  //######################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_REJECT_UDP_NOLOG; do
  local27IFS = IFS;
  if (HOST_REJECT_UDP_NOLOG != NULL) strtok27_FREE = strdup(HOST_REJECT_UDP_NOLOG);
  if (HOST_REJECT_UDP_NOLOG != NULL) for (rule = strtok_r(strtok27_FREE, local27IFS, &r_HOST_REJECT_UDP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local27IFS, &r_HOST_REJECT_UDP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule20_FREE = get_ifs(rule, NULL);
    interfaces=rule20_FREE;;
    //destips=`get_ips "$rule"`
    rule21_FREE = get_ips(rule, NULL);
    destips=rule21_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule22_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule22_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule23_FREE = get_ports_ihp(rule, NULL);
    ports=rule23_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting $hosts for UDP port(s) (NO LOG): $ports"
    show_if_ip6_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting %s for UDP port(s) (NO LOG): %s;" "\n", show_if_ip6_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts6_FREE = ip_range(hosts, NULL);
    local28IFS = IFS;
    if (hosts6_FREE != NULL) strtok28_FREE = strdup(hosts6_FREE);
    if (hosts6_FREE != NULL) for (host = strtok_r(strtok28_FREE, local28IFS, &r_hosts6_FREE1); host != NULL; host = strtok_r(NULL, local28IFS, &r_hosts6_FREE1))
    {
      //for port in $ports; do
      local29IFS = IFS;
      if (ports != NULL) strtok29_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok29_FREE, local29IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local29IFS, &r_ports4))
      {
        //for destip in $destips; do
        local30IFS = IFS;
        if (destips != NULL) strtok30_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok30_FREE, local30IFS, &r_destips6); destip != NULL; destip = strtok_r(NULL, local30IFS, &r_destips6))
        {
          //for interface in $interfaces; do
          local31IFS = IFS;
          if (interfaces != NULL) strtok31_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok31_FREE, local31IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local31IFS, &r_interfaces6))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port -j REJECT --reject-with icmp-host-unreachable
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s -j REJECT --reject-with icmp-host-unreachable", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add TCP ports to REJECT for certain hosts
  //###########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_REJECT_TCP; do
  local32IFS = IFS;
  if (HOST_REJECT_TCP != NULL) strtok32_FREE = strdup(HOST_REJECT_TCP);
  if (HOST_REJECT_TCP != NULL) for (rule = strtok_r(strtok32_FREE, local32IFS, &r_HOST_REJECT_TCP1); rule != NULL; rule = strtok_r(NULL, local32IFS, &r_HOST_REJECT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule24_FREE = get_ifs(rule, NULL);
    interfaces=rule24_FREE;;
    //destips=`get_ips "$rule"`
    rule25_FREE = get_ips(rule, NULL);
    destips=rule25_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule26_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule26_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule27_FREE = get_ports_ihp(rule, NULL);
    ports=rule27_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting $hosts for TCP port(s): $ports"
    show_if_ip7_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting %s for TCP port(s): %s;" "\n", show_if_ip7_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts7_FREE = ip_range(hosts, NULL);
    local33IFS = IFS;
    if (hosts7_FREE != NULL) strtok33_FREE = strdup(hosts7_FREE);
    if (hosts7_FREE != NULL) for (host = strtok_r(strtok33_FREE, local33IFS, &r_hosts7_FREE1); host != NULL; host = strtok_r(NULL, local33IFS, &r_hosts7_FREE1))
    {
      //for port in $ports; do
      local34IFS = IFS;
      if (ports != NULL) strtok34_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok34_FREE, local34IFS, &r_ports5); port != NULL; port = strtok_r(NULL, local34IFS, &r_ports5))
      {
        //for destip in $destips; do
        local35IFS = IFS;
        if (destips != NULL) strtok35_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok35_FREE, local35IFS, &r_destips7); destip != NULL; destip = strtok_r(NULL, local35IFS, &r_destips7))
        {
          //for interface in $interfaces; do
          local36IFS = IFS;
          if (interfaces != NULL) strtok36_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok36_FREE, local36IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local36IFS, &r_interfaces7))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise TCP rejected: "
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Hostwise TCP rejected: \" --log-level %s", interface, host, destip, port, LOGLEVEL);

            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port -j REJECT --reject-with tcp-reset
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j REJECT --reject-with tcp-reset", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add UDP ports to REJECT for certain hosts
  //###########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_REJECT_UDP; do
  local37IFS = IFS;
  if (HOST_REJECT_UDP != NULL) strtok37_FREE = strdup(HOST_REJECT_UDP);
  if (HOST_REJECT_UDP != NULL) for (rule = strtok_r(strtok37_FREE, local37IFS, &r_HOST_REJECT_UDP1); rule != NULL; rule = strtok_r(NULL, local37IFS, &r_HOST_REJECT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule28_FREE = get_ifs(rule, NULL);
    interfaces=rule28_FREE;;
    //destips=`get_ips "$rule"`
    rule29_FREE = get_ips(rule, NULL);
    destips=rule29_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule30_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule30_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule31_FREE = get_ports_ihp(rule, NULL);
    ports=rule31_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting $hosts for UDP port(s): $ports"
    show_if_ip8_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting %s for UDP port(s): %s;" "\n", show_if_ip8_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts8_FREE = ip_range(hosts, NULL);
    local38IFS = IFS;
    if (hosts8_FREE != NULL) strtok38_FREE = strdup(hosts8_FREE);
    if (hosts8_FREE != NULL) for (host = strtok_r(strtok38_FREE, local38IFS, &r_hosts8_FREE1); host != NULL; host = strtok_r(NULL, local38IFS, &r_hosts8_FREE1))
    {
      //for port in $ports; do
      local39IFS = IFS;
      if (ports != NULL) strtok39_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok39_FREE, local39IFS, &r_ports6); port != NULL; port = strtok_r(NULL, local39IFS, &r_ports6))
      {
        //for destip in $destips; do
        local40IFS = IFS;
        if (destips != NULL) strtok40_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok40_FREE, local40IFS, &r_destips8); destip != NULL; destip = strtok_r(NULL, local40IFS, &r_destips8))
        {
          //for interface in $interfaces; do
          local41IFS = IFS;
          if (interfaces != NULL) strtok41_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok41_FREE, local41IFS, &r_interfaces8); interface != NULL; interface = strtok_r(NULL, local41IFS, &r_interfaces8))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise UDP rejected: "
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Hostwise UDP rejected: \" --log-level %s", interface, host, destip, port, LOGLEVEL);

            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port -j REJECT --reject-with icmp-host-unreachable
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s -j REJECT --reject-with icmp-host-unreachable", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add TCP ports to DENY for certain hosts but NOT logged
  //########################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_TCP_NOLOG; do
  local42IFS = IFS;
  if (HOST_DENY_TCP_NOLOG != NULL) strtok42_FREE = strdup(HOST_DENY_TCP_NOLOG);
  if (HOST_DENY_TCP_NOLOG != NULL) for (rule = strtok_r(strtok42_FREE, local42IFS, &r_HOST_DENY_TCP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local42IFS, &r_HOST_DENY_TCP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule32_FREE = get_ifs(rule, NULL);
    interfaces=rule32_FREE;;
    //destips=`get_ips "$rule"`
    rule33_FREE = get_ips(rule, NULL);
    destips=rule33_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule34_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule34_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule35_FREE = get_ports_ihp(rule, NULL);
    ports=rule35_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for TCP port(s) (NO LOG): $ports"
    show_if_ip9_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for TCP port(s) (NO LOG): %s;" "\n", show_if_ip9_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts9_FREE = ip_range(hosts, NULL);
    local43IFS = IFS;
    if (hosts9_FREE != NULL) strtok43_FREE = strdup(hosts9_FREE);
    if (hosts9_FREE != NULL) for (host = strtok_r(strtok43_FREE, local43IFS, &r_hosts9_FREE1); host != NULL; host = strtok_r(NULL, local43IFS, &r_hosts9_FREE1))
    {
      //for port in $ports; do
      local44IFS = IFS;
      if (ports != NULL) strtok44_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok44_FREE, local44IFS, &r_ports7); port != NULL; port = strtok_r(NULL, local44IFS, &r_ports7))
      {
        //for destip in $destips; do
        local45IFS = IFS;
        if (destips != NULL) strtok45_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok45_FREE, local45IFS, &r_destips9); destip != NULL; destip = strtok_r(NULL, local45IFS, &r_destips9))
        {
          //for interface in $interfaces; do
          local46IFS = IFS;
          if (interfaces != NULL) strtok46_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok46_FREE, local46IFS, &r_interfaces9); interface != NULL; interface = strtok_r(NULL, local46IFS, &r_interfaces9))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j POST_INPUT_DROP_CHAIN", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add UDP ports to DENY for certain hosts but NOT logged
  //########################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_UDP_NOLOG; do
  local47IFS = IFS;
  if (HOST_DENY_UDP_NOLOG != NULL) strtok47_FREE = strdup(HOST_DENY_UDP_NOLOG);
  if (HOST_DENY_UDP_NOLOG != NULL) for (rule = strtok_r(strtok47_FREE, local47IFS, &r_HOST_DENY_UDP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local47IFS, &r_HOST_DENY_UDP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule36_FREE = get_ifs(rule, NULL);
    interfaces=rule36_FREE;;
    //destips=`get_ips "$rule"`
    rule37_FREE = get_ips(rule, NULL);
    destips=rule37_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule38_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule38_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule39_FREE = get_ports_ihp(rule, NULL);
    ports=rule39_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for UDP port(s) (NO LOG): $ports"
    show_if_ip10_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for UDP port(s) (NO LOG): %s;" "\n", show_if_ip10_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts10_FREE = ip_range(hosts, NULL);
    local48IFS = IFS;
    if (hosts10_FREE != NULL) strtok48_FREE = strdup(hosts10_FREE);
    if (hosts10_FREE != NULL) for (host = strtok_r(strtok48_FREE, local48IFS, &r_hosts10_FREE1); host != NULL; host = strtok_r(NULL, local48IFS, &r_hosts10_FREE1))
    {
      //for port in $ports; do
      local49IFS = IFS;
      if (ports != NULL) strtok49_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok49_FREE, local49IFS, &r_ports8); port != NULL; port = strtok_r(NULL, local49IFS, &r_ports8))
      {
        //for destip in $destips; do
        local50IFS = IFS;
        if (destips != NULL) strtok50_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok50_FREE, local50IFS, &r_destips10); destip != NULL; destip = strtok_r(NULL, local50IFS, &r_destips10))
        {
          //for interface in $interfaces; do
          local51IFS = IFS;
          if (interfaces != NULL) strtok51_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok51_FREE, local51IFS, &r_interfaces10); interface != NULL; interface = strtok_r(NULL, local51IFS, &r_interfaces10))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s -j POST_INPUT_DROP_CHAIN", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Add IP protocols to DENY for certain hosts but NOT logged
  //###########################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_IP_NOLOG; do
  local52IFS = IFS;
  if (HOST_DENY_IP_NOLOG != NULL) strtok52_FREE = strdup(HOST_DENY_IP_NOLOG);
  if (HOST_DENY_IP_NOLOG != NULL) for (rule = strtok_r(strtok52_FREE, local52IFS, &r_HOST_DENY_IP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local52IFS, &r_HOST_DENY_IP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule40_FREE = get_ifs(rule, NULL);
    interfaces=rule40_FREE;;
    //destips=`get_ips "$rule"`
    rule41_FREE = get_ips(rule, NULL);
    destips=rule41_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule42_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule42_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule43_FREE = get_ports_ihp(rule, NULL);
    protos=rule43_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for IP protocol(s) (NO LOG): $protos"
    show_if_ip11_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for IP protocol(s) (NO LOG): %s;" "\n", show_if_ip11_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts11_FREE = ip_range(hosts, NULL);
    local53IFS = IFS;
    if (hosts11_FREE != NULL) strtok53_FREE = strdup(hosts11_FREE);
    if (hosts11_FREE != NULL) for (host = strtok_r(strtok53_FREE, local53IFS, &r_hosts11_FREE1); host != NULL; host = strtok_r(NULL, local53IFS, &r_hosts11_FREE1))
    {
      //for proto in $protos; do
      local54IFS = IFS;
      if (protos != NULL) strtok54_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok54_FREE, local54IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local54IFS, &r_protos2))
      {
        //for destip in $destips; do
        local55IFS = IFS;
        if (destips != NULL) strtok55_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok55_FREE, local55IFS, &r_destips11); destip != NULL; destip = strtok_r(NULL, local55IFS, &r_destips11))
        {
          //for interface in $interfaces; do
          local56IFS = IFS;
          if (interfaces != NULL) strtok56_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok56_FREE, local56IFS, &r_interfaces11); interface != NULL; interface = strtok_r(NULL, local56IFS, &r_interfaces11))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p $proto -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p %s -j POST_INPUT_DROP_CHAIN", interface, host, destip, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Add ICMP-request to DENY for certain hosts but NOT logged
  //############################################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_ICMP_NOLOG; do
  local57IFS = IFS;
  if (HOST_DENY_ICMP_NOLOG != NULL) strtok57_FREE = strdup(HOST_DENY_ICMP_NOLOG);
  if (HOST_DENY_ICMP_NOLOG != NULL) for (rule = strtok_r(strtok57_FREE, local57IFS, &r_HOST_DENY_ICMP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local57IFS, &r_HOST_DENY_ICMP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule44_FREE = get_ifs(rule, NULL);
    interfaces=rule44_FREE;;
    //destips=`get_ips "$rule"`
    rule45_FREE = get_ips(rule, NULL);
    destips=rule45_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule46_FREE = get_hosts_ih(rule, NULL);
    hosts=rule46_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for ICMP-requests(ping)"
    show_if_ip12_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for ICMP-requests(ping);" "\n", show_if_ip12_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts12_FREE = ip_range(hosts, NULL);
    local58IFS = IFS;
    if (hosts12_FREE != NULL) strtok58_FREE = strdup(hosts12_FREE);
    if (hosts12_FREE != NULL) for (host = strtok_r(strtok58_FREE, local58IFS, &r_hosts12_FREE1); host != NULL; host = strtok_r(NULL, local58IFS, &r_hosts12_FREE1))
    {
      //for destip in $destips; do
      local59IFS = IFS;
      if (destips != NULL) strtok59_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok59_FREE, local59IFS, &r_destips12); destip != NULL; destip = strtok_r(NULL, local59IFS, &r_destips12))
      {
        //for interface in $interfaces; do
        local60IFS = IFS;
        if (interfaces != NULL) strtok60_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok60_FREE, local60IFS, &r_interfaces12); interface != NULL; interface = strtok_r(NULL, local60IFS, &r_interfaces12))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN", interface, host, destip);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add TCP ports to DENY for certain hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_TCP; do
  local61IFS = IFS;
  if (HOST_DENY_TCP != NULL) strtok61_FREE = strdup(HOST_DENY_TCP);
  if (HOST_DENY_TCP != NULL) for (rule = strtok_r(strtok61_FREE, local61IFS, &r_HOST_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local61IFS, &r_HOST_DENY_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule47_FREE = get_ifs(rule, NULL);
    interfaces=rule47_FREE;;
    //destips=`get_ips "$rule"`
    rule48_FREE = get_ips(rule, NULL);
    destips=rule48_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule49_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule49_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule50_FREE = get_ports_ihp(rule, NULL);
    ports=rule50_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for TCP port(s): $ports"
    show_if_ip13_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for TCP port(s): %s;" "\n", show_if_ip13_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts13_FREE = ip_range(hosts, NULL);
    local62IFS = IFS;
    if (hosts13_FREE != NULL) strtok62_FREE = strdup(hosts13_FREE);
    if (hosts13_FREE != NULL) for (host = strtok_r(strtok62_FREE, local62IFS, &r_hosts13_FREE1); host != NULL; host = strtok_r(NULL, local62IFS, &r_hosts13_FREE1))
    {
      //for port in $ports; do
      local63IFS = IFS;
      if (ports != NULL) strtok63_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok63_FREE, local63IFS, &r_ports9); port != NULL; port = strtok_r(NULL, local63IFS, &r_ports9))
      {
        //for destip in $destips; do
        local64IFS = IFS;
        if (destips != NULL) strtok64_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok64_FREE, local64IFS, &r_destips13); destip != NULL; destip = strtok_r(NULL, local64IFS, &r_destips13))
        {
          //for interface in $interfaces; do
          local65IFS = IFS;
          if (interfaces != NULL) strtok65_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok65_FREE, local65IFS, &r_interfaces13); interface != NULL; interface = strtok_r(NULL, local65IFS, &r_interfaces13))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET denied: "
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET denied: \" --log-level %s", interface, host, destip, port, LOGLEVEL);

            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p tcp --dport $port -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p tcp --dport %s -j POST_INPUT_DROP_CHAIN", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add UDP ports to DENY for certain hosts
  //#########################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_UDP; do
  local66IFS = IFS;
  if (HOST_DENY_UDP != NULL) strtok66_FREE = strdup(HOST_DENY_UDP);
  if (HOST_DENY_UDP != NULL) for (rule = strtok_r(strtok66_FREE, local66IFS, &r_HOST_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local66IFS, &r_HOST_DENY_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule51_FREE = get_ifs(rule, NULL);
    interfaces=rule51_FREE;;
    //destips=`get_ips "$rule"`
    rule52_FREE = get_ips(rule, NULL);
    destips=rule52_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule53_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule53_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule54_FREE = get_ports_ihp(rule, NULL);
    ports=rule54_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for UDP port(s): $ports"
    show_if_ip14_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for UDP port(s): %s;" "\n", show_if_ip14_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts14_FREE = ip_range(hosts, NULL);
    local67IFS = IFS;
    if (hosts14_FREE != NULL) strtok67_FREE = strdup(hosts14_FREE);
    if (hosts14_FREE != NULL) for (host = strtok_r(strtok67_FREE, local67IFS, &r_hosts14_FREE1); host != NULL; host = strtok_r(NULL, local67IFS, &r_hosts14_FREE1))
    {
      //for port in $ports; do
      local68IFS = IFS;
      if (ports != NULL) strtok68_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok68_FREE, local68IFS, &r_ports10); port != NULL; port = strtok_r(NULL, local68IFS, &r_ports10))
      {
        //for destip in $destips; do
        local69IFS = IFS;
        if (destips != NULL) strtok69_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok69_FREE, local69IFS, &r_destips14); destip != NULL; destip = strtok_r(NULL, local69IFS, &r_destips14))
        {
          //for interface in $interfaces; do
          local70IFS = IFS;
          if (interfaces != NULL) strtok70_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok70_FREE, local70IFS, &r_interfaces14); interface != NULL; interface = strtok_r(NULL, local70IFS, &r_interfaces14))
          {
            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET denied: "
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET denied: \" --log-level %s", interface, host, destip, port, LOGLEVEL);

            //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -p udp --dport $port -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -p udp --dport %s -j POST_INPUT_DROP_CHAIN", interface, host, destip, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add IP protocols to DENY for certain hosts
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_IP; do
  local71IFS = IFS;
  if (HOST_DENY_IP != NULL) strtok71_FREE = strdup(HOST_DENY_IP);
  if (HOST_DENY_IP != NULL) for (rule = strtok_r(strtok71_FREE, local71IFS, &r_HOST_DENY_IP1); rule != NULL; rule = strtok_r(NULL, local71IFS, &r_HOST_DENY_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule55_FREE = get_ifs(rule, NULL);
    interfaces=rule55_FREE;;
    //destips=`get_ips "$rule"`
    rule56_FREE = get_ips(rule, NULL);
    destips=rule56_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule57_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule57_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule58_FREE = get_ports_ihp(rule, NULL);
    protos=rule58_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for IP protocol(s): $protos"
    show_if_ip15_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for IP protocol(s): %s;" "\n", show_if_ip15_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts15_FREE = ip_range(hosts, NULL);
    local72IFS = IFS;
    if (hosts15_FREE != NULL) strtok72_FREE = strdup(hosts15_FREE);
    if (hosts15_FREE != NULL) for (host = strtok_r(strtok72_FREE, local72IFS, &r_hosts15_FREE1); host != NULL; host = strtok_r(NULL, local72IFS, &r_hosts15_FREE1))
    {
      //for proto in $protos; do
      local73IFS = IFS;
      if (protos != NULL) strtok73_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok73_FREE, local73IFS, &r_protos3); proto != NULL; proto = strtok_r(NULL, local73IFS, &r_protos3))
      {
        //for destip in $destips; do
        local74IFS = IFS;
        if (destips != NULL) strtok74_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok74_FREE, local74IFS, &r_destips15); destip != NULL; destip = strtok_r(NULL, local74IFS, &r_destips15))
        {
          //for interface in $interfaces; do
          local75IFS = IFS;
          if (interfaces != NULL) strtok75_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok75_FREE, local75IFS, &r_interfaces15); interface != NULL; interface = strtok_r(NULL, local75IFS, &r_interfaces15))
          {
            //iptables -A EXT_INPUT_CHAIN -s $host -p $proto  -m limit --limit 1/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET denied: "
            iptables("-A EXT_INPUT_CHAIN -s %s -p %s  -m limit --limit 1/h --limit-burst 1 -j LOG --log-prefix \"AIF:Host INET denied: \" --log-level %s", host, proto, LOGLEVEL);

            //iptables -A EXT_INPUT_CHAIN -s $host -p $proto -j POST_INPUT_DROP_CHAIN
            iptables("-A EXT_INPUT_CHAIN -s %s -p %s -j POST_INPUT_DROP_CHAIN", host, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Add ICMP-request to DENY for certain hosts
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_ICMP; do
  local76IFS = IFS;
  if (HOST_DENY_ICMP != NULL) strtok76_FREE = strdup(HOST_DENY_ICMP);
  if (HOST_DENY_ICMP != NULL) for (rule = strtok_r(strtok76_FREE, local76IFS, &r_HOST_DENY_ICMP1); rule != NULL; rule = strtok_r(NULL, local76IFS, &r_HOST_DENY_ICMP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule59_FREE = get_ifs(rule, NULL);
    interfaces=rule59_FREE;;
    //destips=`get_ips "$rule"`
    rule60_FREE = get_ips(rule, NULL);
    destips=rule60_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule61_FREE = get_hosts_ih(rule, NULL);
    hosts=rule61_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying $hosts for ICMP-requests(ping)"
    show_if_ip16_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying %s for ICMP-requests(ping);" "\n", show_if_ip16_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts16_FREE = ip_range(hosts, NULL);
    local77IFS = IFS;
    if (hosts16_FREE != NULL) strtok77_FREE = strdup(hosts16_FREE);
    if (hosts16_FREE != NULL) for (host = strtok_r(strtok77_FREE, local77IFS, &r_hosts16_FREE1); host != NULL; host = strtok_r(NULL, local77IFS, &r_hosts16_FREE1))
    {
      //for destip in $destips; do
      local78IFS = IFS;
      if (destips != NULL) strtok78_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok78_FREE, local78IFS, &r_destips16); destip != NULL; destip = strtok_r(NULL, local78IFS, &r_destips16))
      {
        //for interface in $interfaces; do
        local79IFS = IFS;
        if (interfaces != NULL) strtok79_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok79_FREE, local79IFS, &r_interfaces16); interface != NULL; interface = strtok_r(NULL, local79IFS, &r_interfaces16))
        {
          //if [ "$ICMP_DROP_LOG" != "0" ]; then
          if  (  (strcmp(ICMP_DROP_LOG,"0")!=0)  )
          {
            //iptables -A EXT_INPUT_CHAIN -s $host -p icmp --icmp-type echo-request -m limit --limit 1/h --limit-burst 1  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host INET denied: "
            iptables("-A EXT_INPUT_CHAIN -s %s -p icmp --icmp-type echo-request -m limit --limit 1/h --limit-burst 1  -j LOG --log-prefix \"AIF:Host INET denied: \" --log-level %s", host, LOGLEVEL);
          //fi
          }
          //iptables -A EXT_INPUT_CHAIN -s $host -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -s %s -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN", host);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding TCP ports to be denied for everyone
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_TCP; do
  local80IFS = IFS;
  if (DENY_TCP != NULL) strtok80_FREE = strdup(DENY_TCP);
  if (DENY_TCP != NULL) for (rule = strtok_r(strtok80_FREE, local80IFS, &r_DENY_TCP1); rule != NULL; rule = strtok_r(NULL, local80IFS, &r_DENY_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule62_FREE = get_ifs(rule, NULL);
    interfaces=rule62_FREE;;
    //destips=`get_ips "$rule"`
    rule63_FREE = get_ips(rule, NULL);
    destips=rule63_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule64_FREE = get_ports_ip(rule, NULL);
    ports=rule64_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying ANYHOST for TCP port(s): $ports"
    show_if_ip17_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying ANYHOST for TCP port(s): %s;" "\n", show_if_ip17_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local81IFS = IFS;
    if (ports != NULL) strtok81_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok81_FREE, local81IFS, &r_ports11); port != NULL; port = strtok_r(NULL, local81IFS, &r_ports11))
    {
      //for destip in $destips; do
      local82IFS = IFS;
      if (destips != NULL) strtok82_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok82_FREE, local82IFS, &r_destips17); destip != NULL; destip = strtok_r(NULL, local82IFS, &r_destips17))
      {
        //for interface in $interfaces; do
        local83IFS = IFS;
        if (interfaces != NULL) strtok83_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok83_FREE, local83IFS, &r_interfaces17); interface != NULL; interface = strtok_r(NULL, local83IFS, &r_interfaces17))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-INPUT denied: "
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:INET-INPUT denied: \" --log-level %s", interface, destip, port, LOGLEVEL);

          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s -j POST_INPUT_DROP_CHAIN", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding UDP ports to be denied for everyone
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_UDP; do
  local84IFS = IFS;
  if (DENY_UDP != NULL) strtok84_FREE = strdup(DENY_UDP);
  if (DENY_UDP != NULL) for (rule = strtok_r(strtok84_FREE, local84IFS, &r_DENY_UDP1); rule != NULL; rule = strtok_r(NULL, local84IFS, &r_DENY_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule65_FREE = get_ifs(rule, NULL);
    interfaces=rule65_FREE;;
    //destips=`get_ips "$rule"`
    rule66_FREE = get_ips(rule, NULL);
    destips=rule66_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule67_FREE = get_ports_ip(rule, NULL);
    ports=rule67_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying ANYHOST for UDP port(s): $ports"
    show_if_ip18_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying ANYHOST for UDP port(s): %s;" "\n", show_if_ip18_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local85IFS = IFS;
    if (ports != NULL) strtok85_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok85_FREE, local85IFS, &r_ports12); port != NULL; port = strtok_r(NULL, local85IFS, &r_ports12))
    {
      //for destip in $destips; do
      local86IFS = IFS;
      if (destips != NULL) strtok86_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok86_FREE, local86IFS, &r_destips18); destip != NULL; destip = strtok_r(NULL, local86IFS, &r_destips18))
      {
        //for interface in $interfaces; do
        local87IFS = IFS;
        if (interfaces != NULL) strtok87_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok87_FREE, local87IFS, &r_interfaces18); interface != NULL; interface = strtok_r(NULL, local87IFS, &r_interfaces18))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p udp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-INPUT denied: "
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p udp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:INET-INPUT denied: \" --log-level %s", interface, destip, port, LOGLEVEL);

          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p udp --dport $port -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p udp --dport %s -j POST_INPUT_DROP_CHAIN", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding TCP ports to be rejected for everyone
  //##############################################
  //unset IFS
  IFS = " ";
  //for rule in $REJECT_TCP; do
  local88IFS = IFS;
  if (REJECT_TCP != NULL) strtok88_FREE = strdup(REJECT_TCP);
  if (REJECT_TCP != NULL) for (rule = strtok_r(strtok88_FREE, local88IFS, &r_REJECT_TCP1); rule != NULL; rule = strtok_r(NULL, local88IFS, &r_REJECT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule68_FREE = get_ifs(rule, NULL);
    interfaces=rule68_FREE;;
    //destips=`get_ips "$rule"`
    rule69_FREE = get_ips(rule, NULL);
    destips=rule69_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule70_FREE = get_ports_ip(rule, NULL);
    ports=rule70_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting ANYHOST for TCP port(s): $ports"
    show_if_ip19_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting ANYHOST for TCP port(s): %s;" "\n", show_if_ip19_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local89IFS = IFS;
    if (ports != NULL) strtok89_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok89_FREE, local89IFS, &r_ports13); port != NULL; port = strtok_r(NULL, local89IFS, &r_ports13))
    {
      //for destip in $destips; do
      local90IFS = IFS;
      if (destips != NULL) strtok90_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok90_FREE, local90IFS, &r_destips19); destip != NULL; destip = strtok_r(NULL, local90IFS, &r_destips19))
      {
        //for interface in $interfaces; do
        local91IFS = IFS;
        if (interfaces != NULL) strtok91_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok91_FREE, local91IFS, &r_interfaces19); interface != NULL; interface = strtok_r(NULL, local91IFS, &r_interfaces19))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Rejected TCP port: "
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:Rejected TCP port: \" --log-level %s", interface, destip, port, LOGLEVEL);

          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port -j REJECT --reject-with tcp-reset
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s -j REJECT --reject-with tcp-reset", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding UDP ports to be rejected for everyone
  //##############################################
  //unset IFS
  IFS = " ";
  //for rule in $REJECT_UDP; do
  local92IFS = IFS;
  if (REJECT_UDP != NULL) strtok92_FREE = strdup(REJECT_UDP);
  if (REJECT_UDP != NULL) for (rule = strtok_r(strtok92_FREE, local92IFS, &r_REJECT_UDP1); rule != NULL; rule = strtok_r(NULL, local92IFS, &r_REJECT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule71_FREE = get_ifs(rule, NULL);
    interfaces=rule71_FREE;;
    //destips=`get_ips "$rule"`
    rule72_FREE = get_ips(rule, NULL);
    destips=rule72_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule73_FREE = get_ports_ip(rule, NULL);
    ports=rule73_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting ANYHOST for UDP port(s): $ports"
    show_if_ip20_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting ANYHOST for UDP port(s): %s;" "\n", show_if_ip20_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local93IFS = IFS;
    if (ports != NULL) strtok93_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok93_FREE, local93IFS, &r_ports14); port != NULL; port = strtok_r(NULL, local93IFS, &r_ports14))
    {
      //for destip in $destips; do
      local94IFS = IFS;
      if (destips != NULL) strtok94_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok94_FREE, local94IFS, &r_destips20); destip != NULL; destip = strtok_r(NULL, local94IFS, &r_destips20))
      {
        //for interface in $interfaces; do
        local95IFS = IFS;
        if (interfaces != NULL) strtok95_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok95_FREE, local95IFS, &r_interfaces20); interface != NULL; interface = strtok_r(NULL, local95IFS, &r_interfaces20))
        {
          //iptables -A EXT_INPUT_CHAIN -p udp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Rejected UDP port: "
          iptables("-A EXT_INPUT_CHAIN -p udp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:Rejected UDP port: \" --log-level %s", port, LOGLEVEL);

          //iptables -A EXT_INPUT_CHAIN -p udp --dport $port -j REJECT --reject-with icmp-host-unreachable
          iptables("-A EXT_INPUT_CHAIN -p udp --dport %s -j REJECT --reject-with icmp-host-unreachable", port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding the "full access hosts"
  //################################
  //unset IFS
  IFS = " ";
  //for rule in $FULL_ACCESS_HOSTS; do
  local96IFS = IFS;
  if (FULL_ACCESS_HOSTS != NULL) strtok96_FREE = strdup(FULL_ACCESS_HOSTS);
  if (FULL_ACCESS_HOSTS != NULL) for (rule = strtok_r(strtok96_FREE, local96IFS, &r_FULL_ACCESS_HOSTS1); rule != NULL; rule = strtok_r(NULL, local96IFS, &r_FULL_ACCESS_HOSTS1))
  {
    //interfaces=`get_ifs "$rule"`
    rule74_FREE = get_ifs(rule, NULL);
    interfaces=rule74_FREE;;
    //destips=`get_ips "$rule"`
    rule75_FREE = get_ips(rule, NULL);
    destips=rule75_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule76_FREE = get_hosts_ih(rule, NULL);
    hosts=rule76_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing $hosts full (inbound) access"
    show_if_ip21_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing %s full (inbound) access;" "\n", show_if_ip21_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts17_FREE = ip_range(hosts, NULL);
    local97IFS = IFS;
    if (hosts17_FREE != NULL) strtok97_FREE = strdup(hosts17_FREE);
    if (hosts17_FREE != NULL) for (host = strtok_r(strtok97_FREE, local97IFS, &r_hosts17_FREE1); host != NULL; host = strtok_r(NULL, local97IFS, &r_hosts17_FREE1))
    {
      //for destip in $destips; do
      local98IFS = IFS;
      if (destips != NULL) strtok98_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok98_FREE, local98IFS, &r_destips21); destip != NULL; destip = strtok_r(NULL, local98IFS, &r_destips21))
      {
        //for interface in $interfaces; do
        local99IFS = IFS;
        if (interfaces != NULL) strtok99_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok99_FREE, local99IFS, &r_interfaces21); interface != NULL; interface = strtok_r(NULL, local99IFS, &r_interfaces21))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -s $host -d $destip -j ACCEPT
          iptables("-A EXT_INPUT_CHAIN -i %s -s %s -d %s -j ACCEPT", interface, host, destip);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# TCP ports to DENY but NOT to LOG
  //##################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_TCP_NOLOG; do
  local100IFS = IFS;
  if (DENY_TCP_NOLOG != NULL) strtok100_FREE = strdup(DENY_TCP_NOLOG);
  if (DENY_TCP_NOLOG != NULL) for (rule = strtok_r(strtok100_FREE, local100IFS, &r_DENY_TCP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local100IFS, &r_DENY_TCP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule77_FREE = get_ifs(rule, NULL);
    interfaces=rule77_FREE;;
    //destips=`get_ips "$rule"`
    rule78_FREE = get_ips(rule, NULL);
    destips=rule78_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule79_FREE = get_ports_ip(rule, NULL);
    ports=rule79_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying ANYHOST for TCP port(s) (NO LOG): $ports"
    show_if_ip22_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying ANYHOST for TCP port(s) (NO LOG): %s;" "\n", show_if_ip22_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local101IFS = IFS;
    if (ports != NULL) strtok101_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok101_FREE, local101IFS, &r_ports15); port != NULL; port = strtok_r(NULL, local101IFS, &r_ports15))
    {
      //for destip in $destips; do
      local102IFS = IFS;
      if (destips != NULL) strtok102_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok102_FREE, local102IFS, &r_destips22); destip != NULL; destip = strtok_r(NULL, local102IFS, &r_destips22))
      {
        //for interface in $interfaces; do
        local103IFS = IFS;
        if (interfaces != NULL) strtok103_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok103_FREE, local103IFS, &r_interfaces22); interface != NULL; interface = strtok_r(NULL, local103IFS, &r_interfaces22))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s -j POST_INPUT_DROP_CHAIN", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to DENY but NOT to LOG
  //##################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_UDP_NOLOG; do
  local104IFS = IFS;
  if (DENY_UDP_NOLOG != NULL) strtok104_FREE = strdup(DENY_UDP_NOLOG);
  if (DENY_UDP_NOLOG != NULL) for (rule = strtok_r(strtok104_FREE, local104IFS, &r_DENY_UDP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local104IFS, &r_DENY_UDP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule80_FREE = get_ifs(rule, NULL);
    interfaces=rule80_FREE;;
    //destips=`get_ips "$rule"`
    rule81_FREE = get_ips(rule, NULL);
    destips=rule81_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule82_FREE = get_ports_ip(rule, NULL);
    ports=rule82_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Denying ANYHOST for UDP port(s) (NO LOG): $ports"
    show_if_ip23_FREE = show_if_ip(interfaces, destips);
    printf(" %s Denying ANYHOST for UDP port(s) (NO LOG): %s;" "\n", show_if_ip23_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local105IFS = IFS;
    if (ports != NULL) strtok105_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok105_FREE, local105IFS, &r_ports16); port != NULL; port = strtok_r(NULL, local105IFS, &r_ports16))
    {
      //for destip in $destips; do
      local106IFS = IFS;
      if (destips != NULL) strtok106_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok106_FREE, local106IFS, &r_destips23); destip != NULL; destip = strtok_r(NULL, local106IFS, &r_destips23))
      {
        //for interface in $interfaces; do
        local107IFS = IFS;
        if (interfaces != NULL) strtok107_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok107_FREE, local107IFS, &r_interfaces23); interface != NULL; interface = strtok_r(NULL, local107IFS, &r_interfaces23))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p udp --dport $port -j POST_INPUT_DROP_CHAIN
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p udp --dport %s -j POST_INPUT_DROP_CHAIN", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# TCP ports to REJECT but NOT to LOG
  //####################################
  //unset IFS
  IFS = " ";
  //for rule in $REJECT_TCP_NOLOG; do
  local108IFS = IFS;
  if (REJECT_TCP_NOLOG != NULL) strtok108_FREE = strdup(REJECT_TCP_NOLOG);
  if (REJECT_TCP_NOLOG != NULL) for (rule = strtok_r(strtok108_FREE, local108IFS, &r_REJECT_TCP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local108IFS, &r_REJECT_TCP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule83_FREE = get_ifs(rule, NULL);
    interfaces=rule83_FREE;;
    //destips=`get_ips "$rule"`
    rule84_FREE = get_ips(rule, NULL);
    destips=rule84_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule85_FREE = get_ports_ip(rule, NULL);
    ports=rule85_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting ANYHOST for TCP port(s) (NO LOG): $ports"
    show_if_ip24_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting ANYHOST for TCP port(s) (NO LOG): %s;" "\n", show_if_ip24_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local109IFS = IFS;
    if (ports != NULL) strtok109_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok109_FREE, local109IFS, &r_ports17); port != NULL; port = strtok_r(NULL, local109IFS, &r_ports17))
    {
      //for destip in $destips; do
      local110IFS = IFS;
      if (destips != NULL) strtok110_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok110_FREE, local110IFS, &r_destips24); destip != NULL; destip = strtok_r(NULL, local110IFS, &r_destips24))
      {
        //for interface in $interfaces; do
        local111IFS = IFS;
        if (interfaces != NULL) strtok111_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok111_FREE, local111IFS, &r_interfaces24); interface != NULL; interface = strtok_r(NULL, local111IFS, &r_interfaces24))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port -j REJECT --reject-with tcp-reset
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s -j REJECT --reject-with tcp-reset", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# UDP ports to REJECT but NOT to LOG
  //####################################
  //unset IFS
  IFS = " ";
  //for rule in $REJECT_UDP_NOLOG; do
  local112IFS = IFS;
  if (REJECT_UDP_NOLOG != NULL) strtok112_FREE = strdup(REJECT_UDP_NOLOG);
  if (REJECT_UDP_NOLOG != NULL) for (rule = strtok_r(strtok112_FREE, local112IFS, &r_REJECT_UDP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local112IFS, &r_REJECT_UDP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule86_FREE = get_ifs(rule, NULL);
    interfaces=rule86_FREE;;
    //destips=`get_ips "$rule"`
    rule87_FREE = get_ips(rule, NULL);
    destips=rule87_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule88_FREE = get_ports_ip(rule, NULL);
    ports=rule88_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Rejecting ANYHOST for UDP port(s) (NO LOG): $ports"
    show_if_ip25_FREE = show_if_ip(interfaces, destips);
    printf(" %s Rejecting ANYHOST for UDP port(s) (NO LOG): %s;" "\n", show_if_ip25_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local113IFS = IFS;
    if (ports != NULL) strtok113_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok113_FREE, local113IFS, &r_ports18); port != NULL; port = strtok_r(NULL, local113IFS, &r_ports18))
    {
      //for destip in $destips; do
      local114IFS = IFS;
      if (destips != NULL) strtok114_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok114_FREE, local114IFS, &r_destips25); destip != NULL; destip = strtok_r(NULL, local114IFS, &r_destips25))
      {
        //for interface in $interfaces; do
        local115IFS = IFS;
        if (interfaces != NULL) strtok115_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok115_FREE, local115IFS, &r_interfaces25); interface != NULL; interface = strtok_r(NULL, local115IFS, &r_interfaces25))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p udp --dport $port -j REJECT --reject-with icmp-host-unreachable
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p udp --dport %s -j REJECT --reject-with icmp-host-unreachable", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Check the packet source address
  //#################################
  //if [ "$DROP_PRIVATE_ADDRESSES" = "1" ]; then
  if  (  (strcmp(DROP_PRIVATE_ADDRESSES,"1")==0)  )
  {
    //echo " Packets will be checked for private source addresses"
    printf(" Packets will be checked for private source addresses" "\n");
  //else
  }
  else
  {
    //echo " Packets will NOT be checked for private source addresses"
    printf(" Packets will NOT be checked for private source addresses" "\n");
  //fi
  }
  //if [ "$DROP_PRIVATE_ADDRESSES" = "1" -o "$RESERVED_NET_LOG" = "1" ]; then
  if  (  ((strcmp(DROP_PRIVATE_ADDRESSES,"1")==0)||(strcmp(RESERVED_NET_LOG,"1")==0)) )
  {
    //iptables -A EXT_INPUT_CHAIN -j RESERVED_NET_CHK
    iptables("-A EXT_INPUT_CHAIN -j RESERVED_NET_CHK");
  //fi
  }

  //# Do NOT allow DRDOS abuse (Distributed Reflection Denial Of Service attack)
  //############################################################################
  //if [ "$DRDOS_PROTECT" = "1" ]; then
  if  (  (strcmp(DRDOS_PROTECT,"1")==0)  )
  {
    //echo " Enabling protection against DRDOS-abuse"
    printf(" Enabling protection against DRDOS-abuse" "\n");

    //iptables -A EXT_INPUT_CHAIN -p tcp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995  -m limit --limit 6/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Possible DRDOS abuse: "
    iptables("-A EXT_INPUT_CHAIN -p tcp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995  -m limit --limit 6/h --limit-burst 1 -j LOG --log-prefix \"AIF:Possible DRDOS abuse: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_INPUT_CHAIN -p udp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995  -m limit --limit 6/h --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Possible DRDOS abuse: "
    iptables("-A EXT_INPUT_CHAIN -p udp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995  -m limit --limit 6/h --limit-burst 1 -j LOG --log-prefix \"AIF:Possible DRDOS abuse: \" --log-level %s", LOGLEVEL);

    //iptables -A EXT_INPUT_CHAIN -p tcp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995 -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_INPUT_CHAIN -p tcp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995 -j POST_INPUT_DROP_CHAIN");
    //iptables -A EXT_INPUT_CHAIN -p udp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995 -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_INPUT_CHAIN -p udp ! --dport 2049 -m multiport --sports 20,21,22,23,80,110,143,443,993,995 -j POST_INPUT_DROP_CHAIN");
  //fi
  }

  //# Adding TCP ports NOT to be firewalled
  //#######################################
  //unset IFS
  IFS = " ";
  //for rule in $OPEN_TCP; do
  local116IFS = IFS;
  if (OPEN_TCP != NULL) strtok116_FREE = strdup(OPEN_TCP);
  if (OPEN_TCP != NULL) for (rule = strtok_r(strtok116_FREE, local116IFS, &r_OPEN_TCP1); rule != NULL; rule = strtok_r(NULL, local116IFS, &r_OPEN_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule89_FREE = get_ifs(rule, NULL);
    interfaces=rule89_FREE;;
    //destips=`get_ips "$rule"`
    rule90_FREE = get_ips(rule, NULL);
    destips=rule90_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule91_FREE = get_ports_ip(rule, NULL);
    ports=rule91_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing ANYHOST for TCP port(s): $ports"
    show_if_ip26_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing ANYHOST for TCP port(s): %s;" "\n", show_if_ip26_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local117IFS = IFS;
    if (ports != NULL) strtok117_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok117_FREE, local117IFS, &r_ports19); port != NULL; port = strtok_r(NULL, local117IFS, &r_ports19))
    {
      //for destip in $destips; do
      local118IFS = IFS;
      if (destips != NULL) strtok118_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok118_FREE, local118IFS, &r_destips26); destip != NULL; destip = strtok_r(NULL, local118IFS, &r_destips26))
      {
        //for interface in $interfaces; do
        local119IFS = IFS;
        if (interfaces != NULL) strtok119_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok119_FREE, local119IFS, &r_interfaces26); interface != NULL; interface = strtok_r(NULL, local119IFS, &r_interfaces26))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p tcp --dport $port -j ACCEPT
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p tcp --dport %s -j ACCEPT", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Adding UDP ports NOT to be firewalled
  //#######################################
  //unset IFS
  IFS = " ";
  //for rule in $OPEN_UDP; do
  local120IFS = IFS;
  if (OPEN_UDP != NULL) strtok120_FREE = strdup(OPEN_UDP);
  if (OPEN_UDP != NULL) for (rule = strtok_r(strtok120_FREE, local120IFS, &r_OPEN_UDP1); rule != NULL; rule = strtok_r(NULL, local120IFS, &r_OPEN_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule92_FREE = get_ifs(rule, NULL);
    interfaces=rule92_FREE;;
    //destips=`get_ips "$rule"`
    rule93_FREE = get_ips(rule, NULL);
    destips=rule93_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule94_FREE = get_ports_ip(rule, NULL);
    ports=rule94_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing ANYHOST for UDP port(s): $ports"
    show_if_ip27_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing ANYHOST for UDP port(s): %s;" "\n", show_if_ip27_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local121IFS = IFS;
    if (ports != NULL) strtok121_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok121_FREE, local121IFS, &r_ports20); port != NULL; port = strtok_r(NULL, local121IFS, &r_ports20))
    {
      //for destip in $destips; do
      local122IFS = IFS;
      if (destips != NULL) strtok122_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok122_FREE, local122IFS, &r_destips27); destip != NULL; destip = strtok_r(NULL, local122IFS, &r_destips27))
      {
        //for interface in $interfaces; do
        local123IFS = IFS;
        if (interfaces != NULL) strtok123_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok123_FREE, local123IFS, &r_interfaces27); interface != NULL; interface = strtok_r(NULL, local123IFS, &r_interfaces27))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p udp --dport $port -j ACCEPT
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p udp --dport %s -j ACCEPT", interface, destip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Adding IP protocols NOT to be firewalled
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $OPEN_IP; do
  local124IFS = IFS;
  if (OPEN_IP != NULL) strtok124_FREE = strdup(OPEN_IP);
  if (OPEN_IP != NULL) for (rule = strtok_r(strtok124_FREE, local124IFS, &r_OPEN_IP1); rule != NULL; rule = strtok_r(NULL, local124IFS, &r_OPEN_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule95_FREE = get_ifs(rule, NULL);
    interfaces=rule95_FREE;;
    //destips=`get_ips "$rule"`
    rule96_FREE = get_ips(rule, NULL);
    destips=rule96_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule97_FREE = get_ports_ip(rule, NULL);
    protos=rule97_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Allowing ANYHOST for IP protocol(s): $protos"
    show_if_ip28_FREE = show_if_ip(interfaces, destips);
    printf(" %s Allowing ANYHOST for IP protocol(s): %s;" "\n", show_if_ip28_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local125IFS = IFS;
    if (protos != NULL) strtok125_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok125_FREE, local125IFS, &r_protos4); proto != NULL; proto = strtok_r(NULL, local125IFS, &r_protos4))
    {
      //for destip in $destips; do
      local126IFS = IFS;
      if (destips != NULL) strtok126_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok126_FREE, local126IFS, &r_destips28); destip != NULL; destip = strtok_r(NULL, local126IFS, &r_destips28))
      {
        //for interface in $interfaces; do
        local127IFS = IFS;
        if (interfaces != NULL) strtok127_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok127_FREE, local127IFS, &r_interfaces28); interface != NULL; interface = strtok_r(NULL, local127IFS, &r_interfaces28))
        {
          //iptables -A EXT_INPUT_CHAIN -i $interface -d $destip -p $proto -j ACCEPT
          iptables("-A EXT_INPUT_CHAIN -i %s -d %s -p %s -j ACCEPT", interface, destip, proto);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Allow world to send IPv4 ICMP packets?
  //########################################
  //if [ "$OPEN_ICMP" = "1" ]; then
  if  (  (strcmp(OPEN_ICMP,"1")==0)  )
  {
//Mos 2013/09/12, fix #9058 Respond to Ping on Internet Port does not take effect when PORT_SCAN_DOS_DISABLE 
#if 0 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
    //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))    
#endif
    {
    //echo " Allowing ANYHOST to send IPv4 ICMP-requests (ping)"
    printf(" Allowing ANYHOST to send IPv4 ICMP-requests (ping)" "\n");
    //ip4tables -A EXT_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT
    ip4tables("-A EXT_INPUT_CHAIN -p icmp --icmp-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    }
  //else
  }
  else
  {
    //echo " Denying ANYHOST to send IPv4 ICMP-requests (ping)"
    printf(" Denying ANYHOST to send IPv4 ICMP-requests (ping)" "\n");
  //fi
  }

  //# Allow world to send IPv6 ICMPv6 packets?
  //##########################################
  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //if [ "$OPEN_ICMPV6" != "0" ]; then
    if  (  (strcmp(OPEN_ICMPV6,"0")!=0)  )
    {
      //echo " Allowing ANYHOST to send IPv6 ICMPv6-requests"
      printf(" Allowing ANYHOST to send IPv6 ICMPv6-requests" "\n");
      //ip6tables -A EXT_INPUT_CHAIN -p icmpv6 --icmpv6-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT
      ip6tables("-A EXT_INPUT_CHAIN -p icmpv6 --icmpv6-type echo-request -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    //else
    }
    else
    {
      //echo " Denying ANYHOST to send IPv6 ICMPv6-requests"
      printf(" Denying ANYHOST to send IPv6 ICMPv6-requests" "\n");
    //fi
    }
  //fi
  }

  //# Logging of possible stealth scans
  //###################################
  //if [ "$POSSIBLE_SCAN_LOG" = "1" ]; then
  if  (  (strcmp(POSSIBLE_SCAN_LOG,"1")==0)  )
  {
    //echo " Logging of possible stealth scans enabled"
    printf(" Logging of possible stealth scans enabled" "\n");
    //if [ "$UNPRIV_TCP_LOG" != "0" ]; then
    if  (  (strcmp(UNPRIV_TCP_LOG,"0")!=0)  )
    {
      //iptables -A EXT_INPUT_CHAIN -p tcp ! --syn --dport 1024:  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth scan? (UNPRIV): "
      iptables("-A EXT_INPUT_CHAIN -p tcp ! --syn --dport 1024:  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:Stealth scan? (UNPRIV): \" --log-level %s", LOGLEVEL);
    //fi
    }

    //if [ "$PRIV_TCP_LOG" != "0" ]; then
    if  (  (strcmp(PRIV_TCP_LOG,"0")!=0)  )
    {
      //iptables -A EXT_INPUT_CHAIN -p tcp ! --syn --dport :1023  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Stealth scan? (PRIV): "
      iptables("-A EXT_INPUT_CHAIN -p tcp ! --syn --dport :1023  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:Stealth scan? (PRIV): \" --log-level %s", LOGLEVEL);
    //fi
    }
  //else
  }
  else
  {
    //echo " Logging of possible stealth scans disabled"
    printf(" Logging of possible stealth scans disabled" "\n");
  //fi
  }

  //# General stealth scan drop
  //###########################
  //iptables -A EXT_INPUT_CHAIN -p tcp ! --syn -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p tcp ! --syn -j POST_INPUT_DROP_CHAIN");

  //# Setup IPv4 chain to handle broadcast traffic
  //##############################################
  //ip4tables -A EXT_INPUT_CHAIN -d 255.255.255.255 -j EXT_BROADCAST_CHAIN
  ip4tables("-A EXT_INPUT_CHAIN -d 255.255.255.255 -j EXT_BROADCAST_CHAIN");

  //# ip4tables -A EXT_INPUT_CHAIN -m pkttype --pkt-type broadcast -j EXT_BROADCAST_CHAIN
  //# ip4tables -A EXT_INPUT_CHAIN -m addrtype --dst-type BROADCAST -j EXT_BROADCAST_CHAIN
  //if [ -n "$EXT_NET_BCAST_ADDRESS" ]; then
  if  (  ((EXT_NET_BCAST_ADDRESS!=NULL)&&(strlen(EXT_NET_BCAST_ADDRESS)!=0))  )
  {
    //IFS=' ,'
    IFS=" ,";
    //for address in $EXT_NET_BCAST_ADDRESS; do
    local128IFS = IFS;
    if (EXT_NET_BCAST_ADDRESS != NULL) strtok128_FREE = strdup(EXT_NET_BCAST_ADDRESS);
    if (EXT_NET_BCAST_ADDRESS != NULL) for (address = strtok_r(strtok128_FREE, local128IFS, &r_EXT_NET_BCAST_ADDRESS1); address != NULL; address = strtok_r(NULL, local128IFS, &r_EXT_NET_BCAST_ADDRESS1))
    {
      //ip4tables -A EXT_INPUT_CHAIN -d $address -j EXT_BROADCAST_CHAIN
      ip4tables("-A EXT_INPUT_CHAIN -d %s -j EXT_BROADCAST_CHAIN", address);
    //done
    }
  //else
  }
  else
  {
    //IFS=' ,'
    IFS=" ,";
    //for net in $EXTERNAL_NET; do
    local129IFS = IFS;
    if (EXTERNAL_NET != NULL) strtok129_FREE = strdup(EXTERNAL_NET);
    if (EXTERNAL_NET != NULL) for (net = strtok_r(strtok129_FREE, local129IFS, &r_EXTERNAL_NET3); net != NULL; net = strtok_r(NULL, local129IFS, &r_EXTERNAL_NET3))
    {
      //# Class C net
      //ip4tables -A EXT_INPUT_CHAIN -d $(echo $net |awk -F. '{ print $1"."$2"."$3".255" }')  -j EXT_BROADCAST_CHAIN
      awk1_FREE = partial_ip4(net, 1, 2, 3, 255);
      ip4tables("-A EXT_INPUT_CHAIN -d (echo net |awk -F. '{ print 1\".\"%s\".\"%s\".255\" }')  -j EXT_BROADCAST_CHAIN", 2, 3);

      //# Class B net
      //ip4tables -A EXT_INPUT_CHAIN -d $(echo $net |awk -F. '{ print $1"."$2".255.255" }')  -j EXT_BROADCAST_CHAIN
      awk2_FREE = partial_ip4(net, 1, 2, 255, 255);
      ip4tables("-A EXT_INPUT_CHAIN -d (echo net |awk -F. '{ print 1\".\"%s\".255.255\" }')  -j EXT_BROADCAST_CHAIN", 2);

      //# Class A net
      //ip4tables -A EXT_INPUT_CHAIN -d $(echo $net |awk -F. '{ print $1".255.255.255" }')  -j EXT_BROADCAST_CHAIN
      awk3_FREE = partial_ip4(net, 1, 255, 255, 255);
      ip4tables("-A EXT_INPUT_CHAIN -d (echo net |awk -F. '{ print 1\".255.255.255\" }')  -j EXT_BROADCAST_CHAIN");
    //done
    }
  //fi
  }

  //# Log packets to privileged TCP ports?
  //##################################################
  //if [ "$PRIV_TCP_LOG" != "0" ]; then
  if  (  (strcmp(PRIV_TCP_LOG,"0")!=0)  )
  {
    //echo " Logging of (other) packets to PRIVILEGED TCP ports enabled"
    printf(" Logging of (other) packets to PRIVILEGED TCP ports enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV TCP packet: "
    iptables("-A EXT_INPUT_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV TCP packet: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV TCP multicast: "
    iptables("-A EXT_MULTICAST_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV TCP multicast: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_BROADCAST_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV TCP broadcast: "
    iptables("-A EXT_BROADCAST_CHAIN -p tcp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV TCP broadcast: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of (other) packets to PRIVILEGED TCP ports disabled"
    printf(" Logging of (other) packets to PRIVILEGED TCP ports disabled" "\n");
  //fi
  }

  //# Log packets to privileged UDP ports?
  //##################################################
  //if [ "$PRIV_UDP_LOG" != "0" ]; then
  if  (  (strcmp(PRIV_UDP_LOG,"0")!=0)  )
  {
    //echo " Logging of (other) packets to PRIVILEGED UDP ports enabled"
    printf(" Logging of (other) packets to PRIVILEGED UDP ports enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV UDP packet: "
    iptables("-A EXT_INPUT_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV UDP packet: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV UDP multicast: "
    iptables("-A EXT_MULTICAST_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV UDP multicast: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_BROADCAST_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:PRIV UDP broadcast: "
    iptables("-A EXT_BROADCAST_CHAIN -p udp --dport :1023  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:PRIV UDP broadcast: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of (other) packets to PRIVILEGED UDP ports disabled"
    printf(" Logging of (other) packets to PRIVILEGED UDP ports disabled" "\n");
  //fi
  }

  //# Log packets to unprivileged TCP ports?
  //####################################################
  //if [ "$UNPRIV_TCP_LOG" != "0" ]; then
  if  (  (strcmp(UNPRIV_TCP_LOG,"0")!=0)  )
  {
    //echo " Logging of (other) packets to UNPRIVILEGED TCP ports enabled"
    printf(" Logging of (other) packets to UNPRIVILEGED TCP ports enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV TCP packet: "
    iptables("-A EXT_INPUT_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV TCP packet: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV TCP multicast: "
    iptables("-A EXT_MULTICAST_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV TCP multicast: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_BROADCAST_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV TCP broadcast: "
    iptables("-A EXT_BROADCAST_CHAIN -p tcp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV TCP broadcast: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of (other) packets to UNPRIVILEGED TCP ports disabled"
    printf(" Logging of (other) packets to UNPRIVILEGED TCP ports disabled" "\n");
  //fi
  }

  //# Log packets to unprivileged UDP ports?
  //####################################################
  //if [ "$UNPRIV_UDP_LOG" != "0" ]; then
  if  (  (strcmp(UNPRIV_UDP_LOG,"0")!=0)  )
  {
    //echo " Logging of (other) packets to UNPRIVILEGED UDP ports enabled"
    printf(" Logging of (other) packets to UNPRIVILEGED UDP ports enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p udp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV UDP packet: "
    iptables("-A EXT_INPUT_CHAIN -p udp --dport 1024:  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV UDP packet: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p udp --dport 1024  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV UDP multicast: "
    iptables("-A EXT_MULTICAST_CHAIN -p udp --dport 1024  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV UDP multicast: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_BROADCAST_CHAIN -p udp --dport 1024  -m limit --limit 6/m --limit-burst 2 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UNPRIV UDP broadcast: "
    iptables("-A EXT_BROADCAST_CHAIN -p udp --dport 1024  -m limit --limit 6/m --limit-burst 2 -j LOG --log-prefix \"AIF:UNPRIV UDP broadcast: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo "Logging of (other) packets to UNPRIVILEGED UDP ports disabled"
    printf("Logging of (other) packets to UNPRIVILEGED UDP ports disabled" "\n");
  //fi
  }

  //# Do we want to log igmp packets?
  //#############################################
  //if [ "$IGMP_LOG" != "0" ]; then
  if  (  (strcmp(IGMP_LOG,"0")!=0)  )
  {
    //echo " Logging of IGMP packets enabled"
    printf(" Logging of IGMP packets enabled" "\n");
    //ip4tables -A EXT_INPUT_CHAIN -p 2  -m limit --limit 1/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IGMP packet: "
    ip4tables("-A EXT_INPUT_CHAIN -p 2  -m limit --limit 1/m --limit-burst 5 -j LOG --log-prefix \"AIF:IGMP packet: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of IPv4 IGMP packets disabled"
    printf(" Logging of IPv4 IGMP packets disabled" "\n");
  //fi
  }

  //# Allow all packets that have been locally redirected
  //#####################################################
  //if [ "$NAT_LOCAL_REDIRECT" = "1" ]; then
  if  (  (strcmp(NAT_LOCAL_REDIRECT,"1")==0)  )
  {
    //echo " Enabling support for NAT local redirect"
    printf(" Enabling support for NAT local redirect" "\n");
    //ip4tables -A EXT_INPUT_CHAIN -m conntrack --ctstate DNAT -j ACCEPT
    ip4tables("-A EXT_INPUT_CHAIN -m conntrack --ctstate DNAT -j ACCEPT");
  //fi
  }

  //# Finally drop all in the broadcast chain
  //iptables -A EXT_BROADCAST_CHAIN -j DROP
  iptables("-A EXT_BROADCAST_CHAIN -j DROP");
    
  //# Jump into the POST_INPUT_CHAIN before we start to DROP
  //iptables -A EXT_INPUT_CHAIN -j POST_INPUT_CHAIN
  iptables("-A EXT_INPUT_CHAIN -j POST_INPUT_CHAIN");
  
  //if [ "$ICMP_REQUEST_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_REQUEST_LOG,"0")!=0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
      //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))      
#endif
    {
    //echo " Logging of dropped ICMP-request(ping) packets enabled"
    printf(" Logging of dropped ICMP-request(ping) packets enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request: "
    iptables("-A EXT_INPUT_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-request: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 3/m --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-multicast-request: "
    iptables("-A EXT_MULTICAST_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-multicast-request: \" --log-level %s", LOGLEVEL);
    }
  //else
  }
  else
  {
    //echo " Logging of dropped ICMP-request(ping) packets disabled"
    printf(" Logging of dropped ICMP-request(ping) packets disabled" "\n");
  //fi
  }
  
  //if [ "$ICMP_OTHER_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_OTHER_LOG,"0")!=0)  )
  {
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
      //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))      
#endif
    {
    //echo " Logging of dropped other ICMP packets enabled"
    printf(" Logging of dropped other ICMP packets enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN -p icmp ! --icmp-type echo-request  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-other: "
    iptables("-A EXT_INPUT_CHAIN -p icmp ! --icmp-type echo-request  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-other: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_MULTICAST_CHAIN -p icmp ! --icmp-type echo-request  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-multicast-other: "
    iptables("-A EXT_MULTICAST_CHAIN -p icmp ! --icmp-type echo-request  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-multicast-other: \" --log-level %s", LOGLEVEL);
    }
  //else
  }
  else
  {
    //echo " Logging of dropped other ICMP packets disabled"
    printf(" Logging of dropped other ICMP packets disabled" "\n");
  //fi
  }

  //# Drop all in the multicast chain
  //iptables -A EXT_MULTICAST_CHAIN -j DROP
  iptables("-A EXT_MULTICAST_CHAIN -j DROP");
    
  //# Drop all "standard" IP protocols
  //##################################
  //iptables -A EXT_INPUT_CHAIN -p tcp -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p tcp -j POST_INPUT_DROP_CHAIN");
  //iptables -A EXT_INPUT_CHAIN -p udp -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p udp -j POST_INPUT_DROP_CHAIN");
  //ip4tables -A EXT_INPUT_CHAIN -p 2 -j POST_INPUT_DROP_CHAIN
  ip4tables("-A EXT_INPUT_CHAIN -p 2 -j POST_INPUT_DROP_CHAIN");
  //iptables -A EXT_INPUT_CHAIN -p icmp -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -p icmp -j POST_INPUT_DROP_CHAIN");

  //# Do we want to log non udp/tcp/icmp packets?
  //#############################################
  //if [ "$OTHER_IP_LOG" != "0" ]; then
  if  (  (strcmp(OTHER_IP_LOG,"0")!=0)  )
  {
    //echo " Logging of other IP protocols (non TCP/UDP/ICMP/IGMP) packets enabled"
    printf(" Logging of other IP protocols (non TCP/UDP/ICMP/IGMP) packets enabled" "\n");
    //iptables -A EXT_INPUT_CHAIN  -m limit --limit 1/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Other connect: "
    iptables("-A EXT_INPUT_CHAIN  -m limit --limit 1/m --limit-burst 5 -j LOG --log-prefix \"AIF:Other connect: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of other IP protocols (non TCP/UDP/ICMP/IGMP) packets disabled"
    printf(" Logging of other IP protocols (non TCP/UDP/ICMP/IGMP) packets disabled" "\n");
  //fi
  }
  
  //# Drop all remaining packets
  //############################
  //iptables -A EXT_INPUT_CHAIN -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_INPUT_CHAIN -j POST_INPUT_DROP_CHAIN");
if (strtok95_FREE != NULL) free(strtok95_FREE);
if (strtok36_FREE != NULL) free(strtok36_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (strtok119_FREE != NULL) free(strtok119_FREE);
if (rule41_FREE != NULL) free(rule41_FREE);
if (rule67_FREE != NULL) free(rule67_FREE);
if (strtok45_FREE != NULL) free(strtok45_FREE);
if (awk2_FREE != NULL) free(awk2_FREE);
if (strtok128_FREE != NULL) free(strtok128_FREE);
if (rule50_FREE != NULL) free(rule50_FREE);
if (show_if_ip27_FREE != NULL) free(show_if_ip27_FREE);
if (strtok54_FREE != NULL) free(strtok54_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (strtok120_FREE != NULL) free(strtok120_FREE);
if (strtok63_FREE != NULL) free(strtok63_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (strtok58_FREE != NULL) free(strtok58_FREE);
if (rule63_FREE != NULL) free(rule63_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (rule89_FREE != NULL) free(rule89_FREE);
if (strtok67_FREE != NULL) free(strtok67_FREE);
if (rule72_FREE != NULL) free(rule72_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (strtok76_FREE != NULL) free(strtok76_FREE);
if (rule81_FREE != NULL) free(rule81_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok85_FREE != NULL) free(strtok85_FREE);
if (hosts5_FREE != NULL) free(hosts5_FREE);
if (rule90_FREE != NULL) free(rule90_FREE);
if (rule31_FREE != NULL) free(rule31_FREE);
if (hosts15_FREE != NULL) free(hosts15_FREE);
if (rule76_FREE != NULL) free(rule76_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);
if (show_if_ip17_FREE != NULL) free(show_if_ip17_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok101_FREE != NULL) free(strtok101_FREE);
if (rule85_FREE != NULL) free(rule85_FREE);
if (rule26_FREE != NULL) free(rule26_FREE);
if (strtok89_FREE != NULL) free(strtok89_FREE);
if (strtok110_FREE != NULL) free(strtok110_FREE);
if (hosts9_FREE != NULL) free(hosts9_FREE);
if (rule94_FREE != NULL) free(rule94_FREE);
if (rule35_FREE != NULL) free(rule35_FREE);
if (strtok72_FREE != NULL) free(strtok72_FREE);
if (strtok98_FREE != NULL) free(strtok98_FREE);
if (strtok39_FREE != NULL) free(strtok39_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (rule44_FREE != NULL) free(rule44_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok81_FREE != NULL) free(strtok81_FREE);
if (strtok105_FREE != NULL) free(strtok105_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (hosts11_FREE != NULL) free(hosts11_FREE);
if (strtok90_FREE != NULL) free(strtok90_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok114_FREE != NULL) free(strtok114_FREE);
if (rule39_FREE != NULL) free(rule39_FREE);
if (show_if_ip13_FREE != NULL) free(show_if_ip13_FREE);
if (strtok40_FREE != NULL) free(strtok40_FREE);
if (strtok123_FREE != NULL) free(strtok123_FREE);
if (rule48_FREE != NULL) free(rule48_FREE);
if (show_if_ip22_FREE != NULL) free(show_if_ip22_FREE);
if (strtok109_FREE != NULL) free(strtok109_FREE);
if (rule57_FREE != NULL) free(rule57_FREE);
if (strtok94_FREE != NULL) free(strtok94_FREE);
if (strtok35_FREE != NULL) free(strtok35_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (strtok118_FREE != NULL) free(strtok118_FREE);
if (rule40_FREE != NULL) free(rule40_FREE);
if (rule66_FREE != NULL) free(rule66_FREE);
if (strtok44_FREE != NULL) free(strtok44_FREE);
if (awk1_FREE != NULL) free(awk1_FREE);
if (strtok127_FREE != NULL) free(strtok127_FREE);
if (show_if_ip26_FREE != NULL) free(show_if_ip26_FREE);
if (strtok53_FREE != NULL) free(strtok53_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (strtok62_FREE != NULL) free(strtok62_FREE);
if (strtok48_FREE != NULL) free(strtok48_FREE);
if (rule53_FREE != NULL) free(rule53_FREE);
if (rule79_FREE != NULL) free(rule79_FREE);
if (strtok57_FREE != NULL) free(strtok57_FREE);
if (rule62_FREE != NULL) free(rule62_FREE);
if (show_if_ip9_FREE != NULL) free(show_if_ip9_FREE);
if (strtok66_FREE != NULL) free(strtok66_FREE);
if (rule71_FREE != NULL) free(rule71_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (strtok75_FREE != NULL) free(strtok75_FREE);
if (rule80_FREE != NULL) free(rule80_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (hosts4_FREE != NULL) free(hosts4_FREE);
if (rule30_FREE != NULL) free(rule30_FREE);
if (rule75_FREE != NULL) free(rule75_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (strtok79_FREE != NULL) free(strtok79_FREE);
if (show_if_ip16_FREE != NULL) free(show_if_ip16_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok100_FREE != NULL) free(strtok100_FREE);
if (rule84_FREE != NULL) free(rule84_FREE);
if (rule25_FREE != NULL) free(rule25_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (strtok88_FREE != NULL) free(strtok88_FREE);
if (hosts8_FREE != NULL) free(hosts8_FREE);
if (rule93_FREE != NULL) free(rule93_FREE);
if (rule34_FREE != NULL) free(rule34_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok71_FREE != NULL) free(strtok71_FREE);
if (strtok97_FREE != NULL) free(strtok97_FREE);
if (strtok38_FREE != NULL) free(strtok38_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (rule43_FREE != NULL) free(rule43_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok80_FREE != NULL) free(strtok80_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (strtok104_FREE != NULL) free(strtok104_FREE);
if (rule88_FREE != NULL) free(rule88_FREE);
if (rule29_FREE != NULL) free(rule29_FREE);
if (hosts10_FREE != NULL) free(hosts10_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok113_FREE != NULL) free(strtok113_FREE);
if (rule97_FREE != NULL) free(rule97_FREE);
if (rule38_FREE != NULL) free(rule38_FREE);
if (show_if_ip12_FREE != NULL) free(show_if_ip12_FREE);
if (strtok122_FREE != NULL) free(strtok122_FREE);
if (rule47_FREE != NULL) free(rule47_FREE);
if (strtok84_FREE != NULL) free(strtok84_FREE);
if (show_if_ip21_FREE != NULL) free(show_if_ip21_FREE);
if (strtok108_FREE != NULL) free(strtok108_FREE);
if (hosts14_FREE != NULL) free(hosts14_FREE);
if (rule56_FREE != NULL) free(rule56_FREE);
if (strtok93_FREE != NULL) free(strtok93_FREE);
if (strtok34_FREE != NULL) free(strtok34_FREE);
if (strtok117_FREE != NULL) free(strtok117_FREE);
if (strtok43_FREE != NULL) free(strtok43_FREE);
if (strtok126_FREE != NULL) free(strtok126_FREE);
if (show_if_ip25_FREE != NULL) free(show_if_ip25_FREE);
if (strtok52_FREE != NULL) free(strtok52_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (strtok61_FREE != NULL) free(strtok61_FREE);
if (rule69_FREE != NULL) free(rule69_FREE);
if (strtok47_FREE != NULL) free(strtok47_FREE);
if (rule52_FREE != NULL) free(rule52_FREE);
if (rule78_FREE != NULL) free(rule78_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (strtok56_FREE != NULL) free(strtok56_FREE);
if (rule61_FREE != NULL) free(rule61_FREE);
if (show_if_ip8_FREE != NULL) free(show_if_ip8_FREE);
if (strtok65_FREE != NULL) free(strtok65_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (rule70_FREE != NULL) free(rule70_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (strtok74_FREE != NULL) free(strtok74_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (rule65_FREE != NULL) free(rule65_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (strtok69_FREE != NULL) free(strtok69_FREE);
if (rule74_FREE != NULL) free(rule74_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok78_FREE != NULL) free(strtok78_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (rule83_FREE != NULL) free(rule83_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (strtok87_FREE != NULL) free(strtok87_FREE);
if (hosts7_FREE != NULL) free(hosts7_FREE);
if (rule92_FREE != NULL) free(rule92_FREE);
if (hosts17_FREE != NULL) free(hosts17_FREE);
if (rule33_FREE != NULL) free(rule33_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok70_FREE != NULL) free(strtok70_FREE);
if (strtok96_FREE != NULL) free(strtok96_FREE);
if (strtok37_FREE != NULL) free(strtok37_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (rule42_FREE != NULL) free(rule42_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (show_if_ip19_FREE != NULL) free(show_if_ip19_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (strtok103_FREE != NULL) free(strtok103_FREE);
if (rule87_FREE != NULL) free(rule87_FREE);
if (rule28_FREE != NULL) free(rule28_FREE);
if (show_if_ip28_FREE != NULL) free(show_if_ip28_FREE);
if (strtok112_FREE != NULL) free(strtok112_FREE);
if (rule96_FREE != NULL) free(rule96_FREE);
if (rule37_FREE != NULL) free(rule37_FREE);
if (show_if_ip11_FREE != NULL) free(show_if_ip11_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (rule46_FREE != NULL) free(rule46_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok83_FREE != NULL) free(strtok83_FREE);
if (show_if_ip20_FREE != NULL) free(show_if_ip20_FREE);
if (strtok107_FREE != NULL) free(strtok107_FREE);
if (hosts13_FREE != NULL) free(hosts13_FREE);
if (rule55_FREE != NULL) free(rule55_FREE);
if (strtok92_FREE != NULL) free(strtok92_FREE);
if (strtok33_FREE != NULL) free(strtok33_FREE);
if (strtok116_FREE != NULL) free(strtok116_FREE);
if (show_if_ip15_FREE != NULL) free(show_if_ip15_FREE);
if (strtok42_FREE != NULL) free(strtok42_FREE);
if (strtok125_FREE != NULL) free(strtok125_FREE);
if (show_if_ip24_FREE != NULL) free(show_if_ip24_FREE);
if (strtok51_FREE != NULL) free(strtok51_FREE);
if (rule59_FREE != NULL) free(rule59_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule68_FREE != NULL) free(rule68_FREE);
if (strtok46_FREE != NULL) free(strtok46_FREE);
if (awk3_FREE != NULL) free(awk3_FREE);
if (strtok129_FREE != NULL) free(strtok129_FREE);
if (rule51_FREE != NULL) free(rule51_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (strtok55_FREE != NULL) free(strtok55_FREE);
if (rule60_FREE != NULL) free(rule60_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (strtok121_FREE != NULL) free(strtok121_FREE);
if (strtok64_FREE != NULL) free(strtok64_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok73_FREE != NULL) free(strtok73_FREE);
if (strtok59_FREE != NULL) free(strtok59_FREE);
if (rule64_FREE != NULL) free(rule64_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (strtok68_FREE != NULL) free(strtok68_FREE);
if (rule73_FREE != NULL) free(rule73_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (strtok77_FREE != NULL) free(strtok77_FREE);
if (rule82_FREE != NULL) free(rule82_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (strtok60_FREE != NULL) free(strtok60_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (strtok86_FREE != NULL) free(strtok86_FREE);
if (hosts6_FREE != NULL) free(hosts6_FREE);
if (rule91_FREE != NULL) free(rule91_FREE);
if (rule32_FREE != NULL) free(rule32_FREE);
if (hosts16_FREE != NULL) free(hosts16_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (rule77_FREE != NULL) free(rule77_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (show_if_ip18_FREE != NULL) free(show_if_ip18_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (strtok102_FREE != NULL) free(strtok102_FREE);
if (rule86_FREE != NULL) free(rule86_FREE);
if (rule27_FREE != NULL) free(rule27_FREE);
if (strtok111_FREE != NULL) free(strtok111_FREE);
if (rule95_FREE != NULL) free(rule95_FREE);
if (rule36_FREE != NULL) free(rule36_FREE);
if (show_if_ip10_FREE != NULL) free(show_if_ip10_FREE);
if (strtok99_FREE != NULL) free(strtok99_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (rule45_FREE != NULL) free(rule45_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (strtok82_FREE != NULL) free(strtok82_FREE);
if (strtok106_FREE != NULL) free(strtok106_FREE);
if (strtok49_FREE != NULL) free(strtok49_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (hosts12_FREE != NULL) free(hosts12_FREE);
if (rule54_FREE != NULL) free(rule54_FREE);
if (strtok91_FREE != NULL) free(strtok91_FREE);
if (strtok32_FREE != NULL) free(strtok32_FREE);
if (strtok115_FREE != NULL) free(strtok115_FREE);
if (show_if_ip14_FREE != NULL) free(show_if_ip14_FREE);
if (strtok41_FREE != NULL) free(strtok41_FREE);
if (strtok124_FREE != NULL) free(strtok124_FREE);
if (rule49_FREE != NULL) free(rule49_FREE);
if (show_if_ip23_FREE != NULL) free(show_if_ip23_FREE);
if (strtok50_FREE != NULL) free(strtok50_FREE);
if (rule58_FREE != NULL) free(rule58_FREE);

//}
}


//######################################################################################################################
//## Chain EXT_ICMP_FLOOD_CHAIN - Checks all ICMP (flooded) packets for the EXTERNAL interface(s)                     ##
//######################################################################################################################
void //setup_ext_icmp_flood_chain()
setup_ext_icmp_flood_chain(void)
//{
{
  //# Log of ICMP flooding
  //######################
  //if [ "$ICMP_FLOOD_LOG" != "0" ]; then
  if  (  (strcmp(ICMP_FLOOD_LOG,"0")!=0)  )
  {
    //echo " Logging of ICMP flooding enabled"
    printf(" Logging of ICMP flooding enabled" "\n");

    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type destination-unreachable  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-unreachable flood: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type destination-unreachable  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-unreachable flood: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type destination-unreachable -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type destination-unreachable -j POST_INPUT_DROP_CHAIN");

    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type time-exceeded  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-time-exceeded fld: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type time-exceeded  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-time-exceeded fld: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type time-exceeded -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type time-exceeded -j POST_INPUT_DROP_CHAIN");

    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type parameter-problem  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-param-problem fld: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type parameter-problem  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-param-problem fld: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type parameter-problem -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type parameter-problem -j POST_INPUT_DROP_CHAIN");

#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
      //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))      
#endif
    {
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-request(ping) fld: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-request  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-request(ping) fld: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-request -j POST_INPUT_DROP_CHAIN");
    }

    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-reply  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-reply(pong) flood: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-reply  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-reply(pong) flood: \" --log-level %s", LOGLEVEL);
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-reply -j POST_INPUT_DROP_CHAIN
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type echo-reply -j POST_INPUT_DROP_CHAIN");

    //ip4tables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type source-quench  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-source-quench fld: "
    ip4tables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type source-quench  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-source-quench fld: \" --log-level %s", LOGLEVEL);
    //ip4tables -A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type source-quench -j POST_INPUT_DROP_CHAIN
    ip4tables("-A EXT_ICMP_FLOOD_CHAIN -p icmp --icmp-type source-quench -j POST_INPUT_DROP_CHAIN");

    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //ip6tables -A EXT_ICMP_FLOOD_CHAIN -p icmpv6 --icmpv6-type packet-too-big  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP-packet-too-big fld: "
      ip6tables("-A EXT_ICMP_FLOOD_CHAIN -p icmpv6 --icmpv6-type packet-too-big  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP-packet-too-big fld: \" --log-level %s", LOGLEVEL);
      //ip6tables -A EXT_ICMP_FLOOD_CHAIN -p icmpv6 --icmpv6-type packet-too-big -j POST_INPUT_DROP_CHAIN
      ip6tables("-A EXT_ICMP_FLOOD_CHAIN -p icmpv6 --icmpv6-type packet-too-big -j POST_INPUT_DROP_CHAIN");
    //fi
    }

    //# All other ICMP into the general log rule
    //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp  -m limit --limit 12/hour --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:ICMP(other) flood: "
    iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp  -m limit --limit 6/hour --limit-burst 1 -j LOG --log-prefix \"DoSICMPFlood:ICMP(other) flood: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of ICMP flooding disabled"
    printf(" Logging of ICMP flooding disabled" "\n");
  //fi
  }

  //# Drop any ICMP packets left
  //iptables -A EXT_ICMP_FLOOD_CHAIN -p icmp -j POST_INPUT_DROP_CHAIN
  iptables("-A EXT_ICMP_FLOOD_CHAIN -p icmp -j POST_INPUT_DROP_CHAIN");
//}
}


//######################################################################################################################
//## Chain EXT_OUTPUT_CHAIN - Checks all outgoing packets for the EXTERNAL interface(s)                               ##
//######################################################################################################################
void //setup_ext_output_chain()
setup_ext_output_chain(void)
//{
{
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *host = NULL;;
char *show_if_ip4_FREE = NULL;;
char *rule15_FREE = NULL;;
char *rule10_FREE = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *strtok10_FREE = NULL;;
char *local5IFS = NULL;;
char *srcips = NULL;;
char *srcip = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok5_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *rule2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *local25IFS = NULL;;
char *rule14_FREE = NULL;;
char *r_interfaces3 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *r_interfaces7 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *strtok13_FREE = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *r_DENY_UDP_OUTPUT1 = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *hosts1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *local23IFS = NULL;;
char *rule13_FREE = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_ports4 = NULL;;
char *interface = NULL;;
char *rule20_FREE = NULL;;
char *r_HOST_DENY_UDP_OUTPUT1 = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *hosts = NULL;;
char *strtok29_FREE = NULL;;
char *r_HOST_DENY_IP_OUTPUT1 = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *rule17_FREE = NULL;;
char *r_DENY_TCP_OUTPUT1 = NULL;;
char *show_if_ip1_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *rule12_FREE = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *hosts4_FREE = NULL;;
char *rule24_FREE = NULL;;
char *r_FULL_ACCESS_HOSTS1 = NULL;;
char *strtok12_FREE = NULL;;
char *local29IFS = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *strtok16_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *rule9_FREE = NULL;;
char *r_HOST_DENY_TCP_OUTPUT1 = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *rule4_FREE = NULL;;
char *r_hosts4_FREE1 = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *rule11_FREE = NULL;;
char *r_srcips1 = NULL;;
char *r_srcips2 = NULL;;
char *r_srcips3 = NULL;;
char *hosts3_FREE = NULL;;
char *r_srcips4 = NULL;;
char *rule23_FREE = NULL;;
char *r_srcips5 = NULL;;
char *r_srcips6 = NULL;;
char *strtok11_FREE = NULL;;
char *r_srcips7 = NULL;;
char *r_DENY_IP_OUTPUT1 = NULL;;
char *local30IFS = NULL;;
char *r_DENY_IP_OUTPUT2 = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *strtok23_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *rule8_FREE = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *local16IFS = NULL;;
char *strtok6_FREE = NULL;;
char *rule3_FREE = NULL;;

  //# This rule is for hostwise OUTPUT TCP blocking
  //###############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_TCP_OUTPUT; do
  local1IFS = IFS;
  if (HOST_DENY_TCP_OUTPUT != NULL) strtok1_FREE = strdup(HOST_DENY_TCP_OUTPUT);
  if (HOST_DENY_TCP_OUTPUT != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_HOST_DENY_TCP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_HOST_DENY_TCP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule1_FREE = get_ifs(rule, NULL);
    interfaces=rule1_FREE;;
    //srcips=`get_ips "$rule"`
    rule2_FREE = get_ips(rule, NULL);
    srcips=rule2_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule3_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule3_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule4_FREE = get_ports_ihp(rule, NULL);
    ports=rule4_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying $hosts for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying %s for TCP port(s): %s;" "\n", show_if_ip1_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local2IFS = IFS;
    if (hosts1_FREE != NULL) strtok2_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok2_FREE, local2IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local2IFS, &r_hosts1_FREE1))
    {
      //for port in $ports; do
      local3IFS = IFS;
      if (ports != NULL) strtok3_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok3_FREE, local3IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local3IFS, &r_ports1))
      {
        //for interface in $interfaces; do
        local4IFS = IFS;
        if (interfaces != NULL) strtok4_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok4_FREE, local4IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local4IFS, &r_interfaces1))
        {
          //for srcip in $srcips; do
          local5IFS = IFS;
          if (srcips != NULL) strtok5_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok5_FREE, local5IFS, &r_srcips1); srcip != NULL; srcip = strtok_r(NULL, local5IFS, &r_srcips1))
          {
            //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p tcp --dport $port  -m limit --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
              iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p tcp --dport %s  -m limit --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, host, port, LOGLEVEL);
            //fi
            }
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p tcp --dport $port -j DROP
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p tcp --dport %s -j DROP", interface, srcip, host, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for hostwise OUTPUT UDP blocking
  //###############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_UDP_OUTPUT; do
  local6IFS = IFS;
  if (HOST_DENY_UDP_OUTPUT != NULL) strtok6_FREE = strdup(HOST_DENY_UDP_OUTPUT);
  if (HOST_DENY_UDP_OUTPUT != NULL) for (rule = strtok_r(strtok6_FREE, local6IFS, &r_HOST_DENY_UDP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local6IFS, &r_HOST_DENY_UDP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule5_FREE = get_ifs(rule, NULL);
    interfaces=rule5_FREE;;
    //srcips=`get_ips "$rule"`
    rule6_FREE = get_ips(rule, NULL);
    srcips=rule6_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule7_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule7_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule8_FREE = get_ports_ihp(rule, NULL);
    ports=rule8_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying $hosts for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying %s for UDP port(s): %s;" "\n", show_if_ip2_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local7IFS = IFS;
    if (hosts2_FREE != NULL) strtok7_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok7_FREE, local7IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local7IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local8IFS = IFS;
      if (ports != NULL) strtok8_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok8_FREE, local8IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local8IFS, &r_ports2))
      {
        //for interface in $interfaces; do
        local9IFS = IFS;
        if (interfaces != NULL) strtok9_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok9_FREE, local9IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local9IFS, &r_interfaces2))
        {
          //for srcip in $srcips; do
          local10IFS = IFS;
          if (srcips != NULL) strtok10_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok10_FREE, local10IFS, &r_srcips2); srcip != NULL; srcip = strtok_r(NULL, local10IFS, &r_srcips2))
          {
            //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p udp --dport $port  -m limit --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
              iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p udp --dport %s  -m limit --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, host, port, LOGLEVEL);
            //fi
            }
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p udp --dport $port -j DROP
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p udp --dport %s -j DROP", interface, srcip, host, port);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for hostwise OUTPUT IP blocking
  //##############################################
  //unset IFS
  IFS = " ";
  //for rule in $HOST_DENY_IP_OUTPUT; do
  local11IFS = IFS;
  if (HOST_DENY_IP_OUTPUT != NULL) strtok11_FREE = strdup(HOST_DENY_IP_OUTPUT);
  if (HOST_DENY_IP_OUTPUT != NULL) for (rule = strtok_r(strtok11_FREE, local11IFS, &r_HOST_DENY_IP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local11IFS, &r_HOST_DENY_IP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule9_FREE = get_ifs(rule, NULL);
    interfaces=rule9_FREE;;
    //srcips=`get_ips "$rule"`
    rule10_FREE = get_ips(rule, NULL);
    srcips=rule10_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule11_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule11_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule12_FREE = get_ports_ihp(rule, NULL);
    protos=rule12_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying $hosts for IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying %s for IP protocol(s): %s;" "\n", show_if_ip3_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local12IFS = IFS;
    if (hosts3_FREE != NULL) strtok12_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok12_FREE, local12IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local12IFS, &r_hosts3_FREE1))
    {
      //for proto in $protos; do
      local13IFS = IFS;
      if (protos != NULL) strtok13_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok13_FREE, local13IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local13IFS, &r_protos1))
      {
        //for interface in $interfaces; do
        local14IFS = IFS;
        if (interfaces != NULL) strtok14_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok14_FREE, local14IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local14IFS, &r_interfaces3))
        {
          //for srcip in $srcips; do
          local15IFS = IFS;
          if (srcips != NULL) strtok15_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok15_FREE, local15IFS, &r_srcips3); srcip != NULL; srcip = strtok_r(NULL, local15IFS, &r_srcips3))
          {
            //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
            if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
            {
              //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p $proto  -m limit --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
              iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p %s  -m limit --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, host, proto, LOGLEVEL);
            //fi
            }
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -p $proto -j DROP
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -p %s -j DROP", interface, srcip, host, proto);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Adding the "full access hosts"
  //################################
  //unset IFS
  IFS = " ";
  //for rule in $FULL_ACCESS_HOSTS; do
  local16IFS = IFS;
  if (FULL_ACCESS_HOSTS != NULL) strtok16_FREE = strdup(FULL_ACCESS_HOSTS);
  if (FULL_ACCESS_HOSTS != NULL) for (rule = strtok_r(strtok16_FREE, local16IFS, &r_FULL_ACCESS_HOSTS1); rule != NULL; rule = strtok_r(NULL, local16IFS, &r_FULL_ACCESS_HOSTS1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //srcips=`get_ips "$rule"`
    rule14_FREE = get_ips(rule, NULL);
    srcips=rule14_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule15_FREE = get_hosts_ih(rule, NULL);
    hosts=rule15_FREE;;

    //echo " $(show_if_ip "$interfaces")Allowing $hosts full (outbound) access"
    show_if_ip4_FREE = show_if_ip(interfaces, NULL);
    printf(" %s Allowing %s full (outbound) access;" "\n", show_if_ip4_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts4_FREE = ip_range(hosts, NULL);
    local17IFS = IFS;
    if (hosts4_FREE != NULL) strtok17_FREE = strdup(hosts4_FREE);
    if (hosts4_FREE != NULL) for (host = strtok_r(strtok17_FREE, local17IFS, &r_hosts4_FREE1); host != NULL; host = strtok_r(NULL, local17IFS, &r_hosts4_FREE1))
    {
      //for interface in $interfaces; do
      local18IFS = IFS;
      if (interfaces != NULL) strtok18_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok18_FREE, local18IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local18IFS, &r_interfaces4))
      {
        //for srcip in $srcips; do
        local19IFS = IFS;
        if (srcips != NULL) strtok19_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok19_FREE, local19IFS, &r_srcips4); srcip != NULL; srcip = strtok_r(NULL, local19IFS, &r_srcips4))
        {
          //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -d $host -j ACCEPT
          iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -d %s -j ACCEPT", interface, srcip, host);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local OUTPUT TCP blocking
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_TCP_OUTPUT; do
  local20IFS = IFS;
  if (DENY_TCP_OUTPUT != NULL) strtok20_FREE = strdup(DENY_TCP_OUTPUT);
  if (DENY_TCP_OUTPUT != NULL) for (rule = strtok_r(strtok20_FREE, local20IFS, &r_DENY_TCP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local20IFS, &r_DENY_TCP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule16_FREE = get_ifs(rule, NULL);
    interfaces=rule16_FREE;;
    //srcips=`get_ips "$rule"`
    rule17_FREE = get_ips(rule, NULL);
    srcips=rule17_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule18_FREE = get_ports_ip(rule, NULL);
    ports=rule18_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying TCP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying TCP port(s): %s;" "\n", show_if_ip5_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local21IFS = IFS;
    if (ports != NULL) strtok21_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok21_FREE, local21IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local21IFS, &r_ports3))
    {
      //for interface in $interfaces; do
      local22IFS = IFS;
      if (interfaces != NULL) strtok22_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok22_FREE, local22IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local22IFS, &r_interfaces5))
      {
        //for srcip in $srcips; do
        local23IFS = IFS;
        if (srcips != NULL) strtok23_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok23_FREE, local23IFS, &r_srcips5); srcip != NULL; srcip = strtok_r(NULL, local23IFS, &r_srcips5))
        {
          //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p tcp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p tcp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, port, LOGLEVEL);
          //fi
          }
          //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p tcp --dport $port -j DROP
          iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p tcp --dport %s -j DROP", interface, srcip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local OUTPUT UDP blocking
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_UDP_OUTPUT; do
  local24IFS = IFS;
  if (DENY_UDP_OUTPUT != NULL) strtok24_FREE = strdup(DENY_UDP_OUTPUT);
  if (DENY_UDP_OUTPUT != NULL) for (rule = strtok_r(strtok24_FREE, local24IFS, &r_DENY_UDP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local24IFS, &r_DENY_UDP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule19_FREE = get_ifs(rule, NULL);
    interfaces=rule19_FREE;;
    //srcips=`get_ips "$rule"`
    rule20_FREE = get_ips(rule, NULL);
    srcips=rule20_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule21_FREE = get_ports_ip(rule, NULL);
    ports=rule21_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying UDP port(s): $ports"
    show_if_ip6_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying UDP port(s): %s;" "\n", show_if_ip6_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local25IFS = IFS;
    if (ports != NULL) strtok25_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok25_FREE, local25IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local25IFS, &r_ports4))
    {
      //for interface in $interfaces; do
      local26IFS = IFS;
      if (interfaces != NULL) strtok26_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok26_FREE, local26IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local26IFS, &r_interfaces6))
      {
        //for srcip in $srcips; do
        local27IFS = IFS;
        if (srcips != NULL) strtok27_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok27_FREE, local27IFS, &r_srcips6); srcip != NULL; srcip = strtok_r(NULL, local27IFS, &r_srcips6))
        {
          //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p udp --dport $port  -m limit --limit 3/m --limit-burst 5 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p udp --dport %s  -m limit --limit 3/m --limit-burst 5 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, port, LOGLEVEL);
          //fi
          }
          //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p udp --dport $port -j DROP
          iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p udp --dport %s -j DROP", interface, srcip, port);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local OUTPUT IP blocking
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $DENY_IP_OUTPUT; do
  local28IFS = IFS;
  if (DENY_IP_OUTPUT != NULL) strtok28_FREE = strdup(DENY_IP_OUTPUT);
  if (DENY_IP_OUTPUT != NULL) for (rule = strtok_r(strtok28_FREE, local28IFS, &r_DENY_IP_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local28IFS, &r_DENY_IP_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule22_FREE = get_ifs(rule, NULL);
    interfaces=rule22_FREE;;
    //srcips=`get_ips "$rule"`
    rule23_FREE = get_ips(rule, NULL);
    srcips=rule23_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule24_FREE = get_ports_ip(rule, NULL);
    protos=rule24_FREE;;

    //echo " $(show_if_ip "$interfaces" "$srcips")Denying IP protocol(s): $protos"
    show_if_ip7_FREE = show_if_ip(interfaces, srcips);
    printf(" %s Denying IP protocol(s): %s;" "\n", show_if_ip7_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $DENY_IP_OUTPUT; do
    local29IFS = IFS;
    if (DENY_IP_OUTPUT != NULL) strtok29_FREE = strdup(DENY_IP_OUTPUT);
    if (DENY_IP_OUTPUT != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_DENY_IP_OUTPUT2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_DENY_IP_OUTPUT2))
    {
      //for interface in $interfaces; do
      local30IFS = IFS;
      if (interfaces != NULL) strtok30_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok30_FREE, local30IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local30IFS, &r_interfaces7))
      {
        //for srcip in $srcips; do
        local31IFS = IFS;
        if (srcips != NULL) strtok31_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok31_FREE, local31IFS, &r_srcips7); srcip != NULL; srcip = strtok_r(NULL, local31IFS, &r_srcips7))
        {
          //if [ "$INET_OUTPUT_DENY_LOG" != "0" ]; then
          if  (  (strcmp(INET_OUTPUT_DENY_LOG,"0")!=0)  )
          {
            //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p $proto  -m limit --limit 1/s --limit-burst 1 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:INET-OUTPUT denied: "
            iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p %s  -m limit --limit 1/s --limit-burst 1 -j LOG --log-prefix \"AIF:INET-OUTPUT denied: \" --log-level %s", interface, srcip, proto, LOGLEVEL);
          //fi
          }
          //iptables -A EXT_OUTPUT_CHAIN -o $interface -s $srcip -p $proto -j DROP
          iptables("-A EXT_OUTPUT_CHAIN -o %s -s %s -p %s -j DROP", interface, srcip, proto);
        //done
        }
      //done
      }
    //done
    }
  //done
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (hosts4_FREE != NULL) free(hosts4_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//# Helper chain to catch multicast traffic
void //setup_ext_multicast_chain()
setup_ext_multicast_chain(void)
//{
{
  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //if [ "$EXTERNAL_DHCPV6_SERVER" = "1" ]; then
    if  (  (strcmp(EXTERNAL_DHCPV6_SERVER,"1")==0)  )
    {
      //# Allow Link-Local multicast to ALL-DHCP-AGENTS
      //ip6tables -A EXT_MULTICAST_CHAIN -s fe80::/10 -d ff02::1:2 -p udp --dport 547 -j ACCEPT
      ip6tables("-A EXT_MULTICAST_CHAIN -s fe80::/10 -d ff02::1:2 -p udp --dport 547 -j ACCEPT");
    //fi
    }
    //if [ "$OPEN_ICMPV6" != "0" ]; then
    if  (  (strcmp(OPEN_ICMPV6,"0")!=0)  )
    {
      //# Allow Link-Local multicast ICMP traffic
      //ip6tables -A EXT_MULTICAST_CHAIN -s fe80::/10 -p icmpv6 --icmpv6-type echo-request  -m state --state NEW  -m limit --limit 20/second --limit-burst 100 -j ACCEPT
      ip6tables("-A EXT_MULTICAST_CHAIN -s fe80::/10 -p icmpv6 --icmpv6-type echo-request  -m state --state NEW  -m limit --limit 20/second --limit-burst 100 -j ACCEPT");
    //fi
    }
  //fi
  }
  //# Note: all remaining multicast traffic will be logged and dropped
//}
}


//# Helper chain to catch broadcast traffic
void //setup_ext_broadcast_chain()
setup_ext_broadcast_chain(void)
//{
{
char *r_interfaces2 = NULL;;
char *rule6_FREE = NULL;;
char *local1IFS = NULL;;
char *local6IFS = NULL;;
char *strtok3_FREE = NULL;;
char *interface = NULL;;
char *rule5_FREE = NULL;;
char *local2IFS = NULL;;
char *destips = NULL;;
char *strtok2_FREE = NULL;;
char *rule4_FREE = NULL;;
char *r_ports1 = NULL;;
char *r_ports2 = NULL;;
char *strtok1_FREE = NULL;;
char *rule3_FREE = NULL;;
char *strtok6_FREE = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_BROADCAST_UDP_NOLOG1 = NULL;;
char *local3IFS = NULL;;
char *rule2_FREE = NULL;;
char *strtok5_FREE = NULL;;
char *local4IFS = NULL;;
char *port = NULL;;
char *show_if_ip1_FREE = NULL;;
char *ports = NULL;;
char *rule1_FREE = NULL;;
char *r_BROADCAST_TCP_NOLOG1 = NULL;;
char *rule = NULL;;
char *local5IFS = NULL;;
char *strtok4_FREE = NULL;;
char *r_interfaces1 = NULL;;
char *interfaces = NULL;;

  //# Disable logging of certain TCP broadcasts on the external interface
  //#####################################################################
  //unset IFS
  IFS = " ";
  //for rule in $BROADCAST_TCP_NOLOG; do
  local1IFS = IFS;
  if (BROADCAST_TCP_NOLOG != NULL) strtok1_FREE = strdup(BROADCAST_TCP_NOLOG);
  if (BROADCAST_TCP_NOLOG != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_BROADCAST_TCP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_BROADCAST_TCP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule1_FREE = get_ifs(rule, NULL);
    interfaces=rule1_FREE;;
    //destips=`get_ips "$rule"`
    rule2_FREE = get_ips(rule, NULL);
    destips=rule2_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule3_FREE = get_ports_ip(rule, NULL);
    ports=rule3_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Logging of external subnet broadcasts disabled for TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, destips);
    printf(" %s Logging of external subnet broadcasts disabled for TCP port(s): %s;" "\n", show_if_ip1_FREE, ports);

    //IFS=' ,'
    IFS=" ,";
    //for port in $ports; do
    local2IFS = IFS;
    if (ports != NULL) strtok2_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok2_FREE, local2IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local2IFS, &r_ports1))
    {
      //for interface in $interfaces; do
      local3IFS = IFS;
      if (interfaces != NULL) strtok3_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok3_FREE, local3IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local3IFS, &r_interfaces1))
      {
        //iptables -A EXT_BROADCAST_CHAIN -i $interface -p tcp --dport $port -j DROP
        iptables("-A EXT_BROADCAST_CHAIN -i %s -p tcp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }

  //# Disable logging of certain UDP broadcasts on the external interface
  //##########################################################################################
  //unset IFS
  IFS = " ";
  //for rule in $BROADCAST_UDP_NOLOG; do
  local4IFS = IFS;
  if (BROADCAST_UDP_NOLOG != NULL) strtok4_FREE = strdup(BROADCAST_UDP_NOLOG);
  if (BROADCAST_UDP_NOLOG != NULL) for (rule = strtok_r(strtok4_FREE, local4IFS, &r_BROADCAST_UDP_NOLOG1); rule != NULL; rule = strtok_r(NULL, local4IFS, &r_BROADCAST_UDP_NOLOG1))
  {
    //interfaces=`get_ifs "$rule"`
    rule4_FREE = get_ifs(rule, NULL);
    interfaces=rule4_FREE;;
    //destips=`get_ips "$rule"`
    rule5_FREE = get_ips(rule, NULL);
    destips=rule5_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule6_FREE = get_ports_ip(rule, NULL);
    ports=rule6_FREE;;

    //echo " $(show_if_ip "$interfaces" "$destips")Logging of external subnet broadcasts disabled for UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, destips);
    printf(" %s Logging of external subnet broadcasts disabled for UDP port(s): %s;" "\n", show_if_ip2_FREE, ports);

    //IFS=' ,'
    IFS=" ,";
    //for port in $ports; do
    local5IFS = IFS;
    if (ports != NULL) strtok5_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok5_FREE, local5IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local5IFS, &r_ports2))
    {
      //for interface in $interfaces; do
      local6IFS = IFS;
      if (interfaces != NULL) strtok6_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok6_FREE, local6IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local6IFS, &r_interfaces2))
      {
        //iptables -A EXT_BROADCAST_CHAIN -i $interface -p udp --dport $port -j DROP
        iptables("-A EXT_BROADCAST_CHAIN -i %s -p udp --dport %s -j DROP", interface, port);
      //done
      }
    //done
    }
  //done
  }
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);

//}
}


//# This creates the input logging rules
//##########################################################
void //setup_input_log()
setup_input_log(void)
//{
{
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *host = NULL;;
char *show_if_ip4_FREE = NULL;;
char *rule15_FREE = NULL;;
char *rule10_FREE = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *strtok10_FREE = NULL;;
char *local5IFS = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok5_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *rule2_FREE = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *local25IFS = NULL;;
char *rule14_FREE = NULL;;
char *r_interfaces3 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *destips = NULL;;
char *r_interfaces6 = NULL;;
char *r_interfaces7 = NULL;;
char *r_LOG_HOST_INPUT_TCP1 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *strtok13_FREE = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *r_LOG_HOST_INPUT_UDP1 = NULL;;
char *hosts1_FREE = NULL;;
char *rule1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *local23IFS = NULL;;
char *rule13_FREE = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_ports4 = NULL;;
char *destip = NULL;;
char *interface = NULL;;
char *rule20_FREE = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *r_LOG_INPUT_TCP1 = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *hosts = NULL;;
char *strtok29_FREE = NULL;;
char *local9IFS = NULL;;
char *r_LOG_INPUT_IP1 = NULL;;
char *rule5_FREE = NULL;;
char *strtok3_FREE = NULL;;
char *r_destips1 = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *r_destips2 = NULL;;
char *rule17_FREE = NULL;;
char *r_destips3 = NULL;;
char *r_destips4 = NULL;;
char *r_destips5 = NULL;;
char *show_if_ip1_FREE = NULL;;
char *r_destips6 = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *rule12_FREE = NULL;;
char *local1IFS = NULL;;
char *r_destips7 = NULL;;
char *r_LOG_INPUT_UDP1 = NULL;;
char *strtok7_FREE = NULL;;
char *hosts4_FREE = NULL;;
char *rule24_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *local29IFS = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *strtok16_FREE = NULL;;
char *r_LOG_HOST_INPUT_IP1 = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *r_LOG_HOST_INPUT1 = NULL;;
char *rule9_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *rule4_FREE = NULL;;
char *r_hosts4_FREE1 = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *rule11_FREE = NULL;;
char *hosts3_FREE = NULL;;
char *rule23_FREE = NULL;;
char *strtok11_FREE = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *strtok23_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *rule8_FREE = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *local16IFS = NULL;;
char *strtok6_FREE = NULL;;
char *rule3_FREE = NULL;;

  //# This rule is for local INPUT TCP watching
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_INPUT_TCP; do
  local1IFS = IFS;
  if (LOG_INPUT_TCP != NULL) strtok1_FREE = strdup(LOG_INPUT_TCP);
  if (LOG_INPUT_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_LOG_INPUT_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_LOG_INPUT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule1_FREE = get_ifs(rule, NULL);
    interfaces=rule1_FREE;;
    //destips=`get_ips "$rule"`
    rule2_FREE = get_ips(rule, NULL);
    destips=rule2_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule3_FREE = get_ports_ip(rule, NULL);
    ports=rule3_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming TCP port(s): %s;" "\n", show_if_ip1_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local2IFS = IFS;
    if (ports != NULL) strtok2_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok2_FREE, local2IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local2IFS, &r_ports1))
    {
      //for destip in $destips; do
      local3IFS = IFS;
      if (destips != NULL) strtok3_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok3_FREE, local3IFS, &r_destips1); destip != NULL; destip = strtok_r(NULL, local3IFS, &r_destips1))
      {
        //for interface in $interfaces; do
        local4IFS = IFS;
        if (interfaces != NULL) strtok4_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok4_FREE, local4IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local4IFS, &r_interfaces1))
        {
          //iptables -A INPUT -i $interface -d $destip -p tcp --dport $port -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:TCP INPUT log: "
          iptables("-A INPUT -i %s -d %s -p tcp --dport %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:TCP INPUT log: \" --log-level %s", interface, destip, port, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# This rule is for local INPUT UDP watching
  //###########################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_INPUT_UDP; do
  local5IFS = IFS;
  if (LOG_INPUT_UDP != NULL) strtok5_FREE = strdup(LOG_INPUT_UDP);
  if (LOG_INPUT_UDP != NULL) for (rule = strtok_r(strtok5_FREE, local5IFS, &r_LOG_INPUT_UDP1); rule != NULL; rule = strtok_r(NULL, local5IFS, &r_LOG_INPUT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule4_FREE = get_ifs(rule, NULL);
    interfaces=rule4_FREE;;
    //destips=`get_ips "$rule"`
    rule5_FREE = get_ips(rule, NULL);
    destips=rule5_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule6_FREE = get_ports_ip(rule, NULL);
    ports=rule6_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming UDP port(s): %s;" "\n", show_if_ip2_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local6IFS = IFS;
    if (ports != NULL) strtok6_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok6_FREE, local6IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local6IFS, &r_ports2))
    {
      //for destip in $destips; do
      local7IFS = IFS;
      if (destips != NULL) strtok7_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok7_FREE, local7IFS, &r_destips2); destip != NULL; destip = strtok_r(NULL, local7IFS, &r_destips2))
      {
        //for interface in $interfaces; do
        local8IFS = IFS;
        if (interfaces != NULL) strtok8_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok8_FREE, local8IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local8IFS, &r_interfaces2))
        {
          //iptables -A INPUT -i $interface -d $destip -p udp --dport $port -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UDP INPUT log: "
          iptables("-A INPUT -i %s -d %s -p udp --dport %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:UDP INPUT log: \" --log-level %s", interface, destip, port, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local INPUT IP watching
  //##########################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_INPUT_IP; do
  local9IFS = IFS;
  if (LOG_INPUT_IP != NULL) strtok9_FREE = strdup(LOG_INPUT_IP);
  if (LOG_INPUT_IP != NULL) for (rule = strtok_r(strtok9_FREE, local9IFS, &r_LOG_INPUT_IP1); rule != NULL; rule = strtok_r(NULL, local9IFS, &r_LOG_INPUT_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule7_FREE = get_ifs(rule, NULL);
    interfaces=rule7_FREE;;
    //destips=`get_ips "$rule"`
    rule8_FREE = get_ips(rule, NULL);
    destips=rule8_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule9_FREE = get_ports_ip(rule, NULL);
    protos=rule9_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming IP protocol(s): %s;" "\n", show_if_ip3_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local10IFS = IFS;
    if (protos != NULL) strtok10_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok10_FREE, local10IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local10IFS, &r_protos1))
    {
      //for destip in $destips; do
      local11IFS = IFS;
      if (destips != NULL) strtok11_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok11_FREE, local11IFS, &r_destips3); destip != NULL; destip = strtok_r(NULL, local11IFS, &r_destips3))
      {
        //for interface in $interfaces; do
        local12IFS = IFS;
        if (interfaces != NULL) strtok12_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok12_FREE, local12IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local12IFS, &r_interfaces3))
        {
          //iptables -A INPUT -i $interface -d $destip -p $proto -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IP INPUT log: "
          iptables("-A INPUT -i %s -d %s -p %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:IP INPUT log: \" --log-level %s", interface, destip, proto, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Hostwise logging of input connection attempts
  //###############################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_INPUT; do
  local13IFS = IFS;
  if (LOG_HOST_INPUT != NULL) strtok13_FREE = strdup(LOG_HOST_INPUT);
  if (LOG_HOST_INPUT != NULL) for (rule = strtok_r(strtok13_FREE, local13IFS, &r_LOG_HOST_INPUT1); rule != NULL; rule = strtok_r(NULL, local13IFS, &r_LOG_HOST_INPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule10_FREE = get_ifs(rule, NULL);
    interfaces=rule10_FREE;;
    //destips=`get_ips "$rule"`
    rule11_FREE = get_ips(rule, NULL);
    destips=rule11_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule12_FREE = get_hosts_ih(rule, NULL);
    hosts=rule12_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming connections of: $hosts"
    show_if_ip4_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming connections of: %s;" "\n", show_if_ip4_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local14IFS = IFS;
    if (hosts1_FREE != NULL) strtok14_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok14_FREE, local14IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local14IFS, &r_hosts1_FREE1))
    {
      //for destip in $destips; do
      local15IFS = IFS;
      if (destips != NULL) strtok15_FREE = strdup(destips);
      if (destips != NULL) for (destip = strtok_r(strtok15_FREE, local15IFS, &r_destips4); destip != NULL; destip = strtok_r(NULL, local15IFS, &r_destips4))
      {
        //for interface in $interfaces; do
        local16IFS = IFS;
        if (interfaces != NULL) strtok16_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok16_FREE, local16IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local16IFS, &r_interfaces4))
        {
          //iptables -A INPUT -i $interface -s $host -d $destip -m state --state NEW  -m limit --limit 12/m --limit-burst 50  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise INPUT log: "
          iptables("-A INPUT -i %s -s %s -d %s -m state --state NEW  -m limit --limit 12/m --limit-burst 50  -j LOG --log-prefix \"AIF:Hostwise INPUT log: \" --log-level %s", interface, host, destip, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Hostwise logging of certain TCP port connection attempts
  //##########################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_INPUT_TCP; do
  local17IFS = IFS;
  if (LOG_HOST_INPUT_TCP != NULL) strtok17_FREE = strdup(LOG_HOST_INPUT_TCP);
  if (LOG_HOST_INPUT_TCP != NULL) for (rule = strtok_r(strtok17_FREE, local17IFS, &r_LOG_HOST_INPUT_TCP1); rule != NULL; rule = strtok_r(NULL, local17IFS, &r_LOG_HOST_INPUT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //destips=`get_ips "$rule"`
    rule14_FREE = get_ips(rule, NULL);
    destips=rule14_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule15_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule15_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule16_FREE = get_ports_ihp(rule, NULL);
    ports=rule16_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming connections of $hosts to TCP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming connections of %s to TCP port(s): %s;" "\n", show_if_ip5_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local18IFS = IFS;
    if (hosts2_FREE != NULL) strtok18_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok18_FREE, local18IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local18IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local19IFS = IFS;
      if (ports != NULL) strtok19_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local19IFS, &r_ports3))
      {
        //for destip in $destips; do
        local20IFS = IFS;
        if (destips != NULL) strtok20_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok20_FREE, local20IFS, &r_destips5); destip != NULL; destip = strtok_r(NULL, local20IFS, &r_destips5))
        {
          //for interface in $interfaces; do
          local21IFS = IFS;
          if (interfaces != NULL) strtok21_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok21_FREE, local21IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local21IFS, &r_interfaces5))
          {
            //iptables -A INPUT -i $interface -s $host -d $destip -p tcp --dport $port -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise TCP log (IN): "
            iptables("-A INPUT -i %s -s %s -d %s -p tcp --dport %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Hostwise TCP log (IN): \" --log-level %s", interface, host, destip, port, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Hostwise logging of certain UDP port connection attempts
  //##########################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_INPUT_UDP; do
  local22IFS = IFS;
  if (LOG_HOST_INPUT_UDP != NULL) strtok22_FREE = strdup(LOG_HOST_INPUT_UDP);
  if (LOG_HOST_INPUT_UDP != NULL) for (rule = strtok_r(strtok22_FREE, local22IFS, &r_LOG_HOST_INPUT_UDP1); rule != NULL; rule = strtok_r(NULL, local22IFS, &r_LOG_HOST_INPUT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule17_FREE = get_ifs(rule, NULL);
    interfaces=rule17_FREE;;
    //destips=`get_ips "$rule"`
    rule18_FREE = get_ips(rule, NULL);
    destips=rule18_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule19_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule19_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule20_FREE = get_ports_ihp(rule, NULL);
    ports=rule20_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming connections of $hosts to UDP port(s): $ports"
    show_if_ip6_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming connections of %s to UDP port(s): %s;" "\n", show_if_ip6_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local23IFS = IFS;
    if (hosts3_FREE != NULL) strtok23_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok23_FREE, local23IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local23IFS, &r_hosts3_FREE1))
    {
      //for port in $ports; do
      local24IFS = IFS;
      if (ports != NULL) strtok24_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports4))
      {
        //for destip in $destips; do
        local25IFS = IFS;
        if (destips != NULL) strtok25_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok25_FREE, local25IFS, &r_destips6); destip != NULL; destip = strtok_r(NULL, local25IFS, &r_destips6))
        {
          //for interface in $interfaces; do
          local26IFS = IFS;
          if (interfaces != NULL) strtok26_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok26_FREE, local26IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local26IFS, &r_interfaces6))
          {
            //iptables -A INPUT -i $interface -s $host -d $destip -p udp --dport $port -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise UDP INPUT log: "
            iptables("-A INPUT -i %s -s %s -d %s -p udp --dport %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Hostwise UDP INPUT log: \" --log-level %s", interface, host, destip, port, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Hostwise logging of certain IP protocols connection attempts
  //##############################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_INPUT_IP; do
  local27IFS = IFS;
  if (LOG_HOST_INPUT_IP != NULL) strtok27_FREE = strdup(LOG_HOST_INPUT_IP);
  if (LOG_HOST_INPUT_IP != NULL) for (rule = strtok_r(strtok27_FREE, local27IFS, &r_LOG_HOST_INPUT_IP1); rule != NULL; rule = strtok_r(NULL, local27IFS, &r_LOG_HOST_INPUT_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule21_FREE = get_ifs(rule, NULL);
    interfaces=rule21_FREE;;
    //destips=`get_ips "$rule"`
    rule22_FREE = get_ips(rule, NULL);
    destips=rule22_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule23_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule23_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule24_FREE = get_ports_ihp(rule, NULL);
    protos=rule24_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Logging incoming connections of $hosts to IP protocol(s): $protos"
    show_if_ip7_FREE = show_if_ip(interfaces, destips);
    printf("%s Logging incoming connections of %s to IP protocol(s): %s;" "\n", show_if_ip7_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts4_FREE = ip_range(hosts, NULL);
    local28IFS = IFS;
    if (hosts4_FREE != NULL) strtok28_FREE = strdup(hosts4_FREE);
    if (hosts4_FREE != NULL) for (host = strtok_r(strtok28_FREE, local28IFS, &r_hosts4_FREE1); host != NULL; host = strtok_r(NULL, local28IFS, &r_hosts4_FREE1))
    {
      //for proto in $protos; do
      local29IFS = IFS;
      if (protos != NULL) strtok29_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_protos2))
      {
        //for destip in $destips; do
        local30IFS = IFS;
        if (destips != NULL) strtok30_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok30_FREE, local30IFS, &r_destips7); destip != NULL; destip = strtok_r(NULL, local30IFS, &r_destips7))
        {
          //for interface in $interfaces; do
          local31IFS = IFS;
          if (interfaces != NULL) strtok31_FREE = strdup(interfaces);
          if (interfaces != NULL) for (interface = strtok_r(strtok31_FREE, local31IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local31IFS, &r_interfaces7))
          {
            //iptables -A INPUT -i $interface -s $host -d $destip -p $proto -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise IP INPUT log: "
            iptables("-A INPUT -i %s -s %s -d %s -p %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Hostwise IP INPUT log: \" --log-level %s", interface, host, destip, proto, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (hosts4_FREE != NULL) free(hosts4_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//# This creates the output logging rules
//##########################################################
void //setup_output_log()
setup_output_log(void)
//{
{
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *host = NULL;;
char *show_if_ip4_FREE = NULL;;
char *rule15_FREE = NULL;;
char *rule10_FREE = NULL;;
char *local15IFS = NULL;;
char *rule22_FREE = NULL;;
char *rule19_FREE = NULL;;
char *strtok10_FREE = NULL;;
char *local5IFS = NULL;;
char *srcips = NULL;;
char *r_LOG_OUTPUT_UDP1 = NULL;;
char *srcip = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *strtok14_FREE = NULL;;
char *rule7_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *strtok5_FREE = NULL;;
char *hosts2_FREE = NULL;;
char *rule2_FREE = NULL;;
char *r_LOG_HOST_OUTPUT_IP1 = NULL;;
char *proto = NULL;;
char *ports = NULL;;
char *local4IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *local25IFS = NULL;;
char *rule14_FREE = NULL;;
char *r_interfaces3 = NULL;;
char *r_interfaces4 = NULL;;
char *strtok9_FREE = NULL;;
char *r_interfaces5 = NULL;;
char *r_interfaces6 = NULL;;
char *r_interfaces7 = NULL;;
char *local13IFS = NULL;;
char *rule21_FREE = NULL;;
char *rule18_FREE = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *local24IFS = NULL;;
char *r_LOG_OUTPUT_IP1 = NULL;;
char *r_hosts1_FREE1 = NULL;;
char *r_hosts3_FREE1 = NULL;;
char *strtok13_FREE = NULL;;
char *rule = NULL;;
char *rule6_FREE = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *hosts1_FREE = NULL;;
char *rule1_FREE = NULL;;
char *show_if_ip7_FREE = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_ports1 = NULL;;
char *local23IFS = NULL;;
char *rule13_FREE = NULL;;
char *r_protos1 = NULL;;
char *r_ports2 = NULL;;
char *r_protos2 = NULL;;
char *r_ports3 = NULL;;
char *strtok8_FREE = NULL;;
char *r_ports4 = NULL;;
char *r_LOG_HOST_OUTPUT_TCP1 = NULL;;
char *interface = NULL;;
char *rule20_FREE = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *port = NULL;;
char *local2IFS = NULL;;
char *hosts = NULL;;
char *strtok29_FREE = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *r_LOG_HOST_OUTPUT_UDP1 = NULL;;
char *strtok3_FREE = NULL;;
char *show_if_ip6_FREE = NULL;;
char *local11IFS = NULL;;
char *rule17_FREE = NULL;;
char *show_if_ip1_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *rule12_FREE = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *hosts4_FREE = NULL;;
char *rule24_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *local29IFS = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *strtok16_FREE = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *rule9_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *rule4_FREE = NULL;;
char *r_hosts4_FREE1 = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *r_LOG_HOST_OUTPUT1 = NULL;;
char *show_if_ip5_FREE = NULL;;
char *rule16_FREE = NULL;;
char *rule11_FREE = NULL;;
char *r_srcips1 = NULL;;
char *r_srcips2 = NULL;;
char *hosts3_FREE = NULL;;
char *r_srcips3 = NULL;;
char *r_srcips4 = NULL;;
char *rule23_FREE = NULL;;
char *r_srcips5 = NULL;;
char *r_srcips6 = NULL;;
char *strtok11_FREE = NULL;;
char *r_srcips7 = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *strtok23_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *rule8_FREE = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *local16IFS = NULL;;
char *strtok6_FREE = NULL;;
char *r_LOG_OUTPUT_TCP1 = NULL;;
char *rule3_FREE = NULL;;

  //# This rule is for local OUTPUT TCP watching
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_OUTPUT_TCP; do
  local1IFS = IFS;
  if (LOG_OUTPUT_TCP != NULL) strtok1_FREE = strdup(LOG_OUTPUT_TCP);
  if (LOG_OUTPUT_TCP != NULL) for (rule = strtok_r(strtok1_FREE, local1IFS, &r_LOG_OUTPUT_TCP1); rule != NULL; rule = strtok_r(NULL, local1IFS, &r_LOG_OUTPUT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule1_FREE = get_ifs(rule, NULL);
    interfaces=rule1_FREE;;
    //srcips=`get_ips "$rule"`
    rule2_FREE = get_ips(rule, NULL);
    srcips=rule2_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule3_FREE = get_ports_ip(rule, NULL);
    ports=rule3_FREE;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing TCP port(s): $ports"
    show_if_ip1_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing TCP port(s): %s;" "\n", show_if_ip1_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local2IFS = IFS;
    if (ports != NULL) strtok2_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok2_FREE, local2IFS, &r_ports1); port != NULL; port = strtok_r(NULL, local2IFS, &r_ports1))
    {
      //for interface in $interfaces; do
      local3IFS = IFS;
      if (interfaces != NULL) strtok3_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok3_FREE, local3IFS, &r_interfaces1); interface != NULL; interface = strtok_r(NULL, local3IFS, &r_interfaces1))
      {
        //for srcip in $srcips; do
        local4IFS = IFS;
        if (srcips != NULL) strtok4_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok4_FREE, local4IFS, &r_srcips1); srcip != NULL; srcip = strtok_r(NULL, local4IFS, &r_srcips1))
        {
          //iptables -A OUTPUT -o $interface -s $srcip -p tcp --dport $port -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:TCP OUTPUT log: "
          iptables("-A OUTPUT -o %s -s %s -p tcp --dport %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:TCP OUTPUT log: \" --log-level %s", interface, srcip, port, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local OUTPUT UDP watching
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_OUTPUT_UDP; do
  local5IFS = IFS;
  if (LOG_OUTPUT_UDP != NULL) strtok5_FREE = strdup(LOG_OUTPUT_UDP);
  if (LOG_OUTPUT_UDP != NULL) for (rule = strtok_r(strtok5_FREE, local5IFS, &r_LOG_OUTPUT_UDP1); rule != NULL; rule = strtok_r(NULL, local5IFS, &r_LOG_OUTPUT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule4_FREE = get_ifs(rule, NULL);
    interfaces=rule4_FREE;;
    //srcips=`get_ips "$rule"`
    rule5_FREE = get_ips(rule, NULL);
    srcips=rule5_FREE;;
    //ports=`get_ports_ip "$rule"`
    rule6_FREE = get_ports_ip(rule, NULL);
    ports=rule6_FREE;;

    //echo "$(show_if_ip "$interfaces")Logging outgoing UDP port(s): $ports"
    show_if_ip2_FREE = show_if_ip(interfaces, NULL);
    printf("%s Logging outgoing UDP port(s): %s;" "\n", show_if_ip2_FREE, ports);

    //IFS=','
    IFS=",";
    //for port in $ports; do
    local6IFS = IFS;
    if (ports != NULL) strtok6_FREE = strdup(ports);
    if (ports != NULL) for (port = strtok_r(strtok6_FREE, local6IFS, &r_ports2); port != NULL; port = strtok_r(NULL, local6IFS, &r_ports2))
    {
      //for interface in $interfaces; do
      local7IFS = IFS;
      if (interfaces != NULL) strtok7_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok7_FREE, local7IFS, &r_interfaces2); interface != NULL; interface = strtok_r(NULL, local7IFS, &r_interfaces2))
      {
        //for srcip in $srcips; do
        local8IFS = IFS;
        if (srcips != NULL) strtok8_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok8_FREE, local8IFS, &r_srcips2); srcip != NULL; srcip = strtok_r(NULL, local8IFS, &r_srcips2))
        {
          //iptables -A OUTPUT -o $interface -s $srcip -p udp --dport $port -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:UDP OUTPUT log: "
          iptables("-A OUTPUT -o %s -s %s -p udp --dport %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:UDP OUTPUT log: \" --log-level %s", interface, srcip, port, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# This rule is for local OUTPUT IP watching
  //###########################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_OUTPUT_IP; do
  local9IFS = IFS;
  if (LOG_OUTPUT_IP != NULL) strtok9_FREE = strdup(LOG_OUTPUT_IP);
  if (LOG_OUTPUT_IP != NULL) for (rule = strtok_r(strtok9_FREE, local9IFS, &r_LOG_OUTPUT_IP1); rule != NULL; rule = strtok_r(NULL, local9IFS, &r_LOG_OUTPUT_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule7_FREE = get_ifs(rule, NULL);
    interfaces=rule7_FREE;;
    //srcips=`get_ips "$rule"`
    rule8_FREE = get_ips(rule, NULL);
    srcips=rule8_FREE;;
    //protos=`get_ports_ip "$rule"`
    rule9_FREE = get_ports_ip(rule, NULL);
    protos=rule9_FREE;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing IP protocol(s): $protos"
    show_if_ip3_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing IP protocol(s): %s;" "\n", show_if_ip3_FREE, protos);

    //IFS=','
    IFS=",";
    //for proto in $protos; do
    local10IFS = IFS;
    if (protos != NULL) strtok10_FREE = strdup(protos);
    if (protos != NULL) for (proto = strtok_r(strtok10_FREE, local10IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local10IFS, &r_protos1))
    {
      //for interface in $interfaces; do
      local11IFS = IFS;
      if (interfaces != NULL) strtok11_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok11_FREE, local11IFS, &r_interfaces3); interface != NULL; interface = strtok_r(NULL, local11IFS, &r_interfaces3))
      {
        //for srcip in $srcips; do
        local12IFS = IFS;
        if (srcips != NULL) strtok12_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok12_FREE, local12IFS, &r_srcips3); srcip != NULL; srcip = strtok_r(NULL, local12IFS, &r_srcips3))
        {
          //iptables -A OUTPUT -o $interface -s $srcip -p $proto -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:IP OUTPUT log: "
          iptables("-A OUTPUT -o %s -s %s -p %s -m state --state NEW -m limit  --limit 3/m --limit-burst 15 -j LOG --log-prefix \"AIF:IP OUTPUT log: \" --log-level %s", interface, srcip, proto, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Hostwise logging of output connection attempts
  //################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_OUTPUT; do
  local13IFS = IFS;
  if (LOG_HOST_OUTPUT != NULL) strtok13_FREE = strdup(LOG_HOST_OUTPUT);
  if (LOG_HOST_OUTPUT != NULL) for (rule = strtok_r(strtok13_FREE, local13IFS, &r_LOG_HOST_OUTPUT1); rule != NULL; rule = strtok_r(NULL, local13IFS, &r_LOG_HOST_OUTPUT1))
  {
    //interfaces=`get_ifs "$rule"`
    rule10_FREE = get_ifs(rule, NULL);
    interfaces=rule10_FREE;;
    //srcips=`get_ips "$rule"`
    rule11_FREE = get_ips(rule, NULL);
    srcips=rule11_FREE;;
    //hosts=`get_hosts_ih "$rule"`
    rule12_FREE = get_hosts_ih(rule, NULL);
    hosts=rule12_FREE;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing connections to: $hosts"
    show_if_ip4_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing connections to: %s;" "\n", show_if_ip4_FREE, hosts);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts1_FREE = ip_range(hosts, NULL);
    local14IFS = IFS;
    if (hosts1_FREE != NULL) strtok14_FREE = strdup(hosts1_FREE);
    if (hosts1_FREE != NULL) for (host = strtok_r(strtok14_FREE, local14IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local14IFS, &r_hosts1_FREE1))
    {
      //for interface in $interfaces; do
      local15IFS = IFS;
      if (interfaces != NULL) strtok15_FREE = strdup(interfaces);
      if (interfaces != NULL) for (interface = strtok_r(strtok15_FREE, local15IFS, &r_interfaces4); interface != NULL; interface = strtok_r(NULL, local15IFS, &r_interfaces4))
      {
        //for srcip in $srcips; do
        local16IFS = IFS;
        if (srcips != NULL) strtok16_FREE = strdup(srcips);
        if (srcips != NULL) for (srcip = strtok_r(strtok16_FREE, local16IFS, &r_srcips4); srcip != NULL; srcip = strtok_r(NULL, local16IFS, &r_srcips4))
        {
          //iptables -A OUTPUT -o $interface -s $srcip -d $host -m state --state NEW  -m limit --limit 12/m --limit-burst 50  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Hostwise OUTPUT log: "
          iptables("-A OUTPUT -o %s -s %s -d %s -m state --state NEW  -m limit --limit 12/m --limit-burst 50  -j LOG --log-prefix \"AIF:Hostwise OUTPUT log: \" --log-level %s", interface, srcip, host, LOGLEVEL);
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Hostwise logging of certain TCP port connection attempts
  //##########################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_OUTPUT_TCP; do
  local17IFS = IFS;
  if (LOG_HOST_OUTPUT_TCP != NULL) strtok17_FREE = strdup(LOG_HOST_OUTPUT_TCP);
  if (LOG_HOST_OUTPUT_TCP != NULL) for (rule = strtok_r(strtok17_FREE, local17IFS, &r_LOG_HOST_OUTPUT_TCP1); rule != NULL; rule = strtok_r(NULL, local17IFS, &r_LOG_HOST_OUTPUT_TCP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule13_FREE = get_ifs(rule, NULL);
    interfaces=rule13_FREE;;
    //srcips=`get_ips "$rule"`
    rule14_FREE = get_ips(rule, NULL);
    srcips=rule14_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule15_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule15_FREE;;
    //ports=`get_ports_ihp "$rule"` 
    rule16_FREE = get_ports_ihp(rule, NULL);
    ports=rule16_FREE ;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing connections of $hosts to TCP port(s): $ports"
    show_if_ip5_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing connections of %s to TCP port(s): %s;" "\n", show_if_ip5_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts2_FREE = ip_range(hosts, NULL);
    local18IFS = IFS;
    if (hosts2_FREE != NULL) strtok18_FREE = strdup(hosts2_FREE);
    if (hosts2_FREE != NULL) for (host = strtok_r(strtok18_FREE, local18IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local18IFS, &r_hosts2_FREE1))
    {
      //for port in $ports; do
      local19IFS = IFS;
      if (ports != NULL) strtok19_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok19_FREE, local19IFS, &r_ports3); port != NULL; port = strtok_r(NULL, local19IFS, &r_ports3))
      {
        //for interface in $interfaces; do
        local20IFS = IFS;
        if (interfaces != NULL) strtok20_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok20_FREE, local20IFS, &r_interfaces5); interface != NULL; interface = strtok_r(NULL, local20IFS, &r_interfaces5))
        {
          //for srcip in $srcips; do
          local21IFS = IFS;
          if (srcips != NULL) strtok21_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok21_FREE, local21IFS, &r_srcips5); srcip != NULL; srcip = strtok_r(NULL, local21IFS, &r_srcips5))
          {
            //iptables -A OUTPUT -o $interface -s $srcip -d $host -p tcp --dport $port -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host TCP log (OUT): "
            iptables("-A OUTPUT -o %s -s %s -d %s -p tcp --dport %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Host TCP log (OUT): \" --log-level %s", interface, srcip, host, port, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }


  //# Hostwise logging of certain UDP port connection attempts
  //##########################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_OUTPUT_UDP; do
  local22IFS = IFS;
  if (LOG_HOST_OUTPUT_UDP != NULL) strtok22_FREE = strdup(LOG_HOST_OUTPUT_UDP);
  if (LOG_HOST_OUTPUT_UDP != NULL) for (rule = strtok_r(strtok22_FREE, local22IFS, &r_LOG_HOST_OUTPUT_UDP1); rule != NULL; rule = strtok_r(NULL, local22IFS, &r_LOG_HOST_OUTPUT_UDP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule17_FREE = get_ifs(rule, NULL);
    interfaces=rule17_FREE;;
    //srcips=`get_ips "$rule"`
    rule18_FREE = get_ips(rule, NULL);
    srcips=rule18_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule19_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule19_FREE;;
    //ports=`get_ports_ihp "$rule"`
    rule20_FREE = get_ports_ihp(rule, NULL);
    ports=rule20_FREE;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing connections of $hosts to UDP port(s): $ports"
    show_if_ip6_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing connections of %s to UDP port(s): %s;" "\n", show_if_ip6_FREE, hosts, ports);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts3_FREE = ip_range(hosts, NULL);
    local23IFS = IFS;
    if (hosts3_FREE != NULL) strtok23_FREE = strdup(hosts3_FREE);
    if (hosts3_FREE != NULL) for (host = strtok_r(strtok23_FREE, local23IFS, &r_hosts3_FREE1); host != NULL; host = strtok_r(NULL, local23IFS, &r_hosts3_FREE1))
    {
      //for port in $ports; do
      local24IFS = IFS;
      if (ports != NULL) strtok24_FREE = strdup(ports);
      if (ports != NULL) for (port = strtok_r(strtok24_FREE, local24IFS, &r_ports4); port != NULL; port = strtok_r(NULL, local24IFS, &r_ports4))
      {
        //for interface in $interfaces; do
        local25IFS = IFS;
        if (interfaces != NULL) strtok25_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok25_FREE, local25IFS, &r_interfaces6); interface != NULL; interface = strtok_r(NULL, local25IFS, &r_interfaces6))
        {
          //for srcip in $srcips; do
          local26IFS = IFS;
          if (srcips != NULL) strtok26_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok26_FREE, local26IFS, &r_srcips6); srcip != NULL; srcip = strtok_r(NULL, local26IFS, &r_srcips6))
          {
            //iptables -A OUTPUT -o $interface -s $srcip -d $host -p udp --dport $port -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host UDP log (OUT): "
            iptables("-A OUTPUT -o %s -s %s -d %s -p udp --dport %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Host UDP log (OUT): \" --log-level %s", interface, srcip, host, port, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  //# Hostwise logging of certain IP protocols connection attempts
  //##############################################################
  //unset IFS
  IFS = " ";
  //for rule in $LOG_HOST_OUTPUT_IP; do
  local27IFS = IFS;
  if (LOG_HOST_OUTPUT_IP != NULL) strtok27_FREE = strdup(LOG_HOST_OUTPUT_IP);
  if (LOG_HOST_OUTPUT_IP != NULL) for (rule = strtok_r(strtok27_FREE, local27IFS, &r_LOG_HOST_OUTPUT_IP1); rule != NULL; rule = strtok_r(NULL, local27IFS, &r_LOG_HOST_OUTPUT_IP1))
  {
    //interfaces=`get_ifs "$rule"`
    rule21_FREE = get_ifs(rule, NULL);
    interfaces=rule21_FREE;;
    //srcips=`get_ips "$rule"`
    rule22_FREE = get_ips(rule, NULL);
    srcips=rule22_FREE;;
    //hosts=`get_hosts_ihp "$rule"`
    rule23_FREE = get_hosts_ihp(rule, NULL);
    hosts=rule23_FREE;;
    //protos=`get_ports_ihp "$rule"`
    rule24_FREE = get_ports_ihp(rule, NULL);
    protos=rule24_FREE;;

    //echo "$(show_if_ip "$interfaces" "$srcips")Logging outgoing connections of $hosts to IP protocol(s): $protos"
    show_if_ip7_FREE = show_if_ip(interfaces, srcips);
    printf("%s Logging outgoing connections of %s to IP protocol(s): %s;" "\n", show_if_ip7_FREE, hosts, protos);

    //IFS=','
    IFS=",";
    //for host in `ip_range "$hosts"`; do
    hosts4_FREE = ip_range(hosts, NULL);
    local28IFS = IFS;
    if (hosts4_FREE != NULL) strtok28_FREE = strdup(hosts4_FREE);
    if (hosts4_FREE != NULL) for (host = strtok_r(strtok28_FREE, local28IFS, &r_hosts4_FREE1); host != NULL; host = strtok_r(NULL, local28IFS, &r_hosts4_FREE1))
    {
      //for proto in $protos; do
      local29IFS = IFS;
      if (protos != NULL) strtok29_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok29_FREE, local29IFS, &r_protos2); proto != NULL; proto = strtok_r(NULL, local29IFS, &r_protos2))
      {
        //for interface in $interfaces; do
        local30IFS = IFS;
        if (interfaces != NULL) strtok30_FREE = strdup(interfaces);
        if (interfaces != NULL) for (interface = strtok_r(strtok30_FREE, local30IFS, &r_interfaces7); interface != NULL; interface = strtok_r(NULL, local30IFS, &r_interfaces7))
        {
          //for srcip in $srcips; do
          local31IFS = IFS;
          if (srcips != NULL) strtok31_FREE = strdup(srcips);
          if (srcips != NULL) for (srcip = strtok_r(strtok31_FREE, local31IFS, &r_srcips7); srcip != NULL; srcip = strtok_r(NULL, local31IFS, &r_srcips7))
          {
            //iptables -A OUTPUT -o $interface -s $srcip -d $host -p $proto -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Host IP log (OUT): "
            iptables("-A OUTPUT -o %s -s %s -d %s -p %s -m state --state NEW  -m limit --limit 12/m --limit-burst 5  -j LOG --log-prefix \"AIF:Host IP log (OUT): \" --log-level %s", interface, srcip, host, proto, LOGLEVEL);
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (show_if_ip4_FREE != NULL) free(show_if_ip4_FREE);
if (rule15_FREE != NULL) free(rule15_FREE);
if (rule10_FREE != NULL) free(rule10_FREE);
if (rule22_FREE != NULL) free(rule22_FREE);
if (rule19_FREE != NULL) free(rule19_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (rule7_FREE != NULL) free(rule7_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (rule14_FREE != NULL) free(rule14_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (rule21_FREE != NULL) free(rule21_FREE);
if (rule18_FREE != NULL) free(rule18_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (show_if_ip7_FREE != NULL) free(show_if_ip7_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (rule13_FREE != NULL) free(rule13_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (rule20_FREE != NULL) free(rule20_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (show_if_ip6_FREE != NULL) free(show_if_ip6_FREE);
if (rule17_FREE != NULL) free(rule17_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (rule12_FREE != NULL) free(rule12_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (hosts4_FREE != NULL) free(hosts4_FREE);
if (rule24_FREE != NULL) free(rule24_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (rule9_FREE != NULL) free(rule9_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_if_ip5_FREE != NULL) free(show_if_ip5_FREE);
if (rule16_FREE != NULL) free(rule16_FREE);
if (rule11_FREE != NULL) free(rule11_FREE);
if (hosts3_FREE != NULL) free(hosts3_FREE);
if (rule23_FREE != NULL) free(rule23_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (rule8_FREE != NULL) free(rule8_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//# This creates the separate host block
//######################################
void //setup_hostblock_chain()
setup_hostblock_chain(void)
//{
{
char *local1IFS = NULL;;
char *strtok3_FREE = NULL;;
char *total_cnt1_FREE = NULL;;
char *local2IFS = NULL;;
char *read_hosts_r1 = NULL;;
char *strtok2_FREE = NULL;;
char *host = NULL;;
char *strtok1_FREE = NULL;;
char *r_BLOCK_HOSTS1 = NULL;;
char *r_hosts2_FREE1 = NULL;;
char *read_hosts1_FREE = NULL;;
char *hosts2_FREE = NULL;;
int cur_cnt = 0;
char *hosts = NULL;;
char *local3IFS = NULL;;
int retval = 0;
char *r_hosts1_FREE1 = NULL;;
char *hosts1_FREE = NULL;;
char *total_cnt = NULL;;

  //if iptables -F HOST_BLOCK_SRC 2>&1 |grep -q "No chain" ||  iptables -F HOST_BLOCK_DST 2>&1 |grep -q "No chain"; then
  if ( WEXITSTATUS(system("iptables -F HOST_BLOCK_SRC 2>&1 |grep -q \"No chain\" ||  iptables -F HOST_BLOCK_DST 2>&1 |grep -q \"No chain\"")) == 0 )
  {
    //printf "\033[40m\033[1;31mERROR: The firewall isn't running!\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31mERROR: The firewall isn't running!\033[0m\n ");
    //printf "\033[40m\033[1;31m       You should first run this script with the \"start\" command.\033[0m\n" >&2
    fprintf(stderr, "\033[40m\033[1;31m       You should first run this script with the \"start\" command.\033[0m\n ");
    //#return 5
    //return 
    return  ;
  //fi
  }

  //# Return if no Blocked Hosts are defined
  //if [ -z "$BLOCK_HOSTS" -a -z "$BLOCK_HOSTS_FILE" ]; then
  if  (  (((BLOCK_HOSTS==NULL)||(strlen(BLOCK_HOSTS)==0))&&((BLOCK_HOSTS_FILE==NULL)||(strlen(BLOCK_HOSTS_FILE)==0))) )
  {
    //return
    return ;
  //fi
  }

  //if [ "$BLOCK_HOSTS_BIDIRECTIONAL" != "0" ]; then
  if  (  (strcmp(BLOCK_HOSTS_BIDIRECTIONAL,"0")!=0)  )
  {
    //echo "Blocking (blackhole) direction: Inbound and Outbound"
    printf("Blocking (blackhole) direction: Inbound and Outbound" "\n");
  //else
  }
  else
  {
    //echo "Blocking (blackhole) direction: Inbound Only"
    printf("Blocking (blackhole) direction: Inbound Only" "\n");
  //fi
  }

  //# Set default to DROP all while rules are added
  //iptables -A HOST_BLOCK_SRC -j DROP
  iptables("-A HOST_BLOCK_SRC -j DROP");
  //iptables -A HOST_BLOCK_DST -j DROP
  iptables("-A HOST_BLOCK_DST -j DROP");

  //iptables_batch init
  iptables_batch("init");
  //#iptables_batch start
  //#iptables_batch init HOST_BLOCK_SRC
  //#iptables_batch init HOST_BLOCK_DST

  //if [ -n "$BLOCK_HOSTS" ]; then
  if  (  ((BLOCK_HOSTS!=NULL)&&(strlen(BLOCK_HOSTS)!=0))  )
  {
    //printf "Blocking (blackhole) host(s): "
    printf("Blocking (blackhole) host(s): ");

    //IFS=' ,'
    IFS=" ,";
    //for hosts in $BLOCK_HOSTS; do
    local1IFS = IFS;
    if (BLOCK_HOSTS != NULL) strtok1_FREE = strdup(BLOCK_HOSTS);
    if (BLOCK_HOSTS != NULL) for (hosts = strtok_r(strtok1_FREE, local1IFS, &r_BLOCK_HOSTS1); hosts != NULL; hosts = strtok_r(NULL, local1IFS, &r_BLOCK_HOSTS1))
    {
      //printf "$hosts "
      printf("%s ", hosts);

      //for host in `ip_range "$hosts"`; do
      hosts1_FREE = ip_range(hosts, NULL);
      local2IFS = IFS;
      if (hosts1_FREE != NULL) strtok2_FREE = strdup(hosts1_FREE);
      if (hosts1_FREE != NULL) for (host = strtok_r(strtok2_FREE, local2IFS, &r_hosts1_FREE1); host != NULL; host = strtok_r(NULL, local2IFS, &r_hosts1_FREE1))
      {
        //get_numeric_ip_version "$host"
        retval = get_numeric_ip_version(host);
        //case $? in
        switch (retval)
        {
        //4)
        case 4:
          //ip4tables_batch -A HOST_BLOCK_SRC -s $host -j HOST_BLOCK_DROP
          ip4tables_batch("-A HOST_BLOCK_SRC -s %s -j HOST_BLOCK_DROP", host);
          //if [ "$BLOCK_HOSTS_BIDIRECTIONAL" != "0" ]; then
          if  (  (strcmp(BLOCK_HOSTS_BIDIRECTIONAL,"0")!=0)  )
          {
            //ip4tables_batch -A HOST_BLOCK_DST -d $host -j HOST_BLOCK_DROP
            ip4tables_batch("-A HOST_BLOCK_DST -d %s -j HOST_BLOCK_DROP", host);
          //fi
          }
          //;;
          break;
        //6)
        case 6:
          //if [ "$IPV6_SUPPORT" = "1" ]; then
          if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
          {
            //ip6tables_batch -A HOST_BLOCK_SRC -s $host -j HOST_BLOCK_DROP
            ip6tables_batch("-A HOST_BLOCK_SRC -s %s -j HOST_BLOCK_DROP", host);
            //if [ "$BLOCK_HOSTS_BIDIRECTIONAL" != "0" ]; then
            if  (  (strcmp(BLOCK_HOSTS_BIDIRECTIONAL,"0")!=0)  )
            {
              //ip6tables_batch -A HOST_BLOCK_DST -d $host -j HOST_BLOCK_DROP
              ip6tables_batch("-A HOST_BLOCK_DST -d %s -j HOST_BLOCK_DROP", host);
            //fi
            }
          //fi
          }
          //;;
          break;
        //esac
        }
      //done
      }
    //done
    }
    //echo ""
    printf("" "\n");
  //fi
  }


  //# Setup the blocked hosts from our file
  //if [ -n "$BLOCK_HOSTS_FILE" ]; then
  if  (  ((BLOCK_HOSTS_FILE!=NULL)&&(strlen(BLOCK_HOSTS_FILE)!=0))  )
  {
    //if [ -e "$BLOCK_HOSTS_FILE" ]; then
    if  (  ((BLOCK_HOSTS_FILE==NULL)||(access(BLOCK_HOSTS_FILE, R_OK)==0))  )
    {
      //local cur_cnt=0 total_cnt
      //local cur_cnt=0 total_cnt
      //total_cnt=$(( $(cat "$BLOCK_HOSTS_FILE" |sed -e 's|[#;].*||' -e 's| *$||' -e '/^$/d' |wc -l) ))
      total_cnt1_FREE = sysout("cat \"BLOCK_HOSTS_FILE\" |sed -e 's|[#;].*||' -e 's| *||' -e '/^/d' |wc -l", NULL);
      total_cnt = total_cnt1_FREE;

      //echo "(Re)loading list of BLOCKED hosts from $BLOCK_HOSTS_FILE..."
      printf("(Re)loading list of BLOCKED hosts from %s..." "\n", BLOCK_HOSTS_FILE);
      //progress_bar $cur_cnt $total_cnt
      //progress_bar cur_cnt total_cnt

      //# Support both a '#' and a ';' as a comment delimiter in BLOCK_HOSTS_FILE file
      //unset IFS
      IFS = " ";
      //cat "$BLOCK_HOSTS_FILE" |sed -e 's|[#;].*||' -e 's| *$||' -e '/^$/d' |while read hosts; do
      read_hosts1_FREE = sysout("cat \"BLOCK_HOSTS_FILE\" |sed -e 's|[#;].*||' -e 's| *||' -e '/^/d' ", NULL);
      for( hosts = strtok_r(read_hosts1_FREE, "\n", &read_hosts_r1); hosts != NULL; hosts = strtok_r(NULL, "\n", &read_hosts_r1))
      {
        //cur_cnt=$(($cur_cnt + 100))
        cur_cnt=cur_cnt + 100;
        //progress_bar $cur_cnt $total_cnt
        //progress_bar cur_cnt total_cnt

        //if [ -n "$hosts" ]; then
        if  (  ((hosts!=NULL)&&(strlen(hosts)!=0))  )
        {
          //IFS=','
          IFS=",";
          //for host in `ip_range "$hosts"`; do
          hosts2_FREE = ip_range(hosts, NULL);
          local3IFS = IFS;
          if (hosts2_FREE != NULL) strtok3_FREE = strdup(hosts2_FREE);
          if (hosts2_FREE != NULL) for (host = strtok_r(strtok3_FREE, local3IFS, &r_hosts2_FREE1); host != NULL; host = strtok_r(NULL, local3IFS, &r_hosts2_FREE1))
          {
            //get_numeric_ip_version "$host"
            retval = get_numeric_ip_version(host);
            //case $? in
            switch (retval)
            {
            //4)
            case 4:
              //ip4tables_batch -A HOST_BLOCK_SRC -s $host -j HOST_BLOCK_DROP
              ip4tables_batch("-A HOST_BLOCK_SRC -s %s -j HOST_BLOCK_DROP", host);
              //if [ "$BLOCK_HOSTS_BIDIRECTIONAL" != "0" ]; then
              if  (  (strcmp(BLOCK_HOSTS_BIDIRECTIONAL,"0")!=0)  )
              {
                //ip4tables_batch -A HOST_BLOCK_DST -d $host -j HOST_BLOCK_DROP
                ip4tables_batch("-A HOST_BLOCK_DST -d %s -j HOST_BLOCK_DROP", host);
              //fi
              }
              //;;
              break;
            //6)
            case 6:
              //if [ "$IPV6_SUPPORT" = "1" ]; then
              if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
              {
                //ip6tables_batch -A HOST_BLOCK_SRC -s $host -j HOST_BLOCK_DROP
                ip6tables_batch("-A HOST_BLOCK_SRC -s %s -j HOST_BLOCK_DROP", host);
                //if [ "$BLOCK_HOSTS_BIDIRECTIONAL" != "0" ]; then
                if  (  (strcmp(BLOCK_HOSTS_BIDIRECTIONAL,"0")!=0)  )
                {
                  //ip6tables_batch -A HOST_BLOCK_DST -d $host -j HOST_BLOCK_DROP
                  ip6tables_batch("-A HOST_BLOCK_DST -d %s -j HOST_BLOCK_DROP", host);
                //fi
                }
              //fi
              }
              //;;
              break;
            //esac
            }
          //done
          }
          //unset IFS
          IFS = " ";
        //fi
        }
      //done
      }
      //echo ".........$total_cnt line(s) read."
      printf(".........%s line(s) read." "\n", total_cnt);
    //else
    }
    else
    {
      //printf "\033[40m\033[1;31mNOTE: Cannot read the blocked hosts file \"$BLOCK_HOSTS_FILE\".\033[0m\n"
      printf("\033[40m\033[1;31mNOTE: Cannot read the blocked hosts file \"%s\".\033[0m\n", BLOCK_HOSTS_FILE);
    //fi
    }
  //fi
  }

  //#iptables_batch apply HOST_BLOCK_SRC
  //#iptables_batch apply HOST_BLOCK_DST
  //#iptables_batch stop
  //iptables_batch apply
  iptables_batch("apply");
  
  //# All Blocked Host rules are applied
  //# Remove default rule at the beginning of the HOST_BLOCK_SRC and HOST_BLOCK_DST chains
  //iptables -D HOST_BLOCK_SRC 1
  iptables("-D HOST_BLOCK_SRC 1");
  //iptables -D HOST_BLOCK_DST 1
  iptables("-D HOST_BLOCK_DST 1");
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (total_cnt1_FREE != NULL) free(total_cnt1_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (read_hosts1_FREE != NULL) free(read_hosts1_FREE);
if (hosts2_FREE != NULL) free(hosts2_FREE);
if (hosts1_FREE != NULL) free(hosts1_FREE);

//}
}


void //setup_mangle_tables()
setup_mangle_tables(void)
//{
{
char *local1IFS = NULL;;
char *strtok3_FREE = NULL;;
char *r_EXT_IF1 = NULL;;
char *interface = NULL;;
char *local2IFS = NULL;;
char *r_EXT_IF2 = NULL;;
char *r_EXT_IF3 = NULL;;
char *strtok2_FREE = NULL;;
char *strtok1_FREE = NULL;;
char *local3IFS = NULL;;

  //# The following line is intended to hide the firewall during a traceroute.
  //##########################################################################
  //if [ "$TTL_INC" = "1" ]; then
  if  (  (strcmp(TTL_INC,"1")==0)  )
  {
    //echo "Enabling TTL-increase for the PREROUTING chain"
    printf("Enabling TTL-increase for the PREROUTING chain" "\n");
    //IFS=' ,'
    IFS=" ,";
    //for interface in $EXT_IF; do
    local1IFS = IFS;
    if (EXT_IF != NULL) strtok1_FREE = strdup(EXT_IF);
    if (EXT_IF != NULL) for (interface = strtok_r(strtok1_FREE, local1IFS, &r_EXT_IF1); interface != NULL; interface = strtok_r(NULL, local1IFS, &r_EXT_IF1))
    {
      //ip4tables -t mangle -A PREROUTING -i $interface -j TTL --ttl-inc 1
      ip4tables("-t mangle -A PREROUTING -i %s -j TTL --ttl-inc 1", interface);
    //done
    }
  //fi
  }

  //# Set TTL on outgoing & forwarded packets:
  //##########################################
  //if [ -n "$PACKET_TTL" ]; then
  if  (  ((PACKET_TTL!=NULL)&&(strlen(PACKET_TTL)!=0))  )
  {
    //if [ $PACKET_TTL -gt 9 -a $PACKET_TTL -lt 256 ]; then
    if  ( ((atoi(PACKET_TTL)>9)&&(atoi(PACKET_TTL)<256)))
    {
      //echo "Setting TTL=$PACKET_TTL for the FORWARD & OUTPUT chains"
      printf("Setting TTL=%s for the FORWARD & OUTPUT chains" "\n", PACKET_TTL);
      //IFS=' ,'
      IFS=" ,";
      //for interface in $EXT_IF; do
      local2IFS = IFS;
      if (EXT_IF != NULL) strtok2_FREE = strdup(EXT_IF);
      if (EXT_IF != NULL) for (interface = strtok_r(strtok2_FREE, local2IFS, &r_EXT_IF2); interface != NULL; interface = strtok_r(NULL, local2IFS, &r_EXT_IF2))
      {
        //ip4tables -t mangle -A FORWARD -o $interface -j TTL --ttl-set $PACKET_TTL
        ip4tables("-t mangle -A FORWARD -o %s -j TTL --ttl-set %s", interface, PACKET_TTL);
        //ip4tables -t mangle -A OUTPUT -o $interface -j TTL --ttl-set $PACKET_TTL
        ip4tables("-t mangle -A OUTPUT -o %s -j TTL --ttl-set %s", interface, PACKET_TTL);
      //done
      }
    //else
    }
    else
    {
      //printf "\033[40m\033[1;31m WARNING: Ingoring invalid value for PACKET_TTL ($PACKET_TTL), it should be between 10 and 255!\033[0m\n" >&2
      fprintf(stderr, "\033[40m\033[1;31m WARNING: Ingoring invalid value for PACKET_TTL (%s), it should be between 10 and 255!\033[0m\n ", PACKET_TTL);
    //fi
    }
  //fi
  }

  //# Mangles the TOS on standard ports so they get priority in routers
  //###################################################################
  //# TOS table
  //# Options:
  //#               Normal-Service = 0 (0x00)
  //#               Minimize-Cost = 2 (0x02)
  //#               Maximize-Reliability = 4 (0x04)
  //#               Maximize-Throughput = 8 (0x08)
  //#               Minimize-Delay = 16 (0x10)
  //if [ "$MANGLE_TOS" = "1" ]; then
  if  (  (strcmp(MANGLE_TOS,"1")==0)  )
  {
    //echo "Enabling mangling TOS"
    printf("Enabling mangling TOS" "\n");
    //# ToS: Client Applications; data => tos_client
    //# Most of these are the RFC 1060/1349 suggested TOS values, yours might vary.
    //# To view mangle table, type: iptables -L -t mangle
    //IFS=' ,'
    IFS=" ,";
    //for interface in $EXT_IF; do
    local3IFS = IFS;
    if (EXT_IF != NULL) strtok3_FREE = strdup(EXT_IF);
    if (EXT_IF != NULL) for (interface = strtok_r(strtok3_FREE, local3IFS, &r_EXT_IF3); interface != NULL; interface = strtok_r(NULL, local3IFS, &r_EXT_IF3))
    {
      //# Mangle values of packets created locally.
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 20 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 20 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 21 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 21 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 22 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 22 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 23 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 23 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 25 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 25 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p udp --dport 53 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p udp --dport 53 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 67 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 67 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 80 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 80 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 110 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 110 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 113 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 113 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 123 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 123 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 143 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 143 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 443 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 443 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 993 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 993 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 995 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 995 -j TOS --set-tos Maximize-Throughput", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 1080 -j TOS --set-tos Minimize-Delay
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 1080 -j TOS --set-tos Minimize-Delay", interface);
      //iptables -t mangle -A OUTPUT -o $interface -p tcp --dport 6000:6063 -j TOS --set-tos Maximize-Throughput
      iptables("-t mangle -A OUTPUT -o %s -p tcp --dport 6000:6063 -j TOS --set-tos Maximize-Throughput", interface);
    //done
    }

    //# Rules to mangle TOS values of packets routed through the firewall
    //iptables -t mangle -A PREROUTING -p tcp --dport 20 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 20 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 21 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 21 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 22 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 22 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 23 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 23 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 25 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 25 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p udp --dport 53 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p udp --dport 53 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 67 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 67 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 80 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 80 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 110 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 110 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 113 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 113 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 123 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 123 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 143 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 143 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 443 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 443 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 993 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 993 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 995 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 995 -j TOS --set-tos Maximize-Throughput");
    //iptables -t mangle -A PREROUTING -p tcp --dport 1080 -j TOS --set-tos Minimize-Delay
    iptables("-t mangle -A PREROUTING -p tcp --dport 1080 -j TOS --set-tos Minimize-Delay");
    //iptables -t mangle -A PREROUTING -p tcp --dport 6000:6063 -j TOS --set-tos Maximize-Throughput
    iptables("-t mangle -A PREROUTING -p tcp --dport 6000:6063 -j TOS --set-tos Maximize-Throughput");
  //fi
  }
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (strtok1_FREE != NULL) free(strtok1_FREE);

//}
}


void //setup_tcp_mss()
setup_tcp_mss(void)
//{
{
char *local1IFS = NULL;;
char *r_EXT_IF1 = NULL;;
char *interface = NULL;;
char *strtok1_FREE = NULL;;

  //# Besides MTU, there is yet another way to set the maximum packet size, the so called Maximum Segment Size.
  //# This is a field in the TCP Options part of a SYN packet.
  //# The good thing about this is that by setting the MSS value, you are telling the remote side unequivocally
  //# 'do not ever try to send me packets bigger than this value'. No ICMP traffic is needed to get this to work.
  //# In order for this to work you need at least iptables-1.2.1a and Linux 2.4.3 or higher.
  //##################################################################################################################
  //if [ "$SET_MSS" = "1" ]; then
  if  (  (strcmp(SET_MSS,"1")==0)  )
  {
    //echo "Enabling setting the maximum packet size via MSS"
    printf("Enabling setting the maximum packet size via MSS" "\n");
    //IFS=' ,'
    IFS=" ,";
    //for interface in $EXT_IF; do
    local1IFS = IFS;
    if (EXT_IF != NULL) strtok1_FREE = strdup(EXT_IF);
    if (EXT_IF != NULL) for (interface = strtok_r(strtok1_FREE, local1IFS, &r_EXT_IF1); interface != NULL; interface = strtok_r(NULL, local1IFS, &r_EXT_IF1))
    {
      //iptables -A FORWARD -o $interface -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
      //iptables("-A FORWARD -o %s -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu", interface);
      //iptables -A OUTPUT -o $interface -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
      //iptables("-A OUTPUT -o %s -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu", interface);

      //if [ "$NAT" = "1" ]; then
      if  (  (strcmp(NAT,"1")==0)  )
      {
        //ip4tables -t nat -A POSTROUTING -o $interface -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
        //ip4tables("-t nat -A POSTROUTING -o %s -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu", interface);
      //fi
      }
    //done
    }
    
    /* Foxconn added start pling 02/01/2017 */
    /* Clamp the TCP MSS value properly when forwarding */
    iptables("-I FORWARD 1 -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu");
    /* Foxconn added end pling 02/01/2017 */

  //fi
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);

//}
}


//# Here the actual iptables rules are loaded
//###########################################
void //setup_firewall_rules()
setup_firewall_rules(void)
//{
{
char *local26IFS = NULL;;
char *strtok1_FREE = NULL;;
char *local6IFS = NULL;;
char *local37IFS = NULL;;
char *show_hosts_ports2_FREE = NULL;;
char *local15IFS = NULL;;
char *if_shosts_sports = NULL;;
char *if_shosts_protos1_FREE = NULL;;
char *strtok10_FREE = NULL;;
char *icmpv6_type = NULL;;
char *local5IFS = NULL;;
char *strtok22_FREE = NULL;;
char *strtok19_FREE = NULL;;
char *protos = NULL;;
char *dhost_dport3_FREE = NULL;;
char *strtok14_FREE = NULL;;
char *strtok34_FREE = NULL;;
char *local36IFS = NULL;;
char *if_shosts_sports4_FREE = NULL;;
char *awk1_FREE = NULL;;
char *tr4_FREE = NULL;;
char *strtok26_FREE = NULL;;
char *local14IFS = NULL;;
char *stringcat1_FREE = NULL;;
char *strtok5_FREE = NULL;;
char *rule2_FREE = NULL;;
char *r_NAT_FORWARD_TCP1 = NULL;;
char *proto = NULL;;
char *local4IFS = NULL;;
char *r_interfaces1 = NULL;;
char *show_if_ip3_FREE = NULL;;
char *r_interfaces2 = NULL;;
char *r_interfaces3 = NULL;;
char *local25IFS = NULL;;
char *r_ICMPV6_SPECIAL_TYPES1 = NULL;;
char *strtok9_FREE = NULL;;
char *dif = NULL;;
char *destips = NULL;;
char *local35IFS = NULL;;
char *show_hosts_ports1_FREE = NULL;;
char *r_INT_IF1 = NULL;;
char *local13IFS = NULL;;
char *r_INT_IF2 = NULL;;
char *r_INT_IF3 = NULL;;
char *r_INT_IF4 = NULL;;
char *interfaces = NULL;;
char *local3IFS = NULL;;
char *r_NAT_FORWARD_UDP1 = NULL;;
char *strtok21_FREE = NULL;;
char *strtok18_FREE = NULL;;
char *input_if = NULL;;
char *local24IFS = NULL;;
char *r_EXT_IF1 = NULL;;
char *shost = NULL;;
char *iif = NULL;;
char *r_EXT_IF2 = NULL;;
char *if_shosts_sports8_FREE = NULL;;
char *dhost_dport2_FREE = NULL;;
char *strtok13_FREE = NULL;;
char *r_EXT_IF3 = NULL;;
char *strtok33_FREE = NULL;;
char *r_EXT_IF4 = NULL;;
char *local34IFS = NULL;;
char *r_EXT_IF5 = NULL;;
char *rule6_FREE = NULL;;
char *if_shosts_sports3_FREE = NULL;;
char *rule = NULL;;
char *r_EXT_IF6 = NULL;;
char *output_if = NULL;;
char *r_EXT_IF7 = NULL;;
char *tr3_FREE = NULL;;
char *strtok25_FREE = NULL;;
char *local12IFS = NULL;;
char *strtok4_FREE = NULL;;
char *rule1_FREE = NULL;;
char *sports = NULL;;
char *strtok37_FREE = NULL;;
char *trsep2_FREE = NULL;;
char *r_TRUSTED_IF1 = NULL;;
char *r_shosts3_FREE1 = NULL;;
char *show_if_ip2_FREE = NULL;;
char *r_TRUSTED_IF2 = NULL;;
char *r_protos1 = NULL;;
char *local23IFS = NULL;;
char *net = NULL;;
char *strtok8_FREE = NULL;;
char *destip = NULL;;
char *eif = NULL;;
char *if_shosts_protos4_FREE = NULL;;
char *dhost = NULL;;
char *interface = NULL;;
char *strtok20_FREE = NULL;;
char *strtok17_FREE = NULL;;
char *local22IFS = NULL;;
char *local19IFS = NULL;;
char *local2IFS = NULL;;
char *r_shosts1_FREE1 = NULL;;
char *if_shosts_sports7_FREE = NULL;;
char *dhost_dport1_FREE = NULL;;
char *shosts3_FREE = NULL;;
char *strtok32_FREE = NULL;;
char *strtok29_FREE = NULL;;
char *local9IFS = NULL;;
char *rule5_FREE = NULL;;
char *if_shosts_sports2_FREE = NULL;;
char *tr2_FREE = NULL;;
char *local33IFS = NULL;;
char *strtok3_FREE = NULL;;
char *r_destips1 = NULL;;
char *r_sports1 = NULL;;
char *r_destips2 = NULL;;
char *r_sports2 = NULL;;
char *local11IFS = NULL;;
char *r_destips3 = NULL;;
char *trsep1_FREE = NULL;;
char *show_if_ip1_FREE = NULL;;
char *local21IFS = NULL;;
char *local18IFS = NULL;;
char *local1IFS = NULL;;
char *strtok7_FREE = NULL;;
char *if_shosts_protos3_FREE = NULL;;
char *strtok12_FREE = NULL;;
char *local32IFS = NULL;;
char *local29IFS = NULL;;
char *strtok24_FREE = NULL;;
char *local10IFS = NULL;;
char *if_group = NULL;;
char *strtok16_FREE = NULL;;
char *strtok36_FREE = NULL;;
char *sport = NULL;;
char *shosts = NULL;;
char *local20IFS = NULL;;
char *local17IFS = NULL;;
char *if_shosts_sports6_FREE = NULL;;
char *strtok31_FREE = NULL;;
char *strtok28_FREE = NULL;;
char *shosts2_FREE = NULL;;
char *rule4_FREE = NULL;;
char *tr1_FREE = NULL;;
char *local31IFS = NULL;;
char *local28IFS = NULL;;
char *local8IFS = NULL;;
char *strtok2_FREE = NULL;;
char *if_shosts_protos = NULL;;
char *r_IF_TRUSTS1 = NULL;;
char *r_if_group1 = NULL;;
char *show_hosts_ports3_FREE = NULL;;
char *r_if_group2 = NULL;;
char *r_NAT_INTERNAL_NET1 = NULL;;
char *if_shosts_protos2_FREE = NULL;;
char *dport = NULL;;
char *r_NAT_INTERNAL_NET2 = NULL;;
char *strtok11_FREE = NULL;;
char *local30IFS = NULL;;
char *local27IFS = NULL;;
char *local7IFS = NULL;;
char *if_shosts_sports1_FREE = NULL;;
char *r_NAT_FORWARD_IP1 = NULL;;
char *strtok23_FREE = NULL;;
char *dhost_dport = NULL;;
char *dhost_dport4_FREE = NULL;;
char *strtok15_FREE = NULL;;
char *strtok35_FREE = NULL;;
char *if_shosts_sports5_FREE = NULL;;
char *awk2_FREE = NULL;;
char *r_DMZ_IF1 = NULL;;
char *strtok30_FREE = NULL;;
char *strtok27_FREE = NULL;;
char *shosts1_FREE = NULL;;
char *local16IFS = NULL;;
char *r_DMZ_IF2 = NULL;;
char *stringcat2_FREE = NULL;;
char *r_DMZ_IF3 = NULL;;
char *strtok6_FREE = NULL;;
char *r_shosts2_FREE1 = NULL;;
char *rule3_FREE = NULL;;
// Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
char *r_DMZ_TCP1 = NULL;;
char *r_DMZ_UDP1 = NULL;;
char *r_DMZ_NAT_IP1 = NULL;;
char dhcp_start[16];
char dhcp_end[16];
// Foxconn Chiaming 2013/07/15 add Port forwarding schedule
char schedule[256];
/* [Foxc] IvyChen, 2014/12/25, [TD#596]C6300-100NAS: Disable isolation, 2.4G and 5G Guest client can not access to usb:readyshare. (For DNS issue)*/
char lan_ifname[16]={0};

  //echo "Using loglevel \"$LOGLEVEL\" for syslogd"
  printf("Using loglevel \"%s\" for syslogd" "\n", LOGLEVEL);
  //echo ""
  printf("" "\n");

  //echo "Setting up firewall rules:"
  printf("Setting up firewall rules:" "\n");
  //echo "-------------------------------------------------------------------------------"
  printf("-------------------------------------------------------------------------------" "\n");

  //# Setup all TCP MSS stuff
  //#########################
  //setup_tcp_mss;
  setup_tcp_mss();

  //# Setup all mangle stuff
  //########################
  //setup_mangle_tables;
  setup_mangle_tables();

    /* matched igmp rules and accept */
#if defined(CONFIG_INTEL_SDK)
    iptables(" -A PREROUTING -t nat -d 224.0.0.0/240.0.0.0 -j ACCEPT");
    iptables(" -A INPUT -d 224.0.0.0/240.0.0.0 -j ACCEPT");
    iptables(" -A OUTPUT -d 224.0.0.0/240.0.0.0 -j ACCEPT");
    iptables(" -A FORWARD -d 224.0.0.0/240.0.0.0 -j ACCEPT");
#endif

  //# Setup basic input/forward/output/... chains
  //#############################################
  //iptables -A INPUT -j INPUT_CHAIN
  iptables("-A INPUT -j INPUT_CHAIN");
  //iptables -A FORWARD -j FORWARD_CHAIN
  iptables("-A FORWARD -j FORWARD_CHAIN");
  //iptables -A OUTPUT -j OUTPUT_CHAIN
  iptables("-A OUTPUT -j OUTPUT_CHAIN");
  //ip4tables -t nat -A PREROUTING -j NAT_PREROUTING_CHAIN
  ip4tables("-t nat -A PREROUTING -j NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -A POSTROUTING -j NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -A POSTROUTING -j NAT_POSTROUTING_CHAIN");

  //# Block all hosts in the custom blocked hosts file
  //##################################################
  //iptables -A INPUT -j HOST_BLOCK_SRC
  iptables("-A INPUT -j HOST_BLOCK_SRC");
  //iptables -A FORWARD -j HOST_BLOCK_SRC
  iptables("-A FORWARD -j HOST_BLOCK_SRC");
  //iptables -A FORWARD -j HOST_BLOCK_DST
  iptables("-A FORWARD -j HOST_BLOCK_DST");
  //iptables -A OUTPUT -j HOST_BLOCK_DST
  iptables("-A OUTPUT -j HOST_BLOCK_DST");

  //# Allow DNS out for plugins and iptables while setting up rules
  //###############################################################
  //iptables -A OUTPUT_CHAIN -p udp --dport 53 -j ACCEPT
  iptables("-A OUTPUT_CHAIN -p udp --dport 53 -j ACCEPT");
  //iptables -A OUTPUT_CHAIN -p tcp --dport 53 -j ACCEPT
  iptables("-A OUTPUT_CHAIN -p tcp --dport 53 -j ACCEPT");

  //# Setup global helper chains
  //############################
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor add start, 2013/03/14, fix bug(id=6633): DUT must protect LAN host when the DoS Protection function enable.
      //if [ $PORT_SCAN_DOS_DISABLE -eq 0 ]; then
    if ( (strcmp(PORT_SCAN_DOS_DISABLE,"0")==0))      
  //# Teidor add end, 2013/03/14		
#endif
  {
  //setup_valid_chk_chain;
  setup_valid_chk_chain();
  }
  
  //setup_reserved_net_chk_chain;
  setup_reserved_net_chk_chain();
// Mos 2014/08/20, modify behavior of disable firewall
#if 1 //don't do spoof check when disable firewall
  if ( (strcmp(FIREWALL_ENABLE,"1")==0))   
  {
#endif

  //setup_spoof_chk_chain;
  setup_spoof_chk_chain();
#if 1 //don't do spoof check when disable firewall
  }
#endif
  //# Check if source address is spoofed
  //####################################
  //iptables -A INPUT -j SPOOF_CHK
  iptables("-A INPUT -j SPOOF_CHK");

  //# Setup rules for input/output logging
  //######################################
  //setup_input_log;
  setup_input_log();
  //setup_output_log;
  setup_output_log();

  //# Explicit unset IFS, just in case
  //unset IFS
  IFS = " ";

  //# Insert the custom rules
  //#########################
  //if [ -e "$CUSTOM_RULES" ]; then
  if  (  ((CUSTOM_RULES==NULL)||(access(CUSTOM_RULES, R_OK)==0))  )
  {
    //echo "Reading custom rules from $CUSTOM_RULES"
    printf("Reading custom rules from %s" "\n", CUSTOM_RULES);
    //. $CUSTOM_RULES
    source(CUSTOM_RULES);
  //fi
  }
#if 1 // Mos 2014/08/15, refresh iptable per different service
    iptables("-I INPUT -j REMOTE_MGMT_WAN_CHAIN");
    iptables("-I VALID_CHK -j REMOTE_MGMT_BYPASS_CHAIN");
    iptables("-I EXT_INPUT_CHAIN -j USER_MGMT_CHAIN");
    iptables("-I EXT_INPUT_CHAIN -j USER_MGMT_CHAIN");
    // Mos 2014/09/16, fix BLOCKSITE not take effect
    // if it setup after BASE_FORWARD_CHAIN, it will bypass by BASE_FORWARD_CHAIN and never take effect
    iptables("-I INPUT 1 -j BLOCKSITE_IN_CHAIN");
#if (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK)
    iptables("-I FORWARD 1 -j BLOCKSITE --ipv4 -i br-lan");
#else
    iptables("-I FORWARD 1 -j BLOCKSITE --ipv4 -i br0");
#endif
    iptables("-A FORWARD -j BLOCK_SERVICE_CHAIN");
#endif
  //# Start (user) plugins
  //######################
  //plugins_start;
  plugins_start();

  //# Drop outgoing fragmented packets (this should in principle never happen because of netfilter's
  //# packet defragmentation
  //################################################################################################
  //ip4tables -A OUTPUT -f  -m limit --limit 3/m -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Fragment packet: "
  ip4tables("-A OUTPUT -f  -m limit --limit 3/m -j LOG --log-level %s --log-prefix \"AIF:Fragment packet: \"", LOGLEVEL);
  //ip4tables -A OUTPUT -f -j DROP
  ip4tables("-A OUTPUT -f -j DROP");

  //# Setup helper chains for EXTERNAL input traffic:
  //echo "Setting up external(INET) INPUT policy"
  printf("Setting up external(INET) INPUT policy" "\n");
  //setup_ext_multicast_chain;
  setup_ext_multicast_chain();
  //setup_ext_broadcast_chain;
  setup_ext_broadcast_chain();
  //setup_ext_icmp_flood_chain;
  setup_ext_icmp_flood_chain();
  //setup_ext_input_chain;
  setup_ext_input_chain();
  
  //# Setup helper chains for EXTERNAL output traffic:
  //echo "Setting up external(INET) OUTPUT policy"
  printf("Setting up external(INET) OUTPUT policy" "\n");
  //setup_ext_output_chain;
  setup_ext_output_chain();

  //# This is used for your external (untrusted) interfaces
  //#######################################################
  //COUNT=0
  COUNT=0;
  //IFS=' ,'
  IFS=" ,";
  //for interface in $EXT_IF; do
  local1IFS = IFS;
  if (EXT_IF != NULL) strtok1_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (interface = strtok_r(strtok1_FREE, local1IFS, &r_EXT_IF1); interface != NULL; interface = strtok_r(NULL, local1IFS, &r_EXT_IF1))
  {
    //COUNT=$(($COUNT + 1))
    COUNT=COUNT + 1;
    //EXTIF_NET=$(echo "$EXTERNAL_NET" |awk "{ print \$$COUNT }")
    awk1_FREE = getfield(EXTERNAL_NET, " ", (int)(COUNT));
    EXTIF_NET = awk1_FREE;

    //printf "Applying external(INET) policy to interface: $interface"
    printf("Applying external(INET) policy to interface: %s", interface);
    //if [ -z "$EXTIF_NET" ]; then
    if  (  ((EXTIF_NET==NULL)||(strlen(EXTIF_NET)==0))  )
    {
      //echo " (without an external subnet specified)"
      printf(" (without an external subnet specified)" "\n");
    //else
    }
    else
    {
      //echo " (EXTERNAL_NET=$EXTIF_NET)"
      printf(" (EXTERNAL_NET=%s)" "\n", EXTIF_NET);
    //fi
    }

    //# Apply external (internet) interface policy for the output chain:
    //##################################################################
    //iptables -A OUTPUT -o $interface -j EXT_OUTPUT_CHAIN
    iptables("-A OUTPUT -o %s -j EXT_OUTPUT_CHAIN", interface);

    //# We must allow special icmpv6 packets since CONNTRACK doesn't handle all icmpv6 types:
    //#######################################################################################
    //if [ "$IPV6_SUPPORT" = "1" -a "$OPEN_ICMPV6" != "0" ]; then
    if  (  ((strcmp(IPV6_SUPPORT,"1")==0)&&(strcmp(OPEN_ICMPV6,"0")!=0)) )
    {
      //for icmpv6_type in $ICMPV6_SPECIAL_TYPES; do
      local2IFS = IFS;
      if (ICMPV6_SPECIAL_TYPES != NULL) strtok2_FREE = strdup(ICMPV6_SPECIAL_TYPES);
      if (ICMPV6_SPECIAL_TYPES != NULL) for (icmpv6_type = strtok_r(strtok2_FREE, local2IFS, &r_ICMPV6_SPECIAL_TYPES1); icmpv6_type != NULL; icmpv6_type = strtok_r(NULL, local2IFS, &r_ICMPV6_SPECIAL_TYPES1))
      {
        //ip6tables -A INPUT -i $interface -p icmpv6 --icmpv6-type $icmpv6_type -m hl --hl-eq 255 -j ACCEPT
        ip6tables("-A INPUT -i %s -p icmpv6 --icmpv6-type %s -m hl --hl-eq 255 -j ACCEPT", interface, icmpv6_type);
      //done
      }
    //fi
    }

    //# Apply external (internet) interface policy for the input chain:
    //#################################################################
    //# Check packets for invalid flags:
    //iptables -A INPUT -i $interface -j VALID_CHK
    iptables("-A INPUT -i %s -j VALID_CHK", interface);

    //# Handle multicast traffic
    //##########################
    //ip4tables -A INPUT -i $interface -d 224.0.0.0/4 -j EXT_MULTICAST_CHAIN
    ip4tables("-A INPUT -i %s -d 224.0.0.0/4 -j EXT_MULTICAST_CHAIN", interface);
    //if [ "$IPV6_SUPPORT" = "1" ]; then
    if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
    {
      //ip6tables -A INPUT -i $interface -d ff00::/8 -j EXT_MULTICAST_CHAIN
      ip6tables("-A INPUT -i %s -d ff00::/8 -j EXT_MULTICAST_CHAIN", interface);
    //fi
    }

    //# Perform check:
    //################
    //# Non-ICMP traffic:
    //iptables -A INPUT -i $interface ! -p icmp -m state --state NEW -j EXT_INPUT_CHAIN
    iptables("-A INPUT -i %s ! -p icmp -m state --state NEW -j EXT_INPUT_CHAIN", interface);

    //# ICMP traffic (rate limited):
    //iptables -A INPUT -i $interface -p icmp -m state --state NEW  -m limit --limit 60/second --limit-burst 100 -j EXT_INPUT_CHAIN
    iptables("-A INPUT -i %s -p icmp -m state --state NEW  -m limit --limit 60/second --limit-burst 100 -j EXT_INPUT_CHAIN", interface);

    //# ICMP traffic (flood)
    //iptables -A INPUT -i $interface -p icmp -m state --state NEW -j EXT_ICMP_FLOOD_CHAIN
    iptables("-A INPUT -i %s -p icmp -m state --state NEW -j EXT_ICMP_FLOOD_CHAIN", interface);

  //done
  }


  //# Setup input rules for your internal net
  //#########################################
  //if [ -n "$INT_IF" ]; then
  if  (  ((INT_IF!=NULL)&&(strlen(INT_IF)!=0))  )
  {
    //# Setup helper chain for the LAN:
    //echo "Setting up internal(LAN) INPUT policy"
    printf("Setting up internal(LAN) INPUT policy" "\n");
    //setup_int_input_chain;
    setup_int_input_chain();

    //IFS=' ,'
    IFS=" ,";
    //for interface in $INT_IF; do
    local3IFS = IFS;
    if (INT_IF != NULL) strtok3_FREE = strdup(INT_IF);
    if (INT_IF != NULL) for (interface = strtok_r(strtok3_FREE, local3IFS, &r_INT_IF1); interface != NULL; interface = strtok_r(NULL, local3IFS, &r_INT_IF1))
    {
      //echo "Applying internal(LAN) policy to interface: $interface"
      printf("Applying internal(LAN) policy to interface: %s" "\n", interface);
      //iptables -A INPUT -i $interface -j INT_INPUT_CHAIN
      iptables("-A INPUT -i %s -j INT_INPUT_CHAIN", interface);
      //iptables -A OUTPUT -o $interface -j INT_OUTPUT_CHAIN
      iptables("-A OUTPUT -o %s -j INT_OUTPUT_CHAIN", interface);
    //done
    }
  //fi
  }

  //# Setup input rules for your DMZ net
  //####################################
  //if [ -n "$DMZ_IF" ]; then
  if  (  ((DMZ_IF!=NULL)&&(strlen(DMZ_IF)!=0))  )
  {
    //# Setup helper chain for the DMZ:
    //echo "Setting up DMZ INPUT policy"
    printf("Setting up DMZ INPUT policy" "\n");
    //setup_dmz_input_chain;
    setup_dmz_input_chain();

    //IFS=' ,'
    IFS=" ,";
    //for interface in $DMZ_IF; do
    local4IFS = IFS;
    if (DMZ_IF != NULL) strtok4_FREE = strdup(DMZ_IF);
    if (DMZ_IF != NULL) for (interface = strtok_r(strtok4_FREE, local4IFS, &r_DMZ_IF1); interface != NULL; interface = strtok_r(NULL, local4IFS, &r_DMZ_IF1))
    {
      //echo "Applying DMZ policy to interface: $interface"
      printf("Applying DMZ policy to interface: %s" "\n", interface);
      //iptables -A INPUT -i $interface -j DMZ_INPUT_CHAIN
      iptables("-A INPUT -i %s -j DMZ_INPUT_CHAIN", interface);
      //iptables -A OUTPUT -o $interface -j DMZ_OUTPUT_CHAIN
      iptables("-A OUTPUT -o %s -j DMZ_OUTPUT_CHAIN", interface);
    //done
    }
  //fi
  }

  //# Accept all packets on "other" interfaces
  //##########################################
  //if [ -n "$TRUSTED_IF" ]; then
  if  (  ((TRUSTED_IF!=NULL)&&(strlen(TRUSTED_IF)!=0))  )
  {
    //echo "Accepting ALL INPUT packets from trusted interface(s): $TRUSTED_IF"
    printf("Accepting ALL INPUT packets from trusted interface(s): %s" "\n", TRUSTED_IF);
    //IFS=' ,'
    IFS=" ,";
    //for interface in $TRUSTED_IF; do
    local5IFS = IFS;
    if (TRUSTED_IF != NULL) strtok5_FREE = strdup(TRUSTED_IF);
    if (TRUSTED_IF != NULL) for (interface = strtok_r(strtok5_FREE, local5IFS, &r_TRUSTED_IF1); interface != NULL; interface = strtok_r(NULL, local5IFS, &r_TRUSTED_IF1))
    {
      //iptables -A INPUT -i $interface -j ACCEPT
      iptables("-A INPUT -i %s -j ACCEPT", interface);
    //done
    }
  //fi
  }
  
  iptables("-A INPUT -j USB_INPUT_CHAIN");

  //# Jump to the POST INPUT chain
  //##############################
  //iptables -A INPUT -j POST_INPUT_CHAIN
  iptables("-A INPUT -j POST_INPUT_CHAIN");
  
  //# Everything else is logged & dropped in INPUT (just in case)...
  //################################################################
  //iptables -A INPUT -m limit --limit 1/s -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Dropped INPUT packet: "
  iptables("-A INPUT -m limit --limit 1/s -j LOG --log-prefix \"AIF:Dropped INPUT packet: \" --log-level %s", LOGLEVEL);
  //iptables -A INPUT -j DROP
  iptables("-A INPUT -j DROP");

  //# Drop all packets at the end of the POST_INPUT_DROP_CHAIN
  //iptables -A POST_INPUT_DROP_CHAIN -j DROP
  iptables("-A POST_INPUT_DROP_CHAIN -j DROP");

  //# Remove the temp rule at the beginning of the POST_INPUT_DROP_CHAIN
  //iptables -D POST_INPUT_DROP_CHAIN 1
  iptables("-D POST_INPUT_DROP_CHAIN 1");

  //###############################################################################################
  //# FORWARD rules                                                                               #
  //###############################################################################################

  //# Drop forward traffic to/from IPv6 Link Local Addresses
  //########################################################
  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //if [ "$FORWARD_LINK_LOCAL" != "1" ]; then
    if  (  (strcmp(FORWARD_LINK_LOCAL,"1")!=0)  )
    {
      //ip6tables -A FORWARD -s fe80::/10 -j LINK_LOCAL_DROP
      ip6tables("-A FORWARD -s fe80::/10 -j LINK_LOCAL_DROP");
      //ip6tables -A FORWARD -d fe80::/10 -j LINK_LOCAL_DROP
      ip6tables("-A FORWARD -d fe80::/10 -j LINK_LOCAL_DROP");
    //else
    }
    else
    {
      //echo "IPv6 Link-Local Addresses are forwarded!"
      printf("IPv6 Link-Local Addresses are forwarded!" "\n");
    //fi
    }
  //fi
  }
#if 0
  //# Allow forward traffic from "trusted-if"
  //#########################################
  //if [ -n "$TRUSTED_IF" ]; then
  if  (  ((TRUSTED_IF!=NULL)&&(strlen(TRUSTED_IF)!=0))  )
  {
    //echo "Accepting ALL FORWARD packets for trusted interface(s): $TRUSTED_IF"
    printf("Accepting ALL FORWARD packets for trusted interface(s): %s" "\n", TRUSTED_IF);
    //IFS=' ,'
    IFS=" ,";
    //for interface in $TRUSTED_IF; do
    local6IFS = IFS;
    if (TRUSTED_IF != NULL) strtok6_FREE = strdup(TRUSTED_IF);
    if (TRUSTED_IF != NULL) for (interface = strtok_r(strtok6_FREE, local6IFS, &r_TRUSTED_IF2); interface != NULL; interface = strtok_r(NULL, local6IFS, &r_TRUSTED_IF2))
    {
      //# Allow forward traffic in:
      //iptables -A FORWARD -i $interface -j ACCEPT
      iptables("-A FORWARD -i %s -j ACCEPT", interface);
      //# Allow forward traffic out:
      //iptables -A FORWARD -o $interface -j ACCEPT
      iptables("-A FORWARD -o %s -j ACCEPT", interface);
    //done
    }
  //fi
  }
#endif
  //# Source the IN/OUT chains for the external interface(s)
  //########################################################
  //IFS=' ,'
  IFS=" ,";
  //for eif in $EXT_IF; do
  local7IFS = IFS;
  if (EXT_IF != NULL) strtok7_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (eif = strtok_r(strtok7_FREE, local7IFS, &r_EXT_IF2); eif != NULL; eif = strtok_r(NULL, local7IFS, &r_EXT_IF2))
  {
    //iptables -A FORWARD -i $eif -j EXT_FORWARD_IN_CHAIN
    iptables("-A FORWARD -i %s -j EXT_FORWARD_IN_CHAIN", eif);
    //iptables -A FORWARD -o $eif -j EXT_FORWARD_OUT_CHAIN
    iptables("-A FORWARD -o %s -j EXT_FORWARD_OUT_CHAIN", eif);
  //done
  }
  
  //# Source the IN/OUT chains for the internal interface(s)
  //########################################################
  //IFS=' ,'
  IFS=" ,";
  //for iif in $INT_IF; do
  local8IFS = IFS;
  if (INT_IF != NULL) strtok8_FREE = strdup(INT_IF);
  if (INT_IF != NULL) for (iif = strtok_r(strtok8_FREE, local8IFS, &r_INT_IF2); iif != NULL; iif = strtok_r(NULL, local8IFS, &r_INT_IF2))
  {
    //iptables -A FORWARD -i $iif -j INT_FORWARD_IN_CHAIN
    iptables("-A FORWARD -i %s -j INT_FORWARD_IN_CHAIN", iif);
    //iptables -A FORWARD -o $iif -j INT_FORWARD_OUT_CHAIN
    iptables("-A FORWARD -o %s -j INT_FORWARD_OUT_CHAIN", iif);
  //done
  }

  //# Source the IN/OUT chains for the dmz interface(s)
  //########################################################
  //IFS=' ,'
  IFS=" ,";
  //for dif in $DMZ_IF; do
  local9IFS = IFS;
  if (DMZ_IF != NULL) strtok9_FREE = strdup(DMZ_IF);
  if (DMZ_IF != NULL) for (dif = strtok_r(strtok9_FREE, local9IFS, &r_DMZ_IF2); dif != NULL; dif = strtok_r(NULL, local9IFS, &r_DMZ_IF2))
  {
    //iptables -A FORWARD -i $dif -j DMZ_FORWARD_IN_CHAIN
    iptables("-A FORWARD -i %s -j DMZ_FORWARD_IN_CHAIN", dif);
    //iptables -A FORWARD -o $dif -j DMZ_FORWARD_OUT_CHAIN
    iptables("-A FORWARD -o %s -j DMZ_FORWARD_OUT_CHAIN", dif);
  //done
  }

  //# Check source address for spoofing
  //###################################
  //iptables -A FORWARD -j SPOOF_CHK
  iptables("-A FORWARD -j SPOOF_CHK");

  //# Check if the incoming packet is (in)valid
  //###########################################
  //iptables -A EXT_FORWARD_IN_CHAIN -j VALID_CHK
  iptables("-A EXT_FORWARD_IN_CHAIN -j VALID_CHK");

  //# Check if incoming packet sources are (in)valid
  //################################################
  //if [ "$DROP_PRIVATE_ADDRESSES" = "1" -o "$RESERVED_NET_LOG" = "1" ]; then
  if  (  ((strcmp(DROP_PRIVATE_ADDRESSES,"1")==0)||(strcmp(RESERVED_NET_LOG,"1")==0)) )
  {
    //iptables -A EXT_FORWARD_IN_CHAIN -j RESERVED_NET_CHK
    iptables("-A EXT_FORWARD_IN_CHAIN -j RESERVED_NET_CHK");
  //fi
  }

  //# Setup forward policy for the DMZ
  //##################################
  //if [ -n "$DMZ_IF" ]; then
  if  (  ((DMZ_IF!=NULL)&&(strlen(DMZ_IF)!=0))  )
  {

    //echo "Setting up DMZ FORWARD policy"
    printf("Setting up DMZ FORWARD policy" "\n");

    //if [ "$DMZ_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(DMZ_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //echo " Logging of denied DMZ (forward) output connections enabled"
      printf(" Logging of denied DMZ (forward) output connections enabled" "\n");
    //else
    }
    else
    {
      //echo " Logging of denied DMZ (forward) output connections disabled"
      printf(" Logging of denied DMZ (forward) output connections disabled" "\n");
    //fi
    }

    //if [ "$DMZ_INPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(DMZ_INPUT_DENY_LOG,"0")!=0)  )
    {
      //echo " Logging of denied DMZ (forward) input connections enabled"
      printf(" Logging of denied DMZ (forward) input connections enabled" "\n");
    //else
    }
    else
    {
      //echo " Logging of denied DMZ (forward) input connections disabled"
      printf(" Logging of denied DMZ (forward) input connections disabled" "\n");
    //fi
    }

    //# Setup helper chains for the DMZ:
    //setup_inet_dmz_forward_chain;
    setup_inet_dmz_forward_chain();
    //setup_dmz_inet_forward_chain;
    setup_dmz_inet_forward_chain();
    //setup_dmz_lan_forward_chain;
    setup_dmz_lan_forward_chain();

    //IFS=' ,'
    IFS=" ,";
    //for dif in $DMZ_IF; do
    local10IFS = IFS;
    if (DMZ_IF != NULL) strtok10_FREE = strdup(DMZ_IF);
    if (DMZ_IF != NULL) for (dif = strtok_r(strtok10_FREE, local10IFS, &r_DMZ_IF3); dif != NULL; dif = strtok_r(NULL, local10IFS, &r_DMZ_IF3))
    {
      //echo "Applying DMZ FORWARD policy to interface: $dif"
      printf("Applying DMZ FORWARD policy to interface: %s" "\n", dif);
      
      //# Always make subnets on the SAME interface trust each other
      //iptables -A FORWARD -i $dif -o $dif -j ACCEPT
      iptables("-A FORWARD -i %s -o %s -j ACCEPT", dif, dif);

      //for eif in $EXT_IF; do
      local11IFS = IFS;
      if (EXT_IF != NULL) strtok11_FREE = strdup(EXT_IF);
      if (EXT_IF != NULL) for (eif = strtok_r(strtok11_FREE, local11IFS, &r_EXT_IF3); eif != NULL; eif = strtok_r(NULL, local11IFS, &r_EXT_IF3))
      {
        //# Apply policy for inet->DMZ traffic
        //iptables -A FORWARD -i $eif -o $dif -j INET_DMZ_FORWARD_CHAIN
        iptables("-A FORWARD -i %s -o %s -j INET_DMZ_FORWARD_CHAIN", eif, dif);

        //# Apply policy for DMZ->inet traffic
        //iptables -A FORWARD -i $dif -o $eif -j DMZ_INET_FORWARD_CHAIN
        iptables("-A FORWARD -i %s -o %s -j DMZ_INET_FORWARD_CHAIN", dif, eif);
      //done
      }

      //# Apply policy for DMZ->LAN traffic & LAN->DMZ traffic
      //for iif in $INT_IF; do
      local12IFS = IFS;
      if (INT_IF != NULL) strtok12_FREE = strdup(INT_IF);
      if (INT_IF != NULL) for (iif = strtok_r(strtok12_FREE, local12IFS, &r_INT_IF3); iif != NULL; iif = strtok_r(NULL, local12IFS, &r_INT_IF3))
      {
        //# Apply policy for DMZ->LAN
        //iptables -A FORWARD -i $dif -o $iif -j DMZ_LAN_FORWARD_CHAIN
        iptables("-A FORWARD -i %s -o %s -j DMZ_LAN_FORWARD_CHAIN", dif, iif);

        //# Apply policy for LAN->DMZ (allow all)
        //iptables -A FORWARD -i $iif -o $dif -j ACCEPT
        iptables("-A FORWARD -i %s -o %s -j ACCEPT", iif, dif);
      //done
      }
    //done
    }
  //fi
  }

  //# Forward traffic for LAN interface(s) that trust each other
  //#######################################################################
  //IFS=$SEP3
  IFS=SEP3;
  //for if_group in $IF_TRUSTS; do
  local13IFS = IFS;
  if (IF_TRUSTS != NULL) strtok13_FREE = strdup(IF_TRUSTS);
  if (IF_TRUSTS != NULL) for (if_group = strtok_r(strtok13_FREE, local13IFS, &r_IF_TRUSTS1); if_group != NULL; if_group = strtok_r(NULL, local13IFS, &r_IF_TRUSTS1))
  {
    //echo "Setting up trust FORWARD policy for interface(s): $if_group"
    printf("Setting up trust FORWARD policy for interface(s): %s" "\n", if_group);
    //IFS=' ,'
    IFS=" ,";
    //for input_if in $if_group; do
    local14IFS = IFS;
    if (if_group != NULL) strtok14_FREE = strdup(if_group);
    if (if_group != NULL) for (input_if = strtok_r(strtok14_FREE, local14IFS, &r_if_group1); input_if != NULL; input_if = strtok_r(NULL, local14IFS, &r_if_group1))
    {
      //for output_if in $if_group; do
      local15IFS = IFS;
      if (if_group != NULL) strtok15_FREE = strdup(if_group);
      if (if_group != NULL) for (output_if = strtok_r(strtok15_FREE, local15IFS, &r_if_group2); output_if != NULL; output_if = strtok_r(NULL, local15IFS, &r_if_group2))
      {
        //if [ "$input_if" != "$output_if" ]; then
        if  (  (strcmp(input_if,output_if)!=0)  )
        {
          //iptables -A FORWARD -i $input_if -o $output_if -j ACCEPT
          iptables("-A FORWARD -i %s -o %s -j ACCEPT", input_if, output_if);
        //fi
        }
      //done
      }
    //done
    }
  //done
  }

  //# Additional rules for the internal subnet(s)
  //#############################################
  //if [ -n "$INT_IF" ]; then
  if  (  ((INT_IF!=NULL)&&(strlen(INT_IF)!=0))  )
  {
    //echo "Setting up internal(LAN) FORWARD policy"
    printf("Setting up internal(LAN) FORWARD policy" "\n");

    //# Enable logging of denied LAN output connections?
    //##################################################
    //if [ "$LAN_OUTPUT_DENY_LOG" != "0" ]; then
    if  (  (strcmp(LAN_OUTPUT_DENY_LOG,"0")!=0)  )
    {
      //echo " Logging of denied LAN->INET FORWARD connections enabled"
      printf(" Logging of denied LAN->INET FORWARD connections enabled" "\n");
    //else
    }
    else
    {
      //echo " Logging of denied LAN->INET FORWARD connections disabled"
      printf(" Logging of denied LAN->INET FORWARD connections disabled" "\n");
    //fi
    }

    //# Setup helper chain for the LAN:
    //setup_lan_inet_forward_chain;
    setup_lan_inet_forward_chain();

    //IFS=' ,'
    IFS=" ,";
    //for iif in $INT_IF; do
    local16IFS = IFS;
    if (INT_IF != NULL) strtok16_FREE = strdup(INT_IF);
    if (INT_IF != NULL) for (iif = strtok_r(strtok16_FREE, local16IFS, &r_INT_IF4); iif != NULL; iif = strtok_r(NULL, local16IFS, &r_INT_IF4))
    {
      //echo "Applying internal(LAN) FORWARD policy to interface: $iif"
      printf("Applying internal(LAN) FORWARD policy to interface: %s" "\n", iif);
      
      //# Always make subnets on the SAME interface trust each other
      //iptables -A FORWARD -i $iif -o $iif -j ACCEPT
      iptables("-A FORWARD -i %s -o %s -j ACCEPT", iif, iif);

      //for eif in $EXT_IF; do
      local17IFS = IFS;
      if (EXT_IF != NULL) strtok17_FREE = strdup(EXT_IF);
      if (EXT_IF != NULL) for (eif = strtok_r(strtok17_FREE, local17IFS, &r_EXT_IF4); eif != NULL; eif = strtok_r(NULL, local17IFS, &r_EXT_IF4))
      {
        //iptables -A FORWARD -i $iif -o $eif -j LAN_INET_FORWARD_CHAIN
        iptables("-A FORWARD -i %s -o %s -j LAN_INET_FORWARD_CHAIN", iif, eif);
      //done
      }
    //done
    }
  //fi
  }


  //##############################################################################
  //# Masquerade (NAT) or SNAT. Share the gateway's internet connection with     #
  //# the internal network                                                       #
  //##############################################################################
  //if [ "$NAT" = "1" ]; then
  if  (  (strcmp(NAT,"1")==0)  )
  {
    //if [ -n "$NAT_STATIC_IP" ]; then
    if  (  ((NAT_STATIC_IP!=NULL)&&(strlen(NAT_STATIC_IP)!=0))  )
    {
      //echo "Enabling SNAT via external interface(s): $EXT_IF"
      printf("Enabling SNAT via external interface(s): %s" "\n", EXT_IF);

      //printf " Adding (internal) host(s): "
      printf(" Adding (internal) host(s): ");

      //IFS=' ,'
      IFS=" ,";
      //for net in $NAT_INTERNAL_NET; do
      local18IFS = IFS;
      if (NAT_INTERNAL_NET != NULL) strtok18_FREE = strdup(NAT_INTERNAL_NET);
      if (NAT_INTERNAL_NET != NULL) for (net = strtok_r(strtok18_FREE, local18IFS, &r_NAT_INTERNAL_NET1); net != NULL; net = strtok_r(NULL, local18IFS, &r_NAT_INTERNAL_NET1))
      {
        //printf "$net "
        printf("%s ", net);

        //COUNT=0
        COUNT=0;
        //for interface in $EXT_IF; do
        local19IFS = IFS;
        if (EXT_IF != NULL) strtok19_FREE = strdup(EXT_IF);
        if (EXT_IF != NULL) for (interface = strtok_r(strtok19_FREE, local19IFS, &r_EXT_IF5); interface != NULL; interface = strtok_r(NULL, local19IFS, &r_EXT_IF5))
        {
          //COUNT=$(($COUNT + 1))         # x++;
          COUNT=COUNT + 1;
          //STATIC_IP=$(echo "$NAT_STATIC_IP" |awk "{ print \$$COUNT }")
          awk2_FREE = getfield(NAT_STATIC_IP, " ", (int)(COUNT));
          STATIC_IP = awk2_FREE;
          //ip4tables -t nat -A POSTROUTING -o $interface -s $net ! -d $net -j SNAT --to-source $STATIC_IP
          ip4tables("-t nat -A POSTROUTING -o %s -s %s ! -d %s -j SNAT --to-source %s", interface, net, net, STATIC_IP);
        //done
        }
      //done
      }
      //echo ""
      printf("" "\n");
    //else
    }
    else
    {
      //# All internal traffic is masqueraded externally
      //################################################
      //echo "Enabling masquerading(NAT) via external interface(s): $EXT_IF"
      printf("Enabling masquerading(NAT) via external interface(s): %s" "\n", EXT_IF);

      //printf " Adding (internal) host(s): "
      printf(" Adding (internal) host(s): ");

      //IFS=' ,'
      IFS=" ,";
      //for net in $NAT_INTERNAL_NET; do
      local20IFS = IFS;
      if (NAT_INTERNAL_NET != NULL) strtok20_FREE = strdup(NAT_INTERNAL_NET);
      if (NAT_INTERNAL_NET != NULL) for (net = strtok_r(strtok20_FREE, local20IFS, &r_NAT_INTERNAL_NET2); net != NULL; net = strtok_r(NULL, local20IFS, &r_NAT_INTERNAL_NET2))
      {
        //printf "$net "
        printf("%s ", net);

        //for interface in $EXT_IF; do
        local21IFS = IFS;
        if (EXT_IF != NULL) strtok21_FREE = strdup(EXT_IF);
        if (EXT_IF != NULL) for (interface = strtok_r(strtok21_FREE, local21IFS, &r_EXT_IF6); interface != NULL; interface = strtok_r(NULL, local21IFS, &r_EXT_IF6))
        {
          //# The "! -d $net" is to avoid problems with Freeswan etc.
          //ip4tables -t nat -A POSTROUTING -o $interface -s $net ! -d $net -j MASQUERADE
          ip4tables("-t nat -A POSTROUTING -o %s -s %s ! -d %s -j MASQUERADE", interface, net, net);
        //done
        }
      //done
      }
      //echo ""
      printf("" "\n");
    //fi
    }
  //fi
  }
#if 1 // Mos 2014/08/15, refresh iptable per different service
    iptables("-A EXT_FORWARD_IN_CHAIN -j PORTFORWARD_FORWARD_IN_CHAIN");
    iptables("-t nat -A PREROUTING -j PORTFORWARD_NAT_CHAIN");
    iptables("-A EXT_FORWARD_IN_CHAIN -j PORTTRIGGER_FORWARD_IN_CHAIN");
    iptables("-t nat -A PREROUTING -j PORTTRIGGER_NAT_CHAIN");
//Mos 2014/08/28 implement usb service filrewall rules
    iptables("-A EXT_FORWARD_IN_CHAIN -j USB_FORWARD_IN_CHAIN");
    iptables("-t nat -A PREROUTING -j USB_NAT_CHAIN");
#endif

    /* [Foxc] Baverly, 2014/10/14, [TD#406] C6300: USB -- There should be IPv6 URL access via HTTP(internet). 
     * Create USB service filrewall rules for IPv6. */
    if (strcmp(IPV6_SUPPORT, "1") == 0)
    {
        ip6tables("-I INPUT -j USB_INPUT_CHAIN");
    }
    iptables("-A OPENVPN_FORWARD_CHAIN -j FORWARD");
  //# Port / protocol forwarding. Forward ports or protocols on the internet-gateway to machines in our LAN
  //#######################################################################################################

  //# NAT TCP port forwards
  //#######################
  //unset IFS
  IFS = " ";
  //for rule in $NAT_FORWARD_TCP; do
  local22IFS = IFS;
  if (NAT_FORWARD_TCP != NULL) strtok22_FREE = strdup(NAT_FORWARD_TCP);
  if (NAT_FORWARD_TCP != NULL) for (rule = strtok_r(strtok22_FREE, local22IFS, &r_NAT_FORWARD_TCP1); rule != NULL; rule = strtok_r(NULL, local22IFS, &r_NAT_FORWARD_TCP1))
  {
    //if_shosts_sports=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts_sports=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts_sports" "$EXT_IF"`
    if_shosts_sports1_FREE = get_ifs(if_shosts_sports, EXT_IF);
    interfaces=if_shosts_sports1_FREE;;
    //destips=`get_ips "$if_shosts_sports"`
    if_shosts_sports2_FREE = get_ips(if_shosts_sports, NULL);
    destips=if_shosts_sports2_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_sports" "0/0"`
    if_shosts_sports3_FREE = get_hosts_ihp(if_shosts_sports, "0/0");
    shosts=if_shosts_sports3_FREE;;
    //sports=`get_ports_ihp "$if_shosts_sports"`
    if_shosts_sports4_FREE = get_ports_ihp(if_shosts_sports, NULL);
    sports=if_shosts_sports4_FREE;;
    //dhost_dport=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhost_dport=rule2_FREE;;
    //dhost=`get_hosts_hp "$dhost_dport"`
    dhost_dport1_FREE = get_hosts_hp(dhost_dport, NULL);
    dhost=dhost_dport1_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Forwarding(NAT) TCP port(s) $(show_hosts_ports "$shosts" "$sports") to $(echo "$dhost_dport" |tr "$SEP-" '::')"
    trsep1_FREE= stringcat(SEP, "-", NULL); tr1_FREE = tr(dhost_dport, trsep1_FREE, "::");
    show_hosts_ports1_FREE = show_hosts_ports(shosts, sports);
    show_if_ip1_FREE = show_if_ip(interfaces, destips);
    printf("%s Forwarding(NAT) TCP port(s) %s  to %s;;" "\n", show_if_ip1_FREE, show_hosts_ports1_FREE, tr1_FREE);;

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local23IFS = IFS;
    if (shosts1_FREE != NULL) strtok23_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok23_FREE, local23IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local23IFS, &r_shosts1_FREE1))
    {
      //for sport in $sports; do
      local24IFS = IFS;
      if (sports != NULL) strtok24_FREE = strdup(sports);
      if (sports != NULL) for (sport = strtok_r(strtok24_FREE, local24IFS, &r_sports1); sport != NULL; sport = strtok_r(NULL, local24IFS, &r_sports1))
      {
        //for destip in $destips; do
        local25IFS = IFS;
        if (destips != NULL) strtok25_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok25_FREE, local25IFS, &r_destips1); destip != NULL; destip = strtok_r(NULL, local25IFS, &r_destips1))
        {
          //# Portforward for all specified interfaces
          //for eif in $interfaces; do
          local26IFS = IFS;
          if (interfaces != NULL) strtok26_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok26_FREE, local26IFS, &r_interfaces1); eif != NULL; eif = strtok_r(NULL, local26IFS, &r_interfaces1))
          {
            //# This code makes it possible to forward to a different port on the internal host
            //dport=`get_ports_hp "$dhost_dport" "$sport"`
            dhost_dport2_FREE = get_ports_hp(dhost_dport, sport);
            dport=dhost_dport2_FREE;;

            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p tcp --dport $sport -j DNAT --to-destination `echo "$dhost_dport" |tr "$SEP-" '::'`
            stringcat1_FREE = stringcat(SEP, "-");
            tr2_FREE = tr(dhost_dport, stringcat1_FREE, "::");
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p tcp --dport %s -j DNAT --to-destination %s", eif, shost, destip, sport, tr2_FREE);
            //if [ -n "$dhost" ]; then
#ifdef CABLE_PORFORWARDING  //Chiaming add 2013/07/15
            getNvValue("Fw.PortForward_Schedule", schedule);
	     if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
                if(strcmp(schedule,"")==0)
	         {
	             //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p tcp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p tcp --dport %s -j ACCEPT", eif, eif, shost, dhost, dport);
            	  }
		  else
		  {
		      //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p tcp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p tcp --dport %s %s -j ACCEPT", eif, eif, shost, dhost, dport,schedule);
		  }
            }
            //Chiaming add end 2013/07/15
#ifdef CABLE_PORFORWARDING // Chiaming 20140520, fix TD 348 Scheduling time settings should be correct,An implementation MUST support the schedule configurations across 2 consecutive days
            getNvValue("Fw.PortForward_Schedule2", schedule);
	     if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
                if(!(strcmp(schedule,"")==0))
		  {
		      //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p tcp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p tcp --dport %s %s -j ACCEPT", eif, eif, shost, dhost, dport,schedule);
		  }
            }
#endif
#endif
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

  #if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
  //# Teidor 2012/11/13, fix bug (id:4615) DMZ can not be configured
  //#######################################################################################################

  //# DMZ NAT TCP port forwards
  //#######################
  //unset IFS
  
  /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
  #if 1           
  char tmpNatLoopbackBuf[255];
  char tmpNatLoopbackBuf2[255];
  char lanIfname[32];
  char wan_ifname[32];
  char dhcp_startSubNet[32];
  char erouterIPStr[32];
  int fd;
  struct ifreq ifr;
  int set_nat_loopback = 0;

  // Init all Buffer to 0
  memset(tmpNatLoopbackBuf, 0, sizeof(tmpNatLoopbackBuf));
  memset( tmpNatLoopbackBuf2, 0, sizeof(tmpNatLoopbackBuf2));
  memset(lanIfname, 0, sizeof(lanIfname));
  memset(wan_ifname, 0, sizeof(wan_ifname));
  memset(dhcp_startSubNet, 0, sizeof(dhcp_startSubNet));
  memset(erouterIPStr,0, sizeof(erouterIPStr));
  memset(&ifr, 0, sizeof(ifr));
  fd=0;
            
  // Getting LAN, WAN interfacename, and LAN DHCP start pull
#if defined(BCA_HNDROUTER) || defined(CONFIG_INTEL_SDK)
  strcpy(lanIfname, INT_IF);
  strcpy(wan_ifname, EXT_IF);
  strcpy(dhcp_startSubNet, INTERNAL_NET);
#else /* !BCA_HNDROUTER */
  getNvValue("Lan.ifname_1", lanIfname);
  getNvValue("Wan.ifname_1", wan_ifname);
  getNvValue("DhcpS.start_1", dhcp_startSubNet);
#endif /* !BCA_HNDROUTER */  
            
  // Getting eRouter IP 
  fd = socket(AF_INET, SOCK_DGRAM, 0);
  ifr.ifr_addr.sa_family = AF_INET;
  /* I want IP address attached to "erouter0" */
  strncpy(ifr.ifr_name, wan_ifname, IFNAMSIZ-1);
  if (ioctl(fd,SIOCGIFADDR,&ifr)<0) 
  {
      // If can't get eRouter IP, skipping IPABLES rules for NAT Loopback settings
      set_nat_loopback=0;
  }
  else
  {
  	  strcpy(erouterIPStr, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
      set_nat_loopback=1;
  }
  close(fd);

  #endif
  
  
  IFS = " ";  
  //for rule in $DMZ_TCP; do
  local22IFS = IFS;
  if (DMZ_TCP != NULL) strtok22_FREE = strdup(DMZ_TCP);
  if (DMZ_TCP != NULL) for (rule = strtok_r(strtok22_FREE, local22IFS, &r_DMZ_TCP1); rule != NULL; rule = strtok_r(NULL, local22IFS, &r_DMZ_TCP1))
  {
    //if_shosts_sports=`echo "$rule" |cut -s -d'>' -f1`
    rule1_FREE = getfield(rule, ">", 1);
    if_shosts_sports=rule1_FREE;;
    //interfaces=`get_ifs "$if_shosts_sports" "$EXT_IF"`
    if_shosts_sports1_FREE = get_ifs(if_shosts_sports, EXT_IF);
    interfaces=if_shosts_sports1_FREE;;
    //destips=`get_ips "$if_shosts_sports"`
    if_shosts_sports2_FREE = get_ips(if_shosts_sports, NULL);
    destips=if_shosts_sports2_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_sports" "0/0"`
    if_shosts_sports3_FREE = get_hosts_ihp(if_shosts_sports, "0/0");
    shosts=if_shosts_sports3_FREE;;
    //sports=`get_ports_ihp "$if_shosts_sports"`
    if_shosts_sports4_FREE = get_ports_ihp(if_shosts_sports, NULL);
    sports=if_shosts_sports4_FREE;;
    //dhost_dport=`echo "$rule" |cut -s -d'>' -f2`
    rule2_FREE = getfield(rule, ">", 2);
    dhost_dport=rule2_FREE;;
    //dhost=`get_hosts_hp "$dhost_dport"`
    dhost_dport1_FREE = get_hosts_hp(dhost_dport, NULL);
    dhost=dhost_dport1_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")DMZ(NAT) TCP port(s) $(show_hosts_ports "$shosts" "$sports") to $(echo "$dhost_dport" |tr "$SEP-" '::')"
    trsep1_FREE= stringcat(SEP, "-", NULL); tr1_FREE = tr(dhost_dport, trsep1_FREE, "::");
    show_hosts_ports1_FREE = show_hosts_ports(shosts, sports);
    show_if_ip1_FREE = show_if_ip(interfaces, destips);
    printf("%s DMZ(NAT) TCP port(s) %s  to %s;;" "\n", show_if_ip1_FREE, show_hosts_ports1_FREE, tr1_FREE);;
	
    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts1_FREE = ip_range(shosts, NULL);
    local23IFS = IFS;
    if (shosts1_FREE != NULL) strtok23_FREE = strdup(shosts1_FREE);
    if (shosts1_FREE != NULL) for (shost = strtok_r(strtok23_FREE, local23IFS, &r_shosts1_FREE1); shost != NULL; shost = strtok_r(NULL, local23IFS, &r_shosts1_FREE1))
    {
      //for sport in $sports; do
      local24IFS = IFS;
      if (sports != NULL) strtok24_FREE = strdup(sports);
      if (sports != NULL) for (sport = strtok_r(strtok24_FREE, local24IFS, &r_sports1); sport != NULL; sport = strtok_r(NULL, local24IFS, &r_sports1))
      {
        //for destip in $destips; do
        local25IFS = IFS;
        if (destips != NULL) strtok25_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok25_FREE, local25IFS, &r_destips1); destip != NULL; destip = strtok_r(NULL, local25IFS, &r_destips1))
        {
          //# Portforward for all specified interfaces
          //for eif in $interfaces; do
          local26IFS = IFS;
          if (interfaces != NULL) strtok26_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok26_FREE, local26IFS, &r_interfaces1); eif != NULL; eif = strtok_r(NULL, local26IFS, &r_interfaces1))
          {
            //# This code makes it possible to forward to a different port on the internal host
            //dport=`get_ports_hp "$dhost_dport" "$sport"`
            dhost_dport2_FREE = get_ports_hp(dhost_dport, sport);
            dport=dhost_dport2_FREE;;

            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p tcp --dport $sport -j DNAT --to-destination `echo "$dhost_dport" |tr "$SEP-" '::'`
            stringcat1_FREE = stringcat(SEP, "-");
            tr2_FREE = tr(dhost_dport, stringcat1_FREE, "::");
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p tcp --dport %s -j DNAT --to-destination %s", eif, shost, destip, sport, tr2_FREE);


            /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
            #if 1           
            if (set_nat_loopback == 1)
            {
                
                // We want to add below two rules for NAT LOOPBACK
                // iptables -t nat -A PREROUTING -p tcp -i l2sd0.2 -s 192.168.0.0/24 -d 10.4.2.117/32 --dport 21 -j DNAT --to-destination 192.168.0.27
                // iptables -t nat -A POSTROUTING -p tcp -s 192.168.0.0/24 -o l2sd0.2 -d 192.168.0.27 --dport 21 -j SNAT --to-source 10.4.2.117
#if (defined BCA_HNDROUTER) || (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK) /* Foxconn added by Max Ding, 02/24/2017 */
                sprintf(tmpNatLoopbackBuf, "-t nat -A PREROUTING  -p tcp -i %s -s %s -d %s/32 --dport %s -j DNAT --to-destination %s",lanIfname, dhcp_startSubNet, erouterIPStr, sport, tr2_FREE); 
                sprintf(tmpNatLoopbackBuf2, "-t nat -A POSTROUTING -p tcp -s %s -o %s -d %s --dport %s -j SNAT --to-source %s",
                        dhcp_startSubNet, 
                        lanIfname, 
                        tr2_FREE,
                        sport,
                        erouterIPStr );
#else
                sprintf(tmpNatLoopbackBuf, "-t nat -A PREROUTING  -p tcp -i %s -s %s/24 -d %s/32 --dport %s -j DNAT --to-destination %s",lanIfname, dhcp_startSubNet, erouterIPStr, sport, tr2_FREE); 
                sprintf(tmpNatLoopbackBuf2, "-t nat -A POSTROUTING -p tcp -s %s/24 -o %s -d %s --dport %s -j SNAT --to-source %s",
                        dhcp_startSubNet, 
                        lanIfname, 
                        tr2_FREE,
                        sport,
                        erouterIPStr );
#endif
            
                ip4tables(tmpNatLoopbackBuf); 
                ip4tables(tmpNatLoopbackBuf2);
           }
           #endif


            /* [Foxc] Poosa, 2014/10/14, [TD#10] C6350-100PAS: There is no log for external ip access. */
#if (defined BCA_HNDROUTER) || (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK) /* Foxconn added by Max Ding, 02/24/2017 */
            //to be added
#else
            ip4tables("-t nat -A POSTROUTING -o l2sd0.2 -p tcp --dport %s -j LOG --log-prefix REMOTE_ACCESS --log-level 5", sport);
#endif

            //if [ -n "$dhost" ]; then
            if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
            /* foxconn add start, for UDP port scan drop from erouter0, Jonathan 2013/5/14 */
            #if 0 /* move to arno_interface.c */
            
              //iptables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -m length --length 0:28 -j LOG --log-prefix "DOS: Port Scan " --log-level 6
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s -m length --length 0:28 -j LOG --log-prefix \"DOS: Port Scan \" --log-level 6", eif, eif, shost, dhost, dport);
              //iptables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -m length --length 0:28 -j DROP
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s -m length --length 0:28 -j DROP", eif, eif, shost, dhost, dport);
            #endif
            /* foxconn add end, for UDP port scan drop from erouter0, Jonathan 2013/5/2 */
            
              //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p tcp --dport $dport -j ACCEPT
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p tcp --dport %s -j ACCEPT", eif, eif, shost, dhost, dport);
            //fi
            }
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }  
#endif

  //# NAT UDP port forwards
  //#######################
  //unset IFS
  IFS = " ";
  //for rule in $NAT_FORWARD_UDP; do
  local27IFS = IFS;
  if (NAT_FORWARD_UDP != NULL) strtok27_FREE = strdup(NAT_FORWARD_UDP);
  if (NAT_FORWARD_UDP != NULL) for (rule = strtok_r(strtok27_FREE, local27IFS, &r_NAT_FORWARD_UDP1); rule != NULL; rule = strtok_r(NULL, local27IFS, &r_NAT_FORWARD_UDP1))
  {
    //if_shosts_sports=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts_sports=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts_sports" "$EXT_IF"`
    if_shosts_sports5_FREE = get_ifs(if_shosts_sports, EXT_IF);
    interfaces=if_shosts_sports5_FREE;;
    //destips=`get_ips "$if_shosts_sports"`
    if_shosts_sports6_FREE = get_ips(if_shosts_sports, NULL);
    destips=if_shosts_sports6_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_sports" "0/0"`
    if_shosts_sports7_FREE = get_hosts_ihp(if_shosts_sports, "0/0");
    shosts=if_shosts_sports7_FREE;;
    //sports=`get_ports_ihp "$if_shosts_sports"`
    if_shosts_sports8_FREE = get_ports_ihp(if_shosts_sports, NULL);
    sports=if_shosts_sports8_FREE;;
    //dhost_dport=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhost_dport=rule4_FREE;;
    //dhost=`get_hosts_hp "$dhost_dport"`
    dhost_dport3_FREE = get_hosts_hp(dhost_dport, NULL);
    dhost=dhost_dport3_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Forwarding(NAT) UDP port(s) $(show_hosts_ports "$shosts" "$sports") to $(echo "$dhost_dport" |tr "$SEP-" '::')"
    trsep2_FREE= stringcat(SEP, "-", NULL); tr3_FREE = tr(dhost_dport, trsep2_FREE, "::");
    show_hosts_ports2_FREE = show_hosts_ports(shosts, sports);
    show_if_ip2_FREE = show_if_ip(interfaces, destips);
    printf("%s Forwarding(NAT) UDP port(s) %s  to %s;;" "\n", show_if_ip2_FREE, show_hosts_ports2_FREE, tr3_FREE);;

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local28IFS = IFS;
    if (shosts2_FREE != NULL) strtok28_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok28_FREE, local28IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local28IFS, &r_shosts2_FREE1))
    {
      //for sport in $sports; do
      local29IFS = IFS;
      if (sports != NULL) strtok29_FREE = strdup(sports);
      if (sports != NULL) for (sport = strtok_r(strtok29_FREE, local29IFS, &r_sports2); sport != NULL; sport = strtok_r(NULL, local29IFS, &r_sports2))
      {
        //for destip in $destips; do
        local30IFS = IFS;
        if (destips != NULL) strtok30_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok30_FREE, local30IFS, &r_destips2); destip != NULL; destip = strtok_r(NULL, local30IFS, &r_destips2))
        {
          //# Portforward for all specified interfaces
          //for eif in $interfaces; do
          local31IFS = IFS;
          if (interfaces != NULL) strtok31_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok31_FREE, local31IFS, &r_interfaces2); eif != NULL; eif = strtok_r(NULL, local31IFS, &r_interfaces2))
          {
            //# This code makes it possible to forward to a different port on the internal host
            //dport=`get_ports_hp "$dhost_dport" "$sport"`
            dhost_dport4_FREE = get_ports_hp(dhost_dport, sport);
            dport=dhost_dport4_FREE;;

            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p udp --dport $sport -j DNAT --to-destination `echo "$dhost_dport" |tr "$SEP-" '::'`
            stringcat2_FREE = stringcat(SEP, "-");
            tr4_FREE = tr(dhost_dport, stringcat2_FREE, "::");
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p udp --dport %s -j DNAT --to-destination %s", eif, shost, destip, sport, tr4_FREE);
            //if [ -n "$dhost" ]; then
#ifdef CABLE_PORTFORWARD  //Chiaming add 2013/07/15
            getNvValue("Fw.PortForward_Schedule", schedule);
	     if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
                if(strcmp(schedule,"")==0)
	         {
	             //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s -j ACCEPT", eif, eif, shost, dhost, dport);
            	  }
		  else
		  {
		      //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s %s -j ACCEPT", eif, eif, shost, dhost, dport,schedule);
		  }
            }
            //Chiaming add end 2013/07/15
#if 1 // Chiaming 20140520, fix TD 348 Scheduling time settings should be correct,An implementation MUST support the schedule configurations across 2 consecutive days
            getNvValue("Fw.PortForward_Schedule2", schedule);
	     if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
                if(!(strcmp(schedule,"")==0))
		  {
		      //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -j ACCEPT
                    ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s %s -j ACCEPT", eif, eif, shost, dhost, dport,schedule);
		  }
            }
#endif
#endif
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
//# Teidor 2012/11/13, fix bug (id:4615) DMZ can not be configured
  //#######################
  //unset IFS
  IFS = " ";
  //for rule in $DMZ_UDP; do
  local27IFS = IFS;
  if (DMZ_UDP != NULL) strtok27_FREE = strdup(DMZ_UDP);
  if (DMZ_UDP != NULL) for (rule = strtok_r(strtok27_FREE, local27IFS, &r_DMZ_UDP1); rule != NULL; rule = strtok_r(NULL, local27IFS, &r_DMZ_UDP1))
  {
    //if_shosts_sports=`echo "$rule" |cut -s -d'>' -f1`
    rule3_FREE = getfield(rule, ">", 1);
    if_shosts_sports=rule3_FREE;;
    //interfaces=`get_ifs "$if_shosts_sports" "$EXT_IF"`
    if_shosts_sports5_FREE = get_ifs(if_shosts_sports, EXT_IF);
    interfaces=if_shosts_sports5_FREE;;
    //destips=`get_ips "$if_shosts_sports"`
    if_shosts_sports6_FREE = get_ips(if_shosts_sports, NULL);
    destips=if_shosts_sports6_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_sports" "0/0"`
    if_shosts_sports7_FREE = get_hosts_ihp(if_shosts_sports, "0/0");
    shosts=if_shosts_sports7_FREE;;
    //sports=`get_ports_ihp "$if_shosts_sports"`
    if_shosts_sports8_FREE = get_ports_ihp(if_shosts_sports, NULL);
    sports=if_shosts_sports8_FREE;;
    //dhost_dport=`echo "$rule" |cut -s -d'>' -f2`
    rule4_FREE = getfield(rule, ">", 2);
    dhost_dport=rule4_FREE;;
    //dhost=`get_hosts_hp "$dhost_dport"`
    dhost_dport3_FREE = get_hosts_hp(dhost_dport, NULL);
    dhost=dhost_dport3_FREE;;
    //echo "$(show_if_ip "$interfaces" "$destips")DMZ(NAT) UDP port(s) $(show_hosts_ports "$shosts" "$sports") to $(echo "$dhost_dport" |tr "$SEP-" '::')"
    trsep2_FREE= stringcat(SEP, "-", NULL); tr3_FREE = tr(dhost_dport, trsep2_FREE, "::");
    show_hosts_ports2_FREE = show_hosts_ports(shosts, sports);
    show_if_ip2_FREE = show_if_ip(interfaces, destips);
    printf("%s DMZ(NAT) UDP port(s) %s  to %s;;" "\n", show_if_ip2_FREE, show_hosts_ports2_FREE, tr3_FREE);;

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts2_FREE = ip_range(shosts, NULL);
    local28IFS = IFS;
    if (shosts2_FREE != NULL) strtok28_FREE = strdup(shosts2_FREE);
    if (shosts2_FREE != NULL) for (shost = strtok_r(strtok28_FREE, local28IFS, &r_shosts2_FREE1); shost != NULL; shost = strtok_r(NULL, local28IFS, &r_shosts2_FREE1))
    {
      //for sport in $sports; do
      local29IFS = IFS;
      if (sports != NULL) strtok29_FREE = strdup(sports);
      if (sports != NULL) for (sport = strtok_r(strtok29_FREE, local29IFS, &r_sports2); sport != NULL; sport = strtok_r(NULL, local29IFS, &r_sports2))
      {
        //for destip in $destips; do
        local30IFS = IFS;
        if (destips != NULL) strtok30_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok30_FREE, local30IFS, &r_destips2); destip != NULL; destip = strtok_r(NULL, local30IFS, &r_destips2))
        {
          //# Portforward for all specified interfaces
          //for eif in $interfaces; do
          local31IFS = IFS;
          if (interfaces != NULL) strtok31_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok31_FREE, local31IFS, &r_interfaces2); eif != NULL; eif = strtok_r(NULL, local31IFS, &r_interfaces2))
          {
            //# This code makes it possible to forward to a different port on the internal host
            //dport=`get_ports_hp "$dhost_dport" "$sport"`
            dhost_dport4_FREE = get_ports_hp(dhost_dport, sport);
            dport=dhost_dport4_FREE;;

            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p udp --dport $sport -j DNAT --to-destination `echo "$dhost_dport" |tr "$SEP-" '::'`
            stringcat2_FREE = stringcat(SEP, "-");
            tr4_FREE = tr(dhost_dport, stringcat2_FREE, "::");
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p udp --dport %s -j DNAT --to-destination %s", eif, shost, destip, sport, tr4_FREE);


            /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
            #if 1           
            if (set_nat_loopback == 1)
            {
                // We want to add below two rules for NAT LOOPBACK
                // iptables -t nat -A PREROUTING -p udp -i l2sd0.2 -s 192.168.0.0/24 -d 10.4.2.117/32 --dport 21 -j DNAT --to-destination 192.168.0.27
                // iptables -t nat -A POSTROUTING -p udp -s 192.168.0.0/24 -o l2sd0.2 -d 192.168.0.27 --dport 21 -j MASQUERADE
#if (defined BCA_HNDROUTER) || (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK)  /* Foxconn added by Max Ding, 02/24/2017 */
                sprintf(tmpNatLoopbackBuf, "-t nat -A PREROUTING  -p udp -i %s -s %s -d %s/32 --dport %s -j DNAT --to-destination %s",lanIfname, dhcp_startSubNet, erouterIPStr, sport, tr2_FREE); 
                sprintf(tmpNatLoopbackBuf2, "-t nat -A POSTROUTING -p udp -s %s -o %s -d %s --dport %s -j SNAT --to %s",
                        dhcp_startSubNet, 
                        lanIfname, 
                        tr2_FREE,
                        sport,
                        erouterIPStr);
                printf("tmpNatLoopbackBuf: %s\n", tmpNatLoopbackBuf);
                printf("tmpNatLoopbackBuf2: %s\n", tmpNatLoopbackBuf2);
#else
                sprintf(tmpNatLoopbackBuf, "-t nat -A PREROUTING  -p udp -i %s -s %s/24 -d %s/32 --dport %s -j DNAT --to-destination %s",lanIfname, dhcp_startSubNet, erouterIPStr, sport, tr2_FREE); 
                sprintf(tmpNatLoopbackBuf2, "-t nat -A POSTROUTING -p udp -s %s/24 -o %s -d %s --dport %s -j SNAT --to %s",
                        dhcp_startSubNet, 
                        lanIfname, 
                        tr2_FREE,
                        sport,
                        erouterIPStr);
#endif
                              
                ip4tables(tmpNatLoopbackBuf); 
                ip4tables(tmpNatLoopbackBuf2);
           }
           #endif



            /* [Foxc] Poosa, 2014/10/14, [TD#10] C6350-100PAS: There is no log for external ip access. */
#if (defined BCA_HNDROUTER) || (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK) /* Foxconn added by Max Ding, 02/24/2017 */
            //to be added
#else
            ip4tables("-t nat -A POSTROUTING -o l2sd0.2 -p udp --dport %s -j LOG --log-prefix REMOTE_ACCESS --log-level 5", sport);
#endif

            //if [ -n "$dhost" ]; then
            if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
              //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p udp --dport $dport -j ACCEPT
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p udp --dport %s -j ACCEPT", eif, eif, shost, dhost, dport);
            //fi
            }
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }
  
    //# Mos 2012/12/20 added 
    //# add for dns hijack
    //#iptables -t nat -I PREROUTING -i l2sd0.2 -p udp --dport 53 -j REDIRECT --to-ports 53
    /* [Foxc] IvyChen, 2014/12/25, [TD#596]C6300-100NAS: Disable isolation, 2.4G and 5G Guest client can not access to usb:readyshare. (For DNS issue)*/
#ifdef CABLE_DNSHIJACK    
    getNvValue("Lan.ifname_1", lan_ifname);
    getNvValue("DhcpS.start_1", dhcp_start);
    getNvValue("DhcpS.end_1", dhcp_end);
    ip4tables("-t nat -I PREROUTING -i %s -p udp --dport 53 -m iprange --src-range %s-%s -j REDIRECT --to-ports 53", lan_ifname, dhcp_start, dhcp_end );
    getNvValue("Lan.ifname_2", lan_ifname);
    getNvValue("DhcpS.start_2", dhcp_start);
    getNvValue("DhcpS.end_2", dhcp_end);
    ip4tables("-t nat -I PREROUTING -i %s -p udp --dport 53 -m iprange --src-range %s-%s -j REDIRECT --to-ports 53", lan_ifname, dhcp_start, dhcp_end );
    getNvValue("Lan.ifname_10", lan_ifname);
    getNvValue("DhcpS.start_10", dhcp_start);
    getNvValue("DhcpS.end_10", dhcp_end);
    ip4tables("-t nat -I PREROUTING -i %s -p udp --dport 53 -m iprange --src-range %s-%s -j REDIRECT --to-ports 53", lan_ifname, dhcp_start, dhcp_end );
#endif /* CABLE_DNSHIJACK */
#endif

  //# Non-TCP/UDP port forwards (protocol based)
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $NAT_FORWARD_IP; do
  local32IFS = IFS;
  if (NAT_FORWARD_IP != NULL) strtok32_FREE = strdup(NAT_FORWARD_IP);
  if (NAT_FORWARD_IP != NULL) for (rule = strtok_r(strtok32_FREE, local32IFS, &r_NAT_FORWARD_IP1); rule != NULL; rule = strtok_r(NULL, local32IFS, &r_NAT_FORWARD_IP1))
  {
    //if_shosts_protos=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts_protos=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts_protos" "$EXT_IF"`
    if_shosts_protos1_FREE = get_ifs(if_shosts_protos, EXT_IF);
    interfaces=if_shosts_protos1_FREE;;
    //destips=`get_ips "$if_shosts_protos"`
    if_shosts_protos2_FREE = get_ips(if_shosts_protos, NULL);
    destips=if_shosts_protos2_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_protos" "0/0"`
    if_shosts_protos3_FREE = get_hosts_ihp(if_shosts_protos, "0/0");
    shosts=if_shosts_protos3_FREE;;
    //protos=`get_ports_ihp "$if_shosts_protos"`
    if_shosts_protos4_FREE = get_ports_ihp(if_shosts_protos, NULL);
    protos=if_shosts_protos4_FREE;;
    //dhost=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhost=rule6_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Forwarding(NAT) IP protocol(s) $(show_hosts_ports "$shosts" "$protos") to $dhost"
    show_hosts_ports3_FREE = show_hosts_ports(shosts, protos);
    show_if_ip3_FREE = show_if_ip(interfaces, destips);
    printf("%s Forwarding(NAT) IP protocol(s) %s  to %s;;" "\n", show_if_ip3_FREE, show_hosts_ports3_FREE, dhost);

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local33IFS = IFS;
    if (shosts3_FREE != NULL) strtok33_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok33_FREE, local33IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local33IFS, &r_shosts3_FREE1))
    {
      //for proto in $protos; do
      local34IFS = IFS;
      if (protos != NULL) strtok34_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok34_FREE, local34IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local34IFS, &r_protos1))
      {
        //for destip in $destips; do
        local35IFS = IFS;
        if (destips != NULL) strtok35_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok35_FREE, local35IFS, &r_destips3); destip != NULL; destip = strtok_r(NULL, local35IFS, &r_destips3))
        {
          //for eif in $interfaces; do
          local36IFS = IFS;
          if (interfaces != NULL) strtok36_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok36_FREE, local36IFS, &r_interfaces3); eif != NULL; eif = strtok_r(NULL, local36IFS, &r_interfaces3))
          {
            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p $proto -j DNAT --to-destination $dhost
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p %s -j DNAT --to-destination %s", eif, shost, destip, proto, dhost);
            //if [ -n "$dhost" ]; then
            if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
              //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p $proto -j ACCEPT
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p %s -j ACCEPT", eif, eif, shost, dhost, proto);
            //fi
            }
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }

#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
//# Teidor 2012/11/13, fix bug (id:4615) DMZ can not be configured
//# DMZ Non-TCP/UDP port forwards (protocol based)
  //############################################
  //unset IFS
  IFS = " ";
  //for rule in $NAT_FORWARD_IP; do
  local32IFS = IFS;
  if (DMZ_NAT_IP != NULL) strtok32_FREE = strdup(DMZ_NAT_IP);
  if (DMZ_NAT_IP != NULL) for (rule = strtok_r(strtok32_FREE, local32IFS, &r_DMZ_NAT_IP1); rule != NULL; rule = strtok_r(NULL, local32IFS, &r_DMZ_NAT_IP1))
  {
    //if_shosts_protos=`echo "$rule" |cut -s -d'>' -f1`
    rule5_FREE = getfield(rule, ">", 1);
    if_shosts_protos=rule5_FREE;;
    //interfaces=`get_ifs "$if_shosts_protos" "$EXT_IF"`
    if_shosts_protos1_FREE = get_ifs(if_shosts_protos, EXT_IF);
    interfaces=if_shosts_protos1_FREE;;
    //destips=`get_ips "$if_shosts_protos"`
    if_shosts_protos2_FREE = get_ips(if_shosts_protos, NULL);
    destips=if_shosts_protos2_FREE;;
    //shosts=`get_hosts_ihp "$if_shosts_protos" "0/0"`
    if_shosts_protos3_FREE = get_hosts_ihp(if_shosts_protos, "0/0");
    shosts=if_shosts_protos3_FREE;;
    //protos=`get_ports_ihp "$if_shosts_protos"`
    if_shosts_protos4_FREE = get_ports_ihp(if_shosts_protos, NULL);
    protos=if_shosts_protos4_FREE;;
    //dhost=`echo "$rule" |cut -s -d'>' -f2`
    rule6_FREE = getfield(rule, ">", 2);
    dhost=rule6_FREE;;

    //echo "$(show_if_ip "$interfaces" "$destips")Forwarding(NAT) IP protocol(s) $(show_hosts_ports "$shosts" "$protos") to $dhost"
    show_hosts_ports3_FREE = show_hosts_ports(shosts, protos);
    show_if_ip3_FREE = show_if_ip(interfaces, destips);
    printf("%s DMZ(NAT) IP protocol(s) %s  to %s;;" "\n", show_if_ip3_FREE, show_hosts_ports3_FREE, dhost);

    //IFS=' ,'
    IFS=" ,";
    //for shost in `ip_range "$shosts"`; do
    shosts3_FREE = ip_range(shosts, NULL);
    local33IFS = IFS;
    if (shosts3_FREE != NULL) strtok33_FREE = strdup(shosts3_FREE);
    if (shosts3_FREE != NULL) for (shost = strtok_r(strtok33_FREE, local33IFS, &r_shosts3_FREE1); shost != NULL; shost = strtok_r(NULL, local33IFS, &r_shosts3_FREE1))
    {
      //for proto in $protos; do
      local34IFS = IFS;
      if (protos != NULL) strtok34_FREE = strdup(protos);
      if (protos != NULL) for (proto = strtok_r(strtok34_FREE, local34IFS, &r_protos1); proto != NULL; proto = strtok_r(NULL, local34IFS, &r_protos1))
      {
        //for destip in $destips; do
        local35IFS = IFS;
        if (destips != NULL) strtok35_FREE = strdup(destips);
        if (destips != NULL) for (destip = strtok_r(strtok35_FREE, local35IFS, &r_destips3); destip != NULL; destip = strtok_r(NULL, local35IFS, &r_destips3))
        {
          //for eif in $interfaces; do
          local36IFS = IFS;
          if (interfaces != NULL) strtok36_FREE = strdup(interfaces);
          if (interfaces != NULL) for (eif = strtok_r(strtok36_FREE, local36IFS, &r_interfaces3); eif != NULL; eif = strtok_r(NULL, local36IFS, &r_interfaces3))
          {
            //ip4tables -t nat -A PREROUTING -i $eif -s $shost -d $destip -p $proto -j DNAT --to-destination $dhost
            ip4tables("-t nat -A PREROUTING -i %s -s %s -d %s -p %s -j DNAT --to-destination %s", eif, shost, destip, proto, dhost);
            //if [ -n "$dhost" ]; then
            if  (  ((dhost!=NULL)&&(strlen(dhost)!=0))  )
            {
              //ip4tables -A EXT_FORWARD_IN_CHAIN -i $eif ! -o $eif -s $shost -d $dhost -p $proto -j ACCEPT
              ip4tables("-A EXT_FORWARD_IN_CHAIN -i %s ! -o %s -s %s -d %s -p %s -j ACCEPT", eif, eif, shost, dhost, proto);
            //fi
            }
          //done
          }
        //done
        }
      //done
      }
    //done
    }
  //done
  }
#endif
  //# Setup rules to allow INET IPv6 and non-NAT'ed IPv4 traffic in FORWARD chain
  //setup_inet_forward_rules;
  setup_inet_forward_rules();

  //# Do we want to loose the forward chain to make use of protocols like UPnP possible?
  //####################################################################################
  //if [ "$LOOSE_FORWARD" = "1" ]; then
  if  (  (strcmp(LOOSE_FORWARD,"1")==0)  )
  {
    //echo "Security is LOOSENED for external interface(s) in the FORWARD chain!"
    printf("Security is LOOSENED for external interface(s) in the FORWARD chain!" "\n");
    //# Loose the forward chain
    //IFS=' ,'
    IFS=" ,";
    //for eif in $EXT_IF; do
    local37IFS = IFS;
    if (EXT_IF != NULL) strtok37_FREE = strdup(EXT_IF);
    if (EXT_IF != NULL) for (eif = strtok_r(strtok37_FREE, local37IFS, &r_EXT_IF7); eif != NULL; eif = strtok_r(NULL, local37IFS, &r_EXT_IF7))
    {
      //iptables -A FORWARD -i $eif ! -o $eif -j ACCEPT
      iptables("-A FORWARD -i %s ! -o %s -j ACCEPT", eif, eif);
    //done
    }
  //else
  }
  else
  {
    //echo "Security is ENFORCED for external interface(s) in the FORWARD chain"
    printf("Security is ENFORCED for external interface(s) in the FORWARD chain" "\n");
  //fi
  }

  //# Jump to the post forward chain
  //iptables -A FORWARD -j POST_FORWARD_CHAIN
  iptables("-A FORWARD -j POST_FORWARD_CHAIN");
  
  //# Everything else is logged & dropped in FORWARD
  //if [ "$FORWARD_DROP_LOG" != "0" ]; then
  if  (  (strcmp(FORWARD_DROP_LOG,"0")!=0)  )
  {
    //echo " Logging of dropped FORWARD packets enabled"
    printf(" Logging of dropped FORWARD packets enabled" "\n");
    //iptables -A FORWARD -m limit --limit 1/m  --limit-burst 3 -j LOG --log-level $LOGLEVEL --log-prefix "AIF:Dropped FORWARD packet: "
    iptables("-A FORWARD -m limit --limit 1/m  --limit-burst 3 -j LOG --log-prefix \"AIF:Dropped FORWARD packet: \" --log-level %s", LOGLEVEL);
  //else
  }
  else
  {
    //echo " Logging of dropped FORWARD packets disabled"
    printf(" Logging of dropped FORWARD packets disabled" "\n");
  //fi
  }

  //# Allow forward traffic from "trusted-if"
  //#########################################
  //if [ -n "$TRUSTED_IF" ]; then
  if  (  ((TRUSTED_IF!=NULL)&&(strlen(TRUSTED_IF)!=0))  )
  {
    //echo "Accepting ALL FORWARD packets for trusted interface(s): $TRUSTED_IF"
    printf("Accepting ALL FORWARD packets for trusted interface(s): %s" "\n", TRUSTED_IF);
    //IFS=' ,'
    IFS=" ,";
    //for interface in $TRUSTED_IF; do
    local6IFS = IFS;
    if (TRUSTED_IF != NULL) strtok6_FREE = strdup(TRUSTED_IF);
    if (TRUSTED_IF != NULL) for (interface = strtok_r(strtok6_FREE, local6IFS, &r_TRUSTED_IF2); interface != NULL; interface = strtok_r(NULL, local6IFS, &r_TRUSTED_IF2))
    {
      //# Allow forward traffic in:
      //iptables -A FORWARD -i $interface -j ACCEPT
      iptables("-A FORWARD -i %s -j ACCEPT", interface);
      //# Allow forward traffic out:
      //iptables -A FORWARD -o $interface -j ACCEPT
      iptables("-A FORWARD -o %s -j ACCEPT", interface);
    //done
    }
  //fi
  }

  system("/usr/sbin/agApi_fwSetTriggerConfByNvram.sh");

  //iptables -A FORWARD -j DROP
  iptables("-A FORWARD -j DROP");

  //# Post/pre routing post chains
  //ip4tables -t nat -A PREROUTING -j POST_NAT_PREROUTING_CHAIN
  ip4tables("-t nat -A PREROUTING -j POST_NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -A POSTROUTING -j POST_NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -A POSTROUTING -j POST_NAT_POSTROUTING_CHAIN");

   /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
  ip4tables("-t nat -A POSTROUTING -j POST_PORTFORWARD_CHAIN");
   
  ip4tables("-t nat -A POSTROUTING -j OPENVPN_POSTROUTING_CHAIN");

  //# Mark outgoing packets for traffic shaping?
  //############################################
  //#if [ "$TRAFFIC_SHAPING" = "1" ]; then
  //#  iptables -t mangle -I OUTPUT -m length --length 0:500 -j MARK --set-mark 1
  //#  iptables -t mangle -I OUTPUT -m length --length 500:1500 -j MARK --set-mark 2
  //#fi

  //# Jump to the post output chain
  //iptables -A OUTPUT -j POST_OUTPUT_CHAIN
  iptables("-A OUTPUT -j POST_OUTPUT_CHAIN");
  
  //# Everything else is accepted in OUTPUT
  //iptables -A OUTPUT -j ACCEPT
  iptables("-A OUTPUT -j ACCEPT");

  //# Clean-up DNS output rules
  //iptables -D OUTPUT_CHAIN 2
  iptables("-D OUTPUT_CHAIN 2");
  //iptables -D OUTPUT_CHAIN 1
  iptables("-D OUTPUT_CHAIN 1");
if (strtok1_FREE != NULL) free(strtok1_FREE);
if (show_hosts_ports2_FREE != NULL) free(show_hosts_ports2_FREE);
if (if_shosts_protos1_FREE != NULL) free(if_shosts_protos1_FREE);
if (strtok10_FREE != NULL) free(strtok10_FREE);
if (strtok22_FREE != NULL) free(strtok22_FREE);
if (strtok19_FREE != NULL) free(strtok19_FREE);
if (dhost_dport3_FREE != NULL) free(dhost_dport3_FREE);
if (strtok14_FREE != NULL) free(strtok14_FREE);
if (strtok34_FREE != NULL) free(strtok34_FREE);
if (if_shosts_sports4_FREE != NULL) free(if_shosts_sports4_FREE);
if (awk1_FREE != NULL) free(awk1_FREE);
if (tr4_FREE != NULL) free(tr4_FREE);
if (strtok26_FREE != NULL) free(strtok26_FREE);
if (stringcat1_FREE != NULL) free(stringcat1_FREE);
if (strtok5_FREE != NULL) free(strtok5_FREE);
if (rule2_FREE != NULL) free(rule2_FREE);
if (show_if_ip3_FREE != NULL) free(show_if_ip3_FREE);
if (strtok9_FREE != NULL) free(strtok9_FREE);
if (show_hosts_ports1_FREE != NULL) free(show_hosts_ports1_FREE);
if (strtok21_FREE != NULL) free(strtok21_FREE);
if (strtok18_FREE != NULL) free(strtok18_FREE);
if (if_shosts_sports8_FREE != NULL) free(if_shosts_sports8_FREE);
if (dhost_dport2_FREE != NULL) free(dhost_dport2_FREE);
if (strtok13_FREE != NULL) free(strtok13_FREE);
if (strtok33_FREE != NULL) free(strtok33_FREE);
if (rule6_FREE != NULL) free(rule6_FREE);
if (if_shosts_sports3_FREE != NULL) free(if_shosts_sports3_FREE);
if (tr3_FREE != NULL) free(tr3_FREE);
if (strtok25_FREE != NULL) free(strtok25_FREE);
if (strtok4_FREE != NULL) free(strtok4_FREE);
if (rule1_FREE != NULL) free(rule1_FREE);
if (strtok37_FREE != NULL) free(strtok37_FREE);
if (trsep2_FREE != NULL) free(trsep2_FREE);
if (show_if_ip2_FREE != NULL) free(show_if_ip2_FREE);
if (strtok8_FREE != NULL) free(strtok8_FREE);
if (if_shosts_protos4_FREE != NULL) free(if_shosts_protos4_FREE);
if (strtok20_FREE != NULL) free(strtok20_FREE);
if (strtok17_FREE != NULL) free(strtok17_FREE);
if (if_shosts_sports7_FREE != NULL) free(if_shosts_sports7_FREE);
if (dhost_dport1_FREE != NULL) free(dhost_dport1_FREE);
if (shosts3_FREE != NULL) free(shosts3_FREE);
if (strtok32_FREE != NULL) free(strtok32_FREE);
if (strtok29_FREE != NULL) free(strtok29_FREE);
if (rule5_FREE != NULL) free(rule5_FREE);
if (if_shosts_sports2_FREE != NULL) free(if_shosts_sports2_FREE);
if (tr2_FREE != NULL) free(tr2_FREE);
if (strtok3_FREE != NULL) free(strtok3_FREE);
if (trsep1_FREE != NULL) free(trsep1_FREE);
if (show_if_ip1_FREE != NULL) free(show_if_ip1_FREE);
if (strtok7_FREE != NULL) free(strtok7_FREE);
if (if_shosts_protos3_FREE != NULL) free(if_shosts_protos3_FREE);
if (strtok12_FREE != NULL) free(strtok12_FREE);
if (strtok24_FREE != NULL) free(strtok24_FREE);
if (strtok16_FREE != NULL) free(strtok16_FREE);
if (strtok36_FREE != NULL) free(strtok36_FREE);
if (if_shosts_sports6_FREE != NULL) free(if_shosts_sports6_FREE);
if (strtok31_FREE != NULL) free(strtok31_FREE);
if (strtok28_FREE != NULL) free(strtok28_FREE);
if (shosts2_FREE != NULL) free(shosts2_FREE);
if (rule4_FREE != NULL) free(rule4_FREE);
if (tr1_FREE != NULL) free(tr1_FREE);
if (strtok2_FREE != NULL) free(strtok2_FREE);
if (show_hosts_ports3_FREE != NULL) free(show_hosts_ports3_FREE);
if (if_shosts_protos2_FREE != NULL) free(if_shosts_protos2_FREE);
if (strtok11_FREE != NULL) free(strtok11_FREE);
if (if_shosts_sports1_FREE != NULL) free(if_shosts_sports1_FREE);
if (strtok23_FREE != NULL) free(strtok23_FREE);
if (dhost_dport4_FREE != NULL) free(dhost_dport4_FREE);
if (strtok15_FREE != NULL) free(strtok15_FREE);
if (strtok35_FREE != NULL) free(strtok35_FREE);
if (if_shosts_sports5_FREE != NULL) free(if_shosts_sports5_FREE);
if (awk2_FREE != NULL) free(awk2_FREE);
if (strtok30_FREE != NULL) free(strtok30_FREE);
if (strtok27_FREE != NULL) free(strtok27_FREE);
if (shosts1_FREE != NULL) free(shosts1_FREE);
if (stringcat2_FREE != NULL) free(stringcat2_FREE);
if (strtok6_FREE != NULL) free(strtok6_FREE);
if (rule3_FREE != NULL) free(rule3_FREE);

//}
}


//# Create our custom chains
void //create_user_chains()
create_user_chains(void)
//{
{
  //# General chains
  //iptables -N HOST_BLOCK_SRC
  iptables("-N HOST_BLOCK_SRC");
  //iptables -N HOST_BLOCK_DST
  iptables("-N HOST_BLOCK_DST");
  //iptables -N HOST_BLOCK_DROP
  iptables("-N HOST_BLOCK_DROP");
  //iptables -N VALID_CHK
  iptables("-N VALID_CHK");
  //iptables -N RESERVED_NET_CHK
  iptables("-N RESERVED_NET_CHK");
  //iptables -N SPOOF_CHK
  iptables("-N SPOOF_CHK");
  //iptables -N INPUT_CHAIN
  iptables("-N INPUT_CHAIN");
  //iptables -N FORWARD_CHAIN
  iptables("-N FORWARD_CHAIN");
  //iptables -N OUTPUT_CHAIN
  iptables("-N OUTPUT_CHAIN");
  //ip4tables -t nat -N NAT_PREROUTING_CHAIN
  ip4tables("-t nat -N NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -N NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -N NAT_POSTROUTING_CHAIN");
  //iptables -N POST_INPUT_DROP_CHAIN
  iptables("-N POST_INPUT_DROP_CHAIN");
  //iptables -N POST_INPUT_CHAIN
  iptables("-N POST_INPUT_CHAIN");
  //iptables -N POST_FORWARD_CHAIN
  iptables("-N POST_FORWARD_CHAIN");
  //iptables -N POST_OUTPUT_CHAIN
  iptables("-N POST_OUTPUT_CHAIN");
  //ip4tables -t nat -N POST_NAT_PREROUTING_CHAIN
  ip4tables("-t nat -N POST_NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -N POST_NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -N POST_NAT_POSTROUTING_CHAIN");

  /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
  ip4tables("-t nat -N POST_PORTFORWARD_CHAIN");

  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //ip6tables -N LINK_LOCAL_DROP
    ip6tables("-N LINK_LOCAL_DROP");
  //fi
  }

  //# Interface-2-interface chains
  //iptables -N DMZ_LAN_FORWARD_CHAIN
  iptables("-N DMZ_LAN_FORWARD_CHAIN");
  //iptables -N INET_DMZ_FORWARD_CHAIN
  iptables("-N INET_DMZ_FORWARD_CHAIN");
  //iptables -N DMZ_INET_FORWARD_CHAIN
  iptables("-N DMZ_INET_FORWARD_CHAIN");
  //iptables -N LAN_INET_FORWARD_CHAIN
  iptables("-N LAN_INET_FORWARD_CHAIN");

  //# Chains for the external interface
  //iptables -N EXT_MULTICAST_CHAIN
  iptables("-N EXT_MULTICAST_CHAIN");
  //iptables -N EXT_BROADCAST_CHAIN
  iptables("-N EXT_BROADCAST_CHAIN");
  //iptables -N EXT_ICMP_FLOOD_CHAIN
  iptables("-N EXT_ICMP_FLOOD_CHAIN");
  //iptables -N EXT_INPUT_CHAIN
  iptables("-N EXT_INPUT_CHAIN");
  //iptables -N EXT_FORWARD_IN_CHAIN
  iptables("-N EXT_FORWARD_IN_CHAIN");
  //iptables -N EXT_FORWARD_OUT_CHAIN
  iptables("-N EXT_FORWARD_OUT_CHAIN");
  //iptables -N EXT_OUTPUT_CHAIN
  iptables("-N EXT_OUTPUT_CHAIN");

  //# INT(LAN) chains
  //iptables -N INT_INPUT_CHAIN
  iptables("-N INT_INPUT_CHAIN");
  //iptables -N INT_FORWARD_IN_CHAIN
  iptables("-N INT_FORWARD_IN_CHAIN");
  //iptables -N INT_FORWARD_OUT_CHAIN
  iptables("-N INT_FORWARD_OUT_CHAIN");
  //iptables -N INT_OUTPUT_CHAIN
  iptables("-N INT_OUTPUT_CHAIN");

  //# DMZ chains
  //iptables -N DMZ_INPUT_CHAIN
  iptables("-N DMZ_INPUT_CHAIN");
  //iptables -N DMZ_FORWARD_IN_CHAIN
  iptables("-N DMZ_FORWARD_IN_CHAIN");
  //iptables -N DMZ_FORWARD_OUT_CHAIN
  iptables("-N DMZ_FORWARD_OUT_CHAIN");
  //iptables -N DMZ_OUTPUT_CHAIN
  iptables("-N DMZ_OUTPUT_CHAIN");
//}

#if 1 //Mos 2013/09/17, fix TD#206: Port fowarding and DMZ doesn't work for the application using TCP
    iptables("-N SYN_FLOOD_CHK");
#endif

#if 1 // Mos 2014/08/15, refresh iptable per different service
    iptables("-N REMOTE_MGMT_WAN_CHAIN");
    iptables("-N REMOTE_MGMT_BYPASS_CHAIN");
    iptables("-N USER_MGMT_CHAIN");
    iptables("-N PORTFORWARD_FORWARD_IN_CHAIN");
    iptables("-t nat -N PORTFORWARD_NAT_CHAIN");
    iptables("-N PORTTRIGGER_FORWARD_IN_CHAIN");
    iptables("-t nat -N PORTTRIGGER_NAT_CHAIN");
    iptables("-N BLOCKSITE");
    iptables("-N BLOCKSITE_IN_CHAIN");
    iptables("-N BLOCK_SERVICE_CHAIN");
//Mos 2014/08/28 implement usb service filrewall rules
    iptables("-N USB_FORWARD_IN_CHAIN");
    iptables("-t nat -N USB_NAT_CHAIN");
    iptables("-N USB_INPUT_CHAIN");
    /* [Foxc] Baverly, 2014/10/14, [TD#406] C6300: USB -- There should be IPv6 URL access via HTTP(internet). 
     * Create USB service filrewall rules for IPv6. */
    if (strcmp(IPV6_SUPPORT, "1") == 0)
    {
        ip6tables("-N USB_INPUT_CHAIN");
    }
#endif
    iptables("-N OPENVPN_FORWARD_CHAIN");
    ip4tables("-t nat -N OPENVPN_POSTROUTING_CHAIN");

}


//# Flush our custom chains
void //flush_user_chains()
flush_user_chains(void)
//{
{
  //# General chains
  //iptables -F HOST_BLOCK_SRC
  iptables("-F HOST_BLOCK_SRC");
  //iptables -F HOST_BLOCK_DST
  iptables("-F HOST_BLOCK_DST");
  //iptables -F HOST_BLOCK_DROP
  iptables("-F HOST_BLOCK_DROP");
  //iptables -F VALID_CHK
  iptables("-F VALID_CHK");
  //iptables -F RESERVED_NET_CHK
  iptables("-F RESERVED_NET_CHK");
  //iptables -F SPOOF_CHK
  iptables("-F SPOOF_CHK");
  //iptables -F INPUT_CHAIN
  iptables("-F INPUT_CHAIN");
  //iptables -F FORWARD_CHAIN
  iptables("-F FORWARD_CHAIN");
  //iptables -F OUTPUT_CHAIN
  iptables("-F OUTPUT_CHAIN");
  //iptables -F POST_INPUT_DROP_CHAIN
  iptables("-F POST_INPUT_DROP_CHAIN");
  //iptables -F POST_INPUT_CHAIN
  iptables("-F POST_INPUT_CHAIN");
  //iptables -F POST_FORWARD_CHAIN
  iptables("-F POST_FORWARD_CHAIN");
  //iptables -F POST_OUTPUT_CHAIN
  iptables("-F POST_OUTPUT_CHAIN");

  //ip4tables -t nat -F NAT_PREROUTING_CHAIN
  ip4tables("-t nat -F NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -F NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -F NAT_POSTROUTING_CHAIN");
  //ip4tables -t nat -F POST_NAT_PREROUTING_CHAIN
  ip4tables("-t nat -F POST_NAT_PREROUTING_CHAIN");
  //ip4tables -t nat -F POST_NAT_POSTROUTING_CHAIN
  ip4tables("-t nat -F POST_NAT_POSTROUTING_CHAIN");

  /* [Foxc] James_Chien, 2015/04/17, TD673 C6300 : [New Feature] : NAT loopback feature */
  ip4tables("-t nat -F POST_PORTFORWARD_CHAIN");

  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {
    //ip6tables -F LINK_LOCAL_DROP
    ip6tables("-F LINK_LOCAL_DROP");
  //fi
  }

  //# Interface-2-interface chains
  //iptables -F DMZ_LAN_FORWARD_CHAIN
  iptables("-F DMZ_LAN_FORWARD_CHAIN");
  //iptables -F INET_DMZ_FORWARD_CHAIN
  iptables("-F INET_DMZ_FORWARD_CHAIN");
  //iptables -F DMZ_INET_FORWARD_CHAIN
  iptables("-F DMZ_INET_FORWARD_CHAIN");
  //iptables -F LAN_INET_FORWARD_CHAIN
  iptables("-F LAN_INET_FORWARD_CHAIN");

  //# Chains for the external interface
  //iptables -F EXT_MULTICAST_CHAIN
  iptables("-F EXT_MULTICAST_CHAIN");
  //iptables -F EXT_BROADCAST_CHAIN
  iptables("-F EXT_BROADCAST_CHAIN");
  //iptables -F EXT_ICMP_FLOOD_CHAIN
  iptables("-F EXT_ICMP_FLOOD_CHAIN");
  //iptables -F EXT_INPUT_CHAIN
  iptables("-F EXT_INPUT_CHAIN");
  //iptables -F EXT_FORWARD_IN_CHAIN
  iptables("-F EXT_FORWARD_IN_CHAIN");
  //iptables -F EXT_FORWARD_OUT_CHAIN
  iptables("-F EXT_FORWARD_OUT_CHAIN");
  //iptables -F EXT_OUTPUT_CHAIN
  iptables("-F EXT_OUTPUT_CHAIN");

  //# INT(LAN) chains
  //iptables -F INT_INPUT_CHAIN
  iptables("-F INT_INPUT_CHAIN");
  //iptables -F INT_FORWARD_IN_CHAIN
  iptables("-F INT_FORWARD_IN_CHAIN");
  //iptables -F INT_FORWARD_OUT_CHAIN
  iptables("-F INT_FORWARD_OUT_CHAIN");
  //iptables -F INT_OUTPUT_CHAIN
  iptables("-F INT_OUTPUT_CHAIN");

  //# DMZ chains
  //iptables -F DMZ_INPUT_CHAIN
  iptables("-F DMZ_INPUT_CHAIN");
  //iptables -F DMZ_FORWARD_IN_CHAIN
  iptables("-F DMZ_FORWARD_IN_CHAIN");
  //iptables -F DMZ_FORWARD_OUT_CHAIN
  iptables("-F DMZ_FORWARD_OUT_CHAIN");
  //iptables -F DMZ_OUTPUT_CHAIN
  iptables("-F DMZ_OUTPUT_CHAIN");
//}
#if 1 //Mos 2013/09/17, fix TD#206: Port fowarding and DMZ doesn't work for the application using TCP
  iptables("-F SYN_FLOOD_CHK");
#endif

#if 1 // Mos 2014/08/15, refresh iptable per different service
    iptables("-F REMOTE_MGMT_WAN_CHAIN");
    iptables("-F REMOTE_MGMT_BYPASS_CHAIN");
    iptables("-F USER_MGMT_CHAIN");
    iptables("-F PORTFORWARD_FORWARD_IN_CHAIN");
    iptables("-t nat -F PORTFORWARD_NAT_CHAIN");
    iptables("-F PORTTRIGGER_FORWARD_IN_CHAIN");
    iptables("-t nat -F PORTTRIGGER_NAT_CHAIN");
    iptables("-F BLOCKSITE_IN_CHAIN");
    iptables("-F BLOCKSITE");
    iptables("-F BLOCK_SERVICE_CHAIN");
//Mos 2014/08/28 implement usb service filrewall rules
    iptables("-F USB_FORWARD_IN_CHAIN");
    iptables("-t nat -F USB_NAT_CHAIN");
    iptables("-F USB_INPUT_CHAIN");
    /* [Foxc] Baverly, 2014/10/14, [TD#406] C6300: USB -- There should be IPv6 URL access via HTTP(internet). 
     * Create USB service filrewall rules for IPv6. */
    if (strcmp(IPV6_SUPPORT, "1") == 0)
    {
        ip6tables("-F USB_INPUT_CHAIN");
    }
#endif
    iptables("-F OPENVPN_FORWARD_CHAIN");
    ip4tables("-t nat -F OPENVPN_POSTROUTING_CHAIN");

}

#if 1 // Mos 2014/08/15, refresh iptable per different service
void
main_run_custom_services()
{
    printf("Reading custom rules from %s !!!\n", "/tmp/custom-service-rules");
    source("/tmp/custom-service-rules");
}
#endif

void //stop_firewall()
stop_firewall(void)
//{
{
  //# Set default IPv4 policies
  //ip4tables -P INPUT ACCEPT
  ip4tables("-P INPUT ACCEPT");
  //ip4tables -P FORWARD DROP
  ip4tables("-P FORWARD DROP");
  //ip4tables -P OUTPUT ACCEPT
  ip4tables("-P OUTPUT ACCEPT");

  //# Flush builtin IPv4 chains
  //ip4tables -F INPUT
  ip4tables("-F INPUT");
  //ip4tables -F OUTPUT
  ip4tables("-F OUTPUT");
  //ip4tables -F FORWARD
  ip4tables("-F FORWARD");

  //# Flush rules in the mangle/nat tables
  //ip4tables -t mangle -F
  ip4tables("-t mangle -F");
  //ip4tables -t mangle -X
  ip4tables("-t mangle -X");
  //ip4tables -t nat -F
  ip4tables("-t nat -F");
  //ip4tables -t nat -X
  ip4tables("-t nat -X");

  //# Attempt to flush all IPv4 chains
  //ip4tables -F
  ip4tables("-F");
  //ip4tables -X
  ip4tables("-X");

  ip4tables("-A FORWARD  -m physdev --physdev-is-bridged -j ACCEPT");
  //if [ "$IPV6_DETECTED" = "1" ]; then
  if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //# Set default IPv6 policies
    //ip6tables -P INPUT ACCEPT
    ip6tables("-P INPUT ACCEPT");
    //ip6tables -P FORWARD DROP
    ip6tables("-P FORWARD DROP");
    //ip6tables -P OUTPUT ACCEPT
    ip6tables("-P OUTPUT ACCEPT");

    //# Flush builtin IPv6 chains
    //ip6tables -F INPUT
    ip6tables("-F INPUT");
    //ip6tables -F OUTPUT
    ip6tables("-F OUTPUT");
    //ip6tables -F FORWARD
    ip6tables("-F FORWARD");

    //# Flush rules in the mangle table
    //ip6tables -t mangle -F
    ip6tables("-t mangle -F");
    //ip6tables -t mangle -X
    ip6tables("-t mangle -X");

    //# Attempt to flush all IPv6 chains
    //ip6tables -F
    ip6tables("-F");
    //ip6tables -X
    ip6tables("-X");
  //fi
    ip6tables("-A FORWARD  -m physdev --physdev-is-bridged -j ACCEPT");
  }
//}
}


void //reinit_firewall_chains()
reinit_firewall_chains(void)
//{
{
  //echo "Reinitializing firewall chains"
  printf("Reinitializing firewall chains" "\n");

  //# Set INDENT for functions
  //INDENT='  '
  INDENT = "  ";

  //# Create chains, just in case
  //create_user_chains 2>/dev/null
  create_user_chains();

  //# Flush our user chains
  //flush_user_chains;
  flush_user_chains();

  //# Temporarily set OUTPUT default policy to ACCEPT
  //# Without it, active states will be flushed.
  //iptables -P OUTPUT ACCEPT
  iptables("-P OUTPUT ACCEPT");

  //# Flush builtin IPv4 chains
  //ip4tables -F INPUT
  ip4tables("-F INPUT");
  //ip4tables -F OUTPUT
  ip4tables("-F OUTPUT");
  //ip4tables -F FORWARD
  ip4tables("-F FORWARD");

  //# Flush rules in the nat/mangle tables
  //ip4tables -t mangle -F
  ip4tables("-t mangle -F");
  //ip4tables -t nat -F
  ip4tables("-t nat -F");

  //if [ "$IPV6_DETECTED" = "1" ]; then
  if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //# Flush builtin IPv6 chains
    //ip6tables -F INPUT
    ip6tables("-F INPUT");
    //ip6tables -F OUTPUT
    ip6tables("-F OUTPUT");
    //ip6tables -F FORWARD
    ip6tables("-F FORWARD");

    //# Flush rules in the mangle table
    //ip6tables -t mangle -F
    ip6tables("-t mangle -F");
  //fi
  }

  //# Restore our base chains (which weren't flushed so any
  //# running connections should be maintained
  //#######################################################
  //iptables -A INPUT -j BASE_INPUT_CHAIN
  iptables("-A INPUT -j BASE_INPUT_CHAIN");
  //iptables -A FORWARD -j BASE_FORWARD_CHAIN
  iptables("-A FORWARD -j BASE_FORWARD_CHAIN");
  //iptables -A OUTPUT -j BASE_OUTPUT_CHAIN
  iptables("-A OUTPUT -j BASE_OUTPUT_CHAIN");
//}
}


void //stop_block_firewall()
stop_block_firewall(void)
//{
{
char *local1IFS = NULL;;
char *r_EXT_IF1 = NULL;;
char *interface = NULL;;
char *strtok1_FREE = NULL;;

  //# Temporarely set default IPv4 policies to DROP,
  //# to not even have a small window of opportunity
  //################################################
  //ip4tables -P INPUT DROP
  ip4tables("-P INPUT DROP");
  //ip4tables -P FORWARD DROP
  ip4tables("-P FORWARD DROP");
  //ip4tables -P OUTPUT DROP
  ip4tables("-P OUTPUT DROP");
  
  //# Flush builtin IPv4 chains
  //ip4tables -F INPUT
  ip4tables("-F INPUT");
  //ip4tables -F OUTPUT
  ip4tables("-F OUTPUT");
  //ip4tables -F FORWARD
  ip4tables("-F FORWARD");

  //# Flush nat/mangle table rules
  //ip4tables -t mangle -F
  ip4tables("-t mangle -F");
  //ip4tables -t mangle -X
  ip4tables("-t mangle -X");
  //ip4tables -t nat -F
  ip4tables("-t nat -F");
  //ip4tables -t nat -X
  ip4tables("-t nat -X");

  //# Attempt to flush all IPv4 chains
  //ip4tables -F
  ip4tables("-F");
  //ip4tables -X
  ip4tables("-X");

  //if [ "$IPV6_DETECTED" = "1" ]; then
  if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //# Temporarely set default IPv6 policies to DROP,
    //# to not even have a small window of opportunity
    //################################################
    //ip6tables -P INPUT DROP
    ip6tables("-P INPUT DROP");
    //ip6tables -P FORWARD DROP
    ip6tables("-P FORWARD DROP");
    //ip6tables -P OUTPUT DROP
    ip6tables("-P OUTPUT DROP");

    //# Flush builtin IPv6 chains
    //ip6tables -F INPUT
    ip6tables("-F INPUT");
    //ip6tables -F OUTPUT
    ip6tables("-F OUTPUT");
    //ip6tables -F FORWARD
    ip6tables("-F FORWARD");

    //# Flush mangle table rules
    //ip6tables -t mangle -F
    ip6tables("-t mangle -F");
    //ip6tables -t mangle -X
    ip6tables("-t mangle -X");

    //# Attempt to flush all IPv6 chains
    //ip6tables -F
    ip6tables("-F");
    //ip6tables -X
    ip6tables("-X");
  //fi
  }

  //# Deny traffic from our internet interfaces
  //IFS=' ,'
  IFS=" ,";
  //for interface in $EXT_IF; do
  local1IFS = IFS;
  if (EXT_IF != NULL) strtok1_FREE = strdup(EXT_IF);
  if (EXT_IF != NULL) for (interface = strtok_r(strtok1_FREE, local1IFS, &r_EXT_IF1); interface != NULL; interface = strtok_r(NULL, local1IFS, &r_EXT_IF1))
  {
    //ip4tables -A INPUT -i $interface -j DROP
    ip4tables("-A INPUT -i %s -j DROP", interface);
    
    //if [ "$IPV6_DETECTED" = "1" ]; then
    if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
    {
      //ip6tables -A INPUT -i $interface -j DROP
      ip6tables("-A INPUT -i %s -j DROP", interface);
    //fi
    }
  //done
  }

  //# Allow IPv4 traffic from the loopback (localhost)
  //ip4tables -A INPUT -i lo -j ACCEPT
  ip4tables("-A INPUT -i lo -j ACCEPT");
  //ip4tables -A FORWARD -i lo -j ACCEPT
  ip4tables("-A FORWARD -i lo -j ACCEPT");
  //ip4tables -A OUTPUT -o lo -j ACCEPT
  ip4tables("-A OUTPUT -o lo -j ACCEPT");

  //# Set default IPv4 policies
  //ip4tables -P INPUT ACCEPT
  ip4tables("-P INPUT ACCEPT");
  //ip4tables -P FORWARD DROP
  ip4tables("-P FORWARD DROP");
  //ip4tables -P OUTPUT ACCEPT
  ip4tables("-P OUTPUT ACCEPT");

  //if [ "$IPV6_DETECTED" = "1" ]; then
  if  (  (strcmp(IPV6_DETECTED,"1")==0)  )
  {
    //# Allow IPv6 traffic from the loopback (localhost)
    //ip6tables -A INPUT -i lo -j ACCEPT
    ip6tables("-A INPUT -i lo -j ACCEPT");
    //ip6tables -A FORWARD -i lo -j ACCEPT
    ip6tables("-A FORWARD -i lo -j ACCEPT");
    //ip6tables -A OUTPUT -o lo -j ACCEPT
    ip6tables("-A OUTPUT -o lo -j ACCEPT");

    //# Set default IPv6 policies
    //ip6tables -P INPUT ACCEPT
    ip6tables("-P INPUT ACCEPT");
    //ip6tables -P FORWARD DROP
    ip6tables("-P FORWARD DROP");
    //ip6tables -P OUTPUT ACCEPT
    ip6tables("-P OUTPUT ACCEPT");
  //fi
  }
if (strtok1_FREE != NULL) free(strtok1_FREE);

//}
}


void //show_start()
show_start(void)
//{
{
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}
  //echo "$DATE ** Starting Arno's Iptables Firewall v$MY_VERSION **" >> $FIREWALL_LOG
  fprintf(FIREWALL_LOG_FILE, "%s ** Starting Arno's Iptables Firewall v%s ** " "\n", DATE, MY_VERSION);
  //echo "** Starting Arno's Iptables Firewall v$MY_VERSION **" |logger -t firewall -p kern.info
  //echo "** Starting Arno's Iptables Firewall vMY_VERSION **" |logger -t firewall -p kern.info
//}
}


void //show_restart()
show_restart(void)
//{
{
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}
  //echo "$DATE ** Restarting Arno's Iptables Firewall v$MY_VERSION **" >> $FIREWALL_LOG
  fprintf(FIREWALL_LOG_FILE, "%s ** Restarting Arno's Iptables Firewall v%s ** " "\n", DATE, MY_VERSION);
  //echo "** Restarting Arno's Iptables Firewall v$MY_VERSION **" |logger -t firewall -p kern.info
  //echo "** Restarting Arno's Iptables Firewall vMY_VERSION **" |logger -t firewall -p kern.info
//}
}


void //show_stop()
show_stop(void)
//{
{
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}
  //printf "$DATE \033[40m\033[1;32mStopping Arno's Iptables Firewall v$MY_VERSION\033[0m\n"
  printf("%s \033[40m\033[1;32mStopping Arno's Iptables Firewall v%s\033[0m\n", DATE, MY_VERSION);
  //echo "$DATE ** Stopping Arno's Iptables Firewall v$MY_VERSION **" >> $FIREWALL_LOG
  fprintf(FIREWALL_LOG_FILE, "%s ** Stopping Arno's Iptables Firewall v%s ** " "\n", DATE, MY_VERSION);
  //echo "** Stopping Arno's Iptables Firewall v$MY_VERSION **" |logger -t firewall -p kern.info
  //echo "** Stopping Arno's Iptables Firewall vMY_VERSION **" |logger -t firewall -p kern.info
//}
}


void //show_stop_blocked()
show_stop_blocked(void)
//{
{
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}
  //printf "$DATE \033[40m\033[1;31mFIREWALL DISABLED & BLOCKING ALL INTERNET TRAFFIC!\033[0m\n"
  printf("%s \033[40m\033[1;31mFIREWALL DISABLED & BLOCKING ALL INTERNET TRAFFIC!\033[0m\n", DATE);
//}
}


//# Now show the final message
void //show_applied()
show_applied(void)
//{
{
  //echo ""
  printf("" "\n");
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}

  //if [ "$IPTABLES_ERROR" = "1" ]; then
  if  (  (strcmp(IPTABLES_ERROR,"1")==0)  )
  {
    //printf "$DATE \033[40m\033[1;31mWARNING: Not all firewall rules are applied.\033[0m\n" >&2
    fprintf(stderr, "%s \033[40m\033[1;31mWARNING: Not all firewall rules are applied.\033[0m\n ", DATE);
    //echo "$DATE ** WARNING: Not all firewall rules are applied **" >> $FIREWALL_LOG
    fprintf(FIREWALL_LOG_FILE, "%s ** WARNING: Not all firewall rules are applied ** " "\n", DATE);
    //echo "** WARNING: Not all firewall rules are applied **" |logger -t firewall -p kern.info
    //echo "** WARNING: Not all firewall rules are applied **" |logger -t firewall -p kern.info
  //else
  }
  else
  {
    //printf "$DATE \033[40m\033[1;32mAll firewall rules applied.\033[0m\n"
    printf("%s \033[40m\033[1;32mAll firewall rules applied.\033[0m\n", DATE);
    //echo "$DATE ** All firewall rules applied **" >> $FIREWALL_LOG
    fprintf(FIREWALL_LOG_FILE, "%s ** All firewall rules applied ** " "\n", DATE);
    //echo "** All firewall rules applied **" |logger -t firewall -p kern.info
    //echo "** All firewall rules applied **" |logger -t firewall -p kern.info
  //fi
  }
//}
}


void //show_disabled()
show_disabled(void)
//{
{
  //DATE=`LC_ALL=C date +'%b %d %H:%M:%S'`
{struct timeval time;gettimeofday(&time, NULL);DATE = ctime( &time.tv_sec );DATE[strlen(DATE) - 2] = '\0';}
  //printf "$DATE \033[40m\033[1;31mFIREWALL DISABLED!\033[0m\n"
  printf("%s \033[40m\033[1;31mFIREWALL DISABLED!\033[0m\n", DATE);
//}
}


void //main_start_c()
main_start_c(void)
//{
{
  //setup_kernel_settings;
  setup_kernel_settings();
  //# Start BATCH
  //iptables_batch init
  iptables_batch("init");
  //init_firewall_chains;
  init_firewall_chains();
  //setup_default_policies;
  setup_default_policies();
  //# The following cannot be done in _batch mode, stop then restart
  //iptables_batch apply
  iptables_batch("apply");
  //setup_hostblock_chain;
  setup_hostblock_chain();
  //# ReStart BATCH
  //iptables_batch init
  iptables_batch("init");
  //setup_firewall_rules;
  setup_firewall_rules();
  //# Stop BATCH
  //iptables_batch apply
  iptables_batch("apply");
//}
}


void //main_restart_c()
main_restart_c(void)
//{
{
  //reinit_firewall_chains;
  reinit_firewall_chains();
  //# Start BATCH
  //iptables_batch init
  iptables_batch("init");
  //setup_default_policies;
  setup_default_policies();
  //# The following cannot be done in _batch mode, stop then restart
  //iptables_batch apply
  iptables_batch("apply");
  //setup_hostblock_chain;
  setup_hostblock_chain();
  //# ReStart BATCH
  //iptables_batch init
  iptables_batch("init");
  //setup_firewall_rules;
  setup_firewall_rules();
  //# Stop BATCH
  //iptables_batch apply
  iptables_batch("apply");
//}
}


void env_init(void)
{
 if ((ANYHOST = getenv("ANYHOST")) == NULL) ANYHOST = "";
 if ((ANYPORT = getenv("ANYPORT")) == NULL) ANYPORT = "";
 if ((BAD_FLAGS_LOG = getenv("BAD_FLAGS_LOG")) == NULL) BAD_FLAGS_LOG = "";
 if ((BLOCKED_HOST_LOG = getenv("BLOCKED_HOST_LOG")) == NULL) BLOCKED_HOST_LOG = "";
 if ((BLOCK_HOSTS = getenv("BLOCK_HOSTS")) == NULL) BLOCK_HOSTS = "";
 if ((BLOCK_HOSTS_BIDIRECTIONAL = getenv("BLOCK_HOSTS_BIDIRECTIONAL")) == NULL) BLOCK_HOSTS_BIDIRECTIONAL = "";
 if ((BLOCK_HOSTS_FILE = getenv("BLOCK_HOSTS_FILE")) == NULL) BLOCK_HOSTS_FILE = "";
 if ((BROADCAST_TCP_NOLOG = getenv("BROADCAST_TCP_NOLOG")) == NULL) BROADCAST_TCP_NOLOG = "";
 if ((BROADCAST_UDP_NOLOG = getenv("BROADCAST_UDP_NOLOG")) == NULL) BROADCAST_UDP_NOLOG = "";
 if ((CONNTRACK = getenv("CONNTRACK")) == NULL) CONNTRACK = "";
 if ((COUNT = getenv("COUNT")) == NULL) COUNT = "";
 if ((CUSTOM_RULES = getenv("CUSTOM_RULES")) == NULL) CUSTOM_RULES = "";
 if ((DATE = getenv("DATE")) == NULL) DATE = "";
 if ((DEFAULT_POLICY_DROP = getenv("DEFAULT_POLICY_DROP")) == NULL) DEFAULT_POLICY_DROP = "";
 if ((DEFAULT_TTL = getenv("DEFAULT_TTL")) == NULL) DEFAULT_TTL = "";
 if ((DENY_IP_OUTPUT = getenv("DENY_IP_OUTPUT")) == NULL) DENY_IP_OUTPUT = "";
 if ((DENY_TCP = getenv("DENY_TCP")) == NULL) DENY_TCP = "";
 if ((DENY_TCP_NOLOG = getenv("DENY_TCP_NOLOG")) == NULL) DENY_TCP_NOLOG = "";
 if ((DENY_TCP_OUTPUT = getenv("DENY_TCP_OUTPUT")) == NULL) DENY_TCP_OUTPUT = "";
 if ((DENY_UDP = getenv("DENY_UDP")) == NULL) DENY_UDP = "";
 if ((DENY_UDP_NOLOG = getenv("DENY_UDP_NOLOG")) == NULL) DENY_UDP_NOLOG = "";
 if ((DENY_UDP_OUTPUT = getenv("DENY_UDP_OUTPUT")) == NULL) DENY_UDP_OUTPUT = "";
 if ((DMESG_PANIC_ONLY = getenv("DMESG_PANIC_ONLY")) == NULL) DMESG_PANIC_ONLY = "";
 if ((DMZ_HOST_OPEN_IP = getenv("DMZ_HOST_OPEN_IP")) == NULL) DMZ_HOST_OPEN_IP = "";
 if ((DMZ_HOST_OPEN_TCP = getenv("DMZ_HOST_OPEN_TCP")) == NULL) DMZ_HOST_OPEN_TCP = "";
 if ((DMZ_HOST_OPEN_UDP = getenv("DMZ_HOST_OPEN_UDP")) == NULL) DMZ_HOST_OPEN_UDP = "";
 if ((DMZ_IF = getenv("DMZ_IF")) == NULL) DMZ_IF = "";
 if ((DMZ_INET_DENY_IP = getenv("DMZ_INET_DENY_IP")) == NULL) DMZ_INET_DENY_IP = "";
 if ((DMZ_INET_DENY_TCP = getenv("DMZ_INET_DENY_TCP")) == NULL) DMZ_INET_DENY_TCP = "";
 if ((DMZ_INET_DENY_UDP = getenv("DMZ_INET_DENY_UDP")) == NULL) DMZ_INET_DENY_UDP = "";
 if ((DMZ_INET_HOST_DENY_IP = getenv("DMZ_INET_HOST_DENY_IP")) == NULL) DMZ_INET_HOST_DENY_IP = "";
 if ((DMZ_INET_HOST_DENY_TCP = getenv("DMZ_INET_HOST_DENY_TCP")) == NULL) DMZ_INET_HOST_DENY_TCP = "";
 if ((DMZ_INET_HOST_DENY_UDP = getenv("DMZ_INET_HOST_DENY_UDP")) == NULL) DMZ_INET_HOST_DENY_UDP = "";
 if ((DMZ_INET_HOST_OPEN_IP = getenv("DMZ_INET_HOST_OPEN_IP")) == NULL) DMZ_INET_HOST_OPEN_IP = "";
 if ((DMZ_INET_HOST_OPEN_TCP = getenv("DMZ_INET_HOST_OPEN_TCP")) == NULL) DMZ_INET_HOST_OPEN_TCP = "";
 if ((DMZ_INET_HOST_OPEN_UDP = getenv("DMZ_INET_HOST_OPEN_UDP")) == NULL) DMZ_INET_HOST_OPEN_UDP = "";
 if ((DMZ_INET_OPEN_ICMP = getenv("DMZ_INET_OPEN_ICMP")) == NULL) DMZ_INET_OPEN_ICMP = "";
 if ((DMZ_INET_OPEN_IP = getenv("DMZ_INET_OPEN_IP")) == NULL) DMZ_INET_OPEN_IP = "";
 if ((DMZ_INET_OPEN_TCP = getenv("DMZ_INET_OPEN_TCP")) == NULL) DMZ_INET_OPEN_TCP = "";
 if ((DMZ_INET_OPEN_UDP = getenv("DMZ_INET_OPEN_UDP")) == NULL) DMZ_INET_OPEN_UDP = "";
 if ((DMZ_INPUT_DENY_LOG = getenv("DMZ_INPUT_DENY_LOG")) == NULL) DMZ_INPUT_DENY_LOG = "";
 if ((DMZ_LAN_HOST_OPEN_IP = getenv("DMZ_LAN_HOST_OPEN_IP")) == NULL) DMZ_LAN_HOST_OPEN_IP = "";
 if ((DMZ_LAN_HOST_OPEN_TCP = getenv("DMZ_LAN_HOST_OPEN_TCP")) == NULL) DMZ_LAN_HOST_OPEN_TCP = "";
 if ((DMZ_LAN_HOST_OPEN_UDP = getenv("DMZ_LAN_HOST_OPEN_UDP")) == NULL) DMZ_LAN_HOST_OPEN_UDP = "";
 if ((DMZ_LAN_OPEN_ICMP = getenv("DMZ_LAN_OPEN_ICMP")) == NULL) DMZ_LAN_OPEN_ICMP = "";
 if ((DMZ_NET = getenv("DMZ_NET")) == NULL) DMZ_NET = "";
 if ((DMZ_NET_ANTISPOOF = getenv("DMZ_NET_ANTISPOOF")) == NULL) DMZ_NET_ANTISPOOF = "";
 if ((DMZ_OPEN_ICMP = getenv("DMZ_OPEN_ICMP")) == NULL) DMZ_OPEN_ICMP = "";
 if ((DMZ_OPEN_IP = getenv("DMZ_OPEN_IP")) == NULL) DMZ_OPEN_IP = "";
 if ((DMZ_OPEN_TCP = getenv("DMZ_OPEN_TCP")) == NULL) DMZ_OPEN_TCP = "";
 if ((DMZ_OPEN_UDP = getenv("DMZ_OPEN_UDP")) == NULL) DMZ_OPEN_UDP = "";
 if ((DMZ_OUTPUT_DENY_LOG = getenv("DMZ_OUTPUT_DENY_LOG")) == NULL) DMZ_OUTPUT_DENY_LOG = "";
 if ((DRDOS_PROTECT = getenv("DRDOS_PROTECT")) == NULL) DRDOS_PROTECT = "";
 if ((DROP_PRIVATE_ADDRESSES = getenv("DROP_PRIVATE_ADDRESSES")) == NULL) DROP_PRIVATE_ADDRESSES = "";
 if ((ECHO_IGNORE = getenv("ECHO_IGNORE")) == NULL) ECHO_IGNORE = "";
 if ((ECN = getenv("ECN")) == NULL) ECN = "";
 if ((EOL = getenv("EOL")) == NULL) EOL = "";
 if ((EXTERNAL_DHCPV6_SERVER = getenv("EXTERNAL_DHCPV6_SERVER")) == NULL) EXTERNAL_DHCPV6_SERVER = "";
 if ((EXTERNAL_DHCP_SERVER = getenv("EXTERNAL_DHCP_SERVER")) == NULL) EXTERNAL_DHCP_SERVER = "";
 if ((EXTERNAL_NET = getenv("EXTERNAL_NET")) == NULL) EXTERNAL_NET = "";
 if ((EXTIF_NET = getenv("EXTIF_NET")) == NULL) EXTIF_NET = "";
 if ((EXT_IF = getenv("EXT_IF")) == NULL) EXT_IF = "";
 if ((EXT_IF_DHCP_IP = getenv("EXT_IF_DHCP_IP")) == NULL) EXT_IF_DHCP_IP = "";
 if ((EXT_NET_BCAST_ADDRESS = getenv("EXT_NET_BCAST_ADDRESS")) == NULL) EXT_NET_BCAST_ADDRESS = "";
 if ((FORWARD_DROP_LOG = getenv("FORWARD_DROP_LOG")) == NULL) FORWARD_DROP_LOG = "";
 if ((FORWARD_LINK_LOCAL = getenv("FORWARD_LINK_LOCAL")) == NULL) FORWARD_LINK_LOCAL = "";
 if ((FRAG_LOG = getenv("FRAG_LOG")) == NULL) FRAG_LOG = "";
 if ((FULL_ACCESS_HOSTS = getenv("FULL_ACCESS_HOSTS")) == NULL) FULL_ACCESS_HOSTS = "";
 if ((HOST_DENY_ICMP = getenv("HOST_DENY_ICMP")) == NULL) HOST_DENY_ICMP = "";
 if ((HOST_DENY_ICMP_NOLOG = getenv("HOST_DENY_ICMP_NOLOG")) == NULL) HOST_DENY_ICMP_NOLOG = "";
 if ((HOST_DENY_IP = getenv("HOST_DENY_IP")) == NULL) HOST_DENY_IP = "";
 if ((HOST_DENY_IP_NOLOG = getenv("HOST_DENY_IP_NOLOG")) == NULL) HOST_DENY_IP_NOLOG = "";
 if ((HOST_DENY_IP_OUTPUT = getenv("HOST_DENY_IP_OUTPUT")) == NULL) HOST_DENY_IP_OUTPUT = "";
 if ((HOST_DENY_TCP = getenv("HOST_DENY_TCP")) == NULL) HOST_DENY_TCP = "";
 if ((HOST_DENY_TCP_NOLOG = getenv("HOST_DENY_TCP_NOLOG")) == NULL) HOST_DENY_TCP_NOLOG = "";
 if ((HOST_DENY_TCP_OUTPUT = getenv("HOST_DENY_TCP_OUTPUT")) == NULL) HOST_DENY_TCP_OUTPUT = "";
 if ((HOST_DENY_UDP = getenv("HOST_DENY_UDP")) == NULL) HOST_DENY_UDP = "";
 if ((HOST_DENY_UDP_NOLOG = getenv("HOST_DENY_UDP_NOLOG")) == NULL) HOST_DENY_UDP_NOLOG = "";
 if ((HOST_DENY_UDP_OUTPUT = getenv("HOST_DENY_UDP_OUTPUT")) == NULL) HOST_DENY_UDP_OUTPUT = "";
 if ((HOST_OPEN_ICMP = getenv("HOST_OPEN_ICMP")) == NULL) HOST_OPEN_ICMP = "";
 if ((HOST_OPEN_IP = getenv("HOST_OPEN_IP")) == NULL) HOST_OPEN_IP = "";
 if ((HOST_OPEN_TCP = getenv("HOST_OPEN_TCP")) == NULL) HOST_OPEN_TCP = "";
 if ((HOST_OPEN_UDP = getenv("HOST_OPEN_UDP")) == NULL) HOST_OPEN_UDP = "";
 if ((HOST_REJECT_TCP = getenv("HOST_REJECT_TCP")) == NULL) HOST_REJECT_TCP = "";
 if ((HOST_REJECT_TCP_NOLOG = getenv("HOST_REJECT_TCP_NOLOG")) == NULL) HOST_REJECT_TCP_NOLOG = "";
 if ((HOST_REJECT_UDP = getenv("HOST_REJECT_UDP")) == NULL) HOST_REJECT_UDP = "";
 if ((HOST_REJECT_UDP_NOLOG = getenv("HOST_REJECT_UDP_NOLOG")) == NULL) HOST_REJECT_UDP_NOLOG = "";
 if ((ICMPV6_SPECIAL_TYPES = getenv("ICMPV6_SPECIAL_TYPES")) == NULL) ICMPV6_SPECIAL_TYPES = "";
 if ((ICMP_DROP_LOG = getenv("ICMP_DROP_LOG")) == NULL) ICMP_DROP_LOG = "";
 if ((ICMP_FLOOD_LOG = getenv("ICMP_FLOOD_LOG")) == NULL) ICMP_FLOOD_LOG = "";
 if ((ICMP_OTHER_LOG = getenv("ICMP_OTHER_LOG")) == NULL) ICMP_OTHER_LOG = "";
 if ((ICMP_REDIRECT = getenv("ICMP_REDIRECT")) == NULL) ICMP_REDIRECT = "";
 if ((ICMP_REQUEST_LOG = getenv("ICMP_REQUEST_LOG")) == NULL) ICMP_REQUEST_LOG = "";
 if ((IF_TRUSTS = getenv("IF_TRUSTS")) == NULL) IF_TRUSTS = "";
 if ((IGMP_LOG = getenv("IGMP_LOG")) == NULL) IGMP_LOG = "";
 if ((INET_DMZ_DENY_IP = getenv("INET_DMZ_DENY_IP")) == NULL) INET_DMZ_DENY_IP = "";
 if ((INET_DMZ_DENY_TCP = getenv("INET_DMZ_DENY_TCP")) == NULL) INET_DMZ_DENY_TCP = "";
 if ((INET_DMZ_DENY_UDP = getenv("INET_DMZ_DENY_UDP")) == NULL) INET_DMZ_DENY_UDP = "";
 if ((INET_DMZ_HOST_DENY_IP = getenv("INET_DMZ_HOST_DENY_IP")) == NULL) INET_DMZ_HOST_DENY_IP = "";
 if ((INET_DMZ_HOST_DENY_TCP = getenv("INET_DMZ_HOST_DENY_TCP")) == NULL) INET_DMZ_HOST_DENY_TCP = "";
 if ((INET_DMZ_HOST_DENY_UDP = getenv("INET_DMZ_HOST_DENY_UDP")) == NULL) INET_DMZ_HOST_DENY_UDP = "";
 if ((INET_DMZ_HOST_OPEN_IP = getenv("INET_DMZ_HOST_OPEN_IP")) == NULL) INET_DMZ_HOST_OPEN_IP = "";
 if ((INET_DMZ_HOST_OPEN_TCP = getenv("INET_DMZ_HOST_OPEN_TCP")) == NULL) INET_DMZ_HOST_OPEN_TCP = "";
 if ((INET_DMZ_HOST_OPEN_UDP = getenv("INET_DMZ_HOST_OPEN_UDP")) == NULL) INET_DMZ_HOST_OPEN_UDP = "";
 if ((INET_DMZ_OPEN_ICMP = getenv("INET_DMZ_OPEN_ICMP")) == NULL) INET_DMZ_OPEN_ICMP = "";
 if ((INET_DMZ_OPEN_IP = getenv("INET_DMZ_OPEN_IP")) == NULL) INET_DMZ_OPEN_IP = "";
 if ((INET_DMZ_OPEN_TCP = getenv("INET_DMZ_OPEN_TCP")) == NULL) INET_DMZ_OPEN_TCP = "";
 if ((INET_DMZ_OPEN_UDP = getenv("INET_DMZ_OPEN_UDP")) == NULL) INET_DMZ_OPEN_UDP = "";
 if ((INET_FORWARD_IP = getenv("INET_FORWARD_IP")) == NULL) INET_FORWARD_IP = "";
 if ((INET_FORWARD_TCP = getenv("INET_FORWARD_TCP")) == NULL) INET_FORWARD_TCP = "";
 if ((INET_FORWARD_UDP = getenv("INET_FORWARD_UDP")) == NULL) INET_FORWARD_UDP = "";
 if ((INET_OUTPUT_DENY_LOG = getenv("INET_OUTPUT_DENY_LOG")) == NULL) INET_OUTPUT_DENY_LOG = "";
 if ((INTERNAL_NET = getenv("INTERNAL_NET")) == NULL) INTERNAL_NET = "";
 if ((INTERNAL_NET_ANTISPOOF = getenv("INTERNAL_NET_ANTISPOOF")) == NULL) INTERNAL_NET_ANTISPOOF = "";
 if ((INT_IF = getenv("INT_IF")) == NULL) INT_IF = "";
 if ((INVALID_ICMP_LOG = getenv("INVALID_ICMP_LOG")) == NULL) INVALID_ICMP_LOG = "";
 if ((INVALID_TCP_LOG = getenv("INVALID_TCP_LOG")) == NULL) INVALID_TCP_LOG = "";
 if ((INVALID_UDP_LOG = getenv("INVALID_UDP_LOG")) == NULL) INVALID_UDP_LOG = "";
 if ((IPTABLES_ERROR = getenv("IPTABLES_ERROR")) == NULL) IPTABLES_ERROR = "";
 if ((IPV6_AUTO_CONFIGURATION = getenv("IPV6_AUTO_CONFIGURATION")) == NULL) IPV6_AUTO_CONFIGURATION = "";
 if ((IPV6_DETECTED = getenv("IPV6_DETECTED")) == NULL) IPV6_DETECTED = "";
 if ((IPV6_SUPPORT = getenv("IPV6_SUPPORT")) == NULL) IPV6_SUPPORT = "";
 if ((IP_FORWARDING = getenv("IP_FORWARDING")) == NULL) IP_FORWARDING = "";
 if ((LAN_DENY_IP = getenv("LAN_DENY_IP")) == NULL) LAN_DENY_IP = "";
 if ((LAN_DENY_TCP = getenv("LAN_DENY_TCP")) == NULL) LAN_DENY_TCP = "";
 if ((LAN_DENY_UDP = getenv("LAN_DENY_UDP")) == NULL) LAN_DENY_UDP = "";
 if ((LAN_HOST_DENY_IP = getenv("LAN_HOST_DENY_IP")) == NULL) LAN_HOST_DENY_IP = "";
 if ((LAN_HOST_DENY_TCP = getenv("LAN_HOST_DENY_TCP")) == NULL) LAN_HOST_DENY_TCP = "";
 if ((LAN_HOST_DENY_UDP = getenv("LAN_HOST_DENY_UDP")) == NULL) LAN_HOST_DENY_UDP = "";
 if ((LAN_HOST_OPEN_IP = getenv("LAN_HOST_OPEN_IP")) == NULL) LAN_HOST_OPEN_IP = "";
 if ((LAN_HOST_OPEN_TCP = getenv("LAN_HOST_OPEN_TCP")) == NULL) LAN_HOST_OPEN_TCP = "";
 if ((LAN_HOST_OPEN_UDP = getenv("LAN_HOST_OPEN_UDP")) == NULL) LAN_HOST_OPEN_UDP = "";
 if ((LAN_INET_DENY_IP = getenv("LAN_INET_DENY_IP")) == NULL) LAN_INET_DENY_IP = "";
 if ((LAN_INET_DENY_TCP = getenv("LAN_INET_DENY_TCP")) == NULL) LAN_INET_DENY_TCP = "";
 if ((LAN_INET_DENY_UDP = getenv("LAN_INET_DENY_UDP")) == NULL) LAN_INET_DENY_UDP = "";
 if ((LAN_INET_HOST_DENY_IP = getenv("LAN_INET_HOST_DENY_IP")) == NULL) LAN_INET_HOST_DENY_IP = "";
 if ((LAN_INET_HOST_DENY_TCP = getenv("LAN_INET_HOST_DENY_TCP")) == NULL) LAN_INET_HOST_DENY_TCP = "";
 if ((LAN_INET_HOST_DENY_UDP = getenv("LAN_INET_HOST_DENY_UDP")) == NULL) LAN_INET_HOST_DENY_UDP = "";
 if ((LAN_INET_HOST_OPEN_IP = getenv("LAN_INET_HOST_OPEN_IP")) == NULL) LAN_INET_HOST_OPEN_IP = "";
 if ((LAN_INET_HOST_OPEN_TCP = getenv("LAN_INET_HOST_OPEN_TCP")) == NULL) LAN_INET_HOST_OPEN_TCP = "";
 if ((LAN_INET_HOST_OPEN_UDP = getenv("LAN_INET_HOST_OPEN_UDP")) == NULL) LAN_INET_HOST_OPEN_UDP = "";
 if ((LAN_INET_OPEN_ICMP = getenv("LAN_INET_OPEN_ICMP")) == NULL) LAN_INET_OPEN_ICMP = "";
 if ((LAN_INET_OPEN_IP = getenv("LAN_INET_OPEN_IP")) == NULL) LAN_INET_OPEN_IP = "";
 if ((LAN_INET_OPEN_TCP = getenv("LAN_INET_OPEN_TCP")) == NULL) LAN_INET_OPEN_TCP = "";
 if ((LAN_INET_OPEN_UDP = getenv("LAN_INET_OPEN_UDP")) == NULL) LAN_INET_OPEN_UDP = "";
 if ((LAN_INPUT_DENY_LOG = getenv("LAN_INPUT_DENY_LOG")) == NULL) LAN_INPUT_DENY_LOG = "";
 if ((LAN_OPEN_ICMP = getenv("LAN_OPEN_ICMP")) == NULL) LAN_OPEN_ICMP = "";
 if ((LAN_OPEN_IP = getenv("LAN_OPEN_IP")) == NULL) LAN_OPEN_IP = "";
 if ((LAN_OPEN_TCP = getenv("LAN_OPEN_TCP")) == NULL) LAN_OPEN_TCP = "";
 if ((LAN_OPEN_UDP = getenv("LAN_OPEN_UDP")) == NULL) LAN_OPEN_UDP = "";
 if ((LAN_OUTPUT_DENY_LOG = getenv("LAN_OUTPUT_DENY_LOG")) == NULL) LAN_OUTPUT_DENY_LOG = "";
 if ((LINK_LOCAL_DROP_LOG = getenv("LINK_LOCAL_DROP_LOG")) == NULL) LINK_LOCAL_DROP_LOG = "";
 if ((LOCAL_PORT_RANGE = getenv("LOCAL_PORT_RANGE")) == NULL) LOCAL_PORT_RANGE = "";
 if ((LOGLEVEL = getenv("LOGLEVEL")) == NULL) LOGLEVEL = "";
 if ((LOG_HOST_INPUT = getenv("LOG_HOST_INPUT")) == NULL) LOG_HOST_INPUT = "";
 if ((LOG_HOST_INPUT_IP = getenv("LOG_HOST_INPUT_IP")) == NULL) LOG_HOST_INPUT_IP = "";
 if ((LOG_HOST_INPUT_TCP = getenv("LOG_HOST_INPUT_TCP")) == NULL) LOG_HOST_INPUT_TCP = "";
 if ((LOG_HOST_INPUT_UDP = getenv("LOG_HOST_INPUT_UDP")) == NULL) LOG_HOST_INPUT_UDP = "";
 if ((LOG_HOST_OUTPUT = getenv("LOG_HOST_OUTPUT")) == NULL) LOG_HOST_OUTPUT = "";
 if ((LOG_HOST_OUTPUT_IP = getenv("LOG_HOST_OUTPUT_IP")) == NULL) LOG_HOST_OUTPUT_IP = "";
 if ((LOG_HOST_OUTPUT_TCP = getenv("LOG_HOST_OUTPUT_TCP")) == NULL) LOG_HOST_OUTPUT_TCP = "";
 if ((LOG_HOST_OUTPUT_UDP = getenv("LOG_HOST_OUTPUT_UDP")) == NULL) LOG_HOST_OUTPUT_UDP = "";
 if ((LOG_INPUT_IP = getenv("LOG_INPUT_IP")) == NULL) LOG_INPUT_IP = "";
 if ((LOG_INPUT_TCP = getenv("LOG_INPUT_TCP")) == NULL) LOG_INPUT_TCP = "";
 if ((LOG_INPUT_UDP = getenv("LOG_INPUT_UDP")) == NULL) LOG_INPUT_UDP = "";
 if ((LOG_MARTIANS = getenv("LOG_MARTIANS")) == NULL) LOG_MARTIANS = "";
 if ((LOG_OUTPUT_IP = getenv("LOG_OUTPUT_IP")) == NULL) LOG_OUTPUT_IP = "";
 if ((LOG_OUTPUT_TCP = getenv("LOG_OUTPUT_TCP")) == NULL) LOG_OUTPUT_TCP = "";
 if ((LOG_OUTPUT_UDP = getenv("LOG_OUTPUT_UDP")) == NULL) LOG_OUTPUT_UDP = "";
 if ((LOOSE_FORWARD = getenv("LOOSE_FORWARD")) == NULL) LOOSE_FORWARD = "";
 if ((LOST_CONNECTION_LOG = getenv("LOST_CONNECTION_LOG")) == NULL) LOST_CONNECTION_LOG = "";
 if ((MANGLE_TOS = getenv("MANGLE_TOS")) == NULL) MANGLE_TOS = "";
 if ((MY_VERSION = getenv("MY_VERSION")) == NULL) MY_VERSION = "";
 if ((NAT = getenv("NAT")) == NULL) NAT = "";
 if ((NAT_FORWARD_IP = getenv("NAT_FORWARD_IP")) == NULL) NAT_FORWARD_IP = "";
 if ((NAT_FORWARD_TCP = getenv("NAT_FORWARD_TCP")) == NULL) NAT_FORWARD_TCP = "";
 if ((NAT_FORWARD_UDP = getenv("NAT_FORWARD_UDP")) == NULL) NAT_FORWARD_UDP = "";
 if ((NAT_INTERNAL_NET = getenv("NAT_INTERNAL_NET")) == NULL) NAT_INTERNAL_NET = "";
 if ((NAT_LOCAL_REDIRECT = getenv("NAT_LOCAL_REDIRECT")) == NULL) NAT_LOCAL_REDIRECT = "";
 if ((NAT_STATIC_IP = getenv("NAT_STATIC_IP")) == NULL) NAT_STATIC_IP = "";
 if ((NMB_BROADCAST_FIX = getenv("NMB_BROADCAST_FIX")) == NULL) NMB_BROADCAST_FIX = "";
 if ((NO_PMTU_DISCOVERY = getenv("NO_PMTU_DISCOVERY")) == NULL) NO_PMTU_DISCOVERY = "";
 if ((OPEN_ICMP = getenv("OPEN_ICMP")) == NULL) OPEN_ICMP = "";
 if ((OPEN_ICMPV6 = getenv("OPEN_ICMPV6")) == NULL) OPEN_ICMPV6 = "";
 if ((OPEN_IP = getenv("OPEN_IP")) == NULL) OPEN_IP = "";
 if ((OPEN_TCP = getenv("OPEN_TCP")) == NULL) OPEN_TCP = "";
 if ((OPEN_UDP = getenv("OPEN_UDP")) == NULL) OPEN_UDP = "";
 if ((OTHER_IP_LOG = getenv("OTHER_IP_LOG")) == NULL) OTHER_IP_LOG = "";
 if ((PACKET_TTL = getenv("PACKET_TTL")) == NULL) PACKET_TTL = "";
 if ((PLUGIN_BIN_PATH = getenv("PLUGIN_BIN_PATH")) == NULL) PLUGIN_BIN_PATH = "";
 if ((PLUGIN_CONF_PATH = getenv("PLUGIN_CONF_PATH")) == NULL) PLUGIN_CONF_PATH = "";
 if ((PLUGIN_LOAD_FILE_RESTART = getenv("PLUGIN_LOAD_FILE_RESTART")) == NULL) PLUGIN_LOAD_FILE_RESTART = "";
 if ((POSSIBLE_SCAN_LOG = getenv("POSSIBLE_SCAN_LOG")) == NULL) POSSIBLE_SCAN_LOG = "";
 if ((PRIV_TCP_LOG = getenv("PRIV_TCP_LOG")) == NULL) PRIV_TCP_LOG = "";
 if ((PRIV_UDP_LOG = getenv("PRIV_UDP_LOG")) == NULL) PRIV_UDP_LOG = "";
 if ((REDUCE_DOS_ABILITY = getenv("REDUCE_DOS_ABILITY")) == NULL) REDUCE_DOS_ABILITY = "";
 if ((REJECT_TCP = getenv("REJECT_TCP")) == NULL) REJECT_TCP = "";
 if ((REJECT_TCP_NOLOG = getenv("REJECT_TCP_NOLOG")) == NULL) REJECT_TCP_NOLOG = "";
 if ((REJECT_UDP = getenv("REJECT_UDP")) == NULL) REJECT_UDP = "";
 if ((REJECT_UDP_NOLOG = getenv("REJECT_UDP_NOLOG")) == NULL) REJECT_UDP_NOLOG = "";
 if ((RESERVED_NET_LOG = getenv("RESERVED_NET_LOG")) == NULL) RESERVED_NET_LOG = "";
 if ((RP_FILTER = getenv("RP_FILTER")) == NULL) RP_FILTER = "";
 if ((SCAN_LOG = getenv("SCAN_LOG")) == NULL) SCAN_LOG = "";
 if ((SEP = getenv("SEP")) == NULL) SEP = "";
 if ((SEP2 = getenv("SEP2")) == NULL) SEP2 = "";
 if ((SEP3 = getenv("SEP3")) == NULL) SEP3 = "";
 if ((SET_MSS = getenv("SET_MSS")) == NULL) SET_MSS = "";
 if ((SOURCE_ROUTE_PROTECTION = getenv("SOURCE_ROUTE_PROTECTION")) == NULL) SOURCE_ROUTE_PROTECTION = "";
 if ((STATIC_IP = getenv("STATIC_IP")) == NULL) STATIC_IP = "";
 if ((SYN_PROT = getenv("SYN_PROT")) == NULL) SYN_PROT = "";
 if ((SYSCTL = getenv("SYSCTL")) == NULL) SYSCTL = "";
 if ((TRAFFIC_SHAPING = getenv("TRAFFIC_SHAPING")) == NULL) TRAFFIC_SHAPING = "";
 if ((TRUSTED_IF = getenv("TRUSTED_IF")) == NULL) TRUSTED_IF = "";
 if ((TTL_INC = getenv("TTL_INC")) == NULL) TTL_INC = "";
 if ((UNPRIV_TCP_LOG = getenv("UNPRIV_TCP_LOG")) == NULL) UNPRIV_TCP_LOG = "";
 if ((UNPRIV_UDP_LOG = getenv("UNPRIV_UDP_LOG")) == NULL) UNPRIV_UDP_LOG = "";

#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
 if ((DMZ_TCP = getenv("DMZ_TCP")) == NULL) DMZ_TCP = "";
 if ((DMZ_UDP = getenv("DMZ_UDP")) == NULL) DMZ_UDP = "";
 if ((DMZ_NAT_IP = getenv("DMZ_NAT_IP")) == NULL) DMZ_NAT_IP = "";
 if ((PORT_SCAN_DOS_DISABLE = getenv("PORT_SCAN_DOS_DISABLE")) == NULL) PORT_SCAN_DOS_DISABLE = "";
 if ((TRIGGER_TIMEOUT = getenv("TRIGGER_TIMEOUT")) == NULL) TRIGGER_TIMEOUT = "";
 if ((FIREWALL_ENABLE = getenv("FIREWALL_ENABLE")) == NULL) FIREWALL_ENABLE = ""; // Mos 2014/08/20, modify behavior of disable firewall
#endif

 if (FIREWALL_LOG == NULL) FIREWALL_LOG = "/dev/console";
 FIREWALL_LOG_FILE = fopen(FIREWALL_LOG, "w");
}


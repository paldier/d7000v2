/* dnsmasq is Copyright (c) 2000-2004 Simon Kelley

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 dated June, 1991.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
*/

/* Author's email: simon@thekelleys.org.uk */

#include "dnsmasq.h"

static int sigterm, sighup, sigusr1, sigalarm, num_kids, in_child;
/* Foxconn added start, Winster Chan, 01/12/2007 */
/* foxconn wklin modified start, 01/24/2007 */
/* init this value to -1, so that it won't affect the
 * protocols other than pptp/pppoe which support DoD.
 */
static int wan_up = -1;
/* foxconn wklin modified end, 01/24/2007 */
/* Foxconn added end, Winster Chan, 01/12/2007 */
/* foxconn wklin added start, 09/03/2007 @mpoe */
#ifdef MULTIPLE_PPPOE
keyword_t *keyword_list = NULL;
static void keyword_list_init(void);

/* foxconn BobGuo added start, 10/24/2007 */

Session2_DNS    Session2_Dns_Tbl;
static void Session2_Dns_Tbl_Init();

/* foxconn BobGuo added end, 10/24/2007 */


#endif /* MULTIPLE_PPPOE */
/* foxconn wklin added end, 09/03/2007 @mpoe*/

/* foxconn removed start by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/
#if 0
/* Foxconn added start, zacker, 07/29/2008,@Russia_PPTP */
keyword_t pptp_domain;
static void pptp_domain_list_init(void);

Session2_DNS pptp_dhcp_dns_tbl;
static void pptp_dhcp_dns_tbl_init(void);
/* Foxconn added end, zacker, 07/29/2008,@Russia_PPTP */
#endif
/* foxconn removed end by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/

static int set_dns_listeners(struct daemon *daemon, fd_set *set, int maxfd);
static void check_dns_listeners(struct daemon *daemon, fd_set *set, time_t now);
static void sig_handler(int sig);

/* foxconn removed start by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/
#if 0
/* Foxconn added start, zacker, 07/29/2008,@Russia_PPTP */
static void pptp_domain_list_init(void) {
    FILE *fp;
    char *token;
    char buf[256];

    memset(&pptp_domain, 0, sizeof(pptp_domain));

    fp = fopen("/tmp/ppp/pptp_domain", "r");
    if(fp == NULL)
        return;

    while (fgets(buf, sizeof(buf), fp))
    {
        token = strtok(buf, " \t\n");
        if(token == NULL)
            continue;
        if(token)
        {
            strcpy(pptp_domain.name, token);
            pptp_domain.next = NULL;
            pptp_domain.wildcard = 0;
        }
    }

    fclose(fp);
}

static void pptp_dhcp_dns_tbl_init()
{
    FILE *fp;
    char *token;
    char line[256];
    in_addr_t   dnsServer;

    memset(&pptp_dhcp_dns_tbl, 0, sizeof(Session2_DNS));
    pptp_dhcp_dns_tbl.iDNSCount = 0;
    
    fp = fopen("/tmp/ppp/pptp_dhcp_dns.conf", "r");
    if(fp == NULL)
        return;
        
    while (fgets(line, sizeof(line), fp)) 
    {
        token = strtok(line, " \t\n");
        if(token == NULL)
            continue;
        if( strcmp(token, "nameserver") == 0)
        {
            token = strtok(NULL, " \t\n");
            if(token)
            {
                dnsServer = inet_addr(token);
                pptp_dhcp_dns_tbl.DNSEntry[pptp_dhcp_dns_tbl.iDNSCount] = dnsServer;
                pptp_dhcp_dns_tbl.iDNSCount++;
            }
        }   
    }
    
    fclose(fp);
}
/* Foxconn added end, zacker, 07/29/2008,@Russia_PPTP */
#endif
/* foxconn removed end by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/

/* foxconn wklin added start, 09/03/2007 @mpoe */
#ifdef MULTIPLE_PPPOE
static void keyword_list_init(void) {
    FILE *fp;
    char buf[MAX_KEYWORD_LEN];
    keyword_t *k1, *k2;

    keyword_t *keyword, *to_be_freed;
    /* fprintf(stderr, "keyword_list_init.\n"); */
    if (keyword_list) {
        /* fprintf(stderr, "free keyword_list.\n"); */
        for (keyword=keyword_list; keyword;) {
            to_be_freed = keyword;
            keyword = keyword->next;
            free(to_be_freed);
            /* fprintf(stderr, "keyword %p freed.\n",keyword);*/
        }
        keyword_list = NULL;
    }
    fp = fopen("/tmp/mpoe_keywords", "r");
    if (fp) {
        while (NULL != fgets(buf, sizeof(buf), fp)) {
            buf[strlen(buf)-1] = '\0'; /* remove \n */
            /* fprintf(stderr, "read keyword %s\n", buf);*/
            k1 = malloc(sizeof(keyword_t));
            if (!k1) {
                /* fprintf(stderr, "out of memory"); */
                return;
            }
            if (strstr(buf, "*")) {
                k1->wildcard = 1;
                strcpy(k1->name, strstr(buf, "*")+1);
            } else {
                k1->wildcard = 0;
                strcpy(k1->name, buf);
            }
            k1->next = NULL;
            /* fprintf(stderr, "added %s (%d) to keyword_list\n", k1->name,
                    k1->wildcard); */
            if (!keyword_list) {
                keyword_list = k1;
            } else {
                k2 = keyword_list;
                while(k2->next)
                    k2 = k2->next;
                k2->next = k1;
            }
        }
        fclose(fp);
    }
}

/* foxconn BobGuo added start, 10/24/2007 */
static void Session2_Dns_Tbl_Init()
{
    FILE *fp;
    char *token;
    char line[256];
    in_addr_t   dnsServer;
    
    Session2_Dns_Tbl.iDNSCount = 0;
    fp = fopen("/tmp/resolv_session2.conf", "r");
    if(fp == NULL)
        return;
        
    while (fgets(line, sizeof(line), fp)) 
    {
        token = strtok(line, " \t\n");
        if(token == NULL)
            continue;
        if( strcmp(token, "nameserver") == 0)
        {
            token = strtok(NULL, " \t\n");
            if(token)
            {
                dnsServer = inet_addr(token);
                Session2_Dns_Tbl.DNSEntry[Session2_Dns_Tbl.iDNSCount] = dnsServer;
                Session2_Dns_Tbl.iDNSCount++;
            }
        }   
    }
    
    fclose(fp);
}

/* foxconn BobGuo added end, 10/24/2007 */

#endif /* MULTIPLE_PPPOE */
/* foxconn wklin added end, 09/03/2007 @mpoe */
int main (int argc, char **argv)
{
  struct daemon *daemon;
  int first_loop = 1;
  int bind_fallback = 0;
  time_t resolv_changed = 0;
  time_t now, last = 0;
  struct irec *interfaces;
  struct sigaction sigact;
  sigset_t sigmask;

  sighup = 1; /* init cache the first time through */
  sigusr1 = 0; /* but don't dump */
  sigterm = 0; /* or die */
#ifdef HAVE_BROKEN_RTC
  sigalarm = 1; /* need regular lease dumps */
#else
  sigalarm = 0; /* or not */
#endif
  num_kids = 0;
  in_child = 0;
 
  sigact.sa_handler = sig_handler;
  sigact.sa_flags = 0;
  sigemptyset(&sigact.sa_mask);
  sigaction(SIGUSR1, &sigact, NULL);
  sigaction(SIGHUP, &sigact, NULL);
  sigaction(SIGTERM, &sigact, NULL);
  sigaction(SIGALRM, &sigact, NULL);
  sigaction(SIGCHLD, &sigact, NULL);
  /* Foxconn added start, Winster Chan, 01/12/2007 */
  sigaction(SIGINT, &sigact, NULL);
  sigaction(SIGUSR2, &sigact, NULL);
  /* Foxconn added end, Winster Chan, 01/12/2007 */

  /* ignore SIGPIPE */
  sigact.sa_handler = SIG_IGN;
  sigaction(SIGPIPE, &sigact, NULL);

  /* now block all the signals, they stay that way except
      during the call to pselect */
  sigaddset(&sigact.sa_mask, SIGUSR1);
  sigaddset(&sigact.sa_mask, SIGTERM);
  sigaddset(&sigact.sa_mask, SIGHUP);
  sigaddset(&sigact.sa_mask, SIGALRM);
  sigaddset(&sigact.sa_mask, SIGCHLD);
  /* Foxconn added start, Winster Chan, 01/12/2007 */
  sigaddset(&sigact.sa_mask, SIGINT);
  sigaddset(&sigact.sa_mask, SIGUSR2);
  /* Foxconn added end, Winster Chan, 01/12/2007 */
  sigprocmask(SIG_BLOCK, &sigact.sa_mask, &sigmask); 

  daemon = read_opts(argc, argv);
  
  if (daemon->edns_pktsz < PACKETSZ)
    daemon->edns_pktsz = PACKETSZ;
  daemon->packet = safe_malloc(daemon->edns_pktsz > DNSMASQ_PACKETSZ ? 
			       daemon->edns_pktsz : DNSMASQ_PACKETSZ);
  
  if (!daemon->lease_file)
    {
      if (daemon->dhcp)
	daemon->lease_file = LEASEFILE;
    }
#ifndef HAVE_ISC_READER
  else if (!daemon->dhcp)
    die("ISC dhcpd integration not available: set HAVE_ISC_READER in src/config.h", NULL);
#endif
  
  interfaces = enumerate_interfaces(daemon);
    
  if (!(daemon->options & OPT_NOWILD) && 
      !(daemon->listeners = create_wildcard_listeners(daemon->port)))
    {
      bind_fallback = 1;
      daemon->options |= OPT_NOWILD;
    }
    
  if (daemon->options & OPT_NOWILD) 
    {
      struct iname *if_tmp;
      daemon->listeners = create_bound_listeners(interfaces, daemon->port);

      for (if_tmp = daemon->if_names; if_tmp; if_tmp = if_tmp->next)
	if (if_tmp->name && !if_tmp->used)
	  die("unknown interface %s", if_tmp->name);
  
      for (if_tmp = daemon->if_addrs; if_tmp; if_tmp = if_tmp->next)
	if (!if_tmp->used)
	  {
	    char *addrbuff = daemon->namebuff;
#ifdef HAVE_IPV6
	    if (if_tmp->addr.sa.sa_family == AF_INET)
	      inet_ntop(AF_INET, &if_tmp->addr.in.sin_addr,
			addrbuff, ADDRSTRLEN);
	    else
	      inet_ntop(AF_INET6, &if_tmp->addr.in6.sin6_addr,
			addrbuff, ADDRSTRLEN);
#else
	    strcpy(addrbuff, inet_ntoa(if_tmp->addr.in.sin_addr));
#endif
	    die("no interface with address %s", addrbuff);
	  }
    }
#if 0  
  /* wklin debug start */
  {
      int fd;
      fd = open("/dev/console", "w");
      if (fd) {
          dup2(fd, 2);
          close(fd);
      }
  }
  /* wklin debug end */
#endif
  forward_init(1);
  cache_init(daemon->cachesize, daemon->options & OPT_LOG);

#ifdef HAVE_BROKEN_RTC
  if ((daemon->uptime_fd = open(UPTIME, O_RDONLY)) == -1)
    die("cannot open " UPTIME ":%s", NULL);
#endif
 
  now = dnsmasq_time(daemon->uptime_fd);
  
#if 0 /* foxconn wklin removed, 01/24/2007 */
  if (daemon->dhcp)
    {
#if !defined(IP_PKTINFO) && !defined(IP_RECVIF)
      int c;
      struct iname *tmp;
      for (c = 0, tmp = daemon->if_names; tmp; tmp = tmp->next)
	if (!tmp->isloop)
	  c++;
      if (c != 1)
	die("must set exactly one interface on broken systems without IP_RECVIF", NULL);
#endif
      dhcp_init(daemon);
      lease_init(daemon, now);
    }
#endif

  /* If query_port is set then create a socket now, before dumping root
     for use to access nameservers without more specific source addresses.
     This allows query_port to be a low port */
  if (daemon->query_port)
    {
      union  mysockaddr addr;
      addr.in.sin_family = AF_INET;
      addr.in.sin_addr.s_addr = INADDR_ANY;
      addr.in.sin_port = htons(daemon->query_port);
#ifdef HAVE_SOCKADDR_SA_LEN
      addr.in.sin_len = sizeof(struct sockaddr_in);
#endif
      allocate_sfd(&addr, &daemon->sfds);
#ifdef HAVE_IPV6
      addr.in6.sin6_family = AF_INET6;
      addr.in6.sin6_addr = in6addr_any;
      addr.in6.sin6_port = htons(daemon->query_port);
      addr.in6.sin6_flowinfo = htonl(0);
#ifdef HAVE_SOCKADDR_SA_LEN
      addr.in6.sin6_len = sizeof(struct sockaddr_in6);
#endif
      allocate_sfd(&addr, &daemon->sfds);
#endif
    }
  
  setbuf(stdout, NULL);

  if (!(daemon->options & OPT_DEBUG))
    {
      FILE *pidfile;
      struct serverfd *serverfdp;
      struct listener *listener;
      struct passwd *ent_pw;
      int i;
        
      /* The following code "daemonizes" the process. 
	 See Stevens section 12.4 */

#ifndef NO_FORK
      if (!(daemon->options & OPT_NO_FORK))
	{
	  if (fork() != 0 )
	    exit(0);
	  
	  setsid();
	  
	  if (fork() != 0)
	    exit(0);
	}
#endif
      
      chdir("/");
      umask(022); /* make pidfile 0644 */
      
      /* write pidfile _after_ forking ! */
      if (daemon->runfile && (pidfile = fopen(daemon->runfile, "w")))
      	{
	  fprintf(pidfile, "%d\n", (int) getpid());
	  fclose(pidfile);
	}
      
      umask(0);

      for (i=0; i<64; i++)
	{
	  for (listener = daemon->listeners; listener; listener = listener->next)
	    if (listener->fd == i || listener->tcpfd == i)
	      break;
	  if (listener)
	    continue;

#ifdef HAVE_BROKEN_RTC	  
	  if (i == daemon->uptime_fd)
	    continue;
#endif

	  if (daemon->dhcp && 
	      (i == daemon->lease_fd || 
	       i == daemon->dhcpfd || 
	       i == daemon->dhcp_raw_fd ||
	       i == daemon->dhcp_icmp_fd))
	    continue;
	  
	  for (serverfdp = daemon->sfds; serverfdp; serverfdp = serverfdp->next)
	    if (serverfdp->fd == i)
	      break;
	  if (serverfdp)
	    continue;

	  close(i);
	}

      /* Change uid and gid for security */
      if (daemon->username && (ent_pw = getpwnam(daemon->username)))
	{
	  gid_t dummy;
	  struct group *gp;
	  /* remove all supplimentary groups */
	  setgroups(0, &dummy);
	  /* change group for /etc/ppp/resolv.conf 
	     otherwise get the group for "nobody" */
	  if ((daemon->groupname && (gp = getgrnam(daemon->groupname))) || 
	      (gp = getgrgid(ent_pw->pw_gid)))
	    setgid(gp->gr_gid); 
	  /* finally drop root */
	  setuid(ent_pw->pw_uid);
	}
    }

#ifdef USE_SYSLOG /* foxconn wklin added, 08/13/2007 */
  openlog("dnsmasq", 
	  DNSMASQ_LOG_OPT(daemon->options & OPT_DEBUG), 
	  DNSMASQ_LOG_FAC(daemon->options & OPT_DEBUG));
  
  if (daemon->cachesize != 0)
    syslog(LOG_INFO, "started, version %s cachesize %d", VERSION, daemon->cachesize);
  else
    syslog(LOG_INFO, "started, version %s cache disabled", VERSION);
  
  if (bind_fallback)
    syslog(LOG_WARNING, "setting --bind-interfaces option because of OS limitations");
#endif /* USE_SYSLOG */
  
#if 0 /* foxconn wklin removed, 01/24/2007 */
  if (daemon->dhcp)
    {
      struct dhcp_context *dhcp_tmp;
      for (dhcp_tmp = daemon->dhcp; dhcp_tmp; dhcp_tmp = dhcp_tmp->next)
	{
	  char *time = daemon->dhcp_buff2;
	  strcpy(daemon->dhcp_buff, inet_ntoa(dhcp_tmp->start));
	  if (dhcp_tmp->lease_time == 0)
	    sprintf(time, "infinite");
	  else
	    {
	      unsigned int x, p = 0, t = (unsigned int)dhcp_tmp->lease_time;
	      if ((x = t/3600))
		p += sprintf(&time[p], "%dh", x);
	      if ((x = (t/60)%60))
		p += sprintf(&time[p], "%dm", x);
	      if ((x = t%60))
		p += sprintf(&time[p], "%ds", x);
	    }
	  syslog(LOG_INFO, 
		 dhcp_tmp->static_only ? 
		 "DHCP, static leases only on %.0s%s, lease time %s" :
		 "DHCP, IP range %s -- %s, lease time %s",
		 daemon->dhcp_buff, inet_ntoa(dhcp_tmp->end), time);
	}
    }
#endif

#ifdef USE_SYSLOG /* foxconn wklin added, 08/13/2007 */
#ifdef HAVE_BROKEN_RTC
  if (daemon->dhcp)
    syslog(LOG_INFO, "DHCP, %s will be written every %ds", daemon->lease_file, daemon->min_leasetime/3);
#endif
  
  if (!(daemon->options & OPT_DEBUG) && (getuid() == 0 || geteuid() == 0))
    syslog(LOG_WARNING, "running as root");
#endif /* USE_SYSLOG */

  check_servers(daemon, interfaces);
  
  while (sigterm == 0)
    {
      fd_set rset;
      
      if (sighup)
	{
	  cache_reload(daemon->options, daemon->namebuff, daemon->domain_suffix, daemon->addn_hosts);
#if 0
	  if (daemon->dhcp)
	    {
	      if (daemon->options & OPT_ETHERS)
		dhcp_read_ethers(daemon);
	      dhcp_update_configs(daemon->dhcp_conf);
	      lease_update_from_configs(daemon->dhcp_conf, daemon->domain_suffix); 
	      lease_update_file(0, now); 
	      lease_update_dns();
	    }
#endif
	  if (daemon->resolv_files && (daemon->options & OPT_NO_POLL))
	    {
	      reload_servers(daemon->resolv_files->name, daemon);
	      check_servers(daemon, interfaces);
	    }

	  /* foxconn wklin added start, 09/03/2007 @mpoe */
#ifdef MULTIPLE_PPPOE
	  keyword_list_init();
	  Session2_Dns_Tbl_Init();
#endif /* MULTIPLE_PPPOE */
	  /* foxconn wklin added end, 09/03/2007 @mpoe*/

      /* foxconn removed start by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/
#if 0
      /* Foxconn added start, zacker, 07/29/2008,@Russia_PPTP */
      pptp_domain_list_init();
      pptp_dhcp_dns_tbl_init();
      /* Foxconn added end, zacker, 07/29/2008,@Russia_PPTP */
#endif
      /* foxconn removed end by Jenny Zhao, 12/10/2008,@Russia_PPTP new spec*/

	  sighup = 0;
	}
      
      if (sigusr1)
	{
	  dump_cache(daemon->options & (OPT_DEBUG | OPT_LOG), daemon->cachesize);
	  sigusr1 = 0;
	}
      
      if (sigalarm)
	{
#if 0	
	  if (daemon->dhcp)
	    {
	      lease_update_file(1, now);
#ifdef HAVE_BROKEN_RTC
	      alarm(daemon->min_leasetime/3);
#endif
	    } 
#endif
	  sigalarm  = 0;
	}
      
      FD_ZERO(&rset);
      
      if (!first_loop)
	{
	  int maxfd = set_dns_listeners(daemon, &rset, 0);
	  	  
#if 0  /* foxconn wklin removed, 01/24/2007 */	  	  
	  if (daemon->dhcp)
	    {
	      FD_SET(daemon->dhcpfd, &rset);
	      if (daemon->dhcpfd > maxfd)
		maxfd = daemon->dhcpfd;
	    }
#endif

#ifdef HAVE_PSELECT
	  if (pselect(maxfd+1, &rset, NULL, NULL, NULL, &sigmask) < 0)
	    FD_ZERO(&rset); /* rset otherwise undefined after error */ 
#else
	  {
	    sigset_t save_mask;
	    sigprocmask(SIG_SETMASK, &sigmask, &save_mask);
	    if (select(maxfd+1, &rset, NULL, NULL, NULL) < 0)
	      FD_ZERO(&rset); /* rset otherwise undefined after error */ 
	    sigprocmask(SIG_SETMASK, &save_mask, NULL);
	  }
#endif
	}

      first_loop = 0;
      now = dnsmasq_time(daemon->uptime_fd);

      /* Check for changes to resolv files once per second max. */
      if (last == 0 || difftime(now, last) > 1.0)
	{
	  last = now;

#ifdef HAVE_ISC_READER
	  if (daemon->lease_file && !daemon->dhcp)
	    load_dhcp(daemon->lease_file, daemon->domain_suffix, now, daemon->namebuff);
#endif

	  if (!(daemon->options & OPT_NO_POLL))
	    {
	      struct resolvc *res = daemon->resolv_files, *latest = NULL;
	      struct stat statbuf;
	      time_t last_change = 0;
	      /* There may be more than one possible file. 
		 Go through and find the one which changed _last_.
		 Warn of any which can't be read. */
	      while (res)
		{
		  if (stat(res->name, &statbuf) == -1)
		    {
#ifdef USE_SYSLOG /* foxconn wklin added, 08/13/2007 */
		      if (!res->logged)
			syslog(LOG_WARNING, "failed to access %s: %m", res->name);
#endif
		      res->logged = 1;
		    }
		  else
		    {
		      res->logged = 0;
		      if (difftime(statbuf.st_mtime, last_change) > 0.0)
			{
			  last_change = statbuf.st_mtime;
			  latest = res;
			}
		    }
		  res = res->next;
		}
	  
	      if (latest && difftime(last_change, resolv_changed) > 0.0)
		{
		  resolv_changed = last_change;
		  reload_servers(latest->name, daemon);
		  check_servers(daemon, interfaces);
		}
	    }
	}

      check_dns_listeners(daemon, &rset, now);

#if 0	  
      if (daemon->dhcp && FD_ISSET(daemon->dhcpfd, &rset))
	dhcp_packet(daemon, now);
#endif	
    }
  
#ifdef USE_SYSLOG /* foxconn wklin added, 08/13/2007 */
  syslog(LOG_INFO, "exiting on receipt of SIGTERM");
#endif

#if 0
  if (daemon->dhcp)
    { 
#ifdef HAVE_BROKEN_RTC
      lease_update_file(1, now);
#endif
      close(daemon->lease_fd);
    }
#endif

  return 0;
}

static void sig_handler(int sig)
{
  if (sig == SIGTERM)
    sigterm = 1;
  else if (sig == SIGHUP)
    sighup = 1;
  else if (sig == SIGUSR1)
    sigusr1 = 1;
  else if (sig == SIGALRM)
    {
      /* alarm is used to kill children after a fixed time. */
      if (in_child)
	exit(0);
      else
	sigalarm = 1;
    }
  else if (sig == SIGCHLD)
    {
      /* See Stevens 5.10 */
      
      while (waitpid(-1, NULL, WNOHANG) > 0)
	num_kids--;
    }
  /* Foxconn added start, Winster Chan, 01/12/2007 */
  else if (sig == SIGINT)
  {
    wan_up = 0; /* foxconn wklin modified, 01/24/2007 */
  }
  else if (sig == SIGUSR2)
  {
    wan_up = 1; /* foxconn wklin modified, 01/24/2007 */
  }
  /* Foxconn added end, Winster Chan, 01/12/2007 */
}

static int set_dns_listeners(struct daemon *daemon, fd_set *set, int maxfd)
{
  struct serverfd *serverfdp;
  struct listener *listener;

  for (serverfdp = daemon->sfds; serverfdp; serverfdp = serverfdp->next)
    {
      FD_SET(serverfdp->fd, set);
      if (serverfdp->fd > maxfd)
	maxfd = serverfdp->fd;
    }
	  
  for (listener = daemon->listeners; listener; listener = listener->next)
    {
      FD_SET(listener->fd, set);
      if (listener->fd > maxfd)
	maxfd = listener->fd;
      FD_SET(listener->tcpfd, set);
      if (listener->tcpfd > maxfd)
	maxfd = listener->tcpfd;
    }

  return maxfd;
}

static void check_dns_listeners(struct daemon *daemon, fd_set *set, time_t now)
{
  struct serverfd *serverfdp;
  struct listener *listener;	  

   for (serverfdp = daemon->sfds; serverfdp; serverfdp = serverfdp->next)
     if (FD_ISSET(serverfdp->fd, set))
       reply_query(serverfdp, daemon, now);

   for (listener = daemon->listeners; listener; listener = listener->next)
     {
       if (FD_ISSET(listener->fd, set))
        {
          /* Foxconn added start, Winster Chan, 01/12/2007 */
          if (!wan_up) /* maybe true in pptp/pppoe mode */
            {
                system("killall -SIGUSR1 bpa_monitor");     /* Foxconn added Bob Guo, 02/25/2007, trigger BPA to dial up */
                system("ping -c 1 -g 0 255.255.255.255");
            }
          /* Foxconn added end, Winster Chan, 01/12/2007 */
          receive_query(listener, daemon, now);
        }
       
    if (FD_ISSET(listener->tcpfd, set))
	{
	   int confd;
	   
	   while((confd = accept(listener->tcpfd, NULL, NULL)) == -1 && errno == EINTR);
	      
	   if (confd != -1)
	   {
	       int match = 1;
	       if (!(daemon->options & OPT_NOWILD)) 
		 {
		   /* Check for allowed interfaces when binding the wildcard address */
		   /* Don't know how to get interface of a connection, so we have to
		      check by address. This will break when interfaces change address */
		   union mysockaddr tcp_addr;
		   socklen_t tcp_len = sizeof(union mysockaddr);
		   struct iname *tmp;
		   
		   if (getsockname(confd, (struct sockaddr *)&tcp_addr, &tcp_len) != -1)
		     {
#ifdef HAVE_IPV6
		       if (tcp_addr.sa.sa_family == AF_INET6)
			 tcp_addr.in6.sin6_flowinfo =  htonl(0);
#endif
		       for (match = 1, tmp = daemon->if_except; tmp; tmp = tmp->next)
			        if (sockaddr_isequal(&tmp->addr, &tcp_addr))
			            match = 0;
		       
		       if (match && (daemon->if_names || daemon->if_addrs))
			 {
			   match = 0;
			   for (tmp = daemon->if_names; tmp; tmp = tmp->next)
			     if (sockaddr_isequal(&tmp->addr, &tcp_addr))
			       match = 1;
			   for (tmp = daemon->if_addrs; tmp; tmp = tmp->next)
			     if (sockaddr_isequal(&tmp->addr, &tcp_addr))
			       match = 1;  
			 }
		     }
		 }			  
	       
	       if (!match || (num_kids >= MAX_PROCS))
		 close(confd);
	       else if (!(daemon->options & OPT_DEBUG) && fork())
		 {
		   num_kids++;
		   close(confd);
		 }
	       else
		 {
		   char *buff;
		   struct server *s; 
		   int flags;
		   
		   /* Arrange for SIGALARM after CHILD_LIFETIME seconds to
		      terminate the process. */
		   if (!(daemon->options & OPT_DEBUG))
		     {
		       sigset_t mask;
		       sigemptyset(&mask);
		       sigaddset(&mask, SIGALRM);
		       sigprocmask(SIG_UNBLOCK, &mask, NULL);
		       alarm(CHILD_LIFETIME);
		       in_child = 1;
		     }
		   
		   /* start with no upstream connections. */
		   for (s = daemon->servers; s; s = s->next)
		     s->tcpfd = -1; 
		   
		   /* The connected socket inherits non-blocking
		      attribute from the listening socket. 
		      Reset that here. */
		   if ((flags = fcntl(confd, F_GETFL, 0)) != -1)
		     fcntl(confd, F_SETFL, flags & ~O_NONBLOCK);
		   
		   buff = tcp_request(daemon, confd, now);
		   
		   if (!(daemon->options & OPT_DEBUG))
		     exit(0);
		      
		   close(confd);
		   if (buff)
		     free(buff);
		   for (s = daemon->servers; s; s = s->next)
		     if (s->tcpfd != -1)
		       close(s->tcpfd);
		 }
	     }
	 }
     }
}

int icmp_ping(struct daemon *daemon, struct in_addr addr)
{
  /* Try and get an ICMP echo from a machine.
     Note that we can't create the raw socket each time
     we do this, since that needs root. Therefore the socket has to hang
     around all the time. Since most of the time we won't read the 
     socket, it will accumulate buffers full of ICMP messages,
     wasting memory. To avoid that we set the receive buffer
     length to zero except when we're actively pinging. */

  /* Note that whilst in the three second wait, we check for 
     (and service) events on the DNS sockets, (so doing that
     better not use any resources our caller has in use...)
     but we remain deaf to signals or further DHCP packets. */

  struct sockaddr_in saddr;
  struct { 
    struct ip ip;
    struct icmp icmp;
  } packet;
  unsigned short id = rand16();
  unsigned int i, j;
  int opt = 2000, gotreply = 0;
  time_t start, now;
  
  saddr.sin_family = AF_INET;
  saddr.sin_port = 0;
  saddr.sin_addr = addr;
#ifdef HAVE_SOCKADDR_SA_LEN
  saddr.sin_len = sizeof(struct sockaddr_in);
#endif
  
  memset(&packet.icmp, 0, sizeof(packet.icmp));
  packet.icmp.icmp_type = ICMP_ECHO;
  packet.icmp.icmp_id = id;
  for (j = 0, i = 0; i < sizeof(struct icmp) / 2; i++)
    j += ((u16 *)&packet.icmp)[i];
  while (j>>16)
    j = (j & 0xffff) + (j >> 16);  
  packet.icmp.icmp_cksum = (j == 0xffff) ? j : ~j;
  
  setsockopt(daemon->dhcp_icmp_fd, SOL_SOCKET, SO_RCVBUF, &opt, sizeof(opt));

  if (sendto(daemon->dhcp_icmp_fd, (char *)&packet.icmp, sizeof(struct icmp), 0, 
	     (struct sockaddr *)&saddr, sizeof(saddr)) == sizeof(struct icmp))
    for (now = start = dnsmasq_time(daemon->uptime_fd); difftime(now, start) < 3.0;)
      {
	struct timeval tv;
	fd_set rset;
	struct sockaddr_in faddr;
	int maxfd, len = sizeof(faddr);

	tv.tv_usec = 250000;
	tv.tv_sec = 0; 

	FD_ZERO(&rset);
	FD_SET(daemon->dhcp_icmp_fd, &rset);
	maxfd = set_dns_listeners(daemon, &rset, daemon->dhcp_icmp_fd);
		
	if (select(maxfd+1, &rset, NULL, NULL, &tv) < 0)
	  FD_ZERO(&rset);
	
	now = dnsmasq_time(daemon->uptime_fd);
	check_dns_listeners(daemon, &rset, now);
	
	if (FD_ISSET(daemon->dhcp_icmp_fd, &rset) &&
	    recvfrom(daemon->dhcp_icmp_fd, &packet, sizeof(packet), 0,
		     (struct sockaddr *)&faddr, &len) == sizeof(packet) &&
	    saddr.sin_addr.s_addr == faddr.sin_addr.s_addr &&
	    packet.icmp.icmp_type == ICMP_ECHOREPLY &&
	    packet.icmp.icmp_seq == 0 &&
	    packet.icmp.icmp_id == id)
	  {
	    gotreply = 1;
	    break;
	  }
      }

  opt = 1;
  setsockopt(daemon->dhcp_icmp_fd, SOL_SOCKET, SO_RCVBUF, &opt, sizeof(opt));

  return gotreply;
}

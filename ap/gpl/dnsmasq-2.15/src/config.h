/* dnsmasq is Copyright (c) 2000 Simon Kelley

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 dated June, 1991.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
*/

/* Author's email: simon@thekelleys.org.uk */
#ifdef OPENDNS_PARENTAL_CONTROL
#define VERSION "2.15-OpenDNS-1"  /* Foxconn modified, Tony W.Y. Wang, 12/02/2008, @Parental Control OpenDNS */
#else
#define VERSION "2.15"
#endif
/* foxconn wklin modified start, 08/31/2007 */
#ifdef MULTIPLE_PPPOE /* for downsize ram usage */
#define FTABSIZ 50 /* max number of outstanding requests */
#define MAX_PROCS 10 /* max no children for TCP requests */
#define CHILD_LIFETIME 150 /* secs 'till terminated (RFC1035 suggests > 120s) */
#define EDNS_PKTSZ 1280 /* default max EDNS.0 UDP packet from RFC2671 */
#define TIMEOUT 20 /* drop UDP queries after TIMEOUT seconds */
#define LOGRATE 120 /* log table overflows every LOGRATE seconds */
#define CACHESIZ 0 /* default cache size */
#define MAXTOK 50 /* token in DHCP leases */
#define MAXLEASES 150 /* maximum number of DHCP leases */
#define SMALLDNAME 40 /* most domain names are smaller than this */
#else
#define FTABSIZ 150 /* max number of outstanding requests */
#define MAX_PROCS 20 /* max no children for TCP requests */
#define CHILD_LIFETIME 150 /* secs 'till terminated (RFC1035 suggests > 120s) */
#define EDNS_PKTSZ 1280 /* default max EDNS.0 UDP packet from RFC2671 */
#define TIMEOUT 20 /* drop UDP queries after TIMEOUT seconds */
#define LOGRATE 120 /* log table overflows every LOGRATE seconds */
#define CACHESIZ 150 /* default cache size */
#define MAXTOK 50 /* token in DHCP leases */
#define MAXLEASES 150 /* maximum number of DHCP leases */
#define SMALLDNAME 40 /* most domain names are smaller than this */
#endif
/* foxconn wklin modified end, 08/31/2007 */
#define HOSTSFILE "/etc/hosts"
#define ETHERSFILE "/etc/ethers"
#ifdef __uClinux__
#  define RESOLVFILE "/etc/config/resolv.conf"
#else
#  define RESOLVFILE "/etc/resolv.conf"
#endif
#define RUNFILE "/var/run/dnsmasq.pid"
#if defined(__FreeBSD__) || defined (__OpenBSD__)
#   define LEASEFILE "/var/db/dnsmasq.leases"
#else
#   define LEASEFILE "/var/lib/misc/dnsmasq.leases"
#endif
#if defined(__FreeBSD__)
#   define CONFFILE "/usr/local/etc/dnsmasq.conf"
#else
#   define CONFFILE "/etc/dnsmasq.conf"
#endif
#define DEFLEASE 3600 /* default lease time, 1 hour */
#define CHUSER "nobody"
#define CHGRP "dip"
#define IP6INTERFACES "/proc/net/if_inet6"
#define UPTIME "/proc/uptime"
#define DHCP_SERVER_PORT 67
#define DHCP_CLIENT_PORT 68

/* Logfile stuff - change this to change the options and facility */
/* debug is true if the --no-daemon flag is given */
#ifdef LOG_PERROR
#  define DNSMASQ_LOG_OPT(debug)  (debug) ? LOG_PERROR : LOG_PID
#else
#  define DNSMASQ_LOG_OPT(debug)  (debug) ? 0 : LOG_PID
#endif

#ifdef LOG_LOCAL0
#  define DNSMASQ_LOG_FAC(debug)  (debug) ? LOG_LOCAL0 : LOG_DAEMON
#else
#  define DNSMASQ_LOG_FAC(debug)  LOG_DAEMON
#endif

/* A small collection of RR-types which are missing on some platforms */

#ifndef T_SRV
#  define T_SRV 33
#endif

#ifndef T_OPT
#  define T_OPT 41
#endif

/* Decide if we're going to support IPv6 */
/* We assume that systems which don't have IPv6
   headers don't have ntop and pton either */

#if defined(INET6_ADDRSTRLEN) && defined(IPV6_V6ONLY) && !defined(NO_IPV6)
#  define HAVE_IPV6
#  define ADDRSTRLEN INET6_ADDRSTRLEN
#  if defined(SOL_IPV6)
#    define IPV6_LEVEL SOL_IPV6
#  else
#    define IPV6_LEVEL IPPROTO_IPV6
#  endif
#elif defined(INET_ADDRSTRLEN)
#  undef HAVE_IPV6
#  define ADDRSTRLEN INET_ADDRSTRLEN
#else
#  undef HAVE_IPV6
#  define ADDRSTRLEN 16 /* 4*3 + 3 dots + NULL */
#endif

/* Get linux C library versions. */
#if defined(__linux__) && !defined(__UCLIBC__) && !defined(__uClinux__)
#  include <libio.h> 
#endif


/* Follows system specific switches. If you run on a 
   new system, you may want to edit these. 
   May replace this with Autoconf one day. 

HAVE_LINUX_IPV6_PROC
   define this to do IPv6 interface discovery using
   proc/net/if_inet6 ala LINUX. 

HAVE_BROKEN_RTC
   define this on embeded systems which don't have an RTC
   which keeps time over reboots. Causes dnsmasq to use uptime()
   for timing, and keep relative time values in its leases file.
   Also enables "Flash disk mode". Normally, dnsmasq tries very hard to 
   keep the on-disk leases file up-to-date: rewriting it after every change.
   When HAVE_BROKEN_RTC is in effect, a different regime is used:
   The leases file is written when dnsmasq terminates, when it receives
   SIGALRM, when a brand new lease is allocated, or every n seconds, 
   where n is one third  of the smallest time configured for leases 
   in a --dhcp-range or --dhcp-host option.
   NOTE: when enabling or disabling this, be sure to delete any old
   leases file, otherwise dnsmasq may get very confused.
   This configuration currently only works on Linux, but could be made to
   work on other systems by teaching dnsmasq_time() in utils.c how to
   read the system uptime.

HAVE_ISC_READER 
   define this to include the old ISC dhcpcd integration. Note that you cannot
   set both HAVE_ISC_READER and HAVE_BROKEN_RTC.

HAVE_GETOPT_LONG
   define this if you have GNU libc or GNU getopt. 

HAVE_ARC4RANDOM
   define this if you have arc4random() to get better security from DNS spoofs
   by using really random ids (OpenBSD) 

HAVE_RANDOM
   define this if you have the 4.2BSD random() function (and its
   associated srandom() function), which is at least as good as (if not
   better than) the rand() function.

HAVE_DEV_RANDOM
   define this if you have the /dev/random device, which gives truly
   random numbers but may run out of random numbers.

HAVE_DEV_URANDOM
   define this if you have the /dev/urandom device, which gives
   semi-random numbers when it runs out of truly random numbers.

HAVE_SOCKADDR_SA_LEN
   define this if struct sockaddr has sa_len field (*BSD) 

HAVE_PSELECT
   If your C library implements pselect, define this.

HAVE_BPF
   If your OS implements Berkeley PAcket filter, define this.

NOTES:
   For Linux you should define 
      HAVE_LINUX_IPV6_PROC 
      HAVE_GETOPT_LONG
      HAVE_RANDOM
      HAVE_DEV_RANDOM
      HAVE_DEV_URANDOM
  you should NOT define 
      HAVE_ARC4RANDOM
      HAVE_SOCKADDR_SA_LEN

   For *BSD systems you should define 
     HAVE_SOCKADDR_SA_LEN
     HAVE_RANDOM
     HAVE_BPF
   you should NOT define  
     HAVE_LINUX_IPV6_PROC 
   and you MAY define  
     HAVE_ARC4RANDOM - OpenBSD and FreeBSD 
     HAVE_DEV_URANDOM - OpenBSD and FreeBSD
     HAVE_DEV_RANDOM - FreeBSD (OpenBSD with hardware random number generator)
     HAVE_GETOPT_LONG - only if you link GNU getopt. 

*/

/* platform independent options. */
#undef HAVE_BROKEN_RTC
#undef HAVE_ISC_READER /* #define HAVE_ISC_READER */

#if defined(HAVE_BROKEN_RTC) && defined(HAVE_ISC_READER)
#  error HAVE_ISC_READER is not compatible with HAVE_BROKEN_RTC
#endif

/* platform dependent options. */

/* Must preceed __linux__ since uClinux defines __linux__ too. */
#if defined(__uClinux__) || defined(__UCLIBC__)
#undef HAVE_LINUX_IPV6_PROC
#define HAVE_GETOPT_LONG
#undef HAVE_ARC4RANDOM
#define HAVE_RANDOM
#define HAVE_DEV_URANDOM
#define HAVE_DEV_RANDOM
#undef HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
/* Don't fork into background on uClinux */
#if defined(__uClinux__)
#  define NO_FORK
#endif

/* libc5 - must precede __linux__ too */
/* Note to build a libc5 binary on a modern Debian system:
   install the packages altgcc libc5 and libc5-altdev 
   then run "make CC=i486-linuxlibc1-gcc" */
/* Note that compling dnsmasq 2.x under libc5 and kernel 2.0.x
   is probably doomed - no packet socket for starters. */
#elif defined(__linux__) && \
      defined(_LINUX_C_LIB_VERSION_MAJOR) && \
      (_LINUX_C_LIB_VERSION_MAJOR == 5 )
#undef HAVE_IPV6
#undef HAVE_LINUX_IPV6_PROC
#define HAVE_GETOPT_LONG
#undef HAVE_ARC4RANDOM
#define HAVE_RANDOM
#define HAVE_DEV_URANDOM
#define HAVE_DEV_RANDOM
#undef HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
/* Fix various misfeatures of libc5 headers */
typedef unsigned long in_addr_t; 
typedef size_t socklen_t;

/* This is for glibc 2.x */
#elif defined(__linux__)
#define HAVE_LINUX_IPV6_PROC
#define HAVE_GETOPT_LONG
#undef HAVE_ARC4RANDOM
#define HAVE_RANDOM
#define HAVE_DEV_URANDOM
#define HAVE_DEV_RANDOM
#undef HAVE_SOCKADDR_SA_LEN
#define HAVE_PSELECT
/* glibc < 2.2  has broken Sockaddr_in6 so we have to use our own. */
/* glibc < 2.2 doesn't define in_addr_t */
#if defined(__GLIBC__) && (__GLIBC__ == 2) && \
    defined(__GLIBC_MINOR__) && (__GLIBC_MINOR__ < 2)
typedef unsigned long in_addr_t; 
#if defined(HAVE_IPV6)
#   define HAVE_BROKEN_SOCKADDR_IN6
#endif
#endif

/* #elif defined(__OpenBSD__)
#error The sockets API in OpenBSD does not provide facilities required by dnsmasq
*/
#elif defined(__FreeBSD__) || defined(__OpenBSD__)
#undef HAVE_LINUX_IPV6_PROC
#undef HAVE_GETOPT_LONG
#define HAVE_ARC4RANDOM
#define HAVE_RANDOM
#define HAVE_DEV_URANDOM
#define HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
#define HAVE_BPF

#elif defined(__APPLE__)
#undef HAVE_LINUX_IPV6_PROC
#undef HAVE_GETOPT_LONG
#define HAVE_ARC4RANDOM
#define HAVE_RANDOM
#define HAVE_DEV_URANDOM
#define HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
#define HAVE_BPF
#define BIND_8_COMPAT
/* Define before sys/socket.h is included so we get socklen_t */
#define _BSD_SOCKLEN_T_
/* The three below are not defined in Mac OS X arpa/nameserv.h */
#define IN6ADDRSZ 16
 
#elif defined(__NetBSD__)
#undef HAVE_LINUX_IPV6_PROC
#undef HAVE_GETOPT_LONG
#undef HAVE_ARC4RANDOM
#define HAVE_RANDOM
#undef HAVE_DEV_URANDOM
#undef HAVE_DEV_RANDOM
#define HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
#define HAVE_BPF
 
/* env "LIBS=-lsocket -lnsl" make */
#elif defined(__sun) || defined(__sun__)
#undef HAVE_LINUX_IPV6_PROC
#undef HAVE_GETOPT_LONG
#undef HAVE_ARC4RANDOM
#define HAVE_RANDOM
#undef HAVE_DEV_URANDOM
#undef HAVE_DEV_RANDOM
#undef HAVE_SOCKADDR_SA_LEN
#undef HAVE_PSELECT
#define HAVE_BPF
#endif





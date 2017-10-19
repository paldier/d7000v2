/*
 ------------------------------------------------------------------------------
                           -= Arno's iptables firewall =-
               Single- & multi-homed firewall script with DSL/ADSL support

                           ~ In memory of my dear father ~

 (C) Copyright 2001-2010 by Arno van Amersfoort
 Co-authors            : Lonnie Abelbeck & Philip Prindeville
 Homepage              : http://rocky.eld.leidenuniv.nl/
 Freshmeat homepage    : http://freshmeat.net/projects/iptables-firewall/?topic_id=151
 Email                 : a r n o v a AT r o c k y DOT e l d DOT l e i d e n u n i v DOT n l
                         (note: you must remove all spaces and substitute the @ and the .
                         at the proper locations!)
 ------------------------------------------------------------------------------
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 ------------------------------------------------------------------------------

 Includes Intel Corporation's changes/modifications dated: 
   13-Apr-2011: Corrected icmp-type, from icmp-request --> echo-request
   22-Aug-2011: Force *_batch processing 
   25-Feb-2013: Generate to a C file

 Changed/modified portions - Copyright ?2013, Intel Corporation.

 ------------------------------------------------------------------------------
*/

#define _CARNOENV_C_

/*! \file carnoenv.c
    \brief functions from the arno environment script translated into C
*/

/**************************************************************************/
/*      INCLUDES:                                                         */
/**************************************************************************/

#include <arpa/inet.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#define __USE_GNU
#include <string.h>
#undef __USE_GNU

#include "carnoutils.h"

/**************************************************************************/
/*      EXTERNS Declaration:                                              */
/**************************************************************************/

extern char *EOL;
extern char *INDENT;
extern char *ANYHOST;
extern char *ANYPORT;
extern char *BAD_FLAGS_LOG;
extern char *BLOCKED_HOST_LOG;
extern char *BLOCK_HOSTS;
extern char *BLOCK_HOSTS_BIDIRECTIONAL;
extern char *BLOCK_HOSTS_FILE;
extern char *BROADCAST_TCP_NOLOG;
extern char *BROADCAST_UDP_NOLOG;
extern char *COUNT;
extern char *CUSTOM_RULES;
extern char *DATE;
extern char *DEFAULT_POLICY_DROP;
extern char *DENY_IP_OUTPUT;
extern char *DENY_TCP;
extern char *DENY_TCP_NOLOG;
extern char *DENY_TCP_OUTPUT;
extern char *DENY_UDP;
extern char *DENY_UDP_NOLOG;
extern char *DENY_UDP_OUTPUT;
extern char *DMESG_PANIC_ONLY;
extern char *DMZ_HOST_OPEN_IP;
extern char *DMZ_HOST_OPEN_TCP;
extern char *DMZ_HOST_OPEN_UDP;
extern char *DMZ_IF;
extern char *DMZ_INET_DENY_IP;
extern char *DMZ_INET_DENY_TCP;
extern char *DMZ_INET_DENY_UDP;
extern char *DMZ_INET_HOST_DENY_IP;
extern char *DMZ_INET_HOST_DENY_TCP;
extern char *DMZ_INET_HOST_DENY_UDP;
extern char *DMZ_INET_HOST_OPEN_IP;
extern char *DMZ_INET_HOST_OPEN_TCP;
extern char *DMZ_INET_HOST_OPEN_UDP;
extern char *DMZ_INET_OPEN_ICMP;
extern char *DMZ_INET_OPEN_IP;
extern char *DMZ_INET_OPEN_TCP;
extern char *DMZ_INET_OPEN_UDP;
extern char *DMZ_INPUT_DENY_LOG;
extern char *DMZ_LAN_HOST_OPEN_IP;
extern char *DMZ_LAN_HOST_OPEN_TCP;
extern char *DMZ_LAN_HOST_OPEN_UDP;
extern char *DMZ_LAN_OPEN_ICMP;
extern char *DMZ_NET;
extern char *DMZ_NET_ANTISPOOF;
extern char *DMZ_OPEN_ICMP;
extern char *DMZ_OPEN_IP;
extern char *DMZ_OPEN_TCP;
extern char *DMZ_OPEN_UDP;
extern char *DMZ_OUTPUT_DENY_LOG;
extern char *DRDOS_PROTECT;
extern char *DROP_PRIVATE_ADDRESSES;
extern char *EXTERNAL_DHCPV6_SERVER;
extern char *EXTERNAL_DHCP_SERVER;
extern char *EXTERNAL_NET;
extern char *EXTIF_NET;
extern char *EXT_IF;
extern char *EXT_IF_DHCP_IP;
extern char *EXT_NET_BCAST_ADDRESS;
extern char *FIREWALL_LOG;
extern char *FORWARD_DROP_LOG;
extern char *FORWARD_LINK_LOCAL;
extern char *FRAG_LOG;
extern char *FULL_ACCESS_HOSTS;
extern char *HOST_DENY_ICMP;
extern char *HOST_DENY_ICMP_NOLOG;
extern char *HOST_DENY_IP;
extern char *HOST_DENY_IP_NOLOG;
extern char *HOST_DENY_IP_OUTPUT;
extern char *HOST_DENY_TCP;
extern char *HOST_DENY_TCP_NOLOG;
extern char *HOST_DENY_TCP_OUTPUT;
extern char *HOST_DENY_UDP;
extern char *HOST_DENY_UDP_NOLOG;
extern char *HOST_DENY_UDP_OUTPUT;
extern char *HOST_OPEN_ICMP;
extern char *HOST_OPEN_IP;
extern char *HOST_OPEN_TCP;
extern char *HOST_OPEN_UDP;
extern char *HOST_REJECT_TCP;
extern char *HOST_REJECT_TCP_NOLOG;
extern char *HOST_REJECT_UDP;
extern char *HOST_REJECT_UDP_NOLOG;
extern char *ICMPV6_SPECIAL_TYPES;
extern char *ICMP_DROP_LOG;
extern char *ICMP_FLOOD_LOG;
extern char *ICMP_OTHER_LOG;
extern char *ICMP_REQUEST_LOG;
extern char *IF_TRUSTS;
extern char *IGMP_LOG;
extern char *INET_DMZ_DENY_IP;
extern char *INET_DMZ_DENY_TCP;
extern char *INET_DMZ_DENY_UDP;
extern char *INET_DMZ_HOST_DENY_IP;
extern char *INET_DMZ_HOST_DENY_TCP;
extern char *INET_DMZ_HOST_DENY_UDP;
extern char *INET_DMZ_HOST_OPEN_IP;
extern char *INET_DMZ_HOST_OPEN_TCP;
extern char *INET_DMZ_HOST_OPEN_UDP;
extern char *INET_DMZ_OPEN_ICMP;
extern char *INET_DMZ_OPEN_IP;
extern char *INET_DMZ_OPEN_TCP;
extern char *INET_DMZ_OPEN_UDP;
extern char *INET_FORWARD_IP;
extern char *INET_FORWARD_TCP;
extern char *INET_FORWARD_UDP;
extern char *INET_OUTPUT_DENY_LOG;
extern char *INTERNAL_NET;
extern char *INTERNAL_NET_ANTISPOOF;
extern char *INT_IF;
extern char *INVALID_ICMP_LOG;
extern char *INVALID_TCP_LOG;
extern char *INVALID_UDP_LOG;
extern char *IPTABLES_ERROR;
extern char *IPV6_DETECTED;
extern char *IPV6_SUPPORT;
extern char *LAN_DENY_IP;
extern char *LAN_DENY_TCP;
extern char *LAN_DENY_UDP;
extern char *LAN_HOST_DENY_IP;
extern char *LAN_HOST_DENY_TCP;
extern char *LAN_HOST_DENY_UDP;
extern char *LAN_HOST_OPEN_IP;
extern char *LAN_HOST_OPEN_TCP;
extern char *LAN_HOST_OPEN_UDP;
extern char *LAN_INET_DENY_IP;
extern char *LAN_INET_DENY_TCP;
extern char *LAN_INET_DENY_UDP;
extern char *LAN_INET_HOST_DENY_IP;
extern char *LAN_INET_HOST_DENY_TCP;
extern char *LAN_INET_HOST_DENY_UDP;
extern char *LAN_INET_HOST_OPEN_IP;
extern char *LAN_INET_HOST_OPEN_TCP;
extern char *LAN_INET_HOST_OPEN_UDP;
extern char *LAN_INET_OPEN_ICMP;
extern char *LAN_INET_OPEN_IP;
extern char *LAN_INET_OPEN_TCP;
extern char *LAN_INET_OPEN_UDP;
extern char *LAN_INPUT_DENY_LOG;
extern char *LAN_OPEN_ICMP;
extern char *LAN_OPEN_IP;
extern char *LAN_OPEN_TCP;
extern char *LAN_OPEN_UDP;
extern char *LAN_OUTPUT_DENY_LOG;
extern char *LINK_LOCAL_DROP_LOG;
extern char *LOCAL_PORT_RANGE;
extern char *LOGLEVEL;
extern char *LOG_HOST_INPUT;
extern char *LOG_HOST_INPUT_IP;
extern char *LOG_HOST_INPUT_TCP;
extern char *LOG_HOST_INPUT_UDP;
extern char *LOG_HOST_OUTPUT;
extern char *LOG_HOST_OUTPUT_IP;
extern char *LOG_HOST_OUTPUT_TCP;
extern char *LOG_HOST_OUTPUT_UDP;
extern char *LOG_INPUT_IP;
extern char *LOG_INPUT_TCP;
extern char *LOG_INPUT_UDP;
extern char *LOG_OUTPUT_IP;
extern char *LOG_OUTPUT_TCP;
extern char *LOG_OUTPUT_UDP;
extern char *LOOSE_FORWARD;
extern char *LOST_CONNECTION_LOG;
extern char *MANGLE_TOS;
extern char *MY_VERSION;
extern char *NAT;
extern char *NAT_FORWARD_IP;
extern char *NAT_FORWARD_TCP;
extern char *NAT_FORWARD_UDP;
extern char *NAT_INTERNAL_NET;
extern char *NAT_LOCAL_REDIRECT;
extern char *NAT_STATIC_IP;
extern char *NMB_BROADCAST_FIX;
extern char *OPEN_ICMP;
extern char *OPEN_ICMPV6;
extern char *OPEN_IP;
extern char *OPEN_TCP;
extern char *OPEN_UDP;
extern char *OTHER_IP_LOG;
extern char *PACKET_TTL;
extern char *PLUGIN_BIN_PATH;
extern char *PLUGIN_CONF_PATH;
extern char *PLUGIN_LOAD_FILE_RESTART;
extern char *POSSIBLE_SCAN_LOG;
extern char *PRIV_TCP_LOG;
extern char *PRIV_UDP_LOG;
extern char *REJECT_TCP;
extern char *REJECT_TCP_NOLOG;
extern char *REJECT_UDP;
extern char *REJECT_UDP_NOLOG;
extern char *RESERVED_NET_LOG;
extern char *SCAN_LOG;
extern char *SEP;
extern char *SEP2;
extern char *SEP3;
extern char *SET_MSS;
extern char *STATIC_IP;
extern char *SYSCTL;
extern char *TRAFFIC_SHAPING;
extern char *TRUSTED_IF;
extern char *TTL_INC;
extern char *UNPRIV_TCP_LOG;
extern char *UNPRIV_UDP_LOG;
#if 1 // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
extern char *DMZ_NAT_IP;
extern char *DMZ_TCP;
extern char *DMZ_UDP;
extern char *PORT_SCAN_DOS_DISABLE;
extern char *TRIGGER_TIMEROUT;
#endif
/**************************************************************************/
/*      DEFINES:                                                          */
/**************************************************************************/

#define WRITE(_fd, _str) write(_fd, _str, strlen(_str))

#define IPT4_REST_FILE "/var/tmp/ipt4_rest_file"
#define IPT6_REST_FILE "/var/tmp/ipt6_rest_file"

/**************************************************************************/
/*      LOCAL DECLARATIONS:                                               */
/**************************************************************************/

/**************************************************************************/
/*      LOCAL VARIABLES:                                                  */
/**************************************************************************/

static char *SYSCTL_ALL = NULL;
static char *IP4TABLES_BATCH_RULES_NAT = NULL;
static char *IP4TABLES_BATCH_RULES_MANGLE = NULL;
static char *IP4TABLES_BATCH_RULES_FILTER = NULL;
static char *FORCE_IP4TABLESBATCH = "0";
static char *IP6TABLES_BATCH_RULES_MANGLE = NULL;
static char *IP6TABLES_BATCH_RULES_FILTER = NULL;
static char *FORCE_IP6TABLESBATCH = "0";

/**************************************************************************/
/*      INTERFACE FUNCTIONS Implementation:                               */
/**************************************************************************/

char *ARNO_IPTABLESBATCH_VERBOSE = "";

/**************************************************************************/
/*! \fn int get_numeric_ip_version(char *arg1)
 **************************************************************************
 *  \brief Determine the IP version of the input IP address
 *  \param[in] IP address
 *  \return 0 - Unknown, 4 - IPv4, 6 - IPv6
 **************************************************************************/
int get_numeric_ip_version(char *arg1)
{
    struct in_addr ip4;
    struct in6_addr ip6;
    char *maybe4;
    char *r;

    if (arg1 == NULL)
    {
        return 0;
    }

    if (strcmp(arg1, "0/0") == 0)
    {
        return 0;
    }

    maybe4 = strdup(arg1);
    maybe4 = strtok_r(maybe4, "/", &r);
    if (inet_pton(AF_INET, maybe4, &ip4) == 1)
    {
        FREE(maybe4);
        return 4;
    }
    FREE(maybe4);

    if (inet_pton(AF_INET6, arg1, &ip6) == 1)
    {
        return 6;
    }

    return 0;
}

/**************************************************************************/
/*! \fn int check_interface(char *in_ifc)
 **************************************************************************
 *  \brief Check existance of an interface
 *  \param[in] Interface name
 *  \return 1 - exists, 0 - does not exist
 **************************************************************************/
int check_interface(char *in_ifc)
{
    char *ifc;
    //char *interfaces=sysout("ip -o link show | cut -d':' -f2");
    char *interfaces=sysout("ifconfig -a | grep \"^[^ ]\" | cut -f1 -d' '", NULL);

    for (ifc = strtok(interfaces, "\n"); ifc != NULL; ifc = strtok(NULL, "\n"))
    {
        if (strstr(ifc, in_ifc) != NULL)
        {
            return 1;
        }
    }

    FREE(interfaces);

    return 0;
}

/**************************************************************************/
/*! \fn int ip4tables_batch(char *arg1)
 **************************************************************************
 *  \brief Add iptables rules in batch using iptables-save and iptables-restore
 *  \param[in]
 *      -   "init" : Initialize BATCH processing
 *      -   "apply" : Apply rules collected since "init"
 *      -   Anything else is considered to be an iptables rule
 *          +   If the rule does not begin with "-t", "filter" table is assumed
 *  \param[in,out] 
 *  \return 0 - OK, 1 - No params, 2 - Missing params
 **************************************************************************/
int ip4tables_batch(char *arg1)
//{
{

char *table = NULL;;
char *new_chain = NULL;;
char *chain_exists = NULL;;
char *ARGS = NULL;;
char *newchaincmd_exists = NULL;;
char *first_param = NULL;;
char *n = NULL;
char *usearg = strdup(arg1);
int len = 0;
int RESULT = 0;
  //local ARGS first_param table new_chain chain_exists newchaincmd_exists
  //local ARGS first_param table new_chain chain_exists newchaincmd_exists

  //# Args must be of the form and called in this order:
  //#   init
  //#   [-t filter|nat|mangle] <anything else>
  //#     filter is the default table
  //#   apply
  //#
  
//  //if [ "$DISABLE_IPTABLES_BATCH" = "1" ]; then
//  if  (  (strcmp(DISABLE_IPTABLES_BATCH,"1")==0)  )
//  {
//    //if [ "$1" = "-A" ]; then
//    if  (  (strcmp(arg1,"-A")==0)  )
//    {
//      //ip4tables "$@"
//      ip4tables("\"@\"");
//    //fi
//    }
//    //return
//    return ;
//  //fi
//  }

  //if [ "$1" = "init" ]; then
  if  (  (strcmp(arg1,"init")==0)  )
  {

    //# Force BATCH for the rest of time
    //FORCE_IP4TABLESBATCH=1
    FORCE_IP4TABLESBATCH="0";
    //# Get initial value
    //IP4TABLES_BATCH_RULES_NAT=`iptables-save -t nat | grep -v COMMIT | grep -v "^#"`
    FREE(IP4TABLES_BATCH_RULES_NAT);
    IP4TABLES_BATCH_RULES_NAT=sysout("iptables-save -t nat | grep -v COMMIT | grep -v \"^#\"", NULL);
    if (IP4TABLES_BATCH_RULES_NAT[strlen(IP4TABLES_BATCH_RULES_NAT) - 1] == '\n')
    {
        IP4TABLES_BATCH_RULES_NAT[strlen(IP4TABLES_BATCH_RULES_NAT) - 1] = '\0';
    }
    //IP4TABLES_BATCH_RULES_MANGLE=`iptables-save -t mangle | grep -v COMMIT | grep -v "^#"`
    FREE(IP4TABLES_BATCH_RULES_MANGLE);
    IP4TABLES_BATCH_RULES_MANGLE=sysout("iptables-save -t mangle | grep -v COMMIT | grep -v \"^#\"", NULL);
    if (IP4TABLES_BATCH_RULES_MANGLE[strlen(IP4TABLES_BATCH_RULES_MANGLE) - 1] == '\n')
    {
        IP4TABLES_BATCH_RULES_MANGLE[strlen(IP4TABLES_BATCH_RULES_MANGLE) - 1] = '\0';
    }
    //IP4TABLES_BATCH_RULES_FILTER=`iptables-save -t filter | grep -v COMMIT | grep -v "^#"`
    FREE(IP4TABLES_BATCH_RULES_FILTER);
    IP4TABLES_BATCH_RULES_FILTER=sysout("iptables-save -t filter | grep -v COMMIT | grep -v \"^#\"", NULL);
    if (IP4TABLES_BATCH_RULES_FILTER[strlen(IP4TABLES_BATCH_RULES_FILTER) - 1] == '\n')
    {
        IP4TABLES_BATCH_RULES_FILTER[strlen(IP4TABLES_BATCH_RULES_FILTER) - 1] = '\0';
    }
  //elif [ "$1" = "apply" ]; then
  }
  else if (  (strcmp(arg1,"apply")==0)  )
  {
      //# Apply
    //# If after init, proceed, otherwise simply skip
    //if [ "$FORCE_IP4TABLESBATCH" = "1" ]; then
    if  (  (strcmp(FORCE_IP4TABLESBATCH,"1")==0)  )
    {
        int fd;

        remove(IPT4_REST_FILE);
        fd = open(IPT4_REST_FILE, O_CREAT | O_WRONLY);

        //# nat
        //echo -e "$IP4TABLES_BATCH_RULES_NAT \nCOMMIT" | iptables-restore
        //printf("%s \nCOMMIT | iptables-restore" "\n", IP4TABLES_BATCH_RULES_NAT);
        WRITE(fd, IP4TABLES_BATCH_RULES_NAT);
        WRITE(fd, " \nCOMMIT\n");
        //if [ "$ARNO_IPTABLESBATCH_VERBOSE" = "FINAL" ]; then 
        if  (  (strcmp(ARNO_IPTABLESBATCH_VERBOSE,"FINAL")==0)  )
        {
            //echo -e "$IP4TABLES_BATCH_RULES_NAT \nCOMMIT" 
            printf("%s \nCOMMIT " "\n", IP4TABLES_BATCH_RULES_NAT);
        //fi
        }
        //# mangle
        //echo -e "$IP4TABLES_BATCH_RULES_MANGLE \nCOMMIT" | iptables-restore
        //printf("%s \nCOMMIT | iptables-restore" "\n", IP4TABLES_BATCH_RULES_MANGLE);
        WRITE(fd, IP4TABLES_BATCH_RULES_MANGLE);
        WRITE(fd, " \nCOMMIT\n");
        //if [ "$ARNO_IPTABLESBATCH_VERBOSE" = "FINAL" ]; then 
        if  (  (strcmp(ARNO_IPTABLESBATCH_VERBOSE,"FINAL")==0)  )
        {
            //echo -e "$IP4TABLES_BATCH_RULES_MANGLE \nCOMMIT" 
            printf("%s \nCOMMIT " "\n", IP4TABLES_BATCH_RULES_MANGLE);
        //fi
        }
        //# filter
        //echo -e "$IP4TABLES_BATCH_RULES_FILTER \nCOMMIT" | iptables-restore
        //printf("%s \nCOMMIT | iptables-restore" "\n", IP4TABLES_BATCH_RULES_FILTER);
        WRITE(fd, IP4TABLES_BATCH_RULES_FILTER);
        WRITE(fd, " \nCOMMIT\n");
        //if [ "$ARNO_IPTABLESBATCH_VERBOSE" = "FINAL" ]; then 
        if  (  (strcmp(ARNO_IPTABLESBATCH_VERBOSE,"FINAL")==0)  )
        {
            //echo -e "$IP4TABLES_BATCH_RULES_FILTER \nCOMMIT" 
            printf("%s \nCOMMIT " "\n", IP4TABLES_BATCH_RULES_FILTER);
        //fi
        }

        close(fd);
        //{struct timeval time;gettimeofday(&time, NULL);printf("Start %s restore- %s", __func__, ctime( &time.tv_sec ));}
        system("iptables-restore < " IPT4_REST_FILE );
        //{struct timeval time;gettimeofday(&time, NULL);printf("End %s restore- %s", __func__, ctime( &time.tv_sec ));}

        //# Reinit everything
        //FORCE_IP4TABLESBATCH=0
        FORCE_IP4TABLESBATCH="0";
        //IP4TABLES_BATCH_RULES_NAT=""
        FREE(IP4TABLES_BATCH_RULES_NAT);
        IP4TABLES_BATCH_RULES_NAT=strdup("");
        //IP4TABLES_BATCH_RULES_MANGLE=""
        FREE(IP4TABLES_BATCH_RULES_MANGLE);
        IP4TABLES_BATCH_RULES_MANGLE=strdup("");
        //IP4TABLES_BATCH_RULES_FILTER=""
        FREE(IP4TABLES_BATCH_RULES_FILTER);
        IP4TABLES_BATCH_RULES_FILTER=strdup("");
    //fi
    }
  //else
  }
  else
  {
    //# Get table, check if 1st param is -t
    //table="filter"
    table="filter";
    //first_param="$1"
    first_param=usearg;
    first_param += strspn(first_param, " ");
    //if [ -n "$first_param" ]; then
    if  (  ((first_param!=NULL)&&(strlen(first_param)!=0))  )
    {
        //# Determine table
        //if [ "$first_param" == "-t" ]; then
        if  (  (strncmp(first_param,"-t ", 3)==0)  )
        {
            //table="$2"
            table=strchr(first_param, ' ');
            table += strspn(table, " ");
            len = strcspn(table, " ");
            table[len] = '\0';
            //# Remove the -t strchr
            //shift 2
//            shift 2
            //first_param="$1"
            first_param = table + len + 1;
            // 1st non-blank
            first_param += strspn(first_param, " ");
        //fi
        }
        //# Determine NEW Chain
        //if [ -n "$first_param" ]; then
        if  (  ((first_param!=NULL)&&(strlen(first_param)!=0))  )
        {
            //if [ "$first_param" == "-N" ]; then
            if  (  (strncmp(first_param,"-N ", 3)==0)  )
            {
                //new_chain="$2"
                // After "-N "
                new_chain=first_param + 3;
                // 1st non-blank
                new_chain += strspn(new_chain, " ");
                len = strcspn(new_chain, " ");
                //# Does this chain already exist?
                //# Look for 
                //# - "existing chain" --> :chain (-|ACCEPT)
                //# - New chain --> -N chain, since all params are quoted, add qotes when searching
                //case "$table" in
                if (strcmp(table, "filter") == 0)
                {
                  //"filter")
                    //chain_exists=`echo -ne "$IP4TABLES_BATCH_RULES_FILTER" | grep "^:$new_chain "`
                    n = stringcatn(":", new_chain, len);
                    chain_exists=strstr(IP4TABLES_BATCH_RULES_FILTER,n);
                    FREE(n);
                    //newchaincmd_exists=`echo -ne "$IP4TABLES_BATCH_RULES_FILTER" | grep "\"-N\" \"$new_chain\""`
                    n = stringcatn("\"-N\" \"", new_chain, len);
                    newchaincmd_exists=strstr(IP4TABLES_BATCH_RULES_FILTER, n);
                    FREE(n);
                      //;;
                      //break;
                }
                else if (strcmp(table, "nat") == 0)
                {
                    //"nat")
                    //"nat")
                    //chain_exists=`echo -ne "$IP4TABLES_BATCH_RULES_NAT" | grep ":$new_chain "`
                    n = stringcatn(":", new_chain, len);
                    chain_exists=strstr(IP4TABLES_BATCH_RULES_NAT,n);
                    FREE(n);
                    //newchaincmd_exists=`echo -ne "$IP4TABLES_BATCH_RULES_NAT" | grep "\"-N\" \"$new_chain\""`
                    n = stringcatn("\"-N\" \"", new_chain, len);
                    newchaincmd_exists=strstr(IP4TABLES_BATCH_RULES_NAT, n);
                    FREE(n);
                    //;;
                    //break;
                }
                else if (strcmp(table, "mangle") == 0)
                {
                    //"mangle")
                    //"mangle")
                    //chain_exists=`echo -ne "$IP4TABLES_BATCH_RULES_MANGLE" | grep ":$new_chain "`
                    n = stringcatn(":", new_chain, len);
                    chain_exists=strstr(IP4TABLES_BATCH_RULES_MANGLE,n);
                    FREE(n);
                    //newchaincmd_exists=`echo -ne "$IP4TABLES_BATCH_RULES_MANGLE" | grep "\"-N\" \"$new_chain\""`
                    n = stringcatn("\"-N\" \"", new_chain, len);
                    newchaincmd_exists=strstr(IP4TABLES_BATCH_RULES_MANGLE, n);
                    FREE(n);
                      //;;
                      //break;
                //esac
                }
                //if [ -n "$chain_exists" -o -n "$newchaincmd_exists" ]; then
                if  (  (((chain_exists!=NULL)&&(strlen(chain_exists)!=0))||((newchaincmd_exists!=NULL)&&(strlen(newchaincmd_exists)!=0))) )
                {
                    //# Chain already exists, skip
                    //return $RESULT
					/* on BCA_HNDROUTER, free error of invalid address */
                    FREE(chain_exists);
                    FREE(newchaincmd_exists);
                    FREE(usearg);
                    return RESULT;
                //fi
                }
            //fi
            }
        //fi
        }
        //# Get all args
        ////while [ -n "$1" ]
        //while [ -n "1" ]
        ////do
        //do();
        //    //# Add space to seperate patams, only between params
        //    //if [ -n "$ARGS" ]; then ARGS="$ARGS "; fi
        //    if  (  ((ARGS!=NULL)&&(strlen(ARGS)!=0))  )
        //    {
        //    //# We could look for a blank (" "), then quote,
        //    //# But it is probably safer to just quote everything.
        //    //ARGS="$ARGS\"$1\""
        //    ARGS="ARGS\"1\"";
        //    //shift
        //    shift();
        ////done
        //}
        ARGS = first_param;

        //if [ -n "$ARGS" ]; then
        if  (  ((ARGS!=NULL)&&(strlen(ARGS)!=0))  )
        {
            //# Save in filter-specific var      
            //case "$table" in
            //switch ("table")
            if (strcmp(table, "filter") == 0)
            {
              //"filter")
              //"filter")
                  //IP4TABLES_BATCH_RULES_FILTER="$IP4TABLES_BATCH_RULES_FILTER \n"$ARGS
                  //IP4TABLES_BATCH_RULES_FILTER="IP4TABLES_BATCH_RULES_FILTER \n"ARGS;
                  n = IP4TABLES_BATCH_RULES_FILTER;
                  IP4TABLES_BATCH_RULES_FILTER=stringcat(IP4TABLES_BATCH_RULES_FILTER, " \n", NULL);
                  FREE(n);
                  n = IP4TABLES_BATCH_RULES_FILTER;
                  IP4TABLES_BATCH_RULES_FILTER=stringcat(IP4TABLES_BATCH_RULES_FILTER, ARGS, NULL);
                  FREE(n);
                  //;;
                  //break;
            }
            if (strcmp(table, "nat") == 0)
            {

              //"nat")
                //"nat")
                  //IP4TABLES_BATCH_RULES_NAT="$IP4TABLES_BATCH_RULES_NAT \n"$ARGS
                  //IP4TABLES_BATCH_RULES_NAT="IP4TABLES_BATCH_RULES_NAT \n"ARGS;
                n = IP4TABLES_BATCH_RULES_NAT;
                IP4TABLES_BATCH_RULES_NAT=stringcat(IP4TABLES_BATCH_RULES_NAT, " \n", NULL);
                FREE(n);
                n = IP4TABLES_BATCH_RULES_NAT;
                IP4TABLES_BATCH_RULES_NAT=stringcat(IP4TABLES_BATCH_RULES_NAT, ARGS, NULL);
                FREE(n);
                  //;;
                  //break;
            }
            if (strcmp(table, "mangle") == 0)
            {
              //"mangle")
                //"mangle")
                  //IP4TABLES_BATCH_RULES_MANGLE="$IP4TABLES_BATCH_RULES_MANGLE \n"$ARGS
                  //IP4TABLES_BATCH_RULES_MANGLE="IP4TABLES_BATCH_RULES_MANGLE \n"ARGS;
                  n = IP4TABLES_BATCH_RULES_MANGLE;
                  IP4TABLES_BATCH_RULES_MANGLE=stringcat(IP4TABLES_BATCH_RULES_MANGLE, " \n", NULL);
                  FREE(n);
                  n = IP4TABLES_BATCH_RULES_MANGLE;
                  IP4TABLES_BATCH_RULES_MANGLE=stringcat(IP4TABLES_BATCH_RULES_MANGLE, ARGS, NULL);
                  FREE(n);
                  //;;
                  //break;
            }
            //esac
            //}
        //else
        }
        else
        {
            //# No params left
            //printf "NO PARAMS (after shift?)" >&2
            fprintf(stderr, "NO PARAMS (after shift?) ");
            //RESULT=2
            RESULT=2;
        //fi
        }
    //else
    }
    else
    {
      //# No params
      //printf "NO PARAMS " >&2
      fprintf(stderr, "NO PARAMS  ");
      //RESULT=1
      FREE(usearg);
      RESULT=1;
    //fi
    }
  //fi
  }

  FREE(usearg);
  //return $RESULT
  return RESULT;

//}
}

/**************************************************************************/
/*! \fn int ip4tables(char *inarg, ...)
 **************************************************************************
 *  \brief Execute an ip4tables command, either directly or via _batch
 *  \param[in...] All args create a single command
 *  \return 0 - Direct, When batch - returns the _batch return value
 **************************************************************************/
int ip4tables(char *inarg, ...)
{
va_list va;
char *arg1;
int len;


    va_start(va, inarg);
    len = vsnprintf(NULL, 0, inarg, va) + 1; // for '\0'
    va_end(va);
    va_start(va, inarg);
    arg1 = malloc(len);
    vsnprintf(arg1, len, inarg, va);
    va_end(va);

    if (strcmp(FORCE_IP4TABLESBATCH, "1") == 0)
    {
        return ip4tables_batch(arg1);
    }
    else
    {
        char *cmd = stringcat("iptables ", arg1, NULL);

        system(cmd);
        FREE(cmd)

        return 0;
    }
}

/**************************************************************************/
/*! \fn int ip6tables_batch(char *arg1)
 **************************************************************************
 *  \brief Add iptables rules in batch using iptables-save and iptables-restore
 *  \param[in]
 *      -   "init" : Initialize BATCH processing
 *      -   "apply" : Apply rules collected since "init"
 *      -   Anything else is considered to be an iptables rule
 *          +   If the rule does not begin with "-t", "filter" table is assumed
 *  \param[in,out] 
 *  \return 0 - OK, 1 - No params, 2 - Missing params
 **************************************************************************/
int ip6tables_batch(char *arg1)
//{
{

char *table = NULL;;
char *new_chain = NULL;;
char *chain_exists = NULL;;
char *ARGS = NULL;;
char *newchaincmd_exists = NULL;;
char *first_param = NULL;;
char *n = NULL;
char *usearg = strdup(arg1);
int len = 0;
int RESULT = 0;
  //local ARGS first_param table new_chain chain_exists newchaincmd_exists
  //local ARGS first_param table new_chain chain_exists newchaincmd_exists

  //# Args must be of the form and called in this order:
  //#   init
  //#   [-t filter|nat|mangle] <anything else>
  //#     filter is the default table
  //#   apply
  //#
  
//  //if [ "$DISABLE_IPTABLES_BATCH" = "1" ]; then
//  if  (  (strcmp(DISABLE_IPTABLES_BATCH,"1")==0)  )
//  {
//    //if [ "$1" = "-A" ]; then
//    if  (  (strcmp(arg1,"-A")==0)  )
//    {
//      //ip6tables "$@"
//      ip6tables("\"@\"");
//    //fi
//    }
//    //return
//    return ;
//  //fi
//  }

  //if [ "$1" = "init" ]; then
  if  (  (strcmp(arg1,"init")==0)  )
  {

    //# Force BATCH for the rest of time
    //FORCE_IP6TABLESBATCH=1
    FORCE_IP6TABLESBATCH="1";
    //# Get initial value
    //IP6TABLES_BATCH_RULES_MANGLE=`ip6tables-save -t mangle | grep -v COMMIT | grep -v "^#"`
    FREE(IP6TABLES_BATCH_RULES_MANGLE);
    IP6TABLES_BATCH_RULES_MANGLE=sysout("ip6tables-save -t mangle | grep -v COMMIT | grep -v \"^#\"", NULL);
    if (IP6TABLES_BATCH_RULES_MANGLE[strlen(IP6TABLES_BATCH_RULES_MANGLE) - 1] == '\n')
    {
        IP6TABLES_BATCH_RULES_MANGLE[strlen(IP6TABLES_BATCH_RULES_MANGLE) - 1] = '\0';
    }
    //IP6TABLES_BATCH_RULES_FILTER=`ip6tables-save -t filter | grep -v COMMIT | grep -v "^#"`
    FREE(IP6TABLES_BATCH_RULES_FILTER);
    IP6TABLES_BATCH_RULES_FILTER=sysout("ip6tables-save -t filter | grep -v COMMIT | grep -v \"^#\"", NULL);
    if (IP6TABLES_BATCH_RULES_FILTER[strlen(IP6TABLES_BATCH_RULES_FILTER) - 1] == '\n')
    {
        IP6TABLES_BATCH_RULES_FILTER[strlen(IP6TABLES_BATCH_RULES_FILTER) - 1] = '\0';
    }
  //elif [ "$1" = "apply" ]; then
  }
  else if (  (strcmp(arg1,"apply")==0)  )
  {
    //# Apply
    //# If after init, proceed, otherwise simply skip
    //if [ "$FORCE_IP6TABLESBATCH" = "1" ]; then
    if  (  (strcmp(FORCE_IP6TABLESBATCH,"1")==0)  )
    {
        int fd;

        remove(IPT6_REST_FILE);
        fd = open(IPT6_REST_FILE, O_CREAT | O_WRONLY);

        //# mangle
        //echo -e "$IP6TABLES_BATCH_RULES_MANGLE \nCOMMIT" | ip6tables-restore
        //printf("%s \nCOMMIT | ip6tables-restore" "\n", IP6TABLES_BATCH_RULES_MANGLE);
        WRITE(fd, IP6TABLES_BATCH_RULES_MANGLE);
        WRITE(fd, " \nCOMMIT\n");
        //if [ "$ARNO_IPTABLESBATCH_VERBOSE" = "FINAL" ]; then 
        if  (  (strcmp(ARNO_IPTABLESBATCH_VERBOSE,"FINAL")==0)  )
        {
            //echo -e "$IP6TABLES_BATCH_RULES_MANGLE \nCOMMIT" 
            printf("%s \nCOMMIT " "\n", IP6TABLES_BATCH_RULES_MANGLE);
        //fi
        }
        //# filter
        //echo -e "$IP6TABLES_BATCH_RULES_FILTER \nCOMMIT" | ip6tables-restore
        //printf("%s \nCOMMIT | ip6tables-restore" "\n", IP6TABLES_BATCH_RULES_FILTER);
        WRITE(fd, IP6TABLES_BATCH_RULES_FILTER);
        WRITE(fd, " \nCOMMIT\n");
        //if [ "$ARNO_IPTABLESBATCH_VERBOSE" = "FINAL" ]; then 
        if  (  (strcmp(ARNO_IPTABLESBATCH_VERBOSE,"FINAL")==0)  )
        {
            //echo -e "$IP6TABLES_BATCH_RULES_FILTER \nCOMMIT" 
            printf("%s \nCOMMIT " "\n", IP6TABLES_BATCH_RULES_FILTER);
        //fi
        }

        close(fd);
        //{struct timeval time;gettimeofday(&time, NULL);printf("Start %s restore- %s", __func__, ctime( &time.tv_sec ));}
        system("ip6tables-restore < " IPT6_REST_FILE );
        //{struct timeval time;gettimeofday(&time, NULL);printf("End %s restore- %s", __func__, ctime( &time.tv_sec ));}

        //# Reinit everything
        //FORCE_IP6TABLESBATCH=0
        FORCE_IP6TABLESBATCH="0";
        //IP6TABLES_BATCH_RULES_MANGLE=""
        FREE(IP6TABLES_BATCH_RULES_MANGLE);
        IP6TABLES_BATCH_RULES_MANGLE=strdup("");;
        //IP6TABLES_BATCH_RULES_FILTER=""
        FREE(IP6TABLES_BATCH_RULES_FILTER);
        IP6TABLES_BATCH_RULES_FILTER=strdup("");;
    //fi
    }
  //else
  }
  else
  {
    //# Get table, check if 1st param is -t
    //table="filter"
    table="filter";
    //first_param="$1"
    first_param=usearg;
    first_param += strspn(first_param, " ");
    //if [ -n "$first_param" ]; then
    if  (  ((first_param!=NULL)&&(strlen(first_param)!=0))  )
    {
        //# Determine table
        //if [ "$first_param" == "-t" ]; then
        if  (  (strncmp(first_param,"-t ", 3)==0)  )
        {
            //table="$2"
            table=strchr(first_param, ' ');
            table += strspn(table, " ");
            len = strcspn(table, " ");
            table[len] = '\0';
            //# Remove the -t strchr
            //shift 2
//            shift 2
            //first_param="$1"
            first_param = table + len + 1;
            // 1st non-blank
            first_param += strspn(first_param, " ");
        //fi
        }
        //# Determine NEW Chain
        //if [ -n "$first_param" ]; then
        if  (  ((first_param!=NULL)&&(strlen(first_param)!=0))  )
        {
            //if [ "$first_param" == "-N" ]; then
            if  (  (strncmp(first_param,"-N ", 3)==0)  )
            {
                //new_chain="$2"
                // After "-N "
                new_chain=first_param + 3;
                // 1st non-blank
                new_chain += strspn(new_chain, " ");
                len = strcspn(new_chain, " ");
                //# Does this chain already exist?
                //# Look for 
                //# - "existing chain" --> :chain (-|ACCEPT)
                //# - New chain --> -N chain, since all params are quoted, add qotes when searching
                //case "$table" in
                if (strcmp(table, "filter") == 0)
                {
                  //"filter")
                    //chain_exists=`echo -ne "$IP6TABLES_BATCH_RULES_FILTER" | grep "^:$new_chain "`
                    n = stringcat(":", new_chain, NULL);
                    chain_exists=strstr(IP6TABLES_BATCH_RULES_FILTER,n);
                    FREE(n);
                    //newchaincmd_exists=`echo -ne "$IP6TABLES_BATCH_RULES_FILTER" | grep "\"-N\" \"$new_chain\""`
                    n = stringcat("\"-N\" \"", new_chain, NULL);
                    newchaincmd_exists=strstr(IP6TABLES_BATCH_RULES_FILTER, n);
                    FREE(n);
                      //;;
                      //break;
                }
                else if (strcmp(table, "mangle") == 0)
                {
                    //"mangle")
                    //"mangle")
                    //chain_exists=`echo -ne "$IP6TABLES_BATCH_RULES_MANGLE" | grep ":$new_chain "`
                    n = stringcat(":", new_chain, NULL);
                    chain_exists=strstr(IP6TABLES_BATCH_RULES_MANGLE,n);
                    FREE(n);
                    //newchaincmd_exists=`echo -ne "$IP6TABLES_BATCH_RULES_MANGLE" | grep "\"-N\" \"$new_chain\""`
                    n = stringcat("\"-N\" \"", new_chain, NULL);
                    newchaincmd_exists=strstr(IP6TABLES_BATCH_RULES_MANGLE, n);
                    FREE(n);
                      //;;
                      //break;
                //esac
                }
                //if [ -n "$chain_exists" -o -n "$newchaincmd_exists" ]; then
                if  (  (((chain_exists!=NULL)&&(strlen(chain_exists)!=0))||((newchaincmd_exists!=NULL)&&(strlen(newchaincmd_exists)!=0))) )
                {
                    //# Chain already exists, skip
                    //return $RESULT
                    FREE(chain_exists);
                    FREE(newchaincmd_exists);
                    FREE(usearg);
                    return RESULT;
                //fi
                }
            //fi
            }
        //fi
        }
        //# Get all args
        ////while [ -n "$1" ]
        //while [ -n "1" ]
        ////do
        //do();
        //    //# Add space to seperate patams, only between params
        //    //if [ -n "$ARGS" ]; then ARGS="$ARGS "; fi
        //    if  (  ((ARGS!=NULL)&&(strlen(ARGS)!=0))  )
        //    {
        //    //# We could look for a blank (" "), then quote,
        //    //# But it is probably safer to just quote everything.
        //    //ARGS="$ARGS\"$1\""
        //    ARGS="ARGS\"1\"";
        //    //shift
        //    shift();
        ////done
        //}
        ARGS = first_param;

        //if [ -n "$ARGS" ]; then
        if  (  ((ARGS!=NULL)&&(strlen(ARGS)!=0))  )
        {
            //# Save in filter-specific var      
            //case "$table" in
            //switch ("table")
            if (strcmp(table, "filter") == 0)
            {
              //"filter")
              //"filter")
                  //IP6TABLES_BATCH_RULES_FILTER="$IP6TABLES_BATCH_RULES_FILTER \n"$ARGS
                  //IP6TABLES_BATCH_RULES_FILTER="IP6TABLES_BATCH_RULES_FILTER \n"ARGS;
                  n = IP6TABLES_BATCH_RULES_FILTER;
                  IP6TABLES_BATCH_RULES_FILTER=stringcat(IP6TABLES_BATCH_RULES_FILTER, " \n", NULL);
                  FREE(n);
                  n = IP6TABLES_BATCH_RULES_FILTER;
                  IP6TABLES_BATCH_RULES_FILTER=stringcat(IP6TABLES_BATCH_RULES_FILTER, ARGS, NULL);
                  FREE(n);
                  //;;
                  //break;
            }
            if (strcmp(table, "mangle") == 0)
            {
              //"mangle")
                //"mangle")
                  //IP6TABLES_BATCH_RULES_MANGLE="$IP6TABLES_BATCH_RULES_MANGLE \n"$ARGS
                  //IP6TABLES_BATCH_RULES_MANGLE="IP6TABLES_BATCH_RULES_MANGLE \n"ARGS;
                  n = IP6TABLES_BATCH_RULES_MANGLE;
                  IP6TABLES_BATCH_RULES_MANGLE=stringcat(IP6TABLES_BATCH_RULES_MANGLE, " \n", NULL);
                  FREE(n);
                  n = IP6TABLES_BATCH_RULES_MANGLE;
                  IP6TABLES_BATCH_RULES_MANGLE=stringcat(IP6TABLES_BATCH_RULES_MANGLE, ARGS, NULL);
                  FREE(n);
                  //;;
                  //break;
            }
            //esac
            //}
        //else
        }
        else
        {
            //# No params left
            //printf "NO PARAMS (after shift?)" >&2
            fprintf(stderr, "NO PARAMS (after shift?) ");
            //RESULT=2
            RESULT=2;
        //fi
        }
    //else
    }
    else
    {
      //# No params
      //printf "NO PARAMS " >&2
      fprintf(stderr, "NO PARAMS  ");
      //RESULT=1
      FREE(usearg);
      RESULT=1;
    //fi
    }
  //fi
  }

  FREE(usearg);
  //return $RESULT
  return RESULT;

//}
}

/**************************************************************************/
/*! \fn int iptables_batch(char *arg1)
 **************************************************************************
 *  \brief Execute ip4tables_batch or both ip4/6tables_batch, according to IPV6_SUPPORT
 *  \param[in] Params for _batch
 *  \return The _batch return value
 **************************************************************************/
int iptables_batch(char *arg1)
{

    int ret;

    if (strcmp(IPV6_SUPPORT, "1") == 0)
    {

        ret = ip4tables_batch(arg1);
        ret = ip6tables_batch(arg1);
    }
    else
    {

        ret = ip4tables_batch(arg1);
    }


    return ret;
}

/**************************************************************************/
/*! \fn int ip6tables(char *inarg, ...)
 **************************************************************************
 *  \brief Execute an ip4tables command, either directly or via _batch
 *  \param[in...] All args create a single command
 *  \return 0 - Direct, When batch - returns the _batch return value
 **************************************************************************/
int ip6tables(char *inarg, ...)
{
va_list va;
char *arg1;
int len;

#if (defined BCA_HNDROUTER) || (defined CONFIG_QCA_SDK) || defined(CONFIG_INTEL_SDK)
    /* not to use ip6tables in BCA_HNDROUTER platform. */
    return 0;
#endif

    va_start(va, inarg);
    len = vsnprintf(NULL, 0, inarg, va) + 1; // for '\0'
    va_end(va);
    va_start(va, inarg);
    arg1 = malloc(len);
    vsnprintf(arg1, len, inarg, va);
    va_end(va);

    if (strcmp(FORCE_IP6TABLESBATCH, "1") == 0)
    {
        return ip6tables_batch(arg1);
    }
    else
    {
        char *cmd = stringcat("ip6tables ", arg1, NULL);

        system(cmd);
        FREE(cmd);

        return 0;
    }
}

/**************************************************************************/
/*! \fn int iptables(char *inarg, ...)
 **************************************************************************
 *  \brief Generic iptables
 *  \param[in] iptables params
 *      -   If src or dst ip is v4 and table == nat ==> ip4tables
 *      -   else If src or dst ip is v6 and proto == icmpv6 ==> ip6tables
 *      -   else if proto == icmp ==> ip4tables + ip6tables with proto icmpv6
 *      -   else ==> ip4tables + ip6tables
 *  \return The ip?tables return value
 **************************************************************************/
int iptables(char *inarg, ...)
//{
{
char *table = "";
char *arg = NULL;;
int dst = 0;
char *r_arg1 = NULL;;
int retval = 0;
int src = 0;
char *proto = "";
char *IFS = NULL;;
int action = '\0';
  //local arg action="" IFS
  //local arg action="" IFS
  //local src=0 dst=0 table="" proto=""
  //local src=0 dst=0 table="" proto=""

va_list va;
char *arg1;
int len;


    va_start(va, inarg);
    len = vsnprintf(NULL, 0, inarg, va) + 1; // for '\0'
    va_end(va);
    va_start(va, inarg);
    arg1 = malloc(len);
    vsnprintf(arg1, len, inarg, va);
    va_end(va);

  //if [ "$IPV6_SUPPORT" = "1" ]; then
  if  (  (strcmp(IPV6_SUPPORT,"1")==0)  )
  {

    //IFS='~'  # expand command-line args using the unique 'tilde' character
    //IFS="~";  //# expand command-line args using the unique 'tilde' character
    IFS=" ";
    //for arg in $*; do
    char *usearg = strdup(arg1);
    action='\0';
    for (arg = strtok_r(usearg, IFS, &r_arg1); arg != NULL; arg = strtok_r(NULL, IFS, &r_arg1))
    {
      //if [ -n "$action" ]; then
      if (action != '\0')
      {
          if (action == 's')
          {
            //s)
              //get_numeric_ip_version "$arg"
              retval = get_numeric_ip_version(arg);
              //src=$?
              src=retval;
              //;;
              //break;
          }
          else if (action == 'd')
          {
            //d)
              //get_numeric_ip_version "$arg"
              retval = get_numeric_ip_version(arg);
              //dst=$?
              dst=retval;
              //;;
              //break;
          }
          else if  (action == 't')
          {
            //t)
              //table="$arg"
              table=arg;
              //;;
              //break;
          }
          else if  (action == 'p')
          {
            //p)
              //proto="$arg"
              proto=arg;
              //;;
              //break;
          }
        //esac
        //}
        //action=""
         action='\0';
      //else
      //}
      }
      else
      {
        //# parse option flags
        //case $arg in
        //switch (arg)
        //{
        //-s|--source)
        if ((strcmp(arg, "-s") == 0) || (strcmp(arg, "--source") == 0))
        {
          //action="s"
            action='s';
          //;;
          //break;
        }
        //-d|--destination)
        if ((strcmp(arg, "-d") == 0) || (strcmp(arg, "--destination") == 0))
        {
          //action="d"
            action='d';
          //;;
          //break;
        }
        //-t|--table)
        if ((strcmp(arg, "-t") == 0) || (strcmp(arg, "--table") == 0))
        {
          //action="t"
          action='t';
          //;;
          //break;
        }
        //-p|--proto)
        if ((strcmp(arg, "-p") == 0) || (strcmp(arg, "--proto") == 0))
        {
        //-p|--proto)
            //action="p"
            action='p';
          //;;
          //break;
        }
        //esac
        //}
      //fi
      }
    //done
    }
    //unset IFS
    IFS = " ";
    
    //#
    //# Call ip4tables and/or ip6tables as appropriate
    //#
    //if [ $src -eq 4 -o $dst -eq 4 -o "$table" = "nat" ]; then
    //if  ( ((atoi(src)==4)||(atoi(dst)==4)) ||  (strcmp(table,"nat")==0)  )
    if  ( (src==4)||(dst==4) ||  (strcmp(table,"nat")==0)  )
    {
      //ip4tables "$@"
      retval = ip4tables(arg1);
    //elif [ $src -eq 6 -o $dst -eq 6 -o "$proto" = "icmpv6" ]; then
    }
    else if ( ((src==6)||(dst==6)) ||  (strcmp(proto,"icmpv6")==0)  )
    {
      //ip6tables "$@"
      retval = ip6tables(arg1);
    //elif [ "$proto" = "icmp" ]; then
    }
    else if (  (strcmp(proto,"icmp")==0)  )
    {
      //ip4tables "$@"
      retval = ip4tables(arg1);
      //# Regenerate ip6tables command-line from the returned 'tilde' separated string
      //IFS='~'; set -- $(ip6tables_icmp_args "$@"); unset IFS
      //IFS='~'; set -- (ip6tables_icmp_args "@"); unset IFS
      // Modify "-p icmp" to "-p icmpv6" and "--icmp-type" to "--icmpv6-type"
      char *usearg = strdup(arg1); 
      int p = 0;
      char *n;
      char *newarg = NULL;
      char *addval;
      for (arg = strtok_r(usearg, IFS, &r_arg1); arg != NULL; arg = strtok_r(NULL, IFS, &r_arg1))
      {
          addval = arg;
          if (strcmp(arg, "--icmp-type") == 0)
          {
              addval = "--icmpv6-type";
          }
          else if ((strcmp(arg, "-p") == 0) || (strcmp(arg, "--proto") == 0))
          {
              p = 1;
          }
          else if (p == 1) 
          {
              if (strcmp(arg, "icmp") == 0)
              {
                  addval = "icmpv6";
              }
              p = 0;
          }
          n = newarg;
          newarg = stringcat(newarg, " ", NULL);
          FREE(n);
          n = newarg;
          newarg = stringcat(newarg, addval, NULL);
          FREE(n);
      }
      //ip6tables "$@"
      retval = ip6tables(newarg);
      FREE(newarg);
      FREE(usearg);
    //else
    }
    else
    {
      //ip4tables "$@"
      retval = ip4tables(arg1);
      //ip6tables "$@"
      retval = ip6tables(arg1);
    //fi
    }
  //else
    FREE(usearg);
  }
  else
  {

    //#
    //# Only call ip4tables since IPv6 filtering is disabled.
    //#
    //ip4tables "$@"
    retval = ip4tables(arg1);
  //fi
  }

  return retval;
//}
}

/**************************************************************************/
/*! \fn int sysctl(char *inarg1, ...)
 **************************************************************************
 *  \brief sysctl binary wrapper
 *  \param[in] params
 *  \return Retval from sysctl
 **************************************************************************/
int sysctl(char *inarg1, ...)
{
    //local result retval IFS=' '
    va_list va;
    char *nextarg;
    char *cmd = NULL;
    char *result = NULL;;
    int retval;

    cmd = strdup(SYSCTL);
    va_start(va, inarg1);
    for (nextarg = inarg1; nextarg != NULL; nextarg = va_arg(va, char *))
    {
        if (cmd[strlen(cmd) - 1] == '=')
        {
            // If nextarg has a space and is not sorrounded , sorround it with ""
            if ((nextarg[0] != '"') && (strchr(nextarg, ' ') != NULL))
            {
                STRINGCAT(cmd, "\"", nextarg, "\"", NULL);
            }
            else
            {
                STRINGCAT(cmd, nextarg, NULL);
            }
        }
        else
        {
            STRINGCAT(cmd, " ", nextarg, NULL);
        }
    }
    va_end(va);
    //result=`trace $SYSCTL "$@" 2>&1`
    //retval=$?
    result = sysout(cmd, &retval);

    //if [ $retval -ne 0 ]; then
    if (retval != 0)
    {
        //# Show any (error) messages in red
        fprintf(stderr,"\033[40m\033[1;31m%s\nERROR (%d): %s\033[0m\n", cmd, retval, result);
        //return $retval
        goto ext;
    //fi
    }
  
    //if [ -n "$result" ]; then
        //echo "${INDENT}$result"
    //fi
  
ext:
    FREE(cmd);
    FREE(result);

    return retval;
}

/**************************************************************************/
/*! \fn int sysctl_multi(char *inarg1, ...)
 **************************************************************************
 *  \brief Execute the 1st variable that exists, from a list of sysctl variables
 *  \param[in] params
 *  \return 0 - success, othe - fail
 **************************************************************************/
int sysctl_multi(char *inarg1, ...)
//{
{
    char *sysctl_commandline = NULL;
    char *variable = NULL;;
    //char *strtok1_FREE = NULL;;
    char *OPTIONS = NULL;
    char *result = NULL;;
    char *VARIABLES = NULL;
    char *r_VARIABLES1 = NULL;;
    char * IFS = " ";
    //char *tr1_FREE = NULL;;
    va_list va;
    char *nextarg;
    int retval;
    char *cmd = NULL;
    char *fld = NULL;
    char *tr1_FREE = NULL;

    //local result retval OPTIONS="" VARIABLES="" IFS=' '
    //local result retval OPTIONS="" VARIABLES="" IFS=' '
    //while [ -n "$1" ]; do
    OPTIONS = strdup("");
    VARIABLES = strdup("");
    va_start(va, inarg1);
    for (nextarg = inarg1; nextarg != NULL; nextarg = va_arg(va, char *))
    {
        //# Combine options and exit on first non-option
        //case "$1" in
        //switch ("1")
        //{
        //-*) OPTIONS="${OPTIONS}${OPTIONS:+ }$1";;
        //-*) OPTIONS="{OPTIONS}{OPTIONS:+ }1";;
        if (nextarg[0] == '-')
        {
            // Option
            STRINGCAT(OPTIONS, " ", nextarg, NULL);
        }
        //*) VARIABLES="${VARIABLES}${VARIABLES:+ }$1";;
        //*) VARIABLES="{VARIABLES}{VARIABLES:+ }1";;
        else
        {
            if (VARIABLES[strlen(VARIABLES) - 1] == '=')
            {
                STRINGCAT(VARIABLES, nextarg, NULL);
            }
            else
            {
                STRINGCAT(VARIABLES, " ", nextarg, NULL);
            }
        }
        //esac
    }
    va_end(va);
    //shift
    //shift();
    //done
    //}
    //IFS=' '
    //IFS=" ";
    //for variable in $VARIABLES; do
    //if (VARIABLES != NULL) strtok1_FREE = strdup(VARIABLES);
    if (VARIABLES != NULL) for (variable = strtok_r(VARIABLES, IFS, &r_VARIABLES1); variable != NULL; variable = strtok_r(NULL, IFS, &r_VARIABLES1))
    {
        FREE(fld);
        FREE(cmd);
        FREE(result);
        //if $SYSCTL "$(echo "$variable" |cut -d'=' -f1)" >/dev/null 2>&1; then
        //if  ( SYSCTL "(echo "variable" |cut -d'=' -f1)" >/dev/null 2>&1 )
        fld = getfield(variable, "=", 1);
        cmd = stringcat(SYSCTL, " ", fld, " >/dev/null 2>&1", NULL);
        result = sysout(cmd, &retval);
        if (retval == 0)
        {
            //local sysctl_commandline="$SYSCTL"
            //local sysctl_commandline="SYSCTL"
            //if [ -n "$OPTIONS" ]; then
            FREE(sysctl_commandline);
            sysctl_commandline = strdup(SYSCTL);
            if (  ((OPTIONS!=NULL)&&(strlen(OPTIONS)!=0))  )
            {
                //sysctl_commandline="$sysctl_commandline $OPTIONS"
                STRINGCAT(sysctl_commandline, " ", OPTIONS, NULL);
                //fi
            }
            //sysctl_commandline="$sysctl_commandline $variable"
            STRINGCAT(sysctl_commandline, " ", variable, NULL);

            //result=`trace $sysctl_commandline 2>&1`
            //retval=$?
            STRINGCAT(sysctl_commandline, " 2>&1", NULL);
            FREE(result);
            result = sysout(sysctl_commandline, &retval);

            //if [ $retval -eq 0 ]; then
            if (retval == 0)
            {
                //if [ -n "$result" ]; then
                if (  ((result!=NULL)&&(strlen(result)!=0))  )
                {
                    //echo "${INDENT}$result"
                    printf("%s%s\n", INDENT, result);
                    //fi
                }
                //return 0
                retval = 0;
                goto ext;
                //else
            }
            else
            {
                //# Show any (error) messages in red
                //printf "\033[40m\033[1;31m${sysctl_commandline}\nERROR ($retval): $result\033[0m\n" >&2
                fprintf(stderr, "\033[40m\033[1;31m%s\nERROR (%d): %s\033[0m\n ", sysctl_commandline, retval, result);
                //fi
            }
            //fi
        }
        //done
    }
    //printf "\033[40m\033[1;31mERROR: Unable to find kernel parameters \"$(echo "$VARIABLES" |tr ' ' '|')\"!\033[0m\n" >&2
    tr1_FREE = tr(VARIABLES, " ", "|");
    fprintf(stderr, "\033[40m\033[1;31mERROR: Unable to find kernel parameters %s!\033[0m\n ", tr1_FREE);
    //return 1
    retval =1 ;
    goto ext;
ext:
    //if (strtok1_FREE != NULL) free(strtok1_FREE);
    if (tr1_FREE != NULL) free(tr1_FREE);
    FREE(sysctl_commandline);
    FREE(OPTIONS);
    FREE(result);
    FREE(VARIABLES);
    FREE(cmd);
    FREE(fld);
    FREE(tr1_FREE);

    return retval;
//}
}

/**************************************************************************/
/*! \fn int sysctl_set_all(char *prefix, char *variable, char *value)
 **************************************************************************
 *  \brief Set a value for sysctl wildcard interfaces (like "net.ipv4.conf.*.rp_filter")
 *  \param[in] prefix (eg. net.ipv4.conf)
 *  \param[in] variable (eg. rp_filter)
 *  \param[in] value to set
 *  \return retval from last sysctl
 **************************************************************************/
int sysctl_set_all(char *prefix, char *variable, char *value)
{
  //local prefix="$1" variable="$2" value="$3"
  //local interface line IFS
    char *cmd = NULL;
    char *sysctl = NULL;
    char *line;
    char *pre = NULL;
    char *var = NULL;
    int prelen;
    int varlen;
    char *r_line;
    char *interfaces = NULL;
    char *interface;
    char *r_interface;
    char *fld = NULL;
    char *cmp = NULL;
    char *res = NULL;
    int retval = 0;
    char *IFS1;
    char *IFS2;

  //if [ -z SYSCTL_ALL ]; then
  if (SYSCTL_ALL == NULL)
  {
      //  SYSCTL_ALL=$($SYSCTL -a 2>/dev/null)
      cmd = stringcat(SYSCTL, " -a 2>/dev/null", NULL);
      SYSCTL_ALL=sysout(cmd, NULL);
      FREE(cmd);
  //fi
  }

  IFS1=EOL;
  //for line in $(echo $SYSCTL_ALL |cut -d' ' -f1 |grep "^${prefix}\..*\.${variable}$"); do
  sysctl = strdup(SYSCTL_ALL);
  pre = stringcat(prefix, ".", NULL);
  prelen = strlen(prefix);
  var = stringcat(".", variable, NULL);
  varlen = strlen(var);
  for (line = strtok_r(sysctl, IFS1, &r_line); line != NULL; line = strtok_r(NULL, IFS1, &r_line))
  {
      FREE(fld);
      fld = getfield(line, " ", 1);
      if ((fld != NULL) && (strncmp(fld, pre, prelen) == 0) && (strncmp(fld + strlen(fld) - varlen, var, varlen) == 0))
      {
          //  IFS=' ,'
          IFS2=" ,";
          //  for interface in $EXT_IF $INT_IF $DMZ_IF; do
          FREE(interfaces);
          interfaces = stringcat(EXT_IF, " ", INT_IF, " ", DMZ_IF, NULL);
          for (interface = strtok_r(interfaces, IFS2, &r_interface); interface != NULL; interface = strtok_r(NULL, IFS2, &r_interface))
          {
              //    if [ "$line" = "$prefix.$interface.$variable" ]; then
              FREE(cmp);
              cmp = stringcat(pre, interface, var, NULL);
              if ((fld != NULL) && (cmp != NULL) && (strcmp(fld, cmp) == 0))
              {
                  //      sysctl -w "$line=$value"
                  FREE(cmd);
                  cmd = stringcat(SYSCTL, " -w ", fld, "=", value, NULL);
                  FREE(res);
                  res = sysout(cmd, &retval);
                  //      break
                  break;
              //    fi
              }
          //  done
          }
      }
  //done
  }

    FREE(cmd);
    FREE(sysctl);
    FREE(pre);
    FREE(var);
    FREE(interfaces);
    FREE(fld);
    FREE(cmp);
    FREE(res);

    return retval;
}

/**************************************************************************/
/*! \fn char * ...
 **************************************************************************
 *  \brief The following get_... and show_... functions do all sort of things
 *          on arno variables. Not completely clear.
 * 
 *      NOT VERY CLEAR AS TO WHAT THEY DO
 * 
 *  \return All return an ALLOCATED STRING that must be "free()"-ed
 **************************************************************************/
//interfaces=`get_ifs "$if_shosts" "$EXT_IF"`
//if_shosts1_FREE = get_ifs(if_shosts, EXT_IF);
char *get_ifs(char *if1, char *if2)
{
    char *a;
    char *result = NULL;

    // if echo "$1" |grep -q -e "$SEP2"; then
    //   result=`echo "$1" |cut -s -d"$SEP2" -f1 |grep -v -e '\.' -e "$ANYHOST" |tr ' ' ','`
    // fi
    a = getfield(if1, SEP2, 1);
    if (a != NULL)
    {
        if ((strstr(a, ".") == NULL) && (strstr(a, ANYHOST) == NULL))
        {
            result = tr(a, " ", ",");
            FREE(a);
        }
    }

    //if [ -n "$result" ]; then
        //echo "$result"
        //return 0
    if (result != NULL)
    {
        return result;
    }
    //else
    else
    {
        //if [ -n "$2" ]; then
            //echo "$2"
        if (if2 != NULL)
        {
            return strdup(if2);
        }
        //else
            //echo "+"
        else
        {
            return strdup("+");
        }
        //fi
        //return 1
    }
    //fi
}

//srcips=`get_ips "$rule"`
//rule6_FREE = get_ips(rule, NULL);
char *get_ips(char *ip1, char *ip2)
{
    char *a;
    char *result = NULL;

    // if echo "$1" |grep -q -e "$SEP2"; then
    //      result=`echo "$1" |cut -s -d"$SEP2" -f1 |grep -e '\.' -e "$ANYHOST" |tr ' ' ','`
    // fi
    a = getfield(ip1, SEP2, 1);
    if (a != NULL)
    {
        if ((strstr(a, ".") != NULL) && (strstr(a, ANYHOST) != NULL))
        {
            result = tr(a, " ", ",");
            FREE(a);
        }
    }

    //if [ -n "$result" ]; then
        //echo "$result"
        //return 0
    if (result != NULL)
    {
        return result;
    }
    //else
    else
    {
        //if [ -n "$2" ]; then
            //echo "$2"
        if (ip2 != NULL)
        {
            return strdup(ip2);
        }
        else
        {
            return strdup(ANYHOST);
        }
        //fi
        //return 1
    }
    //fi
}

//shosts=`get_hosts_ih "$if_shosts" "$ANYHOST"`
//if_shosts2_FREE = get_hosts_ih(if_shosts, ANYHOST);
char *get_hosts_ih(char *ih1, char *ih2)
{
    char *result = NULL;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!")"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
    }

    //if [ -n "$result" ]; then
    //    echo "$result"
    //    return 0;
    if (result != NULL)
    {
        return result;
    }
    //else
    //    echo "$2"
    //    return 1
    else
    {
        if (ih2 != NULL)
        {
            return strdup(ih2);
        }
        else
        {
            return NULL;
        }
    }
    //fi
}

//hosts=`get_hosts_ihp "$rule" "$ANYHOST"`
//rule7_FREE = get_hosts_ihp(rule, ANYHOST);
char *get_hosts_ihp(char *ih1, char *ih2)
{
    char *result = NULL;
    char *n;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!" |cut -s -d"$SEP" -f1)"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
      
        n = result;  
        result = getfield(result, SEP, 1);
        FREE(n);
    }
    //if [ -n "$result" ]; then
    //    echo "$result"
    //    return 0;
    if (result != NULL)
    {
        return result;
    }
    //else
    //    echo "$2"
    //    return 1
    else
    {
        if (ih2 != NULL)
        {
            return strdup(ih2);
        }
        else
        {
            return NULL;
        }
    }
    //fi
}

//ports=`get_ports_ihp "$rule" "$ANYPORT"`
//rule8_FREE = get_ports_ihp(rule, ANYPORT);
char *get_ports_ihp(char *ih1, char *ih2)
{
    char *result = NULL;
    char *n;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!")"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
    }

    //if echo "$result" |grep -q -e "$SEP"; then
    //    echo "$result" |cut -s -d"$SEP" -f2 |tr '-' ':'
    //    return 0
    n = getfield(result, SEP, 2);
    if (n != NULL)
    {
        FREE(result);
        result = tr(n, "-", ":");
        FREE(n);
        return result;
    }
    //elif [ -n "$2" ]; then
    //    # Use default, if specified
    //    echo "$2"
    //    return 1
    else if (ih2 != NULL)
    {
        FREE(result);
        return strdup(ih2);
    }
    //else
    //    # When we have no seperator, assume port(s) only and no host(s)
    //    echo "$result" |tr '-' ':'
    //    return 0
    else
    {
        n = tr(result, "-", ":");
        FREE(result);
        return n;
    }
    //fi
}

//dhosts=`get_hosts_hp "$dhosts_ports"`
//dhosts_ports3_FREE = get_hosts_hp(dhosts_ports, NULL);
char *get_hosts_hp(char *ih1, char *ih2)
{
    char *result = NULL;
    char *n;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!")"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
    }

    //if echo "$result" |grep -q -e "$SEP"; then
    //      echo "$result" |cut -s -d"$SEP" -f1
    //    return 0
    n = getfield(result, SEP, 1);
    if (n != NULL)
    {
        FREE(result);
        result = tr(n, "-", ":");
        FREE(n);
        return result;
    }
    //elif [ -n "$2" ]; then
    //    # Use default, if specified
    //    echo "$2"
    //    return 1
    else if (ih2 != NULL)
    {
        FREE(result);
        return strdup(ih2);
    }
    //else
        //# When we have no seperator, assume host(s) only and no port(s)
        //echo "$result"
        //return 0
    else
    {
        return result;
    }
    //fi
}

//ports=`get_ports_hp "$dhosts_ports" "$ANYPORT"`
//dhosts_ports2_FREE = get_ports_hp(dhosts_ports, ANYPORT);
char *get_ports_hp(char *ih1, char *ih2)
{
    char *result = NULL;
    char *n;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!")"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
    }

    //if echo "$result" |grep -q -e "$SEP"; then
    //    echo "$result" |cut -s -d"$SEP" -f2 |tr '-' ':'
    //    return 0
    n = getfield(result, SEP, 2);
    if (n != NULL)
    {
        FREE(result);
        result = tr(n, "-", ":");
        FREE(n);
        return result;
    }
    //else
    //    echo "$2"
    //    return 1
    //fi
    else
    {
        FREE(result);
        if (ih2 != NULL)
        {
            return strdup(ih2);
        }
        else
        {
            return NULL;
        }
    }
}

//ports=`get_ports_ip "$rule"`
//rule15_FREE = get_ports_ip(rule, NULL);
char *get_ports_ip(char *ih1, char *ih2)
{
    char *result = NULL;
    char *n;

    //local result="$(echo "$1" |sed "s!^.*$SEP2!!")"
    if (ih1 != NULL)
    {
        result = strstr(ih1, SEP2);
        if (result != NULL)
        {
            result = strdup(result + strlen(SEP2));
        }
        else
        {
            result = strdup(ih1);
        }
    }

    //if [ -n "$result" ]; then
    //    echo "$result" |tr '-' ':'
    //    return 0
    if ((result != NULL) && (strlen(result) > 0))
    {
        n = tr(result, "-", ":");
        FREE(result);
        return n;
    }
    //else
    //    echo "$2"
    //    return 1
    //fi
    else
    {
        FREE(result);
        if (ih2 != NULL)
        {
            return strdup(ih2);
        }
        else
        {
            return NULL;
        }
    }
}

//for dhost in `ip_range "$dhosts"`; do
//dhosts4_FREE = ip_range(dhosts, NULL);
char *ip_range(char *arg1, char *arg2)
{
    char *IFS=" ";
    int FIRST;
    char *usearg = strdup(arg1);
    char *item = NULL;;
    char *r_arg = NULL;;
    char *p;
    int start;
    int stop;
    char *host_base;
    int len;
    char *result = NULL;
    int i;
  
    if (arg1 == NULL)
    {
        return NULL;
    }

    //# Return the args if there is no '-' for improved execution speed
    //case "$@" in
    //  *-*) ;;
    //    *) echo "$@"; return;;
    //esac
    if (strchr(arg1, '-') == NULL)
    {
        return usearg;
    }

    FIRST=1;

    IFS=",";
    //# Get variable from commandline
    //for item in $*; do
        //# Check whether an IP range was specified (only works like w.x.y.z1-z2!):
    for (item = strtok_r(usearg, IFS, &r_arg); item != NULL; item = strtok_r(NULL, IFS, &r_arg))
    {
        //start="$(echo "$item" |cut -s -d'-' -f1 |awk -F'.' '{ print $NF }' |grep -e '[0-9]')"
        p = getfield(item, "-", 1);
        /* Find last '.' */
        if (p != NULL)
        {
            start = atoi(strrchr(p, '.'));
            FREE(p);
        }
        else
        {
            start = -1;
        }
        //host_base="$(echo "$item" |cut -s -d'-' -f1 |awk -F'.' '{ for (i=1; i<NF; i++) printf ("%s.",$i) }')"
        p = getfield(item, "-", 1);
        if (p != NULL)
        {
            len = strrchr(p, '.') - p + 1 + 1; /* Include the . and 1 more for \0 */
            host_base = strndup(p, len);
            host_base[len] = '\0';
            FREE(p);
        }
        else
        {
            if (FIRST == 1)
            {
                p = result;
                result = stringcat(result, ",", NULL);
                FREE(p);
                FIRST = 0;
            }
            p = result;
            result = stringcat(result, item, NULL);
            FREE(p);
            continue;
        }
        //stop="$(echo "$item" |cut -s -d'-' -f2 |grep -e '[0-9]')"
        p = getfield(item, "-", 2);
        /* Find last '.' */
        if (p != NULL)
        {
            stop = atoi(strrchr(p, '.'));
            FREE(p);
        }
        else
        {
            stop = -1;
        }

        //if [ -n "$stop" -a -n "$start" ]; then
        //    IFS=' '
        //    for x in `seq -s' ' $start $stop`; do
        //        if [ $FIRST -eq 1 ]; then
        //          FIRST=0
        //        else
        //          printf ","
        //        fi
        //        printf "$host_base$x"
        //    done
        if ((start > 0) && (stop > 0))
        {
            for (i = start; i <= stop; i++)
            {
                char ip4[15+1+1]; /* 255.255.255.255,\0 */
                sprintf(ip4, "%s%d%s", host_base, i, FIRST == 1 ? "" : ",");
                FIRST = 0;
                p = result;
                result = stringcat(result, ip4, NULL);
                FREE(p);
            }
        }
        //else
        //    if [ $FIRST -eq 1 ]; then
        //    FIRST=0
        //    else
        //    printf ","
        //    fi
        //    printf "$item"
        //fi
        else
        {
            if (FIRST == 1)
            {
                p = result;
                result = stringcat(result, ",", NULL);
                FREE(p);
                FIRST = 0;
            }
            p = result;
            result = stringcat(result, item, NULL);
            FREE(p);
        }
    //done
    }

    FREE(usearg);
    return result;
}


//echo " $(show_if_ip "$interfaces" "$destips")Allowing TCP port(s): $ports"
//show_if_ip7_FREE = show_if_ip(interfaces, destips);
char *show_if_ip(char *if1, char *if2)
{
    //# Only show interfaces if not empty:
    //if [ -n "$1" -a "$1" != "+" ]; then
    //    printf "($1) "
    //fi
    if ((if1 != NULL) && (strcmp(if1, "+") != 0))
    {
        return strdup(if1);
    }
    //
    //# Only show destination IPs if not empty:
    //if [ -n "$2" -a "$2" != "$ANYHOST" ]; then
    //    printf "($2) "
    //fi
    if ((if2 != NULL) && (strcmp(if2, ANYHOST) != 0))
    {
        return strdup(if2);
    }

    return NULL;
}

//echo "$(show_if_ip "$interfaces" "$destips")Forwarding(NAT) TCP port(s) $(show_hosts_ports "$shosts" "$sports") to $(echo "$dhost_dport" |tr "$SEP-" '::')"
//trsep1_FREE= stringcat(SEP, "-"); tr1_FREE = tr(dhost_dport, trsep1_FREE, "::");
//show_hosts_ports1_FREE = show_hosts_ports(shosts, sports);
char *show_hosts_ports(char *p1, char *p2)
{
    char *p;
    char *pp;

    //# Only show interfaces if not empty:
    //if [ -n "$1" ]; then
    //  printf "$1:$2"
    //else
    //  printf "$2"
    //fi
    if (p1 != NULL)
    {
        p = stringcat(p1, ":", NULL);
        pp = stringcat(p, p2, NULL);
        FREE(p);
        return pp;
    }
    else
    {
        if (p2 != NULL)
        {
            return strdup(p2);
        }
        else
        {
            return NULL;
        }
    }
}

/**************************************************************************/
/*! \fn void plugins_start(void)
 **************************************************************************
 *  \brief Simply execute the script
 *  \return 
 **************************************************************************/
void plugins_start(void)
{
    char *res;
    char *cmd = 
  "cp -f /dev/null \"$PLUGIN_LOAD_FILE\"" "\n"
  "printf \"Checking for (user) plugins in $PLUGIN_BIN_PATH...\"" "\n"
  "if [ -n \"$(find \"$PLUGIN_BIN_PATH/\" -maxdepth 1 -name \"*.plugin\" 2>/dev/null)\" ]; then" "\n"
    "echo \"\"" "\n"
    "plugin_count=0" "\n"
    "unset IFS" "\n"
    "for plugin in \"$PLUGIN_BIN_PATH\"/*.plugin; do" "\n"
      "PLUGIN_CMD=start" "\n"
      "if [ -e \"$PLUGIN_LOAD_FILE_RESTART\" ]; then" "\n"
        "IFS=$EOL" "\n"
        "for plugin_restart in `cat \"$PLUGIN_LOAD_FILE_RESTART\"`; do" "\n"
          "if [ \"$plugin_restart\" = \"$plugin\" ]; then" "\n"
            "if grep -q \"^plugin_restart\\(\\)\" \"$plugin\"; then" "\n"
              "PLUGIN_CMD=restart" "\n"
            "fi" "\n"
            "break" "\n"
          "fi" "\n"
        "done" "\n"
      "fi" "\n"
      "ENABLED=0" "\n"
      "INDENT=' '" "\n"
      "unset IFS" "\n"
      ". \"$plugin\"" "\n"
      "if [ \"$ENABLED\" = \"1\" ]; then" "\n"
        "echo \"$plugin\" >> \"$PLUGIN_LOAD_FILE\"" "\n"
        "plugin_count=$(($plugin_count + 1))" "\n"
      "fi" "\n"
    "done" "\n"
    "rm -f \"$PLUGIN_LOAD_FILE_RESTART\"" "\n"
    "echo \" Loaded $plugin_count plugin(s)...\"" "\n"
  "else" "\n"
    "echo \"None found\"" "\n"
  "fi" "\n";

    res = sysout(cmd, NULL);
    FREE(res);

}

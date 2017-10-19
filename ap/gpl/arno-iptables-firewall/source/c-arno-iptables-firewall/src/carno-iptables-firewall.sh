#**************************************************************
#* Automatically generated from arno-iptables-firewall_2.0.0a 
#* Mon Feb 25 13:57:47 IST 2013
#* License - same as original
#**************************************************************
export ENV_FILE=/usr/local/share/arno-iptables-firewall/cenvironment.sh

#!/bin/sh

MY_VERSION="2.0.0a"

# Location of the main configuration file for the firewall
##########################################################
#CONFIG_FILE=/etc/arno-iptables-firewall/firewall.conf
CONFIG_FILE=/tmp/firewall.conf
# ------------------------------------------------------------------------------
#                           -= Arno's iptables firewall =-
#               Single- & multi-homed firewall script with DSL/ADSL support
#
#                           ~ In memory of my dear father ~
#
# (C) Copyright 2001-2010 by Arno van Amersfoort
# Co-authors            : Lonnie Abelbeck & Philip Prindeville
# Homepage              : http://rocky.eld.leidenuniv.nl/
# Freshmeat homepage    : http://freshmeat.net/projects/iptables-firewall/?topic_id=151
# Email                 : a r n o v a AT r o c k y DOT e l d DOT l e i d e n u n i v DOT n l
#                         (note: you must remove all spaces and substitute the @ and the .
#                         at the proper locations!)
# ------------------------------------------------------------------------------
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
# ------------------------------------------------------------------------------
#
# Includes Intel Corporation's changes/modifications dated: 
#   13-Apr-2011: Corrected icmp-type, from icmp-request --> echo-request
#   22-Aug-2011: Force *_batch processing 
#   25-Feb-2013: Generate to a C file
#
# Changed/modified portions - Copyright ?2013, Intel Corporation.
#
# ------------------------------------------------------------------------------

printf "\033[40m\033[1;32mArno's Iptables Firewall Script v$MY_VERSION\033[0m\n"
echo "-------------------------------------------------------------------------------"

# Check if the main config file exists and if so load it
########################################################
if [ -e "$CONFIG_FILE" ]; then
  # Make all shell exported, so they can be used by an executable as env variables
  set -a
  . "$CONFIG_FILE"
  # Auto export OFF
  set +a
else
  printf "\033[40m\033[1;31mERROR: Could not read configuration file $CONFIG_FILE!\033[0m\n" >&2
  printf "\033[40m\033[1;31m       Please, check the file's location and (root) rights.\033[0m\n" >&2
  exit 2
fi

# Check if the environment file exists and if so, load it
#########################################################
if [ -z "$ENV_FILE" ]; then
  if [ -f /usr/local/share/arno-iptables-firewall/environment ]; then
    ENV_FILE="/usr/local/share/arno-iptables-firewall/environment"
  else
    if [ -f /usr/share/arno-iptables-firewall/environment ]; then
      ENV_FILE="/usr/share/arno-iptables-firewall/environment"
    else
      printf "\033[40m\033[1;31mERROR: The environment file (ENV_FILE) has not been specified\033[0m\n" >&2
      printf "\033[40m\033[1;31m       in the configuration file. Try upgrading your config-file!\033[0m\n" >&2
      exit 2
    fi
  fi
fi

if [ -e "$ENV_FILE" ]; then
  # Make all shell exported, so they can be used by an executable as env variables
  set -a
  . "$ENV_FILE"
  # Auto export OFF
  set +a
else
  printf "\033[40m\033[1;31mERROR: Could not read environment file \"$ENV_FILE\"!\033[0m\n" >&2
  printf "\033[40m\033[1;31m       Please, check the file's location and (root) rights.\033[0m\n" >&2
  exit 2
fi


sanity_check()
{
  # root check
  if [ "$(id -u)" != "0" ]; then
    printf "\033[40m\033[1;31mERROR: Root check FAILED (you MUST be root to use this script)! Quitting...\033[0m\n" >&2
    exit 1
  fi

  # Check whether the required binaries exist and are executable
  ##############################################################
  check_command_error iptables
  if [ "$IPV6_DETECTED" = "1" ]; then
    check_command_error ip6tables
  fi
  check_command_error awk
  check_command_error tr
  check_command_error ip
  check_command_error cut
  check_command_error uname
  check_command_error sed
  check_command_error cat
  check_command_error date
  check_command_error modprobe
  check_command_error sysctl
  check_command_error head
  check_command_error tail
  check_command_error wc
  check_command_error logger
  
  if [ "$RESOLV_IPS" = "1" ]; then
    check_command_error dig nslookup
  fi
}




load_modules()
{
  unset IFS
  # Set indent for functions
  INDENT=' '

  echo "Checking/probing Iptables modules:"
  
  # Required; all IPv4 modules depend on this one
  modprobe ip_tables
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe ip6_tables
  fi

  # Allows connection tracking state match, which allows you to
  # write rules matching the state of a connection
  modprobe_multi nf_conntrack ip_conntrack
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe nf_conntrack_ipv6
  fi

  # Permits active FTP; requires ip_conntrack
  modprobe_multi nf_conntrack_ftp ip_conntrack_ftp
  
  # Allows tracking for various protocols, placing entries in the conntrack table etc.
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe_multi xt_conntrack "ipt_conntrack,ip6t_conntrack"
  else
    modprobe_multi xt_conntrack ipt_conntrack
  fi
  
  # Allows log limits
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe_multi xt_limit "ipt_limit,ip6t_limit"
  else
    modprobe_multi xt_limit ipt_limit
  fi
  
  # Permits packet state checking (SYN, SYN-ACK, ACK, and so on).
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe_multi xt_state "ipt_state,ip6t_state"
  else
    modprobe_multi xt_state ipt_state
  fi
  
  # Allows packet specifications on multiple ports
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe_multi xt_multiport "ipt_multiport,ip6t_multiport"
  else
    modprobe_multi xt_multiport ipt_multiport
  fi
  
  # Implements the filter table:
  modprobe iptable_filter
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe ip6table_filter
  fi
  
  # Implements the mangle table
  modprobe iptable_mangle
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe ip6table_mangle
  fi

  # Implements the REJECT target:
  modprobe ipt_REJECT
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe ip6t_REJECT
  fi
  
  # Implements the LOG target:
  modprobe ipt_LOG
  if [ "$IPV6_SUPPORT" = "1" ]; then
    modprobe ip6t_LOG
  fi
  
  if [ "$SET_MSS" != "0" ]; then
    # Load the TCPMSS target:
    if [ "$IPV6_SUPPORT" = "1" ]; then
      modprobe_multi xt_TCPMSS "ipt_TCPMSS,ip6t_TCPMSS"
    else
      modprobe_multi xt_TCPMSS ipt_TCPMSS
    fi
  fi
  
  if [ "$MANGLE_TOS" != "0" ]; then
    # Load the TOS target:
    if [ "$IPV6_SUPPORT" = "1" ]; then
      modprobe_multi xt_DSCP "ipt_DSCP,ip6t_DSCP" "ipt_TOS,ip6t_TOS"
    else
      modprobe_multi xt_DSCP ipt_DSCP ipt_TOS
    fi
  fi

  if [ "$PACKET_TTL" = "1" -o "$TTL_INC" = "1" ]; then
    # Load the TTL target:
    modprobe ipt_TTL
  fi

  # (Currently) unused modules:
  #    modprobe ipt_addrtype            # Allows matching src/dst address type (BROKEN!)
  #    modprobe ipt_pkttype             # Permits checking for packet type (BROADCAST, MULTICAST etc.) (BROKEN!)
  #    modprobe ip_queue                # Allows queuing packets to user space
  #    modprobe ipt_owner               # Permits user/group checking on OUTPUT packets
  #    modprobe ipt_mark                # Allows use of mark match
  #    modprobe ip_conntrack_egg

  if [ "$USE_IRC" = "1" ]; then
    #      echo "Enabling IRC DCC module support..."
    modprobe_multi nf_conntrack_irc ip_conntrack_irc        #ports=6661,6662,6663,6664,6665,6666,6667,6668,6669,7000,7001

    if [ "$NAT" = "1" ]; then
      modprobe_multi nf_nat_irc ip_nat_irc            #ports=6661,6662,6663,6664,6665,6666,6667,6668,6669,7000,7001
    fi
  fi

  if [ "$NAT" = "1" ]; then
    modprobe_multi nf_nat_ftp ip_nat_ftp             # Permits active FTP via nat; requires ip_conntrack, iptables_nat
  fi
# // Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
# if 0, Teidor , 2012/11/13, fix bug(id:4615), DMZ can not be configured. 
  # if [ "$NAT" = "1" -o -n "$NAT_FORWARD_TCP" -o -n "$NAT_FORWARD_UDP" -o -n "$NAT_FORWARD_IP" ]; then
#else
  if [ "$NAT" = "1" -o -n "$NAT_FORWARD_TCP" -o -n "$NAT_FORWARD_UDP" -o -n "$NAT_FORWARD_IP" -o -n "$DMZ_NAT_IP" ]; then
#endif
    # Implements the NAT table:
    modprobe iptable_nat

    if [ -z "$NAT_STATIC_IP" ]; then
      # Load the MASQUERADE target:
      modprobe ipt_MASQUERADE
    fi
  fi

  echo " Module check done..."
}








# Check if the base chains are appropriate for the IPV6_SUPPORT setting
#######################################################################
check_for_base_chains()
{
  local ipv4_rtn ipv6_rtn

  iptables -nL BASE_INPUT_CHAIN >/dev/null 2>&1
  ipv4_rtn=$?
  
  if [ "$IPV6_DETECTED" = "1" ]; then
    ip6tables -nL BASE_INPUT_CHAIN >/dev/null 2>&1
    ipv6_rtn=$?
  else
    # No IPv6 available, therefore no ip6tables call
    # Set a return error result of 1 to specify no IPv6 BASE_INPUT_CHAIN
    ipv6_rtn=1
  fi
  
  if [ "$IPV6_SUPPORT" = "1" ]; then
    if [ $ipv4_rtn -eq 0 -a $ipv6_rtn -eq 0 ]; then
      echo "yes"
    elif [ $ipv4_rtn -eq 0 ]; then
      echo "other"
    else
      echo "no"
    fi
  else
    if [ $ipv4_rtn -eq 0 -a $ipv6_rtn -eq 0 ]; then
      echo "other"
    elif [ $ipv4_rtn -eq 0 ]; then
      echo "yes"
    else
      echo "no"
    fi
  fi
}












































plugins_start()
{
  # Truncate/create file
  cp -f /dev/null "$PLUGIN_LOAD_FILE"

  printf "Checking for (user) plugins in $PLUGIN_BIN_PATH..."

  # Check for plugins in our plugins binary path:
  if [ -n "$(find "$PLUGIN_BIN_PATH/" -maxdepth 1 -name "*.plugin" 2>/dev/null)" ]; then
    echo ""
    plugin_count=0
    
    unset IFS
    for plugin in "$PLUGIN_BIN_PATH"/*.plugin; do
      PLUGIN_CMD=start
      if [ -e "$PLUGIN_LOAD_FILE_RESTART" ]; then
        IFS=$EOL
        for plugin_restart in `cat "$PLUGIN_LOAD_FILE_RESTART"`; do
          if [ "$plugin_restart" = "$plugin" ]; then
            if grep -q "^plugin_restart\(\)" "$plugin"; then
              PLUGIN_CMD=restart
            fi
            break
          fi
        done
      fi
      
      # Preset ENABLED=0 to make sure the plugin only
      # gets loaded if the config has an explicit ENABLED=1:
      ENABLED=0

      # Set indent
      INDENT=' '
   
      # Explicit unset IFS, just in case
      unset IFS
     
      # Source the plugin:
      . "$plugin"

      # By checking the ENABLED variable, we know whether the plugin
      # was actually loaded. If so increase the plugin count:
      if [ "$ENABLED" = "1" ]; then
        echo "$plugin" >> "$PLUGIN_LOAD_FILE"
        plugin_count=$(($plugin_count + 1))
      fi
    done
    rm -f "$PLUGIN_LOAD_FILE_RESTART"
    echo " Loaded $plugin_count plugin(s)..."
  else
    echo "None found"
  fi
}


plugins_stop()
{
  local restart="$1"
  
  # Remove any stale plugin restart file
  rm -f "$PLUGIN_LOAD_FILE_RESTART"
  
  if [ -e "$PLUGIN_LOAD_FILE" ]; then
    echo "Stopping (user) plugins..."

    IFS=$EOL
    for plugin in `cat "$PLUGIN_LOAD_FILE"`; do
      plugin_name="$(basename "$plugin" |sed 's/^[0-9]*//')"
      
      if [ -e "$plugin" ]; then
        plugin_file="$plugin"
      else
        # If we can't find it, ignore the priority number in front of the plugin-filename
        plugin_file="$(find "$PLUGIN_BIN_PATH/" -maxdepth 1 -name "*.plugin" |grep "[0-9]*$plugin_name$" |head -n1)"
      fi
      
      if [ -e "$plugin_file" ]; then
        # Only issue the stop command for plugins that support it:
        if grep -q "^plugin_stop\(\)" "$plugin_file"; then
          # Preset ENABLED=0 to make sure the plugin only
          # gets loaded if the config has an explicit ENABLED=1:
          ENABLED=0
          
          # Set indent
          INDENT=' '

          PLUGIN_CMD=stop
          if [ "$restart" = "restart" ] && grep -q "^plugin_restart\(\)" "$plugin_file"; then
            echo "$plugin" >> "$PLUGIN_LOAD_FILE_RESTART"
            PLUGIN_CMD=stop-restart
          fi

          # Explicit unset IFS, just in case
          unset IFS
    
          # Source the plugin:
          . "$plugin_file"
        fi
      else
        printf "\033[40m\033[1;31mERROR: Could not stop plugin \"$plugin_name\" as it does no exist!\033[0m\n" >&2 
      fi
    done
    rm -f "$PLUGIN_LOAD_FILE"
  fi
}


plugins_status()
{
  # Load/insert user plugins
  if [ -e "$PLUGIN_LOAD_FILE" ]; then
    printf "\nShowing status of (user) plugins:\n"
    echo "---------------------------------"

    IFS=$EOL
    for plugin in `cat "$PLUGIN_LOAD_FILE"`; do
      # Only issue the status command for plugins that support the PLUGIN_CMD-variable:
      if grep -q "^plugin_status\(\)" "$plugin"; then
        # Preset ENABLED=0 to make sure the plugin only
        # gets loaded if the config has an explicit ENABLED=1:
        ENABLED=0
        
        # Set indent
        INDENT=' '

        PLUGIN_CMD=status
        
        # Source the plugin:
        printf "=>"
        . "$plugin"
        echo ""
      fi
    done
  fi
}














show_status()
{
  # Check if the user gave any parameters
  if [ -z "$1" ]; then
    iptables -xnvL

    if [ "$NAT" = "1" ]; then
      iptables -t nat -xnvL
    fi

    if [ "$MANGLE_TOS" = "1" ]; then
      iptables -t mangle -nvL
    fi

    # Show plugin status
    plugins_status;
  else
    #iptables -nvL $2 $3 $4 $5
    iptables -xnvL $@
  fi
}














show_help()
{
  echo "Usage: `basename $0` { start | stop | restart | force-reload | status }" >&2
  echo "start                       = Start firewall" >&2
  echo "stop                        = Stop firewall" >&2
  echo "stop-block                  = Stop firewall & block all internet packets" >&2
  echo "restart                     = Restart firewall" >&2
  echo "force-reload                = Reload blocked hosts (blackhole) file" >&2
  echo "check-conf                  = Check configuration file (only)" >&2
  echo "status [-t {table}] [chain] = View firewall ruleset ([chain] & [-t {table}] are optional)" >&2
}


main_stop()
{
  plugins_stop;
  if [ "$1" = "block" ]; then
    stop_block_firewall;
  else
    stop_firewall;
  fi
}


main_start()
{
  load_modules;
  setup_misc;
#  setup_kernel_settings;
  main_start_c;
}



main_restart()
{
  plugins_stop restart;
  load_modules;
#  setup_misc;
  setup_kernel_settings;
  main_restart_c;
}


# int main (char *argv)
#######################

# Check commandline supplied argument:
case "$1" in
  'start' )             sanity_check;
                        show_start;
                        config_check;
                        # Check whether we are actually stopped
                        case $(check_for_base_chains) in
                          no)    main_start;;
                          yes)   main_restart;;
                          other) main_stop; main_start;;
                        esac
                        show_applied;;
  'restart' )           sanity_check;
                        show_restart;
                        config_check;
                        # Check whether we are actually running
                        case $(check_for_base_chains) in
                          no)    main_start;;
                          yes)   main_restart;;
                          other) main_stop; main_start;;
                        esac
                        show_applied;;
  'force-reload' )      sanity_check;
                        config_check;
                        setup_hostblock_chain;
                        show_applied;;
  'stop' )              sanity_check;
                        show_stop;
                        main_stop;
                        show_disabled;;
  'stop-block' )        sanity_check;
                        show_stop;
                        main_stop block;
                        show_stop_blocked;;
  'status' )            shift;
                        show_status $@;;
  'check-conf' )        config_check;;
  * )                   printf "\033[40m\033[1;31mERROR: Bad or missing parameter(s)\033[0m\n" >&2;
                        show_help;;
esac

#//Mos 2014/08/28 implement usb service filrewall rules
#// move to arno-interface.c
#// Foxconn Mos 2013/05/13: Porting from arno-iptables-firewall-2.0.0a
# foxconn add satrt, for readyshare wan ftp access, wait all iptable fininsh, jonathan 2013/1/23
#isWnaFtp=`nvram get Usb.RemoteFtpEnabled`
#AtomIp=`nvram get DhcpS.dhcp_resrv_ip`
#if [ $isWnaFtp == "true" ]; then
#Port=`nvram get Usb.RemoteFtpPort`
#echo "`/fss/gw/sbin/iptables -A PREROUTING -t nat -i erouter0 -p tcp --dport $Port -j DNAT --to-destination $AtomIp:21`" >> /var/tmp/wnnftp_debug.log
#echo "`/fss/gw/sbin/iptables -I EXT_FORWARD_IN_CHAIN 1 -p tcp --dport 21 -d $AtomIp -i erouter0 -j ACCEPT`" >> /var/tmp/wnnftp_debug.log2
#echo "`rmmod nf_nat_ftp`" >> /var/tmp/wnnftp_debug.log3
#echo "`rmmod nf_conntrack_ftp`" >> /var/tmp/wnnftp_debug.log4
#echo "`modprobe nf_conntrack_ftp ports=21,$Port`" >> /var/tmp/wnnftp_debug.log5
#echo "`modprobe nf_nat_ftp`" >> /var/tmp/wnnftpdebug.log6
#fi

#if [ "`nvram get Usb.RemoteHttpEnabled`" == "true" ]; then
#Port=`nvram get Usb.RemoteHttpPort`
#echo "`/fss/gw/sbin/iptables -A PREROUTING -t nat -i erouter0 -p tcp --dport $Port -j DNAT --to-destination $AtomIp:443`" >> /var/tmp/wanhttps_debug.log
#echo "`/fss/gw/sbin/iptables -I EXT_FORWARD_IN_CHAIN 1 -p tcp --dport 443 -d $AtomIp -i erouter0 -j ACCEPT`" >> /var/tmp/wanhttps_debug.log2
#fi

exit $IPTABLES_ERROR


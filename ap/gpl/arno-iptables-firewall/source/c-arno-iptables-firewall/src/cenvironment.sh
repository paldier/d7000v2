#**************************************************************
#* Automatically generated from arno-iptables-firewall_2.0.0a 
#* Mon Feb 25 13:57:47 IST 2013
#* License - same as original
#**************************************************************
export ENV_FILE=/usr/local/share/arno-iptables-firewall/cenvironment.sh


#!/bin/sh
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
#   22-Aug-2011: Provide a means to force *_batch processing
#                Provide batch processing for filter, nat & mangle tables
#   3-Jan-2012:  set proc value only to defined interfaces
#   4-Feb-2013:  Call "sysctl -a" only once, to save time
#   25-Feb-2013: Generate to a C file
#
# Changed/modified portions - Copyright © 2013, Intel Corporation.
#
# ------------------------------------------------------------------------------

# NOTE: When used in combination with firewall.conf. Load firewall.conf first before calling us!

# Some predefined variables/macros:
IPTABLES_ERROR=0
ANYHOST="0/0"
ANYPORT="0:65535"
SEP="~"
SEP2="#"
SEP3="|"
INDENT=""
TAB="$(printf '\t')"
EOL='
'


################################# Functions ####################################

trace()
{
  if [ -n "$TRACEFILE" ]; then
   ((PS4='' ; set -x ; : "$@" >/dev/null) 2>&1 ) | sed 's/^: //' >> $TRACEFILE
  else
    "$@"
  fi
}


# Find command path with '/hint/path/command' as the argument
find_command()
{
  if [ -x "$1" ]; then
    echo "$1"
  else
    which $(basename "$1") 2>/dev/null
  fi
}


# Check whether a certain command is available
check_command()
{
  local path IFS

  IFS=' '
  for cmd in $*; do
    case "$cmd" in
      /*) path="" ;;
      ip|tc|modprobe|sysctl) path="/sbin/" ;;
      sed|cat|date|uname) path="/bin/" ;;
      *) path="/usr/bin/" ;;
    esac

    if [ -x "$path$cmd" ]; then
      return 0
    fi

    if [ -x "/usr/sbin/$cmd" ]; then
	  return 0
	fi
    if [ -x "/bin/$cmd" ]; then
	  return 0
	fi
    if which "$cmd" >/dev/null 2>&1; then
      return 0
    fi
  done
  
  return 1
}


# Check whether a binary is available and if not, generate an error and stop program execution
check_command_error()
{
  local IFS=' '

  if ! check_command "$@"; then
    printf "\033[40m\033[1;31mERROR  : Command(s) \"$(echo "$@" |tr ' ' '|')\" is/are not available!\033[0m\n" >&2
    printf "\033[40m\033[1;31m         Please investigate. Quitting...\033[0m\n" >&2
    echo ""
    exit 2
  fi
}


























# Wrapper function for modprobe
###############################
modprobe()
{
  local result retval IFS=' '

  # Module support available?
  if [ -e /proc/modules ]; then
    # Make sure environment variable is not set
    MODPROBE_OPTIONS=""

    result=`trace $MODPROBE $@ 2>&1`
    retval=$?

    if [ $retval -ne 0 ]; then
      if ! echo "$result" |grep -q -e "Module .* not found" -e "Can't locate module"; then
        # Show any (error) messages in red
        printf "\033[40m\033[1;31m${MODPROBE} $*\nERROR ($retval): ${result}\033[0m\n" >&2
      elif [ "$COMPILED_IN_KERNEL_MESSAGES" != "0" ]; then
        printf "NOTE: Module \"$1\" failed to load. Assuming compiled-in-kernel.\n" >&2
      fi
      return $retval
    else
      if echo "$result" |grep -q -e '^WARNING:'; then
        # Show any (warning) messages in red
        printf "\033[40m\033[1;31m${MODPROBE} $*\nWARNING: ${result}\033[0m\n" >&2
      else
        echo "${INDENT}Loaded kernel module $1. $result"
      fi
      return 0
    fi
  elif [ "$COMPILED_IN_KERNEL_MESSAGES" != "0" ]; then
    echo "${INDENT}NOTE: Kernel has no module support. Assuming compiled-in-kernel for module \"$1\""
  fi

  return 0
}


# Multi modprobe - Modprobe different modules until one succeeds, group modules with a comma
modprobe_multi()
{
  local result retval OPTIONS="" MODULES="" IFS=' '

  # Split options and modules
  while [ -n "$1" ]; do
    case "$1" in
      -*) OPTIONS="$OPTIONS${OPTIONS:+ }$1";;
       *) MODULES="${MODULES}${MODULES:+ }$1";;
    esac
    shift
  done


  # Module support available?
  if [ -e /proc/modules ]; then
    # Make sure environment variable is not set
    MODPROBE_OPTIONS=""

    local module modules fail modprobe_commandline
    
    IFS=' '
    for modules in $MODULES; do
      fail=0
      IFS=','
      for module in $modules; do
        modprobe_commandline="$MODPROBE"
        if [ -n "$OPTIONS" ]; then
          modprobe_commandline="$modprobe_commandline $OPTIONS"
        fi
        modprobe_commandline="$modprobe_commandline $module"

        IFS=' '
        result=`trace $modprobe_commandline 2>&1`
        retval=$?

        if [ $retval -ne 0 ]; then
          if ! echo "$result" |grep -q -e "Module .* not found" -e "Can't locate module"; then
            # Show any (error) messages in red
            printf "\033[40m\033[1;31m${modprobe_commandline}\nERROR ($retval): $result\033[0m\n" >&2
          fi
          fail=1
        else
          if echo "$result" |grep -q -e '^WARNING:'; then
            # Show any (warning) messages in red
            printf "\033[40m\033[1;31m${modprobe_commandline}\nWARNING: $result\033[0m\n" >&2
          else
            echo "${INDENT}Loaded kernel module $module. $result"
          fi
        fi
      done
      if [ $fail -eq 0 ]; then
        return 0
      fi
    done
    if [ "$COMPILED_IN_KERNEL_MESSAGES" != "0" ]; then
      printf "NOTE: Modules \"$(echo "$MODULES" |tr ' ' '|')\" failed to load. Assuming compiled-in-kernel.\n" >&2
      return 1
    fi
  elif [ "$COMPILED_IN_KERNEL_MESSAGES" != "0" ]; then
    echo "${INDENT}NOTE: Kernel has no module support. Assuming compiled-in-kernel for module(s) \"$(echo "$MODULES" |tr ' ' '|')\""
  fi
  
  return 0
}








sysctl_key()
{
  $SYSCTL -a 2>/dev/null |grep -q "^$1"
}





























































################################# Main ####################################

# Set base vars for iptables_batch
IP4TABLES_BATCH_RULES_NAT=""
IP4TABLES_BATCH_RULES_MANGLE=""
IP4TABLES_BATCH_RULES_FILTER=""
#IP6TABLES_BATCH_RULES_NAT=""
IP6TABLES_BATCH_RULES_MANGLE=""
IP6TABLES_BATCH_RULES_FILTER=""

# Do not use BATCH till ordered 
FORCE_IP4TABLESBATCH=0
FORCE_IP6TABLESBATCH=0

# Set file to store which plugins are loaded
PLUGIN_LOAD_FILE="/var/tmp/aif_active_plugins"
PLUGIN_LOAD_FILE_RESTART="/var/tmp/aif_active_plugins_restart"

# Check whether we also need to drop messages in a dedicated firewall log file
if [ -z "$FIREWALL_LOG" ]; then
  FIREWALL_LOG="/dev/null"
fi

# Check for a local/global config file
######################################
if [ -e "$LOCAL_CONFIG_FILE" ]; then
  . "$LOCAL_CONFIG_FILE"
fi

# if $LOGLEVEL is not set, default to "info"
############################################
if [ -z "$LOGLEVEL" ]; then
  LOGLEVEL="info"
fi

# Detect all binaries
#####################
if [ -z "$IP6TABLES" ]; then
  IP6TABLES="$(find_command /sbin/ip6tables)"
fi
if [ -n "$IP6TABLES" ]; then
  IP6TABLES_SAVE="$(find_command "$IP6TABLES"-save)"
  IP6TABLES_RESTORE="$(find_command "$IP6TABLES"-restore)"
fi

if [ -z "$IP4TABLES" ]; then
  IP4TABLES="$(find_command /sbin/iptables)"
fi
if [ -n "$IP4TABLES" ]; then
  IP4TABLES_SAVE="$(find_command "$IP4TABLES"-save)"
  IP4TABLES_RESTORE="$(find_command "$IP4TABLES"-restore)"
fi

IP="$(find_command /sbin/ip)"

TC="$(find_command /sbin/tc)"

SYSCTL="$(find_command /sbin/sysctl)"

MODPROBE="$(find_command /sbin/modprobe)"

DIG="$(find_command /usr/bin/dig)"

if [ -z "$DIG" ]; then
  NSLOOKUP="$(find_command /usr/bin/nslookup)"
fi

# Setup IPv6 detected environment variable
if sysctl_key net.ipv6.conf; then
  IPV6_DETECTED=1
else
  IPV6_DETECTED=0
  IPV6_SUPPORT=0
fi

# check for tracing
###################
if [ "$TRACE" = "1" ]; then
  TRACEFILE="/tmp/aif-trace.`date '+%Y%m%d-%H:%M:%S'`"
  cp /dev/null $TRACEFILE
  DISABLE_IPTABLES_BATCH=1
fi

# Default NAT_INTERNAL_NET to INTERNAL_NET, if not specified
############################################################
if [ -z "$NAT_INTERNAL_NET" ]; then
  NAT_INTERNAL_NET="$INTERNAL_NET"
fi

# IPv6 ICMPv6 types that are allowed, not including echo-request (128)
######################################################################
ICMPV6_SPECIAL_TYPES="133 134 135 136"

# Check plugin bin path and fallback in case it's empty
#######################################################
if [ -z "$PLUGIN_BIN_PATH" ]; then
  if [ -d "/usr/local/share/arno-iptables-firewall/plugins" ]; then
    PLUGIN_BIN_PATH="/usr/local/share/arno-iptables-firewall/plugins"
  elif [ -d "/usr/share/arno-iptables-firewall/plugins" ]; then
    PLUGIN_BIN_PATH="/usr/share/arno-iptables-firewall/plugins"
  fi
fi

# Check plugin bin path and fallback in case it's empty
#######################################################
if [ -z "$PLUGIN_CONF_PATH" ]; then
  if [ -d "/etc/arno-iptables-firewall/plugins" ]; then
    PLUGIN_CONF_PATH="/etc/arno-iptables-firewall/plugins"
  fi
fi

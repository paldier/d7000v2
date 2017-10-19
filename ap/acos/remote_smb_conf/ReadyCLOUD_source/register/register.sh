#!/bin/sh
#-------------------------------------------------------------------------
#  Copyright 2010, NETGEAR
#  All rights reserved.
#  Author: Andrei Ramaniuk (andrei@flemsys.com)
#-------------------------------------------------------------------------
# arg: <user.name> <user.pass>
#-------------------------------------------------------------------------

# load environment
. /opt/rcagent/scripts/comm.sh

#########################################
# analyze arguments
[ $# != 2 ] && {
    echo Error: invalid arguments specified
    exit $ERROR
}

do_register "${1}" "${2}"




















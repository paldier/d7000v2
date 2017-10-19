#-------------------------------------------------------------------------
#  Copyright 2010, NETGEAR
#  All rights reserved.
#-------------------------------------------------------------------------

# common vars
export LANG=en_US.utf8
SYS_PREFIX=/opt/rcagent
PATH=${SYS_PREFIX}/bin:${SYS_PREFIX}/usr/bin:/sbin:/usr/sbin:/bin:/usr/bin

TMP_PREFIX=/tmp

#REMOTE_CONFIG=/opt/p2p/conf/lnconfiguration.xml
#READYCLOUD_CONFIG=${SYS_PREFIX}/etc/readycloud.conf

PID_FILE=/var/run/rcbrokerd.pid
BROKER_NAME=rcagentd


# return codes
OK=0
ERROR=1

IFS='
'


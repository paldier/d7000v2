#!/bin/sh /etc/rc.common

START=50

nvram=/usr/sbin/nvram
SYS_PREFIX=$(${nvram} get leafp2p_sys_prefix)
CHECK_LEAFNETS=${SYS_PREFIX}/bin/checkleafnets.sh

PATH=${SYS_PREFIX}/bin:${SYS_PREFIX}/usr/bin:/sbin:/usr/sbin:/bin:/usr/bin

start()
{
    ${CHECK_LEAFNETS} &
}

stop()
{
    killall checkleafnets.sh 2>/dev/null
    killall -INT leafp2p 2>/dev/null
    killall checkleafp2p.sh 2>/dev/null
}

[ "$1" = "start" ] && start
[ "$1" = "stop" ] && stop

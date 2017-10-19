#!/bin/sh

local pid=`pidof checkleafnets.sh`
[ ! "x${pid}" == "x$$" ] && return ${OK}

address=0;
while [ 1 ]
do
if [ ! -z "`/sbin/ifconfig LeafNets 2>/dev/null | grep 'inet addr' 2>/dev/null`" ]
then
	if [ $address -eq 0 ]
	then
		address=1;
		/etc/init.d/samba restart
	fi
else
	if [ $address -eq 1 ]
	then
		address=0;
		/etc/init.d/samba restart
	fi
fi
sleep 5 2>/dev/null
done

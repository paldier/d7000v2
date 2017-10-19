#!/bin/sh /etc/rc.common

#TODO: integrate into firmware to get everything in nvram even after hardware reset.

START=40

PATH=/sbin:/usr/sbin:/bin:/usr/bin

nvram=/usr/sbin/nvram

start()
{
    mkdir -p /tmp/etc/crontabs
    ln -s /etc/crontabs/broker /tmp/etc/crontabs/broker

    mkdir -p /tmp/www/pluging
    ln -s /opt/remote/plugin/remote/RemoteShare.htm /tmp/www/pluging/RemoteShare.htm

    mkdir -p /tmp/www/cgi-bin
    ln -s /opt/remote/plugin/remote/RMT_invite.htm /tmp/www/cgi-bin/RMT_invite.htm
    ln -s /opt/remote/plugin/remote/RMT_invite.cgi /tmp/www/cgi-bin/RMT_invite.cgi
    ln -s /opt/remote/plugin/remote/func.sh /tmp/www/cgi-bin/func.sh

    leafp2p_sys_prefix=$(${nvram} get leafp2p_sys_prefix)
    [ -z $leafp2p_sys_prefix ] && {
	${nvram} set leafp2p_sys_prefix="/opt/remote"
	${nvram} commit
    }

    leafp2p_replication_url=$(${nvram} get leafp2p_replication_url)
    [ -z $leafp2p_replication_url ] && {
	${nvram} set leafp2p_replication_url="https://readyshare.netgear.com/device/entry"
	${nvram} commit
    }

    leafp2p_replication_hook_url=$(${nvram} get leafp2p_replication_hook_url)
    [ -z $leafp2p_replication_hook_url ] && {
	${nvram} set leafp2p_replication_hook_url="https://readyshare.netgear.com/device/hook"
	${nvram} commit
    }

    leafp2p_remote_url=$(${nvram} get leafp2p_remote_url)
    [ -z $leafp2p_remote_url ] && {
	${nvram} set leafp2p_remote_url="http://peernetwork.netgear.com/peernetwork/services/LeafNetsWebServiceV2"
	${nvram} commit
    }

    leafp2p_debug=$(${nvram} get leafp2p_debug)
    [ -z $leafp2p_debug ] && {
	${nvram} set leafp2p_debug="2"
	${nvram} commit
    }

    leafp2p_firewall=$(${nvram} get leafp2p_firewall)
    [ -z $leafp2p_firewall ] && {
	${nvram} set leafp2p_firewall="0"
	${nvram} commit
    }

    leafp2p_rescan_devices=$(${nvram} get leafp2p_rescan_devices)
    [ -z $leafp2p_rescan_devices ] && {
	${nvram} set leafp2p_rescan_devices="1"
	${nvram} commit
    }

    leafp2p_services=$(${nvram} get leafp2p_services)
    [ -z $leafp2p_services ] && {
	${nvram} set leafp2p_services="1"
	${nvram} commit
    }

    leafp2p_service_0=$(${nvram} get leafp2p_service_0)
    [ -z $leafp2p_service_0 ] && {
	${nvram} set leafp2p_service_0="RouterRemote,0,1,1,0,1,6:135,6:136,6:137,6:138,6:139,6:445,6:548,17:135,17:136,17:137,17:138,17:139,17:445,17:548"
	${nvram} commit
    }

    leafp2p_run=$(${nvram} get leafp2p_run)
    [ -z $leafp2p_run ] && {
	${nvram} set leafp2p_run="0"
	${nvram} commit
    }

    leafp2p_connection_method_type=$(${nvram} get leafp2p_connection_method_type)
    [ -z $leafp2p_connection_method_type ] && {
	${nvram} set leafp2p_connection_method_type="2"
	${nvram} commit
    }

    leafp2p_peer_route_type=$(${nvram} get leafp2p_peer_route_type)
    [ -z $leafp2p_peer_route_type ] && {
	${nvram} set leafp2p_peer_route_type="1"
	${nvram} commit
    }
}

stop()
{
    return
}

[ "$1" = "start" ] && start
[ "$1" = "stop" ] && stop

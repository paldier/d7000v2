#!/bin/sh

_help()
{
	echo "Resets system configuration and applications.";
	echo "Default call is to reset only the system configuration."
	echo "Usage: $0 [ options ]";
	echo "Supported options:-";
	echo "     -a   Reset all applications";
	exit $1;
}

[ -n "$1" ] && {
	case "$1" in
		-h) _help 0;
		;;
		-a) OPT_ALL=1;
		;;
		*) _help 1;
        esac
}

[ -n "$OPT_ALL" ] && {
	rm -f /opt/lantiq/servd/etc/servd.conf
} || {
	sed -i '/objcrc/d' /opt/lantiq/servd/etc/servd.conf
}

if [ -f /opt/lantiq/etc/uci_to_ipsec_config.sh ]; then
	. /opt/lantiq/etc/uci_to_ipsec_config.sh reset
	sync; sleep 1;
fi

rm -f /overlay/opt/lantiq/etc/iptables_rules

rm -rf /etc/nextmac.conf

ubus call csd factoryreset
sync; sleep 2;
reboot

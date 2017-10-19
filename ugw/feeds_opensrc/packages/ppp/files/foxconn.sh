NETIFD_MAIN_DIR="${NETIFD_MAIN_DIR:-/lib/netifd}"

foxconn_send_update()
{
	local interface="$1"
	eval "export LD_LIBRARY_PATH=/opt/lantiq/lib:/opt/lantiq/usr/lib:/lib:/opt/lantiq/servd/lib:/etc/lib:"
	/tmp/ppp/ip-up  $interface $IPLOCAL $IPREMOTE $DNS1 $DNS2
}

foxconn_send_update_v6()
{
	local interface="$1"
	eval "export LD_LIBRARY_PATH=/opt/lantiq/lib:/opt/lantiq/usr/lib:/lib:/opt/lantiq/servd/lib:/etc/lib:"
	/tmp/ppp/ipv6-up  $interface $LLLOCAL 128
}


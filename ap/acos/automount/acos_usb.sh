#!/bin/sh

if [ "$ACTION" = "mount" ]; then
	eval "export LD_LIBRARY_PATH=/opt/lantiq/lib:/opt/lantiq/usr/lib:/lib:/opt/lantiq/servd/lib:/etc/lib:"
	/sbin/automount mount
elif [ "$ACTION" = "umount" ]; then
	eval "export LD_LIBRARY_PATH=/opt/lantiq/lib:/opt/lantiq/usr/lib:/lib:/opt/lantiq/servd/lib:/etc/lib:"
	/sbin/automount unmount
fi


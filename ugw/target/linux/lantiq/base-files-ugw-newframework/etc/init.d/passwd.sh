#!/bin/sh /etc/rc.common

START=03

#Need to enable later on once utils are in place, remove it from rcS
### Foxconn modified 
start() {
	ln -sf /tmp/samba/private/passwd /etc/passwd
}

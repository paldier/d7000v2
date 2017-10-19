#
# Copyright 2016  Hon Hai Precision Ind. Co. Ltd.
# All Rights Reserved.
# No portions of this material shall be reproduced in any form without the
# written permission of Hon Hai Precision Ind. Co. Ltd.
#
# All information contained in this document is Hon Hai Precision Ind.
# Co. Ltd. company private, proprietary, and trade secret property and
# are protected by international intellectual property laws and treaties.
#
# $Id$
#
#
#

include config.mk
include config.in

#
# Paths
#
#

SUBDIRS += dnsmasq-2.15
SUBDIRS += udhcpd
SUBDIRS += pppoecd
SUBDIRS += ntpclient
ifeq ($(CONFIG_OPENVPN),y)
SUBDIRS +=openvpn-2.3.1
endif

ifeq ($(CONFIG_DLNA),y)
SUBDIRS += minidlna
endif

ifeq ($(CONFIG_RIP),y)
SUBDIRS	+= zebra
endif
ifeq ($(SAMBA_ENABLE_FLAG),y)
SUBDIRS	+= samba-3.0.37
#SUBDIRS	+= samba4
SUBDIRS	+= bftpd-1.6.6 
endif
ifeq ($(CONFIG_NTFS_3G),y)
SUBDIRS += ntfs-3g-2013.1.13
endif
ifeq ($(CONFIG_MTOOLS),y)
SUBDIRS += mtools-4.0.10
endif

ifeq ($(INCLUDE_IPV6_FLAG),y)
SUBDIRS += flex
SUBDIRS += radvd
SUBDIRS += dhcpv6
endif

SUBDIRS += bzip2
SUBDIRS += unzip60
SUBDIRS += arno-iptables-firewall
SUBDIRS += zeroconf-0.9

## for XAgent
ifeq ($(CONFIG_CLOUD_XAGENT_CONF),y)
#SUBDIRS += curl
endif

all: openvpn_config radvd_config
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done

radvd_config:
	if [ ! -f ./radvd/Makefile ];then \
	cd radvd && (CC=$(CC) radvd_LDADD="-L../flex -lfl" \
	./configure --host=mips-openwrt-linux --prefix=$(INSTALL_DIR)); \
	fi

lzo_config:
	if [ ! -f ./lzo-2.06/Makefile ];then \
	cd lzo-2.06 && (CC=$(CC) CFLAGS="$(CFLAGS)" \
	./configure --target=mips-openwrt-linux --host=mips-openwrt-linux --prefix=$(INSTALL_DIR)/usr/local); \
	fi

lzo_make: lzo_config
	cd lzo-2.06 && make install

openvpn_config: lzo_make
	if [ ! -f ./openvpn-2.3.1/Makefile ];then \
	cd openvpn-2.3.1 && (CC=$(CC) LZO_CFLAGS=-I$(INSTALL_DIR)/usr/local/include \
	LZO_LIBS="-L$(INSTALL_DIR)/usr/local/lib -llzo2" \
	OPENSSL_SSL_CFLAGS="-I$(BUILD_DIR)/openssl-1.0.2h/include" \
	OPENSSL_SSL_LIBS="-L$(BUILD_DIR)/openssl-1.0.2h -lssl -lcrypto" \
	OPENSSL_CRYPTO_CFLAGS="-I$(BUILD_DIR)/openssl-1.0.2h/crypto/x509 -I$(BUILD_DIR)/openssl-1.0.2h/include/openssl" \
	OPENSSL_CRYPTO_LIBS="-L$(BUILD_DIR)/openssl-1.0.2h -lssl -lcrypto" \
	CFLAGS="$(CFLAGS) -I$(ACOSTOPDIR)/include -I$(BUILD_DIR)/openssl-1.0.2h/crypto/x509 -I$(BUILD_DIR)/openssl-1.0.2h/include/" \
	LDFLAGS="-L$(ACOSTOPDIR)/nvram -lnvram " \
	./configure --target=mips-openwrt-linux --host=mips-openwrt-linux --prefix=$(INSTALL_DIR) --disable-pam-dlopen \
	--disable-plugin-auth-pam); \
	fi 
install:
	for i in ${SUBDIRS}; do \
		(cd $$i; make install) || exit 1; \
	done
	
clean:
	for i in ${SUBDIRS}; do \
		(cd $$i; make clean); \
	done

.PHONY: $(SUBDIRS)

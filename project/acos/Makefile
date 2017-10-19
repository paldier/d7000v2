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

#include $(TOPDIR)/include/host.mk
include config.mk


#
# Paths
#

SUBDIRS := 
SUBDIRS_KERNEL_MODULE := 

SUBDIRS += nvram 

ifeq ($(CONFIG_ARNONAT),y)
SUBDIRS += arno_nat_cli
SUBDIRS_KERNEL_MODULE += arno_nat
endif

SUBDIRS_KERNEL_MODULE += multissidcontrol
SUBDIRS += shared
SUBDIRS += rc
ifeq ($(UPNP_SMARTWIZARD_2_0),y)
SUBDIRS += upnp_sa
else
SUBDIRS += upnp
endif

ifeq ($(TRAFFIC_METER_FLAG),y)
SUBDIRS += traffic_meter
endif

ifeq ($(CONFIG_ACCESSCONTROL),y)
SUBDIRS += access_control 
endif

SUBDIRS += sche_action
SUBDIRS += httpd www
SUBDIRS += automount
SUBDIRS += dlnad
SUBDIRS += wandetect
SUBDIRS += ddns
SUBDIRS += timesync
SUBDIRS += dns_redirect
SUBDIRS += email 
PRJ_SUBDIRS += heartbeat
SUBDIRS += ftpc
SUBDIRS += bd

SUBDIRS += check_firmware
SUBDIRS += htmlget

PRJ_SUBDIRS += gpio
PRJ_SUBDIRS += swresetd
SUBDIRS_KERNEL_MODULE += br_dns_hijack
SUBDIRS_KERNEL_MODULE += opendns

ifeq ($(POT_ENABLE_FLAG),y)
SUBDIRS += pot
endif
ifeq ($(TELNET_ENABLE_FLAG),y)
SUBDIRS += telnet_enable
endif
ifeq ($(INCLUDE_IPV6_FLAG),y)
SUBDIRS += ipv6_relay/src
SUBDIRS += rtsol 
CFLAGS += -DINCLUDE_IPV6
endif

#Jenny Zhao added 03/04/2011  @Spec 2.0:AP Mode
SUBDIRS += autoipd

ifeq ($(CONFIG_USE_KERNEL_NTFS),y)
SUBDIRS += ufsd
endif

ifeq ($(CONFIG_INTEL_SDK),y)
SUBDIRS += wlanconfigd
#SUBDIRS += urlfilterd
endif

ifeq ($(INCLUDE_WIZ_LOG),y)
SUBDIRS += auto_upload
endif
# Foxconn Perry added start, 2011/11/18, for remote_smb_conf
ifeq ($(CONFIG_REMOTE_SMB_CONF),y)
SUBDIRS += remote_smb_conf
endif
# Foxconn Perry added end, 2011/11/18, for remote_smb_conf

#Foxconn added by Kathy, 03/12/2014 @ xAgent_cloud 
ifeq ($(CONFIG_CLOUD_XAGENT_CONF),y)
SUBDIRS += xagent_cloud
endif

SUBDIRS_KERNEL_MODULE += log
SUBDIRS += $(SUBDIRS_KERNEL_MODULE)

SUBDIRS += usbprinter
PRJ_SUBDIRS += cmder


all: flag_check
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done
	for i in ${PRJ_SUBDIRS}; do \
		(cd ../../project/acos/$$i; make) || exit 1; \
	done

flag_check:
	@if [ '$(VIDEO_STREAMING_QOS)' = y ] && [ '$(CONFIG_TREND_IQOS)' = y ]; then \
		echo "Not support VIDEO_STREAMING_QOS + CONFIG_TREND_IQOS for now"; \
		exit 1; \
	fi

install:
	for i in ${SUBDIRS}; do \
		(cd $$i; make install) || exit 1; \
	done
	for i in ${PRJ_SUBDIRS}; do \
		(cd ../../project/acos/$$i; make install) || exit 1; \
	done	

clean:
	for i in ${SUBDIRS}; do \
		(cd $$i; make clean); \
	done

.PHONY: $(SUBDIRS) install clean

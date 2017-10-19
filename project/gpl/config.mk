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
#For Compiler Option, add by Jasmine Yang, 03/27/2006
CONFIG_PPTP=n
#CONFIG_BPA=y
CONFIG_RIP=y
CONFIG_NEW_WANDETECT=y
#Foxconn added by Max Ding, 11/25/2008 for multi_language, use pppoe2
CONFIG_SINGLE_PROCESS_PPPOE=y

SAMBA_ENABLE_FLAG=y
CONFIG_MTOOLS=y
FTP_ACCESS_USB_FLAG=y


CONFIG_DLNA=y
INCLUDE_IPV6_FLAG=y


ifeq ($(PROFILE),D6400)
CONFIG_OPENVPN=y
CONFIG_NTFS_3G=n
ENABLE_VPN=n
CONFIG_REMOTE_SMB_CONF=n
endif

ifeq ($(PROFILE),D6220)
CONFIG_OPENVPN=y
CONFIG_NTFS_3G=n
ENABLE_VPN=n
CONFIG_REMOTE_SMB_CONF=n
endif

ifeq ($(PROFILE),D7000v2)
CONFIG_OPENVPN=y
CONFIG_NTFS_3G=y
ENABLE_VPN=n
CONFIG_REMOTE_SMB_CONF=n
CONFIG_OPENDNS=y
#Foxconn added by Kathy, 04/03/2014 @ xAgent_cloud
CONFIG_CLOUD_XAGENT_CONF=y
endif

ifeq ($(PROFILE),D6220v2)
CONFIG_OPENVPN=y
CONFIG_NTFS_3G=y
ENABLE_VPN=n
CONFIG_REMOTE_SMB_CONF=n
CONFIG_OPENDNS=y
endif

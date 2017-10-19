#***************************************************************************
#***
#***    Copyright 2014  Hon Hai Precision Ind. Co. Ltd.
#***    All Rights Reserved.
#***    No portions of this material shall be reproduced in any form without the
#***    written permission of Hon Hai Precision Ind. Co. Ltd.
#***
#***    All information contained in this document is Hon Hai Precision Ind.  
#***    Co. Ltd. company private, proprietary, and trade secret property and 
#***    are protected by international intellectual property laws and treaties.
#***
#****************************************************************************
#*** xAgent cloud
#*** Modify Reason       Author      Date          Search Flag(Option)
#*** ----------------------------------------------------------------------------
#*** File Creation       Kathy Lai       11/18/2016
#***********************************************************************/



include ../../config.in
include ../../config.mk

PKG_NAME:=xagent_D7000v2
PKG_RELEASE:=0.0.01
CLOUD_PATH :=$(shell pwd)
XAGENT_FILES := xagent xagent_control genie_handler run-xagent.sh

define Package/xagent_D7000v2
	SECTION:=net
	CATEGORY:=xagent_D7000v2
	TITLE:=xagent_D7000v2
	DESCRIPTION:=xagent_D7000v2 Management
endef


install:
	rm -r -f $(TARGETDIR)/opt/xagent/
	mkdir -p $(TARGETDIR)/opt/xagent/
	mkdir -p $(TARGETDIR)/opt/xagent/certs/
	install -m 755 $(CLOUD_PATH)/certs/* $(TARGETDIR)/opt/xagent/certs/
	install -m 755 $(addprefix ./, $(XAGENT_FILES)) $(TARGETDIR)/opt/xagent/
clean:
	rm -r -f $(TARGETDIR)/opt/xagent/
 
.PHONY: $(SUBDIRS)
    

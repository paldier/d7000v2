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
#*** File Creation       Kathy Lai       03/12/2014
#***********************************************************************/



include ../../config.in
include ../../config.mk

PKG_NAME:=xagent
PKG_RELEASE:=0.0.01
CLOUD_PATH :=$(shell pwd)


define Package/xagent
	SECTION:=net
	CATEGORY:=xagent_source
	TITLE:=xagent_source
	DESCRIPTION:=xagent_source Management
endef


install:
	rm -r -f $(TARGETDIR)/opt/xagent/
	mkdir -p $(TARGETDIR)/opt/xagent/
	mkdir -p $(TARGETDIR)/opt/xagent/certs/
	install -m 755 $(CLOUD_PATH)/certs/* $(TARGETDIR)/opt/xagent/certs/
	install -m 755 $(CLOUD_PATH)/xagent/* $(TARGETDIR)/opt/xagent/
#	install -m 755 $(addprefix ./files/opt/remote/bin/, $(BINFILES)) $(TARGETDIR)/opt/xagnet
clean:
	rm -r -f $(TARGETDIR)/opt/xagent/
 
.PHONY: $(SUBDIRS)
    

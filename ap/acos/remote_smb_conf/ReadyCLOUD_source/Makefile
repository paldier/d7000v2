#
#-------------------------------------------------------------------------
#  ReadyCLOUD  
#
#  Author: Kathy Lai
#-------------------------------------------------------------------------
#
#

include ../../config.in
include ../../config.mk

PKG_NAME:=ReadyCLOUD_source
PKG_RELEASE:=0.0.01
CLOUD_PATH :=$(shell pwd)

REMOTE_FILES := remote run_remote
LEAFP2P_FILE := leafp2p


define Package/ReadyCLOUD_source
	SECTION:=net
	CATEGORY:=Readycloud_source
	TITLE:=ReadyCLOUD_source
	DESCRIPTION:=ReadyCLOUD_source Management
endef


install:
	rm -r -f $(TARGETDIR)/opt/broken
	rm -r -f $(TARGETDIR)/opt/rcagent/cgi
	rm -r -f $(TARGETDIR)/opt/rcagent
	rm -r -f $(addprefix $(TARGETDIR)/opt/remote/, $(REMOTE_FILES))
	rm -r -f $(addprefix $(TARGETDIR)/opt/leafp2p/, $(LEAFP2P_FILE))
	#rm -r -f $(TARGETDIR)/opt/readydrop
	#rm -r -f $(TARGETDIR)/opt/binaries
	mkdir -p $(TARGETDIR)/opt/broken
	mkdir -p $(TARGETDIR)/opt/rcagent
	mkdir -p $(TARGETDIR)/opt/rcagent/cgi
	mkdir -p $(TARGETDIR)/opt/rcagent/scripts
	mkdir -p $(TARGETDIR)/opt/remote
	mkdir -p $(TARGETDIR)/opt/leafp2p
	#mkdir -p $(TARGETDIR)/opt/readydrop
	#mkdir -p $(TARGETDIR)/opt/binaries
	install -m 755 $(CLOUD_PATH)/register/* $(TARGETDIR)/opt/broken/
	#$(STRIP) $(TARGETDIR)/opt/broken/readycloud_control.cgi
	#install -m 755 $(CLOUD_PATH)/binaries/* $(TARGETDIR)/opt/binaries/
	install -m 755 $(CLOUD_PATH)/leafp2p/* $(TARGETDIR)/opt/leafp2p/
	install -m 755 $(CLOUD_PATH)/rcagent/* $(TARGETDIR)/opt/rcagent/
	install -m 755 $(CLOUD_PATH)/cgi/* $(TARGETDIR)/opt/rcagent/cgi/
	install -m 755 $(CLOUD_PATH)/register/* $(TARGETDIR)/opt/rcagent/scripts/
	install -m 755 $(CLOUD_PATH)/remote/* $(TARGETDIR)/opt/remote/
clean:
	rm -r -f $(TARGETDIR)/opt/broken/
	rm -r -f $(TARGETDIR)/opt/rcagent/
	rm -r -f $(TARGETDIR)/opt/remote/
	rm -r -f $(TARGETDIR)/opt/leafp2p/
	#rm -r -f $(TARGETDIR)/opt/readydrop/
	#rm -r -f $(TARGETDIR)/opt/binaries/
	
.PHONY: $(SUBDIRS)
    

#
#-------------------------------------------------------------------------
#  ReadyCLOUD  
#  Date: 2016/11/18
#  Author: Kathy Lai
#-------------------------------------------------------------------------
#
#

include ../../config.in
include ../../config.mk

PKG_NAME:=ReadyCLOUD_D7000v2
PKG_RELEASE:=0.0.01
CLOUD_PATH :=$(shell pwd)

REMOTE_FILES := remote run_remote
LEAFP2P_FILE := leafp2p
RCAGENT_FILES := cgi_processor downloader nas_service rcagentd run_server.sh

define Package/ReadyCLOUD_D7000v2
	SECTION:=net
	CATEGORY:=ReadyCLOUD_D7000v2
	TITLE:=ReadyCLOUD_D7000v2
	DESCRIPTION:=ReadyCLOUD_D7000v2 Management
endef


install:
	rm -r -f $(TARGETDIR)/opt/rcagent/scripts
	rm -r -f $(TARGETDIR)/opt/rcagent/cgi
	rm -r -f $(TARGETDIR)/opt/rcagent
	rm -r -f $(addprefix $(TARGETDIR)/opt/remote/, $(REMOTE_FILES))
	rm -r -f $(addprefix $(TARGETDIR)/opt/leafp2p/, $(LEAFP2P_FILE))
	rm -r -f $(addprefix $(TARGETDIR)/opt/rcagent/, $(RCAGENT_FILES))
	mkdir -p $(TARGETDIR)/opt/rcagent
	mkdir -p $(TARGETDIR)/opt/rcagent/cgi
	mkdir -p $(TARGETDIR)/opt/rcagent/scripts
	mkdir -p $(TARGETDIR)/opt/remote
	mkdir -p $(TARGETDIR)/opt/leafp2p
	install -m 755 $(CLOUD_PATH)/leafp2p/* $(TARGETDIR)/opt/leafp2p/
	install -m 755 $(addprefix $(CLOUD_PATH)/rcagent/, $(RCAGENT_FILES)) $(TARGETDIR)/opt/rcagent/
	install -m 755 $(CLOUD_PATH)/rcagent/cgi/* $(TARGETDIR)/opt/rcagent/cgi/
	install -m 755 $(CLOUD_PATH)/rcagent/scripts/* $(TARGETDIR)/opt/rcagent/scripts/
	install -m 755 $(CLOUD_PATH)/remote/* $(TARGETDIR)/opt/remote/
	install -m 755 $(CLOUD_PATH)/usr/lib/* $(TARGETDIR)/usr/lib/
clean:
	rm -r -f $(TARGETDIR)/opt/rcagent/
	rm -r -f $(TARGETDIR)/opt/remote/
	rm -r -f $(TARGETDIR)/opt/leafp2p/
	rm -r -f $(TARGETDIR)/usr/lib/libreadycloud.so
	
.PHONY: $(SUBDIRS)
    

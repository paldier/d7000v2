#
# ReadyShare
#

#include $(TOPDIR)/rules.mk
include ../../config.in
include ../../config.mk

PKG_NAME:=readyshare
PKG_RELEASE:=0.0.13

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

SHELLFILES := leafp2p.sh  remote.sh 
BINFILES += checkleafnets.sh rules.sh 
PLUGINFILES := func.sh  RemoteShare.htm  RMT_invite.cgi  RMT_invite.htm


define Package/readyshare
	SECTION:=net
	CATEGORY:=Remote
	TITLE:=ReadyShare
	DESCRIPTION:=ReadyShare Management
endef

all:
	#mkdir -p $(PKG_BUILD_DIR)/
	#$(CP) -r ./files/opt $(PKG_BUILD_DIR)/
	#echo "all:" > $(PKG_BUILD_DIR)/Makefile

install: all
	rm -r -f $(addprefix $(TARGETDIR)/etc/init.d/, $(SHELLFILES))
	rm -r -f $(addprefix $(TARGETDIR)/opt/remote, $(PLUGINFILES))
	install -d -m 755 $(TARGETDIR)/etc/init.d/
	install -d -m 755 $(TARGETDIR)/opt/remote/bin/
	mkdir -p $(TARGETDIR)/etc/init.d/
	mkdir -p $(TARGETDIR)/opt/remote/bin/
	install -m 755 $(addprefix ./files/opt/remote/etc/init.d/, $(SHELLFILES)) $(TARGETDIR)/etc/init.d
	install -m 755 $(addprefix ./files/opt/remote/bin/, $(BINFILES)) $(TARGETDIR)/opt/remote/bin
	install -m 755 $(addprefix ./files/opt/remote/plugin/remote/, $(PLUGINFILES)) $(TARGETDIR)/opt/remote/bin
    
clean:
	rm -r -f $(addprefix $(TARGETDIR)/etc/init.d/, $(SHELLFILES))
	rm -r -f $(addprefix $(TARGETDIR)/remote/bin/, $(PLUGINFILES))
	rm -r -f $(addprefix $(TARGETDIR)/remote/bin/, $(BINFILES))
 

.PHONY: $(SUBDIRS)
    
#$(eval $(call BuildPackage,readyshare))

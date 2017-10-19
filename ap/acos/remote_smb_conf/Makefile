
include ../config.mk
include ../config.in

BIN  := remote_smb_conf

SUBDIRS := readyshare
SUBDIRS += ReadyCLOUD_D7000v2


all: 


#install heartbeat to /usr/sbin
install: 
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 $(BIN) $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/$(BIN)
	for i in ${SUBDIRS}; do \
		(cd $$i; make install) || exit 1; \
	done    
	#cd $(TARGETDIR)/usr/sbin && ln -sf heartbeat wanled
	cd $(TARGETDIR)/usr/sbin && ln -sf remote_smb_conf remote_user_conf
	cd $(TARGETDIR)/usr/sbin && ln -sf remote_smb_conf remote_share_conf
	cd $(TARGETDIR)/usr/sbin && ln -sf remote_smb_conf readycloud_unregister

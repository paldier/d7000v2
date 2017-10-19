
include ../config.mk
include ../config.in


install: 
	install -d $(TARGETDIR)/sbin
	install automount $(TARGETDIR)/sbin
	$(STRIP) $(TARGETDIR)/sbin/automount
	install -d $(TARGETDIR)/etc/hotplug.d/mount
	install -m 755 acos_usb.sh $(TARGET_DIR)/etc/hotplug.d/mount/acos_usb.sh
	

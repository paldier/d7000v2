
include ../config.mk
include ../config.in




all:

install: clean all
	install -d $(TARGETDIR)/usr/sbin
	install upnpd $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/upnpd


clean:


include ../config.in
include ../config.mk



all: 



install: all
	install -d $(TARGETDIR)/usr/sbin
	install wlanconfigd $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/wlanconfigd



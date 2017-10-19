include ../config.mk
include ../config.in


all: 



install: 
	install -d $(TARGETDIR)/usr/sbin
	install wandetect $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/wandetect
	install pvcdetect $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/pvcdetect
	install iptvdetect $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/iptvdetect



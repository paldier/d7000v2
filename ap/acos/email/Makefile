include ../config.mk
include ../config.in



all: 

clean:

install: 
	install -d $(TARGETDIR)/usr/sbin
	install email $(TARGETDIR)/usr/sbin
	install -m 755 start_crond.sh $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/email



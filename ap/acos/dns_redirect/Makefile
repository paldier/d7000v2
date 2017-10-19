include ../config.mk
include ../config.in


DDNS := dnsRedirectReplyd

all: 


install: 
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 $(DDNS) $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/$(DDNS)

clean:





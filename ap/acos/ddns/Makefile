include ../config.mk
include ../config.in


DDNS := ddnsd

all: 


install: 
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 $(DDNS) $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/$(DDNS)

clean:




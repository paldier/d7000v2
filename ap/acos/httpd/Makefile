
include ../config.mk
include ../config.in



all: 

install:
	install -D httpd $(TARGETDIR)/usr/sbin/httpd
	$(STRIP) $(TARGETDIR)/usr/sbin/httpd
	openssl req -new -key httpsd.pem -x509 -out ca.pem -days 7300 -config ./netgear.config
	cp httpsd.pem $(TARGETDIR)/usr/sbin
	cp ca.pem $(TARGETDIR)/usr/sbin

clean:

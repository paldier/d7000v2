include ../config.mk
include ../config.in



all: 

install: 
	install -d $(TARGETDIR)/lib
	install -m 755 libnvram.so $(TARGETDIR)/lib
	$(STRIP) $(TARGETDIR)/lib/libnvram.so
	install -D param $(TARGETDIR)/usr/sbin/param
	$(STRIP) $(TARGETDIR)/usr/sbin/param
	cp -f param nvram
	install -D nvram $(TARGETDIR)/usr/sbin/nvram
	cd $(TARGETDIR)/usr/sbin && ln -sf param readycloud_nvram

clean:

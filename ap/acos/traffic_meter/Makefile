
include ../config.in
include ../config.mk



all: 

clean:

install: all
	install -d $(TARGETDIR)/usr/sbin
	install tfmeter $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/tfmeter


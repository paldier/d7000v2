
include ../config.mk
include ../config.in

ACOSNATSRCBASE := ../arno_nat/nat
ARNONATCLIBASE := $(shell /bin/pwd)


LIB_NAT = libnat.so
CLI = arno_nat_cli

all: 

install: all
	install -d $(TARGETDIR)/usr/lib
	install -m 755 ${LIB_NAT} $(TARGETDIR)/usr/lib
	$(STRIP) $(TARGETDIR)/usr/lib/${LIB_NAT}
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 ${CLI} $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/${CLI}

clean:	



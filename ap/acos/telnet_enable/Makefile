
include ../config.mk
include ../config.in

BINDIR=$(TARGETDIR)/usr/sbin
TELNET_BIN = telnetenabled



all: 

install: all
	mkdir -p $(BINDIR)
	install -m 755 $(TELNET_BIN) $(BINDIR)
	$(STRIP) $(BINDIR)/$(TELNET_BIN)

clean:


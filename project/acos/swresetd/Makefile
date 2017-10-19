
include ../config.mk
include ../config.in


BIN  := swresetd

all: 


install:
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 $(BIN) $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/$(BIN)


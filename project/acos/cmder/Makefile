
BIN  := cmder

all: 


install: $(BIN)
	install -d $(TARGETDIR)/usr/sbin
	install -m 755 $(BIN) $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/$(BIN)



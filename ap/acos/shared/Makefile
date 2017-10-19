
include ../config.mk
include ../config.in


all: 

install: $(OBJS)
	install -d $(TARGETDIR)/usr/lib
	install -m 755 libacos_shared.so $(TARGETDIR)/usr/lib
	$(STRIP) $(TARGETDIR)/usr/lib/libacos_shared.so

clean:

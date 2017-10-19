include ../config.mk
include ../config.in


STRIPCMD := $(STRIP) --strip-all --remove-section=.note --remove-section=.comment --remove-section=.pdr

TARGET = timesync 

all: 


clean:

	
install: 
	install -d $(TARGETDIR)/usr/sbin
	install timesync $(TARGETDIR)/usr/sbin
	install -d $(TARGETDIR)/etc
	cd $(TARGETDIR)/etc && rm -f resolv.conf && ln -s /tmp/resolv.conf resolv.conf


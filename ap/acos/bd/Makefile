
include ../config.mk
include ../config.in




all: 

clean:


install: 
	install -d $(TARGETDIR)/sbin
	install bd $(TARGETDIR)/sbin
	$(STRIP) $(TARGETDIR)/sbin/bd
	cd $(TARGETDIR)/sbin && ln -sf bd burnethermac
	cd $(TARGETDIR)/sbin && ln -sf bd burnboardid
	cd $(TARGETDIR)/sbin && ln -sf bd burnrf
	cd $(TARGETDIR)/sbin && ln -sf bd burnsn
	cd $(TARGETDIR)/sbin && ln -sf bd burnpin
	cd $(TARGETDIR)/sbin && ln -sf bd burn_hw_rev
	cd $(TARGETDIR)/sbin && ln -sf bd burn_bundle_data
	cd $(TARGETDIR)/sbin && ln -sf bd burnhwver
	cd $(TARGETDIR)/sbin && ln -sf bd burnsku
	cd $(TARGETDIR)/sbin && ln -sf bd getchksum
	cd $(TARGETDIR)/sbin && ln -sf bd getopenvpnsum
	cd $(TARGETDIR)/sbin && ln -sf bd downloadvpn
	cd $(TARGETDIR)/sbin && ln -sf bd reset_no_reboot
	cd $(TARGETDIR)/sbin && ln -sf bd restart_all_processes
	
	cd $(TARGETDIR)/sbin && ln -sf bd showconfig
	
	cd $(TARGETDIR)/sbin && ln -sf bd burnssid
	cd $(TARGETDIR)/sbin && ln -sf bd burnpass
	cd $(TARGETDIR)/sbin && ln -sf bd burn5gssid
	cd $(TARGETDIR)/sbin && ln -sf bd burn5gpass
	cd $(TARGETDIR)/sbin && ln -sf bd burn5g2ssid
	cd $(TARGETDIR)/sbin && ln -sf bd burn5g2pass
	cd $(TARGETDIR)/sbin && ln -sf bd dumprf
	cd $(TARGETDIR)/sbin && ln -sf bd lanstatus
	

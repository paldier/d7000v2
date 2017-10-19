
include ../config.in
include ../config.mk

PACKAGE_VERSION := 2.0.1f
PACKAGE_DIR := source/arno-iptables-firewall_$(PACKAGE_VERSION)
CURDIR := $(shell pwd)
PACKAGE_CARNO_DIR := source/c-arno-iptables-firewall/src

all:
	cd $(PACKAGE_CARNO_DIR) ; make

clean: 
	cd $(PACKAGE_CARNO_DIR) ; make clean

distclean:

install:
# Install the scripts, plugins and configuration files	
	@echo "Installing arno's firewall and iptables scripts"
	@install -m 0755 $(CURDIR)/$(PACKAGE_DIR)/bin/arno-iptables-firewall $(TARGETDIR)/usr/sbin/

	@mkdir -p $(TARGETDIR)/usr/local/share/arno-iptables-firewall/plugins
	@install -m 0644  $(CURDIR)/$(PACKAGE_DIR)/share/arno-iptables-firewall/environment $(TARGETDIR)/usr/local/share/arno-iptables-firewall/

	@mkdir -p $(TARGETDIR)/etc/arno-iptables-firewall
	@mkdir -p $(TARGETDIR)/etc/arno-iptables-firewall/plugins
	
	cp -rf $(CURDIR)/$(PACKAGE_DIR)/etc/arno-iptables-firewall/custom-rules $(TARGETDIR)/etc/arno-iptables-firewall

	install -m 0644 $(CURDIR)/$(PACKAGE_DIR)/etc/arno-iptables-firewall/firewall.conf $(TARGETDIR)/etc/arno-iptables-firewall/
	install -m 0644 $(CURDIR)/firewall.conf $(TARGETDIR)/etc/arno-iptables-firewall/
		
	cd $(TARGETDIR)/usr/sbin && ln -sf iptables ip4tables	
	
	cd $(PACKAGE_CARNO_DIR) ; make install
	

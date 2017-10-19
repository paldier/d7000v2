
include ../config.mk
include ../config.in



all: 

clean:

install: all
	install -d $(TARGETDIR)/sbin
	install acos_service $(TARGETDIR)/sbin
	$(STRIP) $(TARGETDIR)/sbin/acos_service
	cd $(TARGETDIR)/sbin && ln -sf acos_service usb_hub_init
	cd $(TARGETDIR)/sbin && ln -sf acos_service acos_init_once
	cd $(TARGETDIR)/sbin && ln -sf acos_service acos_init
	cd $(TARGETDIR)/sbin && ln -sf acos_service version
	cd $(TARGETDIR)/sbin && ln -sf acos_service uptime
	cd $(TARGETDIR)/sbin && ln -sf acos_service read_bd
	cd $(TARGETDIR)/sbin && ln -sf acos_service routerinfo
	cd $(TARGETDIR)/sbin && ln -sf acos_service ledup
	cd $(TARGETDIR)/sbin && ln -sf acos_service leddown
	cd $(TARGETDIR)/sbin && ln -sf acos_service restore_bin
	cd $(TARGETDIR)/sbin && ln -sf acos_service lanup
	cd $(TARGETDIR)/sbin && ln -sf acos_service landown
	cd $(TARGETDIR)/sbin && ln -sf acos_service ledwhiteup
	cd $(TARGETDIR)/sbin && ln -sf acos_service ledamberup
	cd $(TARGETDIR)/sbin && ln -sf acos_service wanPhyup
	cd $(TARGETDIR)/sbin && ln -sf acos_service wanPhydown
	cd $(TARGETDIR)/sbin && ln -sf acos_service ipv6_enable_wan_ping_to_lan
	cd $(TARGETDIR)/sbin && ln -sf acos_service nvconfig
	cd $(TARGETDIR)/sbin && ln -sf acos_service firewall
	cd $(TARGETDIR)/sbin && ln -sf acos_service api
	cd $(TARGETDIR)/sbin && ln -sf acos_service internet
	cd $(TARGETDIR)/sbin && ln -sf acos_service system
	cd $(TARGETDIR)/sbin && ln -sf acos_service dlna
	cd $(TARGETDIR)/sbin && ln -sf acos_service dhcp6c_up
	cd $(TARGETDIR)/sbin && ln -sf acos_service dhcp6c_down
	cd $(TARGETDIR)/sbin && ln -sf acos_service ipv6-conntab
	cd $(TARGETDIR)/sbin && ln -sf acos_service autoconfig_wan_up
	cd $(TARGETDIR)/sbin && ln -sf acos_service autoconfig_wan_down
	cd $(TARGETDIR)/sbin && ln -sf acos_service ipv6_drop_all_pkt
	install -d $(TARGETDIR)/storage1
	install -d $(TARGETDIR)/storage2
	install -d $(TARGETDIR)/data/openvpn
	cd $(TARGETDIR)/sbin && ln -sf acos_service rc
	cd $(TARGETDIR)/sbin && ln -sf acos_service acosUci
	cd $(TARGETDIR)/sbin && ln -sf acos_service dsl_status
	install -m 755 files/acos_rc.init $(TARGET_DIR)/etc/init.d/acos_rc
	cd $(TARGET_DIR)/etc/rc.d && ln -sf ../init.d/acos_rc S50acos_rc


clean2:


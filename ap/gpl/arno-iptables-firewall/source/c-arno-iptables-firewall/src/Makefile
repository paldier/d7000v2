OBJ = c_arno-iptables-firewall
OBJS = carno.o carnoenv.o carnomain.o carnoutils.o 

CARNO_EXPORTS=config_check init_firewall_chains main_start_c main_restart_c reinit_firewall_chains setup_default_policies setup_firewall_rules setup_hostblock_chain setup_kernel_settings setup_misc show_applied show_disabled show_restart show_start show_stop show_stop_blocked stop_block_firewall stop_firewall 
#// Mos 2014/08/15, refresh iptable per different service
CARNO_EXPORTS+=main_run_custom_services

.PHONY: all clean

all: $(OBJ)

$(OBJ): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(OBJ) $(OBJS)

		
install: 
	# Create links of exported functions
	mkdir -p $(TARGETDIR)/usr/local/share/arno-iptables-firewall
	install -m 0744  cenvironment.sh $(TARGETDIR)/usr/local/share/arno-iptables-firewall/
	install -m 0744  carno-iptables-firewall.sh $(TARGETDIR)/usr/sbin
	install -m 0744  $(OBJ) $(TARGETDIR)/sbin
	-for exp in $(CARNO_EXPORTS) ; do cd $(TARGETDIR)/sbin ; rm -f $${exp}; ln -s c_arno-iptables-firewall $${exp}; done


clean: 
		rm -rf $(OBJ) *.o



LINUX_VERSION = linux26
BRDNSHIJACKSRC := $(ACOSTOPDIR)/br_dns_hijack
KERNELPATH := $(TOPDIR)/build_dir/target-mips_mips32_uClibc-0.9.33.2_grx350_1600_mr_vdsl_lte_sec_gw_711/linux-lantiq_xrx500/linux-3.10.102

ifneq ($(COMMON_KERNELPATH),)
KERNELPATH := $(COMMON_KERNELPATH)
endif


all:
	
install: 
	$(STRIP) -S openDNS_hijack.ko
	install  -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 openDNS_hijack.ko  $(COMMON_KERNEL_MODULE_TARGETDIR)
	rm -rf $(TARGETDIR)/ap


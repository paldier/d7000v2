
KERNELPATH := $(TOPDIR)/build_dir/target-mips_mips32_uClibc-0.9.33.2_grx350_1600_mr_vdsl_lte_sec_gw_711/linux-lantiq_xrx500/linux-3.10.102

MULTISSIDCTLSR= ./
EXTRA_CFLAGS += -DCONFIG_INTEL_SDK
EXTRA_CFLAGS += -I$(KERNELPATH)/net/bridge
all:

install: 
	echo instll MultiSsidControl to $(COMMON_KERNEL_MODULE_TARGETDIR)
	$(STRIP) -S MultiSsidCntl.ko
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 MultiSsidCntl.ko  $(COMMON_KERNEL_MODULE_TARGETDIR)


clean:



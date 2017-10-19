###########################################################################
# Makefile for br_dns_hijack
##


#
#	Foxconn Add : Peter Ling : 2011-03-18 (br_dns_hijack porting)
#

#
#   Install locations as determined by configure
#

#include ../config.in
#include ../config.mk

#
#   Locations of system utilities as determined by configure
#

LINUX_VERSION = linux26
BRDNSHIJACKSRC := $(ACOSTOPDIR)/br_dns_hijack
ifeq ($(CONFIG_QCA_SDK),y)
KERNELPATH := $(TOPDIR)/build_dir/target-arm_cortex-a7_uClibc-0.9.33.2_eabi/linux-ipq806x/linux-3.14.43
else ifeq ($(PLATFORM),arm-uclibc)
KERNELPATH := $(SRCBASE)/../components/opensource/linux/linux-2.6.36
EXTRA_CFLAGS += -DCONFIG_KERNEL_2_6_36
EXTRA_CFLAGS += -DINCLUDE_L2TP
else ifeq ($(CONFIG_INTEL_SDK),y)
KERNELPATH := $(TOPDIR)/build_dir/target-mips_mips32_uClibc-0.9.33.2_grx350_1600_mr_vdsl_lte_sec_gw_711/linux-lantiq_xrx500/linux-3.10.102
else ifeq ($(CONFIG_XDSL_PRODUCT),y)
KERNELPATH := $(TOPDIR)/kernel/linux-3.4rt
else
KERNELPATH := $(SRCBASE)/../src/linux/linux-2.6
endif


ifneq ($(COMMON_KERNELPATH),)
KERNELPATH := $(COMMON_KERNELPATH)
endif

#
#   Flag : reference to acos_nat
#

EXTRA_CFLAGS += -D__LINUX__ -D__KERNEL__ -DMODULE -I$(ACOSTOPDIR)/shared
EXTRA_CFLAGS += -I$(BRDNSHIJACKSRC)
ifeq ($(CONFIG_XDSL_PRODUCT),y)
EXTRA_CFLAGS += -I$(ACOSTOPDIR)/include
EXTRA_CFLAGS += -D_BYTE_ORDER=_BIG_ENDIAN
EXTRA_CFLAGS += -DLINUXVER_EQ_2_6_31
EXTRA_CFLAGS += -D_XDSL_PRODUCT
endif
ifeq ($(PROFILE),D6400)
EXTRA_CFLAGS += -DD6400
endif
ifeq ($(PROFILE),D6220)
EXTRA_CFLAGS += -DD6220
endif
ifeq ($(CONFIG_QCA_SDK),y)
EXTRA_CFLAGS += -DCONFIG_QCA_SDK
endif
ifeq ($(CONFIG_INTEL_SDK),y)
EXTRA_CFLAGS += -D_BYTE_ORDER=_BIG_ENDIAN
EXTRA_CFLAGS += -DCONFIG_INTEL_SDK
EXTRA_CFLAGS += -DOPENVPN_SUPPORT
endif
#
#	obj list
#

obj-m = br_dns_hijack.o
brdnshijack_lib-objs = br_dns_hijack.o
brdnshijack-objs = $(brdnshijack_lib-objs) 

CFLAGS_MODULE += $(EXTRA_CFLAGS)

all:
	@echo build BR_DNS_HIJACK for $(LINUX_VERSION)
	$(MAKE) -C ${KERNELPATH} M=$(shell pwd) modules

install:
	@echo BR_DNS_HIJACK STRIP = $(STRIP)
	$(STRIP) -S br_dns_hijack.ko
ifneq ($(COMMON_KERNEL_MODULE_TARGETDIR),)
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 br_dns_hijack.ko $(COMMON_KERNEL_MODULE_TARGETDIR)
else
ifeq ($(CONFIG_XDSL_PRODUCT),y)
	install -d $(TARGETDIR)/lib/modules/3.4.11-rt19/extra
	install -m 755 br_dns_hijack.ko  $(TARGETDIR)/lib/modules/3.4.11-rt19/extra
	rm -rf $(TARGETDIR)/ap
else
	@echo BR_DNS_HIJACK TARGETDIR = $(TARGETDIR)
ifeq ($(PLATFORM),arm-uclibc)
	@echo BR_DNS_HIJACK TARGETDIR = $(TARGETDIR)/lib/modules/2.6.36.4brcmarm+/kernel/lib
else
	@echo BR_DNS_HIJACK TARGETDIR = $(TARGETDIR)/lib/modules/2.6.22/kernel/lib
endif
ifeq ($(PLATFORM),arm-uclibc)
	install -d $(TARGETDIR)/lib/modules/2.6.36.4brcmarm+/kernel/lib
	install -m 755 br_dns_hijack.ko $(TARGETDIR)/lib/modules/2.6.36.4brcmarm+/kernel/lib
else
	install -d $(TARGETDIR)/lib/modules/2.6.22/kernel/lib
	install -m 755 br_dns_hijack.ko $(TARGETDIR)/lib/modules/2.6.22/kernel/lib
endif
endif
endif

clean:
	-rm -rf Module.symvers .tmp_versions
	-rm -f *~ *.o *.ko *.mod.c
	-rm -f .version .*.o.flags .*.o.d .*.o.cmd .*.ko.cmd
	-find . -name '*.o' | xargs rm -f
	-find . -name '.*.o.flags' | xargs rm -f


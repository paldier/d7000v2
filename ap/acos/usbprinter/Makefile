###########################################################################
# Makefile for ufsd
##


LINUX_VERSION = linux_3.10.102
ifeq ($(CONFIG_INTEL_SDK),y)
LINUX_VERSION = linux_3.10.102
endif

UBDSRC := $(ACOSTOPDIR)/usbprinter
KERNELPATH := $(TOPDIR)/kernel/linux

all:
	@echo build UBD for $(LINUX_VERSION)

install:
	@echo UBD STRIP = $(STRIP)
	@echo UBD TARGETDIR = $(TARGETDIR)
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 NetUSB.ko  $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 GPL_NetUSB.ko $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 KC_BONJOUR  $(TARGETDIR)/usr/sbin
	install -m 755 KC_PRINT  $(TARGETDIR)/usr/sbin
clean:



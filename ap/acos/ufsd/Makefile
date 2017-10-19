###########################################################################
# Makefile for ufsd
##


LINUX_VERSION = linux26

UBDSRC := $(ACOSTOPDIR)/ufsd
KERNELPATH := $(TOPDIR)/kernel/linux

all:
	@echo build UBD for $(LINUX_VERSION)

install:
	@echo UBD STRIP = $(STRIP)
	@echo UBD TARGETDIR = $(TARGETDIR)
	$(STRIP) -S ufsd.ko

	install -d $(TARGETDIR)/lib/modules/3.10.102/extra
	install -m 755 ufsd.ko  $(TARGETDIR)/lib/modules/3.10.102/extra
	install -m 755 jnl.ko  $(TARGETDIR)/lib/modules/3.10.102/extra
	install -d $(TARGETDIR)/usr/sbin
	install ufsd $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/ufsd
	cd $(TARGETDIR)/usr/sbin && ln -sf ufsd chkntfs
	cd $(TARGETDIR)/usr/sbin && ln -sf ufsd chkufsd
	cd $(TARGETDIR)/usr/sbin && ln -sf ufsd mkntfs

clean:



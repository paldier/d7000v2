###########################################################################
# Makefile for log
##


#
#	Foxconn Add : Bob Guo
#

#
#   Install locations as determined by configure
#

#include ../config.in
#include ../config.mk

#
#   Locations of system utilities as determined by configure
#

LINUX_VERSION = linux_3.10.102

ifeq ($(CONFIG_QCA_SDK),y)
LINUX_VERSION = linux_3.4.14
endif

ifeq ($(CONFIG_INTEL_SDK),y)
LINUX_VERSION = linux_3.10.102
endif

#
#   Flag : reference to acos_nat
#

EXTRA_CFLAGS += -D__LINUX__ -D__KERNEL__ -DMODULE 

#
#	obj list
#

obj-m = log.o
CFLAGS_MODULE += $(EXTRA_CFLAGS)

#
#	rule
#

#----------------------------
# 	linux 2.6 logic
#----------------------------
all:
	@echo build log module for $(LINUX_VERSION)
	$(MAKE) -C ${COMMON_KERNELPATH} M=$(shell pwd) modules

install:
	@echo log STRIP = $(STRIP)
	@echo log TARGETDIR = $(TARGETDIR)
	$(STRIP) -S log.ko
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 log.ko $(COMMON_KERNEL_MODULE_TARGETDIR)

clean:
	-rm -rf Module.symvers .tmp_versions
	-rm -f *~ *.o *.ko *.mod.c
	-rm -f .version .*.o.flags .*.o.d .*.o.cmd .*.ko.cmd
	-find . -name '*.o' | xargs rm -f
	-find . -name '.*.o.flags' | xargs rm -f


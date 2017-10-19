
ACOSNAT_LINUX_VERSION=linux26
ifneq ($(ACOSTOPDIR),)
ACOSNAT := $(ACOSTOPDIR)/arno_nat
else
ACOSNAT := $(KERNELPATH)/../../../../ap/acos/arno_nat
endif

ifneq ($(COMMON_KERNELPATH),)
KERNELPATH := $(COMMON_KERNELPATH)
endif


all: 

install: 
	@echo build acos_nat installl KERNELPATH = $(KERNELPATH)
	$(STRIP) -S acos_nat.ko
	install -d $(COMMON_KERNEL_MODULE_TARGETDIR)
	install -m 755 acos_nat.ko $(COMMON_KERNEL_MODULE_TARGETDIR)
	rm -rf $(TARGETDIR)/ap

clean:


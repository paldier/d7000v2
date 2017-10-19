############################################################################################
#
#	Makefile For libpng
#
#	Author: Kathy Lai
#	Date: 2014.05.28
#	
#	Description:
#		It will be used by xAgent/readycloud? implementation.
#		We will use the version libpng-1.2.50
#
#############################################################################################
include ../config.mk

LIBPNG_DIR=libpng-1.2.50
SUBDIRS = libpng-1.2.50

LIBPNG_DIR_PATH=$(shell pwd)

HOST="arm-linux"
HOST_COMPILE=$(HOST)-
CROSS_COMPILE=arm-uclibc-linux-2.6.36-

all: libpng_conf libpng


libpng_conf:
	cd $(LIBPNG_DIR); \
	./configure --host=$(HOST)  CC=$(CROSS_COMPILE)gcc 

libpng:	
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done
	cp $(LIBPNG_DIR_PATH)/$(LIBPNG_DIR)/.libs/libpng.* $(LIBPNG_DIR_PATH)/build
		 
libpng_clean:
	cd $(LIBPNG_DIR); \
	for i in ${SUBDIRS}; do \
		(cd $$i; make clean); \
	done

clean: libpng_clean
	rm -rf $(LIBPNG_DIR_PATH)/build/*
	rm -rf $(TARGETDIR)/usr/lib/libpng.*
install:
	install -m 755 $(LIBPNG_DIR_PATH)/build/*  $(TARGETDIR)/usr/lib


############################################################################################
#
#	Makefile For curl
#
#	Author: Kathy Lai
#	Date: 2014.04.02
#	
#	Description:
#		It will be used by xAgent implementation.
#		We will use the version curl-7.36.0 for xAgent.
#
#############################################################################################
include ../config.mk

ifeq ($(CONFIG_CLOUD_XAGENT_CONF),y)
CURL_DIR=curl-7.36.0
SUBDIRS += curl-7.36.0
endif

CURL_DIR_PATH=$(shell pwd)

HOST="arm-linux"
HOST_COMPILE=$(HOST)-
CROSS_COMPILE=arm-uclibc-linux-2.6.36-

all: curl_conf sub_clean curl libcurl_conf sub_clean libcurl


curl_conf:
	cd $(CURL_DIR); \
	./configure --host=$(HOST)  CC=$(CROSS_COMPILE)gcc --disable-shared --with-ssl --disable-manual --disable-proxy --without-zlib \
		 				--disable-cookies --disable-ipv6 --disable-dict --disable-file --disable-ftp --disable-gopher \
						--disable-imap --disable-pop3 --disable-smtp --disable-telnet --disable-tftp --disable-rtsp  
curl:	
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done
	cp $(CURL_DIR_PATH)/$(CURL_DIR)/src/curl $(CURL_DIR_PATH)/binary
	
	 
libcurl_conf:
	cd $(CURL_DIR); \
	./configure --host=$(HOST)  CC=$(CROSS_COMPILE)gcc --enable-shared --with-ssl --disable-manual --disable-proxy --without-zlib \
						--disable-cookies --disable-ipv6 --disable-dict --disable-file --disable-ftp --disable-gopher \
						--disable-imap --disable-pop3 --disable-smtp --disable-telnet --disable-tftp --disable-rtsp  
libcurl:
	for i in ${SUBDIRS}; do \
		(cd $$i; make) || exit 1; \
	done
	cp $(CURL_DIR_PATH)/$(CURL_DIR)/lib/.libs/libcurl.* $(CURL_DIR_PATH)/binary	

sub_clean:
	cd $(CURL_DIR); \
	for i in ${SUBDIRS}; do \
		(cd $$i; make clean); \
	done

clean: curl_conf sub_clean libcurl_conf sub_clean
	rm -rf $(CURL_DIR_PATH)/binary/*
	rm -rf $(TARGETDIR)/sbin/curl
	rm -rf $(TARGETDIR)/usr/lib/libcurl.*
install:
#	$(CROSS_COMPILE)strip $(CURL_DIR_PATH)/binary/curl
	install -d $(TARGETDIR)/sbin/
	install -m 755 $(CURL_DIR_PATH)/binary/curl $(TARGETDIR)/sbin
	install -m 755 $(CURL_DIR_PATH)/binary/libcurl.*  $(TARGETDIR)/usr/lib


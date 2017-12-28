#
# Samba Makefile
#
# $ Copyright Open Broadcom Corporation 2010 $
#
# $Id: Makefile,v 1.6 2010-07-17 02:57:34 kenlo Exp $
#

include ../config.mk
include ../config.in

export SAMBA_TOP := $(shell pwd)

SAMBA_SRC=source

CFLAGS += -DLINUX

DIRS := ${SAMBA_SRC}

.PHONY: all
all: samba

.PHONY: configure
configure:
	[ -f $(SAMBA_SRC)/Makefile ] || \
	(cd $(SAMBA_SRC); \
	 export SMB_BUILD_CC_NEGATIVE_ENUM_VALUES=yes ; \
	 export libreplace_cv_READDIR_GETDIRENTRIES=no ; \
	 export libreplace_cv_READDIR_GETDENTS=no ; \
	 export linux_getgrouplist_ok=no ; \
	 export samba_cv_REPLACE_READDIR=no ; \
	 export samba_cv_HAVE_WRFILE_KEYTAB=yes ; \
	 export samba_cv_HAVE_KERNEL_OPLOCKS_LINUX=yes ; \
	 export samba_cv_HAVE_IFACE_IFCONF=yes ; \
	 export samba_cv_USE_SETRESUID=yes ; \
	 export samba_cv_have_longlong=yes ; \
	 CC=$(CC) ./configure \
	    --target=mips-openwrt-linux \
	    --host=mips-openwrt-linux \
	    --build=`/bin/arch`-linux \
	    --enable-shared \
	    --disable-static \
	    --disable-cups \
	    --disable-iprint \
	    --disable-pie \
	    --disable-fam \
	    --localstatedir=/tmp/samba/lib/ \
	    --with-configdir=/usr/local/samba/lib/ \
	    --with-privatedir=/usr/local/samba/private \
	    --with-lockdir=/usr/local/samba/var/locks \
	    --with-piddir=/usr/local/samba/var/locks \
	    --without-ldap \
	    --without-sys-quotas \
	    --without-cifsmount \
	    samba_cv_have_longlong=yes \
	    --prefix=/usr/local/samba; \
	)

.PHONY: samba
samba: configure headers
	+$(MAKE) -C $(SAMBA_SRC)

.PHONY: headers
headers: configure
	+$(MAKE) -C $(SAMBA_SRC) headers

.PHONY: install
install: all
	install -d $(TARGET_DIR)/usr/local/
	install -d $(TARGET_DIR)/usr/local/samba
	install -d $(TARGET_DIR)/usr/local/samba/lib
	install -d $(TARGET_DIR)/var/samba/
	install -d $(TARGET_DIR)/var/samba/private
	install -d $(TARGET_DIR)/etc
	install -m 755 $(SAMBA_SRC)/../data/group $(TARGET_DIR)/etc
	install -m 755 $(SAMBA_SRC)/../data/lmhosts $(TARGET_DIR)/usr/local/samba/lib
	install -m 755 $(SAMBA_SRC)/bin/smb_pass  $(TARGET_DIR)/usr/local/samba/
	install -m 755 $(SAMBA_SRC)/bin/nmbd  $(TARGET_DIR)/usr/local/samba/
	install -m 755 $(SAMBA_SRC)/bin/smbd  $(TARGET_DIR)/usr/local/samba/
	$(STRIP) $(TARGET_DIR)/usr/local/samba/smbd
	$(STRIP) $(TARGET_DIR)/usr/local/samba/nmbd
	$(STRIP) $(TARGET_DIR)/usr/local/samba/smb_pass
	cd $(TARGET_DIR)/usr/local/samba && unlink  private || pwd
	cd $(TARGET_DIR)/usr/local/samba && unlink  var || pwd
	cd $(TARGET_DIR)/usr/local/samba && unlink  lock || pwd
	cd $(TARGET_DIR)/usr/local/samba && ln -sf ../../../var/samba/private private
	cd $(TARGET_DIR)/usr/local/samba && ln -sf ../../../var var
	cd $(TARGET_DIR)/usr/local/samba && ln -sf ../../../var/lock lock
	cd $(TARGET_DIR)/usr/local/samba/lib && ln -sf ../../../../tmp/samba/private/smb.conf smb.conf
#	cd $(TARGET_DIR)/etc && unlink passwd || pwd
#	cd $(TARGET_DIR)/etc && ln -sf ../tmp/samba/private/passwd passwd

install-%:
	+$(MAKE) -C $(patsubst install-%,%,$@) install

.PHONY: clean
clean: $(addprefix clean-,${DIRS})

.PHONY: $(addprefix clean-,${DIRS})
$(addprefix clean-,${DIRS}):
	+$(MAKE) -C $(patsubst clean-%,%,$@) clean

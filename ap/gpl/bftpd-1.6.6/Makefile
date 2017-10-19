# Generated automatically from Makefile.in by configure.

include ../config.mk
include ../config.in

VERSION=1.6.6
CFLAGS += -O2 -DHAVE_CONFIG_H -Wall -I. -DVERSION=\"$(VERSION)\" -D_LARGEFILE_SOURCE -DQUICK_FIX_ISSUES -ULEAN
all: bftpd
LIBS= -lcrypt

HEADERS=bftpdutmp.h commands.h commands_admin.h cwd.h dirlist.h list.h login.h logging.h main.h mystring.h options.h targzip.h mypaths.h
OBJS=bftpdutmp.o commands.o commands_admin.o cwd.o dirlist.o list.o login.o logging.o main.o mystring.o options.o
SRCS=bftpdutmp.c commands.c commands_admin.c cwd.c dirlist.c list.c login.c logging.c main.c mystring.c options.c

LDFLAGS=-Wl,-allow-shlib-undefined
LDFLAGS	+= -L$(ACOSTOPDIR)/nvram -lnvram 
LDFLAGS += -L$(ACOSTOPDIR)/shared -lacos_shared
CFLAGS	+= -I. -I$(ACOSTOPDIR)/include

LIB_OPENSSLDIR= $(BUILD_DIR)/openssl-1.0.2h
CFLAGS += -I$(LIB_OPENSSLDIR)/include
LDFLAGS += -L$(LIB_OPENSSLDIR) -lssl -lcrypto

bftpd: $(OBJS)
	./mksources $(DIRPAX)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o bftpd

install:
	$(STRIP) bftpd
	#install -m 755 bftpd $(TARGET_DIR)/bin
	install -m 755 bftpd $(TARGET_DIR)/usr/sbin
	#$(STRIP) $(TARGET_DIR)/bin/bftpd
	#cp -af bftpd.conf $(TARGET_DIR)/etc

clean:
	-rm -f bftpd $(OBJS) mksources.finished config.cache
	rm -f $(TARGET_DIR)/bin/bftpd
	#rm -f $(TARGETDIR)/etc/bftpd.conf


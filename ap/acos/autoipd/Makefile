
include ../config.in
include ../config.mk

CFLAGS	+= -I. -I$(ACOSTOPDIR)/nvram -I$(ACOSTOPDIR)/shared -I$(ACOSTOPDIR)/include -Wall
CFLAGS	+= -D__LINUX__
#CFLAGS	+= -g -DDEBUG
CFLAGS	+= -s -O2


LDFLAGS += -lm
LDFLAGS	+= -L$(ACOSTOPDIR)/nvram -lnvram -L$(STAGING_DIR)/usr/lib 
LDFLAGS	+= -L$(ACOSTOPDIR)/shared -L$(TARGETDIR)/usr/lib -lacos_shared 

ifeq ($(CONFIG_INTEL_SDK),y)
LDFLAGS += -L$(STAGING_DIR)/opt/lantiq/usr/lib
LDFLAGS	+= -L$(STAGING_DIR)/usr/lib 
LDFLAGS	+= -L$(STAGING_DIR)/usr/lib/mcast
LDFLAGS	+= -L$(STAGING_DIR)/lib 
LDFLAGS	+= -L$(TOOLCHAIN_DIR)/usr/lib 
LDFLAGS	+= -L$(TOOLCHAIN_DIR)/lib
LDFLAGS	+= -ldslfapi 
LDFLAGS += -lsysfapi -lethfapi 
LDFLAGS	+= -lhelper -luci -ldl
endif

OBJS := autoipd.o

vpath %.c $(TOP)/shared

all: autoipd

clean:
	rm -f *.o autoipd

install: all
	install -d $(TARGETDIR)/usr/sbin
	install autoipd $(TARGETDIR)/usr/sbin
	$(STRIP) $(TARGETDIR)/usr/sbin/autoipd

email: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


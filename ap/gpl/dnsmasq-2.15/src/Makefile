include ../../config.mk
include ../../config.in

# Uncomment this on Solaris.
#LIBS = -lsocket -lnsl

CFLAGS?= -O2

ifeq ($(MPOE_ENABLE_FLAG),y)
    CFLAGS += -DMULTIPLE_PPPOE
endif

ifeq ($(CONFIG_STATIC_PPPOE),y)
CFLAGS  += -DSTATIC_PPPOE
else
CFLAGS  += -USTATIC_PPPOE
endif

# NO IPv6 support at current stat. Must define, otherwise config.h will define HAVE_IPV6, 
ifneq ($(INCLUDE_IPV6_FLAG),y)
CFLAGS += -DNO_IPV6  
endif

ifeq ($(CONFIG_XDSL_PRODUCT),y)
CFLAGS += -D_XDSL_PRODUCT
endif

#OBJS = cache.o rfc1035.o util.o option.o forward.o isc.o \
#       network.o dnsmasq.o dhcp.o lease.o rfc2131.o 

OBJS = cache.o rfc1035.o util.o option.o forward.o \
       network.o dnsmasq.o 

.c.o: dnsmasq.h config.h 
	$(CC) $(CFLAGS) $(RPM_OPT_FLAGS) -Wall -W -c $*.c 

dnsmasq : $(OBJS) dnsmasq.h config.h
	$(CC) -o $@  $(OBJS) $(LIBS)




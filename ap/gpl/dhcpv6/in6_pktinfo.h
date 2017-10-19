#ifndef IN6_PKTINFO
#define IN6_PKTINFO

struct in6_pktinfo {
    struct in6_addr ipi6_addr;
   int            ipi6_ifindex;
};

#endif

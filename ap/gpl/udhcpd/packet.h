#ifndef _PACKET_H
#define _PACKET_H

#include <netinet/udp.h>
#include <netinet/ip.h>

/* foxconn added start, zacker, 09/18/2009, @big_size_pkt */
#define LEN_OPTIONS 308 /* 312 - sizeof(cookie) */
#define LEN_PADDING 924 /* 1500 - sizeof(udp_dhcp_packet) */
/* foxconn added end, zacker, 09/18/2009, @big_size_pkt */

struct dhcpMessage {
	u_int8_t op;
	u_int8_t htype;
	u_int8_t hlen;
	u_int8_t hops;
	u_int32_t xid;
	u_int16_t secs;
	u_int16_t flags;
	u_int32_t ciaddr;
	u_int32_t yiaddr;
	u_int32_t siaddr;
	u_int32_t giaddr;
	u_int8_t chaddr[16];
	u_int8_t sname[64];
	u_int8_t file[128];
	u_int32_t cookie;
	//u_int8_t options[308]; /* 312 - cookie */ 
	u_int8_t options[LEN_OPTIONS];/* foxconn modified, zacker, 09/18/2009, @big_size_pkt */
};

struct udp_dhcp_packet {
	struct iphdr ip;
	struct udphdr udp;
	struct dhcpMessage data;
};

/* foxconn wklin added start, 10/03/2007 */
/* for dhcp servers sending packet > 576 */
struct udp_dhcp_packet_rcv {
	struct iphdr ip;
	struct udphdr udp;
	struct dhcpMessage data;
	//u_int8_t pad[6];
	u_int8_t pad[LEN_PADDING];/* foxconn modified, zacker, 09/18/2009, @big_size_pkt */
};
/* foxconn wklin added end, 10/03/2007 */
void init_header(struct dhcpMessage *packet, char type);
int get_packet(struct dhcpMessage *packet, int fd);
u_int16_t checksum(void *addr, int count);
int raw_packet(struct dhcpMessage *payload, u_int32_t source_ip, int source_port,
		   u_int32_t dest_ip, int dest_port, unsigned char *dest_arp, int ifindex);
int kernel_packet(struct dhcpMessage *payload, u_int32_t source_ip, int source_port,
		   u_int32_t dest_ip, int dest_port);


#endif

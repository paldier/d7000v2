
#ifndef _MULTISSIDCONTROL_H_
#define _MULTISSIDCONTROL_H_

#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef uint8
#define uint8 unsigned char
#endif
#ifndef uint32
#define uint32 unsigned int
#endif
#ifndef int32
#define int32 int
#endif
#ifndef int8
#define int8 char
#endif

#ifndef int16
#define int16 short
#endif

#define MS_ACCEPT       0
#define MS_DROP         1

#define DNS_PORT          53 /* Foxconn added pling 03/24/2015 */
#define DHCP_SERVER_PORT  67
#define DHCP_CLIENT_PORT  68
#define HTTP_PORT         80 /* foxconn added, zacker, 08/11/2009, @mbssid_filter */
#define DHCP6_SERVER_PORT  547
#define DHCP6_CLIENT_PORT  546

/* Foxconn add start, Tony W.Y. Wang, 12/22/2009 @block FTP and Samba access */
#define FTP_PORT1        20
#define FTP_PORT2        21
#define SAMBA_PORT1      137
#define SAMBA_PORT2      138
#define SAMBA_PORT3      139
#define SAMBA_PORT4      445    /*stanley add 01/13/2010 add samba port*/
#define SOAP_API_PORT    5000   /* pling added 10/22/2013, SOAP API port */
#define TELNET_PORT      23     /* Bob added 02/27/2014, telnet port */
#define FBWIFI_PORT      5001   /* pling added 04/15/2015, for Facebook WiFi */

/* For D7000v2 only */
#if defined(AP_MODE)             
#define WAN_IFNAME          "eth1"
#define WL0_GUEST1_IFNAME   "wlan0.0"
#define WL0_GUEST2_IFNAME   "wlan0.1"
#define WL0_GUEST3_IFNAME   "wlan0.2"

#define WL1_GUEST1_IFNAME   "wlan1.0"
#define WL1_GUEST2_IFNAME   "wlan1.1"
#define WL1_GUEST3_IFNAME   "wlan1.2"
#endif /* AP_MODE */
/* For D7000v2 only end. */

/* Foxconn add end, Tony W.Y. Wang, 12/22/2009 */
typedef struct MulitSsidControlProfile {
       char IfName[8];
       int enable;
       unsigned int FilterIP;
#if defined(AP_MODE)
       int apMode;
#endif /* AP_MODE */
#if !defined(_XDSL_PRODUCT) && !defined(CONFIG_INTEL_SDK)
#if defined(VLAN_SUPPORT)
       int vlanIptvMode;
       int bridgeIntf[8];
       int wanIntf[8];
#endif
#endif
}T_MSsidCtlProfile;


#if 0
#define MultiSsidControlDEBUG(fmt, args...)      printk("<0>MultiSsidControlDEBUG: " fmt, ##args)
#define MultiSsidControlERROR       printk("<0>MultiSsidControlERROR: " fmt, ##args)
#else
#define MultiSsidControlDEBUG(fmt, args...)
#define MultiSsidControlERROR
#endif



#endif 

/***************************************************************************
#***
#***    Copyright 2016  Hon Hai Precision Ind. Co. Ltd.
#***    All Rights Reserved.
#***    No portions of this material shall be reproduced in any form without the
#***    written permission of Hon Hai Precision Ind. Co. Ltd.
#***
#***    All information contained in this document is Hon Hai Precision Ind.  
#***    Co. Ltd. company private, proprietary, and trade secret property and 
#***    are protected by international intellectual property laws and treaties.
#***
#****************************************************************************
***
***    Filename: ambitCfg.h
***
***    Description:
***         This file is specific to each project. Every project should have a
***    different copy of this file.
***        Included from ambit.h which is shared by every project.
***
***    History:
***
***	   Modify Reason		                                        Author		         Date		                Search Flag(Option)
***	--------------------------------------------------------------------------------------
***    File Creation                                            
*******************************************************************************/


#ifndef _AMBITCFG_H
#define _AMBITCFG_H

#define WW_VERSION           1 /* WW SKUs */
#define NA_VERSION           2 /* NA SKUs */
#define JP_VERSION           3
#define GR_VERSION           4
#define PR_VERSION           5
#define KO_VERSION           6
#define RU_VERSION           7
#define SS_VERSION           8
#define PT_VERSION           9
#define TWC_VERSION          10
#define BRIC_VERSION         11
#define SK_VERSION           12

#define WLAN_REGION          WW_VERSION
#define FW_REGION            WW_VERSION   /* true f/w region */
 
/*formal version control*/
#define AMBIT_HARDWARE_VERSION     "U12L358T00"
#define AMBIT_SOFTWARE_VERSION     "V1.0.0.45"
#define AMBIT_UI_VERSION           "1.0.1"
#define STRING_TBL_VERSION         "1.0.0.40_3.1.2.5"

#define AMBIT_PRODUCT_NAME_GENIE    "D7000v2"
#define AMBIT_PRODUCT_NAME          "D7000v2"
#define AMBIT_PRODUCT_ALIAS_TRI     "Nighthawk"
#define AMBIT_PRODUCT_DESCRIPTION   "Nighthawk AC1900 WiFi VDSL/ADSL Modem Router D7000v2"
#define UPnP_MODEL_URL              "D7000v2.aspx"
#define UPnP_MODEL_DESCRIPTION      "802.11ac"

#define AMBIT_NVRAM_VERSION  "1" /* digital only */

#ifdef AMBIT_UPNP_SA_ENABLE /* Jasmine Add, 10/24/2006 */
#define SMART_WIZARD_SPEC_VERSION "0.7"  /* This is specification version of smartwizard 2.0 */
#endif

#define KWILT_VERSION "20150818"
#define KWILT_TARBALL_SIZE  6580335

/****************************************************************************
 * Board-specific defintions 
 *
 ****************************************************************************/
#define LINUX_VERSION	"3.10.102"
#define ETHERNET_LAN_IF_NAMES	"eth0_1 eth0_3 eth0_4 eth1"   /* Intel solution */
#define ETHERNET_NAME_NUM            "eth1"      /* Ethernet-WAN number*/
#define WAN_IF_NAME_NUM              "nas0"
#define LAN_IF_NAME_NUM              "eth0_1"
#define LAN2_IF_NAME_NUM             "eth0_2"
#define LAN3_IF_NAME_NUM             "eth0_4"
#define LAN4_IF_NAME_NUM             "eth1"
#define WLAN_IF_NAME_NUM             "wlan0"       /* Mulitple BSSID #1 == Primary SSID */
#if defined(INCLUDE_DUAL_BAND)
#define WLAN_N_IF_NAME_NUM           "wlan1" 
#endif /* WLAN_5G_BAND */
#define WDS_IF_NAME_NUM              "wds0.1"    /* WDS interface */

#define BR_IF_NAME                   "br-lan"
#define ETH_WAN_IF                   "eth1"
#define WAN_IFX_NUM_MAX             (8)     //support max 8 wan interface...
/* Foxconn add start by aspen Bai, 11/13/2008 */
#ifdef MULTIPLE_SSID
#define MIN_BSSID_NUM       2
#define MAX_BSSID_NUM       4

#define WLAN_BSS1_NAME_NUM          "wlan0.0"     /* Multiple BSSID #2 */
#define WLAN_BSS2_NAME_NUM          "wlan0.1"     /* Multiple BSSID #3 */
#define WLAN_BSS3_NAME_NUM          "wlan0.2"     /* Multiple BSSID #4 */

#if defined(INCLUDE_DUAL_BAND)
#define WLAN_5G_BSS1_NAME_NUM       "wlan1.0"     /* Multiple BSSID #2 */
#define WLAN_5G_BSS2_NAME_NUM       "wlan1.1"     /* Multiple BSSID #3 */
#define WLAN_5G_BSS3_NAME_NUM       "wlan1.2"     /* Multiple BSSID #4 */


#endif /* INCLUDE_DUAL_BAND */
#endif /* MULTIPLE_SSID */

#define NUM_WAN_INTERFACE       2 //D6400
#define NUM_LAN_INTERFACE       4
#define NUM_INTERFACE_GROUPS    4
#define NUM_VLAN_GROUPS         4

/* GPIO definitions */
#define GPIO_RESET_BUTTON       0 
#define GPIO_WPS_BUTTON         30 
#define GPIO_WIFI_BUTTON        33  

#define GPIO_USB1_LED           1  /* 2.0 */
#define GPIO_USB2_LED           31  /* 3.0 */
#define GPIO_USB1_LED_STR       "1"
#define GPIO_USB2_LED_STR       "31"

#define GPIO_INTERNET_ACT_LED   10   
#define GPIO_INTERNET_FAIL_LED  9  

#define GPIO_POWER_GREEN_LED    34
#define GPIO_POWER_LED_GREEN_STR    "34"
#define GPIO_POWER_RED_LED      8
#define GPIO_POWER_LED_AMBER_STR    "8"

#define GPIO_XDSL1_LED          32
#define GPIO_24G_LED            28
#define GPIO_5G_LED             29
#define WPS_LED_GPIO            4
#define GPIO_WIFI_LED           6
#define GPIO_WIFI_BUTTON_LED    6

#define GPIO_FE_LAN1            11
#define GPIO_GIGA_LAN1          15
#define GPIO_FE_LAN2            21
#define GPIO_GIGA_LAN2          22
#define GPIO_FE_LAN3            35
#define GPIO_GIGA_LAN3          36
#define GPIO_FE_LAN4            42
#define GPIO_GIGA_LAN4          43

#define GPIO_USB1_ENABLE        2

#define LED_ON                  0
#define LED_OFF                 1


#if 1
#define enable_usb_ports()
#define disable_usb_ports()
#else
#define enable_usb_ports() { \
     system("gpio 2 1"); \
    }

#define disable_usb_ports() { \
     system("gpio 2 0"); \
    }
#endif

#define LANG_TBL_MTD_RD             "/dev/mtdblock"
#define LANG_TBL_MTD_WR             "/storage1/string_table_"



#if defined(X_ST_ML)
#define ST_SUPPORT_NUM            (10)        /* The maxium value can be 2-10. */
#define LANG_TBL_MTD_START        (1)
#define LANG_TBL_MTD_END          (ST_SUPPORT_NUM+LANG_TBL_MTD_START-1)
#define FLASH_MTD_ML_SIZE           0x20000   /* 128k */
#define BUILTIN_LANGUAGE          "English"
#define BUILTIN_GERMAN            "German"

#if defined(NAND_STRING_TABLE) || defined(D7000v2) || defined(D6220v2)

#define NAND_STRING_TABLE_1_FILE 	"/storage1/string_table_1"
#define NAND_STRING_TABLE_2_FILE 	"/storage1/string_table_2"
#define NAND_STRING_TABLE_3_FILE 	"/storage1/string_table_3"
#define NAND_STRING_TABLE_4_FILE 	"/storage1/string_table_4"
#define NAND_STRING_TABLE_5_FILE 	"/storage1/string_table_5"
#define NAND_STRING_TABLE_6_FILE 	"/storage1/string_table_6"
#define NAND_STRING_TABLE_7_FILE 	"/storage1/string_table_7"
#define NAND_STRING_TABLE_8_FILE 	"/storage1/string_table_8"
#define NAND_STRING_TABLE_9_FILE 	"/storage1/string_table_9"
#define NAND_STRING_TABLE_10_FILE 	"/storage1/string_table_10"
#define NAND_STRING_TABLE_11_FILE 	"/storage1/string_table_11"

#define ML1_MTD_RD                  "/storage1/string_table_1"
#define ML1_MTD_WR                  "/storage1/string_table_1"
#define ML2_MTD_RD                  "/storage1/string_table_2"
#define ML2_MTD_WR                  "/storage1/string_table_2"
#define ML3_MTD_RD                  "/storage1/string_table_3"
#define ML3_MTD_WR                  "/storage1/string_table_3"
#define ML4_MTD_RD                  "/storage1/string_table_4"
#define ML4_MTD_WR                  "/storage1/string_table_4"
#define ML5_MTD_RD                  "/storage1/string_table_5"
#define ML5_MTD_WR                  "/storage1/string_table_5"
#define ML6_MTD_RD                  "/storage1/string_table_6"
#define ML6_MTD_WR                  "/storage1/string_table_6"
#define ML7_MTD_RD                  "/storage1/string_table_7"
#define ML7_MTD_WR                  "/storage1/string_table_7"
#define ML8_MTD_RD                  "/storage1/string_table_8"
#define ML8_MTD_WR                  "/storage1/string_table_8"
#define ML9_MTD_RD                  "/storage1/string_table_9"
#define ML9_MTD_WR                  "/storage1/string_table_9"
#define ML10_MTD_RD                 "/storage1/string_table_10"
#define ML10_MTD_WR                 "/storage1/string_table_10"
#endif

#define NAND_POT_FILE				"/storage2/POT" 
#define NAND_TRAFFIC_METER_1_FILE	"/storage1/traffic_meter_1"
#define NAND_TRAFFIC_METER_2_FILE	"/storage1/traffic_meter_2"

#define BD_MTD_RD                   "/dev/mtdblock7"
#define BD_MTD_WR                   "/dev/mtd7"

#define NVRAM_MTD_RD                "/dev/mtdblock6"
#define NVRAM_MTD_WR                "/dev/mtd6"
#endif /*#if defined(X_ST_ML)*/


#define KERNEL_MTD_RD               "/dev/mtdblock26"
#define KERNEL_MTD_WR               "/dev/mtd26"

#define ROOTFS_MTD_RD               "/dev/mtdblock27"
#define ROOTFS_MTD_WR               "/dev/mtd27"

#define QOS_MTD_RD                 	"/dev/mtdblock21"   /* use MISC1 first*/
#define QOS_MTD_WR                 	"/dev/mtd21"

/* Foxconn added start, Sinclair, 04/17/2014@ reuse MTD16 in R7300 */
//#if !defined(VIDEO_STREAMING_QOS)
#define DEBUG_MSG_MTD               "mtd19"
#define DEBUG_MSG_MTD_RD            "/dev/mtdblock19"
#define DEBUG_MSG_MTD_WR            "/dev/mtd19"

#define OPENVPN_MTD               "mtd20"
#define OPENVPN_MTD_RD            "/dev/mtdblock20"
#define OPENVPN_MTD_WR            "/dev/mtd20"
//#endif      /* VIDEO_STREAMING_QOS */


#define FS_UNZIP_LANG_TBL    "/www/string_table_d7000v2"
#define FS_ZIP_LANG_TBL      "/tmp/string_table_d7000v2.bz2"

/* wklin added start, 11/22/2006 */
/* The following definition is used in acosNvramConfig.c and acosNvramConfig.h
 * to distingiush between Foxconn's and Broadcom's implementation.
 */
#define BRCM_NVRAM          /* use broadcom nvram instead of ours */

/* The following definition is to used as the key when doing des
 * encryption/decryption of backup file.
 * Have to be 7 octects.
 */
#define BACKUP_FILE_KEY         "NtgrBak"
/* wklin added end, 11/22/2006 */

/* Foxconn Perry added start, 2011/04/13, for document URL */
#define DOCUMENT_URL		"http://documentation.netgear.com/d7000v2/enu/202-10581-01/index.htm"
/* Foxconn Perry added end, 2011/04/13, for document URL */

/* Foxconn Perry added start, 2011/08/17, for USB Support level */
#define USB_support_level        "29" /* bit 1: basic,  bit 2: Cloud, bit 3: Printer, bit 4: Vault */
/* Foxconn Perry added end, 2011/08/17, for USB Support level */


#define WIRELESS_SETTINGS_PAGE                  "WLG_wireless_dual_band_r10.htm"
#define WIRELESS_GUEST_SETTINGS_PAGE            "WLG_wireless_dual_band_2.htm"
#define WIRELESS_ADV_SETTINGS_PAGE              "WLG_adv_dual_band2.htm"

#define STATUS_DUAL_BAND_PAGE                   "ADVANCED_home2.htm"
#define STATUS_TRI_BAND_PAGE                    "ADVANCED_home2_tri_band.htm"


#define CE_DFS_ENABLE       "0"
#define FCC_DFS_ENABLE      "0"
#define TELEC_DFS_ENABLE    "0"

#define KERNEL_MODULE_PATH "/lib/modules/3.10.102/extra"

/* 
 * It could be a good practice to define these
 * project dependent macro in your ambigCfg.h
 */

#define FLASH_SIZE      (96*1024*1024)
#define MAX_SIZE_FILE   96*1024*1024
#define MAX_SIZE_KERNEL (MAX_SIZE_FILE)
#define MAX_SIZE_ROOTFS (MAX_SIZE_FILE)
#define MAX_SIZE_FILE_OPENSOURCE    MAX_SIZE_FILE
#define MAX_SIZE_KERNEL_OPENSOURCE  MAX_SIZE_FILE
#define MAX_SIZE_ROOTFS_OPENSOURCE  MAX_SIZE_FILE
#define BOARD_ID_OPENSOURCE         "U12L358T00_OPENSOURCE"
#define OPENSOURCE_START_MTD_IDX    (1)
#define OPENSOURCE_END_MTD_IDX      (1)

#define IMAGE_BLOCK_SIZE        0x20000
#define MAX_IMAGE_SIZE  MAX_SIZE_FILE

#endif /*_AMBITCFG_H*/

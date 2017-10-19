/* 
  GPL LICENSE SUMMARY

  Copyright(c) 2013-2013 Intel Corporation.

  This program is free software; you can redistribute it and/or modify 
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but 
  WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  General Public License for more details.

  You should have received a copy of the GNU General Public License 
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution 
  in the file called LICENSE.GPL.

  Contact Information:
    Intel Corporation
    2200 Mission College Blvd.
    Santa Clara, CA  97052
*/

/***************************************************************************/

/*! \file carnoutils.h
    \brief Exported utils

****************************************************************************/

#ifndef _CARNOUTILS_H_
#define _CARNOUTILS_H_

/**************************************************************************/
/*      INCLUDES                                                          */
/**************************************************************************/

#include <stdio.h>

/**************************************************************************/
/*      INTERFACE  Defines and Structs                                    */
/**************************************************************************/

#define DBG(format, args...) printf("%s - %d: " format "\n", __func__, __LINE__, ##args)
#define DBGVAR(__var) DBG(#__var " |%s|", __var) 

#define stringcat(__s1, __s2, __ss...) stringcat_null(__s1, __s2, ##__ss, NULL)

#define FREE(__p) if (__p) {free(__p); __p = NULL;}
#define STRINGCAT(__to_str1, __str2, args...) \
    do { \
        char *n = NULL; \
        n = __to_str1; \
        __to_str1 = stringcat(__to_str1, __str2, ##args); \
        FREE(n); \
    } while (0)

/**************************************************************************/
/*      EXTERN definition block                                           */
/**************************************************************************/

#define SYSOUTDBGON DBG_sysoutDebug = 1;
#define SYSOUTDBGOFF DBG_sysoutDebug = 0;

extern int DBG_sysoutDebug;
extern int DBG_stringcatDebug;
extern int DBG_getfield;

/**************************************************************************/
/*      INTERFACE VARIABLES (prefix with EXTERN)                          */
/**************************************************************************/

extern char *ARNO_IPTABLESBATCH_VERBOSE;

/**************************************************************************/
/*      INTERFACE FUNCTIONS Prototypes:                                   */
/**************************************************************************/

extern char *sysout(char *cmd, int *retval);
extern char *stringcat_null(char *, char*, ...);
extern char *stringcatn(char *s1, char *s2, int s2_len);
extern char *getfield(char *src, char *sep, int field_num);
extern char *tr(char *src, char *org, char *repl);

extern int iptables(char *inarg, ...);
extern int ip6tables(char *inarg, ...);
extern int ip4tables(char *inarg, ...);

/* Auto generated into - carno.c */
extern void env_init(void);

#endif


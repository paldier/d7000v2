/*	$Id: common.h,v 1.2 2008/11/20 21:41:03 Exp $	*/
/*	ported from KAME: common.h,v 1.29 2002/06/11 08:24:34 jinmei Exp */

/*
 * Copyright (C) 1998 and 1999 WIDE Project.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#define IN6_IFF_INVALID -1

/* ANSI __func__ can not be concatantated (C99 std) */
#if defined(HAVE_GCC_FUNCTION)
#define FNAME __FUNCTION__ ":"
#else
#define FNAME ""
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

extern int foreground;
extern int debug_thresh;

/* common.c */
extern int set_dhcp6c_flags(u_int32_t flags);   // Foxconn added pling 09/21/2010

extern int dhcp6_copy_list __P((struct dhcp6_list *, const struct dhcp6_list *));
extern void dhcp6_clear_list __P((struct dhcp6_list *));
extern int dhcp6_count_list __P((struct dhcp6_list *));
extern struct dhcp6_listval *dhcp6_find_listval __P((struct dhcp6_list *,
							void *,
							dhcp6_listval_type_t));
extern struct dhcp6_listval *dhcp6_add_listval __P((struct dhcp6_list *,
						       void *,
						       dhcp6_listval_type_t));
extern struct dhcp6_event *dhcp6_create_event __P((struct dhcp6_if *, int));
extern void dhcp6_remove_event __P((struct dhcp6_event *));
extern int getifaddr __P((struct in6_addr *, char *, struct in6_addr *,
			  int, int, int));
extern int transmit_sa __P((int, struct sockaddr_in6 *, char *, size_t));
extern long random_between __P((long, long));
extern int prefix6_mask __P((struct in6_addr *, int));
extern int sa6_plen2mask __P((struct sockaddr_in6 *, int));
extern char *addr2str __P((struct sockaddr *));
extern char *in6addr2str __P((struct in6_addr *, int));
extern const char *getdev __P((struct sockaddr_in6 *));
extern int in6_addrscopebyif __P((struct in6_addr *, char *));
extern int in6_scope __P((struct in6_addr *));
extern void setloglevel __P((int));
#ifdef	__GNUC__
extern void dprintf2(int, const char *, ...)
	__attribute__ ((__format__(__printf__, 2, 3)));
#else
extern void dprintf2 __P((int, const char *, ...));
#endif

extern int get_duid __P((const char *, const char *, struct duid *));
extern void dhcp6_init_options __P((struct dhcp6_optinfo *));
extern void dhcp6_clear_options __P((struct dhcp6_optinfo *));
extern int dhcp6_copy_options __P((struct dhcp6_optinfo *,
				   struct dhcp6_optinfo *));
/* Foxconn modified start pling 10/04/2010 */
//extern int dhcp6_get_options __P((struct dhcp6opt *, struct dhcp6opt *,
//				  struct dhcp6_optinfo *));
extern int dhcp6_get_options __P((struct dhcp6opt *, struct dhcp6opt *,
                  struct dhcp6_optinfo *, int, int, int));
/* Foxconn modified end pling 10/04/2010 */
extern int dhcp6_set_options __P((struct dhcp6opt *, struct dhcp6opt *,
				  struct dhcp6_optinfo *));
extern void dhcp6_set_timeoparam __P((struct dhcp6_event *));
extern void dhcp6_reset_timer __P((struct dhcp6_event *));
extern char *dhcp6optstr __P((int));
extern char *dhcp6msgstr __P((int));
extern char *dhcp6_stcodestr __P((int));
extern char *duidstr __P((const struct duid *));
extern int duidcpy __P((struct duid *, const struct duid *));
extern int duidcmp __P((const struct duid *, const struct duid *));
extern void duidfree __P((struct duid *));
extern void relayfree __P((struct relay_list *));
extern void ifinit __P((const char *));
extern int configure_duid __P((const char *, struct duid *));
extern struct dhcp6_if *find_ifconfbyname __P((const char *));
extern struct dhcp6_if *find_ifconfbyid __P((unsigned int));
extern struct prefix_ifconf *find_prefixifconf __P((const char *));
extern struct host_conf *find_hostconf __P((const struct duid *));

#define __CONFIG_UCLIBC__ 1
#if defined(__CONFIG_UCLIBC__)     /* Use macro instead for uClibc. */
#define warn(format, ...) do { fprintf(stderr, format "\n", ##__VA_ARGS__); } while(0)
#define warnx(format, ...) do { fprintf(stderr, format "\n", ##__VA_ARGS__); } while(0)

#define err(rc, format, ...) do { fprintf(stderr, format "\n", ##__VA_ARGS__); exit(rc); } while(0)
#define errx(rc, format, ...) do { fprintf(stderr, format "\n", ##__VA_ARGS__); exit(rc); } while(0)
#endif

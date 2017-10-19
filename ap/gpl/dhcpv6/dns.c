/*  
 * Copyright (c) 1985, 1993  
 *    The Regents of the University of California.  All rights reserved.  
 *   
 * Redistribution and use in source and binary forms, with or without  
 * modification, are permitted provided that the following conditions  
 * are met:  
 * 1. Redistributions of source code must retain the above copyright  
 *    notice, this list of conditions and the following disclaimer.  
 * 2. Redistributions in binary form must reproduce the above copyright  
 *    notice, this list of conditions and the following disclaimer in the  
 *    documentation and/or other materials provided with the distribution.  
 * 4. Neither the name of the University nor the names of its contributors  
 *    may be used to endorse or promote products derived from this software  
 *    without specific prior written permission.  
 *   
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  
 * SUCH DAMAGE.  
 */  
  
/*  
 * Portions Copyright (c) 1993 by Digital Equipment Corporation.  
 *   
 * Permission to use, copy, modify, and distribute this software for any  
 * purpose with or without fee is hereby granted, provided that the above  
 * copyright notice and this permission notice appear in all copies, and that  
 * the name of Digital Equipment Corporation not be used in advertising or  
 * publicity pertaining to distribution of the document or software without  
 * specific, written prior permission.  
 *   
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  
 * SOFTWARE.  
 */  
  
/*  
 * Portions Copyright (c) 1996-1999 by Internet Software Consortium.  
 *  
 * Permission to use, copy, modify, and distribute this software for any  
 * purpose with or without fee is hereby granted, provided that the above  
 * copyright notice and this permission notice appear in all copies.  
 *  
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  
 * SOFTWARE.  
 */  
  
/*  
 * Copyright (c) 1996,1999 by Internet Software Consortium.  
 *  
 * Permission to use, copy, modify, and distribute this software for any  
 * purpose with or without fee is hereby granted, provided that the above  
 * copyright notice and this permission notice appear in all copies.  
 *  
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  
 * SOFTWARE.  
 */  
  
/*  
 *  
 * DNS helper functions not implemented in uclibc  
 *  
 */  
  
  
#include <sys/types.h>  
#include <sys/param.h>  
#include <netinet/in.h>  
#include <arpa/nameser.h>  
#include <ctype.h>  
#include <resolv.h>  
#include <stdio.h>  
#include <string.h>  
#include <unistd.h>  
  
static const char       digits[] = "0123456789";  
  
/* Forward. */  
  
static int              special(int);  
static int              printable(int);  
static int              dn_find(const u_char *, const u_char *,  
                                const u_char * const *,  
                                const u_char * const *);  
  
  

/*  
 * ns_name_pton(src, dst, dstsiz)  
 *      Convert a ascii string into an encoded domain name as per RFC1035.  
 * return:  
 *      -1 if it fails  
 *      1 if string was fully qualified  
 *      0 is string was not fully qualified  
 * notes:  
 *      Enforces label and domain length limits.  
 */  
  
int  
__ns_name_pton(const char *src, u_char *dst, size_t dstsiz) {  
        u_char *label, *bp, *eom;  
        int c, n, escaped;  
        char *cp;  
  
        escaped = 0;  
        bp = dst;  
        eom = dst + dstsiz;  
        label = bp++;  
  
        while ((c = *src++) != 0) {  
                if (escaped) {  
                        if ((cp = strchr(digits, c)) != NULL) {  
                                n = (cp - digits) * 100;  
                                if ((c = *src++) == 0 ||  
                                    (cp = strchr(digits, c)) == NULL) {  
                                        return (-1);  
                                }  
                                n += (cp - digits) * 10;  
                                if ((c = *src++) == 0 ||  
                                    (cp = strchr(digits, c)) == NULL) {  
                                        return (-1);  
                                }  
                                n += (cp - digits);  
                                if (n > 255) {  
                                        return (-1);  
                                }  
                                c = n;  
                        }  
                        escaped = 0;  
                } else if (c == '\\') {  
                        escaped = 1;  
                        continue;  
                } else if (c == '.') {  
                        c = (bp - label - 1);  
                        if ((c & NS_CMPRSFLGS) != 0) {  /* Label too big. */  
                                return (-1);  
                        }  
                        if (label >= eom) {  
                                return (-1);  
                        }  
                        *label = c;  
                        /* Fully qualified ? */  
                        if (*src == '\0') {  
                                if (c != 0) {  
                                        if (bp >= eom) {  
                                                return (-1);  
                                        }  
                                        *bp++ = '\0';  
                                }  
                                if ((bp - dst) > MAXCDNAME) {  
                                        return (-1);  
                                }  
                                return (1);  
                        }  
                        if (c == 0 || *src == '.') {  
                                return (-1);  
                        }  
                        label = bp++;  
                        continue;  
                }  
                if (bp >= eom) {  
                        return (-1);  
                }  
                *bp++ = (u_char)c;  
        }  
        c = (bp - label - 1);  
        if ((c & NS_CMPRSFLGS) != 0) {          /* Label too big. */  
                return (-1);  
        }  
        if (label >= eom) {  
                return (-1);  
        }  
        *label = c;  
        if (c != 0) {  
                if (bp >= eom) {  
                        return (-1);  
                }  
                *bp++ = 0;  
        }  
        if ((bp - dst) > MAXCDNAME) {   /* src too big */  
                return (-1);  
        }  
        return (0);  
}  
  
/*  
 * ns_name_ntol(src, dst, dstsiz)  
 *      Convert a network strings labels into all lowercase.  
 * return:  
 *      Number of bytes written to buffer, or -1 (with errno set)  
 * notes:  
 *      Enforces label and domain length limits.  
 */  
  
int  
__ns_name_ntol(const u_char *src, u_char *dst, size_t dstsiz) {  
        const u_char *cp;  
        u_char *dn, *eom;  
        u_char c;  
        u_int n;  
  
        cp = src;  
        dn = dst;  
        eom = dst + dstsiz;  
  
        while ((n = *cp++) != 0) {  
                if ((n & NS_CMPRSFLGS) != 0) {  
                        /* Some kind of compression pointer. */  
                        return (-1);  
                }  
                *dn++ = n;  
                if (dn + n >= eom) {  
                        return (-1);  
                }  
                for ((void)NULL; n > 0; n--) {  
                        c = *cp++;  
                        if (isupper(c))  
                                *dn++ = tolower(c);  
                        else  
                                *dn++ = c;  
                }  
        }  
        *dn++ = '\0';  
        return (dn - dst);  
}  
  
/*  
 * ns_name_pack(src, dst, dstsiz, dnptrs, lastdnptr)  
 *      Pack domain name 'domain' into 'comp_dn'.  
 * return:  
 *      Size of the compressed name, or -1.  
 * notes:  
 *      'dnptrs' is an array of pointers to previous compressed names.  
 *      dnptrs[0] is a pointer to the beginning of the message. The array  
 *      ends with NULL.  
 *      'lastdnptr' is a pointer to the end of the array pointed to  
 *      by 'dnptrs'.  
 * Side effects:  
 *      The list of pointers in dnptrs is updated for labels inserted into  
 *      the message as we compress the name.  If 'dnptr' is NULL, we don't  
 *      try to compress names. If 'lastdnptr' is NULL, we don't update the  
 *      list.  
 */  
int  
__ns_name_pack(const u_char *src, u_char *dst, int dstsiz,  
             const u_char **dnptrs, const u_char **lastdnptr)  
{  
        u_char *dstp;  
        const u_char **cpp, **lpp, *eob, *msg;  
        const u_char *srcp;  
        int n, l, first = 1;  
  
        srcp = src;  
        dstp = dst;  
        eob = dstp + dstsiz;  
        lpp = cpp = NULL;  
        if (dnptrs != NULL) {  
                if ((msg = *dnptrs++) != NULL) {  
                        for (cpp = dnptrs; *cpp != NULL; cpp++)  
                                (void)NULL;  
                        lpp = cpp;      /* end of list to search */  
                }  
        } else  
                msg = NULL;  
  
        /* make sure the domain we are about to add is legal */  
        l = 0;  
        do {  
                n = *srcp;  
                if ((n & NS_CMPRSFLGS) != 0) {  
                        return (-1);  
                }  
                l += n + 1;  
                if (l > MAXCDNAME) {  
                        return (-1);  
                }  
                srcp += n + 1;  
        } while (n != 0);  
  
        /* from here on we need to reset compression pointer array on error */  
        srcp = src;  
        do {  
                /* Look to see if we can use pointers. */  
                n = *srcp;  
                if (n != 0 && msg != NULL) {  
                        l = dn_find(srcp, msg, (const u_char * const *)dnptrs,  
                                    (const u_char * const *)lpp);  
                        if (l >= 0) {  
                                if (dstp + 1 >= eob) {  
                                        goto cleanup;  
                                }  
                                *dstp++ = (l >> 8) | NS_CMPRSFLGS;  
                                *dstp++ = l % 256;  
                                return (dstp - dst);  
                        }  
                        /* Not found, save it. */  
                        if (lastdnptr != NULL && cpp < lastdnptr - 1 &&  
                            (dstp - msg) < 0x4000 && first) {  
                                *cpp++ = dstp;  
                                *cpp = NULL;  
                                first = 0;  
                        }  
                }  
                /* copy label to buffer */  
                if (n & NS_CMPRSFLGS) {         /* Should not happen. */  
                        goto cleanup;  
                }  
                if (dstp + 1 + n >= eob) {  
                        goto cleanup;  
                }  
                memcpy(dstp, srcp, n + 1);  
                srcp += n + 1;  
                dstp += n + 1;  
        } while (n != 0);  
  
        if (dstp > eob) {  
cleanup:  
                if (msg != NULL)  
                        *lpp = NULL;  
                return (-1);  
        }   
        return (dstp - dst);  
}  
  

/*  
 * ns_name_compress(src, dst, dstsiz, dnptrs, lastdnptr)  
 *      Compress a domain name into wire format, using compression pointers.  
 * return:  
 *      Number of bytes consumed in `dst' or -1 (with errno set).  
 * notes:  
 *      'dnptrs' is an array of pointers to previous compressed names.  
 *      dnptrs[0] is a pointer to the beginning of the message.  
 *      The list ends with NULL.  'lastdnptr' is a pointer to the end of the  
 *      array pointed to by 'dnptrs'. Side effect is to update the list of  
 *      pointers for labels inserted into the message as we compress the name.  
 *      If 'dnptr' is NULL, we don't try to compress names. If 'lastdnptr'  
 *      is NULL, we don't update the list.  
 */  
int  
__ns_name_compress(const char *src, u_char *dst, size_t dstsiz,  
                 const u_char **dnptrs, const u_char **lastdnptr)  
{  
        u_char tmp[NS_MAXCDNAME];  
  
        if (ns_name_pton(src, tmp, sizeof tmp) == -1)  
                return (-1);  
        return (ns_name_pack(tmp, dst, dstsiz, dnptrs, lastdnptr));  
}  
  
/*  
 * special(ch)  
 *      Thinking in noninternationalized USASCII (per the DNS spec),  
 *      is this characted special ("in need of quoting") ?  
 * return:  
 *      boolean.  
 */  
static int  
special(int ch) {  
        switch (ch) {  
        case 0x22: /* '"' */  
        case 0x2E: /* '.' */  
        case 0x3B: /* ';' */  
        case 0x5C: /* '\\' */  
        /* Special modifiers in zone files. */  
        case 0x40: /* '@' */  
        case 0x24: /* '$' */  
                return (1);  
        default:  
                return (0);  
        }  
}  
  
/*  
 * printable(ch)  
 *      Thinking in noninternationalized USASCII (per the DNS spec),  
 *      is this character visible and not a space when printed ?  
 * return:  
 *      boolean.  
 */  
static int  
printable(int ch) {  
        return (ch > 0x20 && ch < 0x7f);  
}  
  
/*  
 *      Thinking in noninternationalized USASCII (per the DNS spec),  
 *      convert this character to lower case if it's upper case.  
 */  
static int  
mklower(int ch) {  
        if (ch >= 0x41 && ch <= 0x5A)  
                return (ch + 0x20);  
        return (ch);  
}  
  
/*  
 * dn_find(domain, msg, dnptrs, lastdnptr)  
 *      Search for the counted-label name in an array of compressed names.  
 * return:  
 *      offset from msg if found, or -1.  
 * notes:  
 *      dnptrs is the pointer to the first name on the list,  
 *      not the pointer to the start of the message.  
 */  
static int  
dn_find(const u_char *domain, const u_char *msg,  
        const u_char * const *dnptrs,  
        const u_char * const *lastdnptr)  
{  
        const u_char *dn, *cp, *sp;  
        const u_char * const *cpp;  
        u_int n;  
  
        for (cpp = dnptrs; cpp < lastdnptr; cpp++) {  
                sp = *cpp;  
                /*  
                 * terminate search on:  
                 * root label  
                 * compression pointer  
                 * unusable offset  
                 */  
                while (*sp != 0 && (*sp & NS_CMPRSFLGS) == 0 &&  
                       (sp - msg) < 0x4000) {  
                        dn = domain;  
                        cp = sp;  
                        while ((n = *cp++) != 0) {  
                                /*  
                                 * check for indirection  
                                 */  
                                switch (n & NS_CMPRSFLGS) {  
                                case 0:         /* normal case, n == len */  
                                        if (n != *dn++)  
                                                goto next;  
                                        for ((void)NULL; n > 0; n--)  
                                                if (mklower(*dn++) !=  
                                                    mklower(*cp++))  
                                                        goto next;  
                                        /* Is next root for both ? */  
                                        if (*dn == '\0' && *cp == '\0')  
                                                return (sp - msg);  
                                        if (*dn)  
                                                continue;  
                                        goto next;  
  
                                case NS_CMPRSFLGS:      /* indirection */  
                                        cp = msg + (((n & 0x3f) << 8) | *cp);  
                                        break;  
  
                                default:        /* illegal type */  
                                        return (-1);  
                                }  
                        }  
 next:  
                        sp += *sp + 1;  
                }  
        }  
        return (-1);  
}  
  
/*  
 * Pack domain name 'exp_dn' in presentation form into 'comp_dn'.  
 * Return the size of the compressed name or -1.  
 * 'length' is the size of the array pointed to by 'comp_dn'.  
 */  
int  
__dn_comp(const char *src, u_char *dst, int dstsiz,  
        u_char **dnptrs, u_char **lastdnptr)  
{  
        return (ns_name_compress(src, dst, (size_t)dstsiz,  
                                 (const u_char **)dnptrs,  
                                 (const u_char **)lastdnptr));  
}  
  

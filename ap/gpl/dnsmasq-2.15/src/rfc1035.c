/* dnsmasq is Copyright (c) 2000 Simon Kelley

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 dated June, 1991.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
*/

#include "dnsmasq.h"

static int extract_name(HEADER *header, unsigned int plen, unsigned char **pp, 
			unsigned char *name, int isExtract)
{
  unsigned char *cp = name, *p = *pp, *p1 = NULL;
  unsigned int j, l, hops = 0;
  int retvalue = 1;
  
  while ((l = *p++))
    {
      unsigned int label_type = l & 0xc0;
      if (label_type == 0xc0) /* pointer */
	{ 
	  if (p - (unsigned char *)header + 1u >= plen)
	    return 0;
	      
	  /* get offset */
	  l = (l&0x3f) << 8;
	  l |= *p++;
	  if (l >= (unsigned int)plen) 
	    return 0;
	  
	  if (!p1) /* first jump, save location to go back to */
	    p1 = p;
	      
	  hops++; /* break malicious infinite loops */
	  if (hops > 255)
	    return 0;
	  
	  p = l + (unsigned char *)header;
	}
      else if (label_type == 0x80)
	return 0; /* reserved */
      else if (label_type == 0x40)
	{ /* ELT */
	  unsigned int count, digs;
	  
	  if ((l & 0x3f) != 1)
	    return 0; /* we only understand bitstrings */

	  if (!isExtract)
	    return 0; /* Cannot compare bitsrings */
	  
	  count = *p++;
	  if (count == 0)
	    count = 256;
	  digs = ((count-1)>>2)+1;
	  
	  /* output is \[x<hex>/siz]. which is digs+9 chars */
	  if (cp - name + digs + 9 >= MAXDNAME)
	    return 0;
	  if (p - (unsigned char *)header + ((count-1)>>3) + 1u >= plen)
	    return 0;

	  *cp++ = '\\';
	  *cp++ = '[';
	  *cp++ = 'x';
	  for (j=0; j<digs; j++)
	    {
	      unsigned int dig;
	      if (j%2 == 0)
		dig = *p >> 4;
	      else
		dig = *p++ & 0x0f;
	      
	      *cp++ = dig < 10 ? dig + '0' : dig + 'A' - 10;
	    } 
	  cp += sprintf(cp, "/%d]", count);
	  /* do this here to overwrite the zero char from sprintf */
	  *cp++ = '.';
	}
      else 
	{ /* label_type = 0 -> label. */
	  if (cp - name + l + 1 >= MAXDNAME)
	    return 0;
	  if (p - (unsigned char *)header + 1u >= plen)
	    return 0;
	  for(j=0; j<l; j++, p++)
	    if (isExtract)
	      {
		if (legal_char(*p))
		  *cp++ = *p;
		else
		  return 0;
	      }
	    else 
	      {
		unsigned char c1 = *cp, c2 = *p;
		
		if (c1 == 0)
		  retvalue = 2;
		else 
		  {
		    cp++;
		    if (c1 >= 'A' && c1 <= 'Z')
		      c1 += 'a' - 'A';
		    if (c2 >= 'A' && c2 <= 'Z')
		      c2 += 'a' - 'A';
		    
		    if (c1 != c2)
		      retvalue =  2;
		  }
	      }
	  
	  if (isExtract)
	    *cp++ = '.';
	  else
	    if (*cp != 0 && *cp++ != '.')
	      retvalue = 2;
	}
      
      if ((unsigned int)(p - (unsigned char *)header) >= plen)
	return 0;
    }

  if (isExtract)
    *--cp = 0; /* terminate: lose final period */
  
  if (p1) /* we jumped via compression */
    *pp = p1;
  else
    *pp = p;

  return retvalue;
}
 
/* Max size of input string (for IPv6) is 75 chars.) */
#define MAXARPANAME 75
static int in_arpa_name_2_addr(char *namein, struct all_addr *addrp)
{
  int j;
  char name[MAXARPANAME+1], *cp1;
  unsigned char *addr = (unsigned char *)addrp;
  char *lastchunk = NULL, *penchunk = NULL;
  
  if (strlen(namein) > MAXARPANAME)
    return 0;

  memset(addrp, 0, sizeof(struct all_addr));

  /* turn name into a series of asciiz strings */
  /* j counts no of labels */
  for(j = 1,cp1 = name; *namein; cp1++, namein++)
    if (*namein == '.')
      {
	penchunk = lastchunk;
        lastchunk = cp1 + 1;
	*cp1 = 0;
	j++;
      }
    else
      *cp1 = *namein;
  
  *cp1 = 0;

  if (j<3)
    return 0;

  if (hostname_isequal(lastchunk, "arpa") && hostname_isequal(penchunk, "in-addr"))
    {
      /* IP v4 */
      /* address arives as a name of the form
	 www.xxx.yyy.zzz.in-addr.arpa
	 some of the low order address octets might be missing
	 and should be set to zero. */
      for (cp1 = name; cp1 != penchunk; cp1 += strlen(cp1)+1)
	{
	  /* check for digits only (weeds out things like
	     50.0/24.67.28.64.in-addr.arpa which are used 
	     as CNAME targets according to RFC 2317 */
	  char *cp;
	  for (cp = cp1; *cp; cp++)
	    if (!isdigit((int)*cp))
	      return 0;
	  
	  addr[3] = addr[2];
	  addr[2] = addr[1];
	  addr[1] = addr[0];
	  addr[0] = atoi(cp1);
	}

      return F_IPV4;
    }
#ifdef HAVE_IPV6
  else if (hostname_isequal(penchunk, "ip6") && 
	   (hostname_isequal(lastchunk, "int") || hostname_isequal(lastchunk, "arpa")))
    {
      /* IP v6:
         Address arrives as 0.1.2.3.4.5.6.7.8.9.a.b.c.d.e.f.ip6.[int|arpa]
    	 or \[xfedcba9876543210fedcba9876543210/128].ip6.[int|arpa]
      
	 Note that most of these the various reprentations are obsolete and 
	 left-over from the many DNS-for-IPv6 wars. We support all the formats
	 that we can since there is no reason not to.
      */

      if (*name == '\\' && *(name+1) == '[' && 
	  (*(name+2) == 'x' || *(name+2) == 'X'))
	{	  
	  for (j = 0, cp1 = name+3; *cp1 && isxdigit(*cp1) && j < 32; cp1++, j++)
	    {
	      char xdig[2];
	      xdig[0] = *cp1;
	      xdig[1] = 0;
	      if (j%2)
		addr[j/2] |= strtol(xdig, NULL, 16);
	      else
		addr[j/2] = strtol(xdig, NULL, 16) << 4;
	    }
	  
	  if (*cp1 == '/' && j == 32)
	    return F_IPV6;
	}
      else
	{
	  for (cp1 = name; cp1 != penchunk; cp1 += strlen(cp1)+1)
	    {
	      if (*(cp1+1) || !isxdigit((int)*cp1))
		return 0;
	      
	      for (j = sizeof(struct all_addr)-1; j>0; j--)
		addr[j] = (addr[j] >> 4) | (addr[j-1] << 4);
	      addr[0] = (addr[0] >> 4) | (strtol(cp1, NULL, 16) << 4);
	    }
	  
	  return F_IPV6;
	}
    }
#endif
  
  return 0;
}

static unsigned char *skip_name(unsigned char *ansp, HEADER *header, unsigned int plen)
{
  while(1)
    {
      unsigned int label_type = (*ansp) & 0xc0;
      
      if ((unsigned int)(ansp - (unsigned char *)header) >= plen)
	return NULL;
      
      if (label_type == 0xc0)
	{
	  /* pointer for compression. */
	  ansp += 2;	
	  break;
	}
      else if (label_type == 0x80)
	return NULL; /* reserved */
      else if (label_type == 0x40)
	{
	  /* Extended label type */
	  unsigned int count;
	  
	  if (((*ansp++) & 0x3f) != 1)
	    return NULL; /* we only understand bitstrings */
	  
	  count = *(ansp++); /* Bits in bitstring */
	  
	  if (count == 0) /* count == 0 means 256 bits */
	    ansp += 32;
	  else
	    ansp += ((count-1)>>3)+1;
	}
      else
	{ /* label type == 0 Bottom six bits is length */
	  unsigned int len = (*ansp++) & 0x3f;
	  if (len == 0)
	    break; /* zero length label marks the end. */
	  
	  ansp += len;
	}
    }
  
  return ansp;
}

static unsigned char *skip_questions(HEADER *header, unsigned int plen)
{
  int q, qdcount = ntohs(header->qdcount);
  unsigned char *ansp = (unsigned char *)(header+1);

  for (q = 0; q<qdcount; q++)
    {
      if (!(ansp = skip_name(ansp, header, plen)))
	return NULL;
      ansp += 4; /* class and type */
    }
  if ((unsigned int)(ansp - (unsigned char *)header) > plen) 
     return NULL;
  
  return ansp;
}

int resize_packet(HEADER *header, unsigned int plen, unsigned char *pheader, unsigned int hlen)
{
  int i;
  unsigned char *ansp = skip_questions(header, plen);
  unsigned short rdlen;
  
  if (!ansp)
    return 0;
  
  for (i = 0; 
       i < (ntohs(header->ancount) + ntohs(header->nscount) + ntohs(header->arcount)); 
       i++)
    {
      if (!(ansp = skip_name(ansp, header, plen)))
	return 0; 
      ansp += 8; /* type, class, TTL */
      GETSHORT(rdlen, ansp);
      if ((unsigned int)(ansp + rdlen - (unsigned char *)header) > plen) 
	return 0;
      ansp += rdlen;
    }

  /* restore pseudoheader */
  if (pheader && ntohs(header->arcount) == 0)
    {
      /* must use memmove, may overlap */
      memmove(ansp, pheader, hlen);
      header->arcount = htons(1);
      ansp += hlen;
    }

  return ansp - (unsigned char *)header;
}

unsigned char *find_pseudoheader(HEADER *header, unsigned int plen, unsigned int *len, unsigned char **p)
{
  /* See if packet has an RFC2671 pseudoheader, and if so return a pointer to it. 
     also return length of pseudoheader in *len and pointer to the UDP size in *p */
  
  int i, arcount = ntohs(header->arcount);
  unsigned char *ansp;
  unsigned short rdlen, type;

  if (arcount == 0 || !(ansp = skip_questions(header, plen)))
    return NULL;
  
  for (i = 0; i < (ntohs(header->ancount) + ntohs(header->nscount)); i++)
    {
      if (!(ansp = skip_name(ansp, header, plen)))
	return NULL; 
      ansp += 8; /* type, class, TTL */
      GETSHORT(rdlen, ansp);
      if ((unsigned int)(ansp + rdlen - (unsigned char *)header) > plen) 
	return NULL;
      ansp += rdlen;
    }

  for (i = 0; i < arcount; i++)
    {
      unsigned char *save, *start = ansp;
      if (!(ansp = skip_name(ansp, header, plen)))
	return NULL; 

      GETSHORT(type, ansp);
      save = ansp;
      ansp += 6; /* class, TTL */
      GETSHORT(rdlen, ansp);
      if ((unsigned int)(ansp + rdlen - (unsigned char *)header) > plen) 
	return NULL;
       ansp += rdlen;
       if (type == T_OPT)
	{
	  if (len)
	    *len = ansp - start;
	  if (p)
	    *p = save;
	  return start;
	}
    }
  
  return NULL;
}
      
  
/* is addr in the non-globally-routed IP space? */ 
static int private_net(struct all_addr *addrp) 
{
  struct in_addr addr = *(struct in_addr *)addrp;
  if (inet_netof(addr) == 0xA ||
      (inet_netof(addr) >= 0xAC10 && inet_netof(addr) < 0xAC20) ||
      (inet_netof(addr) >> 8) == 0xC0A8) 
    return 1;
  else 
    return 0;
}
 
static unsigned char *add_text_record(unsigned int nameoffset, unsigned char *p, 
				      unsigned long ttl, unsigned short pref, 
				      unsigned short type, char *name)
{
  unsigned char *sav, *cp;
  int j;
  
  PUTSHORT(nameoffset | 0xc000, p); 
  PUTSHORT(type, p);
  PUTSHORT(C_IN, p);
  PUTLONG(ttl, p); /* TTL */
  
  sav = p;
  PUTSHORT(0, p); /* dummy RDLENGTH */

  if (pref)
    PUTSHORT(pref, p);

  while (*name) 
    {
      cp = p++;
      for (j=0; *name && (*name != '.'); name++, j++)
	*p++ = *name;
      *cp = j;
      if (*name)
	name++;
    }
  *p++ = 0;
  j = p - sav - 2;
  PUTSHORT(j, sav); /* Real RDLENGTH */
  
  return p;
}

/* On receiving an NXDOMAIN or NODATA reply, determine which names are known
   not to exist for negative caching. name if a working buffer passed in. */
void extract_neg_addrs(HEADER *header, unsigned int qlen, char *name, time_t now, unsigned short flags) 
{
  unsigned char *p;
  int i, found_soa = 0;
  int qtype, qclass, rdlen;
  unsigned long ttl, minttl = 0;
   
  /* there may be more than one question with some questions
     answered. We don't generate negative entries from those. */
  if (ntohs(header->ancount) != 0)
    return;
  
  if (!(p = skip_questions(header, qlen)))
    return; /* bad packet */
  
  /* we first need to find SOA records, to get min TTL, then we
     add a NEG cache entry for each question. */

  for (i=0; i<ntohs(header->nscount); i++)
    {
      if (!extract_name(header, qlen, &p, name, 1))
	return; /* bad packet */

      GETSHORT(qtype, p); 
      GETSHORT(qclass, p);
      GETLONG(ttl, p);
      GETSHORT(rdlen, p);
       
      if ((qclass == C_IN) && (qtype == T_SOA))
	{
	  int dummy;
	  /* MNAME */
	  if (!extract_name(header, qlen, &p, name, 1))
	    return;
	  /* RNAME */
	  if (!extract_name(header, qlen, &p, name, 1))
	    return;
	  GETLONG(dummy, p); /* SERIAL */
	  GETLONG(dummy, p); /* REFRESH */
	  GETLONG(dummy, p); /* RETRY */
	  GETLONG(dummy, p); /* EXPIRE */
	  if (!found_soa)
	    {
	      found_soa = 1;
	      minttl = ttl;
	    }
	  else if (ttl < minttl)
	    minttl = ttl;
	  GETLONG(ttl, p); /* minTTL */
	  if (ttl < minttl)
	    minttl = ttl;
	}
      else
	p += rdlen;

      if ((unsigned int)(p - (unsigned char *)header) > qlen)
	return; /* bad packet */
    }
  
  if (!found_soa)
    return; /* failed to find SOA */

  cache_start_insert();
  
  p = (unsigned char *)(header+1);
  
  for (i=0; i<ntohs(header->qdcount); i++)
    {
      struct all_addr addr;
      int is_arpa;

      if (!extract_name(header, qlen, &p, name, 1))
	return; /* bad packet */
      
      GETSHORT(qtype, p); 
      GETSHORT(qclass, p);
      
      if (qclass == C_IN && qtype == T_PTR && (is_arpa = in_arpa_name_2_addr(name, &addr)))
	cache_insert(name, &addr, now, minttl , is_arpa | F_REVERSE | flags);
      else if (qclass == C_IN && qtype == T_A) 
	cache_insert(name, NULL, now, minttl, F_IPV4 | F_FORWARD | flags);
#ifdef HAVE_IPV6	      
      else if (qclass == C_IN && qtype == T_AAAA) 
	cache_insert(name, NULL, now, minttl, F_IPV6 | F_FORWARD | flags);
#endif
    }
  
  cache_end_insert();
}

static void dns_doctor(HEADER *header, struct doctor *doctor, struct in_addr *addr)
{
  for (; doctor; doctor = doctor->next)
    if (is_same_net(doctor->in, *addr, doctor->mask))
      {
	addr->s_addr &= ~doctor->mask.s_addr;
	addr->s_addr |= (doctor->out.s_addr & doctor->mask.s_addr);
	/* Since we munged the data, the server it came from is no longer authoritative */
	header->nscount = htons(0);
	header->arcount = htons(0);
	break;
      }
}

void extract_addresses(HEADER *header, unsigned int qlen, char *name, 
		       time_t now, struct doctor *doctors)
{
  unsigned char *p, *psave, *endrr;
  int qtype, qclass, rdlen;
  unsigned long ttl;
  int i;
  
  /* skip over questions */
  if (!(p = skip_questions(header, qlen)))
    return; /* bad packet */
  
  cache_start_insert();
  
  psave = p;
  
  for (i=0; i<ntohs(header->ancount); i++)
    {
      unsigned char *origname = p;
      if (!extract_name(header, qlen, &p, name, 1))
	return; /* bad packet */

      GETSHORT(qtype, p); 
      GETSHORT(qclass, p);
      GETLONG(ttl, p);
      GETSHORT(rdlen, p);
	
      endrr = p + rdlen;
      if ((unsigned int)(endrr - (unsigned char *)header) > qlen)
	return; /* bad packet */
      
      if (qclass != C_IN)
	{
	  p = endrr;
	  continue;
	}

      if (qtype == T_A) /* A record. */
	{
	  dns_doctor(header, doctors, (struct in_addr *)p);
	  cache_insert(name, (struct all_addr *)p, now, 
		       ttl, F_IPV4 | F_FORWARD);
	}
#ifdef HAVE_IPV6
      else if (qtype == T_AAAA) /* IPV6 address record. */
	cache_insert(name, (struct all_addr *)p, now,
		     ttl, F_IPV6 | F_FORWARD);
#endif
      else if (qtype == T_PTR)
	{
  /* PTR record */
	  struct all_addr addr;
	  int name_encoding = in_arpa_name_2_addr(name, &addr);
	  if (name_encoding)
	    {
	      if (!extract_name(header, qlen, &p, name, 1))
		return; /* bad packet */
	      cache_insert(name, &addr, now, 
			   ttl, name_encoding | F_REVERSE); 
	    }
	}
      else if (qtype == T_CNAME)
	{
	  /* CNAME, search whole answer section again */
	  unsigned char *endrr1;
	  unsigned long cttl;
	  int j;
	  unsigned char *targp = p;
	  	  
	  p = psave; /* rewind p */
	  for (j=0; j<ntohs(header->ancount); j++)
	    {
	      int res;
	      unsigned char *tmp = targp; 
	      /* copy since it gets altered by extract_name */
	      /* get CNAME target each time round */
	      if (!extract_name(header, qlen, &tmp, name, 1))
		return; /* bad packet */
	      /* compare this name with target of CNAME in name buffer */
	      if (!(res = extract_name(header, qlen, &p, name, 0)))
		return; /* bad packet */
	      
	      GETSHORT(qtype, p); 
	      GETSHORT(qclass, p);
	      GETLONG(cttl, p);
	      GETSHORT(rdlen, p);
	      
	      endrr1 = p+rdlen;
	      if ((unsigned int)(endrr1 - (unsigned char *)header) > qlen)
		return; /* bad packet */

	      /* is this RR name same as target of CNAME */
	      if ((qclass != C_IN) || (res == 2))
		{
		  p = endrr1;
		  continue;
		}

	      /* match, use name of CNAME, data from this RR
		 use min TTL of two */

	      if (ttl < cttl)
		cttl = ttl;

	      /* get orig. name back again */
	      tmp = origname;
	      if (!extract_name(header, qlen, &tmp, name, 1))
		return;

	      if (qtype == T_A) /* A record. */
		{
		  dns_doctor(header, doctors, (struct in_addr *)p);
		  cache_insert(name, (struct all_addr *)p, now, 
			       cttl, F_IPV4 | F_FORWARD);
		}
#ifdef HAVE_IPV6
	      else if (qtype == T_AAAA) /* IPV6 address record. */
		cache_insert(name, (struct all_addr *)p, now, 
			     cttl, F_IPV6 | F_FORWARD);
#endif
	      else if (qtype == T_PTR)
		{
		  /* PTR record extract address from CNAME name */
		  struct all_addr addr;
		  int name_encoding = in_arpa_name_2_addr(name, &addr);
		  if (name_encoding)
		    {
		      if (!extract_name(header, qlen, &p, name, 1))
			return; /* bad packet */
		      cache_insert(name, &addr, now, cttl, 
				   name_encoding | F_REVERSE);
		    } 
		}
	      p = endrr1;
	    }
	} 
      p = endrr;
    }

  cache_end_insert();
}

/* If the packet holds exactly one query
   return 1 and leave the name from the query in name. */

unsigned short extract_request(HEADER *header,unsigned int qlen, char *name, unsigned short *typep)
{
  unsigned char *p = (unsigned char *)(header+1);
  int qtype, qclass;

  if (typep)
    *typep = 0;

  if (ntohs(header->qdcount) != 1 || header->opcode != QUERY)
    return 0; /* must be exactly one query. */
  
  if (!extract_name(header, qlen, &p, name, 1))
    return 0; /* bad packet */
   
  GETSHORT(qtype, p); 
  GETSHORT(qclass, p);

  if (qclass == C_IN)
    {
      if (typep)
	*typep = qtype;

      if (qtype == T_A)
	return F_IPV4;
      if (qtype == T_AAAA)
	return F_IPV6;
      if (qtype == T_ANY)
	return  F_IPV4 | F_IPV6;
    }
  
  return F_QUERY;
}


int setup_reply(HEADER *header, unsigned int qlen,
		struct all_addr *addrp, unsigned short flags, unsigned long ttl)
{
  unsigned char *p = skip_questions(header, qlen);
  
  header->qr = 1; /* response */
  header->aa = 0; /* authoritive */
  header->ra = 1; /* recursion if available */
  header->tc = 0; /* not truncated */
  header->nscount = htons(0);
  header->arcount = htons(0);
  header->ancount = htons(0); /* no answers unless changed below */
  if (flags == F_NEG)
    header->rcode = SERVFAIL; /* couldn't get memory */
  else if (flags == F_NOERR || flags == F_QUERY)
    header->rcode = NOERROR; /* empty domain */
  else if (flags == F_NXDOMAIN)
    header->rcode = NXDOMAIN;
  else if (p && flags == F_IPV4)
    { /* we know the address */
      header->rcode = NOERROR;
      header->ancount = htons(1);
      header->aa = 1;
      PUTSHORT (sizeof(HEADER) | 0xc000, p);
      PUTSHORT(T_A, p);
      PUTSHORT(C_IN, p);
      PUTLONG(ttl, p); /* TTL */
      PUTSHORT(INADDRSZ, p);
      memcpy(p, addrp, INADDRSZ);
      p += INADDRSZ;
    }
#ifdef HAVE_IPV6
  else if (p && flags == F_IPV6)
    {
      header->rcode = NOERROR;
      header->ancount = htons(1);
      header->aa = 1;
      PUTSHORT (sizeof(HEADER) | 0xc000, p);
      PUTSHORT(T_AAAA, p);
      PUTSHORT(C_IN, p);
      PUTLONG(ttl, p); /* TTL */
      PUTSHORT(IN6ADDRSZ, p);
      memcpy(p, addrp, IN6ADDRSZ);
      p += IN6ADDRSZ;
    }
#endif
  else /* nowhere to forward to */
    header->rcode = REFUSED;
 
  return p - (unsigned char *)header;
}

/* check if name matches local names ie from /etc/hosts or DHCP or local mx names. */
int check_for_local_domain(char *name, time_t now, struct mx_record *mx)
{
  struct crec *crecp;
  
  if ((crecp = cache_find_by_name(NULL, name, now, F_IPV4|F_IPV6)) &&
      (crecp->flags & (F_HOSTS | F_DHCP)))
    return 1;
  
  for (; mx; mx = mx->next)
    if (hostname_isequal(name, mx->mxname))
      return 1;
  
  return 0;
}

/* Is the packet a reply with the answer address equal to addr?
   If so mung is into an NXDOMAIN reply and also put that information
   in the cache. */
int check_for_bogus_wildcard(HEADER *header, unsigned int qlen, char *name, 
			     struct bogus_addr *baddr, time_t now)
{
  unsigned char *p;
  int i, qtype, qclass, rdlen;
  unsigned long ttl;
  struct bogus_addr *baddrp;

  /* skip over questions */
  if (!(p = skip_questions(header, qlen)))
    return 0; /* bad packet */

  for (i=0; i<ntohs(header->ancount); i++)
    {
      if (!extract_name(header, qlen, &p, name, 1))
	return 0; /* bad packet */
  
      GETSHORT(qtype, p); 
      GETSHORT(qclass, p);
      GETLONG(ttl, p);
      GETSHORT(rdlen, p);
      
      if (qclass == C_IN && qtype == T_A)
	for (baddrp = baddr; baddrp; baddrp = baddrp->next)
	  if (memcmp(&baddrp->addr, p, INADDRSZ) == 0)
	    {
	      /* Found a bogus address. Mangle the packet into an NXDOMAIN reply */
	      header->aa = 0;
	      header->ra = 1; /* recursion if available */
	      header->nscount = htons(0);
	      header->arcount = htons(0);
	      header->ancount = htons(0);
	      header->rcode = NXDOMAIN;
	      
	      cache_start_insert();
	      cache_insert(name, NULL, now, ttl, F_IPV4 | F_FORWARD | F_NEG | F_NXDOMAIN | F_CONFIG);
	      cache_end_insert();
	      
	      return 1;
	    }
      
      p += rdlen;
    }
  
  return 0;
}

/* return zero if we can't answer from cache, or packet size if we can */
int answer_request(HEADER *header, char *limit, unsigned int qlen, struct daemon *daemon, time_t now) 
{
  char *name = daemon->namebuff;
  unsigned char *p, *ansp, *pheader;
  int qtype, qclass, is_arpa;
  struct all_addr addr;
  unsigned int nameoffset;
  unsigned short flag;
  int qdcount = ntohs(header->qdcount); 
  int q, ans, anscount;
  int dryrun = 0, sec_reqd = 0;
  struct crec *crecp;
  int nxdomain, auth;

  if (!qdcount || header->opcode != QUERY )
    return 0;

  /* If there is an RFC2671 pseudoheader then it will be overwritten by
     partial replies, so we have to do a dry run to see if we can answer
     the query. We check to see if the do bit is set, if so we always
     forward rather than answering from the cache, which doesn't include
     security information. */

  if (find_pseudoheader(header, qlen, NULL, &pheader))
    { 
      unsigned short udpsz, ext_rcode, flags;
      unsigned char *psave = pheader;

      GETSHORT(udpsz, pheader);
      GETSHORT(ext_rcode, pheader);
      GETSHORT(flags, pheader);
      
      sec_reqd = flags & 0x8000; /* do bit */ 

      /* If our client is advertising a larger UDP packet size
	 than we allow, trim it so that we don't get an overlarge
	 response from upstream */

      if (udpsz > daemon->edns_pktsz)
	PUTSHORT(daemon->edns_pktsz, psave); 

      dryrun = 1;
    }

 rerun:
  /* determine end of question section (we put answers there) */
  if (!(ansp = skip_questions(header, qlen)))
    return 0; /* bad packet */
   
  /* now process each question, answers go in RRs after the question */
  p = (unsigned char *)(header+1);
  nxdomain = 0, auth = 1, anscount = 0;

  for (q=0; q<qdcount; q++)
    {
      /* save pointer to name for copying into answers */
      nameoffset = p - (unsigned char *)header;

      /* now extract name as .-concatenated string into name */
      if (!extract_name(header, qlen, &p, name, 1))
	return 0; /* bad packet */
      
      /* see if it's w.z.y.z.in-addr.arpa format */

      is_arpa = in_arpa_name_2_addr(name, &addr);
      
      GETSHORT(qtype, p); 
      GETSHORT(qclass, p);

      ans = 0; /* have we answered this question */
      
      if (qclass == C_CHAOS && qtype == T_TXT)
	/* special query to get version. */
	{
	  ans = 1;
	  if (!dryrun)
	    {
	      int len;
	      if (hostname_isequal(name, "version.bind"))
		sprintf(name, "dnsmasq-%s", VERSION);
	      else if (hostname_isequal(name, "authors.bind"))
		sprintf(name, "Simon Kelley");
	      else if (hostname_isequal(name, "copyright.bind"))
		sprintf(name, COPYRIGHT);
	      else
		*name = 0;
	      len = strlen(name);
	      PUTSHORT(nameoffset | 0xc000, ansp); 
	      PUTSHORT(T_TXT, ansp);
	      PUTSHORT(C_CHAOS, ansp);
	      PUTLONG(0, ansp);
	      PUTSHORT(len+1, ansp);
	      *ansp++ = len;
	      memcpy(ansp, name, len);
	      ansp += len;
	      anscount++;
	    }
	  }
      else if (qclass == C_IN)
	{
	  if ((daemon->options & OPT_FILTER) && 
	      (qtype == T_SOA || qtype == T_SRV || (qtype == T_ANY && strchr(name, '_'))))
	    {
	      ans = 1;
	      log_query(F_CONFIG | F_NEG, name, &addr, 0);
	    }
	  else 
	    {
	      if (qtype == T_PTR || qtype == T_ANY)
		{
		  if (!(crecp = cache_find_by_addr(NULL, &addr, now, is_arpa)))
		    { 
		      if (is_arpa == F_IPV4 && (daemon->options & OPT_BOGUSPRIV) && private_net(&addr))
			{
			  /* if not in cache, enabled and private IPV4 address, return NXDOMAIN */
			  ans = 1;
			  if (!dryrun)
			    {
			      log_query(F_CONFIG | F_REVERSE | F_IPV4 | F_NEG | F_NXDOMAIN, name, &addr, 0);
			      nxdomain = 1;
			    }
			}
		    }
		  else do 
		    { 
		      /* don't answer wildcard queries with data not from /etc/hosts or dhcp leases */
		      if (qtype == T_ANY && !(crecp->flags & (F_HOSTS | F_DHCP)))
			continue;
		      
		      if (crecp->flags & F_NEG)
			{
			  ans = 1;
			  if (!dryrun)
			    {
			      log_query(crecp->flags & ~F_FORWARD, name, &addr, 0);
			      auth = 0;
			      if (crecp->flags & F_NXDOMAIN)
				nxdomain = 1;
			    }
			}
		      else if ((crecp->flags & (F_HOSTS | F_DHCP)) || !sec_reqd)
			{
			  ans = 1;
			  if (!dryrun)
			    {
			      unsigned long ttl;
			      /* Return 0 ttl for DHCP entries, which might change
				 before the lease expires. */
			      if  (crecp->flags & (F_IMMORTAL | F_DHCP))
				ttl = daemon->local_ttl;
			      else
				ttl = crecp->ttd - now;
			      
			      if (!(crecp->flags & (F_HOSTS | F_DHCP)))
				auth = 0;
			      
			      ansp = add_text_record(nameoffset, ansp, ttl, 0, T_PTR, 
						     cache_get_name(crecp));
			      
			      log_query(crecp->flags & ~F_FORWARD, cache_get_name(crecp), &addr, 0);
			      anscount++;
			      
			      /* if last answer exceeded packet size, give up */
			      if (((unsigned char *)limit - ansp) < 0)
				return 0;
			    }
			}
		    } while ((crecp = cache_find_by_addr(crecp, &addr, now, is_arpa)));
		}
	      
	      for (flag = F_IPV4; flag; flag = (flag == F_IPV4) ? F_IPV6 : 0)
		{
		  unsigned short type = T_A;
		  int addrsz = INADDRSZ;
		  
		  if (flag == F_IPV6)
		    {
#ifdef HAVE_IPV6
		      type = T_AAAA;
		      addrsz = IN6ADDRSZ;
#else
		      break;
#endif
		    }
		  
		  if (qtype != type && qtype != T_ANY)
		    continue;
		  
		  crecp = NULL;
		  while ((crecp = cache_find_by_name(crecp, name, now, flag)))
		    { 
		      /* don't answer wildcard queries with data not from /etc/hosts
			 or DHCP leases */
		      if (qtype == T_ANY && !(crecp->flags & (F_HOSTS | F_DHCP)))
			continue;
		      
		      if (crecp->flags & F_NEG)
			{
			  ans = 1;
			  if (!dryrun)
			    {
			      log_query(crecp->flags, name, NULL, 0);
			      auth = 0;
			      if (crecp->flags & F_NXDOMAIN)
				nxdomain = 1;
			    }
			}
		      else if ((crecp->flags & (F_HOSTS | F_DHCP)) || !sec_reqd)
			{
			  ans = 1;
			  if (!dryrun)
			    {
			      unsigned long ttl;
			      
			      if  (crecp->flags & (F_IMMORTAL | F_DHCP))
				ttl = daemon->local_ttl;
			      else
				ttl = crecp->ttd - now;
			      
			      if (!(crecp->flags & (F_HOSTS | F_DHCP)))
				auth = 0;
			      log_query(crecp->flags & ~F_REVERSE, name, &crecp->addr, 0);
			      
			      /* copy question as first part of answer (use compression) */
			      PUTSHORT(nameoffset | 0xc000, ansp); 
			      PUTSHORT(type, ansp);
			      PUTSHORT(C_IN, ansp);
			      PUTLONG(ttl, ansp); /* TTL */
			      
			      PUTSHORT(addrsz, ansp);
			      memcpy(ansp, &crecp->addr, addrsz);
			      ansp += addrsz;
			      anscount++;
			      
			      if (((unsigned char *)limit - ansp) < 0)
				return 0;
			    }
			}
		    }
		}
	      
	      if (qtype == T_MX || qtype == T_ANY)
		{
		  struct mx_record *mx;
		  for (mx = daemon->mxnames; mx; mx = mx->next)
		    if (hostname_isequal(name, mx->mxname))
		      break;
		  if (mx)
		    {
		      ans = 1;
		      if (!dryrun)
			{
			  ansp = add_text_record(nameoffset, ansp, daemon->local_ttl, 1, T_MX, 
						 mx->mxtarget ? mx->mxtarget : daemon->mxtarget);
			  anscount++;
			}
		    }
		  else if ((daemon->options & (OPT_SELFMX | OPT_LOCALMX)) && 
			   cache_find_by_name(NULL, name, now, F_HOSTS | F_DHCP))
		    { 
		      ans = 1;
		      if (!dryrun)
			{
			  ansp = add_text_record(nameoffset, ansp, daemon->local_ttl, 1, T_MX,  
						 (daemon->options & OPT_SELFMX) ? name : daemon->mxtarget);
			  anscount++;
			}
		    }
		}
	      
	      if (qtype == T_MAILB)
		ans = 1, nxdomain = 1;
	      
	    }
	}
      
      if (!ans || ((unsigned char *)limit - ansp) < 0)
	return 0; /* failed to answer a question */
    }

  if (dryrun)
    {
      dryrun = 0;
      goto rerun;
    }
  
  /* done all questions, set up header and return length of result */
  header->qr = 1; /* response */
  header->aa = auth; /* authoritive - only hosts and DHCP derived names. */
  header->ra = 1; /* recursion if available */
  header->tc = 0; /* truncation */
  if (anscount == 0 && nxdomain)
    header->rcode = NXDOMAIN;
  else
    header->rcode = NOERROR; /* no error */
  header->ancount = htons(anscount);
  header->nscount = htons(0);
  header->arcount = htons(0);
  return ansp - (unsigned char *)header;
}

/* foxconn wklin added start, 09/05/2007 @mpoe */
#ifdef MULTIPLE_PPPOE
typedef struct {
    int param_count;
    int param_len[32];
    void *param[32];
} acos_t;

unsigned long acos_ip = 0 ;
static void acos_set_ipaddr(struct in_addr *p)
{
    acos_t param;
    int fd;
    unsigned long refresh_tick = 0;
    unsigned long ipaddr = 0;

    fd = open("/dev/acos_nat_cli", O_RDWR);
    if (!fd)  
        return;

    ipaddr = ntohl(p->s_addr);
    memset((char *)&param, 0, sizeof(acos_t));
    param.param_count = 2;
    param.param[0] = (void *)&ipaddr;
    param.param_len[0] = sizeof(unsigned long);
    param.param[1] = (void *)&refresh_tick;
    param.param_len[1] = sizeof(unsigned long);
    /* Foxconn modified by Max Ding, 01/13/2009 for multi-language */
    //if (0 > ioctl(fd, _IOR(120, 98, char *), &param)) 
    if (0 > ioctl(fd, _IOR(100, 110, char *), &param)) 
        fprintf(stderr, "error setting ipaddress %08x.\n", ipaddr);

    close(fd);
    return;
}

void extract_set_addr(HEADER *header, unsigned int qlen)
{
    unsigned char *p, *psave, *endrr;
    int qtype, qclass, rdlen;
    unsigned long ttl;
    int i;
    
    unsigned long *pTTL;
  
    /* skip over questions */
    if (!(p = skip_questions(header, qlen)))   
        return; /* bad packet */
        
    psave = p;
  
    for (i=0; i<ntohs(header->ancount); i++)
    {
        unsigned char name[256];
        if (!extract_name(header, qlen, &p, &name[0], 1))      
          return; /* bad packet */
       
        GETSHORT(qtype, p); 
        GETSHORT(qclass, p);
        pTTL = p;
        GETLONG(ttl, p);
        GETSHORT(rdlen, p);
	
        endrr = p + rdlen;
        if ((unsigned int)(endrr - (unsigned char *)header) > qlen)
            return;
      
        if (qclass != C_IN)
	    {
	        p = endrr;
	        continue;
	    }

        if (qtype == T_A) { /* A record. */
            *pTTL = 0;
            /*   Add a unsigned long variable acos_ip to avoid the 4-bytes align issue.      weal @ April 14 */
            memcpy(&acos_ip, p, 4);
            acos_set_ipaddr((struct in_addr *)&acos_ip);
        }
        p = endrr;
    }
    return;
}
#endif /* MULTIPLE_PPPOE */
/* foxconn wklin added end, 09/05/2007 @mpoe */

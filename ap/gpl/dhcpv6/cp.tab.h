/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_CPYY_Y_TAB_H_INCLUDED
# define YY_CPYY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int cpyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTERFACE = 258,
    IFNAME = 259,
    IPV6ADDR = 260,
    REQUEST = 261,
    SEND = 262,
    RAPID_COMMIT = 263,
    PREFIX_DELEGATION = 264,
    DNS_SERVERS = 265,
    SIP_SERVERS = 266,
    NTP_SERVERS = 267,
    INFO_ONLY = 268,
    TEMP_ADDR = 269,
    SOLICIT_ONLY = 270,
    IANA_ONLY = 271,
    IAPD_ONLY = 272,
    DOMAIN_LIST = 273,
    ADDRESS = 274,
    PREFIX = 275,
    IAID = 276,
    RENEW_TIME = 277,
    REBIND_TIME = 278,
    V_TIME = 279,
    P_TIME = 280,
    PREFIX_DELEGATION_INTERFACE = 281,
    USER_CLASS = 282,
    XID_SOL = 283,
    XID_REQ = 284,
    DUID_TIME = 285,
    NUMBER = 286,
    SLASH = 287,
    EOS = 288,
    BCL = 289,
    ECL = 290,
    STRING = 291,
    INFINITY = 292,
    COMMA = 293,
    OPTION = 294
  };
#endif
/* Tokens.  */
#define INTERFACE 258
#define IFNAME 259
#define IPV6ADDR 260
#define REQUEST 261
#define SEND 262
#define RAPID_COMMIT 263
#define PREFIX_DELEGATION 264
#define DNS_SERVERS 265
#define SIP_SERVERS 266
#define NTP_SERVERS 267
#define INFO_ONLY 268
#define TEMP_ADDR 269
#define SOLICIT_ONLY 270
#define IANA_ONLY 271
#define IAPD_ONLY 272
#define DOMAIN_LIST 273
#define ADDRESS 274
#define PREFIX 275
#define IAID 276
#define RENEW_TIME 277
#define REBIND_TIME 278
#define V_TIME 279
#define P_TIME 280
#define PREFIX_DELEGATION_INTERFACE 281
#define USER_CLASS 282
#define XID_SOL 283
#define XID_REQ 284
#define DUID_TIME 285
#define NUMBER 286
#define SLASH 287
#define EOS 288
#define BCL 289
#define ECL 290
#define STRING 291
#define INFINITY 292
#define COMMA 293
#define OPTION 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 104 "client6_parse.y" /* yacc.c:1909  */

	long long num;
	char* str;
	struct cf_list *list;
	struct in6_addr addr;
	struct dhcp6_addr *v6addr;

#line 140 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE cpyylval;

int cpyyparse (void);

#endif /* !YY_CPYY_Y_TAB_H_INCLUDED  */

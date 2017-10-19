/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         sfyyparse
#define yylex           sfyylex
#define yyerror         sfyyerror
#define yydebug         sfyydebug
#define yynerrs         sfyynerrs

#define yylval          sfyylval
#define yychar          sfyychar

/* Copy the first part of user declarations.  */
#line 34 "server6_parse.y" /* yacc.c:339  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include "queue.h"
#include "dhcp6.h"
#include "config.h"
#include "common.h"
#include "server6_conf.h"
#include "hash.h"
#include "lease.h"

extern int num_lines;
extern char *sfyytext;
extern int sock;
static struct interface *ifnetworklist = NULL;
static struct link_decl *linklist = NULL;
static struct host_decl *hostlist = NULL;
static struct pool_decl *poollist = NULL;

static struct interface *ifnetwork = NULL;
static struct link_decl *link = NULL;
static struct host_decl *host = NULL;
static struct pool_decl *pool = NULL;
static struct scopelist *currentscope = NULL;
static struct scopelist *currentgroup = NULL;
static int allow = 0;

static void cleanup(void);
void sfyyerror(char *msg);

#define ABORT	do { cleanup(); YYABORT; } while (0)

extern int sfyylex __P((void));

#line 116 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_SFYY_Y_TAB_H_INCLUDED
# define YY_SFYY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int sfyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTERFACE = 258,
    IFNAME = 259,
    PREFIX = 260,
    LINK = 261,
    RELAY = 262,
    STRING = 263,
    NUMBER = 264,
    SIGNEDNUMBER = 265,
    DECIMAL = 266,
    BOOLEAN = 267,
    IPV6ADDR = 268,
    INFINITY = 269,
    HOST = 270,
    POOL = 271,
    RANGE = 272,
    GROUP = 273,
    LINKLOCAL = 274,
    OPTION = 275,
    ALLOW = 276,
    SEND = 277,
    PREFERENCE = 278,
    RENEWTIME = 279,
    REBINDTIME = 280,
    RAPIDCOMMIT = 281,
    ADDRESS = 282,
    VALIDLIFETIME = 283,
    PREFERLIFETIME = 284,
    UNICAST = 285,
    TEMPIPV6ADDR = 286,
    DNS_SERVERS = 287,
    SIP_SERVERS = 288,
    NTP_SERVERS = 289,
    DUID = 290,
    DUID_ID = 291,
    IAID = 292,
    IAIDINFO = 293,
    INFO_ONLY = 294,
    TO = 295,
    BAD_TOKEN = 296
  };
#endif
/* Tokens.  */
#define INTERFACE 258
#define IFNAME 259
#define PREFIX 260
#define LINK 261
#define RELAY 262
#define STRING 263
#define NUMBER 264
#define SIGNEDNUMBER 265
#define DECIMAL 266
#define BOOLEAN 267
#define IPV6ADDR 268
#define INFINITY 269
#define HOST 270
#define POOL 271
#define RANGE 272
#define GROUP 273
#define LINKLOCAL 274
#define OPTION 275
#define ALLOW 276
#define SEND 277
#define PREFERENCE 278
#define RENEWTIME 279
#define REBINDTIME 280
#define RAPIDCOMMIT 281
#define ADDRESS 282
#define VALIDLIFETIME 283
#define PREFERLIFETIME 284
#define UNICAST 285
#define TEMPIPV6ADDR 286
#define DNS_SERVERS 287
#define SIP_SERVERS 288
#define NTP_SERVERS 289
#define DUID 290
#define DUID_ID 291
#define IAID 292
#define IAIDINFO 293
#define INFO_ONLY 294
#define TO 295
#define BAD_TOKEN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 116 "server6_parse.y" /* yacc.c:355  */

	unsigned int	num;
	int 	snum;
	char	*str;
	int 	dec;
	int	bool;
	struct in6_addr	addr;
	struct dhcp6_addr *dhcp6addr;

#line 248 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE sfyylval;

int sfyyparse (void);

#endif /* !YY_SFYY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   128,   132,   133,   134,   135,   139,   165,
     206,   208,   212,   213,   214,   215,   219,   237,   274,   276,
     280,   281,   282,   283,   284,   285,   286,   290,   291,   295,
     317,   330,   355,   357,   361,   362,   363,   364,   365,   369,
     412,   507,   517,   519,   523,   524,   525,   526,   527,   528,
     529,   533,   558,   582,   614,   615,   619,   627,   628,   632,
     638,   642,   646,   650,   661,   662,   666,   680,   688,   692,
     700,   708,   712,   716,   723,   743,   747,   755,   764,   775,
     782,   789,   796,   803,   806,   809,   815,   816,   820,   827,
     828,   832,   839,   840,   844,   850,   881,   882,   886,   895,
     904,   920,   936,   950,   954,   961
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTERFACE", "IFNAME", "PREFIX", "LINK",
  "RELAY", "STRING", "NUMBER", "SIGNEDNUMBER", "DECIMAL", "BOOLEAN",
  "IPV6ADDR", "INFINITY", "HOST", "POOL", "RANGE", "GROUP", "LINKLOCAL",
  "OPTION", "ALLOW", "SEND", "PREFERENCE", "RENEWTIME", "REBINDTIME",
  "RAPIDCOMMIT", "ADDRESS", "VALIDLIFETIME", "PREFERLIFETIME", "UNICAST",
  "TEMPIPV6ADDR", "DNS_SERVERS", "SIP_SERVERS", "NTP_SERVERS", "DUID",
  "DUID_ID", "IAID", "IAIDINFO", "INFO_ONLY", "TO", "BAD_TOKEN", "'{'",
  "'}'", "';'", "'/'", "$accept", "statements", "networkdef", "ifdef",
  "ifhead", "ifbody", "ifparams", "linkdef", "linkhead", "linkbody",
  "linkparams", "relaylist", "relaypara", "pooldef", "poolhead",
  "poolbody", "poolparas", "prefixdef", "rangedef", "groupdef",
  "groupbody", "groupparas", "grouphead", "hostdef", "hosthead",
  "hostbody", "hostdecl", "iaiddef", "iaidbody", "iaidpara", "hostparas",
  "hostpara", "hostaddr6", "hostprefix6", "addr6para", "v6address",
  "optiondecl", "optionhead", "optionpara", "dns_paras", "dns_para",
  "sip_paras", "sip_para", "ntp_paras", "ntp_para", "confdecl", "paradecl",
  "number_or_infinity", "name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   123,   125,    59,    47
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -49,   144,   -49,    15,    14,   -49,   -49,   -49,   -49,    31,
      32,    32,    32,    32,   -49,   -49,   -19,   -49,     2,   -49,
      23,   -49,   145,   -49,   -49,   -49,   -49,   -49,    27,   -49,
     -49,    34,    40,    50,    57,   -49,   -49,   -49,    58,    61,
      65,    55,    63,    56,    67,   -49,   -49,   -49,   -49,   -49,
     -49,   113,    38,     9,   -49,   -49,   -49,   -49,     3,   -49,
     -49,     4,   -49,   -49,   -49,     5,   -49,   -49,    14,    68,
     -49,   -49,   -49,   -49,    72,   -49,   102,   103,   -49,   104,
      76,   -49,    44,   -49,   -49,    80,   -49,   -49,   -49,   -49,
     -49,    79,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   105,    85,
      94,   106,   -49,   -49,   -49,   -49,   107,   109,   112,   117,
      86,   -49,   -49,    52,   -49,   -49,   -49,   -49,   136,   146,
     141,    75,   147,   147,   119,   124,   126,   -49,   -49,   130,
     137,   135,   138,   -49,   -49,   -49,   -49,   -49,   -49,   140,
      -1,   -49,     7,   -49,   174,    -4,   -49,   -49,   -49,   -49,
     177,   -49,   178,    32,    32,   148,   149,   150,    32,    32,
     151,   152,   153,   154,   155,   -49,   -49,   -49,   156,   157,
     -49,   -49,   -49,   -49,   -49,   -49,   -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,    51,    78,    77,    76,     0,
       0,     0,     0,     0,     3,     4,     0,     7,     0,     5,
       0,    97,     0,     6,    96,     9,   105,    17,     0,   103,
     104,     0,     0,     0,     0,    10,    18,    42,     0,     0,
       0,     0,     0,     0,     0,    75,   102,    98,    99,   100,
     101,     0,     0,     0,    79,    81,    80,    88,     0,    87,
      91,     0,    90,    95,    94,     0,    93,    82,     0,     0,
      11,    12,    14,    13,     0,    15,     0,     0,    31,     0,
       0,    19,    26,    28,    20,     0,    22,    21,    24,    23,
      25,     0,    49,    46,    45,    48,    47,    43,    44,    50,
      83,    86,    84,    89,    85,    92,    53,     8,     0,     0,
       0,     0,    16,    27,    32,    41,     0,     0,     0,     0,
       0,    55,    57,    58,    65,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    64,     0,
       0,     0,     0,    33,    37,    36,    35,    34,    38,     0,
       0,    73,     0,    56,     0,     0,    62,    52,    39,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    69,    63,     0,     0,
      59,    40,    74,    71,    72,    60,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,   158,   -49,   -49,   -49,    24,   -49,   -49,
     -49,   -49,   108,   159,   -49,   -49,   -49,   -43,   -42,   -45,
     -49,   -49,   -49,   -44,   -49,   -49,    69,   -49,   -49,   -49,
     -49,    81,   -49,   -49,    70,   -49,   -38,   -49,   -49,   -49,
     133,   -49,   127,   -49,   142,   -48,   -49,   -11,   134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,    15,    16,    51,    70,    17,    18,    52,
      81,    82,    83,    84,    85,   131,   143,    86,    87,    19,
      53,    97,    20,    73,    74,   120,   121,   122,   155,   156,
     123,   124,   125,   126,   150,   151,    21,    22,    45,    58,
      59,    61,    62,    65,    66,    23,    24,    31,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    33,    34,    75,    90,    99,    72,    88,    89,    98,
      95,    96,     3,    63,    76,     4,    57,    60,    64,    25,
     168,   169,    26,    35,    68,    78,    79,   163,   164,     6,
       7,     8,     9,    10,    11,   163,   164,    12,    13,   170,
      28,    29,   165,    76,    36,    77,    30,   100,   102,   104,
     166,    77,    91,    68,    78,    79,     5,   116,     6,     7,
       8,     9,    10,    11,    63,    37,    12,    13,    57,    64,
     127,    46,     6,     7,     8,    71,    60,    93,    47,   117,
      76,    80,   127,   148,    48,   127,   146,   147,   144,   145,
      68,   116,    79,     5,    49,     6,     7,     8,     9,    10,
      11,    50,    54,    12,    13,    55,     6,     7,     8,    56,
     116,    67,   107,   117,   108,   109,   110,   111,   142,     4,
     112,   118,   114,   115,   119,     6,     7,     8,    68,   136,
     128,     5,   117,     6,     7,     8,     9,    10,    11,   129,
     118,    12,    13,   119,     2,   139,   130,     3,   134,   132,
       4,   133,   173,   174,   141,   140,    69,   178,   179,   135,
     149,   154,     5,   153,     6,     7,     8,     9,    10,    11,
     157,    38,    12,    13,   158,    39,    40,    41,    42,    43,
     160,   159,   161,   167,    44,   162,   171,   172,   103,   137,
     113,   101,   175,   176,   177,   180,   181,   182,   183,   184,
     185,   186,   106,   152,   138,     0,     0,   105,     0,     0,
       0,    92,    94
};

static const yytype_int16 yycheck[] =
{
      11,    12,    13,    51,    52,    53,    51,    52,    52,    53,
      53,    53,     3,     8,     5,     6,    13,    13,    13,     4,
      24,    25,     8,    42,    15,    16,    17,    28,    29,    20,
      21,    22,    23,    24,    25,    28,    29,    28,    29,    43,
       9,     9,    43,     5,    42,     7,    14,    44,    44,    44,
      43,     7,    43,    15,    16,    17,    18,     5,    20,    21,
      22,    23,    24,    25,     8,    42,    28,    29,    13,    13,
     108,    44,    20,    21,    22,    51,    13,    53,    44,    27,
       5,    43,   120,   131,    44,   123,   131,   131,   131,   131,
      15,     5,    17,    18,    44,    20,    21,    22,    23,    24,
      25,    44,    44,    28,    29,    44,    20,    21,    22,    44,
       5,    44,    44,    27,    42,    13,    13,    13,    43,     6,
      44,    35,    42,    44,    38,    20,    21,    22,    15,    43,
      45,    18,    27,    20,    21,    22,    23,    24,    25,    45,
      35,    28,    29,    38,     0,     9,    40,     3,    36,    42,
       6,    42,   163,   164,    13,     9,    43,   168,   169,    42,
      13,    37,    18,    44,    20,    21,    22,    23,    24,    25,
      44,    26,    28,    29,    44,    30,    31,    32,    33,    34,
      45,    44,    44,     9,    39,    45,     9,     9,    61,   120,
      82,    58,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    68,   133,   123,    -1,    -1,    65,    -1,    -1,
      -1,    53,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     3,     6,    18,    20,    21,    22,    23,
      24,    25,    28,    29,    48,    49,    50,    53,    54,    65,
      68,    82,    83,    91,    92,     4,     8,    94,     9,     9,
      14,    93,    93,    93,    93,    42,    42,    42,    26,    30,
      31,    32,    33,    34,    39,    84,    44,    44,    44,    44,
      44,    51,    55,    66,    44,    44,    44,    13,    85,    86,
      13,    87,    88,     8,    13,    89,    90,    44,    15,    43,
      52,    53,    65,    69,    70,    91,     5,     7,    16,    17,
      43,    56,    57,    58,    59,    60,    63,    64,    65,    69,
      91,    43,    49,    53,    59,    63,    64,    67,    69,    91,
      44,    86,    44,    88,    44,    90,    94,    44,    42,    13,
      13,    13,    44,    58,    42,    44,     5,    27,    35,    38,
      71,    72,    73,    76,    77,    78,    79,    82,    45,    45,
      40,    61,    42,    42,    36,    42,    43,    72,    77,     9,
       9,    13,    43,    62,    63,    64,    65,    69,    91,    13,
      80,    81,    80,    44,    37,    74,    75,    44,    44,    44,
      45,    44,    45,    28,    29,    43,    43,     9,    24,    25,
      43,     9,     9,    93,    93,    44,    44,    44,    93,    93,
      44,    44,    44,    44,    44,    44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    49,    50,
      51,    51,    52,    52,    52,    52,    53,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    69,    70,    71,    71,    72,    72,    72,    73,
      74,    74,    74,    75,    76,    76,    77,    77,    77,    78,
      79,    80,    80,    80,    81,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     5,     2,
       0,     2,     1,     1,     1,     1,     5,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       5,     1,     0,     2,     1,     1,     1,     1,     1,     5,
       7,     5,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     2,     1,     3,     1,     1,     5,
       4,     4,     1,     3,     2,     1,     1,     1,     1,     5,
       5,     4,     4,     1,     4,     2,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     3,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 140 "server6_parse.y" /* yacc.c:1646  */
    {
		if (linklist) {
			ifnetwork->linklist = linklist;
			linklist = NULL;
		}
		if (hostlist) {
			ifnetwork->hostlist = hostlist;
			hostlist = NULL;
		}
		if (currentgroup) 
			ifnetwork->group = currentgroup->scope;

		dprintf(LOG_DEBUG, "interface definition for %s is ok", ifnetwork->name);
		ifnetwork->next = ifnetworklist;
		ifnetworklist = ifnetwork;
		ifnetwork = NULL;

		globalgroup->iflist = ifnetworklist;

		/* leave interface scope we know the current scope is not point to NULL*/
		currentscope = pop_double_list(currentscope);
	}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 166 "server6_parse.y" /* yacc.c:1646  */
    {
		struct interface *temp_if = ifnetworklist;
		while (temp_if)
		{
			if (!strcmp(temp_if->name, (yyvsp[0].str)))
			{
				dprintf(LOG_ERR, "duplicate interface definition for %s",
					temp_if->name);
				ABORT;
			}
			temp_if = temp_if->next;
		}
		ifnetwork = (struct interface *)malloc(sizeof(*ifnetwork));
		if (ifnetwork == NULL) {
			dprintf(LOG_ERR, "failed to allocate memory");
			ABORT;
		}
		memset(ifnetwork, 0, sizeof(*ifnetwork));
		TAILQ_INIT(&ifnetwork->ifscope.dnslist.addrlist);
		TAILQ_INIT(&ifnetwork->ifscope.siplist);
		TAILQ_INIT(&ifnetwork->ifscope.ntplist);
		strncpy(ifnetwork->name, (yyvsp[0].str), strlen((yyvsp[0].str))); 
		if (get_linklocal(ifnetwork->name, &ifnetwork->linklocal) < 0) {
			dprintf(LOG_ERR, "get device %s linklocal failed", ifnetwork->name);
		}
		
		/* check device, if the device is not available,
		 * it is OK, it might be added later
		 * so keep this in the configuration file.
		 */
		if (if_nametoindex(ifnetwork->name) == 0) {
			dprintf(LOG_ERR, "this device %s doesn't exist.", (yyvsp[0].str));
		}
		/* set up hw_addr, link local, primary ipv6addr */
		/* enter interface scope */
		currentscope = push_double_list(currentscope, &ifnetwork->ifscope);
		if (currentscope == NULL)
			ABORT;
	}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "server6_parse.y" /* yacc.c:1646  */
    {
		if (poollist) {
			link->poollist = poollist;
			poollist = NULL;
		}
		if (currentgroup) 
			link->group = currentgroup->scope;

		link->next = linklist;
		linklist = link;
		link = NULL;
		/* leave iink scope we know the current scope is not point to NULL*/
		currentscope = pop_double_list(currentscope);
	}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 238 "server6_parse.y" /* yacc.c:1646  */
    {
		struct link_decl *temp_sub = linklist;
		/* memory allocation for link */
		link = (struct link_decl *)malloc(sizeof(*link));
		if (link == NULL) {
			dprintf(LOG_ERR, "failed to allocate memory");
			ABORT;
		}
		memset(link, 0, sizeof(*link));
		TAILQ_INIT(&link->linkscope.dnslist.addrlist);
		TAILQ_INIT(&link->linkscope.siplist);
		TAILQ_INIT(&link->linkscope.ntplist);
		while (temp_sub) {
			if (!strcmp(temp_sub->name, (yyvsp[0].str)))
			{
				dprintf(LOG_ERR, "duplicate link definition for %s", (yyvsp[0].str));
				ABORT;
			}
			temp_sub = temp_sub->next;
		}			
		/* link set */
		strncpy(link->name, (yyvsp[0].str), strlen((yyvsp[0].str)));
		if (ifnetwork)
			link->network = ifnetwork;
		else {
			/* create a ifnetwork for this interface */
		}
		link->relaylist = NULL;
		link->seglist = NULL;
		/* enter link scope */
		currentscope = push_double_list(currentscope, &link->linkscope);
		if (currentscope == NULL)
			ABORT;
	}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 296 "server6_parse.y" /* yacc.c:1646  */
    {
		struct v6addrlist *temprelay;
		if (!link) {
			dprintf(LOG_ERR, "relay must be defined under link");
			ABORT;
		}
		temprelay = (struct v6addrlist *)malloc(sizeof(*temprelay));
		if (temprelay == NULL) {
			dprintf(LOG_ERR, "failed to allocate memory");
			ABORT;
		}
		memset(temprelay, 0, sizeof(*temprelay));
		memcpy(&temprelay->v6addr.addr, &(yyvsp[-3].addr), sizeof(temprelay->v6addr.addr));
		temprelay->v6addr.plen = (yyvsp[-1].num);
		temprelay->next = link->relaylist;
		link->relaylist = temprelay;
		temprelay = NULL;
	}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "server6_parse.y" /* yacc.c:1646  */
    {
		if (currentgroup) 
			pool->group = currentgroup->scope;
		pool->next = poollist;
		poollist = pool;
		pool = NULL;
		/* leave pool scope we know the current scope is not point to NULL*/
		currentscope = pop_double_list(currentscope);
	}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 331 "server6_parse.y" /* yacc.c:1646  */
    {
		if (!link) {
			dprintf(LOG_ERR, "pooldef must be defined under link");
			ABORT;
		}
		pool = (struct pool_decl *)malloc(sizeof(*pool));
		if (pool == NULL) {
			dprintf(LOG_ERR, "fail to allocate memory");
			ABORT;
		}
		memset(pool, 0, sizeof(*pool));
		TAILQ_INIT(&pool->poolscope.dnslist.addrlist);
		TAILQ_INIT(&pool->poolscope.siplist);
		TAILQ_INIT(&pool->poolscope.ntplist);
		if (link)
			pool->link = link;
			
		/* enter pool scope */
		currentscope = push_double_list(currentscope, &pool->poolscope);
		if (currentscope == NULL)
			ABORT;
	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 370 "server6_parse.y" /* yacc.c:1646  */
    {
		struct v6prefix *v6prefix, *v6prefix0;
		struct v6addr *prefix;
		if (!link) {
			dprintf(LOG_ERR, "prefix must be defined under link");
			ABORT;
		}
		v6prefix = (struct v6prefix *)malloc(sizeof(*v6prefix));
		if (v6prefix == NULL) {
			dprintf(LOG_ERR, "failed to allocate memory");
			ABORT;
		}
		memset(v6prefix, 0, sizeof(*v6prefix));
		v6prefix->link = link;
		if (pool)
			v6prefix->pool = pool;
		/* make sure the range ipv6 address within the prefixaddr */
		if ((yyvsp[-1].num) > 128 || (yyvsp[-1].num) < 0) {
			dprintf(LOG_ERR, "invalid prefix length in line %d", num_lines);
			ABORT;
		}
		prefix = getprefix(&(yyvsp[-3].addr), (yyvsp[-1].num));
		for (v6prefix0 = link->prefixlist; v6prefix0; v6prefix0 = v6prefix0->next) {
			if (IN6_ARE_ADDR_EQUAL(prefix, &v6prefix0->prefix.addr) && 
					(yyvsp[-1].num) == v6prefix0->prefix.plen)  {
				dprintf(LOG_ERR, "duplicated prefix defined within same link");
				ABORT;
			}
		}
		/* check the assigned prefix is not reserved pv6 addresses */
		if (IN6_IS_ADDR_RESERVED(prefix)) {
			dprintf(LOG_ERR, "config reserved prefix");
			ABORT;
		}
		memcpy(&v6prefix->prefix, prefix, sizeof(v6prefix->prefix));
		v6prefix->next = link->prefixlist;
		link->prefixlist = v6prefix;
		free(prefix);
	}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 413 "server6_parse.y" /* yacc.c:1646  */
    {
		struct v6addrseg *seg, *temp_seg;
		struct v6addr *prefix1, *prefix2;
		if (!link) {
			dprintf(LOG_ERR, "range must be defined under link");
			ABORT;
		}
		seg = (struct v6addrseg *)malloc(sizeof(*seg));
		if (seg == NULL) {
			dprintf(LOG_ERR, "failed to allocate memory");
			ABORT;
		}
		memset(seg, 0, sizeof(*seg));
		temp_seg = link->seglist;
		seg->link = link;
		if (pool)
			seg->pool = pool;
		/* make sure the range ipv6 address within the prefixaddr */
		if ((yyvsp[-1].num) > 128 || (yyvsp[-1].num) < 0) {
			dprintf(LOG_ERR, "invalid prefix length in line %d", num_lines);
			ABORT;
		}
		prefix1 = getprefix(&(yyvsp[-5].addr), (yyvsp[-1].num));
		prefix2 = getprefix(&(yyvsp[-3].addr), (yyvsp[-1].num));
		if (!prefix1 || !prefix2) {
			dprintf(LOG_ERR, "address range defined error");
			ABORT;
		}
		if (ipv6addrcmp(&prefix1->addr, &prefix2->addr)) {
			dprintf(LOG_ERR, 
				"address range defined doesn't in the same prefix range");
			ABORT;
		}
		if (ipv6addrcmp(&(yyvsp[-5].addr), &(yyvsp[-3].addr)) < 0) {
			memcpy(&seg->min, &(yyvsp[-5].addr), sizeof(seg->min));
			memcpy(&seg->max, &(yyvsp[-3].addr), sizeof(seg->max));
		} else {
			memcpy(&seg->max, &(yyvsp[-5].addr), sizeof(seg->max));
			memcpy(&seg->min, &(yyvsp[-3].addr), sizeof(seg->min));
		}
		/* check the assigned addresses are not reserved ipv6 addresses */
		if (IN6_IS_ADDR_RESERVED(&seg->max) || IN6_IS_ADDR_RESERVED(&seg->max)) {
			dprintf(LOG_ERR, "config reserved ipv6address");
			ABORT;
		}

		memcpy(&seg->prefix, prefix1, sizeof(seg->prefix));
		memcpy(&seg->free, &seg->min, sizeof(seg->free));
		if (pool)
			seg->pool = pool;
		/* make sure there is no overlap in the rangelist */
		/* the segaddr is sorted by prefix len, thus most specific
		   ipv6 address is going to be assigned.
		 */
		if (!temp_seg) {
			seg->next = NULL;
			seg->prev = NULL;
			link->seglist = seg;
		} else {
			for (; temp_seg; temp_seg = temp_seg->next) { 
				if ( prefix1->plen < temp_seg->prefix.plen) {
					if (temp_seg->next == NULL) {
						temp_seg->next = seg;
						seg->prev = temp_seg;
						seg->next = NULL;
						break;
					}
					continue;
				}
				if (prefix1->plen == temp_seg->prefix.plen) {
	     				if (!(ipv6addrcmp(&seg->min, &temp_seg->max) > 0
					    || ipv6addrcmp(&seg->max, &temp_seg->min) < 0)) {
		   				dprintf(LOG_ERR, "overlap range addr defined");
		   				ABORT;
					}
				}
				if (temp_seg->prev == NULL) { 
					link->seglist = seg;
					seg->prev = NULL;
				} else {
					temp_seg->prev->next = seg;
					seg->prev = temp_seg->prev;
				}
				temp_seg->prev = seg;
				seg->next = temp_seg;
				break;
			}
		}
		free(prefix1);
		free(prefix2);
	}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 508 "server6_parse.y" /* yacc.c:1646  */
    {
		/* return to prev group scope if any */
		currentgroup = pop_double_list(currentgroup);

		/* leave current group scope */
		currentscope = pop_double_list(currentscope);
	}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 534 "server6_parse.y" /* yacc.c:1646  */
    {
		struct scope *groupscope;
		groupscope = (struct scope *)malloc(sizeof(*groupscope));
		if (groupscope == NULL) {
			dprintf(LOG_ERR, "group memory allocation failed");
			ABORT;
		}
		memset(groupscope, 0, sizeof(*groupscope));
		TAILQ_INIT(&groupscope->dnslist.addrlist);
		TAILQ_INIT(&groupscope->siplist);
		TAILQ_INIT(&groupscope->ntplist);
		/* set up current group */
		currentgroup = push_double_list(currentgroup, groupscope);
		if (currentgroup == NULL)
			ABORT;

		/* enter group scope  */
		currentscope = push_double_list(currentscope, groupscope);
		if (currentscope == NULL)
			ABORT;
	}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 559 "server6_parse.y" /* yacc.c:1646  */
    {
		struct host_decl *temp_host = hostlist;
		while (temp_host)
		{
			if (temp_host->iaidinfo.iaid == host->iaidinfo.iaid) {
				dprintf(LOG_ERR, "duplicated host %d redefined", 
					host->iaidinfo.iaid);
				ABORT;
			}
			temp_host = temp_host->next;
		}
		if (currentgroup) 
			host->group = currentgroup->scope;
		host->next = hostlist;
		hostlist = host;
		host = NULL;
		/* leave host scope we know the current scope is not point to NULL*/
		currentscope = pop_double_list(currentscope);
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 583 "server6_parse.y" /* yacc.c:1646  */
    {
		struct host_decl *temp_host = hostlist;
		while (temp_host)
		{
			if (!strcmp(temp_host->name, (yyvsp[0].str))) {
				dprintf(LOG_ERR, "duplicated host %s redefined", (yyvsp[0].str));
				ABORT;
			}
			temp_host = temp_host->next;
		}
		host = (struct host_decl *)malloc(sizeof(*host));
		if (host == NULL) {
			dprintf(LOG_ERR, "fail to allocate memory");
			ABORT;
		}
		memset(host, 0, sizeof(*host));
		TAILQ_INIT(&host->addrlist);
		TAILQ_INIT(&host->prefixlist);
		TAILQ_INIT(&host->hostscope.dnslist.addrlist);
		TAILQ_INIT(&host->hostscope.siplist);
		TAILQ_INIT(&host->hostscope.ntplist);
		host->network = ifnetwork;
		strncpy(host->name, (yyvsp[0].str), strlen((yyvsp[0].str)));
		/* enter host scope */
		currentscope = push_double_list(currentscope, &host->hostscope);
		if (currentscope == NULL)
			ABORT;
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 620 "server6_parse.y" /* yacc.c:1646  */
    {
		if (host == NULL) {
			dprintf(LOG_DEBUG, "duid should be defined under host decl");
			ABORT;
		}
		configure_duid((yyvsp[-1].str), &host->cid);
	}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 633 "server6_parse.y" /* yacc.c:1646  */
    {
	}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 639 "server6_parse.y" /* yacc.c:1646  */
    {
		host->iaidinfo.renewtime = (yyvsp[-1].num);
	}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 643 "server6_parse.y" /* yacc.c:1646  */
    {
		host->iaidinfo.rebindtime = (yyvsp[-1].num);
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 651 "server6_parse.y" /* yacc.c:1646  */
    {
		if (host == NULL) {
			dprintf(LOG_DEBUG, "iaid should be defined under host decl");
			ABORT;
		}
		host->iaidinfo.iaid = (yyvsp[-1].num);
	}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 667 "server6_parse.y" /* yacc.c:1646  */
    {
		if (host == NULL) {
			dprintf(LOG_DEBUG, "address should be defined under host decl");
			ABORT;
		}
		dhcp6_add_listval(&host->addrlist, (yyvsp[0].dhcp6addr), DHCP6_LISTVAL_DHCP6ADDR);
		if (hash_add(host_addr_hash_table, &((yyvsp[0].dhcp6addr)->addr), (yyvsp[0].dhcp6addr)) != 0) {
			dprintf(LOG_ERR, "%s" "hash add lease failed for %s",
				FNAME, in6addr2str(&((yyvsp[0].dhcp6addr)->addr), 0));
			free((yyvsp[0].dhcp6addr));
			return (-1);
		}
	}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 681 "server6_parse.y" /* yacc.c:1646  */
    {
		if (host == NULL) {
			dprintf(LOG_DEBUG, "prefix should be defined under host decl");
			ABORT;
		}
		dhcp6_add_listval(&host->prefixlist, (yyvsp[0].dhcp6addr), DHCP6_LISTVAL_DHCP6ADDR);
	}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 693 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].dhcp6addr)->type = IANA;
		(yyval.dhcp6addr) = (yyvsp[-2].dhcp6addr);
	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 701 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].dhcp6addr)->type = IAPD;
		(yyval.dhcp6addr) = (yyvsp[-2].dhcp6addr);
	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 709 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].dhcp6addr)->validlifetime = (yyvsp[-1].num);
	}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 713 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].dhcp6addr)->preferlifetime = (yyvsp[-1].num);
	}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 717 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyval.dhcp6addr) = (yyvsp[0].dhcp6addr);
	}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 724 "server6_parse.y" /* yacc.c:1646  */
    {
		struct dhcp6_addr *temp;
		temp = (struct dhcp6_addr *)malloc(sizeof(*temp));
		if (temp == NULL) {
			dprintf(LOG_ERR, "v6addr memory allocation failed");
			ABORT;
		}
		memset(temp, 0, sizeof(*temp));
		memcpy(&temp->addr, &(yyvsp[-3].addr), sizeof(temp->addr));
		if ((yyvsp[-1].num) > 128 || (yyvsp[-1].num) < 0) {
			dprintf(LOG_ERR, "invalid prefix length in line %d", num_lines);
			ABORT;
		}
		temp->plen = (yyvsp[-1].num);
		(yyval.dhcp6addr) = temp;
	}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 748 "server6_parse.y" /* yacc.c:1646  */
    {		
		if (!currentscope) { 
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
	}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 756 "server6_parse.y" /* yacc.c:1646  */
    {		
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		allow = 1;
	}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 765 "server6_parse.y" /* yacc.c:1646  */
    {		
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
	}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 776 "server6_parse.y" /* yacc.c:1646  */
    {
		if (allow) 
			currentscope->scope->allow_flags |= DHCIFF_RAPID_COMMIT;
		else 
			currentscope->scope->send_flags |= DHCIFF_RAPID_COMMIT;
	}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 783 "server6_parse.y" /* yacc.c:1646  */
    {
		if (allow) 
			currentscope->scope->allow_flags |= DHCIFF_TEMP_ADDRS;
		else 
			currentscope->scope->send_flags |= DHCIFF_TEMP_ADDRS;
	}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 790 "server6_parse.y" /* yacc.c:1646  */
    {
		if (allow) 
			currentscope->scope->allow_flags |= DHCIFF_UNICAST;
		else 
			currentscope->scope->send_flags |= DHCIFF_UNICAST;
	}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 797 "server6_parse.y" /* yacc.c:1646  */
    {
		if (allow) 
			currentscope->scope->allow_flags |= DHCIFF_INFO_ONLY;
		else
			currentscope->scope->send_flags |= DHCIFF_INFO_ONLY;
	}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 804 "server6_parse.y" /* yacc.c:1646  */
    {
	}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 807 "server6_parse.y" /* yacc.c:1646  */
    {
	}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 810 "server6_parse.y" /* yacc.c:1646  */
    {
	}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 821 "server6_parse.y" /* yacc.c:1646  */
    {
		dhcp6_add_listval(&currentscope->scope->dnslist.addrlist, &(yyvsp[0].addr),
			DHCP6_LISTVAL_ADDR6);
	}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 833 "server6_parse.y" /* yacc.c:1646  */
    {
		dhcp6_add_listval(&currentscope->scope->siplist, &(yyvsp[0].addr),
			DHCP6_LISTVAL_ADDR6);
	}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 845 "server6_parse.y" /* yacc.c:1646  */
    {
		dhcp6_add_listval(&currentscope->scope->ntplist, &(yyvsp[0].addr),
			DHCP6_LISTVAL_ADDR6);
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 851 "server6_parse.y" /* yacc.c:1646  */
    {
		struct domain_list *domainname, *temp;
		int len = 0;
		domainname = (struct domain_list *)malloc(sizeof(*domainname));
		if (domainname == NULL)
			ABORT;
		len = strlen((yyvsp[0].str));
		if (len > MAXDNAME) 
			ABORT;
		strncpy(domainname->name, (yyvsp[0].str), len);
		domainname->name[len] = '\0';
		domainname->next = NULL;
		if (currentscope->scope->dnslist.domainlist == NULL) {
			currentscope->scope->dnslist.domainlist = domainname;
			dprintf(LOG_DEBUG, "add domain name %s", domainname->name);
		} else {
			for (temp = currentscope->scope->dnslist.domainlist; temp;
			     temp = temp->next) {
				if (temp->next == NULL) {
					dprintf(LOG_DEBUG, "add domain name %s", 
						domainname->name);
					temp->next = domainname;
					break;
				}
			}
		}
	}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 887 "server6_parse.y" /* yacc.c:1646  */
    {
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		currentscope->scope->renew_time = (yyvsp[-1].num);
	}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 896 "server6_parse.y" /* yacc.c:1646  */
    {	
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		currentscope->scope->rebind_time = (yyvsp[-1].num);
	}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 905 "server6_parse.y" /* yacc.c:1646  */
    {
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		currentscope->scope->valid_life_time = (yyvsp[-1].num);
		if (currentscope->scope->prefer_life_time != 0 && 
		    currentscope->scope->valid_life_time <
		    currentscope->scope->prefer_life_time) {
			dprintf(LOG_ERR, "%s" 
				"validlifetime is less than preferlifetime", FNAME);
			ABORT;
		}
	}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 921 "server6_parse.y" /* yacc.c:1646  */
    {
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		currentscope->scope->prefer_life_time = (yyvsp[-1].num);
		if (currentscope->scope->valid_life_time != 0 &&
		    currentscope->scope->valid_life_time <
		    currentscope->scope->prefer_life_time) {
			dprintf(LOG_ERR, "%s" 
				"validlifetime is less than preferlifetime", FNAME);
			ABORT;
		}
	}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 937 "server6_parse.y" /* yacc.c:1646  */
    {
		if (!currentscope) {
			currentscope = push_double_list(currentscope, &globalgroup->scope);
			if (currentscope == NULL)
				ABORT;
		}
		if ((yyvsp[-1].num) < 0 || (yyvsp[-1].num) > 255)
			dprintf(LOG_ERR, "%s" "bad server preference number", FNAME);
		currentscope->scope->server_pref = (yyvsp[-1].num);
	}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 951 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyval.num) = (yyvsp[0].num); 
	}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 955 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyval.num) = DHCP6_DURATITION_INFINITE;
	}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 962 "server6_parse.y" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[0].str);
	}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2317 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 967 "server6_parse.y" /* yacc.c:1906  */



static
void cleanup(void)
{
	/* it is not necessary to free all the pre malloc(), if it fails, 
	 * exit will free them automatically.
	 */
}

void
sfyyerror(char *msg)
{
	cleanup();
	dprintf(LOG_ERR, "%s in line %d: %s ", msg, num_lines, sfyytext);
}

/* A Bison parser, made by GNU Bison 2.6.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 360 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yaccExample.h"
#include "Semantics.h"
#include "CodeGen.h"

extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern struct SymTab *table;
extern struct SymTab *funcTable;
extern struct SymEntry *entry;


/* Line 360 of yacc.c  */
#line 88 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Ident = 258,
     IntLit = 259,
     FloatLit = 260,
     Int = 261,
     Float = 262,
     PRINT = 263,
     PRINTLN = 264,
     PRINTSPACE = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     EQ = 269,
     NEQ = 270,
     LT = 271,
     LTE = 272,
     GT = 273,
     GTE = 274,
     Bool = 275,
     BoolLit = 276,
     BoolAnd = 277,
     BoolOr = 278,
     Def = 279,
     Return = 280,
     Void = 281,
     Not = 282,
     Read = 283
   };
#endif
/* Tokens.  */
#define Ident 258
#define IntLit 259
#define FloatLit 260
#define Int 261
#define Float 262
#define PRINT 263
#define PRINTLN 264
#define PRINTSPACE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define EQ 269
#define NEQ 270
#define LT 271
#define LTE 272
#define GT 273
#define GTE 274
#define Bool 275
#define BoolLit 276
#define BoolAnd 277
#define BoolOr 278
#define Def 279
#define Return 280
#define Void 281
#define Not 282
#define Read 283



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 376 of yacc.c  */
#line 22 "parser.y"

  int val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;


/* Line 376 of yacc.c  */
#line 195 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 379 of yacc.c  */
#line 223 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      32,    33,    40,    38,    37,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    15,    19,    23,    30,
      37,    44,    47,    48,    49,    59,    60,    70,    71,    81,
      82,    92,    97,   100,   101,   105,   109,   113,   118,   123,
     128,   133,   138,   150,   158,   166,   170,   172,   173,   177,
     179,   183,   185,   189,   193,   195,   199,   203,   207,   211,
     215,   219,   221,   225,   229,   231,   235,   239,   243,   245,
     249,   251,   255,   258,   261,   263,   265,   267,   269,   274,
     276,   281,   283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    48,    55,    -1,    47,    46,    -1,
      -1,     6,    68,    29,    -1,    20,    68,    29,    -1,     7,
      68,    29,    -1,     6,    30,    69,    31,    68,    29,    -1,
      20,    30,    69,    31,    68,    29,    -1,     7,    30,    69,
      31,    68,    29,    -1,    49,    48,    -1,    -1,    -1,    24,
       6,     3,    50,    32,    33,    34,    54,    35,    -1,    -1,
      24,    20,     3,    51,    32,    33,    34,    54,    35,    -1,
      -1,    24,     7,     3,    52,    32,    33,    34,    54,    35,
      -1,    -1,    24,    26,     3,    53,    32,    33,    34,    55,
      35,    -1,    55,    25,    60,    29,    -1,    56,    55,    -1,
      -1,    10,    60,    29,    -1,     9,    57,    29,    -1,     8,
      58,    29,    -1,    68,    32,    33,    29,    -1,    68,    36,
      59,    29,    -1,    67,    36,    59,    29,    -1,    68,    36,
      28,    29,    -1,    67,    36,    28,    29,    -1,    11,    32,
      59,    33,    34,    55,    35,    12,    34,    55,    35,    -1,
      11,    32,    59,    33,    34,    55,    35,    -1,    13,    32,
      60,    33,    34,    55,    35,    -1,    58,    37,    60,    -1,
      60,    -1,    -1,    58,    37,    60,    -1,    60,    -1,    68,
      32,    33,    -1,    60,    -1,    60,    22,    61,    -1,    60,
      23,    61,    -1,    61,    -1,    62,    14,    62,    -1,    62,
      15,    62,    -1,    62,    18,    62,    -1,    62,    16,    62,
      -1,    62,    19,    62,    -1,    62,    17,    62,    -1,    62,
      -1,    62,    38,    63,    -1,    62,    39,    63,    -1,    63,
      -1,    63,    40,    66,    -1,    63,    41,    66,    -1,    63,
      42,    66,    -1,    64,    -1,    65,    43,    65,    -1,    65,
      -1,    32,    60,    33,    -1,    27,    65,    -1,    39,    65,
      -1,    66,    -1,     4,    -1,     5,    -1,    21,    -1,    68,
      30,    62,    31,    -1,    68,    -1,    68,    30,    62,    31,
      -1,     3,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    80,    81,    83,    84,    85,    87,    88,
      89,    91,    92,    94,    94,    95,    95,    96,    96,    97,
      97,    99,   101,   102,   104,   105,   106,   108,   110,   111,
     112,   113,   115,   116,   117,   119,   120,   121,   123,   124,
     126,   127,   129,   130,   131,   133,   134,   135,   136,   137,
     138,   139,   141,   142,   143,   145,   146,   147,   148,   150,
     151,   153,   154,   155,   156,   158,   159,   161,   162,   163,
     165,   167,   171
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Ident", "IntLit", "FloatLit", "Int",
  "Float", "PRINT", "PRINTLN", "PRINTSPACE", "IF", "ELSE", "WHILE", "EQ",
  "NEQ", "LT", "LTE", "GT", "GTE", "Bool", "BoolLit", "BoolAnd", "BoolOr",
  "Def", "Return", "Void", "Not", "Read", "';'", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "'='", "','", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "$accept", "Prog", "Declarations", "Dec", "Functions", "FuncDec",
  "$@1", "$@2", "$@3", "$@4", "RStmtSeq", "StmtSeq", "Stmt", "P0", "P1",
  "R0", "E0", "E1", "E2", "E3", "O0", "O1", "E4", "E5", "Id", "SIZE", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      91,    93,    40,    41,   123,   125,    61,    44,    43,    45,
      42,    47,    37,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    48,    50,    49,    51,    49,    52,    49,    53,
      49,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      67,    68,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     3,     3,     3,     6,     6,
       6,     2,     0,     0,     9,     0,     9,     0,     9,     0,
       9,     4,     2,     0,     3,     3,     3,     4,     4,     4,
       4,     4,    11,     7,     7,     3,     1,     0,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     1,     1,     4,     1,
       4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,    12,     4,    71,     0,     0,
       0,     0,     0,     0,     1,     0,    23,    12,     3,    72,
       0,     5,     0,     7,     0,     6,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     2,    23,     0,     0,    11,
       0,     0,     0,    13,    17,    15,    19,    65,    66,    67,
       0,     0,     0,     0,    39,    44,    51,    54,    58,    60,
      64,    69,     0,     0,    36,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,    63,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,    24,     0,    41,    69,     0,     0,     0,     0,
       0,     0,     0,     8,    10,     9,     0,     0,     0,     0,
      61,    38,    42,    43,    45,    46,    48,    50,    47,    49,
      52,    53,    55,    56,    57,    59,     0,    35,     0,     0,
       0,    31,    29,    70,    27,    30,    28,     0,     0,     0,
       0,    68,    23,    40,    23,    23,    23,    23,    23,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    14,     0,
      18,    16,    20,     0,     0,    23,    21,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    16,    17,    76,    78,    77,    79,
     161,   162,    36,    62,    53,   103,   104,    55,    56,    57,
      58,    59,    60,    37,    61,    20
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
      82,     1,     6,     8,    12,    30,    82,   -48,    54,    34,
      54,    37,    54,    40,   -48,     7,    97,    30,   -48,   -48,
      43,   -48,    59,   -48,   109,   -48,    74,   147,   149,   155,
      46,    46,    46,   127,   128,   -48,    97,   125,    96,   -48,
     160,   160,   160,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
      46,    46,    46,    -5,    90,   -48,    78,    93,   -48,   121,
     -48,   135,   137,   130,    38,    98,    46,    46,   -48,    16,
      46,   136,    25,   139,   141,   142,   140,   143,   144,   145,
     -48,    76,   -48,   -48,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    13,    13,    13,    46,    46,
     -48,    46,   -48,   146,    90,    15,    81,   151,   152,    80,
     153,   154,   156,   -48,   -48,   -48,   157,   158,   159,   161,
     -48,    90,   -48,   -48,    91,    91,    91,    91,    91,    91,
      93,    93,   -48,   -48,   -48,   -48,    84,    64,   150,   162,
     163,   -48,   -48,   -48,   -48,   -48,   -48,   164,   165,   166,
     167,   -48,    97,   -48,    97,    97,    97,    97,    97,   138,
     168,   169,   171,   170,   172,   173,   174,   -48,   -48,    46,
     -48,   -48,   -48,   175,   102,    97,   -48,   176,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   181,   -48,   185,   -48,   -48,   -48,   -48,   -48,
     -14,   -13,   -48,   -48,   179,   -47,   -25,    61,    -8,    55,
     -48,   -42,    41,   -48,    -1,    60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
       9,    11,    13,    35,     7,    54,    64,    65,    80,     7,
      82,     7,    14,    26,    27,    38,     7,    47,    48,     7,
      47,    48,   108,    68,    83,   112,    81,    28,     7,    47,
      48,     8,    84,    29,    49,    38,    10,    49,    12,    73,
      74,    75,   106,    50,   107,    99,    49,   139,    51,     7,
      47,    48,    50,   111,    15,    52,   135,    51,    19,   121,
      85,    86,   109,    21,    52,   105,    23,    49,   105,    25,
      22,   105,    24,    50,    40,   -39,   137,    43,    51,   124,
     125,   126,   127,   128,   129,    52,    85,    86,     1,     2,
      41,   136,    87,    88,    89,    90,    91,    92,    85,    86,
       7,   -38,     3,    85,    86,    30,    31,    32,    33,   120,
      34,   143,    85,    86,   140,   151,    93,    94,    93,    94,
      85,    86,    93,    94,    85,    86,    70,   102,    71,    93,
      94,   176,    72,    95,    96,    97,   132,   133,   134,   159,
      42,   160,   163,   164,   174,   165,   122,   123,   130,   131,
      44,    38,    45,    38,    38,    38,    38,    38,    46,    66,
      67,    69,   177,     7,    98,    99,   100,   101,   113,   110,
     114,   115,   116,   166,    38,   117,   118,   119,     0,   138,
     141,   142,   144,   145,   152,   146,   173,    18,     0,     0,
     147,   148,   149,     0,   150,   153,   169,   154,   155,   156,
     157,   158,    39,   167,   168,   170,     0,   171,   172,   175,
      63,   178
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    16,     3,    30,    31,    32,    50,     3,
      52,     3,     0,     6,     7,    16,     3,     4,     5,     3,
       4,     5,    69,    36,    29,    72,    51,    20,     3,     4,
       5,    30,    37,    26,    21,    36,    30,    21,    30,    40,
      41,    42,    67,    27,    28,    30,    21,    32,    32,     3,
       4,     5,    27,    28,    24,    39,    98,    32,     4,    84,
      22,    23,    70,    29,    39,    66,    29,    21,    69,    29,
      10,    72,    12,    27,    31,    37,   101,     3,    32,    87,
      88,    89,    90,    91,    92,    39,    22,    23,     6,     7,
      31,    99,    14,    15,    16,    17,    18,    19,    22,    23,
       3,    37,    20,    22,    23,     8,     9,    10,    11,    33,
      13,    31,    22,    23,    33,    31,    38,    39,    38,    39,
      22,    23,    38,    39,    22,    23,    30,    29,    32,    38,
      39,    29,    36,    40,    41,    42,    95,    96,    97,   152,
      31,   154,   156,   157,   169,   158,    85,    86,    93,    94,
       3,   152,     3,   154,   155,   156,   157,   158,     3,    32,
      32,    36,   175,     3,    43,    30,    29,    37,    29,    33,
      29,    29,    32,    35,   175,    32,    32,    32,    -1,    33,
      29,    29,    29,    29,    34,    29,    12,     6,    -1,    -1,
      33,    33,    33,    -1,    33,    33,    25,    34,    34,    34,
      34,    34,    17,    35,    35,    35,    -1,    35,    35,    34,
      31,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    20,    45,    46,    47,     3,    30,    68,
      30,    68,    30,    68,     0,    24,    48,    49,    46,     4,
      69,    29,    69,    29,    69,    29,     6,     7,    20,    26,
       8,     9,    10,    11,    13,    55,    56,    67,    68,    48,
      31,    31,    31,     3,     3,     3,     3,     4,     5,    21,
      27,    32,    39,    58,    60,    61,    62,    63,    64,    65,
      66,    68,    57,    58,    60,    60,    32,    32,    55,    36,
      30,    32,    36,    68,    68,    68,    50,    52,    51,    53,
      65,    60,    65,    29,    37,    22,    23,    14,    15,    16,
      17,    18,    19,    38,    39,    40,    41,    42,    43,    30,
      29,    37,    29,    59,    60,    68,    60,    28,    59,    62,
      33,    28,    59,    29,    29,    29,    32,    32,    32,    32,
      33,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    66,    66,    66,    65,    62,    60,    33,    32,
      33,    29,    29,    31,    29,    29,    29,    33,    33,    33,
      33,    31,    34,    33,    34,    34,    34,    34,    34,    55,
      55,    54,    55,    54,    54,    55,    35,    35,    35,    25,
      35,    35,    35,    12,    60,    34,    29,    55,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1778 of yacc.c  */
#line 78 "parser.y"
    {Finish((yyvsp[(3) - (3)].InstrSeq)); }
    break;

  case 3:
/* Line 1778 of yacc.c  */
#line 80 "parser.y"
    {}
    break;

  case 4:
/* Line 1778 of yacc.c  */
#line 81 "parser.y"
    {}
    break;

  case 5:
/* Line 1778 of yacc.c  */
#line 83 "parser.y"
    {EnterName(table, (yyvsp[(2) - (3)].string), &entry); SetAttr(entry, "int");}
    break;

  case 6:
/* Line 1778 of yacc.c  */
#line 84 "parser.y"
    {EnterName(table, (yyvsp[(2) - (3)].string), &entry); SetAttr(entry, "bool");}
    break;

  case 7:
/* Line 1778 of yacc.c  */
#line 85 "parser.y"
    {EnterName(table, (yyvsp[(2) - (3)].string), &entry); SetAttr(entry, "float");}
    break;

  case 8:
/* Line 1778 of yacc.c  */
#line 87 "parser.y"
    {EnterName(table, (yyvsp[(5) - (6)].string), &entry); SetAttr(entry, "intarr");decArr((yyvsp[(5) - (6)].string), (yyvsp[(3) - (6)].val));}
    break;

  case 9:
/* Line 1778 of yacc.c  */
#line 88 "parser.y"
    {EnterName(table, (yyvsp[(5) - (6)].string), &entry); SetAttr(entry, "boolarr");decArr((yyvsp[(5) - (6)].string), (yyvsp[(3) - (6)].val));}
    break;

  case 10:
/* Line 1778 of yacc.c  */
#line 89 "parser.y"
    {EnterName(table, (yyvsp[(5) - (6)].string), &entry); SetAttr(entry, "floatarr");decArr((yyvsp[(5) - (6)].string), (yyvsp[(3) - (6)].val));}
    break;

  case 11:
/* Line 1778 of yacc.c  */
#line 91 "parser.y"
    {}
    break;

  case 12:
/* Line 1778 of yacc.c  */
#line 92 "parser.y"
    {}
    break;

  case 13:
/* Line 1778 of yacc.c  */
#line 94 "parser.y"
    {EnterName(funcTable, yytext, &entry);  SetAttr(entry, "int"); }
    break;

  case 14:
/* Line 1778 of yacc.c  */
#line 94 "parser.y"
    {doFuncDec(entry->Name, (yyvsp[(8) - (9)].InstrSeq));}
    break;

  case 15:
/* Line 1778 of yacc.c  */
#line 95 "parser.y"
    {EnterName(funcTable, yytext, &entry); SetAttr(entry, "bool"); }
    break;

  case 16:
/* Line 1778 of yacc.c  */
#line 95 "parser.y"
    {doFuncDec(entry->Name, (yyvsp[(8) - (9)].InstrSeq));}
    break;

  case 17:
/* Line 1778 of yacc.c  */
#line 96 "parser.y"
    {EnterName(funcTable, yytext, &entry); SetAttr(entry, "float"); }
    break;

  case 18:
/* Line 1778 of yacc.c  */
#line 96 "parser.y"
    {doFuncDec(entry->Name, (yyvsp[(8) - (9)].InstrSeq));}
    break;

  case 19:
/* Line 1778 of yacc.c  */
#line 97 "parser.y"
    {EnterName(funcTable, yytext, &entry); SetAttr(entry, "void"); }
    break;

  case 20:
/* Line 1778 of yacc.c  */
#line 97 "parser.y"
    {doFuncDec(entry->Name, (yyvsp[(8) - (9)].InstrSeq));}
    break;

  case 21:
/* Line 1778 of yacc.c  */
#line 99 "parser.y"
    {(yyval.InstrSeq) = AppendSeq((yyvsp[(1) - (4)].InstrSeq), doReturn((yyvsp[(3) - (4)].ExprRes))); }
    break;

  case 22:
/* Line 1778 of yacc.c  */
#line 101 "parser.y"
    {(yyval.InstrSeq) = AppendSeq((yyvsp[(1) - (2)].InstrSeq), (yyvsp[(2) - (2)].InstrSeq)); }
    break;

  case 23:
/* Line 1778 of yacc.c  */
#line 102 "parser.y"
    {(yyval.InstrSeq) = NULL;}
    break;

  case 24:
/* Line 1778 of yacc.c  */
#line 104 "parser.y"
    {(yyval.InstrSeq) = doPrintSpace((yyvsp[(2) - (3)].ExprRes));}
    break;

  case 25:
/* Line 1778 of yacc.c  */
#line 105 "parser.y"
    {(yyval.InstrSeq) = (yyvsp[(2) - (3)].InstrSeq);}
    break;

  case 26:
/* Line 1778 of yacc.c  */
#line 106 "parser.y"
    {(yyval.InstrSeq) = (yyvsp[(2) - (3)].InstrSeq);}
    break;

  case 27:
/* Line 1778 of yacc.c  */
#line 108 "parser.y"
    {(yyval.InstrSeq) = doFunc((yyvsp[(1) - (4)].string));}
    break;

  case 28:
/* Line 1778 of yacc.c  */
#line 110 "parser.y"
    {(yyval.InstrSeq) = doAssign((yyvsp[(1) - (4)].string), NULL, (yyvsp[(3) - (4)].ExprRes));}
    break;

  case 29:
/* Line 1778 of yacc.c  */
#line 111 "parser.y"
    {(yyval.InstrSeq) = doAssign(NULL, (yyvsp[(1) - (4)].ExprRes), (yyvsp[(3) - (4)].ExprRes));}
    break;

  case 30:
/* Line 1778 of yacc.c  */
#line 112 "parser.y"
    {(yyval.InstrSeq) = read((yyvsp[(1) - (4)].string), NULL); }
    break;

  case 31:
/* Line 1778 of yacc.c  */
#line 113 "parser.y"
    {(yyval.InstrSeq) = read(NULL, (yyvsp[(1) - (4)].ExprRes));}
    break;

  case 32:
/* Line 1778 of yacc.c  */
#line 115 "parser.y"
    {(yyval.InstrSeq) = doIfElse((yyvsp[(3) - (11)].ExprRes), (yyvsp[(6) - (11)].InstrSeq), (yyvsp[(10) - (11)].InstrSeq));}
    break;

  case 33:
/* Line 1778 of yacc.c  */
#line 116 "parser.y"
    {(yyval.InstrSeq) = doIf((yyvsp[(3) - (7)].ExprRes), (yyvsp[(6) - (7)].InstrSeq));}
    break;

  case 34:
/* Line 1778 of yacc.c  */
#line 117 "parser.y"
    {(yyval.InstrSeq) = doWhile((yyvsp[(3) - (7)].ExprRes), (yyvsp[(6) - (7)].InstrSeq));}
    break;

  case 35:
/* Line 1778 of yacc.c  */
#line 119 "parser.y"
    {(yyval.InstrSeq) = doPrintln((yyvsp[(1) - (3)].InstrSeq), (yyvsp[(3) - (3)].ExprRes));}
    break;

  case 36:
/* Line 1778 of yacc.c  */
#line 120 "parser.y"
    {(yyval.InstrSeq) = doPrintln(NULL, (yyvsp[(1) - (1)].ExprRes));}
    break;

  case 37:
/* Line 1778 of yacc.c  */
#line 121 "parser.y"
    {(yyval.InstrSeq) = doPrintln(NULL, NULL);}
    break;

  case 38:
/* Line 1778 of yacc.c  */
#line 123 "parser.y"
    {(yyval.InstrSeq) = doPrint((yyvsp[(1) - (3)].InstrSeq), (yyvsp[(3) - (3)].ExprRes));}
    break;

  case 39:
/* Line 1778 of yacc.c  */
#line 124 "parser.y"
    {(yyval.InstrSeq) = doPrint(NULL, (yyvsp[(1) - (1)].ExprRes));}
    break;

  case 40:
/* Line 1778 of yacc.c  */
#line 126 "parser.y"
    {(yyval.ExprRes) = doFuncReturn((yyvsp[(1) - (3)].string));}
    break;

  case 41:
/* Line 1778 of yacc.c  */
#line 127 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes);}
    break;

  case 42:
/* Line 1778 of yacc.c  */
#line 129 "parser.y"
    {(yyval.ExprRes) = doBoolOp((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "and");}
    break;

  case 43:
/* Line 1778 of yacc.c  */
#line 130 "parser.y"
    {(yyval.ExprRes) = doBoolOp((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "or");}
    break;

  case 44:
/* Line 1778 of yacc.c  */
#line 131 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes);}
    break;

  case 45:
/* Line 1778 of yacc.c  */
#line 133 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "beq");}
    break;

  case 46:
/* Line 1778 of yacc.c  */
#line 134 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "bne");}
    break;

  case 47:
/* Line 1778 of yacc.c  */
#line 135 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "bgt");}
    break;

  case 48:
/* Line 1778 of yacc.c  */
#line 136 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "blt");}
    break;

  case 49:
/* Line 1778 of yacc.c  */
#line 137 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "bge");}
    break;

  case 50:
/* Line 1778 of yacc.c  */
#line 138 "parser.y"
    {(yyval.ExprRes) = doBExpr((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "ble");}
    break;

  case 51:
/* Line 1778 of yacc.c  */
#line 139 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes);}
    break;

  case 52:
/* Line 1778 of yacc.c  */
#line 141 "parser.y"
    {(yyval.ExprRes) = doBinArith((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "add"); }
    break;

  case 53:
/* Line 1778 of yacc.c  */
#line 142 "parser.y"
    {(yyval.ExprRes) = doBinArith((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "sub"); }
    break;

  case 54:
/* Line 1778 of yacc.c  */
#line 143 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes); }
    break;

  case 55:
/* Line 1778 of yacc.c  */
#line 145 "parser.y"
    {(yyval.ExprRes) = doBinArith((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "mul"); }
    break;

  case 56:
/* Line 1778 of yacc.c  */
#line 146 "parser.y"
    {(yyval.ExprRes) = doBinArith((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "div"); }
    break;

  case 57:
/* Line 1778 of yacc.c  */
#line 147 "parser.y"
    {(yyval.ExprRes) = doBinArith((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes), "rem"); }
    break;

  case 58:
/* Line 1778 of yacc.c  */
#line 148 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes); }
    break;

  case 59:
/* Line 1778 of yacc.c  */
#line 150 "parser.y"
    {(yyval.ExprRes) = doExponent((yyvsp[(1) - (3)].ExprRes), (yyvsp[(3) - (3)].ExprRes)); }
    break;

  case 60:
/* Line 1778 of yacc.c  */
#line 151 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes); }
    break;

  case 61:
/* Line 1778 of yacc.c  */
#line 153 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(2) - (3)].ExprRes); }
    break;

  case 62:
/* Line 1778 of yacc.c  */
#line 154 "parser.y"
    {(yyval.ExprRes) = not((yyvsp[(2) - (2)].ExprRes)); }
    break;

  case 63:
/* Line 1778 of yacc.c  */
#line 155 "parser.y"
    {(yyval.ExprRes) = neg((yyvsp[(2) - (2)].ExprRes)); }
    break;

  case 64:
/* Line 1778 of yacc.c  */
#line 156 "parser.y"
    {(yyval.ExprRes) = (yyvsp[(1) - (1)].ExprRes); }
    break;

  case 65:
/* Line 1778 of yacc.c  */
#line 158 "parser.y"
    {(yyval.ExprRes) = doIntLit(yytext); }
    break;

  case 66:
/* Line 1778 of yacc.c  */
#line 159 "parser.y"
    {(yyval.ExprRes) = doFltLit(yytext); }
    break;

  case 67:
/* Line 1778 of yacc.c  */
#line 161 "parser.y"
    {(yyval.ExprRes) = doBoolLit(yytext);}
    break;

  case 68:
/* Line 1778 of yacc.c  */
#line 162 "parser.y"
    {(yyval.ExprRes) = doRval((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].ExprRes)); }
    break;

  case 69:
/* Line 1778 of yacc.c  */
#line 163 "parser.y"
    {(yyval.ExprRes) = doRval((yyvsp[(1) - (1)].string), NULL); }
    break;

  case 70:
/* Line 1778 of yacc.c  */
#line 165 "parser.y"
    {(yyval.ExprRes) = doRval((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].ExprRes)); }
    break;

  case 71:
/* Line 1778 of yacc.c  */
#line 167 "parser.y"
    {(yyval.string) = strdup(yytext);}
    break;

  case 72:
/* Line 1778 of yacc.c  */
#line 171 "parser.y"
    {(yyval.val) = atoi(yytext); }
    break;


/* Line 1778 of yacc.c  */
#line 1987 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2041 of yacc.c  */
#line 173 "parser.y"




yyerror(char *s)  {
  WriteIndicator(GetCurrentColumn());
  WriteMessage(s);
}

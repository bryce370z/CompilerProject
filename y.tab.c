/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     END = 259,
     DATA = 260,
     ALGORITHM = 261,
     EXIT = 262,
     IF = 263,
     ELSE = 264,
     DO = 265,
     WHILE = 266,
     COUNTING = 267,
     UPWARD = 268,
     DOWNWARD = 269,
     TO = 270,
     READ = 271,
     PRINT = 272,
     INTEGER = 273,
     REAL = 274,
     SEMICOLON = 275,
     COLON = 276,
     CARRIAGE_RETURN = 277,
     LPAREN = 278,
     RPAREN = 279,
     COMMA = 280,
     RBRACKET = 281,
     LBRACKET = 282,
     LBRACE = 283,
     RBRACE = 284,
     VARIABLE = 285,
     INT = 286,
     FLOAT = 287,
     PLUS = 288,
     MINUS = 289,
     MULT = 290,
     DIV = 291,
     MOD = 292,
     LESSTHAN = 293,
     LESSTHANEQ = 294,
     GREATERTHAN = 295,
     GREATERTHANEQ = 296,
     EQUAL = 297,
     NOTEQ = 298,
     AND = 299,
     OR = 300,
     NOT = 301,
     ASSIGN = 302,
     STRING = 303,
     TRASH = 304
   };
#endif
/* Tokens.  */
#define MAIN 258
#define END 259
#define DATA 260
#define ALGORITHM 261
#define EXIT 262
#define IF 263
#define ELSE 264
#define DO 265
#define WHILE 266
#define COUNTING 267
#define UPWARD 268
#define DOWNWARD 269
#define TO 270
#define READ 271
#define PRINT 272
#define INTEGER 273
#define REAL 274
#define SEMICOLON 275
#define COLON 276
#define CARRIAGE_RETURN 277
#define LPAREN 278
#define RPAREN 279
#define COMMA 280
#define RBRACKET 281
#define LBRACKET 282
#define LBRACE 283
#define RBRACE 284
#define VARIABLE 285
#define INT 286
#define FLOAT 287
#define PLUS 288
#define MINUS 289
#define MULT 290
#define DIV 291
#define MOD 292
#define LESSTHAN 293
#define LESSTHANEQ 294
#define GREATERTHAN 295
#define GREATERTHANEQ 296
#define EQUAL 297
#define NOTEQ 298
#define AND 299
#define OR 300
#define NOT 301
#define ASSIGN 302
#define STRING 303
#define TRASH 304




/* Copy the first part of user declarations.  */
#line 1 "Parser.y"

  /*--------------------*/
  /*    Bryce Skelton   */
  /*    Checkpoint 4    */
  /*      10/11/17      */
  /*--------------------*/
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "structs.h"
  #define PRINT_TABLE 0

  /* symbol table */
  struct symbol symbol_array[500];
  int address = 0;
  int pos= 0;
  char *new_type;

  /*AST*/
  struct statement * stmt_list;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "Parser.y"
{
  // symbol table
  char* name;
  char* datatype;
  char* rbracket;
  char* lbracket;
  int ival;
  float fval;

  //AST
  char* p_string;
  struct statement* new_statement;
  struct expression* new_expression;
  struct print* new_print;

}
/* Line 193 of yacc.c.  */
#line 233 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 246 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    15,    16,    19,    24,    28,    30,
      32,    34,    36,    41,    45,    48,    50,    55,    63,    71,
      82,    90,    94,    98,   105,   108,   112,   114,   116,   118,
     120,   124,   128,   131,   133,   137,   141,   145,   149,   153,
     157,   159,   163,   167,   169,   173,   177,   181,   183,   187,
     190,   192,   194,   196,   198
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,     3,    20,    52,    58,     4,     3,    20,
      -1,     5,    21,    53,    -1,    -1,    53,    54,    -1,    56,
      21,    55,    20,    -1,    55,    25,    57,    -1,    57,    -1,
      18,    -1,    19,    -1,    30,    -1,    30,    27,    31,    26,
      -1,     6,    21,    59,    -1,    60,    59,    -1,    60,    -1,
      30,    47,    63,    20,    -1,    30,    27,    63,    26,    47,
      63,    20,    -1,     8,    63,    20,    59,     4,     8,    20,
      -1,     8,    63,    20,    59,     9,    20,    59,     4,     8,
      20,    -1,    11,    63,    20,    59,     4,    11,    20,    -1,
      17,    61,    20,    -1,    16,    30,    20,    -1,    16,    30,
      27,    63,    26,    20,    -1,     7,    20,    -1,    61,    25,
      62,    -1,    62,    -1,    63,    -1,    22,    -1,    48,    -1,
      63,    44,    64,    -1,    63,    45,    64,    -1,    46,    64,
      -1,    64,    -1,    64,    38,    65,    -1,    64,    39,    65,
      -1,    64,    40,    65,    -1,    64,    41,    65,    -1,    64,
      42,    65,    -1,    64,    43,    65,    -1,    65,    -1,    65,
      33,    66,    -1,    65,    34,    66,    -1,    66,    -1,    66,
      35,    67,    -1,    66,    36,    67,    -1,    66,    37,    67,
      -1,    67,    -1,    23,    63,    24,    -1,    34,    67,    -1,
      68,    -1,    31,    -1,    32,    -1,    30,    -1,    30,    27,
      63,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   105,   109,   110,   114,   118,   119,   123,
     127,   134,   146,   161,   167,   172,   179,   187,   196,   204,
     213,   221,   228,   235,   243,   249,   254,   261,   267,   273,
     281,   289,   297,   304,   311,   319,   327,   335,   343,   351,
     359,   366,   376,   384,   390,   398,   406,   414,   420,   424,
     432,   439,   446,   453,   471
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "END", "DATA", "ALGORITHM",
  "EXIT", "IF", "ELSE", "DO", "WHILE", "COUNTING", "UPWARD", "DOWNWARD",
  "TO", "READ", "PRINT", "INTEGER", "REAL", "SEMICOLON", "COLON",
  "CARRIAGE_RETURN", "LPAREN", "RPAREN", "COMMA", "RBRACKET", "LBRACKET",
  "LBRACE", "RBRACE", "VARIABLE", "INT", "FLOAT", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "LESSTHAN", "LESSTHANEQ", "GREATERTHAN", "GREATERTHANEQ",
  "EQUAL", "NOTEQ", "AND", "OR", "NOT", "ASSIGN", "STRING", "TRASH",
  "$accept", "prog", "datasec", "vartable", "vardec", "varlist",
  "datatype", "dataholder", "algosec", "algobody", "algoline", "printlist",
  "printable", "statement", "comparison", "exp", "term", "factor", "atom", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     0,     2,     4,     3,     1,     1,
       1,     1,     4,     3,     2,     1,     4,     7,     7,    10,
       7,     3,     3,     6,     2,     3,     1,     1,     1,     1,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     2,
       1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     0,     0,
       3,     0,     0,     9,    10,     5,     0,     0,     0,     0,
       0,     0,     0,    13,    15,     0,     0,    24,     0,    53,
      51,    52,     0,     0,     0,    33,    40,    43,    47,    50,
       0,     0,    28,    29,     0,    26,    27,     0,     0,    14,
       2,    11,     0,     8,     0,     0,    49,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    21,     0,     0,     0,     0,
       6,     0,    48,     0,     0,    30,    31,    34,    35,    36,
      37,    38,    39,    41,    42,    44,    45,    46,     0,     0,
      25,     0,    16,     0,     7,    54,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    23,     0,    18,     0,    20,
      17,     0,     0,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    10,    15,    52,    16,    53,     9,    23,
      24,    44,    45,    46,    35,    36,    37,    38,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int8 yypact[] =
{
      13,     2,    28,    44,   -50,    14,    51,   -50,    45,    76,
      92,    54,    69,   -50,   -50,   -50,    62,    65,   -19,   -19,
      66,    21,   -21,   -50,    54,    70,    84,   -50,   -19,    88,
     -50,   -50,    63,    63,   -11,    60,   -26,    52,   -50,   -50,
      -6,    -3,   -50,   -50,     0,   -50,    68,   -19,   -19,   -50,
     -50,    89,    39,   -50,    30,   -19,   -50,    60,    54,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    54,   -50,   -19,   -50,    21,    32,     1,    86,
     -50,    84,   -50,    34,    64,    60,    60,   -26,   -26,   -26,
     -26,   -26,   -26,    52,    52,   -50,   -50,   -50,   114,    37,
     -50,    72,   -50,    94,   -50,   -50,   113,   102,   112,   104,
     -19,   -50,   105,    54,   106,   -50,     3,   -50,   123,   -50,
     -50,   120,   109,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -50,    49,   -50,   -22,
     -50,   -50,    55,   -18,   -28,    43,   -49,   -29,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    40,    49,    56,    28,    57,    47,    67,    68,    58,
      54,    29,    30,    31,    72,    32,     1,    73,    93,    94,
      75,   102,     3,   120,    74,    76,    48,    33,     4,    77,
      78,    85,    86,    59,    60,     7,    84,    83,    59,    60,
      95,    96,    97,    42,    28,    59,    60,    59,    60,     5,
      98,    29,    30,    31,    82,    32,    99,     8,   101,    80,
     105,    17,    18,   109,    81,    19,    11,    33,   106,    43,
      20,    21,    25,   107,    59,    60,    59,    60,    59,    60,
      12,    59,    60,    26,    22,    27,    28,    69,    70,    71,
      50,   118,   116,    29,    30,    31,    41,    32,    61,    62,
      63,    64,    65,    66,    87,    88,    89,    90,    91,    92,
      13,    14,    59,    60,    51,    55,    79,   103,   108,   110,
     111,   112,   113,   114,   115,   117,   119,   121,   122,   123,
     104,   100
};

static const yytype_uint8 yycheck[] =
{
      18,    19,    24,    32,    23,    33,    27,    33,    34,    20,
      28,    30,    31,    32,    20,    34,     3,    20,    67,    68,
      20,    20,    20,    20,    27,    25,    47,    46,     0,    47,
      48,    59,    60,    44,    45,    21,    58,    55,    44,    45,
      69,    70,    71,    22,    23,    44,    45,    44,    45,     5,
      72,    30,    31,    32,    24,    34,    74,     6,    26,    20,
      26,     7,     8,    26,    25,    11,    21,    46,     4,    48,
      16,    17,     3,     9,    44,    45,    44,    45,    44,    45,
       4,    44,    45,    21,    30,    20,    23,    35,    36,    37,
      20,   113,   110,    30,    31,    32,    30,    34,    38,    39,
      40,    41,    42,    43,    61,    62,    63,    64,    65,    66,
      18,    19,    44,    45,    30,    27,    27,    31,     4,    47,
      26,     8,    20,    11,    20,    20,    20,     4,     8,    20,
      81,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    51,    20,     0,     5,    52,    21,     6,    58,
      53,    21,     4,    18,    19,    54,    56,     7,     8,    11,
      16,    17,    30,    59,    60,     3,    21,    20,    23,    30,
      31,    32,    34,    46,    63,    64,    65,    66,    67,    68,
      63,    30,    22,    48,    61,    62,    63,    27,    47,    59,
      20,    30,    55,    57,    63,    27,    67,    64,    20,    44,
      45,    38,    39,    40,    41,    42,    43,    33,    34,    35,
      36,    37,    20,    20,    27,    20,    25,    63,    63,    27,
      20,    25,    24,    63,    59,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    59,    63,
      62,    26,    20,    31,    57,    26,     4,     9,     4,    26,
      47,    26,     8,    20,    11,    20,    63,    20,    59,    20,
      20,     4,     8,    20
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 9:
#line 124 "Parser.y"
    {
  new_type = (yyvsp[(1) - (1)].datatype);
}
    break;

  case 10:
#line 128 "Parser.y"
    {
  new_type = (yyvsp[(1) - (1)].datatype);
}
    break;

  case 11:
#line 135 "Parser.y"
    {
  symbol_array[pos].name = (yyvsp[(1) - (1)].name);
  symbol_array[pos].datatype = new_type;
  symbol_array[pos].address = address;
  symbol_array[pos].kind = "scalar";
  if(PRINT_TABLE == 1){
    printf("name:%s address:%i datatype:%s kind:%s\n",symbol_array[pos].name, symbol_array[pos].address, symbol_array[pos].datatype, symbol_array[pos].kind);
  }
  pos++;
  address++;
}
    break;

  case 12:
#line 147 "Parser.y"
    {
  symbol_array[pos].name = (yyvsp[(1) - (4)].name);
  symbol_array[pos].datatype = new_type;
  symbol_array[pos].address = address;
  symbol_array[pos].kind = "array dec";
  if(PRINT_TABLE == 1){
    printf("name:%s address:%i datatype:%s kind:%s\n", symbol_array[pos].name, symbol_array[pos].address, symbol_array[pos].datatype, symbol_array[pos].kind);
  }
  pos++;
  address += (yyvsp[(3) - (4)].ival);
}
    break;

  case 13:
#line 162 "Parser.y"
    {
  stmt_list = (yyvsp[(3) - (3)].new_statement);
}
    break;

  case 14:
#line 168 "Parser.y"
    {
  (yyvsp[(1) - (2)].new_statement)->next = (yyvsp[(2) - (2)].new_statement);
  (yyval.new_statement) = (yyvsp[(1) - (2)].new_statement);
}
    break;

  case 15:
#line 173 "Parser.y"
    {
  (yyval.new_statement) = (yyvsp[(1) - (1)].new_statement);
}
    break;

  case 16:
#line 180 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_ASSIGN;
  (yyval.new_statement)->var = (yyvsp[(1) - (4)].name);
  (yyval.new_statement)->expression = (yyvsp[(3) - (4)].new_expression);
  (yyval.new_statement)->next = NULL;
}
    break;

  case 17:
#line 188 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_ASSIGN;
  (yyval.new_statement)->var = (yyvsp[(1) - (7)].name);
  (yyval.new_statement)->var_array_expresssion = (yyvsp[(3) - (7)].new_expression);
  (yyval.new_statement)->expression = (yyvsp[(6) - (7)].new_expression);
  (yyval.new_statement)->next = NULL;
}
    break;

  case 18:
#line 197 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_IF;
  (yyval.new_statement)->expression = (yyvsp[(2) - (7)].new_expression);
  (yyval.new_statement)->next = NULL;
  (yyval.new_statement)->body = (yyvsp[(4) - (7)].new_statement);
}
    break;

  case 19:
#line 205 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_IF_ELSE;
  (yyval.new_statement)->expression = (yyvsp[(2) - (10)].new_expression);
  (yyval.new_statement)->next = NULL;
  (yyval.new_statement)->body = (yyvsp[(4) - (10)].new_statement);
  (yyval.new_statement)->else_body = (yyvsp[(7) - (10)].new_statement);
}
    break;

  case 20:
#line 214 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_WHILE;
  (yyval.new_statement)->expression = (yyvsp[(2) - (7)].new_expression);
  (yyval.new_statement)->next = NULL;
  (yyval.new_statement)->body = (yyvsp[(4) - (7)].new_statement);
}
    break;

  case 21:
#line 222 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_PRINT;
  (yyval.new_statement)->print = (yyvsp[(2) - (3)].new_print);
  (yyval.new_statement)->next = NULL;
}
    break;

  case 22:
#line 229 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_READ;
  (yyval.new_statement)->var = (yyvsp[(2) - (3)].name);
  (yyval.new_statement)->next = NULL;
}
    break;

  case 23:
#line 236 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_READ;
  (yyval.new_statement)->expression = (yyvsp[(4) - (6)].new_expression);
  (yyval.new_statement)->var = (yyvsp[(2) - (6)].name);
  (yyval.new_statement)->next = NULL;
}
    break;

  case 24:
#line 244 "Parser.y"
    {
  (yyval.new_statement) = malloc(sizeof(struct statement));
  (yyval.new_statement)->kind = STMT_EXIT;
  (yyval.new_statement)->next = NULL;
}
    break;

  case 25:
#line 250 "Parser.y"
    {
  (yyvsp[(1) - (3)].new_print)->next = (yyvsp[(3) - (3)].new_print);
  (yyval.new_print) = (yyvsp[(1) - (3)].new_print);
}
    break;

  case 26:
#line 255 "Parser.y"
    {
  (yyval.new_print) = (yyvsp[(1) - (1)].new_print);
}
    break;

  case 27:
#line 262 "Parser.y"
    {
  (yyval.new_print) = malloc(sizeof(struct print));
  (yyval.new_print)->kind = P_EXPR_KIND;
  (yyval.new_print)->p_expr = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 28:
#line 268 "Parser.y"
    {
  (yyval.new_print) = malloc(sizeof(struct print));
  (yyval.new_print)->kind = P_NEWLINE_KIND;
  (yyval.new_print)->newline = 1;
}
    break;

  case 29:
#line 274 "Parser.y"
    {
  (yyval.new_print) = malloc(sizeof(struct print));
  (yyval.new_print)->kind = P_STR_KIND;
  (yyval.new_print)->p_string = (yyvsp[(1) - (1)].p_string);
}
    break;

  case 30:
#line 282 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = AND_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 31:
#line 290 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = OR_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 32:
#line 298 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = NOT_OP;
  (yyval.new_expression)->right_op = (yyvsp[(2) - (2)].new_expression);
}
    break;

  case 33:
#line 305 "Parser.y"
    {
  (yyval.new_expression) = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 34:
#line 312 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = LESSTHAN_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 35:
#line 320 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = LESSTHANEQ_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 36:
#line 328 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = GREATERTHAN_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 37:
#line 336 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = GREATERTHANEQ_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 38:
#line 344 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = EQUAL_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 39:
#line 352 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = NOTEQ_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 40:
#line 360 "Parser.y"
    {
   (yyval.new_expression) = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 41:
#line 367 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = ADD_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 42:
#line 377 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = MINUS_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 43:
#line 385 "Parser.y"
    {
  (yyval.new_expression) = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 44:
#line 391 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = MULT_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 45:
#line 399 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = DIV_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 46:
#line 407 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = MOD_OP;
  (yyval.new_expression)->left_op = (yyvsp[(1) - (3)].new_expression);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (3)].new_expression);
}
    break;

  case 47:
#line 415 "Parser.y"
    {
  (yyval.new_expression) = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 48:
#line 421 "Parser.y"
    {
  (yyval.new_expression) = (yyvsp[(2) - (3)].new_expression);
}
    break;

  case 49:
#line 425 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = EXPR_KIND;
  (yyval.new_expression)->op_kind = U_MINUS_OP;
  (yyval.new_expression)->right_op = (yyvsp[(2) - (2)].new_expression);
  // printf("%i\n", $$->op_kind);
}
    break;

  case 50:
#line 433 "Parser.y"
    {
  (yyval.new_expression) = (yyvsp[(1) - (1)].new_expression);
}
    break;

  case 51:
#line 440 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = NUM_KIND;
  (yyval.new_expression)->value = (yyvsp[(1) - (1)].ival);
  (yyval.new_expression)->datatype = DT_INTEGER;
}
    break;

  case 52:
#line 447 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = NUM_KIND;
  (yyval.new_expression)->value = (yyvsp[(1) - (1)].fval);
  (yyval.new_expression)->datatype = DT_FLOAT;
}
    break;

  case 53:
#line 454 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = VAR_KIND;
  (yyval.new_expression)->var_name = (yyvsp[(1) - (1)].name);
  for(int i = 0; i < 500; i++){
    if(symbol_array[i].name != NULL){
      if(strcmp((yyvsp[(1) - (1)].name), symbol_array[i].name) == 0){
        if(strcmp(symbol_array[i].datatype, "real") == 0){
          (yyval.new_expression)->datatype = DT_FLOAT;
        }
        else{
          (yyval.new_expression)->datatype = DT_INTEGER;
        }
      }
    }
  }
}
    break;

  case 54:
#line 472 "Parser.y"
    {
  (yyval.new_expression) = malloc(sizeof(struct expression));
  (yyval.new_expression)->kind = ARRAY_KIND;
  (yyval.new_expression)->var_name = (yyvsp[(1) - (4)].name);
  (yyval.new_expression)->right_op = (yyvsp[(3) - (4)].new_expression);
  for(int i = 0; i < 500; i++){
    if(symbol_array[i].name != NULL){
      if(strcmp((yyvsp[(1) - (4)].name), symbol_array[i].name) == 0){
        if(strcmp(symbol_array[i].datatype, "real") == 0){
          (yyval.new_expression)->datatype = DT_FLOAT;
        }
        else{
          (yyval.new_expression)->datatype = DT_INTEGER;
        }
      }
    }
  }
}
    break;


/* Line 1267 of yacc.c.  */
#line 2020 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 492 "Parser.y"


int yyerror()
{
   printf("Called yyerror()\n");
   return 0;
}


/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "inter.y"

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <fstream>
#include "symTabParser.h"
using namespace std;

#define INTSIZE 4
#define FLOATSIZE 4

extern int yylex();
extern int yyparse();
extern int yylineno;
extern char* yytext;
extern int yyleng;
void yyerror(char* s);

FILE *mips;
string activeFunc;
int paramOffset;
string returnVal;
int floatLabel = 0;
vector<funcEntry> functionList;
vector<typeRecord> globalVariables;

void saveRegisters(int frameSize);
void retrieveRegisters(int frameSize);  
bool isGlobal;  

#line 103 "inter.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INTER_TAB_H_INCLUDED
# define YY_YY_INTER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEG = 259,
    END = 260,
    IF = 261,
    GOTO = 262,
    PARAM = 263,
    REFPARAM = 264,
    CALL = 265,
    LSB = 266,
    RSB = 267,
    RETURN = 268,
    NEWLINE = 269,
    CONVERTINT = 270,
    CONVERTFLOAT = 271,
    LP = 272,
    RP = 273,
    USERVAR = 274,
    REGINT = 275,
    REGFLOAT = 276,
    LABEL = 277,
    NUMINT = 278,
    NUMFLOAT = 279,
    PRINT = 280,
    READ = 281,
    COMMA = 282,
    COLON = 283,
    SEMI = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    MOD = 289,
    EQUAL = 290,
    NOTEQUAL = 291,
    OR = 292,
    AND = 293,
    LT = 294,
    GT = 295,
    LE = 296,
    GE = 297,
    ASSIGN = 298,
    NEG = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "inter.y"

    int intval;
    float floatval;
    char *idName;

#line 197 "inter.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTER_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   299

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    55,    56,    57,    61,    65,    66,
      73,    80,    84,    88,   107,   118,   129,   133,   138,   144,
     153,   162,   168,   177,   186,   192,   208,   217,   233,   239,
     243,   247,   252,   256,   260,   264,   268,   272,   277,   282,
     286,   290,   297,   301,   305,   309,   313,   319,   328,   334,
     350,   359,   373,   379,   383,   387,   391,   395,   399,   403,
     412,   421,   433,   445,   454,   463,   472,   483,   487,   491,
     495,   499,   509,   519,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEG", "END", "IF", "GOTO",
  "PARAM", "REFPARAM", "CALL", "LSB", "RSB", "RETURN", "NEWLINE",
  "CONVERTINT", "CONVERTFLOAT", "LP", "RP", "USERVAR", "REGINT",
  "REGFLOAT", "LABEL", "NUMINT", "NUMFLOAT", "PRINT", "READ", "COMMA",
  "COLON", "SEMI", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQUAL",
  "NOTEQUAL", "OR", "AND", "LT", "GT", "LE", "GE", "ASSIGN", "NEG",
  "$accept", "STMT_LIST", "STMT", "ASG", "FLOATASG", "IFSTMT", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -20

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    46,    -8,    -3,    49,    60,    25,    72,   -11,   -19,
      33,    40,    75,    77,     1,    95,   -20,   -20,   -20,    59,
     -20,    64,    66,   -20,   -20,   -20,   -20,   -20,    84,   -20,
     -20,   -18,    83,    52,    58,   -20,   -20,   -20,   -20,   -20,
     -20,    96,   -20,   -20,   -17,     5,     8,    22,    89,   101,
     102,   -20,   -20,    98,   105,    24,    48,   -20,   100,   107,
     -15,   -20,   -20,   112,   113,   114,   115,   116,   117,   118,
     119,   -20,    86,    88,   106,    18,    19,    71,   108,   110,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   111,
     129,   130,   131,   132,   133,   134,   135,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    85,    87,   155,   152,   162,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   157,
     164,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     8,     0,
      15,     0,     0,     6,     9,    10,    11,    12,     0,    17,
      18,     0,     0,     0,     0,     7,    19,    20,    21,    22,
       1,     0,     3,    14,     0,     0,     0,     0,     0,     0,
       0,    23,    47,     0,    26,    30,     0,    29,     0,    50,
      54,    53,     2,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    32,    35,    33,
      36,    37,    38,    39,    40,    42,    41,    43,    44,    45,
      46,    59,    60,    62,    61,    63,    64,    65,    66,     0,
       0,    55,    56,    57,    58,    67,    69,    68,    70,    71,
      73,    72,    74,    25,    49,    24,    48,    31,    27,    28,
      52,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -20,   -20,   163,   -20,   -20,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    40,    49,    63,     1,    50,    64,     2,     3,     4,
       5,     6,    21,    22,     7,    99,   100,   101,   102,    23,
       8,     9,    10,    11,    33,    65,    12,    13,    66,    67,
       1,    68,    32,     2,     3,     4,     5,     6,   114,   116,
       7,   115,   117,    69,    28,    70,     8,     9,    10,    11,
      19,    20,    12,    13,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    53,    35,    24,
      25,    54,    55,    56,    58,    57,    34,    59,    43,    60,
      26,    27,    61,    89,    90,    91,    92,    93,    94,    95,
      96,   118,    29,    30,   119,    36,    37,    38,    39,    44,
      45,    46,    47,    51,    52,   153,   154,   155,   156,    42,
      62,    48,    71,    72,    73,    74,    75,    97,    98,   103,
     104,   105,   106,   107,   108,   109,   110,   113,   120,   111,
     121,   112,   131,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
     141,   142,   143,   144,   158,   145,   146,   147,   148,   149,
     150,   151,   152,   157,   159,   160,   161,    41
};

static const yytype_int8 yycheck[] =
{
      11,     0,    20,    20,     3,    23,    23,     6,     7,     8,
       9,    10,    20,    21,    13,    30,    31,    32,    33,    22,
      19,    20,    21,    22,    43,    20,    25,    26,    23,    21,
       3,    23,    43,     6,     7,     8,     9,    10,    20,    20,
      13,    23,    23,    21,    19,    23,    19,    20,    21,    22,
       4,     5,    25,    26,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    15,    28,    20,
      21,    19,    20,    21,    16,    23,    43,    19,    19,    21,
      20,    21,    24,    35,    36,    37,    38,    39,    40,    41,
      42,    20,    20,    21,    23,    20,    21,    20,    21,    35,
      36,    35,    36,    20,    21,    20,    21,    20,    21,    14,
      14,    27,    23,    12,    12,    17,    11,    17,    11,     7,
       7,     7,     7,     7,     7,     7,     7,    21,    20,    43,
      20,    43,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    -1,
      21,    21,    21,    21,    21,    21,    21,    20,    20,    -1,
      21,    21,    21,    21,    12,    22,    22,    22,    22,    22,
      22,    22,    22,    18,    12,    18,    12,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    13,    19,    20,
      21,    22,    25,    26,    46,    47,    48,    49,    50,     4,
       5,    20,    21,    22,    20,    21,    20,    21,    19,    20,
      21,    11,    43,    43,    43,    28,    20,    21,    20,    21,
       0,    47,    14,    19,    35,    36,    35,    36,    27,    20,
      23,    20,    21,    15,    19,    20,    21,    23,    16,    19,
      21,    24,    14,    20,    23,    20,    23,    21,    23,    21,
      23,    23,    12,    12,    17,    11,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    35,
      36,    37,    38,    39,    40,    41,    42,    17,    11,    30,
      31,    32,    33,     7,     7,     7,     7,     7,     7,     7,
       7,    43,    43,    21,    20,    23,    20,    23,    20,    23,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    21,    21,    21,    21,    21,    21,    21,    21,    20,
      20,    21,    21,    21,    21,    22,    22,    22,    22,    22,
      22,    22,    22,    20,    21,    20,    21,    18,    12,    12,
      18,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     2,     2,     1,     2,
       2,     2,     2,     4,     3,     2,     1,     2,     2,     2,
       2,     2,     2,     3,     6,     6,     3,     6,     6,     3,
       3,     6,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     3,     6,     6,
       3,     6,     6,     3,     3,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     6,     6,     6,
       6,     6,     6,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
  case 6:
#line 58 "inter.y"
    {
        fprintf(mips, "j %s\n", (yyvsp[0].idName));
    }
#line 1396 "inter.tab.c"
    break;

  case 7:
#line 62 "inter.y"
    {
        fprintf(mips, "%s:\n", (yyvsp[-1].idName));
    }
#line 1404 "inter.tab.c"
    break;

  case 9:
#line 67 "inter.y"
    {
        // The initial frame of the caller function remains intact, grows downwards for each param
        paramOffset += INTSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", INTSIZE); // addu $sp, $sp, -INTSIZE
        fprintf(mips, "sw $t%c, 0($sp)\n", (yyvsp[0].idName)[1]);     // sw $t0, 0($sp)
    }
#line 1415 "inter.tab.c"
    break;

  case 10:
#line 74 "inter.y"
    {
        paramOffset += FLOATSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", FLOATSIZE);    // addu $sp, $sp, -INTSIZE
        fprintf(mips, "mfc1 $s0, $f%s\n", (yyvsp[0].idName)+1);             // store a float reg into int reg s0
        fprintf(mips, "sw $s0, 0($sp)\n");                 // sw $t0, 0($sp)
    }
#line 1426 "inter.tab.c"
    break;

  case 11:
#line 81 "inter.y"
    {
        returnVal = string((yyvsp[0].idName));
    }
#line 1434 "inter.tab.c"
    break;

  case 12:
#line 85 "inter.y"
    {
        returnVal = string((yyvsp[0].idName));
    }
#line 1442 "inter.tab.c"
    break;

  case 13:
#line 89 "inter.y"
    {
        int frameSize = getFunctionOffset(functionList, activeFunc); 
        saveRegisters(frameSize+paramOffset);       // Save all temp registers
        fprintf(mips, "jal %s\n", (yyvsp[-2].idName));                     // jal calling
        retrieveRegisters(frameSize+paramOffset);   // retrieve all registers
        if(returnVal==""){

        } else if(returnVal[0] == 'F'){
            fprintf(mips, "move $s0, $v0\n");   // move result to refparam
            fprintf(mips, "mtc1 $s0, $f%s\n", returnVal.c_str()+1);   // move result to refparam
        } else {
            fprintf(mips, "move $t%c, $v0\n", returnVal[1]);   // move result to refparam 
        }
        int funcParamOffset = getParamOffset(functionList, string((yyvsp[-2].idName)));
        fprintf(mips, "add $sp, $sp, %d\n", funcParamOffset);  // collapse space used by parameters
        paramOffset-=funcParamOffset;
        returnVal = "";
    }
#line 1465 "inter.tab.c"
    break;

  case 14:
#line 108 "inter.y"
    {
        activeFunc = string((yyvsp[0].idName));
        fprintf(mips, "%s:\n", (yyvsp[0].idName));
        // Push return address and frame pointer to top of frame
        int frameSize = getFunctionOffset(functionList, activeFunc);
        fprintf(mips, "subu $sp, $sp, %d\n", frameSize);
        fprintf(mips, "sw $ra, %d($sp)\n", frameSize-INTSIZE);
        fprintf(mips, "sw $fp, %d($sp)\n", frameSize-2*INTSIZE);
        fprintf(mips, "move $fp, $sp\n");
    }
#line 1480 "inter.tab.c"
    break;

  case 15:
#line 119 "inter.y"
    {
        int frameSize = getFunctionOffset(functionList, activeFunc);
        fprintf(mips, "end_%s:\n", activeFunc.c_str());
        fprintf(mips, "move $sp, $fp\n");                          // move    $sp,$fp
        fprintf(mips, "lw $ra, %d($sp)\n", frameSize-INTSIZE);     // lw      $31,52($sp)
        fprintf(mips, "lw $fp, %d($sp)\n", frameSize-2*INTSIZE);   // lw      $fp,48($sp)
        fprintf(mips, "addu $sp, $sp, %d\n", frameSize);           // addiu   $sp,$sp,56
        fprintf(mips, "j $ra\n");                                  // j       $31
        //nop
    }
#line 1495 "inter.tab.c"
    break;

  case 16:
#line 130 "inter.y"
    {
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
#line 1503 "inter.tab.c"
    break;

  case 17:
#line 134 "inter.y"
    {
        fprintf(mips, "move $v0, $t%c\n", (yyvsp[0].idName)[1]);
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
#line 1512 "inter.tab.c"
    break;

  case 18:
#line 139 "inter.y"
    {
        fprintf(mips, "mfc1 $s0, $f%s\n", (yyvsp[0].idName)+1);
        fprintf(mips, "move $v0, $s0\n");
        fprintf(mips, "j end_%s\n", activeFunc.c_str());
    }
#line 1522 "inter.tab.c"
    break;

  case 19:
#line 145 "inter.y"
    {
        fprintf(mips, "move $a0, $t%s\n", (yyvsp[0].idName)+1);
        fprintf(mips, "li $v0 1\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");//         li $v0, 4 # system call code for printing string = 4
        fprintf(mips, "la $a0, endline\n");// la $a0, out_string # load address of string to be printed into $a0
        fprintf(mips, "syscall\n");// syscall
    }
#line 1535 "inter.tab.c"
    break;

  case 20:
#line 154 "inter.y"
    {
        fprintf(mips, "mov.s $f12, $f%s\n", (yyvsp[0].idName)+1);
        fprintf(mips, "li $v0 2\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");//         li $v0, 4 # system call code for printing string = 4
        fprintf(mips, "la $a0, endline\n");// la $a0, out_string # load address of string to be printed into $a0
        fprintf(mips, "syscall\n");// syscall
    }
#line 1548 "inter.tab.c"
    break;

  case 21:
#line 163 "inter.y"
    {
        fprintf(mips, "li $v0 5\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "move $t%s, $v0\n", (yyvsp[0].idName)+1);
    }
#line 1558 "inter.tab.c"
    break;

  case 22:
#line 169 "inter.y"
    {
        fprintf(mips, "li $v0 6\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "mov.s $f%s, $f0\n", (yyvsp[0].idName)+1);
    }
#line 1568 "inter.tab.c"
    break;

  case 23:
#line 178 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-2].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "sw $t%c, %d($sp)\n", (yyvsp[0].idName)[1], offset);
        } else {
            fprintf(mips, "sw $t%s, %s\n", (yyvsp[0].idName)+1, (yyvsp[-2].idName)); 
        }
    }
#line 1581 "inter.tab.c"
    break;

  case 24:
#line 187 "inter.y"
    {
        // useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-5].idName)), 0, isGlobal)+paramOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", (yyvsp[-3].idName)[1], offset);
    }
#line 1591 "inter.tab.c"
    break;

  case 25:
#line 193 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-5].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-3].idName)+1, (yyvsp[-3].idName)+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", (yyvsp[-3].idName)+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", (yyvsp[0].idName)+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-3].idName)+1, (yyvsp[-3].idName)+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", (yyvsp[-5].idName));
            fprintf(mips,"addu $s0, $s1, $t%s\n", (yyvsp[-3].idName)+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", (yyvsp[0].idName)+1);
        }
    }
#line 1611 "inter.tab.c"
    break;

  case 26:
#line 209 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[0].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "lw $t%c, %d($sp)\n", (yyvsp[-2].idName)[1], offset);
        } else {
            fprintf(mips, "lw $t%c, %s\n", (yyvsp[-2].idName)[1], (yyvsp[0].idName));
        }
    }
#line 1624 "inter.tab.c"
    break;

  case 27:
#line 218 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-3].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-1].idName)+1, (yyvsp[-1].idName)+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", (yyvsp[-1].idName)+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", (yyvsp[-5].idName)+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-1].idName)+1, (yyvsp[-1].idName)+1, INTSIZE);
            fprintf(mips,"la $s0, %s\n", (yyvsp[-3].idName));
            fprintf(mips,"addu $s0, $s0, $t%s\n", (yyvsp[-3].idName)+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", (yyvsp[-5].idName)+1);
        }
    }
#line 1644 "inter.tab.c"
    break;

  case 28:
#line 234 "inter.y"
    {
        //useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-3].idName)), 0, isGlobal)+paramOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", (yyvsp[-5].idName)[1], offset);
    }
#line 1654 "inter.tab.c"
    break;

  case 29:
#line 240 "inter.y"
    {
        fprintf(mips, "li $t%c, %s\n", (yyvsp[-2].idName)[1], (yyvsp[0].idName));
    }
#line 1662 "inter.tab.c"
    break;

  case 30:
#line 244 "inter.y"
    {
        fprintf(mips, "move $t%c, $t%c\n", (yyvsp[-2].idName)[1], (yyvsp[0].idName)[3]);
    }
#line 1670 "inter.tab.c"
    break;

  case 31:
#line 248 "inter.y"
    {
        fprintf(mips, "cvt.w.s $f%s, $f%s\n", (yyvsp[-1].idName)+1, (yyvsp[-1].idName)+1);
        fprintf(mips, "mfc1 $t%c, $f%s\n", (yyvsp[-5].idName)[1], (yyvsp[-1].idName)+1);
    }
#line 1679 "inter.tab.c"
    break;

  case 32:
#line 253 "inter.y"
    {
        fprintf(mips, "addu $t%c, $t%c, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName));
    }
#line 1687 "inter.tab.c"
    break;

  case 33:
#line 257 "inter.y"
    {
        fprintf(mips, "subu $t%c, $t%c, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName));
    }
#line 1695 "inter.tab.c"
    break;

  case 34:
#line 261 "inter.y"
    {
        fprintf(mips, "add $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1703 "inter.tab.c"
    break;

  case 35:
#line 265 "inter.y"
    {
        fprintf(mips, "sub $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1711 "inter.tab.c"
    break;

  case 36:
#line 269 "inter.y"
    {
        fprintf(mips, "mul $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1719 "inter.tab.c"
    break;

  case 37:
#line 273 "inter.y"
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
        fprintf(mips, "mflo $t%c\n", (yyvsp[-4].idName)[1]);
    }
#line 1728 "inter.tab.c"
    break;

  case 38:
#line 278 "inter.y"
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
        fprintf(mips, "mfhi $t%c\n", (yyvsp[-4].idName)[1]);
    }
#line 1737 "inter.tab.c"
    break;

  case 39:
#line 283 "inter.y"
    {
        fprintf(mips, "seq $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1745 "inter.tab.c"
    break;

  case 40:
#line 287 "inter.y"
    {
        fprintf(mips, "sne $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1753 "inter.tab.c"
    break;

  case 41:
#line 291 "inter.y"
    {
        // hack, will not arise when short-circuit is done
        fprintf(mips, "sne $t%c, $t%c, 0\n", (yyvsp[-2].idName)[1], (yyvsp[-2].idName)[1]);
        fprintf(mips, "sne $t%c, $t%c, 0\n", (yyvsp[0].idName)[1], (yyvsp[0].idName)[1]);
        fprintf(mips, "and $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1764 "inter.tab.c"
    break;

  case 42:
#line 298 "inter.y"
    {
        fprintf(mips, "or $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1772 "inter.tab.c"
    break;

  case 43:
#line 302 "inter.y"
    {
        fprintf(mips, "slt $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1780 "inter.tab.c"
    break;

  case 44:
#line 306 "inter.y"
    {
        fprintf(mips, "sgt $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1788 "inter.tab.c"
    break;

  case 45:
#line 310 "inter.y"
    {
        fprintf(mips, "sle $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1796 "inter.tab.c"
    break;

  case 46:
#line 314 "inter.y"
    {
        fprintf(mips, "sge $t%c, $t%c, $t%c\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName)[1]);
    }
#line 1804 "inter.tab.c"
    break;

  case 47:
#line 320 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-2].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "s.s $f%s, %d($sp)\n", (yyvsp[0].idName)+1, offset);
        } else {
            fprintf(mips, "s.s $f%s, %s\n", (yyvsp[0].idName)+1, (yyvsp[-2].idName));
        }
    }
#line 1817 "inter.tab.c"
    break;

  case 48:
#line 329 "inter.y"
    {
        //useless
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-5].idName)), 0, isGlobal)+paramOffset;
        fprintf(mips, "s.s $f%s, %d($sp)\n", (yyvsp[-3].idName)+1, offset);
    }
#line 1827 "inter.tab.c"
    break;

  case 49:
#line 335 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-5].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-3].idName)+1, (yyvsp[-3].idName)+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", (yyvsp[-3].idName)+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", (yyvsp[0].idName)+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-3].idName)+1, (yyvsp[-3].idName)+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", (yyvsp[-5].idName));
            fprintf(mips,"addu $s0, $s1, $t%s\n", (yyvsp[-3].idName)+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", (yyvsp[0].idName)+1);
        }
    }
#line 1847 "inter.tab.c"
    break;

  case 50:
#line 351 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[0].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "l.s $f%s, %d($sp)\n", (yyvsp[-2].idName)+1, offset);
        } else {
            fprintf(mips, "l.s $f%s, %s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName));
        }
    }
#line 1860 "inter.tab.c"
    break;

  case 51:
#line 360 "inter.y"
    {
        int offset = getOffset(functionList, globalVariables, activeFunc, string((yyvsp[-3].idName)), 0, isGlobal)+paramOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-1].idName)+1, (yyvsp[-1].idName)+1, INTSIZE);
            fprintf(mips, "subu $s0, $sp, $t%s\n", (yyvsp[-1].idName)+1);
            fprintf(mips, "l.s $f%s, %d($s0)\n", (yyvsp[-5].idName)+1, offset);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", (yyvsp[-1].idName)+1, (yyvsp[-1].idName)+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", (yyvsp[-3].idName));
            fprintf(mips,"addu $s0, $s1, $t%s\n", (yyvsp[-1].idName)+1);
            fprintf(mips,"l.s $f%s, 0($s0)\n", (yyvsp[-5].idName)+1);
        }
    }
#line 1878 "inter.tab.c"
    break;

  case 52:
#line 374 "inter.y"
    {
        // convert from integer to float
        fprintf(mips, "mtc1 $t%c, $f%s\n", (yyvsp[-1].idName)[1], (yyvsp[-5].idName)+1);
        fprintf(mips, "cvt.s.w $f%s, $f%s\n", (yyvsp[-5].idName)+1, (yyvsp[-5].idName)+1);
    }
#line 1888 "inter.tab.c"
    break;

  case 53:
#line 380 "inter.y"
    {
        fprintf(mips, "li.s $f%s, %s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName));
    }
#line 1896 "inter.tab.c"
    break;

  case 54:
#line 384 "inter.y"
    {
        fprintf(mips, "mov.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
    }
#line 1904 "inter.tab.c"
    break;

  case 55:
#line 388 "inter.y"
    {
        fprintf(mips, "add.s $f%s, $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
    }
#line 1912 "inter.tab.c"
    break;

  case 56:
#line 392 "inter.y"
    {
        fprintf(mips, "sub.s $f%s, $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
    }
#line 1920 "inter.tab.c"
    break;

  case 57:
#line 396 "inter.y"
    {
        fprintf(mips, "mul.s $f%s, $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
    }
#line 1928 "inter.tab.c"
    break;

  case 58:
#line 400 "inter.y"
    {
        fprintf(mips, "div.s $f%s, $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
    }
#line 1936 "inter.tab.c"
    break;

  case 59:
#line 404 "inter.y"
    {
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 1949 "inter.tab.c"
    break;

  case 60:
#line 413 "inter.y"
    {
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 1962 "inter.tab.c"
    break;

  case 61:
#line 422 "inter.y"
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[-2].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 1978 "inter.tab.c"
    break;

  case 62:
#line 434 "inter.y"
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[-2].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 1994 "inter.tab.c"
    break;

  case 63:
#line 446 "inter.y"
    {
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 2007 "inter.tab.c"
    break;

  case 64:
#line 455 "inter.y"
    {
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 2020 "inter.tab.c"
    break;

  case 65:
#line 464 "inter.y"
    {
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 2033 "inter.tab.c"
    break;

  case 66:
#line 473 "inter.y"
    {
        fprintf(mips, "li $t%c, 1\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", (yyvsp[-2].idName)+1, (yyvsp[0].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $t%c, 0\n", (yyvsp[-4].idName)[1]);
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        floatLabel++;
    }
#line 2046 "inter.tab.c"
    break;

  case 67:
#line 484 "inter.y"
    {
        fprintf(mips, "beq $t%c, $t%c, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName));
    }
#line 2054 "inter.tab.c"
    break;

  case 68:
#line 488 "inter.y"
    {
        fprintf(mips, "bne $t%c, $t%c, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName)[1], (yyvsp[0].idName));
    }
#line 2062 "inter.tab.c"
    break;

  case 69:
#line 492 "inter.y"
    {
        fprintf(mips, "beq $t%c, %s, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName), (yyvsp[0].idName));
    }
#line 2070 "inter.tab.c"
    break;

  case 70:
#line 496 "inter.y"
    {
        fprintf(mips, "bne $t%c, %s, %s\n", (yyvsp[-4].idName)[1], (yyvsp[-2].idName), (yyvsp[0].idName));
    }
#line 2078 "inter.tab.c"
    break;

  case 71:
#line 500 "inter.y"
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1);
        fprintf(mips, "bc1t FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", (yyvsp[0].idName));
        floatLabel++;
    }
#line 2092 "inter.tab.c"
    break;

  case 72:
#line 510 "inter.y"
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", (yyvsp[-4].idName)+1, (yyvsp[-2].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", (yyvsp[0].idName));
        floatLabel++;
    }
#line 2106 "inter.tab.c"
    break;

  case 73:
#line 520 "inter.y"
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[-4].idName)+1);
        fprintf(mips, "bc1t FLOAT%d\n", floatLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", (yyvsp[0].idName));
        floatLabel++;
    }
#line 2122 "inter.tab.c"
    break;

  case 74:
#line 532 "inter.y"
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", (yyvsp[-4].idName)+1);
        fprintf(mips, "bc1f FLOAT%d\n", floatLabel); // goto label float when equal to 0
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", floatLabel);
        fprintf(mips, "beq $s0, 1, %s\n", (yyvsp[0].idName));
        floatLabel++;
    }
#line 2138 "inter.tab.c"
    break;


#line 2142 "inter.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 545 "inter.y"


void saveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "sw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "s.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void retrieveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "lw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "l.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void yyerror(char *s)
{      
    printf("\nSyntax error %s at line %d\n", s, yylineno);
    // cout << BOLD(FRED("Error : ")) << FYEL("Syntax error " + string(s) + "in intermediate code at line " + to_string(yylineno)) << endl;
    fflush(stdout);
}

int main(int argc, char **argv)
{
    readSymbolTable(functionList, globalVariables);
    returnVal = ""; 
    isGlobal = false;
    mips = fopen("mips.s", "w");
    fflush(mips);
    fprintf(mips,".data\n");
    for(auto it : globalVariables){
        fprintf(mips, "%s: .space %d\n", it.name.c_str(), 4*(it.varOffset));
    }
    fprintf(mips,"endline: .asciiz \"\\n\"\n");
    fprintf(mips,".text\n");
    paramOffset = 0;
    floatLabel = 0;
    yyparse();
    fflush(mips);
    fclose(mips);
}

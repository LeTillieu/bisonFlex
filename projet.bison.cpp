/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "projet.bison" /* yacc.c:339  */

  #include <iostream>
  #include <map>
  #include <string>
  #include <vector>  
  #include <algorithm>
  #include"matplotlibcpp.h"
  using namespace std;
  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  map<string, double> variables;
  map<string, vector<double>> functions;      //ic of start and end of each func
  map<string, vector<string>> funcParameters; //name of parameters of each func
  map<string, vector<string>> funcReturn; //name of return of each func
  vector<map<string, double>> varFunc; //variables to reset after function
  map<int, pair<double, double>> forLoop;
  vector<double> funcPlotX;
  vector<double> funcPlotY;
  double minX, maxX, step;
  string plotVarName;
  vector<int> toGoAfterFunc;
  vector<pair<int,string>> instructions;
  int ic = 0;   // compteur instruction 

  void ins(int c, string d) { instructions.push_back(make_pair(c, d)); ic++;};
  bool is_number(const std::string& s)
  {
      std::string::const_iterator it = s.begin();
      while (it != s.end() && (std::isdigit(*it) || *it == '.'|| *it == ',') ) ++it;
      return !s.empty() && it == s.end();
  }

  // structure pour stocker les adresses pour les sauts condistionnels et autres...
  typedef struct adr {
    int ic_goto; 
    int ic_false;
    int lastVarId;
  } t_adresse; 


#line 109 "projet.bison.cpp" /* yacc.c:339  */

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
   by #include "projet.bison.hpp".  */
#ifndef YY_YY_PROJET_BISON_HPP_INCLUDED
# define YY_YY_PROJET_BISON_HPP_INCLUDED
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
    NUMBER = 258,
    IDENTIFIER = 259,
    GET = 260,
    GETFUNC = 261,
    SI = 262,
    ALORS = 263,
    SINON = 264,
    FINSI = 265,
    REPEAT = 266,
    JMP = 267,
    JNZ = 268,
    JNZINV = 269,
    OUT = 270,
    SUP = 271,
    INF = 272,
    EQUAL = 273,
    DIFF = 274,
    SUPEQ = 275,
    INFEQ = 276,
    FUNC = 277,
    PARAM = 278,
    ADDPARAM = 279,
    ADDRET = 280,
    EXECFUNC = 281,
    FUNCNAME = 282,
    RESETFUNC = 283,
    FOR = 284,
    GETMAXFOR = 285,
    DEFFUNC = 286,
    FUNCEXP = 287,
    PLOT = 288,
    PRINT = 289,
    LIM = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "projet.bison" /* yacc.c:355  */

  double valeur;
  char nom[50];
  t_adresse adresse;

#line 191 "projet.bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "projet.bison.cpp" /* yacc.c:358  */

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
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    39,    37,    49,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      48,    46,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    44,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    92,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    96,   105,   106,   107,   108,   105,   111,
     112,   113,   114,   111,   116,   117,   118,   116,   121,   122,
     123,   124,   123,   126,   127,   127,   129,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   142,   143,   144,   145,
     146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENTIFIER", "GET", "GETFUNC",
  "SI", "ALORS", "SINON", "FINSI", "REPEAT", "JMP", "JNZ", "JNZINV", "OUT",
  "SUP", "INF", "EQUAL", "DIFF", "SUPEQ", "INFEQ", "'{'", "FUNC", "PARAM",
  "ADDPARAM", "ADDRET", "EXECFUNC", "FUNCNAME", "RESETFUNC", "FOR",
  "GETMAXFOR", "DEFFUNC", "FUNCEXP", "PLOT", "PRINT", "LIM", "'+'", "'-'",
  "'*'", "'/'", "'\\n'", "'('", "')'", "'}'", "':'", "'='", "'>'", "'<'",
  "','", "$accept", "bloc", "instruction", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "condition", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   123,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,    43,    45,    42,
      47,    10,    40,    41,   125,    58,    61,    62,    60,    44
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,   105,   -37,   -14,   -37,   -37,   -37,    -1,   -36,   -37,
      14,    14,   -32,   -37,    14,   -29,   -27,   -37,    -5,    16,
     -20,   -37,   -37,    14,   131,     4,   -37,   131,    14,    14,
      84,   -22,    -7,    14,    -4,    14,    14,    14,    14,    14,
       4,    -3,   111,    11,    13,    31,    14,    43,   -37,   -28,
     -28,    15,    15,   131,    21,   -37,    14,    14,    14,    14,
      14,    14,   -37,   -37,    40,   107,   -37,   -37,    41,   131,
     131,   131,   131,   131,   131,    50,    62,   -37,    14,   -37,
     -37,   -37,   -37,   124,   -37,   -37,    33,    67,   -37,    84,
      84,    14,    32,    55,    35,    52,    44,   -37,   -37,   -37,
     -37,   -37,   -37,    75,    84,   -37,    54,    72,   -37,   -37,
     -37,    84,    56,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    28,     1,     0,     5,    14,    19,     0,     0,    34,
       0,     0,     0,    33,     0,     0,     0,     3,     0,     0,
       0,    49,    50,     0,     4,     0,     2,    29,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    43,
      44,    45,    46,    47,     0,     6,     0,     0,     0,     0,
       0,     0,    15,    21,     0,     0,    35,    36,     0,    39,
      40,    41,    42,    37,    38,     0,     0,    30,     0,     7,
      16,    22,     3,     0,     3,     3,     0,    28,    24,     8,
      17,     0,     0,     0,     0,     0,     0,    32,    25,     9,
      18,    23,     3,     0,    26,    10,     0,     0,    27,    11,
       3,    12,     0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -17,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -25,    -9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    15,    68,    84,    94,   103,   107,   110,
     112,    16,    75,    85,    95,    17,    44,    76,    86,    93,
     102,   106,    82,    92,    20,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    24,    25,    18,    43,    27,    19,    21,    22,    26,
      13,    37,    38,    28,    34,    29,    40,    21,    22,    31,
      32,    39,    33,    45,    47,    67,    49,    50,    51,    52,
      53,    54,    14,    35,    36,    37,    38,    65,    46,    48,
      55,    35,    36,    37,    38,    39,    23,    69,    70,    71,
      72,    73,    74,    39,    62,    64,    23,    63,    35,    36,
      37,    38,    77,    79,    39,    87,    96,    89,    90,    83,
      39,     3,    80,    81,     4,    91,    97,    98,     5,    99,
      35,    36,    37,    38,   105,   104,    66,   101,     3,     6,
       7,     4,    39,   111,   109,     5,   100,     8,   108,     0,
     113,     9,    10,    11,     0,     2,     6,     7,     0,     3,
       0,   -31,     4,     0,     8,     0,     5,     0,     9,    10,
      11,     0,     0,     0,     0,   -28,     0,     6,     7,    56,
      57,    58,    59,     0,     0,     8,     0,     0,     0,     9,
      10,    11,     0,     0,    35,    36,    37,    38,    35,    36,
      37,    38,    78,     0,     0,     0,    39,     0,    60,    61,
      39,    35,    36,    37,    38,     0,     0,    88,    35,    36,
      37,    38,     0,    39,     0,     0,     0,     0,     0,     0,
      39
};

static const yytype_int8 yycheck[] =
{
      17,    10,    11,     4,    29,    14,    42,     3,     4,    41,
      24,    39,    40,    42,    23,    42,    25,     3,     4,    24,
       4,    49,    42,    45,    33,     4,    35,    36,    37,    38,
      39,    40,    46,    37,    38,    39,    40,    46,    45,    43,
      43,    37,    38,    39,    40,    49,    42,    56,    57,    58,
      59,    60,    61,    49,    43,    24,    42,    44,    37,    38,
      39,    40,    22,    22,    49,    82,    91,    84,    85,    78,
      49,     4,    22,    11,     7,    42,    44,    22,    11,    44,
      37,    38,    39,    40,     9,   102,    43,    43,     4,    22,
      23,     7,    49,   110,    22,    11,    44,    30,    44,    -1,
      44,    34,    35,    36,    -1,     0,    22,    23,    -1,     4,
      -1,    44,     7,    -1,    30,    -1,    11,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    22,    23,    18,
      19,    20,    21,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    37,    38,    39,    40,    37,    38,
      39,    40,    45,    -1,    -1,    -1,    49,    -1,    47,    48,
      49,    37,    38,    39,    40,    -1,    -1,    43,    37,    38,
      39,    40,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     4,     7,    11,    22,    23,    30,    34,
      35,    36,    52,    24,    46,    53,    61,    65,     4,    42,
      74,     3,     4,    42,    76,    76,    41,    76,    42,    42,
      51,    24,     4,    42,    76,    37,    38,    39,    40,    49,
      76,    75,    76,    75,    66,    45,    45,    76,    43,    76,
      76,    76,    76,    76,    76,    43,    18,    19,    20,    21,
      47,    48,    43,    44,    24,    76,    43,     4,    54,    76,
      76,    76,    76,    76,    76,    62,    67,    22,    45,    22,
      22,    11,    72,    76,    55,    63,    68,    51,    43,    51,
      51,    42,    73,    69,    56,    64,    75,    44,    22,    44,
      44,    43,    70,    57,    51,     9,    71,    58,    44,    22,
      59,    51,    60,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    52,    61,    62,    63,    64,    52,    65,
      66,    67,    68,    52,    69,    70,    71,    52,    52,    52,
      72,    73,    52,    52,    74,    52,    52,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    11,     0,     0,     0,    14,     0,     3,
       0,     0,    10,     2,     0,     5,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1
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
        case 4:
#line 95 "projet.bison" /* yacc.c:1646  */
    {ins(OUT, "");}
#line 1377 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "projet.bison" /* yacc.c:1646  */
    {}
#line 1383 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[-4].adresse).ic_false = ic; ins(JNZ, "0"); }
#line 1389 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "projet.bison" /* yacc.c:1646  */
    {}
#line 1395 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "projet.bison" /* yacc.c:1646  */
    {}
#line 1401 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "projet.bison" /* yacc.c:1646  */
    {}
#line 1407 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[-12].adresse).ic_goto = ic; ins(JMP, "0");instructions[(yyvsp[-12].adresse).ic_false].second = to_string(ic);}
#line 1413 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "projet.bison" /* yacc.c:1646  */
    {}
#line 1419 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "projet.bison" /* yacc.c:1646  */
    {}
#line 1425 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "projet.bison" /* yacc.c:1646  */
    {instructions[(yyvsp[-18].adresse).ic_goto].second = to_string(ic);}
#line 1431 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[0].adresse).ic_goto = ic;}
#line 1437 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[-4].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1443 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 107 "projet.bison" /* yacc.c:1646  */
    {}
#line 1449 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 108 "projet.bison" /* yacc.c:1646  */
    {}
#line 1455 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 109 "projet.bison" /* yacc.c:1646  */
    {instructions[(yyvsp[-10].adresse).ic_false].second = to_string(ic+1); ins(JMP, to_string((yyvsp[-10].adresse).ic_goto));}
#line 1461 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[0].adresse).ic_goto = ic;}
#line 1467 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "projet.bison" /* yacc.c:1646  */
    {}
#line 1473 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "projet.bison" /* yacc.c:1646  */
    {}
#line 1479 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "projet.bison" /* yacc.c:1646  */
    {}
#line 1485 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 115 "projet.bison" /* yacc.c:1646  */
    {ins(JNZINV,to_string((yyvsp[-10].adresse).ic_goto));}
#line 1491 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 116 "projet.bison" /* yacc.c:1646  */
    {(yyvsp[-7].adresse).ic_goto = ic; ins(FOR, (yyvsp[-5].nom)); ins(GET, (yyvsp[-5].nom)); ins(GETMAXFOR, to_string((yyvsp[-7].adresse).ic_goto)); ins(INF, "0"); (yyvsp[-7].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1497 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 117 "projet.bison" /* yacc.c:1646  */
    {}
#line 1503 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "projet.bison" /* yacc.c:1646  */
    {}
#line 1509 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 119 "projet.bison" /* yacc.c:1646  */
    {ins(GET, (yyvsp[-11].nom)); ins(NUMBER, "1"); ins('+', "0"); ins(IDENTIFIER, (yyvsp[-11].nom)); ins(JMP, to_string((yyvsp[-13].adresse).ic_goto+1)); instructions[(yyvsp[-13].adresse).ic_false].second = to_string(ic);ins(GET, (yyvsp[-11].nom)); ins(NUMBER, "1"); ins('-', "0"); ins(IDENTIFIER, (yyvsp[-11].nom));}
#line 1515 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 122 "projet.bison" /* yacc.c:1646  */
    {ins(IDENTIFIER, (yyvsp[-2].nom));}
#line 1521 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 123 "projet.bison" /* yacc.c:1646  */
    {ins(FUNCNAME, (yyvsp[-4].nom)); ins(ADDPARAM, (yyvsp[-1].nom)); ins(FUNCNAME, (yyvsp[-4].nom)); ins(ADDRET, (yyvsp[-3].nom)); (yyvsp[-5].adresse).ic_goto = ic; ins(JMP, "0"); functions[(yyvsp[-4].nom)] = vector<double>(2,0); functions[(yyvsp[-4].nom)][0] = ic;}
#line 1527 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 124 "projet.bison" /* yacc.c:1646  */
    {}
#line 1533 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 125 "projet.bison" /* yacc.c:1646  */
    {ins(FUNCNAME, (yyvsp[-8].nom));ins(RESETFUNC, "0");functions[(yyvsp[-8].nom)][1] = ic; ins(JMP, "0");instructions[(yyvsp[-9].adresse).ic_goto].second = to_string(ic);}
#line 1539 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 126 "projet.bison" /* yacc.c:1646  */
    {ins(FUNCNAME, (yyvsp[-1].nom));ins(EXECFUNC, (yyvsp[0].nom));}
#line 1545 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "projet.bison" /* yacc.c:1646  */
    {ins(NUMBER, to_string(maxX)); ins(GET, plotVarName); ins(INF, "0"); (yyvsp[0].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1551 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "projet.bison" /* yacc.c:1646  */
    {}
#line 1557 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 129 "projet.bison" /* yacc.c:1646  */
    {ins(FUNCNAME, (yyvsp[0].nom));ins(LIM, "0");}
#line 1563 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 132 "projet.bison" /* yacc.c:1646  */
    {ins(SUP, "0");}
#line 1569 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 133 "projet.bison" /* yacc.c:1646  */
    {ins(INF, "0");}
#line 1575 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 134 "projet.bison" /* yacc.c:1646  */
    {ins(EQUAL, "0");}
#line 1581 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 135 "projet.bison" /* yacc.c:1646  */
    {ins(DIFF, "0");}
#line 1587 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 136 "projet.bison" /* yacc.c:1646  */
    {ins(SUPEQ, "0");}
#line 1593 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 137 "projet.bison" /* yacc.c:1646  */
    {ins(INFEQ, "0");}
#line 1599 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "projet.bison" /* yacc.c:1646  */
    { ins('+', "0");}
#line 1605 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 140 "projet.bison" /* yacc.c:1646  */
    { ins('-', "0");}
#line 1611 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 141 "projet.bison" /* yacc.c:1646  */
    { ins('*', "0");}
#line 1617 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 142 "projet.bison" /* yacc.c:1646  */
    { ins('/', "0");}
#line 1623 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 143 "projet.bison" /* yacc.c:1646  */
    { }
#line 1629 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 144 "projet.bison" /* yacc.c:1646  */
    { }
#line 1635 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 145 "projet.bison" /* yacc.c:1646  */
    { ins(NUMBER, to_string((yyvsp[0].valeur)));}
#line 1641 "projet.bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 146 "projet.bison" /* yacc.c:1646  */
    {ins(GET, (yyvsp[0].nom));}
#line 1647 "projet.bison.cpp" /* yacc.c:1646  */
    break;


#line 1651 "projet.bison.cpp" /* yacc.c:1646  */
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
#line 148 "projet.bison" /* yacc.c:1906  */


// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
  switch (instruction){
  case '-'     : return "-";
  case '+'     : return "+";
  case '/'     : return "/";
  case '*'     : return "*";
  case NUMBER  : return "NUM";
  case OUT     : return "OUT";
  case JNZ     : return "JNZ";   // Jump if not zero
  case JNZINV     : return "JNZINV";   // Jump if zero

  case JMP     : return "JMP";   // Unconditional Jump
  case IDENTIFIER  : return "VAR";
  case SUP :     return "SUP";
  case INF :     return "INF";
  case SUPEQ :     return "SUPEQ";
  case INFEQ :     return "INFEQ";
  case EQUAL :     return "EQUAL";
  case DIFF :     return "DIFF";
  case FUNC :    return "FUNC";
  case GET:     return "GET";

  case PARAM:   return "PARAM";
  case GETFUNC:  return "GETFUNC";
  case ADDPARAM:   return "ADDPARAM";
  case ADDRET:   return "ADDRET";
  case FUNCNAME:  return "FUNCNAME";
  case RESETFUNC: return "RESETFUNC";
  case EXECFUNC : return  "EXECFUNC";
  case FOR:       return  "FOR";
  case LIM:        return   "LIM";
  default  : return to_string (instruction);
   }
}

void print_program(){
  cout << "==== CODE GENERE ====" << endl;
  int i = 0;
  for (auto ins : instructions )
    cout << i++ << "\t\t\t" << nom(ins.first) << "\t\t"  << ins.second << endl;
  cout << "=====================" << endl;  
  

}

string depiler(vector<string> &pile) {
  string t = pile[pile.size()-1];
  pile.pop_back();
  return t;
}

double depilerDouble(vector<string> &pile){
  string t = pile[pile.size()-1];
  pile.pop_back();
  return (double)atof(t.c_str());
}

void run_program(){
  vector<string> pile; 
  double x,y;
  string var;
  variables.clear();
  ic = 0;
  cout << "===== EXECUTION =====" << endl;
  while ( ic < instructions.size() ){
    auto ins = instructions[ic];
    switch(ins.first){
      case '+':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y+x));
        ic++;
      }     
      break;
    
      case '*':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y*x));
        ic++;
      }     
      break;

      case '-':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y-x));
        ic++;
      }
      break;


      case '/':{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(y/x));
        ic++;
      }
      break;

      case NUMBER :{
        pile.push_back(ins.second);
        ic++;
      }  
      break;
    
      case JMP :{
        ic = (double)atof(ins.second.c_str());
      }
      break;
    
      case JNZ :{
        x = depilerDouble(pile);
        ic = ( x ? ic+1 : (double)atof(ins.second.c_str()));
      }
      break;

      case JNZINV:{
        x = depilerDouble(pile);
        ic = ( x ? (double)atof(ins.second.c_str()) : ic+1);
      }  
      break;

      case OUT:{
        if(!pile.empty()){
          var = depiler(pile);
          if(is_number(instructions[ic-1].second)){
          cout << "Résultat : " << var << endl;
          }else if(variables.find(instructions[ic-1].second) != variables.end()){
            cout << instructions[ic-1].second << ": " << var << endl;
          }
        }
        ic++;
      }
      break;

      case IDENTIFIER :{
        x = depilerDouble(pile);
        variables[ins.second] = x;
        ic++;
      }      
      break;

      case GET:{
        if(variables.find(ins.second) != variables.end()){
          pile.push_back(to_string(variables[ins.second]));
        }
        ic++;
      }
      break;

      case GETFUNC:
        var = ins.second;
        instructions[functions[var][1]].second = to_string(ic+1);
        ic = functions[var][0];
      break;
      
     case SUP:{
      x = depilerDouble(pile);
      y = depilerDouble(pile);
      if(y>x){
          pile.push_back("1");
      }else{
        pile.push_back("0");
      }
       ic++;
     }  
      break;

      case INF:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        cout << y << " " << x << endl;
        if(y<x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case SUPEQ:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y>=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case INFEQ:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y<=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case EQUAL:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y==x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case DIFF:{
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        if(y!=x){
          pile.push_back("1");
        }else{
          pile.push_back("0");
        }
       ic++;
     }  
      break;

      case FOR:{
        double maxVal = depilerDouble(pile);
        double minVal = depilerDouble(pile);
        pair<double, double> tmp;
        tmp.first = minVal;
        tmp.second = maxVal;
        forLoop[ic] = tmp;
        variables[ins.second] = minVal;
        ic++;
      }
      break;

      case GETMAXFOR: {
        x = forLoop[stoi(ins.second)].second;
        pile.push_back(to_string(x));
        ic++;
      }
      break;


      case RESETFUNC: {
        string funcName = depiler(pile);
        vector<pair<string, double>> returnedVar;
        pair<string, double> tmpPair;
        for(auto c: funcReturn[funcName]){
            tmpPair.first = c;
            tmpPair.second = variables[c];
            returnedVar.push_back(tmpPair);
        }

        variables = varFunc[varFunc.size()-1];
        
        for(auto c: returnedVar){
            variables[c.first] = c.second;
        }
        ic = toGoAfterFunc[toGoAfterFunc.size()-1];
        toGoAfterFunc.pop_back();
      }
      break;

      case FUNCNAME:{
        pile.push_back(ins.second);
        ic++;
      }
      break;

      case ADDPARAM:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;
        int curCommaPos = param.find(",");
        while(curCommaPos != string::npos){
          curParam = param.substr(0,curCommaPos);
          if(!is_number(string(1,curParam.at(0)))){
            funcParameters[funcName].push_back(curParam);
          }
          param = param.substr(curCommaPos+1,param.length());
          curCommaPos = param.find(",");
        }
        if(!is_number(string(1,param.at(0)))){
            funcParameters[funcName].push_back(param);
        }
        ic++;
      }  
      break;
      
      case ADDRET:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;
        int curCommaPos = param.find(",");
        while(curCommaPos != string::npos){
          funcReturn[funcName].push_back(param.substr(0,curCommaPos));
          param = param.substr(curCommaPos+1,param.length());
          curCommaPos = param.find(",");
        }
        funcReturn[funcName].push_back(param);
        ic++;
      }  
      break;

      case EXECFUNC:{
        string funcName = depiler(pile);
        string param = ins.second.substr(1,ins.second.length()-2);
        string curParam;

        int curCommaPos = param.find(",");

        vector<double> parameters;

        while(curCommaPos != string::npos){
          curParam = param.substr(0,curCommaPos);
          if(is_number(curParam)){
            parameters.push_back(atof(curParam.c_str()));
          }else if(variables.find(curParam) != variables.end()){
            parameters.push_back(variables[curParam]);
          }
          param = param.substr(curCommaPos+1, param.length());
          curCommaPos = param.find(",");
        }

        if(is_number(param)){
           parameters.push_back(atof(param.c_str()));
        }else if(variables.find(param) != variables.end()){
            parameters.push_back(variables[param]);
        }
        if(parameters.size() == funcParameters[funcName].size()){
          varFunc.push_back(variables);
          for(int i =0; i < parameters.size(); i++){
            variables[funcParameters[funcName][i]] = parameters[i];
          }
          toGoAfterFunc.push_back(ic+1);
          ic=functions[funcName][0];
        }else{
          ic++;
        }
      }     
      break;

      case FUNCEXP:{
        pile.push_back(ins.second);
        ic++;
      }
      break;

      case LIM:{
        plotVarName = depiler(pile);
        cout << plotVarName << endl;
        step = depilerDouble(pile);
        maxX = depilerDouble(pile);
        minX = depilerDouble(pile);
        variables[plotVarName] = minX;
        ic++;
      }
      break;

      default:{
        cout << "No instruction" << endl;
        ic++;
      }    
    }

    
  }
  cout << "=====================" << endl; 

   auto i = 0;
    cout << "==== VARIABLES ====" << endl;
    for (auto ins : variables )
      cout << i++ << '\t' << ins.first << "\t" << ins.second << endl;
  cout << "=====================" << endl; 

    cout << "==== FONCTION ====" << endl;
    for (auto ins : functions )
      cout << ins.first << '\t' << ins.second[0] << '\t' << ins.second[1]  << endl;
  cout << "=====================" << endl; 
}

int main(int argc, char **argv) {
  
  if ( argc > 1 ){
    yyin = fopen( argv[1], "r" );
  }
  else{
    yyin = stdin;
    cout << stdin << endl;
  }
  yyparse();
  print_program();

  run_program();

}

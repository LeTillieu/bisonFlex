/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

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
  #include <cmath> 
  #include <SFML/OpenGL.hpp>
  #include <SFML/Graphics.hpp>
  using namespace std;
  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }
  sf::RenderWindow window(sf::VideoMode(100, 100), "My window");
  map<string, double> variables;
  map<string, vector<double>> functions;      //ic of start and end of each func
  map<string, vector<string>> funcParameters; //name of parameters of each func
  map<string, vector<string>> funcReturn; //name of return of each func
  vector<map<string, double>> varFunc; //variables to reset after function
  map<int, pair<double, double>> forLoop;
  map<string, vector<double>> arrays;
vector<string> funcNames;
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


#line 115 "projet.bison.cpp" /* yacc.c:339  */

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
    LIM = 290,
    PLOTGRAPH = 291,
    PRINTFUNC = 292,
    EXP = 293,
    SIN = 294,
    COS = 295,
    TAN = 296,
    IN = 297,
    OUTPUT = 298,
    RETFUNC = 299,
    ARRAY = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "projet.bison" /* yacc.c:355  */

  double valeur;
  char nom[50];
  t_adresse adresse;

#line 207 "projet.bison.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "projet.bison.cpp" /* yacc.c:358  */

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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    49,    47,    55,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,    56,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    54,     2,     2,     2,     2,
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
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   108,   111,   112,   113,   114,   115,   116,
     117,   118,   111,   120,   121,   122,   123,   120,   126,   127,
     128,   129,   126,   131,   132,   133,   131,   136,   137,   138,
     139,   138,   141,   141,   143,   144,   145,   146,   147,   148,
     151,   152,   153,   154,   155,   156,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     176,   177,   178
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
  "GETMAXFOR", "DEFFUNC", "FUNCEXP", "PLOT", "PRINT", "LIM", "PLOTGRAPH",
  "PRINTFUNC", "EXP", "SIN", "COS", "TAN", "IN", "OUTPUT", "RETFUNC",
  "ARRAY", "'+'", "'-'", "'*'", "'/'", "'\\n'", "'('", "')'", "'}'", "','",
  "'='", "'['", "']'", "'>'", "'<'", "'^'", "$accept", "bloc",
  "instruction", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "condition", "expression",
  "setParam", YY_NULLPTR
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
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,    43,    45,    42,
      47,    10,    40,    41,   125,    44,    61,    91,    93,    62,
      60,    94
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -31

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -54,   185,   -54,    86,   -54,   -54,   -54,     3,   -36,   -54,
     136,    14,   136,   136,   -31,   -54,   136,   136,   136,   136,
     136,   136,     6,   184,   -28,   -20,   -54,   -19,    30,   136,
      68,   -54,   184,   184,   -54,   184,   184,   184,   184,   184,
      44,   136,   184,   136,   136,   136,   136,   136,   136,   136,
     136,   161,    31,   -18,   184,    68,   -54,   -44,   132,   132,
     -53,   -53,   184,   184,   -17,   204,   -13,   -12,   -54,   -40,
     136,    19,   -54,   -54,   136,   136,   136,   136,   136,   136,
     -54,   -54,    21,    31,   188,   -54,    22,   184,   184,   184,
     184,   184,   184,    27,    40,   -54,   -14,   136,   -54,   -54,
     -54,   -54,    97,   -54,   -54,     7,   126,   -54,   161,   161,
     136,     8,    38,    11,    16,    20,   -54,   -54,   -54,   -54,
     -54,   -54,    67,   161,   -54,    28,    59,   -54,   -54,   -54,
     161,    42,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    27,     1,     0,     4,    13,    18,     0,     0,    32,
       0,     0,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     3,     0,     0,     0,
       0,    35,    36,    37,     2,    59,    55,    56,    57,    58,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    62,     0,    33,     0,    52,     0,    46,    47,
      48,    49,    51,    50,     0,     0,     0,     0,    61,     0,
       0,     0,    39,     5,     0,     0,     0,     0,     0,     0,
      14,    20,     0,    62,     0,    34,     0,    42,    43,    44,
      45,    40,    41,     0,     0,    29,    60,     0,     6,    15,
      21,     3,     0,     3,     3,     0,    27,    23,     7,    16,
       0,     0,     0,     0,     0,     0,    31,    24,     8,    17,
      22,     3,     0,    25,     9,     0,     0,    26,    10,     3,
      11,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -26,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -49,     9,    15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,    24,    86,   103,   113,   122,   126,   129,
     131,    25,    93,   104,   114,    26,    67,    94,   105,   112,
     121,   125,   101,   111,    29,    64,    65,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    66,    47,    43,    44,    45,    46,    27,    48,    15,
      16,    47,    23,    82,    72,    83,    28,    48,    31,    30,
      34,    32,    33,    85,    49,    35,    36,    37,    38,    39,
      40,    42,    50,    52,    53,    68,    73,    70,    54,    55,
      80,    83,    81,    95,    98,    17,    18,    19,    20,    99,
      57,   100,    58,    59,    60,    61,    62,    63,    21,   110,
     117,   115,   116,    41,    71,   118,    43,    44,    45,    46,
     119,    15,    16,   120,    47,   106,   124,   108,   109,    84,
      48,   128,   127,    87,    88,    89,    90,    91,    92,    15,
      16,    43,    44,    45,    46,   123,   132,    56,    96,    47,
       0,     0,     0,   130,     0,    48,   102,    17,    18,    19,
      20,     0,     0,     0,     0,    43,    44,    45,    46,     0,
      21,     0,     0,    47,     0,    17,    18,    19,    20,    48,
       3,     0,     0,     4,     0,     0,     0,     5,    21,    15,
      16,     0,    22,     0,    43,    44,    45,    46,     6,     7,
     107,     0,    47,     0,     0,     0,     8,     0,    48,     0,
       9,     0,    10,     0,     0,     3,     0,     0,     4,    11,
      12,    13,     5,     0,     0,    17,    18,    19,    20,     0,
     -30,    45,    46,     6,     7,     2,     0,    47,    21,     3,
       0,     8,     4,    48,     0,     9,     5,    10,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     6,     7,     0,
       0,     0,   -27,     0,     0,     8,     0,     0,     0,     9,
       0,    10,    74,    75,    76,    77,     0,     0,    11,    12,
      13,    43,    44,    45,    46,    43,    44,    45,    46,    47,
       0,     0,     0,    97,     0,    48,     0,     0,     0,    48,
       0,    43,    44,    45,    46,     0,     0,     0,     0,    47,
       0,     0,     0,    78,    79,    48
};

static const yytype_int16 yycheck[] =
{
      26,    50,    55,    47,    48,    49,    50,     4,    61,     3,
       4,    55,     3,    53,    58,    55,    52,    61,     4,    10,
      51,    12,    13,     4,    52,    16,    17,    18,    19,    20,
      21,    22,    52,    52,     4,     4,    53,    55,    29,    30,
      53,    55,    54,    22,    22,    39,    40,    41,    42,    22,
      41,    11,    43,    44,    45,    46,    47,    48,    52,    52,
      22,   110,    54,    57,    55,    54,    47,    48,    49,    50,
      54,     3,     4,    53,    55,   101,     9,   103,   104,    70,
      61,    22,    54,    74,    75,    76,    77,    78,    79,     3,
       4,    47,    48,    49,    50,   121,    54,    53,    83,    55,
      -1,    -1,    -1,   129,    -1,    61,    97,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      52,    -1,    -1,    55,    -1,    39,    40,    41,    42,    61,
       4,    -1,    -1,     7,    -1,    -1,    -1,    11,    52,     3,
       4,    -1,    56,    -1,    47,    48,    49,    50,    22,    23,
      53,    -1,    55,    -1,    -1,    -1,    30,    -1,    61,    -1,
      34,    -1,    36,    -1,    -1,     4,    -1,    -1,     7,    43,
      44,    45,    11,    -1,    -1,    39,    40,    41,    42,    -1,
      54,    49,    50,    22,    23,     0,    -1,    55,    52,     4,
      -1,    30,     7,    61,    -1,    34,    11,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    22,    23,    -1,
      -1,    -1,    51,    -1,    -1,    30,    -1,    -1,    -1,    34,
      -1,    36,    18,    19,    20,    21,    -1,    -1,    43,    44,
      45,    47,    48,    49,    50,    47,    48,    49,    50,    55,
      -1,    -1,    -1,    55,    -1,    61,    -1,    -1,    -1,    61,
      -1,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     4,     7,    11,    22,    23,    30,    34,
      36,    43,    44,    45,    64,     3,     4,    39,    40,    41,
      42,    52,    56,    88,    65,    73,    77,     4,    52,    86,
      88,     4,    88,    88,    51,    88,    88,    88,    88,    88,
      88,    57,    88,    47,    48,    49,    50,    55,    61,    52,
      52,    63,    52,     4,    88,    88,    53,    88,    88,    88,
      88,    88,    88,    88,    87,    88,    87,    78,     4,    89,
      55,    88,    58,    53,    18,    19,    20,    21,    59,    60,
      53,    54,    53,    55,    88,     4,    66,    88,    88,    88,
      88,    88,    88,    74,    79,    22,    89,    55,    22,    22,
      11,    84,    88,    67,    75,    80,    63,    53,    63,    63,
      52,    85,    81,    68,    76,    87,    54,    22,    54,    54,
      53,    82,    69,    63,     9,    83,    70,    54,    22,    71,
      63,    72,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    65,    66,    67,    68,    69,    70,
      71,    72,    64,    73,    74,    75,    76,    64,    77,    78,
      79,    80,    64,    81,    82,    83,    64,    64,    64,    84,
      85,    64,    86,    64,    64,    64,    64,    64,    64,    64,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    11,     0,     0,     0,    14,     0,     3,     0,
       0,    10,     0,     3,     5,     2,     2,     2,     2,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     2,
       3,     1,     0
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
#line 111 "projet.bison" /* yacc.c:1648  */
    {}
#line 1424 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 5:
#line 112 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[-4].adresse).ic_false = ic; ins(JNZ, "0"); }
#line 1430 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 6:
#line 113 "projet.bison" /* yacc.c:1648  */
    {}
#line 1436 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 7:
#line 114 "projet.bison" /* yacc.c:1648  */
    {}
#line 1442 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 8:
#line 115 "projet.bison" /* yacc.c:1648  */
    {}
#line 1448 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 9:
#line 116 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[-12].adresse).ic_goto = ic; ins(JMP, "0");instructions[(yyvsp[-12].adresse).ic_false].second = to_string(ic);}
#line 1454 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 10:
#line 117 "projet.bison" /* yacc.c:1648  */
    {}
#line 1460 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 11:
#line 118 "projet.bison" /* yacc.c:1648  */
    {}
#line 1466 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 12:
#line 119 "projet.bison" /* yacc.c:1648  */
    {instructions[(yyvsp[-18].adresse).ic_goto].second = to_string(ic);}
#line 1472 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 13:
#line 120 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[0].adresse).ic_goto = ic;}
#line 1478 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 14:
#line 121 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[-4].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1484 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 15:
#line 122 "projet.bison" /* yacc.c:1648  */
    {}
#line 1490 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 16:
#line 123 "projet.bison" /* yacc.c:1648  */
    {}
#line 1496 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 17:
#line 124 "projet.bison" /* yacc.c:1648  */
    {instructions[(yyvsp[-10].adresse).ic_false].second = to_string(ic+1); ins(JMP, to_string((yyvsp[-10].adresse).ic_goto));}
#line 1502 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 18:
#line 126 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[0].adresse).ic_goto = ic;}
#line 1508 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 19:
#line 127 "projet.bison" /* yacc.c:1648  */
    {}
#line 1514 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 20:
#line 128 "projet.bison" /* yacc.c:1648  */
    {}
#line 1520 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 21:
#line 129 "projet.bison" /* yacc.c:1648  */
    {}
#line 1526 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 22:
#line 130 "projet.bison" /* yacc.c:1648  */
    {ins(JNZINV,to_string((yyvsp[-10].adresse).ic_goto));}
#line 1532 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 23:
#line 131 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[-7].adresse).ic_goto = ic; ins(FOR, (yyvsp[-5].nom)); ins(GET, (yyvsp[-5].nom)); ins(GETMAXFOR, to_string((yyvsp[-7].adresse).ic_goto)); ins(INF, "0"); (yyvsp[-7].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1538 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 24:
#line 132 "projet.bison" /* yacc.c:1648  */
    {}
#line 1544 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 25:
#line 133 "projet.bison" /* yacc.c:1648  */
    {}
#line 1550 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 26:
#line 134 "projet.bison" /* yacc.c:1648  */
    {ins(GET, (yyvsp[-11].nom)); ins(NUMBER, "1"); ins('+', "0"); ins(IDENTIFIER, (yyvsp[-11].nom)); ins(JMP, to_string((yyvsp[-13].adresse).ic_goto+1)); instructions[(yyvsp[-13].adresse).ic_false].second = to_string(ic);ins(GET, (yyvsp[-11].nom)); ins(NUMBER, "1"); ins('-', "0"); ins(IDENTIFIER, (yyvsp[-11].nom));}
#line 1556 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 28:
#line 137 "projet.bison" /* yacc.c:1648  */
    {ins(IDENTIFIER, (yyvsp[-2].nom));}
#line 1562 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 29:
#line 138 "projet.bison" /* yacc.c:1648  */
    {ins(FUNCNAME, (yyvsp[-4].nom)); ins(ADDPARAM, "0"); (yyvsp[-5].adresse).ic_goto = ic; ins(JMP, "0"); functions[(yyvsp[-4].nom)] = vector<double>(2,0); functions[(yyvsp[-4].nom)][0] = ic;}
#line 1568 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 30:
#line 139 "projet.bison" /* yacc.c:1648  */
    {}
#line 1574 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 31:
#line 140 "projet.bison" /* yacc.c:1648  */
    {instructions[(yyvsp[-9].adresse).ic_goto].second = to_string(ic);}
#line 1580 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 32:
#line 141 "projet.bison" /* yacc.c:1648  */
    {(yyvsp[0].adresse).ic_goto = ic; ins(GET, "maxX"); ins(GET, plotVarName); ins(SUP, "0"); (yyvsp[0].adresse).ic_false = ic; ins(JNZ, "0");}
#line 1586 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 33:
#line 142 "projet.bison" /* yacc.c:1648  */
    {ins(PRINTFUNC, "0"); ins(GET, "step"); ins(GET, plotVarName); ins('+', "0"); ins(IDENTIFIER, plotVarName); ins(JMP, to_string((yyvsp[-2].adresse).ic_goto)); instructions[(yyvsp[-2].adresse).ic_false].second = to_string(ic); ins(PLOTGRAPH, "0");}
#line 1592 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 34:
#line 143 "projet.bison" /* yacc.c:1648  */
    {ins(FUNCNAME, (yyvsp[0].nom));ins(LIM, "0"); plotVarName = (yyvsp[0].nom);}
#line 1598 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 35:
#line 144 "projet.bison" /* yacc.c:1648  */
    {ins(IN, (yyvsp[0].nom));}
#line 1604 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 36:
#line 145 "projet.bison" /* yacc.c:1648  */
    {ins(OUTPUT, "0");}
#line 1610 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 37:
#line 146 "projet.bison" /* yacc.c:1648  */
    {ins(RESETFUNC, "0");}
#line 1616 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 38:
#line 147 "projet.bison" /* yacc.c:1648  */
    {ins(FUNCNAME, (yyvsp[-1].nom));ins(EXECFUNC, "0");}
#line 1622 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 39:
#line 148 "projet.bison" /* yacc.c:1648  */
    {ins(ARRAY, "0");}
#line 1628 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 40:
#line 151 "projet.bison" /* yacc.c:1648  */
    {ins(SUP, "0");}
#line 1634 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 41:
#line 152 "projet.bison" /* yacc.c:1648  */
    {ins(INF, "0");}
#line 1640 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 42:
#line 153 "projet.bison" /* yacc.c:1648  */
    {ins(EQUAL, "0");}
#line 1646 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 43:
#line 154 "projet.bison" /* yacc.c:1648  */
    {ins(DIFF, "0");}
#line 1652 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 44:
#line 155 "projet.bison" /* yacc.c:1648  */
    {ins(SUPEQ, "0");}
#line 1658 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 45:
#line 156 "projet.bison" /* yacc.c:1648  */
    {ins(INFEQ, "0");}
#line 1664 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 46:
#line 158 "projet.bison" /* yacc.c:1648  */
    { ins('+', "0");}
#line 1670 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 47:
#line 159 "projet.bison" /* yacc.c:1648  */
    { ins('-', "0");}
#line 1676 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 48:
#line 160 "projet.bison" /* yacc.c:1648  */
    { ins('*', "0");}
#line 1682 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 49:
#line 161 "projet.bison" /* yacc.c:1648  */
    { ins('/', "0");}
#line 1688 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 50:
#line 162 "projet.bison" /* yacc.c:1648  */
    {ins('^', "0");}
#line 1694 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 51:
#line 163 "projet.bison" /* yacc.c:1648  */
    { }
#line 1700 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 52:
#line 164 "projet.bison" /* yacc.c:1648  */
    { }
#line 1706 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 53:
#line 165 "projet.bison" /* yacc.c:1648  */
    {ins(NUMBER, to_string((yyvsp[0].valeur)));}
#line 1712 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 54:
#line 166 "projet.bison" /* yacc.c:1648  */
    {ins(GET, (yyvsp[0].nom));}
#line 1718 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 55:
#line 167 "projet.bison" /* yacc.c:1648  */
    { ins(EXP, "0");}
#line 1724 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 56:
#line 168 "projet.bison" /* yacc.c:1648  */
    { ins(SIN, "0");}
#line 1730 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 57:
#line 169 "projet.bison" /* yacc.c:1648  */
    { ins(COS, "0");}
#line 1736 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 58:
#line 170 "projet.bison" /* yacc.c:1648  */
    { ins(TAN, "0");}
#line 1742 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 59:
#line 171 "projet.bison" /* yacc.c:1648  */
    {ins(FUNCNAME, (yyvsp[-1].nom));ins(EXECFUNC, "0");}
#line 1748 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 60:
#line 176 "projet.bison" /* yacc.c:1648  */
    { }
#line 1754 "projet.bison.cpp" /* yacc.c:1648  */
    break;

  case 61:
#line 177 "projet.bison" /* yacc.c:1648  */
    {ins(FUNCNAME, (yyvsp[0].nom));}
#line 1760 "projet.bison.cpp" /* yacc.c:1648  */
    break;


#line 1764 "projet.bison.cpp" /* yacc.c:1648  */
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
#line 183 "projet.bison" /* yacc.c:1907  */


// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
  switch (instruction){
  case '-'     : return "-";
  case '+'     : return "+";
  case '/'     : return "/";
  case '*'     : return "*";
  case '^'      :return "^";
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
  case EXP     : return "EXP"; 
  case SIN     : return "SIN"; 
  case COS     : return "COS"; 
  case TAN     : return "TAN";
  case IN:        return "IN"; 
  case OUTPUT:    return "OUTPUT"; 
  case  PRINTFUNC:  return "PRINTFUNC";
  case PLOTGRAPH:   return  "PLOTGRAPH";
  case  RETFUNC:    return  "RETFUNC";
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
  double x,y,z; 
  string var;
  plotVarName = "";
  funcPlotX.clear();
  funcPlotY.clear();
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

      case '^': {
        x = depilerDouble(pile);
        y = depilerDouble(pile);
        pile.push_back(to_string(pow(y,x)));
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

      case IN:{ 
        cout << ins.second <<": ";
        cin>>x; 
        variables[ins.second] = x;
        pile.push_back(to_string(x)); 
        ic++; 
      } 
      break; 
 
      case OUTPUT:{ 
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

      case EXP : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(exp(x))); 
        ic++; 
      }
      break; 
 
      case SIN : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(sin(x*M_PI/180))); 
        ic++; 
      }   
      break; 
 
      case COS : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(cos(x))); 
        ic++; 
      }  
      break; 
 
      case TAN : {
        x = depilerDouble(pile); 
        pile.push_back(to_string(sin(x)/cos(x))); 
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
        string funcName = funcNames[funcNames.size() - 1];
        var = depiler(pile);
      
        if(is_number(var)){
            pile.push_back(var);
        }else if(variables.find(var) != variables.end()){
          cout << var << endl;
          pile.push_back(to_string(variables[var]));
        }
        variables = varFunc[varFunc.size()-1];
        varFunc.pop_back();
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
        while(!pile.empty()){
          funcParameters[funcName].push_back(depiler(pile));
        }
        functions[funcName][1] = funcParameters[funcName].size();
        ic++;
      }  
      break;
    

      case EXECFUNC:{
        string funcName = depiler(pile);
        if(pile.size() >= functions[funcName][1]){
          vector<double> parameters;
          for(auto i =0; i < functions[funcName][1]; i++){
            var = depiler(pile);
            if(is_number(var)){
            parameters.push_back(stof(var));
            }else if(variables.find(var) != variables.end()){
              parameters.push_back(variables[var]);
            }

            if(parameters.size() == funcParameters[funcName].size()){
              varFunc.push_back(variables);
              for(auto i = 0; i < parameters.size(); i++){
                variables[funcParameters[funcName][i]] = parameters[i];
              }
              toGoAfterFunc.push_back(ic+1);
              ic = functions[funcName][0];
              funcNames.push_back(funcName);
              
            }else{
              ic++;
            }
          }
        }else{
          ic++;
        }
      }   
      break;

      case LIM:{
        plotVarName = depiler(pile);
        step = depilerDouble(pile);

        maxX = depilerDouble(pile);
        variables["maxX"] = maxX;

        minX = depilerDouble(pile);
        variables[plotVarName] = minX;

        variables["step"] = (maxX-minX)/step;

        ic++;
      }
      break;

      case PLOTGRAPH:{
        sf::VertexArray vertexPoints(sf::LinesStrip, funcPlotX.size());
        for(int i = 0; i < funcPlotX.size(); i++){
          vertexPoints[i].position = sf::Vector2f(funcPlotX[i], funcPlotY[i]);
        }
        variables["maxX"] = maxX;
        variables[plotVarName] = minX;
        window.draw(vertexPoints);
        variables["step"] = (maxX-minX)/step;
        funcPlotX.clear();
        funcPlotY.clear();
        ic++;
      }
      break;

      case PRINTFUNC:{
        funcPlotX.push_back(variables[plotVarName]+window.getSize().x/2);
        x = depilerDouble(pile);
        funcPlotY.push_back(-x+window.getSize().y/2);
        ic++;
      }
      break;

      case ARRAY:{
        var = depiler(pile);
        while(!pile.empty()){
          arrays[var].push_back(depilerDouble(pile));
        }
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
  sf::VertexArray vertexPoints(sf::LinesStrip, 2);
          vertexPoints[0].position = sf::Vector2f(0, window.getSize().y/2);
          vertexPoints[1].position = sf::Vector2f(window.getSize().x, window.getSize().y/2);
  window.draw(vertexPoints);

          vertexPoints[0].position = sf::Vector2f(window.getSize().x/2, 0);
          vertexPoints[1].position = sf::Vector2f(window.getSize().x/2, window.getSize().y);
  window.draw(vertexPoints);
  window.display();
  //  while (window.isOpen())
  //   {
  //       // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
  //       sf::Event event;
  //       while (window.pollEvent(event))
  //       {
  //           // fermeture de la fenêtre lorsque l'utilisateur le souhaite
  //           if (event.type == sf::Event::Closed)
  //               window.close();
            
  //       }

        
  //   }

}

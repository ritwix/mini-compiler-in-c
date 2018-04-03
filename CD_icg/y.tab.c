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
#line 1 "parser.y" /* yacc.c:339  */

	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "codegen.cpp"

	int yylex(void);
	void yyerror(char *);

    extern FILE* yyin;
	extern int linecount;
	extern int commentflag;
	int flagarr = 0;
	int error;
	int type;
	int flag = -1;
	int flagassign = 0;
	extern char* yytext;



#line 90 "y.tab.c" /* yacc.c:339  */

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    _GREAT_EQ = 258,
    _LESS_EQ = 259,
    _LOGIC_OR = 260,
    _LOGIC_AND = 261,
    _NOT_EQ = 262,
    _EQUAL = 263,
    _INCR_1 = 264,
    _DECR_1 = 265,
    _CONSTANT = 266,
    _INCR_VAL = 267,
    _DECR_VAL = 268,
    _MULT_VAL = 269,
    _DIV_VAL = 270,
    _MOD_VAL = 271,
    _DO = 272,
    _ELSE = 273,
    _FOR = 274,
    _IF = 275,
    _PRINT = 276,
    _SCAN = 277,
    _WHILE = 278,
    _HEADER = 279,
    _PREPROC = 280,
    _STRING = 281,
    _RETURN = 282,
    _IDENTIFIER = 283,
    _MAIN = 284,
    _INT = 285,
    _CHAR = 286,
    _VOID = 287,
    MOD_VAL = 288
  };
#endif
/* Tokens.  */
#define _GREAT_EQ 258
#define _LESS_EQ 259
#define _LOGIC_OR 260
#define _LOGIC_AND 261
#define _NOT_EQ 262
#define _EQUAL 263
#define _INCR_1 264
#define _DECR_1 265
#define _CONSTANT 266
#define _INCR_VAL 267
#define _DECR_VAL 268
#define _MULT_VAL 269
#define _DIV_VAL 270
#define _MOD_VAL 271
#define _DO 272
#define _ELSE 273
#define _FOR 274
#define _IF 275
#define _PRINT 276
#define _SCAN 277
#define _WHILE 278
#define _HEADER 279
#define _PREPROC 280
#define _STRING 281
#define _RETURN 282
#define _IDENTIFIER 283
#define _MAIN 284
#define _INT 285
#define _CHAR 286
#define _VOID 287
#define MOD_VAL 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:355  */

	int number;
    char str[10000];

#line 201 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   595

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,    50,     2,
      43,    44,    40,    38,    33,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      37,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    53,    54,    55,    58,    66,    72,    73,
      79,    82,    86,    91,    96,   103,   124,   144,   163,   185,
     206,   228,   229,   233,   237,   241,   269,   275,   276,   281,
     289,   294,   307,   359,   359,   359,   360,   361,   362,   365,
     375,   385,   395,   405,   415,   416,   426,   436,   446,   456,
     466,   476,   486,   496,   497,   497,   563,   623,   682,   742,
     748,   755,   756,   759,   772,   783,   795,   796,   799,   800,
     803,   804,   805,   806,   809,   810,   817,   817,   824,   831,
     838,   839,   842,   847,   853,   860,   868,   876
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_GREAT_EQ", "_LESS_EQ", "_LOGIC_OR",
  "_LOGIC_AND", "_NOT_EQ", "_EQUAL", "_INCR_1", "_DECR_1", "_CONSTANT",
  "_INCR_VAL", "_DECR_VAL", "_MULT_VAL", "_DIV_VAL", "_MOD_VAL", "_DO",
  "_ELSE", "_FOR", "_IF", "_PRINT", "_SCAN", "_WHILE", "_HEADER",
  "_PREPROC", "_STRING", "_RETURN", "_IDENTIFIER", "_MAIN", "_INT",
  "_CHAR", "_VOID", "','", "'='", "MOD_VAL", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'",
  "'&'", "$accept", "global", "funcdec", "mainfunc", "funcdec_",
  "declaration", "type_specifier", "declist", "pointer", "optional",
  "optional_call", "main", "functiondec", "body", "expression", "$@1",
  "expression_statement", "funccall_statement", "return_statement",
  "io_statement", "identifier_list", "identifieraddr_list", "statement",
  "$@2", "loop_statement", "do_statement", "if_statement",
  "else_statement", YY_NULLPTR
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
     285,   286,   287,    44,    61,   288,    62,    60,    43,    45,
      42,    47,    37,    40,    41,   123,   125,    59,    91,    93,
      38
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    15,    66,   139,  -124,  -124,  -124,  -124,  -124,   139,
     139,  -124,    95,    37,    58,   139,    91,   139,  -124,    61,
     101,  -124,   -17,   126,   548,   548,   139,   548,   108,    91,
    -124,    56,  -124,  -124,   113,   120,   121,   140,   141,  -124,
       9,    80,    94,  -124,  -124,    91,   119,   174,  -124,   138,
    -124,  -124,  -124,   142,   150,   151,   362,   393,  -124,   169,
     139,     2,   164,    14,    94,   182,   183,    94,   152,  -124,
     186,    94,    22,    24,   198,   189,  -124,  -124,   171,  -124,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,  -124,  -124,   548,   548,   548,  -124,
    -124,   172,    91,   180,  -124,   132,    14,   240,   197,   199,
     250,  -124,   321,   192,  -124,  -124,  -124,   215,  -124,   172,
    -124,   388,   388,    76,    76,   292,   292,   361,   388,   388,
      85,    85,  -124,  -124,  -124,   424,   455,   486,   216,   223,
     204,   361,  -124,    20,  -124,   231,    -9,  -124,    94,   212,
      94,  -124,   238,   244,   132,   172,   258,  -124,   260,   152,
     124,   152,   242,   128,   311,   243,   361,   229,   256,   361,
    -124,   252,   226,  -124,  -124,   267,   264,  -124,   152,    -1,
     265,  -124,   254,    94,  -124,   268,   139,  -124,   152,  -124,
    -124,   152,   293,  -124,  -124,   302,   548,    91,  -124,  -124,
     152,   273,   517,   294,  -124,  -124,  -124,   172,   279,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    12,    13,    14,     2,     0,
       0,     8,    22,     0,     0,     5,    22,     3,    10,     0,
       0,    21,     0,     0,     0,     0,     4,     0,     0,    22,
      11,    26,    59,    85,     0,     0,     0,     0,     0,    60,
       0,    30,     0,    61,    33,    22,     0,     0,    74,     0,
      80,    81,    34,     0,     0,     0,     0,     0,    31,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    30,    64,
       0,     0,     0,    58,     0,     0,     6,    36,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    35,     0,     0,     0,     7,
       9,    26,    22,     0,    23,     0,     0,     0,     0,     0,
       0,    65,     0,     0,    27,    56,    57,     0,    44,    26,
      38,    47,    48,    52,    51,    49,    50,    53,    45,    46,
      39,    40,    41,    42,    43,     0,     0,     0,    17,     0,
      24,    19,    20,     0,    86,     0,     0,    84,     0,    28,
       0,    78,     0,    75,     0,    26,     0,    82,     0,    30,
       0,    30,     0,     0,    53,     0,    55,     0,     0,    15,
      16,     0,     0,    83,    69,     0,     0,    73,    30,     0,
       0,    63,     0,     0,    87,     0,     0,    25,    30,    66,
      71,    30,     0,    67,    29,     0,     0,    22,    68,    72,
      30,     0,     0,     0,    70,    79,    77,    26,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   326,   112,    -3,     0,  -124,   -21,   -96,
    -123,  -124,    52,   -23,     5,  -124,   -62,   -35,  -124,  -124,
    -124,  -124,   -28,  -124,  -124,  -124,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    44,    45,    22,    23,    62,
      73,    13,    14,    46,    47,   117,    48,    49,    50,    51,
     160,   163,    52,   168,    53,    54,    55,   185
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   106,    56,    12,    57,   138,    11,    18,    59,    16,
      12,    78,    18,   103,    11,    16,    29,    16,    79,   161,
      32,    78,    78,    18,    75,    32,    16,   191,    79,    79,
      30,    32,     1,   115,   116,    39,   174,    68,   177,     3,
      39,   162,    68,    77,   143,    70,    39,    74,    68,   192,
     113,   104,    42,    77,    77,   190,    69,    42,   -54,   171,
     102,    43,    19,    42,   157,   198,     4,    19,   199,   107,
     142,   114,   110,   135,   136,   137,   112,   204,    19,    80,
      81,   139,    24,    84,    85,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    60,
      78,    78,    78,    25,    61,    32,    27,    79,    79,    79,
     141,   208,    87,    88,    89,    90,    91,    92,    93,   170,
      39,    15,    68,    71,    20,    91,    92,    93,    72,    26,
      32,    21,    77,    77,    77,    21,    33,    42,    34,    35,
      36,    37,    38,    32,    28,    39,    40,    41,   158,     5,
       6,     7,    58,   164,    31,   166,    63,   175,    39,   169,
      41,   179,    42,    64,    65,    76,    43,    78,   176,     5,
       6,     7,   180,   202,    79,    42,   203,    80,    81,    82,
      83,    84,    85,    66,    67,    95,   197,    96,   195,    80,
      81,    82,    83,    84,    85,    97,    98,   101,   105,    77,
      72,    80,    81,    82,    83,    84,    85,    86,   108,   109,
      87,    88,    89,    90,    91,    92,    93,   119,   120,    86,
      61,    94,    87,    88,    89,    90,    91,    92,    93,   140,
     145,    86,   146,   111,    87,    88,    89,    90,    91,    92,
      93,   149,   118,    80,    81,    82,    83,    84,    85,   150,
     154,   155,   156,    80,    81,    82,    83,    84,    85,   159,
     165,   167,   -76,    80,    81,    82,    83,    84,    85,   172,
     178,   182,   183,    86,   184,   187,    87,    88,    89,    90,
      91,    92,    93,    86,   144,   186,    87,    88,    89,    90,
      91,    92,    93,    86,   147,   188,    87,    88,    89,    90,
      91,    92,    93,   194,   173,    80,    81,    82,    83,    84,
      85,   189,   193,   196,    80,    81,    82,    83,    84,    85,
     205,   200,   207,   209,    80,    81,    82,    83,    84,    85,
      89,    90,    91,    92,    93,    86,    17,     0,    87,    88,
      89,    90,    91,    92,    93,     0,   201,    87,    88,    89,
      90,    91,    92,    93,   148,   181,     0,    87,    88,    89,
      90,    91,    92,    93,    80,    81,    82,    83,    84,    85,
       0,     0,     0,    32,     0,     0,     0,     0,     0,    33,
       0,    34,    35,    36,    37,    38,     0,     0,    39,    40,
      41,     0,     5,     6,     7,    84,    85,    87,    88,    89,
      90,    91,    92,    93,    32,    42,     0,     0,    99,    43,
      33,     0,    34,    35,    36,    37,    38,     0,     0,    39,
      40,    41,     0,     5,     6,     7,    89,    90,    91,    92,
      93,     0,     0,     0,     0,    32,    42,     0,     0,   100,
      43,    33,     0,    34,    35,    36,    37,    38,     0,     0,
      39,    40,    41,     0,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    42,     0,     0,
     151,    43,    33,     0,    34,    35,    36,    37,    38,     0,
       0,    39,    40,    41,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    42,     0,
       0,   152,    43,    33,     0,    34,    35,    36,    37,    38,
       0,     0,    39,    40,    41,     0,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    42,
       0,     0,   153,    43,    33,     0,    34,    35,    36,    37,
      38,     0,     0,    39,    40,    41,     0,     5,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      42,     0,     0,   206,    43,    33,     0,    34,    35,    36,
      37,    38,     0,     0,    39,    40,    41,     0,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       3,    63,    25,     3,    27,   101,     9,    10,    29,     9,
      10,    46,    15,    11,    17,    15,    33,    17,    46,    28,
      11,    56,    57,    26,    45,    11,    26,    28,    56,    57,
      47,    11,    25,     9,    10,    26,   159,    28,   161,    24,
      26,    50,    28,    46,   106,    40,    26,    42,    28,    50,
      28,    49,    43,    56,    57,   178,    47,    43,    34,   155,
      60,    47,    10,    43,    44,   188,     0,    15,   191,    64,
     105,    49,    67,    96,    97,    98,    71,   200,    26,     3,
       4,   102,    45,     7,     8,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    43,
     135,   136,   137,    45,    48,    11,    45,   135,   136,   137,
     105,   207,    36,    37,    38,    39,    40,    41,    42,   154,
      26,     9,    28,    43,    29,    40,    41,    42,    48,    17,
      11,    40,   135,   136,   137,    40,    17,    43,    19,    20,
      21,    22,    23,    11,    43,    26,    27,    28,   143,    30,
      31,    32,    44,   148,    28,   150,    43,    33,    26,   154,
      28,    33,    43,    43,    43,    46,    47,   202,    44,    30,
      31,    32,    44,   196,   202,    43,   197,     3,     4,     5,
       6,     7,     8,    43,    43,    47,   186,    45,   183,     3,
       4,     5,     6,     7,     8,    45,    45,    28,    34,   202,
      48,     3,     4,     5,     6,     7,     8,    33,    26,    26,
      36,    37,    38,    39,    40,    41,    42,    28,    47,    33,
      48,    47,    36,    37,    38,    39,    40,    41,    42,    49,
      33,    33,    33,    47,    36,    37,    38,    39,    40,    41,
      42,    49,    44,     3,     4,     5,     6,     7,     8,    34,
      34,    28,    48,     3,     4,     5,     6,     7,     8,    28,
      48,    23,    18,     3,     4,     5,     6,     7,     8,    11,
      28,    28,    43,    33,    18,    49,    36,    37,    38,    39,
      40,    41,    42,    33,    44,    33,    36,    37,    38,    39,
      40,    41,    42,    33,    44,    28,    36,    37,    38,    39,
      40,    41,    42,    49,    44,     3,     4,     5,     6,     7,
       8,    47,    47,    45,     3,     4,     5,     6,     7,     8,
      47,    28,    28,    44,     3,     4,     5,     6,     7,     8,
      38,    39,    40,    41,    42,    33,    10,    -1,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    36,    37,    38,
      39,    40,    41,    42,    33,    44,    -1,    36,    37,    38,
      39,    40,    41,    42,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    -1,    30,    31,    32,     7,     8,    36,    37,    38,
      39,    40,    41,    42,    11,    43,    -1,    -1,    46,    47,
      17,    -1,    19,    20,    21,    22,    23,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    11,    43,    -1,    -1,    46,
      47,    17,    -1,    19,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    43,    -1,    -1,
      46,    47,    17,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    43,    -1,
      -1,    46,    47,    17,    -1,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    -1,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    43,
      -1,    -1,    46,    47,    17,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      43,    -1,    -1,    46,    47,    17,    -1,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    52,    24,     0,    30,    31,    32,    53,    54,
      55,    56,    57,    62,    63,    55,    57,    54,    56,    63,
      29,    40,    58,    59,    45,    45,    55,    45,    43,    33,
      47,    28,    11,    17,    19,    20,    21,    22,    23,    26,
      27,    28,    43,    47,    56,    57,    64,    65,    67,    68,
      69,    70,    73,    75,    76,    77,    64,    64,    44,    59,
      43,    48,    60,    43,    43,    43,    43,    43,    28,    47,
      65,    43,    48,    61,    65,    59,    46,    56,    68,    73,
       3,     4,     5,     6,     7,     8,    33,    36,    37,    38,
      39,    40,    41,    42,    47,    47,    45,    45,    45,    46,
      46,    28,    57,    11,    49,    34,    67,    65,    26,    26,
      65,    47,    65,    28,    49,     9,    10,    66,    44,    28,
      47,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    64,    64,    64,    60,    59,
      49,    65,    68,    67,    44,    33,    33,    44,    33,    49,
      34,    46,    46,    46,    34,    28,    48,    44,    65,    28,
      71,    28,    50,    72,    65,    48,    65,    23,    74,    65,
      68,    60,    11,    44,    61,    33,    44,    61,    28,    33,
      44,    44,    28,    43,    18,    78,    33,    49,    28,    47,
      61,    28,    50,    47,    49,    65,    45,    57,    61,    61,
      28,    44,    64,    59,    61,    47,    46,    28,    60,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    54,    55,    55,    55,
      55,    56,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    65,    65,    65,    65,    65,
      65,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    73,    73,    73,
      73,    73,    75,    75,    75,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     4,     4,     1,     5,
       2,     3,     1,     1,     1,     7,     7,     5,     3,     5,
       5,     1,     0,     2,     3,     6,     0,     2,     3,     6,
       0,     4,    14,     1,     1,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     5,     3,     3,     2,     1,
       1,     1,     2,     6,     2,     3,     7,     7,     4,     2,
       5,     3,     4,     2,     1,     4,     0,     9,     4,     9,
       1,     1,     5,     6,     4,     1,     4,     1
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
        case 6:
#line 59 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();
		 }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 67 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();
		 }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
			s.pop();
		 }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "parser.y" /* yacc.c:1646  */
    {
 	flag = 3;
 	strcpy((yyval.str),"INTEGER_VARIABLE");
 }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "parser.y" /* yacc.c:1646  */
    {
 	strcpy((yyval.str),"CHAR_VARIABLE");
 	flag = 4;
 }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "parser.y" /* yacc.c:1646  */
    {
 	strcpy((yyval.str),"VOID_VARIABLE");
 	flag = 5;
 }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
			token = (yyvsp[-3].str);
			if(flagarr == 0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[-2].str);
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push((yyvsp[-3].str));
			printTACasgn();
		}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
			token = (yyvsp[-3].str);
			if(flagarr == 0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[-2].str);
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
		}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 145 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
  			token = (yyvsp[-1].str);
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[0].str);
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
  		}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
			token = (yyvsp[-1].str);
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[0].str);
				int i;
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push((yyvsp[-1].str));
			disp(table);
		}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 186 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
			token = (yyvsp[-3].str);
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[-2].str);
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
			operands.push((yyvsp[-3].str));
			printTACasgn();
		}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "parser.y" /* yacc.c:1646  */
    {
			table = s.top();
			token = (yyvsp[-3].str);
			if(flagarr ==0)
			{
				error = insertToken(flag,table);
			}
			else
			{
				error = insertToken(flag,table);
				columnMap[token] = (yyvsp[-2].str);
			}
			if(error)
			{
				printf("REDECLARED_VARIABLE");
				exit(error);
			}
		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 1;
 }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 238 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 1;
 }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 242 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 2;
	int num = (yyvsp[-1].number);
	int i;
	char tempS[100];
	int k = 0;
	if(num == 0)
	{
		tempS[k++] = '0';
	}
	while(num!=0)
	{
		int r = num % 10;
		tempS[k++] = '0' + r;
		num /= 10;
	}
	tempS[k] = '\0';
	char tempC;
	for(i = 0; i < (k / 2); i++)
	{
		tempC = tempS[i];
		tempS[i] = tempS[k - i - 1];
		tempS[k - i - 1] = tempC;
	}
	strcpy((yyval.str), tempS);
 }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 0;
 }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "parser.y" /* yacc.c:1646  */
    {
 	strcpy((yyval.str),(yyvsp[-1].str));
	flagarr = 1;
 }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 282 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 2;
	strcpy((yyval.str), (yyvsp[-4].str));
	strcat((yyval.str), ",");
	strcat((yyval.str), (yyvsp[-1].str));
 }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 289 "parser.y" /* yacc.c:1646  */
    {
 	flagarr = 0;
 }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "parser.y" /* yacc.c:1646  */
    {
		 table.clear();
     	 s.push(table);
    	 counter++;
		 token = (yyvsp[-2].str);
		 insertToken(2,table);
		 ret = helper[(yyvsp[-3].str)];
		 makeFunction(token);
		 labelFuncCall(token);
	  }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 308 "parser.y" /* yacc.c:1646  */
    {

				table.clear();
				s.push(table);
			    counter++;
				token = (yyvsp[-11].str);
				makeFunction(token);
				error = insertToken(flag,table);
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				token = (yyvsp[-7].str);
				if(flagarr ==0)
				{
					error = insertToken(flag,table);
				}
				else
				{
				error = insertToken(flagarr+5,table);
				}
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				token = (yyvsp[-2].str);
				if(flagarr ==0)
				{
					error = insertToken(flag,table);
				}
				else
				{
				error = insertToken(flagarr+5,table);
				}
				if(error)
				{
					printf("REDECLARED_VARIABLE");
					exit(error);
				}
				ret = helper[(yyvsp[-13].str)];
				error = insertFunc((yyvsp[-13].str),(yyvsp[-11].str),(yyvsp[-9].str),(yyvsp[-4].str));
				if(error == -1)
				{
					printf("REDECLARED_FUNCTION");
					exit(error);
				}
			}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 366 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("+");
			}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 376 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("-");
			}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("*");
			}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number) || (yyval.number) != (yyvsp[-2].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("/");
			}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 406 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number) || (yyval.number) != (yyvsp[-2].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("%");
			}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 417 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC(">");
			}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 427 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("<");
			}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 437 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC(">=");
			}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 447 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("<=");
			}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 457 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("!=");
			}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("==");
			}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 477 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("&&");
			}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 487 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].number)!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error");
					exit(2);
				}
				(yyval.number) = (yyvsp[-2].number);
				printTAC("||");
			}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 497 "parser.y" /* yacc.c:1646  */
    {flagassign = flagarr;}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 498 "parser.y" /* yacc.c:1646  */
    {

				token = (yyvsp[-4].str);
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE\n");
					exit(error);
				}
				type = lookupType((yyvsp[-4].str));
		   		if(type!=(yyvsp[0].number))
				{
					printf("Type Mismatch Error\n");
					exit(2);
				}
				operands.push((yyvsp[-4].str));
				if(flagassign == 1)
				{
					printf("$$$$$$$$$$$$$$$$$%s",(yyvsp[-3].str));
					operands.push((yyvsp[-3].str));
					printTAC("+");
				}
				if(flagassign == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, (yyvsp[-3].str));
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACasgn();
           }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 564 "parser.y" /* yacc.c:1646  */
    {
		   		(yyval.number) = lookupType((yyvsp[-2].str));
				token = (yyvsp[-2].str);
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push((yyvsp[-2].str));
				if(flagarr == 1)
				{
					operands.push((yyvsp[-1].str));
					printTAC("+");

				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, (yyvsp[-1].str));
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACun('+');
		   }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 624 "parser.y" /* yacc.c:1646  */
    {
		   		(yyval.number) = lookupType((yyvsp[-2].str));
				token = (yyvsp[-2].str);
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push((yyvsp[-2].str));
				if(flagarr == 1)
				{
					operands.push((yyvsp[-1].str));
					printTAC("+");
				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, (yyvsp[-1].str));
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}
				printTACun('-');
		   }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 683 "parser.y" /* yacc.c:1646  */
    {
		   		(yyval.number) = lookupType((yyvsp[-1].str));
				token = (yyvsp[-1].str);
				error = lookupTable(token);
				if(error)
				{
					printf("UNDECLARED_VARIABLE");
					exit(error);
				}
				operands.push((yyvsp[-1].str));

				if(flagarr == 1)
				{
					operands.push((yyvsp[0].str));
					printTAC("+");
				}
				if(flagarr == 2)
				{
					int i;
					char TotColumn[1000];
					char charStarColumnMap[1000];
					for(i = 0; i < columnMap[token].length(); i++)
						charStarColumnMap[i] = columnMap[token][i];
					charStarColumnMap[i] = '\0';
					strcpy(TotColumn, charStarColumnMap);
					char s[1000];
					strcpy(s, (yyvsp[0].str));
					char a[500], b[500];
					int p = 0, q = 0;
					int next = 0;
					for(i = 0; i < strlen(s); i++)
					{
						if(s[i] == ',')
						{
							next = 1;
							continue;
						}
						if(next == 1)
						{
							b[q++] = s[i];
						}
						else
						{
							a[p++] = s[i];
						}
					}
					a[p] = '\0';
					b[q] = '\0';
					operands.push(a);
					operands.push("1");
					printTAC("-");
					operands.push(TotColumn);
					printTAC("*");
					operands.push(b);
					printTAC("+");
					printTAC("+");
				}

		   }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 743 "parser.y" /* yacc.c:1646  */
    {
	   			(yyval.number) = 3;
				//strcpy(, yytext);
				operands.push(yytext);
		   }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 749 "parser.y" /* yacc.c:1646  */
    {
		   		(yyval.number) = 4;
				operands.push(yytext);
		   }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 760 "parser.y" /* yacc.c:1646  */
    {

						error = funcType((yyvsp[-5].str),(yyvsp[-3].number),(yyvsp[-1].number));
						if(error == -1)
						{
							printf("Function call arguments type error\n");
							exit(1);
						}
						labelFuncCall((yyvsp[-5].str));
					}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 773 "parser.y" /* yacc.c:1646  */
    {
						printf("^^^^^^^^^^^^^^^^^^^^%d",ret);
						if(ret != 5)
						{
							printf("return type mismatch error\n");
							exit(1);
						}
						operands.push("");
						printRet();
					}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 784 "parser.y" /* yacc.c:1646  */
    {

						if(ret != (yyvsp[-1].number) )
						{
							printf("return type mismatch error\n");
							exit(1);
						}
						printRet();
					}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 811 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printLabel();
		  }
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 817 "parser.y" /* yacc.c:1646  */
    {printGotoLabel();}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 818 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printLabel();
		  }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 825 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();

		  }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 832 "parser.y" /* yacc.c:1646  */
    {
			disp(s.top());
			if(!s.empty())
				s.pop();
			printTADoWhile();
		  }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 843 "parser.y" /* yacc.c:1646  */
    {
					table.clear();
					s.push(table); counter++;
			   }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 848 "parser.y" /* yacc.c:1646  */
    {
				    table.clear();
				    s.push(table); counter++;

			   }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 854 "parser.y" /* yacc.c:1646  */
    {
				    table.clear();
				    s.push(table); counter++;
			   }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 861 "parser.y" /* yacc.c:1646  */
    {
				table.clear();
				s.push(table); counter++;
				makeLabel();
			 }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 869 "parser.y" /* yacc.c:1646  */
    {
			 	printTAIfNot();
				table.clear();
				s.push(table); counter++;
			 }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 877 "parser.y" /* yacc.c:1646  */
    {
					disp(s.top());
					if(!s.empty())
						s.pop();
			   		table.clear();
					s.push(table); counter++;
			   }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2483 "y.tab.c" /* yacc.c:1646  */
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
#line 886 "parser.y" /* yacc.c:1906  */



int main(int argc, char *argv[])
{
	FILE* SRC;
	printf("\nSYNTACTICAL ANALYSIS\n");
	printf("----------------\n\n");
	if (argc == 2 && (SRC = fopen(argv[1],"r")))
        	yyin = SRC;
	else if(SRC == NULL)
	{
		printf("File not found\n");
		exit(0);
	}
	helper["FUNCTION"] = 1;
	helper["MAIN_FUNCTION"] = 2;
	helper["INTEGER_VARIABLE"] = 3;
	helper["CHAR_VARIABLE"] = 4;
	helper["VOID_VARIABLE"] = 5;
	insertFunc("INTEGER_VARIABLE", "strcmp", "CHAR_VARIABLE", "CHAR_VARIABLE");
	insertFunc("INTEGER_VARIABLE", "strcpy", "CHAR_VARIABLE", "CHAR_VARIABLE");
	table.clear();
	s.push(table);
	ofstream ofs;
	ofs.open("icg.txt",std::ofstream::out | std::ofstream::trunc);
	if(!yyparse())
		printf("\nPARSING PASSED!\n");
	else
		printf("\nPARSING FAILED!\n");
	fclose(SRC);
	ofs.close();
	if(commentflag)
	{
		printf("\nERROR 2 : Comment not closed\n");
		exit(2);
	}

	return 0;
}

void yyerror(char *msg)
{
	printf("\nSYNTAX ERROR at line %d\n",linecount);
}

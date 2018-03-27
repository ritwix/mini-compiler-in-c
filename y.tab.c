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
#line 1 "par.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    char * typ;
    extern FILE *fp;
    extern char idname[1000];
    extern int yylineno;
    int yylex(void);
    int dim=0;    
    void yyerror(char*);
    #define SIZE 1000
    int hashCode(char* key);
    void insert_hash(char *,char *,int,int,int, char *);
    void display_hash();
    struct DataItem 
    {
        char* text;             /* The token*/
        char* type;         /* Type of the token*/
        int scope;
        int lineno;         /* Line number in the input file*/
        int arrdim;
        char* retype;
     	
        struct DataItem * next;     /*Pointer to next data item*/
    };
    struct DataItem* hashArray[SIZE]; 
    struct DataItem* item;
    int scopes[1000];
int scopesLength = 1;
int scopeCounter = 1;
int getCurrentScope();
void startNewScope();
void endCurrentScope();
int isScopeValid(int);
int hash_lookup_scope(char * key);
void getidtype(char *);
int gdim=0;  
char * typ, * op1,* op2; 
int flg=0; 

#line 108 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    NUM = 259,
    CHLIT = 260,
    STRINGLIT = 261,
    INT = 262,
    VOID = 263,
    CHAR = 264,
    UMINUS = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    BREAK = 269,
    SCANF = 270,
    PRINTF = 271,
    RETURN = 272,
    LBRACE = 273,
    RBRACE = 274,
    LPAREN = 275,
    RPAREN = 276,
    SEMICOLON = 277,
    COMMA = 278,
    DOT = 279,
    LSQ = 280,
    RSQ = 281,
    QM = 282,
    AND = 283,
    NOT = 284,
    OR = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    ASSIGN = 291,
    ISEQ = 292,
    GT = 293,
    LT = 294,
    GEQ = 295,
    LEQ = 296,
    DAND = 297,
    DOR = 298,
    NEQ = 299
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define CHLIT 260
#define STRINGLIT 261
#define INT 262
#define VOID 263
#define CHAR 264
#define UMINUS 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define BREAK 269
#define SCANF 270
#define PRINTF 271
#define RETURN 272
#define LBRACE 273
#define RBRACE 274
#define LPAREN 275
#define RPAREN 276
#define SEMICOLON 277
#define COMMA 278
#define DOT 279
#define LSQ 280
#define RSQ 281
#define QM 282
#define AND 283
#define NOT 284
#define OR 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define MOD 290
#define ASSIGN 291
#define ISEQ 292
#define GT 293
#define LT 294
#define GEQ 295
#define LEQ 296
#define DAND 297
#define DOR 298
#define NEQ 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
       0,    58,    58,    59,    61,    62,    65,    66,    67,    68,
      69,    71,    78,    84,    85,    87,    88,    90,    91,    92,
      93,    94,    95,    97,   102,   107,   109,   115,   121,   122,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   134,
     135,   136,   137,   138,   140,   141,   142,   144,   165,   166,
     168,   169,   170,   172,   173,   175,   176,   177,   179,   180,
     181,   183,   184,   185,   186,   186,   187,   188,   189,   190,
     190,   210,   210,   230,   230,   250,   250,   270,   270,   290,
     290,   310,   310,   330,   330,   350,   350,   370,   370,   390,
     391,   399,   408,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "CHLIT", "STRINGLIT", "INT",
  "VOID", "CHAR", "UMINUS", "IF", "ELSE", "WHILE", "BREAK", "SCANF",
  "PRINTF", "RETURN", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "SEMICOLON",
  "COMMA", "DOT", "LSQ", "RSQ", "QM", "AND", "NOT", "OR", "ADD", "SUB",
  "MUL", "DIV", "MOD", "ASSIGN", "ISEQ", "GT", "LT", "GEQ", "LEQ", "DAND",
  "DOR", "NEQ", "$accept", "program", "declist", "declstmt", "intid",
  "cid", "assign", "funclist", "funcdecl", "ifid", "vfid", "compstmt",
  "block_start", "block_end", "stmtlist", "stmt", "declaration", "funcall",
  "fc", "whilestmt", "ifstmt", "returnstmt", "printstmt", "scanstmt",
  "expr", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "identifier", "arrid", "declarray", YY_NULLPTR
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

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,     6,     9,    13,    24,   123,   -62,    72,   -62,   -62,
     -14,    -6,    -4,    32,     3,   -62,    -6,   -62,   -62,    72,
      23,   -62,   -62,    29,   118,    89,    59,    51,   -62,    59,
      -2,    94,    88,   107,   112,   -62,   -62,   118,   118,    27,
      78,   118,   -62,    59,   -62,    -8,   -62,   -62,   180,   117,
      59,    51,   -62,    13,   119,   -62,   196,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   268,
      -6,    51,   136,    12,   142,    13,   129,   137,   139,   140,
      52,   -62,    31,   -62,   -62,   -62,    83,   -62,   -62,   -62,
     -62,   -62,    27,   -62,   159,   147,   -62,    -6,   -62,   -62,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   134,   150,   -62,    59,   -62,   149,    -6,    -6,   118,
     118,   173,   175,   -62,   252,   -62,   -62,   -62,   164,   182,
      59,    51,   166,   114,   114,   276,   276,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   124,   -62,   169,   102,   113,   210,
     224,    18,    22,   -62,   -62,   172,   118,   177,   -62,   -62,
     -62,   -62,    51,   -62,    59,   -62,    13,   160,   160,   179,
     171,   184,   201,   -62,   238,    51,   -62,    -6,    -6,   195,
     -62,   -62,   -62,   -62,   205,   -62,    54,   187,   -62,   188,
     189,    51,    62,   202,   215,   -62,   -62,   -62,   -62,   203,
     204,   -62,   217,   -62,   236,   230,   225,   -62,   231,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     5,     3,    16,    10,
      11,    14,     0,     0,     0,    12,    14,     1,     4,     2,
       0,    15,    23,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,    91,    62,    63,     0,     0,    13,
      61,     0,     7,     0,    11,     0,    26,    19,     0,     0,
       0,     0,     9,     0,     0,    92,     0,    90,    69,    71,
      73,    75,    85,    81,    83,    77,    79,    87,    64,     0,
      14,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,    38,     0,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    43,     0,     0,    22,    14,    93,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,    18,     0,    47,    11,    14,    14,     0,
       0,     0,     0,    54,     0,    27,    25,    28,     0,     0,
       0,     0,     0,    70,    72,    74,    76,    86,    82,    84,
      78,    80,    88,    65,     0,     6,     0,     0,     0,     0,
       0,     0,     0,    53,    46,     0,     0,     0,    21,     8,
      68,    67,     0,    40,     0,    42,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,    17,    14,    14,    50,
      52,    48,    49,    58,     0,    55,     0,     0,    20,     0,
       0,     0,     0,     0,     0,    44,    39,    41,    51,     0,
       0,    56,     0,    59,     0,     0,     0,    57,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   255,   -25,   -46,   -16,   261,     1,   -62,
     -62,   -49,   -62,   -62,   -62,   -61,   -62,   143,   -62,   -62,
     -62,   -62,   -62,   -62,   -10,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    16,    25,     7,     8,    12,
      14,    47,    48,   126,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   110,   100,   101,   102,   103,
     107,   108,   105,   106,   104,   109,    40,    41,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    45,    96,    26,    49,    50,    22,    97,    21,    10,
      29,    23,    13,    71,    39,    72,    15,    27,    70,    51,
      21,   127,   113,    30,    17,    95,    32,    56,    57,   118,
      24,    69,   115,    33,    73,    35,    36,    55,    74,   169,
      75,   170,    76,   171,    77,   172,    78,    79,    80,   117,
     125,    37,    28,    81,   112,    34,    35,    36,    58,    59,
      60,    61,    44,    38,    62,    63,    64,    65,    66,    46,
     124,    67,    37,     9,   123,   193,   129,   194,     9,    20,
       2,   132,   158,   199,    38,   200,    34,    35,    36,   146,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   147,   148,    37,   128,   157,   180,   182,    22,   149,
     150,    42,    43,   176,    68,    38,    52,    53,   179,   181,
     178,    34,    35,    36,   163,   164,   188,    73,    35,    36,
       1,     2,     3,    54,   161,   165,   166,    55,    37,   177,
      94,    98,   198,   114,    37,   116,   174,    60,    61,   119,
      38,    62,    63,    64,    65,    66,    38,   120,    67,   121,
     122,   189,   190,    73,    35,    36,   130,    74,   131,    75,
     144,    76,   145,    77,    23,    78,    79,    80,    46,   151,
      37,   152,    81,    73,    35,    36,   154,    74,   159,    75,
     162,    76,    38,    77,   173,    78,    79,    80,   175,   184,
      37,   183,    81,   155,   186,   156,   185,   191,   192,   195,
     196,   197,    38,    58,    59,    60,    61,    99,   202,    62,
      63,    64,    65,    66,   201,   203,    67,    58,    59,    60,
      61,   167,   204,    62,    63,    64,    65,    66,   205,   206,
      67,    58,    59,    60,    61,   168,   208,    62,    63,    64,
      65,    66,   207,   209,    67,    58,    59,    60,    61,   187,
      18,    62,    63,    64,    65,    66,    19,     0,    67,    58,
      59,    60,    61,     0,   153,    62,    63,    64,    65,    66,
       0,     0,    67,    58,    59,    60,    61,   160,     0,    62,
      63,    64,    65,    66,   111,     0,    67,     0,     0,    58,
      59,    60,    61,     0,     0,    62,    63,    64,    65,    66,
       0,     0,    67,    62,    63,    64,    65,    66,     0,     0,
      67
};

static const yytype_int16 yycheck[] =
{
      16,    26,    51,     7,    29,     7,    20,    53,     7,     3,
       7,    25,     3,    21,    24,    23,     3,    21,    43,    21,
      19,    82,    71,    20,     0,    50,     3,    37,    38,    75,
      36,    41,    20,     4,     3,     4,     5,    25,     7,    21,
       9,    23,    11,    21,    13,    23,    15,    16,    17,    74,
      19,    20,    20,    22,    70,     3,     4,     5,    31,    32,
      33,    34,     3,    32,    37,    38,    39,    40,    41,    18,
      80,    44,    20,     0,    22,    21,    86,    23,     5,     7,
       8,    97,   131,    21,    32,    23,     3,     4,     5,   114,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   117,   118,    20,    21,   130,   167,   168,    20,   119,
     120,    22,    23,   162,    36,    32,    22,    23,   167,   168,
     166,     3,     4,     5,    22,    23,   175,     3,     4,     5,
       7,     8,     9,    26,   144,    22,    23,    25,    20,   164,
      23,    22,   191,     7,    20,     3,   156,    33,    34,    20,
      32,    37,    38,    39,    40,    41,    32,    20,    44,    20,
      20,   177,   178,     3,     4,     5,     7,     7,    21,     9,
      36,    11,    22,    13,    25,    15,    16,    17,    18,     6,
      20,     6,    22,     3,     4,     5,    22,     7,    22,     9,
      21,    11,    32,    13,    22,    15,    16,    17,    21,    28,
      20,    22,    22,    21,     3,    23,    22,    12,     3,    22,
      22,    22,    32,    31,    32,    33,    34,    21,     3,    37,
      38,    39,    40,    41,    22,    22,    44,    31,    32,    33,
      34,    21,    28,    37,    38,    39,    40,    41,    21,     3,
      44,    31,    32,    33,    34,    21,    21,    37,    38,    39,
      40,    41,    22,    22,    44,    31,    32,    33,    34,    21,
       5,    37,    38,    39,    40,    41,     5,    -1,    44,    31,
      32,    33,    34,    -1,    22,    37,    38,    39,    40,    41,
      -1,    -1,    44,    31,    32,    33,    34,   144,    -1,    37,
      38,    39,    40,    41,    26,    -1,    44,    -1,    -1,    31,
      32,    33,    34,    -1,    -1,    37,    38,    39,    40,    41,
      -1,    -1,    44,    37,    38,    39,    40,    41,    -1,    -1,
      44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    46,    47,    48,    52,    53,    83,
       3,    49,    54,     3,    55,     3,    50,     0,    48,    52,
       7,    53,    20,    25,    36,    51,     7,    21,    20,     7,
      20,    51,     3,     4,     3,     4,     5,    20,    32,    69,
      81,    82,    22,    23,     3,    49,    18,    56,    57,    49,
       7,    21,    22,    23,    26,    25,    69,    69,    31,    32,
      33,    34,    37,    38,    39,    40,    41,    44,    36,    69,
      49,    21,    23,     3,     7,     9,    11,    13,    15,    16,
      17,    22,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    83,    23,    49,    56,    50,    22,    21,
      71,    72,    73,    74,    79,    77,    78,    75,    76,    80,
      70,    26,    51,    56,     7,    20,     3,    49,    50,    20,
      20,    20,    20,    22,    69,    19,    58,    60,    21,    69,
       7,    21,    51,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    36,    22,    49,    51,    51,    69,
      69,     6,     6,    22,    22,    21,    23,    49,    56,    22,
      62,    69,    21,    22,    23,    22,    23,    21,    21,    21,
      23,    21,    23,    22,    69,    21,    56,    49,    50,    56,
      60,    56,    60,    22,    28,    22,     3,    21,    56,    51,
      51,    12,     3,    21,    23,    22,    22,    22,    56,    21,
      23,    22,     3,    22,    28,    21,     3,    22,    21,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    49,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    55,    56,    57,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    70,    69,    69,    69,    69,    71,
      69,    72,    69,    73,    69,    74,    69,    75,    69,    76,
      69,    77,    69,    78,    69,    79,    69,    80,    69,    69,
      69,    81,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     7,     4,     7,     4,
       1,     1,     1,     2,     0,     2,     1,     9,     6,     4,
       9,     7,     5,     2,     2,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       4,     7,     4,     1,     6,     4,     3,     2,     5,     5,
       5,     7,     5,     3,     2,     5,     7,     9,     5,     8,
      11,     1,     1,     1,     0,     4,     3,     5,     5,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       2,     1,     2,     6
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
        case 11:
#line 72 "par.y" /* yacc.c:1646  */
    {
	
	insert_hash(idname,"int",getCurrentScope(),yylineno,0,"NA");	

}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "par.y" /* yacc.c:1646  */
    {
	insert_hash(idname,"char",getCurrentScope(),yylineno,0,"NA");

}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 98 "par.y" /* yacc.c:1646  */
    {
	insert_hash(idname,"function",getCurrentScope(),yylineno,0,"int");
}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "par.y" /* yacc.c:1646  */
    {
	insert_hash(idname,"function",getCurrentScope(),yylineno,0,"void");
}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "par.y" /* yacc.c:1646  */
    {
	startNewScope();
	//printf("%d\n",getCurrentScope());
}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "par.y" /* yacc.c:1646  */
    {
	endCurrentScope();
	
}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "par.y" /* yacc.c:1646  */
    {
	int hashIndex = hashCode(idname);
	int flag=0;
	if(hashArray[hashIndex]!=NULL){
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,idname)==0 && strcmp(temp->type,"function")==0){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	}
	if(flag==0){
		printf("Undefined function: '%s' in line %d\n",idname,yylineno);
	}
	
}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 183 "par.y" /* yacc.c:1646  */
    {flg=0;}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 184 "par.y" /* yacc.c:1646  */
    {flg=1;}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 185 "par.y" /* yacc.c:1646  */
    {flg=2;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 186 "par.y" /* yacc.c:1646  */
    {getidtype(idname) ;  if(strcmp(typ,"int")!=0) {printf("LHS of assignment should be int in line %d",yylineno); return -1;} }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 190 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 197 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 210 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 230 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 237 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 250 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 257 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 270 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 290 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 297 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 310 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 317 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 330 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 337 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 350 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 357 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 370 "par.y" /* yacc.c:1646  */
    {
	if(flg==0){
	getidtype(idname); op1=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op1,typ);}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 377 "par.y" /* yacc.c:1646  */
    {
if(flg==0){
	getidtype(idname); op2=(char *)malloc(strlen(typ)*sizeof(char));  strcpy(op2,typ);
	if(strcmp(op1,op2)!=0){
		printf("Operand are of different types in line %d\n",yylineno);
		return -1;
	}
	}
	if(flg==2){
		printf("Character can't be operand\n in line %d",yylineno);
		return -1;
	}
}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 392 "par.y" /* yacc.c:1646  */
    {
	if(flg!=1){
		printf("Invalid operand in line %d",yylineno);
		return -1;
	}
}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 400 "par.y" /* yacc.c:1646  */
    {	
		if(hash_lookup_scope(idname)==0){
			printf("Undeclared Variable: '%s' in line %d\n",idname,yylineno);
			return -1;
		}
		
}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 409 "par.y" /* yacc.c:1646  */
    {	

	if(hash_lookup_scope(idname)==0){
		printf("Undeclared Variable: '%s' in line %d\n",idname,yylineno);
		return -1;
	}
	int hashIndex = hashCode(idname);
	int f=0;
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,idname)==0){
			int sc=temp->scope;
			if(isScopeValid(sc)==1){
				if(strcmp(temp->type,"array")!=0){
					f=1;
				}
				else gdim=temp->arrdim;
			}
				
		}
		temp=temp->next;
	}
	if(f==1){
		printf("Single variable id or function has subscript\n");
		return -1;
	}
	
return 0;

}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 442 "par.y" /* yacc.c:1646  */
    {
	dim = (yyvsp[-2]);
	if(dim<1){
		printf("Array size less than 1\n");
		return -1;
	}
	insert_hash(idname,"array",getCurrentScope(),yylineno,dim,"NA");
}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1964 "y.tab.c" /* yacc.c:1646  */
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
#line 458 "par.y" /* yacc.c:1906  */

#include"lex.yy.c"
#include<ctype.h>
int count=0;
int getCurrentScope () 
{
    return scopes[scopesLength - 1];
}

void startNewScope () 
{
   scopes[scopesLength++] = scopeCounter++;
}

void endCurrentScope () 
{
    scopesLength--;
}

int isScopeValid (int scope)
{
   int i=0;
   for (i = scopesLength-1; i>=0; i--)
        if (scopes[i] == scope)
            return 1;
   return 0;
}
int hash_lookup_scope(char * key)
{
int hashIndex = hashCode(key);
if(hashArray[hashIndex]!=NULL){
	struct DataItem * temp = hashArray[hashIndex];

	while(temp!=NULL){
		if(strcmp(temp->text,key)==0){
			int sc=temp->scope;
			if(isScopeValid(sc)==1)
				return 1;
		}
		temp=temp->next;
	}
	}
return 0;
}
void getidtype(char * key){
	
		if(hash_lookup_scope(key)==1){
			int hashIndex=hashCode(key);
			struct DataItem * temp = hashArray[hashIndex];
			while(temp!=NULL){
				if(strcmp(temp->text,key)==0){
					int sc=temp->scope;
					if(isScopeValid(sc)==1){
						
						typ=(char *)malloc(sizeof(char)*strlen(temp->type));
						strcpy(typ,temp->type);
						
					}
				}
				temp=temp->next;
			}
		}
		


}

int hashCode(char* key)             /* Returns unique index for a token */
{
   unsigned int i,hash=7;
   for(i=0;i<strlen(key);++i)
   {
       hash=hash*31+key[i];
   }
   return hash % SIZE;
}
void insert_hash(char* text,char* type,int scope, int lineno,int dim, char* retype) 
{
    int len,len2,len3;
    len= strlen(text);
    len2= strlen(type);
    len3 = strlen(retype);
    
   int hashIndex = hashCode(text);
   if(hashArray[hashIndex]!=NULL){
   		struct DataItem * temp = hashArray[hashIndex];
   		while(temp!=NULL){
		if(strcmp(temp->text,text)==0){
			int sc=temp->scope;
			if(sc==scope)
				{printf("Multiple declarations: '%s' in line %d\nVariable already declared in line %d\n\n",text,lineno,temp->lineno);
				return;
				}
		}
		temp=temp->next;
	}

   }
   		struct DataItem * new;
        new = (struct DataItem *)malloc(sizeof(struct DataItem));     
        new-> type = (char *)malloc(len2*sizeof(char));
        strcpy(new->type,type);
        new->lineno= lineno;
        new-> text = (char *)malloc(len*sizeof(char));
        strcpy(new->text,text);
        new->retype = (char*)malloc(len3*sizeof(char));
        strcpy(new->retype,retype);
        new->arrdim=dim;
        new->scope=scope;
       
        

        new->next= NULL;


   if(hashArray[hashIndex] != NULL) 
   {    //chaining

        struct DataItem * head = hashArray[hashIndex];
        new->next=head;
        hashArray[hashIndex]=new;
       
   }
   else{

   
   hashArray[hashIndex] = new;
}
}
void display_hash() 
{
   int i = 0;
  printf("Lexeme\t\tType\t\tScope\t\tLineno\t\tArrdim\t\tReturntype\n"); 
   for(i = 0; i<SIZE; i++) 
   {
      if(hashArray[i] != NULL){
        struct DataItem * head = hashArray[i];
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%s\n",head->text,head->type,head->scope,head->lineno,head->arrdim,head->retype);
        while(head->next!=NULL){
            head=head->next;
              printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%s\n",head->text,head->type,head->scope,head->lineno,head->arrdim,head->retype);
        }      
      }
   }
  
   printf("\n");
}


int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
   
   if(!yyparse())
        printf("\nParsing complete!\n");
    else
        printf("\nParsing failed!\n");
    printf("\n SYMBOL TABLE\n");
    display_hash();
    fclose(yyin);
    return 0;
}
         
void yyerror(char *s) {
    printf("Line %d : %s before '%s'\n", yylineno, s, yytext);
}


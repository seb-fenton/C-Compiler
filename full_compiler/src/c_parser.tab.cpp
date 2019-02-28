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

#line 67 "src/c_parser.tab.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y" /* yacc.c:355  */

  #include "ast.hpp"

  #include <cassert>

  extern BranchNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 111 "src/c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ASSIGNMENT_OP = 258,
    RIGHT_SHIFT_OP = 259,
    LEFT_SHIFT_OP = 260,
    INC_OP = 261,
    DEC_OP = 262,
    PTR_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    LE_OP = 266,
    GE_OP = 267,
    EQ_OP = 268,
    NE_OP = 269,
    INT_CONSTANT = 270,
    FLOAT_CONSTANT = 271,
    STRING_LITERAL = 272,
    T_VOID = 273,
    T_CHAR = 274,
    T_SHORT = 275,
    T_INT = 276,
    T_LONG = 277,
    T_FLOAT = 278,
    T_DOUBLE = 279,
    T_SIGNED = 280,
    T_UNSIGNED = 281,
    T_TYPEDEF = 282,
    T_EXTERN = 283,
    T_STATIC = 284,
    T_AUTO = 285,
    T_REGISTER = 286,
    T_CONST = 287,
    T_VOLATILE = 288,
    T_STRUCT = 289,
    T_UNION = 290,
    T_GOTO = 291,
    T_BREAK = 292,
    T_CONTINUE = 293,
    T_CASE = 294,
    T_DEFAULT = 295,
    T_SWITCH = 296,
    T_IF = 297,
    T_ELSE = 298,
    T_RETURN = 299,
    T_WHILE = 300,
    T_DO = 301,
    T_FOR = 302,
    T_SIZEOF = 303,
    TYPEDEF_NAME = 304,
    T_IDENTIFIER = 305,
    ENUMERATION_CONSTANT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/c_parser.y" /* yacc.c:355  */

  Node *node;
  BranchNode *bnode;
  ExpressionNode *enode;
  double number;
  std::string *string;

#line 183 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    72,    65,     2,
      58,    59,    70,    68,    55,    69,    75,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    52,
      67,    57,    66,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    63,    54,    73,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    56,    57,    61,    62,    63,    67,    71,
      72,    76,    77,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     101,   102,   103,   108,   109,   113,   114,   118,   119,   123,
     124,   128,   129,   130,   135,   136,   140,   141,   145,   146,
     150,   151,   152,   153,   154,   155,   156,   160,   161,   162,
     163,   167,   168,   169,   173,   174,   178,   182,   183,   187,
     188,   192,   193,   197,   198,   202,   203,   208,   209,   213,
     214,   218,   219,   220,   224,   225,   226,   227,   228,   232,
     233,   234,   238,   239,   240,   244,   245,   246,   247,   251,
     252,   256,   257,   258,   259,   260,   261,   265,   266,   267,
     268,   269,   270,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   287,   288,   289,   290,   294,   295,   296,
     300,   301,   305,   309,   310,   314,   315,   319,   320,   324,
     325,   329,   333,   334,   338,   339,   343,   344,   348,   349,
     353,   354,   361,   362,   363,   364,   365,   366,   370,   371,
     375,   376,   380,   381,   385,   386,   390,   391,   392,   396,
     397,   398,   399,   403,   404,   405,   409,   410,   411,   412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ASSIGNMENT_OP", "RIGHT_SHIFT_OP",
  "LEFT_SHIFT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "INT_CONSTANT", "FLOAT_CONSTANT",
  "STRING_LITERAL", "T_VOID", "T_CHAR", "T_SHORT", "T_INT", "T_LONG",
  "T_FLOAT", "T_DOUBLE", "T_SIGNED", "T_UNSIGNED", "T_TYPEDEF", "T_EXTERN",
  "T_STATIC", "T_AUTO", "T_REGISTER", "T_CONST", "T_VOLATILE", "T_STRUCT",
  "T_UNION", "T_GOTO", "T_BREAK", "T_CONTINUE", "T_CASE", "T_DEFAULT",
  "T_SWITCH", "T_IF", "T_ELSE", "T_RETURN", "T_WHILE", "T_DO", "T_FOR",
  "T_SIZEOF", "TYPEDEF_NAME", "T_IDENTIFIER", "ENUMERATION_CONSTANT",
  "';'", "'{'", "'}'", "','", "':'", "'='", "'('", "')'", "'['", "']'",
  "'?'", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'~'", "'!'", "'.'", "$accept", "root", "translation_unit",
  "external_declaration", "typedef_declaration", "declaration",
  "declaration_specifier_list", "declaration_specifiers",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "init_declarator_list",
  "init_declarator", "declarator", "direct_declarator", "initialiser_list",
  "initialiser", "assignment_operator", "constant_expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "constant", "expression", "designation",
  "designator_list", "designator", "function_definition",
  "declaration_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "pointer",
  "argument_expression_list", "statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "labeled_statement",
  "jump_statement", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    59,   123,   125,    44,    58,    61,    40,    41,
      91,    93,    63,   124,    94,    38,    62,    60,    43,    45,
      42,    47,    37,   126,    33,    46
};
# endif

#define YYPACT_NINF -233

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-233)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1171,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    1193,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
      61,  1171,  -233,  -233,  -233,   893,  -233,  -233,    49,  -233,
     936,  -233,  -233,  -233,  -233,   105,   -61,  -233,   125,  -233,
    1021,   -27,    -2,    -4,  1193,    14,    79,  -233,  -233,   105,
     318,   536,  -233,   893,  1135,  -233,   979,   563,   -27,  1193,
     850,  1061,  -233,  -233,  -233,  -233,    86,   728,   728,  -233,
    -233,  -233,    93,   108,   766,   101,   120,   130,   601,   132,
     476,   151,   793,   129,  -233,  -233,  -233,   438,  -233,  -233,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,     6,   204,  -233,
     155,   182,    41,    40,    77,    36,   163,  -233,    44,   766,
      33,  -233,  -233,   127,  -233,  -233,   378,  -233,  -233,  -233,
    -233,  -233,  -233,  -233,   253,  -233,  -233,  -233,  -233,  -233,
    -233,   105,   156,   193,  -233,   -17,  -233,   188,  1098,  -233,
     766,   137,  -233,   194,  -233,  -233,   438,  -233,  -233,  -233,
    -233,   195,  -233,  -233,   476,   766,   766,  -233,   145,   766,
     209,   628,   438,  -233,   476,   196,     5,   766,   766,   766,
     766,   766,   766,   766,   766,   766,   766,   766,   766,   766,
     766,   766,   766,   766,   766,   766,  -233,  -233,   766,  -233,
    -233,  -233,   206,   641,   766,   207,  -233,   766,  -233,  -233,
     766,   208,   150,  -233,   536,    99,  -233,  -233,  -233,  1193,
     211,  -233,  -233,  -233,  -233,  -233,     9,   766,   203,   476,
    -233,   103,   109,  -233,   110,   205,   628,   212,  -233,   688,
    -233,    -5,    15,    76,    15,    35,   182,    41,    40,    40,
      77,    77,    77,    77,    36,    36,   163,   163,  -233,  -233,
    -233,  -233,  -233,  -233,  -233,   111,   -26,  -233,  -233,   213,
    -233,  -233,   133,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
     214,  -233,   476,   476,   476,   766,   701,   214,   253,  -233,
     766,   766,  -233,  -233,  -233,  -233,  -233,   536,  -233,   221,
    -233,   112,   476,   117,   167,  -233,  -233,  -233,   476,   220,
    -233,   476,  -233,   225,  -233,  -233,  -233,  -233
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    33,    34,    29,
       0,     2,     3,     7,     6,     0,    11,    28,     0,     5,
       0,     1,     4,    50,     9,     0,   148,    12,     0,    44,
      47,    49,     0,    32,     0,     0,     0,   149,    10,     0,
       0,     0,   139,     0,     0,   138,     0,     0,    48,     0,
       0,     0,    35,     8,    51,    45,    47,     0,     0,   127,
     128,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   129,   164,   158,     0,   107,   109,
     110,   108,   111,   112,   162,   130,    67,    69,    71,    73,
      75,    77,    79,    81,    84,    89,    92,    95,    99,     0,
     101,   113,   124,     0,   163,   153,     0,   160,   154,   155,
     156,   152,   157,   123,     0,    46,    63,   140,   137,   146,
      56,   145,     0,   141,   142,     0,    52,     0,     0,    37,
       0,     0,    39,    43,    30,    36,     0,   102,   103,   177,
     176,     0,    66,    99,     0,     0,     0,   178,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    64,     0,   104,
     119,   120,     0,     0,     0,     0,   165,     0,   159,   161,
       0,     0,     0,    58,     0,     0,   133,   144,    54,     0,
       0,    55,    53,    31,    41,    38,     0,     0,     0,     0,
     175,     0,     0,   179,     0,     0,     0,     0,   173,     0,
     126,     0,    72,     0,    76,    74,    78,    80,    82,    83,
      87,    88,    85,    86,    91,    90,    93,    94,    96,    97,
      98,    68,   118,   115,   150,     0,     0,   117,   131,     0,
     136,    61,     0,    57,   132,   134,   143,   147,    40,    42,
       0,   174,     0,     0,     0,     0,     0,   106,     0,   100,
       0,     0,   116,   114,   135,    62,    60,     0,   168,   167,
     169,     0,     0,     0,     0,    70,   151,    59,     0,     0,
     171,     0,   121,     0,   166,   170,   172,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,  -233,  -233,   244,  -233,   -33,    13,   -10,  -233,  -233,
     218,   -53,  -233,    50,  -233,   231,     2,   239,     4,   -50,
    -233,  -137,   -51,   -70,   -75,   -57,   114,  -233,   115,   116,
      52,    68,    59,    47,   -95,   -56,  -233,  -233,  -233,  -233,
     -59,  -232,  -233,    82,  -233,  -233,  -233,  -233,    80,  -233,
     255,  -233,   -78,   -18,  -233,   176,  -151,  -233,  -233,  -233,
    -233
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    53,    26,    27,    28,
      61,    62,   141,   142,    38,    39,    66,    41,   202,   203,
     188,   151,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   204,   205,   206,    29,    54,   132,   133,   134,   135,
      42,   255,   114,   115,   116,   117,   118,   119,   120,   121,
     122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,   125,   160,   214,   152,   167,   137,    52,   145,    36,
     226,   147,   148,    25,   189,    37,   167,    94,   153,   158,
      37,   127,    55,    30,   170,   -71,   163,    40,   166,   197,
     287,    56,    45,    57,    25,   283,   128,    46,   210,   190,
     191,   192,   211,    37,   -73,   -73,   131,   186,    33,    59,
      37,   175,   176,   153,   173,   174,    35,    60,   169,    33,
     197,    31,   143,   259,   230,   140,    63,    35,   168,   169,
     152,   287,    60,   126,    60,   276,   220,   165,   -71,    36,
     269,   179,   180,    94,   153,   145,   228,   166,   248,   249,
     250,   193,   231,   194,   231,   231,   221,   222,   -73,    43,
     224,   187,    44,   166,   181,   182,   177,   178,   195,   233,
     232,   153,   234,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     152,   197,   280,   207,   279,   256,   218,   251,    64,    67,
      68,   271,   254,    51,   153,   149,   258,   152,    69,    70,
      71,    60,   227,   126,   263,    33,   264,   154,   197,   200,
     150,   153,   272,    35,   197,   197,   281,   197,   273,   274,
     282,   299,   197,   153,   201,    36,   301,    48,   155,   196,
      49,    82,   197,   123,    84,   164,   124,   285,   156,   215,
     159,    87,   216,   200,   288,   289,   290,   223,    88,   131,
     197,    89,    90,    91,   261,   262,    92,    93,   201,   161,
     295,   126,   286,   170,   300,   208,   291,   293,   143,   171,
     304,   302,   303,   306,   153,   238,   239,   126,   246,   247,
     296,    67,    68,   183,   184,   185,   126,   297,   244,   245,
      69,    70,    71,   240,   241,   242,   243,   172,   209,   212,
     217,   219,   126,   286,   225,   229,   252,   257,   260,    67,
      68,   267,   270,   275,   298,    32,   268,   278,    69,    70,
      71,   277,   305,    82,   284,   123,    84,   138,   124,   307,
      65,    58,   294,    87,   235,   200,   236,   265,   237,   266,
      88,    47,   199,    89,    90,    91,     0,     0,    92,    93,
     201,    82,     0,   123,    84,     0,   124,     0,     0,     0,
       0,    87,     0,   200,     0,     0,     0,     0,    88,     0,
       0,    89,    90,    91,    67,    68,    92,    93,   201,     0,
       0,     0,     0,    69,    70,    71,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    11,    12,    13,    14,
      15,    16,    17,    18,     0,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    19,    83,    84,
      85,    50,    86,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    88,    67,    68,    89,    90,    91,     0,
       0,    92,    93,    69,    70,    71,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    11,    12,    13,    14,
      15,    16,    17,    18,     0,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    19,    83,    84,
      85,    50,   198,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    88,    67,    68,    89,    90,    91,     0,
       0,    92,    93,    69,    70,    71,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    82,    19,   123,    84,
       0,    69,    70,    71,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    88,     0,     0,    89,    90,    91,     0,
       0,    92,    93,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    50,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    88,    67,    68,    89,    90,    91,     0,     0,    92,
      93,    69,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,     0,     0,     0,    82,     0,   123,    84,     0,   124,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    88,     0,     0,    89,    90,    91,    67,    68,    92,
      93,    82,     0,   123,    84,     0,    69,    70,    71,     0,
       0,    87,     0,     0,   136,     0,     0,     0,    88,     0,
       0,    89,    90,    91,    67,    68,    92,    93,     0,     0,
       0,     0,     0,    69,    70,    71,     0,    67,    68,    82,
       0,   123,    84,   157,     0,     0,    69,    70,    71,    87,
       0,     0,     0,     0,     0,     0,    88,     0,     0,    89,
      90,    91,     0,     0,    92,    93,    82,     0,   123,    84,
      85,     0,     0,     0,     0,     0,    87,     0,     0,    82,
       0,   123,    84,    88,    67,    68,    89,    90,    91,    87,
     253,    92,    93,    69,    70,    71,    88,    67,    68,    89,
      90,    91,     0,     0,    92,    93,    69,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    82,     0,   123,    84,
       0,   278,     0,    69,    70,    71,    87,     0,     0,    82,
       0,   123,    84,    88,     0,     0,    89,    90,    91,    87,
     292,    92,    93,     0,     0,     0,    88,     0,     0,    89,
      90,    91,    67,    68,    92,    93,    82,     0,   123,    84,
       0,    69,    70,    71,     0,     0,   146,     0,     0,     0,
       0,     0,     0,    88,     0,     0,    89,    90,    91,    67,
      68,    92,    93,     0,     0,     0,     0,     0,    69,    70,
      71,     0,     0,     0,    82,     0,   123,    84,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    88,     0,     0,    89,    90,    91,     0,     0,    92,
      93,    82,     0,   123,    84,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,    88,     0,
       0,    89,    90,    91,     0,     0,    92,    93,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      33,     0,   139,     0,     0,     0,   140,     0,    35,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      36,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    33,     0,    34,     0,     0,     0,     0,
       0,    35,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    36,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    33,     0,     0,     0,
       0,     0,     0,     0,    35,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    36,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,    50,     0,     0,     0,    51,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,   144,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,   213,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    50,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      19,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      51,    51,    80,   140,    74,    10,    57,    40,    61,    70,
     161,    67,    68,     0,   109,    25,    10,    50,    74,    78,
      30,    54,    40,    10,     9,    10,    82,    25,    87,    55,
     262,    58,    30,    60,    21,    61,    54,    35,    55,     6,
       7,     8,    59,    53,     9,    10,    56,     3,    50,    53,
      60,    11,    12,   109,    13,    14,    58,    44,    63,    50,
      55,     0,    60,   200,    59,    56,    52,    58,    62,    63,
     140,   303,    59,   124,    61,   226,   154,    87,    63,    70,
     217,     4,     5,   116,   140,   138,   164,   146,   183,   184,
     185,    58,   167,    60,   169,   170,   155,   156,    63,    50,
     159,    57,    53,   162,    68,    69,    66,    67,    75,   168,
     167,   167,   169,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     200,    55,    56,   131,   229,   194,   146,   188,    59,     6,
       7,   219,   193,    57,   200,    52,   197,   217,    15,    16,
      17,   138,   162,   204,   204,    50,    57,    56,    55,    60,
      52,   217,    59,    58,    55,    55,    55,    55,    59,    59,
      59,    59,    55,   229,    75,    70,    59,    52,    58,    52,
      55,    48,    55,    50,    51,    56,    53,    54,    58,    52,
      58,    58,    55,    60,   272,   273,   274,    52,    65,   209,
      55,    68,    69,    70,    54,    55,    73,    74,    75,    58,
     280,   262,   262,     9,   292,    59,   275,   276,   216,    64,
     298,    54,    55,   301,   280,   173,   174,   278,   181,   182,
     281,     6,     7,    70,    71,    72,   287,   287,   179,   180,
      15,    16,    17,   175,   176,   177,   178,    65,    55,    61,
      56,    56,   303,   303,    45,    59,    50,    50,    50,     6,
       7,    50,    59,    58,    43,    21,   216,    53,    15,    16,
      17,    59,    52,    48,    61,    50,    51,    59,    53,    54,
      49,    42,   278,    58,   170,    60,   171,   205,   172,   209,
      65,    36,   116,    68,    69,    70,    -1,    -1,    73,    74,
      75,    48,    -1,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,     6,     7,    73,    74,    75,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,     6,     7,    68,    69,    70,    -1,
      -1,    73,    74,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,     6,     7,    68,    69,    70,    -1,
      -1,    73,    74,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    -1,    48,    49,    50,    51,
      -1,    15,    16,    17,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    69,    70,    -1,
      -1,    73,    74,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    65,     6,     7,    68,    69,    70,    -1,    -1,    73,
      74,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    69,    70,     6,     7,    73,
      74,    48,    -1,    50,    51,    -1,    15,    16,    17,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,     6,     7,    73,    74,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,     6,     7,    48,
      -1,    50,    51,    52,    -1,    -1,    15,    16,    17,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,    -1,    -1,    73,    74,    48,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    48,
      -1,    50,    51,    65,     6,     7,    68,    69,    70,    58,
      59,    73,    74,    15,    16,    17,    65,     6,     7,    68,
      69,    70,    -1,    -1,    73,    74,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    48,    -1,    50,    51,
      -1,    53,    -1,    15,    16,    17,    58,    -1,    -1,    48,
      -1,    50,    51,    65,    -1,    -1,    68,    69,    70,    58,
      59,    73,    74,    -1,    -1,    -1,    65,    -1,    -1,    68,
      69,    70,     6,     7,    73,    74,    48,    -1,    50,    51,
      -1,    15,    16,    17,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    69,    70,     6,
       7,    73,    74,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      74,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    -1,    -1,    73,    74,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      70,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    70,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    70,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    54,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    54,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      49,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    49,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   120,
      82,     0,    79,    50,    52,    58,    70,    83,    90,    91,
      92,    93,   126,    50,    53,    92,    92,   126,    52,    55,
      53,    57,    81,    82,   121,   129,    58,    60,    93,    53,
      82,    86,    87,    52,    59,    91,    92,     6,     7,    15,
      16,    17,    37,    38,    39,    40,    41,    42,    44,    45,
      46,    47,    48,    50,    51,    52,    54,    58,    65,    68,
      69,    70,    73,    74,    81,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    50,    53,    95,    98,    81,   129,    50,
      59,    83,   122,   123,   124,   125,    61,    98,    86,    52,
      56,    88,    89,    92,    54,    87,    58,   111,   111,    52,
      52,    97,    99,   111,    56,    58,    58,    52,   116,    58,
     128,    58,    58,   111,    56,    83,   116,    10,    62,    63,
       9,    64,    65,    13,    14,    11,    12,    66,    67,     4,
       5,    68,    69,    70,    71,    72,     3,    57,    96,   110,
       6,     7,     8,    58,    60,    75,    52,    55,    54,   131,
      60,    75,    94,    95,   117,   118,   119,    92,    59,    55,
      55,    59,    61,    54,    97,    52,    55,    56,    83,    56,
     128,   116,   116,    52,   116,    45,   132,    83,   128,    59,
      59,   100,   101,   116,   101,   102,   104,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,    98,    50,    59,    98,   127,   116,    50,    98,    97,
      50,    54,    55,    95,    57,   119,   124,    50,    89,    97,
      59,   128,    59,    59,    59,    58,   132,    59,    53,   110,
      56,    55,    59,    61,    61,    54,    95,   117,   128,   128,
     128,   116,    59,   116,    94,    99,    98,    95,    43,    59,
     128,    59,    54,    55,   128,    52,   128,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   115,   115,   115,
     116,   116,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   134,
     134,   134,   134,   135,   135,   135,   136,   136,   136,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     4,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       3,     2,     3,     1,     1,     3,     3,     1,     2,     1,
       1,     3,     3,     4,     4,     4,     3,     2,     1,     4,
       3,     3,     4,     1,     1,     1,     1,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     2,
       2,     6,     7,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     2,     1,     2,     3,     2,     4,     3,     1,
       2,     1,     1,     3,     2,     1,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     2,     1,     1,     1,     2,     7,     5,     5,     5,
       7,     6,     7,     3,     4,     3,     2,     2,     2,     3
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
        case 2:
#line 53 "src/c_parser.y" /* yacc.c:1646  */
    {/*$1 = new translation_unit();*/ g_root = (yyvsp[0].bnode);}
#line 1709 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.bnode) = new translation_unit((yyvsp[0].node));}
#line 1715 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1721 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1727 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1733 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration((yyvsp[-1].bnode));}
#line 1739 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration((yyvsp[-2].bnode),(yyvsp[-1].bnode));}
#line 1745 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.bnode) = new declaration_specifier_list((yyvsp[0].node));}
#line 1751 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 77 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1757 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 81 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("void");}
#line 1763 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 82 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("char");}
#line 1769 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 83 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("short");}
#line 1775 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 84 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("int"); }
#line 1781 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 85 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("long");}
#line 1787 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 86 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("float");}
#line 1793 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 87 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("double");}
#line 1799 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 88 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("signed");}
#line 1805 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 89 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declaration_specifiers("unsigned");}
#line 1811 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 135 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.bnode) = new init_declarator_list((yyvsp[0].node));}
#line 1817 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 136 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1823 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 140 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new init_declarator((yyvsp[-2].node), (yyvsp[0].node));}
#line 1829 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 141 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new init_declarator((yyvsp[0].node));}
#line 1835 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 145 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new declarator((yyvsp[0].node), (yyvsp[-1].node));}
#line 1841 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 146 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1847 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 150 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new direct_declarator(*((yyvsp[0].string)));}
#line 1853 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 151 "src/c_parser.y" /* yacc.c:1646  */
    { }
#line 1859 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 169 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.node) = new initialiser((yyvsp[0].enode));}
#line 1865 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 173 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.string) = new std::string("="); }
#line 1871 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 174 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1877 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 182 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1883 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 187 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1889 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 188 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new conditional_expression((yyvsp[-4].enode),(yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1895 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 192 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1901 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 193 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new LogicalOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1907 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 197 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1913 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 198 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new LogicalAndOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1919 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 202 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1925 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 203 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new InclusiveOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1931 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 208 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1937 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 209 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new ExclusiveOrOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 1943 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 213 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1949 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 214 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new AndOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 1955 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 218 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1961 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 219 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new EqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1967 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 220 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new NotEqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 1973 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 224 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 1979 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 225 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new GreaterThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 1985 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 226 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new LessThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 1991 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 227 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new LessThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 1997 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 228 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new GreaterThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2003 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2009 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 233 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new LeftShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2015 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 234 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new RightShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2021 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 238 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2027 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new AddOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2033 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 240 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new SubOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2039 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 244 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2045 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 245 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new MultOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2051 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 246 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new DivOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2057 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 247 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new ModulusOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2063 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 251 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2069 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 256 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2075 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 274 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2081 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 287 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new primary_expression(*((yyvsp[0].string)));}
#line 2087 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 288 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.enode) = new constantNode((yyvsp[0].number));}
#line 2093 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 294 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 2099 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 295 "src/c_parser.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 2105 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2109 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 415 "src/c_parser.y" /* yacc.c:1906  */


BranchNode *g_root;

Node *parseAST()
{
  	g_root=0;
  	yyparse();
  	return g_root;
}

/* A Bison parser, made by GNU Bison 3.3.  */

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
#define YYBISON_VERSION "3.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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
#line 1 "src/c_parser.y" /* yacc.c:352  */

  #include "ast.hpp"

  #include <cassert>

  extern BranchNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 116 "src/c_parser.tab.cpp" /* yacc.c:352  */

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
    T_ENUM = 304,
    TYPEDEF_NAME = 305,
    T_IDENTIFIER = 306,
    ENUMERATION_CONSTANT = 307,
    NOELSE = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/c_parser.y" /* yacc.c:352  */

  Node *node;
  BranchNode *bnode;
  ExpressionNode *enode;
  double number;
  std::string *string;
  identifier_list *idlist;
  Pointer *ptrNode;

#line 192 "src/c_parser.tab.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */



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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
       2,     2,     2,    76,     2,     2,     2,    74,    67,     2,
      60,    61,    72,    70,    57,    71,    77,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    54,
      69,    59,    68,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    65,    56,    75,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    67,    68,    72,    73,    74,    78,    82,
      83,    87,    88,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   106,   107,   108,   112,   113,   117,
     118,   122,   123,   127,   128,   129,   134,   135,   139,   140,
     144,   145,   149,   150,   151,   152,   153,   154,   155,   159,
     160,   164,   165,   166,   170,   171,   175,   179,   180,   184,
     185,   189,   190,   194,   195,   199,   200,   205,   206,   210,
     211,   215,   216,   217,   221,   222,   223,   224,   225,   229,
     230,   231,   235,   236,   237,   241,   242,   243,   244,   248,
     249,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   267,   268,   269,   270,   271,   272,   273,   274,
     278,   279,   280,   281,   285,   286,   287,   291,   295,   296,
     297,   298,   302,   303,   307,   311,   312,   316,   317,   318,
     322,   323,   327,   328,   332,   333,   337,   338,   342,   343,
     344,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     362,   363,   364,   365,   366,   367,   371,   372,   376,   377,
     381,   382,   386,   387,   391,   392,   393,   397,   398,   399,
     400,   404,   405,   406,   410,   411,   412,   413
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
  "T_SIZEOF", "T_ENUM", "TYPEDEF_NAME", "T_IDENTIFIER",
  "ENUMERATION_CONSTANT", "NOELSE", "';'", "'{'", "'}'", "','", "':'",
  "'='", "'('", "')'", "'['", "']'", "'?'", "'|'", "'^'", "'&'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept",
  "root", "translation_unit", "external_declaration",
  "typedef_declaration", "declaration", "declaration_specifier_list",
  "declaration_specifiers", "struct_or_union_specifier",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "init_declarator_list",
  "init_declarator", "declarator", "direct_declarator", "initialiser_list",
  "initialiser", "assignment_operator", "constant_expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "constant", "expression", "function_definition", "declaration_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "pointer", "argument_expression_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "labeled_statement", "jump_statement", YY_NULLPTR
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
     305,   306,   307,   308,    59,   123,   125,    44,    58,    61,
      40,    41,    91,    93,    63,   124,    94,    38,    62,    60,
      43,    45,    42,    47,    37,   126,    33,    46
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     946,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    1208,     4,  -187,  -187,    -2,   -62,    29,   946,  -187,  -187,
    -187,   965,  -187,  -187,  1191,    27,  -187,    21,  1071,     7,
    1208,   -20,  -187,  -187,  -187,  -187,  -187,     6,  -187,   820,
     253,  -187,   965,  1191,  -187,  1134,   479,    27,    -6,  1208,
     873,   386,  -187,  -187,  -187,    -2,   541,  1191,  -187,   739,
     739,  -187,  -187,  -187,    28,    53,   801,    15,    16,    65,
     555,    77,   377,    81,   814,    55,  -187,  -187,  -187,   439,
     801,   801,   801,   801,   801,   801,  -187,  -187,  -187,    11,
     139,    87,    90,   110,    10,    33,   140,    99,    60,  -187,
       9,    58,  -187,  -187,   125,  -187,  -187,   315,  -187,  -187,
    -187,  -187,  -187,  -187,   122,  -187,  -187,  -187,  -187,  1008,
     121,   131,  -187,    22,  -187,  -187,   126,  -187,  -187,  -187,
    1152,  -187,   801,    70,  -187,   132,  -187,  -187,  -187,   541,
    -187,  -187,  -187,   801,  -187,  -187,  -187,  -187,   133,   377,
     801,   801,  -187,   138,   801,   149,   617,   439,  -187,   377,
    1089,   134,   135,  -187,  -187,  -187,  -187,  -187,  -187,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   801,  -187,  -187,
     801,  -187,  -187,   151,   630,   801,   152,  -187,  -187,  -187,
     891,   647,  -187,   -25,  -187,    89,  -187,  1208,   153,  -187,
    -187,  -187,  -187,  -187,    26,   801,   116,  -187,   377,  -187,
     144,   145,  -187,   146,   150,   617,   148,  -187,  1026,   106,
    -187,  -187,   801,   139,   142,    87,    90,   110,    10,    33,
      33,   140,   140,   140,   140,    99,    99,    60,    60,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,    47,   157,  -187,  -187,
     163,   165,  -187,   164,    89,   560,   709,  -187,  -187,  -187,
    -187,  -187,   465,  -187,   377,   377,   377,   801,   722,  -187,
    -187,   801,   801,  -187,  -187,  -187,  -187,  -187,  -187,   169,
    -187,   168,  -187,  -187,  -187,   170,  -187,   180,   377,   182,
    -187,  -187,  -187,  -187,   377,   158,  -187,   377,  -187,  -187,
    -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,    23,    42,     0,   132,     0,     2,     3,     7,
       6,     0,    11,    22,     0,    41,     5,     0,     0,    26,
       0,     0,   133,     1,     4,     9,    12,     0,    36,    39,
       0,   122,     0,     0,   121,     0,     0,    40,     0,     0,
       0,     0,    27,    43,    10,     0,     0,     0,   119,     0,
       0,   114,   115,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   116,   162,   156,     0,
       0,     0,     0,     0,     0,     0,   160,   117,    57,    59,
      61,    63,    65,    67,    69,    71,    74,    79,    82,    85,
      89,    91,   102,   111,     0,   161,   151,     0,   158,   152,
     153,   154,   150,   155,    39,   123,   120,   130,    48,   129,
       0,   124,   125,     0,   110,    44,     0,    56,    89,     8,
       0,    29,     0,     0,    31,    35,    24,    28,    37,     0,
      38,    53,   118,     0,    92,    93,   175,   174,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,   100,     0,
     136,     0,     0,    94,    96,    97,    95,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    54,
       0,   108,   109,     0,     0,     0,     0,   163,   157,   159,
       0,     0,   127,   138,   128,   139,    46,     0,     0,    47,
      45,    25,    33,    30,     0,     0,     0,    49,     0,   173,
       0,     0,   177,     0,     0,     0,     0,   171,     0,   138,
     137,   113,     0,    62,     0,    64,    66,    68,    70,    72,
      73,    77,    78,    75,    76,    81,    80,    83,    84,    86,
      87,    88,    58,   107,   104,   134,     0,     0,   106,   146,
       0,     0,   142,     0,   140,     0,     0,   126,   131,    32,
      34,    51,     0,   172,     0,     0,     0,     0,     0,   101,
      90,     0,     0,   105,   103,   147,   141,   143,   148,     0,
     144,     0,    52,    50,   166,   165,   167,     0,     0,     0,
      60,   135,   149,   145,     0,     0,   169,     0,   164,   168,
     170
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,   194,  -187,    14,     1,   -14,  -187,   197,
     -24,  -187,    37,  -187,   159,    19,   -23,  -187,  -133,  -187,
     -44,   -54,   -41,  -187,    78,    82,    80,    83,    88,     0,
     -15,     2,     3,    12,   -40,  -187,  -187,  -187,   -28,  -187,
     215,   -42,  -187,    48,  -187,    -7,  -187,   100,  -104,  -186,
     -59,   104,  -187,   154,  -147,  -187,  -187,  -187,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    42,    22,    23,    51,
      52,   133,   134,    37,    38,    24,    25,   216,   140,   190,
     126,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   128,   101,   102,   103,   104,    26,
      43,   260,   121,   122,   123,    27,   256,   162,   261,   205,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     100,    21,   141,   120,    47,   127,   217,    36,    32,   225,
      15,    28,   188,   155,    36,   204,   100,   264,    21,   144,
     145,   169,   148,   175,   176,   127,    13,   137,    36,    33,
     100,    50,   100,    31,   158,   200,    36,   201,    41,   100,
      39,    53,   153,   264,   177,   178,   119,    48,   129,    13,
      50,   161,    50,    41,    86,    29,   230,   115,    14,    30,
      54,   114,    49,    55,   191,   192,   193,   100,   189,   135,
      15,   115,    13,   149,   114,   170,   150,    13,   278,   208,
     160,    14,   146,   209,   132,   141,    14,    45,   212,    46,
     219,   127,   163,   164,   165,   166,   167,   168,    15,   100,
     227,   179,   180,   100,   282,    36,   137,   147,   283,   100,
     100,   100,   203,   159,   100,   161,   100,   100,   194,   100,
     195,    86,   220,   221,   213,   151,   223,   214,    44,   161,
     100,    50,   185,   186,   187,   196,   252,   154,   202,   293,
     255,   156,   234,    58,   181,   182,    36,   116,   171,   265,
     100,   266,   172,   229,   100,   100,   173,   263,   160,   273,
     127,   142,   241,   242,   243,   244,   228,   257,   201,   183,
     184,   270,   271,   272,   127,   239,   240,   174,   100,   197,
      47,    56,   206,   245,   246,   100,   247,   248,   207,   210,
     215,   218,   222,   203,   224,   231,   232,   249,   250,   251,
     281,   119,   253,   258,   268,   274,   275,   276,   119,   279,
     277,    34,   309,   304,   138,   294,   295,   296,   141,    31,
     284,   229,   291,   289,   285,   127,   286,   287,   301,   119,
     302,   303,   100,   135,   100,   100,   100,   100,   100,   306,
     300,   305,   100,   307,   280,   308,   130,   233,   310,   297,
     299,   269,   236,   235,    57,   267,   237,   226,   100,    59,
      60,   199,   238,     0,   100,     0,   119,   100,    61,    62,
      63,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,     0,    12,    75,    76,     0,    77,    40,    78,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
      80,    59,    60,    81,    82,    83,     0,     0,    84,    85,
      61,    62,    63,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,     0,    12,    75,    76,     0,    77,
      40,   198,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,    80,    59,    60,    81,    82,    83,     0,     0,
      84,    85,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    64,    65,    66,    67,    68,    69,
      11,    70,    71,    72,    73,    74,     0,     0,    75,    76,
       0,    77,    40,     0,     0,     0,    12,    79,     0,     0,
       0,     0,   136,     0,    80,    59,    60,    81,    82,    83,
       0,     0,    84,    85,    61,    62,    63,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    59,    60,    11,     0,     0,     0,     0,     0,     0,
      61,    62,    63,     0,     0,    59,    60,    74,     0,    12,
     124,    76,     0,     0,    61,    62,    63,     0,     0,    79,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
      82,    83,     0,    74,    84,    85,   124,    76,     0,     0,
     139,   292,     0,     0,     0,    79,     0,    74,     0,     0,
     124,    76,    80,     0,     0,    81,    82,    83,     0,    79,
      84,    85,   125,     0,     0,     0,    80,    59,    60,    81,
      82,    83,     0,     0,    84,    85,    61,    62,    63,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    74,
       0,     0,   124,    76,    11,     0,   139,     0,     0,     0,
       0,    79,     0,    74,     0,     0,   124,    76,    80,   152,
      12,    81,    82,    83,     0,    79,    84,    85,     0,     0,
       0,   288,    80,    59,    60,    81,    82,    83,     0,     0,
      84,    85,    61,    62,    63,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    63,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    74,     0,     0,   124,    76,
       0,    77,     0,     0,     0,     0,     0,    79,    74,     0,
       0,   124,    76,     0,    80,     0,     0,    81,    82,    83,
      79,   254,    84,    85,     0,    74,     0,    80,   124,    76,
      81,    82,    83,     0,     0,    84,    85,    79,     0,     0,
     262,     0,     0,     0,    80,    59,    60,    81,    82,    83,
       0,     0,    84,    85,    61,    62,    63,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    74,     0,     0,
     124,    76,     0,     0,     0,     0,     0,     0,     0,    79,
      74,     0,   290,   124,    76,     0,    80,     0,     0,    81,
      82,    83,    79,   298,    84,    85,     0,    74,     0,    80,
     124,    76,    81,    82,    83,     0,     0,    84,    85,   143,
       0,     0,     0,     0,     0,     0,    80,    59,    60,    81,
      82,    83,     0,     0,    84,    85,    61,    62,    63,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    74,
       0,     0,   124,    76,    11,     0,     0,     0,     0,     0,
       0,    79,    74,     0,     0,   124,    76,     0,    80,     0,
      12,    81,    82,    83,   157,    40,    84,    85,     0,    56,
       0,    80,     0,     0,    81,    82,    83,     0,     0,    84,
      85,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,    12,    13,    11,     0,   131,     0,     0,
       0,   132,     0,    14,     0,     0,     0,     0,     0,     0,
       0,    12,    13,     0,     0,    15,     0,     0,     0,     0,
       0,   200,   259,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,     0,    12,    13,     0,    11,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,    15,    35,
       0,     0,     0,     0,     0,    14,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    15,     0,     0,
       0,     0,    11,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    12,    13,
      11,     0,     0,     0,     0,     0,     0,     0,   200,     0,
     201,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      15,     0,     0,     0,     0,     0,   228,   259,   201,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    15,     0,
       0,     0,     0,     0,     0,    11,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    12,    13,    11,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,    15,     0,     0,     0,     0,     0,   228,
       0,   201,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    15,     0,     0,     0,     0,     0,     0,    11,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    12,   117,    11,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,   211,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    11,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    12,    11,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      40,     0,    56,    45,    27,    46,   139,    21,    15,   156,
      72,    10,     3,    72,    28,   119,    56,   203,    17,    59,
      60,    10,    66,    13,    14,    66,    51,    51,    42,     0,
      70,    30,    72,    14,    74,    60,    50,    62,    24,    79,
      21,    61,    70,   229,    11,    12,    45,    28,    54,    51,
      49,    79,    51,    39,    40,    51,   160,    43,    60,    55,
      54,    42,    55,    57,     6,     7,     8,   107,    59,    50,
      72,    57,    51,    58,    55,    64,    60,    51,   225,    57,
      79,    60,    54,    61,    58,   139,    60,    60,   132,    62,
     149,   132,    80,    81,    82,    83,    84,    85,    72,   139,
     159,    68,    69,   143,    57,   119,   130,    54,    61,   149,
     150,   151,   119,    58,   154,   143,   156,   157,    60,   159,
      62,   107,   150,   151,    54,    60,   154,    57,    24,   157,
     170,   130,    72,    73,    74,    77,   190,    60,   119,   272,
     194,    60,   170,    39,     4,     5,   160,    43,     9,    60,
     190,    62,    65,   160,   194,   195,    66,   201,   157,   218,
     201,    57,   177,   178,   179,   180,    60,   195,    62,    70,
      71,   215,    56,    57,   215,   175,   176,    67,   218,    54,
     203,    59,    61,   181,   182,   225,   183,   184,    57,    63,
      58,    58,    54,   200,    45,    61,    61,   185,   186,   187,
      58,   200,    51,    51,    51,    61,    61,    61,   207,    61,
      60,    17,    54,    43,    55,   274,   275,   276,   272,   200,
      63,   228,   266,   265,    61,   266,    61,    63,   282,   228,
      61,    63,   272,   214,   274,   275,   276,   277,   278,   298,
     281,    61,   282,    61,   232,   304,    49,   169,   307,   277,
     278,   214,   172,   171,    39,   207,   173,   157,   298,     6,
       7,   107,   174,    -1,   304,    -1,   265,   307,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    -1,    54,    55,    56,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,     6,     7,    70,    71,    72,    -1,    -1,    75,    76,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    -1,    54,
      55,    56,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,     6,     7,    70,    71,    72,    -1,    -1,
      75,    76,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    37,    38,    39,    40,    41,    42,
      34,    44,    45,    46,    47,    48,    -1,    -1,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    50,    60,    -1,    -1,
      -1,    -1,    56,    -1,    67,     6,     7,    70,    71,    72,
      -1,    -1,    75,    76,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,     6,     7,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,     6,     7,    48,    -1,    50,
      51,    52,    -1,    -1,    15,    16,    17,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      71,    72,    -1,    48,    75,    76,    51,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    -1,    48,    -1,    -1,
      51,    52,    67,    -1,    -1,    70,    71,    72,    -1,    60,
      75,    76,    63,    -1,    -1,    -1,    67,     6,     7,    70,
      71,    72,    -1,    -1,    75,    76,    15,    16,    17,    -1,
      -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    48,
      -1,    -1,    51,    52,    34,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    48,    -1,    -1,    51,    52,    67,    54,
      50,    70,    71,    72,    -1,    60,    75,    76,    -1,    -1,
      -1,    61,    67,     6,     7,    70,    71,    72,    -1,    -1,
      75,    76,    15,    16,    17,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    48,    -1,    -1,    51,    52,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    48,    -1,
      -1,    51,    52,    -1,    67,    -1,    -1,    70,    71,    72,
      60,    61,    75,    76,    -1,    48,    -1,    67,    51,    52,
      70,    71,    72,    -1,    -1,    75,    76,    60,    -1,    -1,
      63,    -1,    -1,    -1,    67,     6,     7,    70,    71,    72,
      -1,    -1,    75,    76,    15,    16,    17,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      48,    -1,    63,    51,    52,    -1,    67,    -1,    -1,    70,
      71,    72,    60,    61,    75,    76,    -1,    48,    -1,    67,
      51,    52,    70,    71,    72,    -1,    -1,    75,    76,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,     6,     7,    70,
      71,    72,    -1,    -1,    75,    76,    15,    16,    17,    -1,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    48,
      -1,    -1,    51,    52,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    48,    -1,    -1,    51,    52,    -1,    67,    -1,
      50,    70,    71,    72,    60,    55,    75,    76,    -1,    59,
      -1,    67,    -1,    -1,    70,    71,    72,    -1,    -1,    75,
      76,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    50,    51,    34,    -1,    54,    -1,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    50,    51,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    72,    54,
      -1,    -1,    -1,    -1,    -1,    60,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    34,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    50,    51,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    50,    51,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    72,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    50,    51,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    34,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    34,    50,    51,    60,    72,    79,    80,    81,    82,
      83,    84,    85,    86,    93,    94,   117,   123,    84,    51,
      55,    93,   123,     0,    81,    54,    85,    91,    92,    93,
      55,    83,    84,   118,   129,    60,    62,    94,    93,    55,
      84,    87,    88,    61,    54,    57,    59,   118,   129,     6,
       7,    15,    16,    17,    37,    38,    39,    40,    41,    42,
      44,    45,    46,    47,    48,    51,    52,    54,    56,    60,
      67,    70,    71,    72,    75,    76,    83,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   128,   129,   130,   131,   132,
     133,   134,   135,   136,    93,    83,   129,    51,    61,    84,
     119,   120,   121,   122,    51,    63,    98,   100,   112,    54,
      87,    54,    58,    89,    90,    93,    56,    88,    92,    55,
      96,    99,   129,    60,   112,   112,    54,    54,    98,    58,
      60,    60,    54,   116,    60,   128,    60,    60,   112,    58,
      84,   116,   125,   111,   111,   111,   111,   111,   111,    10,
      64,     9,    65,    66,    67,    13,    14,    11,    12,    68,
      69,     4,     5,    70,    71,    72,    73,    74,     3,    59,
      97,     6,     7,     8,    60,    62,    77,    54,    56,   131,
      60,    62,    93,   123,   126,   127,    61,    57,    57,    61,
      63,    56,    98,    54,    57,    58,    95,    96,    58,   128,
     116,   116,    54,   116,    45,   132,   125,   128,    60,   123,
     126,    61,    61,   102,   116,   103,   104,   105,   106,   107,
     107,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,    99,    51,    61,    99,   124,   116,    51,    61,
     119,   126,    63,    98,   127,    60,    62,   121,    51,    90,
      98,    56,    57,   128,    61,    61,    61,    60,   132,    61,
     111,    58,    57,    61,    63,    61,    61,    63,    61,   119,
      63,    98,    56,    96,   128,   128,   128,   116,    61,   116,
     100,    99,    61,    63,    43,    61,   128,    61,   128,    54,
     128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   109,   110,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   115,   115,   115,   116,   117,   117,
     117,   117,   118,   118,   119,   120,   120,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   135,   136,   136,   136,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     4,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     2,     1,     2,     2,
       3,     1,     3,     2,     3,     1,     1,     3,     3,     1,
       2,     1,     1,     3,     3,     4,     4,     4,     3,     1,
       3,     3,     4,     1,     1,     1,     1,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     1,     4,     3,     4,     3,     3,     2,     2,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     3,
       3,     2,     1,     2,     1,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       1,     1,     1,     2,     7,     5,     5,     5,     7,     6,
       7,     3,     4,     3,     2,     2,     2,     3
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
        case 2:
#line 64 "src/c_parser.y" /* yacc.c:1667  */
    {/*$1 = new translation_unit();*/ g_root = (yyvsp[0].bnode);}
#line 1718 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 3:
#line 67 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new translation_unit((yyvsp[0].node));}
#line 1724 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 4:
#line 68 "src/c_parser.y" /* yacc.c:1667  */
    { (yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1730 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 5:
#line 72 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1736 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 6:
#line 73 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1742 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 7:
#line 74 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1748 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 8:
#line 78 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new typedef_declaration((yyvsp[-2].bnode),(yyvsp[-1].node));}
#line 1754 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 9:
#line 82 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration((yyvsp[-1].bnode));}
#line 1760 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 10:
#line 83 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration((yyvsp[-2].bnode),(yyvsp[-1].bnode));}
#line 1766 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 11:
#line 87 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new declaration_specifier_list((yyvsp[0].node));}
#line 1772 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 12:
#line 88 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1778 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 13:
#line 92 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("void");}
#line 1784 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 14:
#line 93 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("char");}
#line 1790 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 15:
#line 94 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("short");}
#line 1796 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 16:
#line 95 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("int"); }
#line 1802 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 17:
#line 96 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("long");}
#line 1808 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 18:
#line 97 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("float");}
#line 1814 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 19:
#line 98 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("double");}
#line 1820 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 20:
#line 99 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("signed");}
#line 1826 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 21:
#line 100 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declaration_specifiers("unsigned");}
#line 1832 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 22:
#line 101 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1838 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 23:
#line 102 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new TypdefSpecifier(*((yyvsp[0].string)));}
#line 1844 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 24:
#line 106 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_specifier((yyvsp[-1].bnode));}
#line 1850 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 25:
#line 107 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_specifier(*((yyvsp[-3].string)), (yyvsp[-1].bnode));}
#line 1856 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 26:
#line 108 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_specifier(*((yyvsp[0].string)));}
#line 1862 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 27:
#line 112 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new struct_declaration_list((yyvsp[0].node));}
#line 1868 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 28:
#line 113 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1874 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 29:
#line 117 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_declaration((yyvsp[-1].bnode));}
#line 1880 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 30:
#line 118 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_declaration((yyvsp[-2].bnode), (yyvsp[-1].bnode));}
#line 1886 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 31:
#line 122 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new struct_declarator_list((yyvsp[0].node));}
#line 1892 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 32:
#line 123 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1898 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 33:
#line 127 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_declarator((yyvsp[0].enode));}
#line 1904 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 34:
#line 128 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_declarator((yyvsp[-2].node), (yyvsp[0].enode));}
#line 1910 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 35:
#line 129 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new struct_declarator((yyvsp[0].node));}
#line 1916 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 36:
#line 134 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new init_declarator_list((yyvsp[0].node));}
#line 1922 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 37:
#line 135 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 1928 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 38:
#line 139 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new init_declarator((yyvsp[-2].node), (yyvsp[0].node));}
#line 1934 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 39:
#line 140 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new init_declarator((yyvsp[0].node));}
#line 1940 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 40:
#line 144 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new declarator((yyvsp[0].node), (yyvsp[-1].ptrNode));}
#line 1946 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 41:
#line 145 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1952 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 42:
#line 149 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new direct_declarator(*((yyvsp[0].string)));}
#line 1958 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 43:
#line 150 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1964 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 44:
#line 151 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ArrayDeclaration((yyvsp[-2].node));}
#line 1970 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 45:
#line 152 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ArrayDeclaration((yyvsp[-3].node), (yyvsp[-1].enode));}
#line 1976 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 46:
#line 153 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-1].bnode));}
#line 1982 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 47:
#line 154 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new FunctionDeclaration((yyvsp[-3].node), (yyvsp[-1].idlist));}
#line 1988 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 48:
#line 155 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new FunctionDeclaration((yyvsp[-2].node));}
#line 1994 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 49:
#line 159 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new initialiser_list((yyvsp[0].node));}
#line 2000 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 50:
#line 160 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2006 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 51:
#line 164 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ObjectInitialiser((yyvsp[-1].bnode));}
#line 2012 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 52:
#line 165 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ObjectInitialiser((yyvsp[-2].bnode));}
#line 2018 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 53:
#line 166 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new initialiser((yyvsp[0].enode));}
#line 2024 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 54:
#line 170 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.string) = new std::string("="); }
#line 2030 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 55:
#line 171 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.string) = (yyvsp[0].string); }
#line 2036 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 56:
#line 175 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2042 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 57:
#line 179 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2048 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 58:
#line 180 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new assignment_expression((yyvsp[-2].enode), *(yyvsp[-1].string), (yyvsp[0].enode));}
#line 2054 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 59:
#line 184 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2060 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 60:
#line 185 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new conditional_expression((yyvsp[-4].enode),(yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2066 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 61:
#line 189 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2072 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 62:
#line 190 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LogicalOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2078 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 63:
#line 194 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2084 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 64:
#line 195 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LogicalAndOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2090 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 65:
#line 199 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2096 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 66:
#line 200 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new InclusiveOrOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2102 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 67:
#line 205 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2108 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 68:
#line 206 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new ExclusiveOrOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2114 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 69:
#line 210 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2120 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 70:
#line 211 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new AndOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2126 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 71:
#line 215 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2132 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 72:
#line 216 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new EqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2138 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 73:
#line 217 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new NotEqualOp((yyvsp[-2].enode),(yyvsp[0].enode));}
#line 2144 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 74:
#line 221 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2150 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 75:
#line 222 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new GreaterThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2156 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 76:
#line 223 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LessThanOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2162 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 77:
#line 224 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LessThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2168 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 78:
#line 225 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new GreaterThanEqOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2174 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 79:
#line 229 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2180 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 80:
#line 230 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LeftShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2186 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 81:
#line 231 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new RightShiftOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2192 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 82:
#line 235 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2198 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 83:
#line 236 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new AddOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2204 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 84:
#line 237 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new SubOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2210 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 85:
#line 241 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2216 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 86:
#line 242 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new MultOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2222 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 87:
#line 243 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new DivOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2228 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 88:
#line 244 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new ModulusOp((yyvsp[-2].enode), (yyvsp[0].enode));}
#line 2234 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 89:
#line 248 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2240 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 90:
#line 249 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new cast_expression((yyvsp[-2].node), (yyvsp[0].enode));}
#line 2246 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 91:
#line 253 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2252 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 92:
#line 254 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PreIncOp((yyvsp[0].enode));}
#line 2258 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 93:
#line 255 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PreDecOp((yyvsp[0].enode));}
#line 2264 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 94:
#line 256 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new RefOp((yyvsp[0].enode));}
#line 2270 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 95:
#line 257 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PtrOp((yyvsp[0].enode));}
#line 2276 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 96:
#line 258 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new UAddOp((yyvsp[0].enode));}
#line 2282 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 97:
#line 259 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new USubOp((yyvsp[0].enode));}
#line 2288 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 98:
#line 260 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new BitwiseNotOp((yyvsp[0].enode));}
#line 2294 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 99:
#line 261 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new LogicalNotOp((yyvsp[0].enode));}
#line 2300 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 100:
#line 262 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new SizeOf((yyvsp[0].enode));}
#line 2306 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 101:
#line 263 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new SizeOf((yyvsp[-1].node));}
#line 2312 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 102:
#line 267 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2318 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 103:
#line 268 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new array_call((yyvsp[-3].enode), (yyvsp[-1].enode));}
#line 2324 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 104:
#line 269 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new function_call((yyvsp[-2].enode), NULL);}
#line 2330 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 105:
#line 270 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new function_call((yyvsp[-3].enode), (yyvsp[-1].bnode));}
#line 2336 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 106:
#line 271 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new DotMemberOp((yyvsp[-2].enode), *((yyvsp[0].string)));}
#line 2342 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 107:
#line 272 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PtrMemberOp((yyvsp[-2].enode), *((yyvsp[0].string)));}
#line 2348 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 108:
#line 273 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PostIncOp((yyvsp[-1].enode));}
#line 2354 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 109:
#line 274 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new PostDecOp((yyvsp[-1].enode));}
#line 2360 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 110:
#line 278 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new primary_expression(*((yyvsp[0].string)));}
#line 2366 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 111:
#line 279 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new constantNode((yyvsp[0].number));}
#line 2372 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 112:
#line 280 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = new stringNode(*((yyvsp[0].string)));}
#line 2378 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 113:
#line 281 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[-1].enode);}
#line 2384 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 114:
#line 285 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.number) = (yyvsp[0].number);}
#line 2390 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 115:
#line 286 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.number) = (yyvsp[0].number);}
#line 2396 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 116:
#line 287 "src/c_parser.y" /* yacc.c:1667  */
    {}
#line 2402 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 117:
#line 291 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.enode) = (yyvsp[0].enode);}
#line 2408 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 118:
#line 295 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO*/}
#line 2414 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 119:
#line 296 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new function_definition((yyvsp[-2].bnode), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2420 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 120:
#line 297 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO*/}
#line 2426 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 121:
#line 298 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new function_definition((yyvsp[-1].node), (yyvsp[0].node));}
#line 2432 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 122:
#line 302 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new declaration_list((yyvsp[0].node));}
#line 2438 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 123:
#line 303 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2444 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 124:
#line 307 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[0].bnode);}
#line 2450 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 125:
#line 311 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new parameter_list((yyvsp[0].node));}
#line 2456 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 126:
#line 312 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2462 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 127:
#line 316 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new parameter_declaration((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2468 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 128:
#line 317 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new parameter_declaration((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2474 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 129:
#line 318 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new parameter_declaration((yyvsp[0].bnode));}
#line 2480 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 130:
#line 322 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.idlist) = new identifier_list(*((yyvsp[0].string)));}
#line 2486 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 131:
#line 323 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.idlist) = (yyvsp[-2].idlist); (yyval.idlist)->push(*((yyvsp[0].string)));}
#line 2492 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 132:
#line 327 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.ptrNode) = new Pointer();}
#line 2498 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 133:
#line 328 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.ptrNode) = (yyvsp[0].ptrNode); (yyval.ptrNode)->inc();}
#line 2504 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 134:
#line 332 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new argument_expression_list((yyvsp[0].enode));}
#line 2510 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 135:
#line 333 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-2].bnode); (yyval.bnode)->push((yyvsp[0].enode));}
#line 2516 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 136:
#line 337 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new type_name((yyvsp[0].bnode));}
#line 2522 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 137:
#line 338 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new type_name((yyvsp[-1].bnode), (yyvsp[0].node));}
#line 2528 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 138:
#line 342 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new abstract_pointer((yyvsp[0].ptrNode));}
#line 2534 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 139:
#line 343 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new abstract_declarator((yyvsp[0].node));}
#line 2540 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 140:
#line 344 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new abstract_declarator((yyvsp[0].node), (yyvsp[-1].ptrNode));}
#line 2546 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 141:
#line 348 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2552 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 142:
#line 349 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new AbstractArray();}
#line 2558 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 143:
#line 350 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new AbstractArray(NULL, (yyvsp[-1].enode));}
#line 2564 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 144:
#line 351 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new AbstractArray((yyvsp[-2].node), NULL);}
#line 2570 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 145:
#line 352 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new AbstractArray((yyvsp[-3].node), (yyvsp[-1].enode));}
#line 2576 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 146:
#line 353 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO: do it later.*/}
#line 2582 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 147:
#line 354 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO: do it later.*/}
#line 2588 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 148:
#line 355 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO: do it later.*/}
#line 2594 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 149:
#line 356 "src/c_parser.y" /* yacc.c:1667  */
    {/*TODO: do it later.*/}
#line 2600 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 150:
#line 362 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2606 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 151:
#line 363 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2612 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 152:
#line 364 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2618 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 153:
#line 365 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2624 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 154:
#line 366 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2630 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 155:
#line 367 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2636 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 156:
#line 371 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new compound_statement();}
#line 2642 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 157:
#line 372 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new compound_statement((yyvsp[-1].bnode));}
#line 2648 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 158:
#line 376 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = new block_item_list((yyvsp[0].node));}
#line 2654 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 159:
#line 377 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.bnode) = (yyvsp[-1].bnode); (yyval.bnode)->push((yyvsp[0].node));}
#line 2660 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 160:
#line 381 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2666 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 161:
#line 382 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2672 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 162:
#line 386 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new expression_statement();}
#line 2678 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 163:
#line 387 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new expression_statement((yyvsp[-1].enode));}
#line 2684 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 164:
#line 391 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new IfStatement((yyvsp[-4].enode), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2690 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 165:
#line 392 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new IfStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2696 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 166:
#line 393 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new SwitchStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2702 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 167:
#line 397 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new WhileStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2708 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 168:
#line 398 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new DoStatement((yyvsp[-5].node), (yyvsp[-2].enode));}
#line 2714 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 169:
#line 399 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ForStatement((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2720 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 170:
#line 400 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ForStatement((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].enode), (yyvsp[0].node));}
#line 2726 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 171:
#line 404 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new LabelStatement(*((yyvsp[-2].string)), (yyvsp[0].node));}
#line 2732 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 172:
#line 405 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new CaseStatement((yyvsp[-2].enode), (yyvsp[0].node));}
#line 2738 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 173:
#line 406 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new DefaultStatement((yyvsp[0].node));}
#line 2744 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 174:
#line 410 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ContinueStatement();}
#line 2750 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 175:
#line 411 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new BreakStatement();}
#line 2756 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 176:
#line 412 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ReturnStatement();}
#line 2762 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;

  case 177:
#line 413 "src/c_parser.y" /* yacc.c:1667  */
    {(yyval.node) = new ReturnStatement((yyvsp[-1].enode));}
#line 2768 "src/c_parser.tab.cpp" /* yacc.c:1667  */
    break;


#line 2772 "src/c_parser.tab.cpp" /* yacc.c:1667  */
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
#line 416 "src/c_parser.y" /* yacc.c:1918  */


BranchNode *g_root;

Node *parseAST()
{
  	g_root=0;
  	yyparse();
  	return g_root;
}

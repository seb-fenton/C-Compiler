/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "src/c_parser.y" /* yacc.c:1909  */

  #include "../include/ast.hpp"

  #include <cassert>

  extern BranchNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
  //to allow file input to AST
  extern FILE *yyin;

#line 60 "src/c_parser.tab.hpp" /* yacc.c:1909  */

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
#line 20 "src/c_parser.y" /* yacc.c:1909  */

  Node *node;
  BranchNode *bnode;
  ExpressionNode *enode;
  double number;
  std::string *string;
  identifier_list *idlist;
  Pointer *ptrNode;

#line 136 "src/c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

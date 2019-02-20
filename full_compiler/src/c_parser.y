%code requires{
  //#include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Node *node;
  double number;
  std::string *string;
}

%token T_ASSIGNMENT_OP, RIGHT_SHIFT_OP, LEFT_SHIFT_OP, INC_OP, DEC_OP, PTR_OP, AND_OP, OR_OP, LE_OP, GE_OP, EQ_OP, NE_OP,
%token INT_CONSTANT, FLOAT_CONSTANT, STRING_LITERAL
%token T_VOID, T_CHAR, T_SHORT, T_INT, T_LONG, T_FLOAT, T_DOUBLE, T_SIGNED
%token T_UNSIGNED, T_TYPEDEF, T_EXTERN, T_STATIC, T_AUTO, T_REGISTER, T_CONST, T_VOLATILE, T_STRUCT,
%token T_GOTO, T_BREAK, T_CONTINUE, T_CASE, T_DEFAULT, T_SWITCH, T_IF, T_ELSE, 
%token T_RETURN, T_WHILE, T_DO, T_FOR, T_SIZEOF, T_IDENTIFIER

%type <node>
%type <number> 
%type <string> 

%start SRC_CODE
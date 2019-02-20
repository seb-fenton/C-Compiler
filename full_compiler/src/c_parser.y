%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Top_Node *g_root; // A way of getting the AST out

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
%token T_RETURN, T_WHILE, T_DO, T_FOR, T_SIZEOF
%token TYPEDEF_NAME, T_IDENTIFIER

%type <node>
%type <number> 
%type <string> 

%start roor

%%

//TO-DO Group the rules so that similar things are together

root: translation_unit {$1 = new translation_unit(); g_root = $1}

translation_unit: 
		external_declaration	{$$->push($1)}//push back into g_root node
		| translation_unit external_declaration  {$$->push($2); $1 = $$}//should only have one translation_unit in the entire tree with this
		;

external_declaration: 
		function_definition {$$ = $1} 	//create function node in next step not now
		| declaration   	{$$ = $1}	//create declaration node in next step
		;

declaration:
		declaration_specifier_list ';'  {$1 = new declaration_specifier_list(); $$ = new declaration($1);}
		| declaration_specifier_list init_declarator_list ';'  {$1 = new declaration_specifier_list(); $2 = new init_declarator_list(); $$ = new declaration($1,$2);} 
		;	// also make two constructors

declaration_specifier_list:
		declaration_specifiers 		{$$->push($1);}									//$1 will just return a string or something
		| declaration_specifier_list declaration_specifiers {$$->push($2); $1 = $$;}	
		;	// $1 = $$ should give you the same node on the next iteration

declaration_specifiers:
		T_VOID //decide how to return this, maybe as a string or bool values
    	|T_CHAR
    	|T_SHORT
    	|T_INT
    	|T_LONG
    	|T_FLOAT
    	|T_DOUBLE
    	|T_SIGNED
    	|T_UNSIGNED
    	|T_TYPEDEF
    	|T_EXTERN
    	|T_STATIC
    	|T_AUTO
    	|T_REGISTER
    	|T_CONST
    	|T_VOLATILE
    	|T_STRUCT
		;

init_declarator_list:
		init_declarator	{$$->push($1)}						//same way as sbove do $$->push($1) to store the init_declarator in the list node
		| init_declarator ',' init_declarator_list {$$->push($2); $1 = $$;}		// this  should work. who knows
		; 

init_declarator:
		declarator '=' initialiser //declarator is a variable name
		| declarator
		;

declarator: 
		pointer direct_declarator //each declarations should only happen once
		| direct_declarator 
		;

direct_declarator:
		T_IDENTIFIER 		//Need node to check bindings and identifier names
		|'(' declarator ')' //works for dereferencing pointers
		| direct_declarator '[' ']' //need node for array declaration
		| direct_declarator '[' assignment_expression ']' //
		| direct_declarator '(' parameter_type_list ')' //returns a variable name and then a list of arguments? only used for function calls probably
		| direct_declarator '(' identifier_list ')' //just a list of variables, no idea of example case
		| direct_declarator '(' ')' //no clue - figure this one out maybe used for function calls
		;



				
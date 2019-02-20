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

%start translation_unit

%%

translation_unit: 
		external_declaration	//push back into g_root node
		| translation_unit external_declaration  //pushback into g_root node
		;

external_declaration: 
		function_definition //create function node in next step not now
		| declaration   	//create declaration node in next step
		;

declaration:
		declaration_specifier_list ';' // maybe have a class which has a list of bools specifying the type of the variable
		| declaration_specifier_list init_declarator_list ';' //need to find a way to create a base init_declarator_list class which has a vector of declarations
		;

declaration_specifier_list:
		declaration_specifiers 									//do something like $$->push($1) where $1 is a either just a node or a string.
		| declaration_specifier_list declaration_specifiers 	//first $$->push($2) to push the type into the original node,
		;														// then $$ = $1 should make it so the next iteration uses the same node

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
		init_declarator									//same way as sbove do $$->push($1) to store the init_declarator in the list node
		| init_declarator ',' init_declarator_list 		//then $$->push($1); $1 = $$? hmm maybe ask olly, this or the other should work. who knows
		; 

init_declarator:
		declarator '=' initialiser //declarator is a variable name, and encompasses arrays aswell, decide a way to edit context to change the binding
		| declarator
		;

declarator: 
		pointer direct_declarator //each declarations should only happen once
		| direct_declarator 
		;

direct_declarator:
		T_IDENTIFIER 		//returns variable name
		|'(' declarator ')' //works for dereferencing pointers
		| direct_declarator '[' ']' //empty array
		| direct_declarator '[' assignment_expression ']' //assignment_expression is just something which returns a value
		| direct_declarator '(' parameter_type_list ')' //returns a variable name and then a list of arguments? only used for function calls probably
		| direct_declarator '(' identifier_list ')' //just a list of variables, no idea of example case
		| direct_declarator '(' ')' //no clue - figure this one out maybe used for function calls
		;



				
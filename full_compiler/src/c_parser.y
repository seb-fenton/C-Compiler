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

%start root

%%

//TO-DO Group the rules so that similar things are together
//Spec https://www.pdf-archive.com/2014/10/02/ansi-iso-9899-1990-1/ansi-iso-9899-1990-1.pdf

root: translation_unit {/*$1 = new translation_unit();*/ g_root = $1}; 

translation_unit: 
		external_declaration	{$$ = new translation_unit($1);/*$$->push($1)*/} //push back into g_root node
		| translation_unit external_declaration  { $$ = $1; $$->push($2);}//should only have one translation_unit in the entire tree with this
		;

external_declaration: 
		function_definition {$$ = $1} 	//create function node in next step not now
		| declaration   	{$$ = $1}	//create declaration node in next step
		| typedef_declaration 			//need to make this ourselves, ill explain it to you
		;

typedef_declaration:
		T_TYPEDEF declaration_specifier_list declarator ';' //this needs some thinking, since arrays work differently with typedefs,
															//might be worth not doing it
		;

declaration:
		declaration_specifier_list ';'  { $$ = new declaration($1);}
		| declaration_specifier_list init_declarator_list ';'  { $$ = new declaration($1,$2);} 
		;	// also make two constructors

declaration_specifier_list:
		declaration_specifiers 		{$$ = new declaration_specifier_list($1);}			// $1 will just return a string or something
		| declaration_specifier_list declaration_specifiers {$$ = $1; $$->push($2);}	// $1 = $$ should give you the same node on the next iteration
		;													

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
    	|T_EXTERN
    	|T_STATIC
    	|T_AUTO
    	|T_REGISTER
    	|T_CONST
    	|T_VOLATILE
    	| struct_or_union_specifier	
		|TYPEDEF_NAME
		;

struct_or_union_specifier:
		struct_or_union '{' struct_declaration_list '}'					//used to initlialise structs
		| struct_or_union IDENTIFIER '{' struct_declaration_list '}'	//Page: 59
		| struct_or_union IDENTIFIER
		;

	
struct_or_union:
		T_STRUCT
		| T_UNION
		;
	
struct_declaration_list:
		struct_declaration										
		| struct_declaration_list struct_declaration
		; 

struct_declaration:
		declaration_specifier_list ';' /* for anonymous structs/unions */
		| declaration_specifier_list struct_declarator_list ';'
		; //One more rule using static don't know if it needs to be implemented

struct_declarator_list:
		struct_declarator  //creates a list of variables to be used in a struct
		| struct_declarator_list ',' struct_declarator
		;

struct_declarator:
		':' constant_expression
		| declarator ':' constant_expression
		| declarator
		;


init_declarator_list:
		init_declarator	{$$ = new init_declarator_list($1);}						//same way as sbove do $$->push($1) to store the init_declarator in the list node
		| init_declarator_list ',' init_declarator {$$ = $1; $$->push($2);}			
		; 

init_declarator:
		declarator '=' initialiser //declarator is a variable name
		| declarator
		;

declarator: 
		pointer direct_declarator 				//each declarations should only happen once, so there is no recursion
		| direct_declarator 
		;

direct_declarator:
		T_IDENTIFIER 										//Need node to check bindings and identifier names
		|'(' declarator ')' 								//works for dereferencing pointers
		| direct_declarator '[' ']' 						//need node for array declaration   
		| direct_declarator '[' assignment_expression ']' 	//same as above but with expression inside square brackers
		| direct_declarator '(' parameter_type_list ')' 	//returns a variable name and then a list of arguments? only used for function calls probably
		| direct_declarator '(' identifier_list ')' 		//just a list of variables, no idea of example case
		| direct_declarator '(' ')' 						//no clue - figure this one out, maybe used for function calls
		;

initialiser_list:
		designation initialiser
		| initialiser
		| initialiser_list ',' designation initialiser
		| initialiser_list ',' initialiser
		;

initialiser:
		'{' initialiser_list '}' 		//used for arrays 
		|'{' initialiser_list ',' '}'	//i think for multi-dimensional array. PAGE:71 in spec linked above
		|assignment_expression			//assignment_expression is anything that would be on the RHS of an assignment operator. An expression is just a list of these, we can rename it.
		;								//Also this can be a full expression with its own assignment operator but dw about that for now

constant_expression:
		conditional_expression
		;

assignment_expression:
		conditional_expression											//this will go through all the operators that are used in evaulating an expression
		| unary_expression assignment_operator assignment_expression	//this, I believe is used when changing variables etc. PAGE:53 in spec
		;

conditional_expression:
		logical_or_expression												//this binds the highest and is thus first, 
		| logical_or_expression '?' expression ':' conditional_expression	//the following expression rules just go in order of priority
		;

logical_or_expression:
		logical_and_expression
		| logical_or_expression OR_OP logical_and_expression			
		;

logical_and_expression:
		inclusive_or_expression
		| logical_and_expression AND_OP inclusive_or_expression		
		;

inclusive_or_expression:
		exclusive_or_expression
		| logical_or_expression '|' logical_and_expression			
		;


exclusive_or_expression:
		and_expression
		| exclusive_or_expression '^' and_expression			
		;

and_expression:
		equality_expression
		| and_expression '&' equality_expression
		;

equality_expression:
		relational_expression
		| equality_expression EQ_OP relational_expression  //need to decide if we want different classes for each operator, or we can use one class for both
		| equality_expression NE_OP relational_expression
		;

relational_expression:
		shift_expression
		| relational_expression '>' shift_expression  		//once again, one class or 4 classes? dont know if we can take the char value
		| relational_expression '<' shift_expression		// of the single character operators, may be possible to turn all operators in the lex
		| relational_expression LE_OP shift_expression		// to c-strings then we can just use those throughout the program
		| relational_expression GE_OP shift_expression
		;

shift_expression:
		additive_expression										//so after this we start the basic maths
		| shift_expression LEFT_SHIFT_OP additive_expression
		| shift_expression RIGHT_SHIFT_OP additive_expression
		;

additive_expression:
		multiplicative_expression
		| additive_expression '+' multiplicative_expression
		| additive_expression '-' multiplicative_expression
		;

multiplicative_expression:
		cast_expression
		| multiplicative_expression '*' cast_expression
		| multiplicative_expression '/' cast_expression
		| multiplicative_expression '%' cast_expression
		;

cast_expression:
		unary_expression 							//the unary expression does operations on single numbers or variable, all leads to getting the variable name at one point
		| '(' type_name ')' cast_expression
		;

unary_expression:  									//PAGE : 43
		postfix_expression
		| INC_OP unary_expression
		| DEC_OP unary_expression
		| unary_operator cast_expression
		| T_SIZEOF unary_expression
		| T_SIZEOF '(' type_name ')'
		;

postfix_expression:
		primary_expression						//Page 39
		| postfix_expression '[' expression ']'  //array calls
		| postfix_expression '(' ')'
		| postfix_expression '(' argument_expression_list ')' //used for function calls most likely
		| postfix_expression '.' IDENTIFIER
		| postfix_expression PTR_OP IDENTIFIER
		| postfix_expression INC_OP
		| postfix_expression DEC_OP
		| '(' type_name ')' '{' initialiser_list '}'
		| '(' type_name ')' '{' initialiser_list ',' '}'
		;

primary_expression:
		IDENTIFIER
		| constant
		| STRING_LITERAL
		| '(' expression ')'
		;

constant:
		INT_CONSTANT
		| FLOAT_CONSTANT
		| ENUMERATION_CONSTANT  // Do this later
		;

expression:
		assignment_expression
		| expression ',' assignment_expression
		;

designation:
		designator_list '='
		;

designator_list:
		designator
		| designator_list designator
		;

designator:
		'[' constant_expression ']'
		| '.' IDENTIFIER
		;
		
function_definition:
		declaration_specifiers declarator declaration_list compound_statement
		| declaration_specifiers declarator compound_statement
		;

declaration_list:
		declaration
		| declaration_list declaration
		;

parameter_type_list:
		parameter_list
		;

parameter_list:
		parameter_declaration
		| parameter_list ',' parameter_declaration
		;

parameter_declaration:
		declaration_specifiers declarator
		| declaration_specifier
		;

identifier_list:
		IDENTIFIER
		| identifier_list ',' IDENTIFIER
		;

//statements

statement:
		labeled_statement
		| compound_statement
		| expression_statement
		| selection_statement
		| iteration_statement
		| jump_statement
		;

compound_statement:
		'{' '}'
		| '{' block_item_list '}'
		;

block_item_list:
		block_item
		| block_item_list block_item
		;

block_item:
		declaration
		| statement
		;

expression_statement:
		';'
		| expression ';'
		;

selection_statement:
		T_IF '(' expression ')' statement T_ELSE statement  //Page: 77
		| T_IF '(' expression ')' statement 
		| T_SWITCH '(' expression ')' statement
		;

iteration_statement:
		T_WHILE '(' expression ')' statement 							//page 78
		| T_DO statement T_WHILE '(' expression ')' ';'
		| T_FOR '(' expression_statement expression_statement ')' statement
		| T_FOR '(' expression_statement expression_statement expression ')' statement
		| T_FOR '(' declaration expression_statement ')' statement
		| T_FOR '(' declaration expression_statement expression ')' statement
		;	



jump_statement:
		CONTINUE ';'
		| BREAK ';'
		| RETURN ';'
		| RETURN expression ';'
		;

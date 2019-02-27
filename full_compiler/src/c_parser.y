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
  double fnumber;
  long inumber;
  std::string *string;
}

%token T_ASSIGNMENT_OP, RIGHT_SHIFT_OP, LEFT_SHIFT_OP, INC_OP, DEC_OP, PTR_OP, AND_OP, OR_OP, LE_OP, GE_OP, EQ_OP, NE_OP,
%token INT_CONSTANT, FLOAT_CONSTANT, STRING_LITERAL
%token T_VOID, T_CHAR, T_SHORT, T_INT, T_LONG, T_FLOAT, T_DOUBLE, T_SIGNED
%token T_UNSIGNED, T_TYPEDEF, T_EXTERN, T_STATIC, T_AUTO, T_REGISTER, T_CONST, T_VOLATILE, T_STRUCT,
%token T_GOTO, T_BREAK, T_CONTINUE, T_CASE, T_DEFAULT, T_SWITCH, T_IF, T_ELSE, 
%token T_RETURN, T_WHILE, T_DO, T_FOR, T_SIZEOF
%token TYPEDEF_NAME, T_IDENTIFIER

%type <node> translation_unit external_declaration declaration declaration_specifier_list declaration_specifier
%type <node> init_declarator_list declarator direct_declarator
%type <fnumber> FLOAT_CONSTANT
%type <inumber> INT_CONSTANT
%type <string> TYPEDEF_NAME T_IDENTIFIER STRING_LITERAL

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

declaration_specifiers: //we need to make this a class which holds the specifer name, and optionally all the struct information
		T_VOID 						{$$ = new declaration_specifier($1);}
    	|T_CHAR						{$$ = new declaration_specifier($1);}
    	|T_SHORT					{$$ = new declaration_specifier($1);}
    	|T_INT						{$$ = new declaration_specifier($1);}
    	|T_LONG						{$$ = new declaration_specifier($1);}
    	|T_FLOAT					{$$ = new declaration_specifier($1);}
    	|T_DOUBLE					{$$ = new declaration_specifier($1);}
    	|T_SIGNED					{$$ = new declaration_specifier($1);}
    	|T_UNSIGNED					{$$ = new declaration_specifier($1);}
    	|T_EXTERN					{$$ = new declaration_specifier($1);}
    	|T_STATIC					{$$ = new declaration_specifier($1);}
    	|T_AUTO						{$$ = new declaration_specifier($1);}
    	|T_REGISTER					{$$ = new declaration_specifier($1);}
    	|T_CONST					{$$ = new declaration_specifier($1);}
    	|T_VOLATILE					{$$ = new declaration_specifier($1);}
    	| struct_or_union_specifier	{$$ = new declaration_specifier($1, 1);} //make a second constructor which accepts a integer specficying if its an enum, typedef or a struct
		|TYPEDEF_NAME				{$$ = new declaration_specifier($1, 2);}
		;

struct_or_union_specifier:
		struct_or_union '{' struct_declaration_list '}'					//used to initlialise structs
		| struct_or_union T_IDENTIFIER '{' struct_declaration_list '}'	//Page: 59
		| struct_or_union T_IDENTIFIER
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
		declarator '=' initialiser	 {$$ = new init_declarator($1, $3);} //declarator is a variable name
		| declarator				 {$$ = new init_declarator($1);} //two constructors one taking an initialiser
		;

declarator: 
		pointer direct_declarator 	{$$ = new declarator($1, TRUE);}			//each declarations should only happen once, so there is no recursion
		| direct_declarator 		{$$ = new declarator($1, FALSE);} //true indicates the declrator is a pointer
		;

direct_declarator:
		T_IDENTIFIER 										{$$ = new direct_declarator(*$1);}//Need node to check bindings and T_IDENTIFIER names
		|'(' declarator ')' 								{ }								//works for dereferencing pointers
		| direct_declarator '[' ']' 						{$$ = $1; NodePtr tmp = new ArrayDeclaration(); $$->isArray(temp);}//need node for array declaration   
		| direct_declarator '[' assignment_expression ']' 	{$$ = $1; NodePtr tmp = new ArrayDeclaration($3); $$->isArray(temp);}//make a second constructer for declarations with expressions
		| direct_declarator '(' parameter_type_list ')' 	{$$ = $1; $$->isFuncDef($3);} 	//used for function definitions
		| direct_declarator '(' identifier_list ')' 		{$$ = $1; $$->isFuncCall($3);} 	//this function makes the direct declarator state its a fucntion call
		| direct_declarator '(' ')' 						{$$ = $1; $$->isFuncCall();}	//used for function calls with no args
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

assignment_operator:
		'='					{ $$ = new std::string("="); }
		| T_ASSIGNMENT_OP  	{ $$ = $1; }
		;

constant_expression:
		conditional_expression
		;

assignment_expression:
		conditional_expression									{$$ = $1;}		//this will go through all the operators that are used in evaulating an expression
		| unary_expression assignment_operator assignment_expression {$$ = assignment_expression($1, *$2, $3);}	//need to decide how ast will deal with expressions.  PAGE:53 in spec
		;																									//specifcally how to make it easier to print assembly

conditional_expression:
		logical_or_expression											{$$ = $1;}	//this binds the highest and is thus first, 
		| logical_or_expression '?' expression ':' conditional_expression {$$ = conditional_expression($1,$3,$5);}	//the following expression rules just go in order of priority
		;

logical_or_expression:
		logical_and_expression											{$$ = $1;}
		| logical_or_expression OR_OP logical_and_expression			{$$ = logical_or_expression($1,$3);}
		;

logical_and_expression:
		inclusive_or_expression											{$$ = $1);}
		| logical_and_expression AND_OP inclusive_or_expression			{$$ = logical_and_expression($1,$3);}
		;

inclusive_or_expression:
		exclusive_or_expression											{$$ = $1;}
		| logical_or_expression '|' logical_and_expression				{$$ = inclusive_or_expression($1,$3);}
		;


exclusive_or_expression:
		and_expression													{$$ = $1;}
		| exclusive_or_expression '^' and_expression					{$$ = exclusive_expression($1, $3);}
		;

and_expression:
		equality_expression												{$$ = $1;}
		| and_expression '&' equality_expression						{$$ = and_expression($1, $3);}
		;

equality_expression:
		relational_expression											{$$ = $1;}
		| equality_expression EQ_OP relational_expression  				{$$ = equality_expression($1,$3,TRUE);} // TRUE indicates equal
		| equality_expression NE_OP relational_expression				{$$ = equality_expression($1,$3,FALSE)} //FALSE means not equal
		;

relational_expression:
		shift_expression												{$$ = $1;}
		| relational_expression '>' shift_expression  					{$$ = GreaterThanOp($1, $3);}
		| relational_expression '<' shift_expression					{$$ = LessThanOp($1, $3);}
		| relational_expression LE_OP shift_expression					{$$ = LessThanEqOp($1, $3);}
		| relational_expression GE_OP shift_expression					{$$ = GreaterThanEqOp($1, $3);}
		;

shift_expression:
		additive_expression												{$$ = $1;}
		| shift_expression LEFT_SHIFT_OP additive_expression			{$$ = LeftShiftOp($1, $3);}
		| shift_expression RIGHT_SHIFT_OP additive_expression			{$$ = RightShiftOp($1, $3);}
		;

additive_expression:
		multiplicative_expression										{$$ = $1;}
		| additive_expression '+' multiplicative_expression				{$$ = AddOp($1, $3);}
		| additive_expression '-' multiplicative_expression				{$$ = SubOp($1, $3);}
		;

multiplicative_expression:
		cast_expression													{$$ = $1;}
		| multiplicative_expression '*' cast_expression					{$$ = MultOp($1, $3)}
		| multiplicative_expression '/' cast_expression					{$$ = DivOp($1, $3)}
		| multiplicative_expression '%' cast_expression					{$$ = ModulusOp($1, $3)}
		;

cast_expression:
		unary_expression 												{$$ = $1;}	//the unary expression does operations on single numbers or variable
		| '(' type_name ')' cast_expression								{$$ = cast_expression($2, $4);}	//all leads to getting the variable name at one point
		;

unary_expression:  									//PAGE : 43
		postfix_expression												{$$ = $1}
		| INC_OP unary_expression
		| DEC_OP unary_expression
		| unary_operator cast_expression
		| T_SIZEOF unary_expression
		| T_SIZEOF '(' type_name ')'
		;

postfix_expression:
		primary_expression						{$$ = $1}//Page 39
		| postfix_expression '[' expression ']'  //array calls
		| postfix_expression '(' ')'
		| postfix_expression '(' argument_expression_list ')' //used for function calls most likely
		| postfix_expression '.' T_IDENTIFIER
		| postfix_expression PTR_OP T_IDENTIFIER
		| postfix_expression INC_OP
		| postfix_expression DEC_OP
		| '(' type_name ')' '{' initialiser_list '}'
		| '(' type_name ')' '{' initialiser_list ',' '}'
		;

primary_expression:
		T_IDENTIFIER						{$$ = primary_expression(*($1));} //for now we can just return the value of the variable in an eval func,
		| constant															//but we may need more constructors to differentiate different primary_expressions
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
		| '.' T_IDENTIFIER
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
		T_IDENTIFIER
		| identifier_list ',' T_IDENTIFIER
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

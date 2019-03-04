%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern BranchNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}
%define parse.error verbose

// Represents the value associated with any kind of
// AST node.
%union{
  Node *node;
  BranchNode *bnode;
  ExpressionNode *enode;
  double number;
  std::string *string;
  identifier_list *idlist;
}

%token T_ASSIGNMENT_OP RIGHT_SHIFT_OP LEFT_SHIFT_OP INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%token INT_CONSTANT FLOAT_CONSTANT STRING_LITERAL
%token T_VOID T_CHAR T_SHORT T_INT T_LONG T_FLOAT T_DOUBLE T_SIGNED
%token T_UNSIGNED T_TYPEDEF T_EXTERN T_STATIC T_AUTO T_REGISTER T_CONST T_VOLATILE T_STRUCT T_UNION
%token T_GOTO T_BREAK T_CONTINUE T_CASE T_DEFAULT T_SWITCH T_IF T_ELSE 
%token T_RETURN T_WHILE T_DO T_FOR T_SIZEOF
%token TYPEDEF_NAME T_IDENTIFIER ENUMERATION_CONSTANT

//TODO: sort out which are branch nodes and which are normal, maybe introduce expression nodes
%type <bnode> translation_unit init_declarator_list declaration_specifier_list  parameter_type_list block_item_list 
%type <bnode> argument_expression_list parameter_list initialiser_list
%type <node> declarator direct_declarator init_declarator initialiser declaration declaration_specifiers
%type <node> pointer external_declaration function_definition compound_statement statement parameter_declaration
%type <node> block_item expression_statement selection_statement iteration_statement labeled_statement
%type <node> jump_statement designation designator_list designator  
%type <enode> assignment_expression conditional_expression logical_or_expression logical_and_expression inclusive_or_expression
%type <enode> exclusive_or_expression and_expression equality_expression relational_expression shift_expression additive_expression
%type <enode> multiplicative_expression cast_expression unary_expression postfix_expression primary_expression expression
%type <enode> constant_expression
%type <number> FLOAT_CONSTANT INT_CONSTANT constant
%type <string> TYPEDEF_NAME T_IDENTIFIER STRING_LITERAL T_ASSIGNMENT_OP assignment_operator
%type <idlist> identifier_list

%start root

%%

//TODO Group the rules so that similar things are together
//TODO Finish allocating types to different terminals
//TODO Code all classes
//Spec https://www.pdf-archive.com/2014/10/02/ansi-iso-9899-1990-1/ansi-iso-9899-1990-1.pdf

root: translation_unit {/*$1 = new translation_unit();*/ g_root = $1;} 

translation_unit: 
		external_declaration	{$$ = new translation_unit($1);} //push back into g_root node
		| translation_unit external_declaration  { $$ = $1; $$->push($2);}//should only have one translation_unit in the entire tree with this
		;

external_declaration: 
		function_definition {$$ = $1;} 	//create function node in next step not now
		| declaration   	{$$ = $1;}	//create declaration node in next step
		| typedef_declaration 			//need to make this ourselves, ill explain it to you
		;

typedef_declaration:
		T_TYPEDEF declaration_specifier_list declarator ';' //this needs some thinking, since arrays work differently with typedefs, might be worth not doing it
		;

declaration:
		declaration_specifier_list ';'  {$$ = new declaration($1);}
		| declaration_specifier_list init_declarator_list ';'  {$$ = new declaration($1,$2);} 
		;	// also make two constructors

declaration_specifier_list:
		declaration_specifiers 		{$$ = new declaration_specifier_list($1);}			// $1 will just return a string or something
		| declaration_specifier_list declaration_specifiers {$$ = $1; $$->push($2);}	// $1 = $$ should give you the same node on the next iteration
		;													

declaration_specifiers: //we need to make this a class which holds the specifer name, and optionally all the struct information
		T_VOID 						{$$ = new declaration_specifiers("void");}
    	|T_CHAR						{$$ = new declaration_specifiers("char");}
    	|T_SHORT					{$$ = new declaration_specifiers("short");}
    	|T_INT						{$$ = new declaration_specifiers("int"); }
    	|T_LONG						{$$ = new declaration_specifiers("long");}
    	|T_FLOAT					{$$ = new declaration_specifiers("float");}
    	|T_DOUBLE					{$$ = new declaration_specifiers("double");}
    	|T_SIGNED					{$$ = new declaration_specifiers("signed");}
    	|T_UNSIGNED					{$$ = new declaration_specifiers("unsigned");}				
    	|struct_or_union_specifier	//{$$ = new declaration_specifiers($1, 1);} //might want to make different classes for special cases
		|TYPEDEF_NAME				//{$$ = new declaration_specifiers($1, 2);}
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
		| init_declarator_list ',' init_declarator {$$ = $1; $$->push($3);}			
		; 

init_declarator:
		declarator '=' initialiser	 {$$ = new init_declarator($1, $3);} //declarator is a variable name
		| declarator 				 {$$ = new init_declarator($1);} //two constructors one taking an initialiser
		;

declarator: 
		pointer direct_declarator 	{$$ = new declarator($2, $1);}			//pointer class will return the pointer level and other misc info
		| direct_declarator 		{$$ = $1;} //declarators should only exist if something is a pointer
		;

direct_declarator:
		T_IDENTIFIER 										{$$ = new direct_declarator(*($1));}//Need node to check bindings and T_IDENTIFIER names
		|'(' declarator ')' 								{ }								//works for dereferencing pointers
		| direct_declarator '[' ']' 						{$$ = new ArrayDeclaration($1);}//need node for array declaration   
		| direct_declarator '[' constant_expression ']' 	{$$ = new ArrayDeclaration($1, $3);}//make a second constructer for declarations with expressions
		| direct_declarator '(' parameter_type_list ')' 	{$$ = new FunctionDeclaration($1, $3);} 	//used for function definitions
		| direct_declarator '(' identifier_list ')' 		{$$ = new FunctionDeclaration($1, $3);} 
		| direct_declarator '(' ')' 						{$$ = new FunctionDeclaration($1);}	//used for function calls with no args
		;

initialiser_list:
		initialiser								{$$ = new initialiser_list($1);}
		| initialiser_list ',' initialiser		{$$ = $1; $$->push($3);}
		;

initialiser:
		'{' initialiser_list '}' 				{$$ = new ObjectInitialiser($2);}//used for arrays 
		|'{' initialiser_list ',' '}'			{$$ = new ObjectInitialiser($2);}//
		|assignment_expression					{$$ = new initialiser($1);} //assignment_expression is anything that would be on the RHS of an assignment operator. An expression is just a list of these, we can rename it.
		;								//Also this can be a full expression with its own assignment operator but dw about that for now

assignment_operator:
		'='					{$$ = new std::string("="); }
		| T_ASSIGNMENT_OP  	{$$ = $1; }
		;

constant_expression:
		conditional_expression		{$$ = $1;}
		;

assignment_expression:
		conditional_expression											{$$ = $1;}		//this will go through all the operators that are used in evaulating an expression
		| unary_expression assignment_operator assignment_expression 	{$$ = new assignment_expression($1, *$2, $3);}	//need to decide how ast will deal with expressions.  PAGE:53 in spec
		;																									//specifcally how to make it easier to print assembly

conditional_expression:
		logical_or_expression												{$$ = $1;}	//this binds the highest and is thus first, 
		| logical_or_expression '?' expression ':' conditional_expression 	{$$ = new conditional_expression($1,$3,$5);}	//the following expression rules just go in order of priority
		;

logical_or_expression:
		logical_and_expression											{$$ = $1;}
		| logical_or_expression OR_OP logical_and_expression			{$$ = new LogicalOrOp($1,$3);}
		;

logical_and_expression:
		inclusive_or_expression											{$$ = $1;}
		| logical_and_expression AND_OP inclusive_or_expression			{$$ = new LogicalAndOp($1,$3);}
		;

inclusive_or_expression:
		exclusive_or_expression											{$$ = $1;}
		| logical_or_expression '|' exclusive_or_expression				{$$ = new InclusiveOrOp($1,$3);}
		;


exclusive_or_expression:
		and_expression													{$$ = $1;}
		| exclusive_or_expression '^' and_expression					{$$ = new ExclusiveOrOp($1, $3);}
		;

and_expression:
		equality_expression												{$$ = $1;}
		| and_expression '&' equality_expression						{$$ = new AndOp($1, $3);}
		;

equality_expression:
		relational_expression											{$$ = $1;}
		| equality_expression EQ_OP relational_expression  				{$$ = new EqualOp($1,$3);}
		| equality_expression NE_OP relational_expression				{$$ = new NotEqualOp($1,$3);} 
		;

relational_expression:
		shift_expression												{$$ = $1;}
		| relational_expression '>' shift_expression  					{$$ = new GreaterThanOp($1, $3);}
		| relational_expression '<' shift_expression					{$$ = new LessThanOp($1, $3);}
		| relational_expression LE_OP shift_expression					{$$ = new LessThanEqOp($1, $3);}
		| relational_expression GE_OP shift_expression					{$$ = new GreaterThanEqOp($1, $3);}
		;

shift_expression:
		additive_expression												{$$ = $1;}
		| shift_expression LEFT_SHIFT_OP additive_expression			{$$ = new LeftShiftOp($1, $3);}
		| shift_expression RIGHT_SHIFT_OP additive_expression			{$$ = new RightShiftOp($1, $3);}
		;

additive_expression:
		multiplicative_expression										{$$ = $1;}
		| additive_expression '+' multiplicative_expression				{$$ = new AddOp($1, $3);}
		| additive_expression '-' multiplicative_expression				{$$ = new SubOp($1, $3);}
		;

multiplicative_expression:
		cast_expression													{$$ = $1;}
		| multiplicative_expression '*' cast_expression					{$$ = new MultOp($1, $3);}
		| multiplicative_expression '/' cast_expression					{$$ = new DivOp($1, $3);}
		| multiplicative_expression '%' cast_expression					{$$ = new ModulusOp($1, $3);}
		;

cast_expression:
		unary_expression 												{$$ = $1;}	
		| '(' declaration_specifier_list ')' cast_expression			{$$ = new cast_expression($2, $4);}	//all leads to getting the variable name at one point
		;

unary_expression:  									//PAGE : 43
		postfix_expression												{$$ = $1;}
		| INC_OP unary_expression										{$$ = new PreIncOp($2);}
		| DEC_OP unary_expression										{$$ = new PreDecOp($2);}
		| '&' cast_expression											{$$ = new RefOp($2);}
		| '*' cast_expression											{$$ = new PtrOp($2);}
		| '+' cast_expression											{$$ = new UAddOp($2);}
		| '-' cast_expression											{$$ = new USubOp($2);}
		| '~' cast_expression											{$$ = new BitwiseNotOp($2);}
		| '!' cast_expression											{$$ = new LogicalNotOp($2);}
		| T_SIZEOF unary_expression										{$$ = new SizeOf($2);}
		| T_SIZEOF '(' declaration_specifier_list ')'					{$$ = new SizeOf($3);}
		;

postfix_expression: 
		primary_expression												{$$ = $1;}	//Page 39
		| postfix_expression '[' expression ']'  						{$$ = new array_call($1, $3);}//array calls TODO
		| postfix_expression '(' ')'									{$$ = new function_call($1, NULL);}
		| postfix_expression '(' argument_expression_list ')' 			{$$ = new function_call($1, $3);}//used for function calls most likely
		| postfix_expression '.' T_IDENTIFIER							{$$ = new DotMemberOp($1, *($3));} //turn into two classes one for pointer referencing, one for dot operator
		| postfix_expression PTR_OP T_IDENTIFIER						{$$ = new PtrMemberOp($1, *($3));}
		| postfix_expression INC_OP										{$$ = new PostIncOp($1);}
		| postfix_expression DEC_OP										{$$ = new PostDecOp($1);}
		;

primary_expression:
		T_IDENTIFIER													{$$ = new primary_expression(*($1));} //for now we can just return the value of the variable in an eval func,
		| constant														{$$ = new constantNode($1);}							//but we may need more constructors to differentiate different primary_expressions
		| STRING_LITERAL												{$$ = new stringNode(*($1));}
		| '(' expression ')'											{$$ = $2;}
		;

constant:
		INT_CONSTANT													{$$ = $1;}
		| FLOAT_CONSTANT												{$$ = $1;}
		| ENUMERATION_CONSTANT  // Do this later
		;

expression:
		assignment_expression 											{$$ = $1;}
		;
		
function_definition:
		declaration_specifier_list declarator declaration_list compound_statement
		| declaration_specifier_list declarator compound_statement						{$$ = new function_definition($1, $2, $3);}
		| declarator declaration_list compound_statement
		| declarator compound_statement													{$$ = new function_definition($1, $2);}
		;

declaration_list:
		declaration
		| declaration_list declaration
		;

parameter_type_list:			
		parameter_list									{$$ = $1;}
		;

parameter_list:
		parameter_declaration							{$$ = new parameter_list($1);}
		| parameter_list ',' parameter_declaration		{$$ = $1; $$->push($3);}
		;

parameter_declaration:
		declaration_specifier_list declarator			{$$ = new parameter_declaration($1, $2);}
		| declaration_specifier_list					{$$ = new parameter_declaration($1);}
		;

identifier_list:
		T_IDENTIFIER									{$$ = new identifier_list(*($1));}
		| identifier_list ',' T_IDENTIFIER				{$$ = $1; $$->push(*($3));}
		;

pointer:
		'*'
		| '*' pointer
		;

argument_expression_list:
		assignment_expression									{$$ = new argument_expression_list($1);}
		| argument_expression_list ',' assignment_expression	{$$ = $1; $$->push($3);}
		;


//statements

statement:
		labeled_statement						{$$ = $1;}
		| compound_statement					{$$ = $1;}
		| expression_statement					{$$ = $1;}
		| selection_statement					{$$ = $1;}
		| iteration_statement					{$$ = $1;}
		| jump_statement						{$$ = $1;}
		;

compound_statement:
		'{' '}'									{$$ = new compound_statement();}
		| '{' block_item_list '}'				{$$ = new compound_statement($2);}
		;

block_item_list:
		block_item								{$$ = new block_item_list($1);}
		| block_item_list block_item			{$$ = $1; $$->push($2);}
		;

block_item:
		declaration								{$$ = $1;}
		| statement								{$$ = $1;}
		;

expression_statement:
		';'										{$$ = new expression_statement();}
		| expression ';'						{$$ = new expression_statement($1);}
		;

selection_statement:
		T_IF '(' expression ')' statement T_ELSE statement  {$$ = new IfStatement($3, $5, $7);}//Page: 77
		| T_IF '(' expression ')' statement 				{$$ = new IfStatement($3, $5);}
		| T_SWITCH '(' expression ')' statement				{$$ = new SwitchStatement($3, $5);}
		;

iteration_statement:
		T_WHILE '(' expression ')' statement 											{$$ = new WhileStatement($3, $5);}			//page 78
		| T_DO statement T_WHILE '(' expression ')' ';'									{$$ = new DoStatement($2, $5);}
		| T_FOR '(' expression_statement expression_statement ')' statement				{$$ = new ForStatement($3, $4, $6);}
		| T_FOR '(' expression_statement expression_statement expression ')' statement	{$$ = new ForStatement($3, $4, $5, $7);}
		;	

labeled_statement:
		T_IDENTIFIER ':' statement						{$$ = new LabelStatement(*($1), $3);}
		| T_CASE constant_expression ':' statement		{$$ = new CaseStatement($2, $4);}
		| T_DEFAULT ':' statement						{$$ = new DefaultStatement($3);}
		;

jump_statement:
		T_CONTINUE ';'									{$$ = new ContinueStatement();}
		| T_BREAK ';'									{$$ = new BreakStatement();}
		| T_RETURN ';'									{$$ = new ReturnStatement();}
		| T_RETURN expression ';'						{$$ = new ReturnStatement($2);}
		;

%%

BranchNode *g_root;

Node *parseAST()
{
  	g_root=0;
  	yyparse();
  	return g_root;
}
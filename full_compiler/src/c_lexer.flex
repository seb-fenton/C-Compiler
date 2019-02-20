%option noyywrap
%x COMMENT_BLOCK
%x TYPEDEFS

%{
    #include "c_lexer.hpp"

    #include <sstream>
    #include <stdlib.h>

    extern void yyerror(const char *); 
    static void comment(void);
%}


IDENTIFIER          [_a-zA-Z][_a-zA-Z0-9]*

ASSIGNMENT_OPERATOR (("<<"|">>"|[*\/%+\-&^|])"="|"=")
INTEGERSUFFIX       ([uU][lL]|[lL][uU]|[uUlL])
FLOATINGSUFFIX      ([fFlL])
EXPONENTSUFFIX      ([Ee][+-]?[0-9]+)
BASE2EXSUFFIX       ([Pp][+-]?[0-9]+)

NONZERO             [1-9]
DEC                 [0-9]
OCTAL               [0-7]
HEX                 [a-fA-F0-9]
HEXPREFIX           (0[xX])
WHITESPACE          [ \t\r\n]+ 

%%


"/*"            { BEGIN(COMMENT_BLOCK); }
<COMMENT_BLOCK>"*/" { BEGIN(INITIAL); }
<COMMENT_BLOCK>\n   { }
<COMMENT_BLOCK>.    { }

"//"[^\n]*  {} //one-line comment

"void"		{ return T_VOID; }
"char"		{ return T_CHAR; }
"short"		{ return T_SHORT; }
"int"		{ return T_INT; }
"long"		{ return T_LONG; }
"float"		{ return T_FLOAT; }
"double"	{ return T_DOUBLE; }
"signed"	{ return T_SIGNED; }
"unsigned"	{ return T_UNSIGNED; }
"typedef"	{ BEGIN(TYPEDEFS);return T_TYPEDEF; }
"extern"	{ return T_EXTERN; }
"static"	{ return T_STATIC; }
"auto"		{ return T_AUTO; }
"register"	{ return T_REGISTER; }
"const"		{ return T_CONST; }
"volatile"	{ return T_VOLATILE; }
"struct"    { return T_STRUCT; }

"goto"		{ return T_GOTO; }
"break"		{ return T_BREAK; }
"continue"	{ return T_CONTINUE; }
"case"		{ return T_CASE; }
"default"	{ return T_DEFAULT; }
"switch"	{ return T_SWITCH; }
"if"	    { return T_IF; }
"else"		{ return T_ELSE; }
"return"	{ return T_RETURN; }
"while"		{ return T_WHILE; }
"do"		{ return T_DO; }
"for"		{ return T_FOR; }
"sizeof"    { return T_SIZEOF; }


{ASSIGNMENT_OPERATOR} { yylval.string = new std::string(yytext); return T_ASSIGNMENT_OP; }

">>"					{ return RIGHT_SHIFT_OP; }
"<<"					{ return LEFT_SHIFT_OP; }
"++"					{ return INC_OP; }
"--"					{ return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"			        { return AND_OP; }
"||"			        { return OR_OP; }
"<="			        { return LE_OP; }
">="			        { return GE_OP; }
"=="			        { return EQ_OP; }
"!="			        { return NE_OP; }
";"					    { return ';'; }
","					    { return ','; }
":"					    { return ':'; }
"="					    { return '='; }
"."					    { return '.'; }
"&"					    { return '&'; }
"!"					    { return '!'; }
"~"					    { return '~'; }
"-"					    { return '-'; }
"+"					    { return '+'; }
"*"					    { return '*'; }
"/"					    { return '/'; }
"%"					    { return '%'; }
"<"					    { return '<'; }
">"					    { return '>'; }
"^"					    { return '^'; }
"|"					    { return '|'; }
"?"					    { return '?'; }
"{"			            { return '}'; }
"}"     		        { return '{'; }
"("					    { return '('; }
")"					    { return ')'; }
"["				        { return '['; }
"]"			            { return ']'; } 

{IDENTIFIER}	{ yylval.string = new std::string(yytext); return T_IDENTIFIER; } //Store variable names in bindings
<TYPEDEFS>{IDENTIFIER} {yylval.string = new std::string(yytext); return T_IDENTIFIER; BEGIN(INITIAL); } //when making bindings store all typdefs in context

{HEXPREFIX}{HEX}+{INTEGERSUFFIX}?                               { return INT_CONSTANT; }
{NONZERO}{DEC}*{INTEGERSUFFIX}?                                 { return INT_CONSTANT; }
"0"{OCTAL}*{INTEGERSUFFIX}?                                     { return INT_CONSTANT; }

{DEC}+{EXPONENTSUFFIX}{FLOATINGSUFFIX}?                         {return FLOAT_CONSTANT;}
{DEC}*"."{DEC}+{EXPONENTSUFFIX}?{FLOATINGSUFFIX}?               {return FLOAT_CONSTANT;}
{DEC}+"."{EXPONENTSUFFIX}?{FLOATINGSUFFIX}?                     {return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}+{BASE2EXSUFFIX}{FLOATINGSUFFIX}?               {return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}*"."{HEX}+{BASE2EXSUFFIX}{FLOATINGSUFFIX}?      {return FLOAT_CONSTANT;}
{HEXPREFIX}{HEX}+"."{BASE2EXSUFFIX}{FLOATINGSUFFIX}?            {return FLOAT_CONSTANT;}


(\"[^\n\"]*\")                                                  {return STRING_LITERAL;}



{WHITESPACE} { ; }

%%






%option noyywrap
%{
    #include "c_lexer.hpp"

    #include <sstream>
    #include <stdlib.h>
%}


IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*

ASSIGNMENT_OPERATOR (("<<"|">>"|[*\/%+\-&^|])"="|"=")
INTEGERSUFFIX ([uU][lL]|[lL][uU]|[uUlL])

DECIMALCONSTANT ([1-9][0-9]*)
OCTALCONSTANT ([0][0-7]*)
HEXCONSTANT ([0][xX][0-9A-Fa-f]+)

WHITESPACE [ \t\r\n]+ 

%%



"void"		{ return T_VOID; }
"char"		{ return T_CHAR; }
"short"		{ return T_SHORT; }
"int"		{ return T_INT; }
"long"		{ return T_LONG; }
"float"		{ return T_FLOAT; }
"double"	{ return T_DOUBLE; }
"signed"	{ return T_SIGNED; }
"unsigned"	{ return T_UNSIGNED; }
"typedef"	{ return T_TYPEDEF; }
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

">>"					{ return RIGHT_OP; }
"<<"					{ return LEFT_OP; }
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
["{"|"<%"]				{ return '{'; }
["}"|"%>"]				{ return '}'; }
","					    { return ','; }
":"					    { return ':'; }
"="					    { return '='; }
"("					    { return '('; }
")"					    { return ')'; }
["["|"<:"]				{ return '['; }
["]"|":>"]				{ return ']'; }
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

{IDENTIFIER}	{ yylval.string = new std::string(yytext); return T_IDENTIFIER; }

({HEXCONSTANT}|{OCTALCONSTANT}|{DECIMALCONSTANT}){INTEGERSUFFIX}?	{ yylval.number = strtol(yytext, NULL, 0); return INT_CONSTANT; }


{WHITESPACE} { ; }





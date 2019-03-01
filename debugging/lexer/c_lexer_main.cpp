#include "c_lexer.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>



TokenValue yylval;


std::map<TokenType, std::string> tokenStr = {
    
    {None, "None"},
    {T_IDENTIFIER, "T_IDENTIFIER"},
    {TYPEDEF_NAME, "TYPEDEF_NAME"},

    //OPERATORS & SYMBOLS
    {T_ASSIGNMENT_OP, "T_ASSIGNMENT_OP"},
    {RIGHT_SHIFT_OP, "RIGHT_SHIFT_OP"},
    {LEFT_SHIFT_OP, "LEFT_SHIFT_OP"},
    {INC_OP, "INC_OP"},
    {DEC_OP, "INC_OP"},
    {PTR_OP, "PTR_OP"},
    {AND_OP, "AND_OP"},
    {OR_OP, "OR_OP"},
    {LE_OP, "LE_OP"},
    {GE_OP, "GE_OP"},
    {EQ_OP, "EQ_OP"},
    {NE_OP, "NE_OP"},
    

    //CONSTANTS

    {INT_CONSTANT, "INT_CONSTANT"},
    {FLOAT_CONSTANT, "FLOAT_CONSTANT"},
    {STRING_LITERAL, "STRING_LITERAL"},
    


    //TYPES

    {T_VOID, "T_VOID"},
    {T_CHAR, "T_CHAR"},
    {T_SHORT, "T_SHORT"},
    {T_INT, "T_INT"},
    {T_LONG, "T_LONG"},
    {T_FLOAT, "T_FLOAT"}, 
    {T_DOUBLE, "T_DOUBLE"},
    {T_SIGNED, "T_SIGNED"},
    {T_UNSIGNED, "T_UNSIGNED"},
    {T_TYPEDEF, "T_TYPEDEF"},
    {T_EXTERN, "T_EXTERN"},
    {T_STATIC, "T_STATIC"},
    {T_AUTO, "T_AUTO"},
    {T_REGISTER, "T_REGISTER"},
    {T_CONST, "T_CONST"},
    {T_VOLATILE, "T_VOLATILE"},
    {T_STRUCT, "T_STRUCT"},

    //FLOW-CONTROL

    {T_GOTO, "T_GOTO"},
    {T_BREAK, "T_BREAK"},
    {T_CONTINUE, "T_CONTINUE"},
    {T_CASE, "T_CASE"},
    {T_DEFAULT, "T_DEFAULT"},
    {T_SWITCH, "T_SWITCH"},
    {T_IF, "T_IF"},
    {T_ELSE, "T_ELSE"},
    {T_RETURN, "T_RETURN"},
    {T_WHILE, "T_WHILE"},
    {T_DO, "T_DO"},
    {T_FOR, "T_FOR"},
    {T_SIZEOF, "T_SIZEOF"}
    
};


int main()
{
    TokenType type;
    while((type=(TokenType)yylex())){
        if(tokenStr.find(type) != tokenStr.end()){
            std::cout<< tokenStr[type] << std::endl;
        }else{
            std::cout << (char)type << std::endl;
        }

    }


    return 0;
}

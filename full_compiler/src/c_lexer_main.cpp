#include "c_lexer.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>



TokenValue yylval;


std::map<TokenType, std::string> tokenStr = {
    {T_INT, "T_INT"},
    {T_DOUBLE, "T_DOUBLE"},
    {TYPEDEF_NAME, "TYPEDEF_NAME"},
    {T_TYPEDEF, "T_TYPEDEF"},
    {T_IDENTIFIER, "T_IDENTIFIER"},
    {T_LONG, "T_LONG"},
    {INT_CONSTANT, "INT_CONSTANT"},
    {FLOAT_CONSTANT, "FLOAT_CONSTANT"},
    {T_DOUBLE, "T_DOUBLE"}
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

#include "c_lexer.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>



TokenValue yylval;

std::string print_type(TokenType type) {
    switch(type) {
        case T_INT: return "T_INT: ";
        case TYPEDEF_NAME: return "TYPEDEF_NAME: ";
        case T_TYPEDEF: return "T_TYPEDEF: ";
        case T_IDENTIFIER: return "T_IDENTIFIER: ";
        case T_LONG: return "T_LONG: ";
        default: return "";
    }
}

int main()
{
    TokenType type;
    while((type=(TokenType)yylex())){
        std::cout << print_type(type) <<std::endl;
    }


    return 0;
}

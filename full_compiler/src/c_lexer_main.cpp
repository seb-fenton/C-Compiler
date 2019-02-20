#include "c_lexer.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>



// Define the instance of the variable that is declared in the histogram.hpp header
TokenValue yylval;

int main()
{
    while(1){
        TokenType type=(TokenType)yylex();

        if(type==None){
            break; // No more tokens

        }else if(type==T_VOID){
 
            std::cout<<"COMMENT FOUND" << std::endl;    
        }
    }


    return 0;
}

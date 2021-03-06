#ifndef c_lexer_hpp
#define c_lexer_hpp


#include <string>
#include <vector>
#include <map>
#include <algorithm>

enum TokenType{
    None,
    T_IDENTIFIER,
    TYPEDEF_NAME,

    //OPERATORS & SYMBOLS
    T_ASSIGNMENT_OP,
    RIGHT_SHIFT_OP,
    LEFT_SHIFT_OP,
    INC_OP,
    DEC_OP,
    PTR_OP,
    AND_OP,
    OR_OP,
    LE_OP,
    GE_OP,
    EQ_OP,
    NE_OP,
    

    //CONSTANTS

    INT_CONSTANT,
    FLOAT_CONSTANT,
    STRING_LITERAL,
    


    //TYPES

    T_VOID,
    T_CHAR,
    T_SHORT,
    T_INT,
    T_LONG,
    T_FLOAT,
    T_DOUBLE,
    T_SIGNED,
    T_UNSIGNED,
    T_TYPEDEF,
    T_EXTERN,
    T_STATIC,
    T_AUTO,
    T_REGISTER,
    T_CONST,
    T_VOLATILE,
    T_STRUCT,

    //FLOW-CONTROL

    T_GOTO,
    T_BREAK,
    T_CONTINUE,
    T_CASE,
    T_DEFAULT,
    T_SWITCH,
    T_IF,
    T_ELSE,
    T_RETURN,
    T_WHILE,
    T_DO,
    T_FOR,
    T_SIZEOF,

    

};

union TokenValue{
    double number;
    std::string *string;
};



struct context{
    std::vector<std::vector<std::string>> type_defs = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;

    void incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

    void decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }
};



static context ctx;

extern TokenValue yylval;
extern int yylex();

#endif
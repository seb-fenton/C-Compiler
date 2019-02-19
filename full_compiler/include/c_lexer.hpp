#ifndef c_lexer_hpp
#define c_lexer_hpp


#include <string>

enum TokenType{
    None,
    T_IDENTIFIER,

    //OPERATORS
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
    std::string string;
};

extern TokenValue yylval;
extern int yylex();

#endif
#include "context.hpp"

//---------------------------------------------//
//--------------Lexer_Context------------------//
//---------------------------------------------//


void lexContext::incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

void lexContext::decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }

//---------------------------------------------//
//--------------Python_Context-----------------//
//---------------------------------------------//

void pyContext::incScope(){
        scopeLevel++;
    }

void pyContext::decScope(){
        scopeLevel--;
    }

//---------------------------------------------//
//----------------Vardata_Struct---------------//
//---------------------------------------------//



//---------------------------------------------//
//----------------Scope_Struct-----------------//
//---------------------------------------------//

scope::scope(std::map<std::string, varData> _bindings): bindings(_bindings){}

//---------------------------------------------//
//----------------Compiler_Context-------------//
//---------------------------------------------//

void compilerContext::incScope(){
        scopes.push_back(scope(scopes[scopeLevel].bindings)); //when you enter a new scope, take the old scope bindings and put them into the new one
        scopeLevel++;
    }

void compilerContext::functionCall(){
        scopes.push_back(globalVars); //when a function call occurs, only give it the global variables and not the previous scopes bindings
        scopeLevel++;
    }

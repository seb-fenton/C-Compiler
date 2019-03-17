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
//----------------tempDecl_Struct--------------//
//---------------------------------------------//

void DeclaratorContext::purge(){
    id.clear();
    initliased = false;
    int size = 0;
    offset = 0;
    elements = 1;
    isArray = false;
}

void DeclaratorContext::nextElement(){
    id.clear();
    initliased = false;
    offset = 0;
    elements = 1;
    isArray = false;
}

int DeclaratorContext::totSize(){
    return size * elements;
}

//---------------------------------------------//
//----------------Vardata_Struct---------------//
//---------------------------------------------//

varData::varData(int _offset, int _elements, bool _isArray): offset(_offset), elements(_elements), isArray(_isArray){}

//---------------------------------------------//
//----------------Scope_Struct-----------------//
//---------------------------------------------//

scope::scope(std::map<std::string, varData> _bindings, int _stackOffset): bindings(_bindings), stackOffset(_stackOffset){}

void scope::addToBindings(std::string id, int offset, int elements, bool isArray){
    bindings[id] = varData(offset, elements, isArray);
}

//---------------------------------------------//
//----------------funcScope_Struct-------------//
//---------------------------------------------//

funcScope::funcScope(std::ostream& stream){}

void funcScope::incScope(){
    if(scopes.size() == 0){
        scopes.push_back(scope(parameters, memUsed));
        scopeLevel++;
    }else{
        scopes.push_back(scope(scopes[scopeLevel-1].bindings, memUsed)); //when you enter a new scope, take the old scope bindings and put them into the new one
        scopeLevel++;
    }
}

void funcScope::decScope(std::ostream& stream){
    int scopeMem = memUsed - scopes.back().stackOffset; //should give the amount of memory the scope has used
    stream << "addiu $sp, $sp, " << scopeMem << std::endl; //positive value moves up the stack

}

//li $5, x
//lw $2, 0($5)

//---------------------------------------------//
//----------------Compiler_Context-------------//
//---------------------------------------------//

void compilerContext::setup(std::ostream& stream){
    addToStack(8, stream);
    stream << "sw $fp, 0($sp)" << std::endl;
    stream << "sw $31, 4($sp)" << std::endl;
    
}

void compilerContext::endFunc(std::ostream& stream){
    stream << "move $sp, $fp" << std::endl; //$fp needs to be reset in func call.
    stream << "lw $31, -4($sp) \nnop" << std::endl; 
    stream << "j $31"<< std::endl; 
    stream << std::endl;
    stream << std::endl;  
    functions.pop_back();
}

std::map<std::string, varData>* compilerContext::currentBindings(){
    return &functions.back().scopes.back().bindings;
}

scope* compilerContext::currentScope(){
    return &functions.back().scopes.back();
}

funcScope* compilerContext::currentFunc(){
    return &functions.back();
}

void compilerContext::addToStack(int size, std::ostream& stream){
    if(functions.size()> 0){
        stream << "addiu $sp, $sp, " << -size << std::endl;
        functions.back().memUsed += size;
    }
}

std::string compilerContext::generateUniqueLabel(){
    std::stringstream temp;
    temp.str("label");
    temp << labelGen;

    labelGen++;

    return temp.str();
}
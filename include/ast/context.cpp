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

varData::varData(int _offset, int _elements): offset(_offset), elements(_elements){}

//---------------------------------------------//
//----------------Scope_Struct-----------------//
//---------------------------------------------//

scope::scope(std::map<std::string, varData>& _bindings, int _stackOffset): bindings(_bindings), stackOffset(_stackOffset){}

void scope::addToBindings(std::string id, int offset, int elements){
    bindings[id] = varData(offset, elements);
}

//---------------------------------------------//
//----------------funcScope_Struct-------------//
//---------------------------------------------//

funcScope::funcScope(std::ostream& stream){}

void funcScope::incScope(){
    scopes.push_back(scope(scopes[scopeLevel].bindings, memUsed)); //when you enter a new scope, take the old scope bindings and put them into the new one
    scopeLevel++;
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

void compilerContext::newFunc(std::ostream& stream){
    addToStack(8, stream);
    stream << "sw $fp, 0($sp)" << std::endl;
    stream << "sw $31, 4($sp)" << std::endl;
    functions.push_back(funcScope(stream));
    
}

void compilerContext::endFunc(std::ostream& stream){
    stream << "move $sp, $fp" << std::endl; //$fp needs to be reset in func call.
    stream << "lw $31, -4($sp)" << std::endl; 
    stream << "j $31"<< std::endl; 
    functions.pop_back();
}

std::map<std::string, varData>* compilerContext::currentBindings(){
    return &functions.back().scopes.back().bindings;
}

scope* compilerContext::currentScope(){
    return &functions.back().scopes.back();
}

void compilerContext::addToStack(int size, std::ostream& stream){
    stream << "addiu $sp, $sp, " << -size << std::endl;
    if(functions.size()> 0){
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
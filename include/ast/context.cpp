#include "context.hpp"
#include "ast_base_nodes.hpp"

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
    initOffset = 0;
}

void DeclaratorContext::nextElement(){
    id.clear();
    initliased = false;
    offset = 0;
    elements = 1;
    isArray = false;
    initOffset = 0;
}

int DeclaratorContext::totSize(){
    return size * elements;
}

//---------------------------------------------//
//----------------Vardata_Struct---------------//
//---------------------------------------------//

varData::varData(bool _typedef, int _type): type(_type), isTypdef(_typedef){}

varData::varData(int _offset, int _elements, int _size, bool _global, bool _pointer): offset(_offset), elements(_elements), size(_size), global(_global), isPointer(_pointer){}

//---------------------------------------------//
//----------------EnumContext------------------//
//---------------------------------------------//

void EnumContext::reset(){
    nextVal = 0;
}

//---------------------------------------------//
//----------------Scope_Struct-----------------//
//---------------------------------------------//

scope::scope(std::map<std::string, varData> _bindings, int _stackOffset): bindings(_bindings), stackOffset(_stackOffset){}

void scope::addToBindings(std::string id, int offset, int elements, int size, bool global, bool pointer){
    bindings[id] = varData(offset, elements, size, global, pointer);
}

//---------------------------------------------//
//----------------funcScope_Struct-------------//
//---------------------------------------------//

funcScope::funcScope(std::ostream& stream, std::map<std::string, varData> _globalVars): globalVars(_globalVars){}

void funcScope::incScope(){
    if(scopes.size() == 0){
        scopes.push_back(scope(parameters, memUsed));
        scopes.back().bindings.insert(globalVars.begin(), globalVars.end());
        scopeLevel++;
    }else{
        scopes.push_back(scopes.back()); //when you enter a new scope, take the old scope bindings and put them into the new one
        scopes.back().stackOffset = memUsed;
        scopeLevel++;
    }
}

void funcScope::decScope(std::ostream& stream){
    int scopeMem = memUsed - scopes.back().stackOffset; //should give the amount of memory the scope has used
    stream << "addiu $sp, $sp, " << scopeMem << std::endl; //positive value moves up the stack
    memUsed -= scopeMem;
    scopes.pop_back();
}   


//---------------------------------------------//
//----------------Compiler_Context-------------//
//---------------------------------------------//

void compilerContext::setup(std::ostream& stream){
    addToStack(8, stream);
    stream << "sw $fp, 0($sp)" << std::endl;
    stream << "sw $31, 4($sp)" << std::endl;
}

void compilerContext::endFunc(std::ostream& stream){
    stream << "lw $31, "<<  (functions.back().memUsed - 4) << "($sp) \nnop" << std::endl; 
    stream << "addiu $sp, $sp, " << functions.back().memUsed <<std::endl; //$fp needs to be reset in func call.
    stream << "jr $31 \nnop"<< std::endl; 
    stream << std::endl; 
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

void compilerContext::removeFromStack(int size, std::ostream& stream){
    if(functions.size()> 0){
        stream << "addiu $sp, $sp, " << size << std::endl;
        functions.back().memUsed -= size;
    }
}

std::string compilerContext::generateUniqueLabel(){
    std::stringstream temp;
    temp.str("label");
    temp << labelGen;

    labelGen++;

    return temp.str();
}

std::string compilerContext::generateLabel(std::string s){
    s = s + std::to_string(labelGen);
    labelGen++;
    return s;
}
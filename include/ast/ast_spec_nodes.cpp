#include "ast_spec_nodes.hpp"


//declaration

declarator::declarator(NodePtr direct, NodePtr pointer): directDeclarator(direct), pointerPtr(pointer) {}
declarator::declarator(NodePtr direct): directDeclarator(direct) {}


void declaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(specifier_list != NULL){specifier_list->printMips(ctx, stream);}
    if(declarator_list != NULL){declarator_list->printMips(ctx, stream);}
    ctx.tempDeclarator.purge();
}


//declaration_specifiers

declaration_specifiers::declaration_specifiers(std::string s): type_name(s) {}

void declaration_specifiers::printMips(compilerContext& ctx, std::ostream& stream){
    if(type_name == "int"){
        ctx.tempDeclarator.size = 4; //size in bytes
    }
}


//init_declarator

init_declarator::init_declarator(NodePtr declarator, NodePtr initial): declaratorPtr(declarator), initialiserPtr(initial) {}
init_declarator::init_declarator(NodePtr declarator): declaratorPtr(declarator) {}

void init_declarator::printMips(compilerContext& ctx, std::ostream& stream){
    //need to do something different for arrays
    if(declaratorPtr != NULL){declaratorPtr->printMips(ctx, stream);}
    ctx.addToStack(ctx.tempDeclarator.totSize(), stream);
    ctx.tempDeclarator.offset = ctx.functions.back().memUsed; //setting the offset
    if(initialiserPtr != NULL){
        initialiserPtr->printMips(ctx, stream);
        stream << "sw $2, 0($sp)" << std::endl;   
    }
    ctx.currentScope()->addToBindings(ctx.tempDeclarator.id, ctx.tempDeclarator.offset, ctx.tempDeclarator.elements, ctx.tempDeclarator.isArray);
}


//direct_declarator

direct_declarator::direct_declarator(std::string s): identifier(s) {}

void direct_declarator::printMips(compilerContext& ctx, std::ostream& stream){
    if(!ctx.funcDef){ctx.tempDeclarator.id = identifier;}
    else{
        stream << identifier << ":" << std::endl;
    }
}


void initialiser::printMips(compilerContext& ctx, std::ostream& stream){
    if(assignment != NULL){assignment->printMips(ctx, stream);}
}


//initialiser

initialiser::initialiser(ExpPtr a): assignment(a) {}

//ArrayDeclaration

void ArrayDeclaration::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.tempDeclarator.isArray = true;
    if(size != NULL){
    //ctx.tempDeclarator.elements = size->eval(); need to make eval function to calculate size of arrays at compile time
    }
    else{
        ctx.tempDeclarator.elements = 0; //represents empty array
    }
}


//function definition
void function_definition::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.funcDef = true;
    ctx.functions.push_back(funcScope(stream)); //creates function
    if(name != NULL){name->printMips(ctx, stream);} //prints a label
    ctx.setup(stream);
    for(int i = 0; i < ctx.currentFunc()->parameters.size(); i++){
        stream << "sw $" << (i+4) << ", " << (i*4) << "($fp)" << std::endl;  
    }
    //if(type != NULL){type->printMips(ctx, stream);}
    ctx.funcDef = false;
    if(statement != NULL){statement->printMips(ctx, stream);} //prints actual statement
    ctx.endFunc(stream);
}

//FunctionDeclaration
void FunctionDeclaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(funcName != NULL){funcName->printMips(ctx, stream);}
    if(argList != NULL){argList->printMips(ctx, stream);}
}

void parameter_declaration::printMips(compilerContext& ctx, std::ostream& stream){
    bool temp = ctx.funcDef;
    ctx.funcDef = false;
    if(specifiers != NULL){specifiers->printMips(ctx, stream);}
    if(dec != NULL){dec->printMips(ctx, stream);}
    ctx.tempDeclarator.offset = -(ctx.currentFunc()->parameters.size()*4);
    ctx.currentFunc()->parameters[ctx.tempDeclarator.id] = varData(ctx.tempDeclarator.offset, ctx.tempDeclarator.elements, ctx.tempDeclarator.isArray);
    ctx.tempDeclarator.purge();
    ctx.funcDef = temp;
    
}


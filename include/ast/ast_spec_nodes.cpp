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
    if(declaratorPtr != NULL){declaratorPtr->printMips(ctx, stream);}
    ctx.addToStack(ctx.tempDeclarator.totSize(), stream);
    ctx.tempDeclarator.offset = ctx.functions.back().memUsed; //setting the offset
    if(initialiserPtr != NULL){
        initialiserPtr->printMips(ctx, stream);
        stream << "sw $2, 0($sp)" << std::endl;   
    }
}


//direct_declarator

direct_declarator::direct_declarator(std::string s): identifier(s) {}

void direct_declarator::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.tempDeclarator.id = identifier;
}


void initialiser::printMips(compilerContext& ctx, std::ostream& stream){
    if(assignment != NULL){assignment->printMips(ctx, stream);}
}


//initialiser

initialiser::initialiser(ExpPtr a): assignment(a) {}
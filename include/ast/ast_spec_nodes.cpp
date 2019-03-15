#include "ast_spec_nodes.hpp"

void declaration::printMips(compilerContext& ctx){
    if(specifier_list != NULL){specifier_list->printMips(ctx);}
    if(declarator_list != NULL){declarator_list->printMips(ctx);}
    ctx.tempDeclarator.purge();
}

void declaration_specifiers::printMips(compilerContext& ctx){
    if(type_name == "int"){
        ctx.tempDeclarator.size = 4; //size in bytes
    }
}
#include "ast_spec_nodes.hpp"

void declaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(specifier_list != NULL){specifier_list->printMips(ctx, stream);}
    if(declarator_list != NULL){declarator_list->printMips(ctx, stream);}
    ctx.tempDeclarator.purge();
}

void declaration_specifiers::printMips(compilerContext& ctx, std::ostream& stream){
    if(type_name == "int"){
        ctx.tempDeclarator.size = 4; //size in bytes
    }
}
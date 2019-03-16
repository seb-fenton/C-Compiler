#include "ast_spec_nodes.hpp"

void declaration::printMips(compilerContext& ctx, std::ostream& os){
    if(specifier_list != NULL){specifier_list->printMips(ctx, os);}
    if(declarator_list != NULL){declarator_list->printMips(ctx, os);}
    ctx.tempDeclarator.purge();
}

void declaration_specifiers::printMips(compilerContext& ctx, std::ostream& os){
    if(type_name == "int"){
        ctx.tempDeclarator.size = 4; //size in bytes
    }
}

void init_declarator::printMips(compilerContext& ctx, std::ostream& os){
    if(declaratorPtr != NULL){declaratorPtr->printMips(ctx, os);}
    ctx.addToStack(ctx.tempDeclarator.totSize(), os);
    ctx.tempDeclarator.offset = ctx.functions.back().memUsed; //setting the offset
    if(initialiserPtr != NULL){
        initialiserPtr->printMips(ctx, os);
        os << "sw $2, 0($sp)" << std::endl;   
    }
}

void direct_declarator::printMips(compilerContext& ctx, std::ostream& os){
    ctx.tempDeclarator.id = identifier;
}


void initialiser::printMips(compilerContext& ctx, std::ostream& os){
    if(assignment != NULL){assignment->printMips(ctx, os);}
}
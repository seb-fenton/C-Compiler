#include "ast_branch_nodes.hpp"
#include "context.hpp"

void declaration_specifier_list::printMips(compilerContext& ctx){
    for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printMips(ctx);
	}
}

void init_declarator_list::printMips(compilerContext& ctx){
    for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printMips(ctx);
            ctx.tempDeclarator.nextElement();
	}
}
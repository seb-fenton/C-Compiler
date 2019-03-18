#include "ast_statement_nodes.hpp"

//Compound Statement
void compound_statement::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.currentFunc()->incScope();
    if(block_list != NULL){block_list->printMips(ctx, stream);}
    ctx.currentFunc()->decScope(stream);
}

//Block Item List
void block_item_list::printMips(compilerContext& ctx, std::ostream& stream){
    for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
	}
}

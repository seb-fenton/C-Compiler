#include "ast_branch_nodes.hpp"
#include "context.hpp"


//declaration_sepcifier_list 

declaration_specifier_list::declaration_specifier_list(NodePtr p){branches.push_back(p);}
declaration_specifier_list::~declaration_specifier_list(){}


void declaration_specifier_list::printMips(compilerContext& ctx, std::ostream& stream){
    for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printMips(ctx, stream);
	}
}


//init_declarator

init_declarator_list::init_declarator_list(NodePtr p){branches.push_back(p);} //branches contain init_declarator nodes

void init_declarator_list::printMips(compilerContext& ctx, std::ostream& stream){
    for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
        ctx.tempDeclarator.nextElement();
	}
}


//argument_declarator_list

argument_expression_list::argument_expression_list(NodePtr p){branches.push_back(p);}

//parameter list

void parameter_list::printMips(compilerContext& ctx, std::ostream& stream){
	for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
	}
}
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

void argument_expression_list::printMips(compilerContext& ctx, std::ostream& stream){
	ctx.addToStack((int)branches.size()*4, stream);
	
	for(int i = branches.size() - 1; i >= 0; i--){
		if(i < 4){
			branches[i]->printMips(ctx, stream);
			stream << "move $" << i + 4  << ", $2" << std::endl;
		} else{
			branches[i]->printMips(ctx, stream);
			stream << "sw $2, 0($sp)" << std::endl;
		}
	}
	 //retrieve prev args
}
//parameter list

void parameter_list::printMips(compilerContext& ctx, std::ostream& stream){
	for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
	}
}

//enumarator_list
void enumerator_list::printMips(compilerContext& ctx, std::ostream& stream){
	for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
	}
	ctx.enumCtx.reset();
}


void initialiser_list::printMips(compilerContext& ctx, std::ostream& stream){
	for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
		ctx.tempDeclarator.initOffset += 4;
	}
}
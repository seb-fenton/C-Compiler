#ifndef AST_BRANCH_NODES_HPP
#define AST_BRANCH_NODES_HPP

#include "ast_base_nodes.hpp"
#include "context.hpp"
//---------------------------------------------//
//------------BranchNodeS---------------------//
//        Nodes with branches in them          //
//---------------------------------------------//


class translation_unit : public BranchNode{
	public:
	translation_unit(NodePtr p){branches.push_back(p);}
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Translation Unit" <<std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	~translation_unit() {}
	void printPy(pyContext& context, std::ostream& stream){
        for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printPy(context, stream);
			stream << std::endl;
		}
		//tabprint(context.scopeLevel, stream);  - redundant
		stream << "# Boilerplate" << std::endl;
		stream << "if __name__ == \"__main__\":" << std::endl;
		context.incScope();
		tabprint(context.scopeLevel, stream);
		stream << "import sys" << std::endl;
		tabprint(context.scopeLevel, stream);
		stream << "ret=main()" << std::endl;
		tabprint(context.scopeLevel, stream);
		stream << "sys.exit(ret)";
  }
	void printMips(compilerContext& ctx, std::ostream& os){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printMips(ctx, os);
		}
	}
};

class declaration_specifier_list : public BranchNode{
	public:
	declaration_specifier_list(NodePtr p){branches.push_back(p);}
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Declaration Specifier List" << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void printMips(compilerContext& ctx, std::ostream& os);
	~declaration_specifier_list() {}
};

class init_declarator_list : public BranchNode{
	public:
	init_declarator_list(NodePtr p){branches.push_back(p);} //branches contain init_declarator nodes
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Init Declarator List" << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	void printMips(compilerContext& ctx, std::ostream& os);
	~init_declarator_list() {}
};

class argument_expression_list : public BranchNode{
	public:
	argument_expression_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		std::cout<< "Arguments: [";
		for(int i = 0; i < (int)branches.size(); i++){
			std::cout << i+1 << ": ";
			branches[i]->printTree(n);
			if(i < (int)branches.size()-1){std::cout<< ", ";}
		}
		std::cout << "]";
	}
	void printPy(pyContext& context, std::ostream& stream){
		for(int i = 0; i < branches.size(); i++){
			branches[i]->printPy(context, stream);
			if(i != branches.size()-1) stream << ",";
		}
	}
};

class parameter_list : public BranchNode{
	public:
	parameter_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Parameters: " << std::endl;
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n+1);
		}
	}
	void printPy(pyContext& context, std::ostream& stream){
		for(int i = 0; i < branches.size(); i++){
			branches[i]->printPy(context, stream);
			if(i != branches.size()-1) stream << ",";
		}
	}
};

class identifier_list : public Node{
	public:
	std::vector<std::string> identifiers;
	identifier_list(std::string id){identifiers.push_back(id);}
	void push(std::string id){identifiers.push_back(id);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Idenitifers: ";
		for(int i = 0; i < (int)identifiers.size(); i++){
			std::cout<< identifiers[i] << " " ;
		}
		std::cout << std::endl;
	}
};

class initialiser_list : public BranchNode{
	public:
	initialiser_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
};

class struct_declaration_list : public BranchNode {
	public:
	struct_declaration_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}

};

class struct_declarator_list : public BranchNode{
	public:
	struct_declarator_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
};

class declaration_list : public BranchNode{
	public:
	declaration_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
};

class enumerator_list : public BranchNode{
	public:
	enumerator_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < (int)branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
};



#endif
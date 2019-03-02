#ifndef AST_BRANCH_NODES_HPP
#define AST_BRANCH_NODES_HPP

#include "ast_base_nodes.hpp"

//---------------------------------------------//
//------------BranchNodeS---------------------//
//        Nodes with branches in them          //
//---------------------------------------------//

class BranchNode : public Node{
    public:
		std::vector<NodePtr> branches;
		
		void push(NodePtr n) {
			branches.push_back(n);
		}

		virtual ~BranchNode()  {}
};

class translation_unit : public BranchNode{
	public:
	translation_unit(NodePtr p){branches.push_back(p);}
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Translation Unit" <<std::endl;
		for(int i = 0; i < branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	~translation_unit() {}
};

class declaration_specifier_list : public BranchNode{
	public:
	declaration_specifier_list(NodePtr p){branches.push_back(p);}
	void printTree(int n) {
		/*for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}*/
		//std::cout << "Declaration Specifier List" << std::endl;
		for(int i = 0; i < branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
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
		for(int i = 0; i < branches.size(); i++){
			branches[i]->printTree(n);
		}
	}
	~init_declarator_list() {}
};



//---------------------------------------------//
//------------Spec_Nodes-----------------------//
//           Nodes with specific pointers      //
//---------------------------------------------//


class declaration : public Node{
	public:
	NodePtr specifier_list = NULL , declarator_list = NULL;

	declaration(NodePtr spec, NodePtr dec): specifier_list(spec), declarator_list(dec) {}
	declaration(NodePtr spec): specifier_list(spec) {}

	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declaration" << std::endl;
		if(specifier_list != NULL){specifier_list->printTree(n+1);}
		if(declarator_list != NULL)declarator_list->printTree(n+1);
	}
};

class declaration_specifiers : public Node{
	public:
	std::string type_name;
	declaration_specifiers(std::string s): type_name(s) {}

	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declaration Specifier: " << type_name << std::endl;

	}
};

class init_declarator : public Node{
	public:
	NodePtr declaratorPtr = NULL , initialiserPtr = NULL;

	init_declarator(NodePtr declarator, NodePtr initial): declaratorPtr(declarator), initialiserPtr(initial) {}
	init_declarator(NodePtr declarator): declaratorPtr(declarator) {}

	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Init Declarator" << std::endl;
		if(declaratorPtr != NULL){declaratorPtr->printTree(n+1);}
		if(initialiserPtr != NULL){initialiserPtr->printTree(n+1);}
	}
};

class declarator : public Node{
	public:
	NodePtr directDeclarator = NULL , pointerPtr = NULL;

	declarator(NodePtr direct, NodePtr pointer): directDeclarator(direct), pointerPtr(pointer) {}
	declarator(NodePtr direct): directDeclarator(direct) {}

	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declarator" << std::endl;
		if(directDeclarator != NULL){directDeclarator->printTree(n+1);}
		if(pointerPtr != NULL){pointerPtr->printTree(n+1);}
	}
};

class direct_declarator : public Node{
	public:
	std::string identifier;
	//TODO: Need to adapt so that it has functions which turn this class into array declarators and function calls
	direct_declarator(std::string s): identifier(s) {}

	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Direct Declarator: " << identifier << std::endl;
	}
};

class initialiser : public Node{
	public:
	ExpPtr assignment;
	initialiser(ExpPtr a): assignment(a) {}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Initialiser: ";
		assignment->printTree(n);
		std::cout << std::endl;
	}
};


#endif
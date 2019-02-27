#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>




class Node;
typedef Node* NodePtr;


//----------BASE_CLASS---------//
class Node{

	public:
		virtual ~Node()  {}
		virtual void printTree(int n);
};


//---------------------------------------------//
//------------BRANCH_NODES---------------------//
//        Nodes with branches in them          //
//---------------------------------------------//

class Branch_Node : public Node{
    public:
		std::vector<NodePtr> branches;
		
		void push(NodePtr n){
			branches.push_back(n);
		}

		virtual ~Branch_Node()  {}
};

class translation_unit : public Branch_Node{
	public:
	translation_unit(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Translation Unit" << std::endl;
		for(int i; i < branches.size(); i++){
			branches[i]->printTree(++n);
		}
	}
	~translation_unit() {}
};

class declaration_specifier_list : public Branch_Node{
	public:
	declaration_specifier_list(NodePtr p){branches.push_back(p);}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declaration Specifier List" << std::endl;
		for(int i; i < branches.size(); i++){
			branches[i]->printTree(++n);
		}
	}
	~declaration_specifier_list() {}
};

class init_declarator_list : public Branch_Node{
	public:
	init_declarator_list(NodePtr p){branches.push_back(p);} //branches contain init_declarator nodes
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Init Declarator List" << std::endl;
		for(int i; i < branches.size(); i++){
			branches[i]->printTree(++n);
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

	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declaration" << std::endl;
		if(specifier_list != NULL){specifier_list->printTree(++n);}
		if(declarator_list != NULL)declarator_list->printTree(++n);
	}
};

class declaration_specifier : public Node{
	public:
	std::string type_name;
	declaration_specifier(std::string s): type_name(s) {}

	void printTree(int n){
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

	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declaration" << std::endl;
		if(declaratorPtr != NULL){declaratorPtr->printTree(++n);}
		if(initialiserPtr != NULL){initialiserPtr->printTree(++n);}
	}
};

class declarator : public Node{
	public:
	NodePtr directDeclarator = NULL , pointerPtr = NULL;

	declarator(NodePtr direct, NodePtr pointer): directDeclarator(direct), pointerPtr(pointer) {}
	declarator(NodePtr direct): directDeclarator(direct) {}

	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Declarator" << std::endl;
		if(directDeclarator != NULL){directDeclarator->printTree(++n);}
		if(pointerPtr != NULL){pointerPtr->printTree(++n);}
	}
};

class direct_declarator : public Node{
	public:
	std::string identifier;
	//TODO: Need to apapt so that it has functions which turn this class into array declarators and function calls
	direct_declarator(std::string s): identifier(s) {}

	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Direct Declarator: " << identifier << std::endl;
	}
};



//---------------------------------------------//
//------------EXPRESSION-----------------------//
//           Expression Nodes                  //
//---------------------------------------------//

class primary_expression : public Node{
	std::string identifier;
	primary_expression(std::string s): identifier(s) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Primary Expression: " << identifier << std::endl;
	}
};

#endif
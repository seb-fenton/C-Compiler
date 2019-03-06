#ifndef AST_BRANCH_NODES_HPP
#define AST_BRANCH_NODES_HPP

#include "ast_base_nodes.hpp"

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
	void printPy(){
		std::cout << type_name;
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
	void printPy(){
		declaratorPtr->printPy();
		std::cout << "=";
		initialiserPtr->printPy();	
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
	void printPy(){
		std::cout << identifier;	
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


class function_definition : public Node{
	public:
	NodePtr type = NULL, name = NULL, statement = NULL, decList = NULL;
	function_definition(NodePtr specifiers, NodePtr varName, NodePtr _statement): type(specifiers), name(varName), statement(_statement) {}
	function_definition(NodePtr varName, NodePtr _statement):name(varName), statement(_statement) {
		type = new declaration_specifier_list(new declaration_specifiers("int"));
	}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Function Definition" << std::endl;
		if(type != NULL){ type->printTree(n+1);}
		if(name != NULL){ name->printTree(n+1);}
		if(decList != NULL){decList->printTree(n+1);}
		if(statement != NULL){statement->printTree(n+1);}
		
	}
};

class ArrayDeclaration : public Node{
	public:
	NodePtr varName = NULL;
	ExpPtr size = NULL;
	ArrayDeclaration(NodePtr _varName): varName(_varName) {}
	ArrayDeclaration(NodePtr _varName, ExpPtr _size): varName(_varName), size(_size) {}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "ArrayDeclaration" << std::endl;
		if(varName != NULL){varName->printTree(n+1);}
		if(size != NULL){
			for(int i = 0; i < n+1; i++){
				std::cout<< "|\t" ;
			}	
			std::cout<< "Size: ";size->printTree(n);
			std::cout << std::endl;
		}
	}
};

class parameter_declaration : public Node{
	public:
	NodePtr specifiers = NULL, dec = NULL;
	parameter_declaration(NodePtr _specifiers, NodePtr _dec): specifiers(_specifiers), dec(_dec) {}
	parameter_declaration(NodePtr _specifiers): specifiers(_specifiers) {}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Parameter" << std::endl;
		if(specifiers != NULL){specifiers->printTree(n+1);}
		if(dec != NULL){dec->printTree(n+1);}
	}

};

class FunctionDeclaration : public Node{
	public:
	NodePtr funcName = NULL, argList = NULL;
	FunctionDeclaration(NodePtr _funcName, NodePtr _argList): funcName(_funcName), argList(_argList) {}
	FunctionDeclaration(NodePtr _funcName): funcName(_funcName) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Function Declaration:" << std::endl;
		if(funcName != NULL){funcName->printTree(n+1);}
		if(argList != NULL){argList->printTree(n+1);}

	}
};

class ObjectInitialiser : public Node{
	public:
	NodePtr initList;
	ObjectInitialiser(NodePtr _initList): initList(_initList) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Object Initlialiser:" << std::endl;
		if(initList != NULL){initList->printTree(n+1);}
	}
};

class typedef_declaration : public Node{
	public:
	NodePtr specifierList = NULL, defName = NULL;
	typedef_declaration(NodePtr _specifierList, NodePtr _defName = NULL): specifierList(_specifierList), defName(_defName) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout<< "Typedef Declaration:" << std::endl;
		if(specifierList != NULL){specifierList->printTree(n+1);}
		if(defName != NULL){defName->printTree(n+1);}
	}
};

class TypdefSpecifier : public Node{
	public:
	std::string defName;
	TypdefSpecifier(std::string s): defName(s) {}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Typedef: " << defName << std::endl;
	}
};

class struct_specifier : public Node{
	public:
	std::string id;
	NodePtr decList = NULL;
	struct_specifier(std::string _id, NodePtr _decList): id(_id), decList(_decList) {}
	struct_specifier(NodePtr _decList): id(""), decList(_decList) {}
	struct_specifier(std::string _id): id(_id), decList(NULL) {}
	void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Struct: ";
		if(id == ""){std::cout<<id;}
		std::cout << std::endl;
		if(decList != NULL){decList->printTree(n+1);}
	}
};

class struct_declaration : public Node{
	public:
	NodePtr specList = NULL, declaratorList = NULL;
	struct_declaration(NodePtr _specList, NodePtr _declaratorList): specList(_specList), declaratorList(_declaratorList) {}
	struct_declaration(NodePtr _specList): specList(_specList), declaratorList(NULL) {}
	void printTree(int n){
				for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Struct Declaration" << std::endl;
		if(specList != NULL){specList->printTree(n+1);}
		if(declaratorList != NULL){declaratorList->printTree(n+1);}
	}
};

class struct_declarator : public Node{
	public:
	NodePtr declarator = NULL;
	ExpPtr constExp = NULL;
	struct_declarator(NodePtr _declarator, ExpPtr _constExp): declarator(_declarator), constExp(_constExp) {} 
	struct_declarator(NodePtr _declarator): declarator(_declarator), constExp(NULL) {} 
	struct_declarator(ExpPtr _constExp): declarator(NULL), constExp(_constExp) {} 
	void printTree(int n){
				for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Struct Declarator" << std::endl;
		if(declarator != NULL){declarator->printTree(n+1);}
		if(constExp != NULL){std::cout<< "Buffer: " ;constExp->printTree(n+1); std::cout<<std::endl;}
	}
};

class Pointer : public Node{
	public:
	int ptrDepth = 0;
	Pointer(): ptrDepth(1) {}
	void inc(){ptrDepth++;}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Pointer Depth: "<< ptrDepth << std::endl;
	}
};


#endif
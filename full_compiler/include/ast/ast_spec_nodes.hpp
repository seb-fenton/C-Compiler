#ifndef AST_SPEC_NODES_HPP
#define AST_SPEC_NODES_HPP

#include "ast_base_nodes.hpp"
#include "ast_branch_nodes.hpp"

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
	void printPy(pyContext& context, std::ostream& stream){
		tabprint(context.scopeLevel, stream);
		specifier_list->printPy(context, stream);
		declarator_list->printPy(context, stream);	
		stream << std::endl;
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
	void printPy(pyContext& context, std::ostream& stream){
		declaratorPtr->printPy(context, stream);
		stream << "=";
		if(initialiserPtr == NULL) stream << "0";
		else initialiserPtr->printPy(context, stream);	
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
	void printPy(pyContext& context, std::ostream& stream){
		directDeclarator->printPy(context, stream);
		pointerPtr->printPy(context, stream);
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
	void printPy(pyContext& context, std::ostream& stream){
		stream << identifier;
		if(context.scopeLevel == 0) {
			context.pythonBindings.push_back(identifier);
		}	
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
	void printPy(pyContext& context, std::ostream& stream){
		assignment->printPy(context, stream);
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
	
	void printPy(pyContext& context, std::ostream& stream){
        tabprint(context.scopeLevel, stream);
		context.incScope();
		stream << "def ";
        name->printPy(context, stream);
		stream << ":" << std::endl;

		if(context.pythonBindings.size() > 0){
			for(int i = 0; i < context.pythonBindings.size(); i++){
				tabprint(context.scopeLevel, stream);
				stream << "global " << context.pythonBindings[i] << std::endl;
			}
		}

		statement->printPy(context, stream);
		context.decScope();
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
	void printPy(pyContext& context, std::ostream& stream){
		dec->printPy(context, stream);
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
	void printPy(pyContext& context, std::ostream& stream){
		funcName->printPy(context, stream);
		stream << "(";
		if(argList != NULL) argList->printPy(context, stream);
		stream << ")";
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
	void printPy(pyContext& context, std::ostream& stream){
		initList->printPy(context, stream);
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

class type_name : public Node{
	public:
	NodePtr specList = NULL, abstractDec = NULL;
	type_name(NodePtr _specList, NodePtr _abstractDec): specList(_specList), abstractDec(_abstractDec) {}
	type_name(NodePtr _specList): specList(_specList) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Type Name " << std::endl;
		if(specList != NULL){specList->printTree(n+1);}
		if(abstractDec != NULL){abstractDec->printTree(n+1);}
	}
};

class abstract_pointer : public Node{
	public:
	NodePtr ptr = NULL;
	abstract_pointer(NodePtr _ptr): ptr(_ptr) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Abstract Pointer " << std::endl;
		if(ptr != NULL){ptr->printTree(n+1);}
	}
};

class abstract_declarator : public Node{
	public:
	NodePtr directAbstract = NULL, ptr = NULL; 
	abstract_declarator(NodePtr _directAbstract, NodePtr _ptr): directAbstract(_directAbstract), ptr(_ptr) {}
	abstract_declarator(NodePtr _directAbstract): directAbstract(_directAbstract) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Abstract Declarator" << std::endl;
		if(ptr != NULL){ptr->printTree(n+1);}
		if(directAbstract != NULL){ptr->printTree(n+1);}
	}
};

class AbstractArray : public Node{
	public:
	NodePtr directAbstract = NULL;
	ExpPtr size = NULL;
	AbstractArray(){}
	AbstractArray(NodePtr _directAbstract, ExpPtr _size): directAbstract(_directAbstract), size(_size) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Abstract Array" << std::endl;
		if(directAbstract != NULL){directAbstract->printTree(n+1);}
		if(size != NULL){std::cout<< "Size:";size->printTree(n+1); std::cout<< std::endl;}
	}
};

class EnumConstants : public Node{
	public:
	NodePtr enumList;
	EnumConstants(NodePtr _enumList): enumList(_enumList) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Enum Constants" << std::endl;
		if(enumList != NULL){enumList->printTree(n+1);}
	}
};

class EnumDeclaration : public EnumConstants {
	public:
	std::string id;
	EnumDeclaration(std::string _id, NodePtr _enumList): EnumConstants(_enumList), id(_id) {}
	virtual void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Enum Declaration: " << id << std::endl;
		if(enumList != NULL){enumList->printTree(n+1);}
	}
};

class EnumSpecifier : public Node {
	public:
	std::string id;
	EnumSpecifier(std::string _id): id(_id) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Enum Specifier: " << id << std::endl;
	}
};
 
class enumerator : public Node {
	public:
	std::string id;
	ExpPtr val;
	enumerator(std::string _id, ExpPtr _val): id(_id), val(_val) {}
	enumerator(std::string _id): id(_id), val(NULL) {}
	void printTree(int n){
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Enum Constant Id: " << id << std::endl;
		if(val != NULL){
			for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
			}
			std::cout << "Value";
			val->printTree(n);
			std::cout << std::endl; 
		}
	}
};



#endif
#ifndef AST_STATEMENT_NODES_HPP
#define AST_STATEMENT_NODES_HPP

#include "ast_base_nodes.hpp"

class compound_statement : public Node{
    public:
    NodePtr block_list;
    compound_statement(){}
    compound_statement(NodePtr block): block_list(block) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Compound Statement" << std::endl;
		if(block_list != NULL) {block_list->printTree(n+1);}
	}
};

class expression_statement: public Node{
    public:
    ExpPtr stmt = NULL;
    expression_statement() {}
    expression_statement(ExpPtr _stmt): stmt(_stmt) {}
    void printTree(int n){
        if(stmt != NULL){stmt->printTree(n);}
    }
};

class block_item_list : public BranchNode{
    public:
    block_item_list(NodePtr item){
        branches.push_back(item);
    }
    void printTree(int n) {
		for(int i; i < branches.size(); i++){
            branches[i]->printTree(n);
        }
	}
};

class IfStatement : public Node{
    public:
    ExpPtr cond = NULL;
    NodePtr _true = NULL, _false = NULL;
    IfStatement(ExpPtr _cond, NodePtr T, NodePtr F): cond(_cond), _true(T), _false(F) {}
    IfStatement(ExpPtr _cond, NodePtr T): cond(_cond), _true(T) {/* make a bool stating this does not have an else statement or the other way round */}
    void printTree(int n) {
        for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "If Statement: ";
		if(cond != NULL) {cond->printTree(n);}
        std::cout<< std::endl;
        if(_true != NULL) {_true->printTree(n+1);}
        if(_false != NULL) {_false->printTree(n+1);}
	}
};

class SwitchStatement : public Node{
    public:
    ExpPtr test = NULL;
    NodePtr stmt = NULL;
    SwitchStatement(ExpPtr _test, NodePtr _stmt): test(_test), stmt(_stmt) {/*need to fuck with context to make sure case statements work with this*/};
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Switch Statement: ";
		if(test != NULL) {test->printTree(n);}
        std::cout<< std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
	}
};

class WhileStatement : public Node{
    public:
    ExpPtr cond;
    NodePtr stmt;
    WhileStatement(ExpPtr _cond, NodePtr _stmt): cond(_cond), stmt(_stmt) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "While Statement: ";
		if(cond != NULL) {cond->printTree(n);}
        std::cout<< std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};

class DoStatement : public Node{
    public:
    ExpPtr cond;
    NodePtr stmt;
    DoStatement(NodePtr _stmt, ExpPtr _cond): cond(_cond), stmt(_stmt) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Do Statement: ";
		if(cond != NULL) {cond->printTree(n);}
        std::cout<< std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};

class ForStatement : public Node{
    public:
    ExpPtr  iter = NULL;
    NodePtr stmt = NULL, init = NULL, cond = NULL;
    ForStatement(NodePtr _init, NodePtr _cond, ExpPtr _iter, NodePtr _stmt): init(_init), cond(_cond), iter(_iter), stmt(_stmt) {}
    ForStatement(NodePtr _init, NodePtr _cond, NodePtr _stmt): init(_init), cond(_cond), stmt(_stmt) {/*constructor without the iteration statement*/}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "For Statement: ";
        if(init != NULL) {init->printTree(n);}
        std::cout << "; ";
		if(cond != NULL) {cond->printTree(n);}
        std::cout << "; ";
        if(iter != NULL) {iter->printTree(n);}
        std::cout<< std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};

class LabelStatement : public Node{
    public:
    std::string labelName;
    NodePtr stmt;
    LabelStatement(std::string name, NodePtr _stmt): labelName(name), stmt(_stmt) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Label Statement: " << labelName << std::endl ;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }

};

class CaseStatement : public Node{
    public:
    ExpPtr val;
    NodePtr stmt;
    CaseStatement(ExpPtr _val, NodePtr _stmt): val(_val), stmt(_stmt) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Case Statement: " ;
        if(val != NULL) {val->printTree(n);}
        std::cout << std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};



#endif
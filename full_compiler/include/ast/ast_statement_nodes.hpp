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
    void printPy(pyContext& context, std::ostream& stream){
        //tabprint(context.scopeLevel, stream);
        context.incScope();
        block_list->printPy(context, stream); //TODO : - resolve global scope print!
        context.decScope();
        stream << std::endl;
    }
};

class expression_statement: public Node{
    public:
    ExpPtr stmt = NULL;
    expression_statement() {}
    expression_statement(ExpPtr _stmt): stmt(_stmt) {}
    void printTree(int n){
        for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
        std::cout<< "Expression: ";
        if(stmt != NULL){stmt->printTree(n);}
        std::cout << std::endl;
    }
    void printPy(pyContext& context, std::ostream& stream){
        tabprint(context.scopeLevel, stream);
        stmt->printPy(context, stream); //TODO : - resolve global scope print!
        stream << std::endl;
    }
};

class block_item_list : public BranchNode{
    public:
    block_item_list(NodePtr item){
        branches.push_back(item);
    }
    void printTree(int n) {
		for(int i = 0; i < (int)branches.size(); i++){
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
    void printPy(pyContext& context, std::ostream& stream){
        stream << std::endl;
        tabprint(context.scopeLevel, stream);
        stream << "if(";
        cond->printPy(context, stream);
        stream << "):\n";
        context.incScope();
        //tabprint(context.scopeLevel, stream);
        _true->printPy(context, stream);
        context.decScope();

        if(_false!=NULL){
            stream << std::endl;
            tabprint(context.scopeLevel, stream);
            stream << "else():\n";
            context.incScope();
            //tabprint(context.scopeLevel, stream);
            _false->printPy(context, stream);
            context.decScope();
        }
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
    ExpPtr cond = NULL;
    NodePtr stmt = NULL;
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
    void printPy(pyContext& context, std::ostream& stream){
        tabprint(context.scopeLevel, stream);
        stream << "while(";
        cond->printPy(context, stream);
        stream << ")\n";
        context.incScope();
        tabprint(context.scopeLevel, stream);
        cond->printPy(context, stream);
        context.decScope();
    }
};

class DoStatement : public Node{
    public:
    ExpPtr cond = NULL;
    NodePtr stmt = NULL;
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
    ForStatement(NodePtr _init, NodePtr _cond, ExpPtr _iter, NodePtr _stmt): iter(_iter), stmt(_stmt), init(_init), cond(_cond) {}
    ForStatement(NodePtr _init, NodePtr _cond, NodePtr _stmt): stmt(_stmt), init(_init), cond(_cond) {/*constructor without the iteration statement*/}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "For Statement: " << std::endl;
        if(init != NULL) {init->printTree(n+1);}
		if(cond != NULL) {cond->printTree(n+1);}
        for(int i = 0; i < n+1; i++){
			std::cout<< "|\t" ;
		}
        std::cout<< "Iteration: ";
        if(iter != NULL) {iter->printTree(n);}
        std::cout<<std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};

class LabelStatement : public Node{
    public:
    std::string labelName;
    NodePtr stmt = NULL;
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
    ExpPtr val = NULL;
    NodePtr stmt = NULL;
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

class DefaultStatement : public Node{
    public:
    NodePtr stmt = NULL;
    DefaultStatement(NodePtr _stmt):  stmt(_stmt) {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Default Statement: " << std::endl;
        if(stmt != NULL) {stmt->printTree(n+1);}
    }
};

class ContinueStatement : public Node{
    public:
    ContinueStatement() {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Continue Statement: " << std::endl;
    }
};

class BreakStatement : public Node{
    public:
    BreakStatement() {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Break Statement: " << std::endl;
    }
};

class ReturnStatement : public Node{
    public:
    ExpPtr expr = NULL;
    ReturnStatement(ExpPtr _expr): expr(_expr) {}
    ReturnStatement() {}
    void printTree(int n) {
		for(int i = 0; i < n; i++){
			std::cout<< "|\t" ;
		}
		std::cout << "Return Statement: ";
        if(expr != NULL){expr->printTree(n);}
        std::cout<<std::endl;
    }
    void printPy(pyContext& context, std::ostream& stream){
        tabprint(context.scopeLevel, stream);
        stream << "return";
        if(expr!=NULL) expr->printPy(context, stream);
        stream << "\n";
	}
};


#endif
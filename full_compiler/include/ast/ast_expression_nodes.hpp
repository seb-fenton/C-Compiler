#ifndef AST_EXPRESSION_NODES_HPP
#define AST_EXPRESSION_NODES_HPP

#include "ast_base_nodes.hpp"

//---------------------------------------------//
//------------EXPRESSION-----------------------//
//           Expression Nodes                  //
//---------------------------------------------//



class primary_expression : public ExpressionNode{
	public:
	std::string identifier;
	primary_expression(std::string s): identifier(s) {}
	void printTree(int n) {
		std::cout << identifier;
	}
};

class constantNode : public ExpressionNode{
	public:
	double init;
	constantNode(double n): init(n) {}
	void printTree(int n) {
		std::cout << init;
	}
};

class stringNode : public ExpressionNode{
	public:
	std::string init;
	stringNode(std::string n): init(n) {}
	void printTree(int n) {
		std::cout << init;
	}
};


class conditional_expression: public ExpressionNode{
	public:
	ExpPtr Cond = NULL, TrueExp= NULL, FalseExp= NULL;
	conditional_expression(ExpPtr a, ExpPtr b, ExpPtr c): Cond(a), TrueExp(b), FalseExp(c) {} 
	void printTree(int n) {
		if(Cond != NULL){Cond->printTree(n);}
		std::cout << " ? ";
		if(TrueExp != NULL){TrueExp->printTree(n);}
		std::cout << " : ";
		if(FalseExp != NULL){FalseExp->printTree(n);}
	}
};

class LogicalOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LogicalOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		
		if(left != NULL){left->printTree(n);}
		std::cout << " || ";
		if(right != NULL){right->printTree(n);}
	}
};


class LogicalAndOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LogicalAndOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		
		if(left != NULL){left->printTree(n);}
		std::cout << " && ";
		if(right != NULL){right->printTree(n);}
	}
};

class InclusiveOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	InclusiveOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " | ";
		if(right != NULL){right->printTree(n);}
	}
};

class ExclusiveOrOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	ExclusiveOrOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " ^ ";
		if(right != NULL){right->printTree(n);}
	}
};

class AndOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	AndOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " & ";
		if(right != NULL){right->printTree(n);}
	}
};

class EqualOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	EqualOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " = ";
		if(right != NULL){right->printTree(n);}
	}
};

class NotEqualOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	NotEqualOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " != ";
		if(right != NULL){right->printTree(n);}
	}
};

class GreaterThanOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	GreaterThanOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " > ";
		if(right != NULL){right->printTree(n);}
	}
};

class LessThanOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LessThanOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " < ";
		if(right != NULL){right->printTree(n);}
	}
};

class LessThanEqOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LessThanEqOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " <= ";
		if(right != NULL){right->printTree(n);}
	}
};

class GreaterThanEqOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	GreaterThanEqOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " >= ";
		if(right != NULL){right->printTree(n);}
	}
};

class LeftShiftOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	LeftShiftOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " << ";
		if(right != NULL){right->printTree(n);}
	}
};

class RightShiftOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	RightShiftOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " >> ";
		if(right != NULL){right->printTree(n);}
	}
};

class AddOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	AddOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " + ";
		if(right != NULL){right->printTree(n);}
	}
};

class SubOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	SubOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " - ";
		if(right != NULL){right->printTree(n);}
	}
};

class MultOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	MultOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " * ";
		if(right != NULL){right->printTree(n);}
	}
};

class DivOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	DivOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " / ";
		if(right != NULL){right->printTree(n);}
	}
};

class  ModulusOp: public ExpressionNode{
	public:
	ExpPtr left = NULL, right= NULL;
	ModulusOp(ExpPtr a, ExpPtr b): left(a), right(b){} 
	void printTree(int n) {
		if(left != NULL){left->printTree(n);}
		std::cout << " % ";
		if(right != NULL){right->printTree(n);}
	}
};

class cast_expression: public ExpressionNode{
    public:
    NodePtr left = NULL;
    ExpPtr right = NULL;
    cast_expression(NodePtr a, ExpPtr b): left(a), right(b){}
    void printTree(int n){
        std::cout << "( ";
        if(left != NULL){left->printTree(n);}
        std::cout << " ) ";
        if(right != NULL){right->printTree(n);}
    }
};

class PreIncOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PreIncOp(ExpPtr a): expr(a){}
    void printTree(int n){
        std::cout << "++";
        if(expr != NULL){expr->printTree(n);}
    }
};

class PreDecOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PreDecOp(ExpPtr a): expr(a){}
    void printTree(int n){
        std::cout << "--";
        if(expr != NULL){expr->printTree(n);}
    }
};

class PostIncOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PostIncOp(ExpPtr a): expr(a){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        std::cout << "++";
    }
};

class PostDecOp: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    PostDecOp(ExpPtr a): expr(a){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        std::cout << "--";    
    }
};

class unary_expression: public ExpressionNode{
    public:
    std::string unaryOp = NULL;
    ExpPtr expr = NULL;
    unary_expression(std::string a, ExpPtr b): unaryOp(a), expr(b){}
    void printTree(int n){
        std::cout << unaryOp;
        if(expr != NULL){expr->printTree(n);}
    }
};

class SizeOf: public ExpressionNode{
    public: 
    NodePtr sizeOf = NULL;
    ExpPtr expr = NULL;
    bool primitive = false;
    SizeOf(NodePtr a, ExpPtr b, bool c): sizeOf(a), expr(b), primitive(c){}
    void printTree(int n){
        if(sizeOf != NULL){sizeOf->printTree(n);}
		if(primitive) std::cout << "(";
		if(expr != NULL){expr->printTree(n);}
        if(primitive) std::cout << ")";
    }
};

class array_call: public ExpressionNode{ //TODO
    public: 
    //what the cock
};

class function_call: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    ExpPtr list = NULL;
    function_call(ExpPtr a, ExpPtr b): expr(a), list(b){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        std::cout << "(";
        if(list != NULL){list->printTree(n);}
        std::cout << ")";
    }
};

class postfix_exppression_other: public ExpressionNode{
    public: 
    ExpPtr expr = NULL;
    ExpPtr ptrOp = NULL;
    ExpPtr identifier = NULL;
    postfix_exppression_other(ExpPtr a, ExpPtr b, ExpPtr c): expr(a), ptrOp(b), identifier(c){}
    void printTree(int n){
        if(expr != NULL){expr->printTree(n);}
        if(ptrOp != NULL){ptrOp->printTree(n);}
        else std::cout << ".";
        if(identifier != NULL){identifier->printTree(n);}
    } 
    
};

class postfix_exppression_dec_init: public ExpressionNode{
    public: 
    ExpPtr dec = NULL;
    ExpPtr init = NULL;
    bool comma = false;
    postfix_exppression_dec_init(ExpPtr a, ExpPtr b): dec(a), init(b){}
    void printTree(int n){
        std::cout << "(";
        if(dec != NULL){dec->printTree(n);}
        std::cout << "){";
        if(init != NULL){init->printTree(n);}
        if(comma) std::cout << ",";
        std::cout << "}";
    } 
    
};

#endif
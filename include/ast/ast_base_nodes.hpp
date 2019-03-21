#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>
#include "context.hpp"

class Node{

	public:
		virtual ~Node() {};

		bool funcDefPy = false;

		void addOperands(int one, int two, int three, std::ostream& stream){
			stream << "add $" << one << ", $" << two << ", $" << three << std::endl;
		}
		void storeOperand(int operand, int offset, std::ostream& stream){
			stream << "sw $" << operand << ", " << offset << "($sp)" << std::endl;
		}
		void loadOperand(int operand, int offset, std::ostream& stream){
			stream << "lw $" << operand << ", " << offset << "($sp)" << std::endl;
		}
		
		virtual void printTree(int n) = 0;
		virtual void printPy(pyContext& context, std::ostream& stream){}
		virtual void tabprint(int scope, std::ostream& stream){
			for(int i = 0; i < scope; i++){stream << "\t";}
		}
		virtual void printMips(compilerContext& ctx, std::ostream& stream){} //TODO - Implement this
};
typedef Node* NodePtr;

class ExpressionNode : public Node{
	public:
    virtual ~ExpressionNode()  {};



		virtual int eval(){return 0;}
};
typedef ExpressionNode* ExpPtr;

class BranchNode : public Node{
    public:
		std::vector<NodePtr> branches;
		
		void push(NodePtr n) {
			branches.push_back(n);
		}

		virtual ~BranchNode()  {}
		
		virtual void printPy(pyContext& context, std::ostream& stream){
			for(int i = 0; i < (int)branches.size(); i++){
				branches[i]->printPy(context, stream);
			}
		}
};
typedef BranchNode* BranchPtr;


#endif
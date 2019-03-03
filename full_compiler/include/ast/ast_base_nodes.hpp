#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>







//----------BASE_CLASS---------//
class Node{

	public:
		virtual void printTree(int n) = 0;
		//virtual void printPy(std::string fileName); //TODO - Implement this
		//virtual void printMips(std::string fileName); //TODO - Implement this

};
typedef Node* NodePtr;

class ExpressionNode : public Node{
	public:

};
typedef ExpressionNode* ExpPtr;

class BranchNode : public Node{
    public:
		std::vector<NodePtr> branches;
		
		void push(NodePtr n) {
			branches.push_back(n);
		}

		virtual ~BranchNode()  {}
};



#endif
#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>


class Node{

	public:
		virtual void printTree(int n) = 0;
<<<<<<< HEAD
		virtual void printPy(){ std::cout << "#python not implemented for this command\n";}
		virtual void printMips(); //TODO - Implement this
=======
		//virtual void printPy(std::string fileName); //TODO - Implement this
		//virtual void printMips(std::string fileName); //TODO - Implement this
>>>>>>> 08a552f0602c09a3dc81cfed1bfdd499d7eef7da

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
typedef BranchNode* BranchPtr;


#endif
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
		virtual void printTree(int n) = 0 ;
};
typedef Node* NodePtr;

class ExpressionNode : public Node{
	public:

};
typedef ExpressionNode* ExpPtr;




#endif
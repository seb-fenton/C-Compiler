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
		virtual void printTree();
};


//---------------------------------------------//
//------------BRANCH_NODES------------------------//
//        Nodes with branches in them          //
//---------------------------------------------//

class Branch_Node : public Node{
    public:
		std::vector<NodePtr> branches;
		virtual ~Branch_Node()  {}
		void push(NodePtr n){
			branches.push_back(n);
		}
};

class translation_unit : public Branch_Node{
	public:
	void printTree(){
		std::cout << "Translation Unit" << std::endl;
		for(int i; i < branches.size(); i++){
			branches[i]->printTree();
		}
	}
};


//---------------------------------------------//
//------------SPEC_NODES-----------------------//
//        Nodes with specified pointers		     //
//---------------------------------------------//

class Spec_Node : public Node{
    private:
    protected:
    public:
		virtual ~Spec_Node()  {}
};

#endif
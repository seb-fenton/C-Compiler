#ifndef AST_NODES_HPP
#define AST_NODES_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>




class Node;
typedef std::shared_ptr<Node> NodePtr;


//----------BASE_CLASS---------//
class Node{

	public:
    		virtual  void print_C() const  {
		}

		 virtual ~Node()  {}
};


//---------------------------------------------//
//------------EXPRESSION_NODES-----------------//
//---------------------------------------------//

class Expression : public Node{
    private:

    protected:
    public:
};

#endif
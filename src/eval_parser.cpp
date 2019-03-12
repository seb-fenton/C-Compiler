#include "../include/ast.hpp"


int main(int argc, char *argv[])
{

    Node *ast=parseAST(NULL);
    
    
    ast->printTree(0);

    return 0;
}

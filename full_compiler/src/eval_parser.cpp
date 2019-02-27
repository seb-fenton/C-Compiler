#include "ast.hpp"


int main(int argc, char *argv[])
{

    Node *ast=parseAST();
    
    
    ast->printTree(0);

    return 0;
}

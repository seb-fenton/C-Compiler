#include "../include/ast.hpp"

int main(int argc, char* argv[]){
    if(argc != 5){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    if(argv[1] == "--translate"){
        Node* ast = parseAST(argv[2]); 
        ast->printPy(argv[4]);
        return 0;
    }
    else if(argv[1] == "-S"){
        Node* ast = parseAST(argv[2]);
        ast->printMips(argv[4]);
        return 0;
    }
    else std::cerr << "invalid input format" << std::endl;
    return -1;
}
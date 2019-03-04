#include "../include/ast.hpp"

int main(int argc, char* argv[]){
    if(argc != 5){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    if(std::string(argv[1]) =="--translate"){
        Node* ast = parseAST(argv[2]); 
        freopen(argv[4],"w",stdout);
        ast->printPy();
        fclose(stdout);
        return 0;
    }
    else if(std::string(argv[1]) == "-S"){
        Node* ast = parseAST(argv[2]);
        freopen(argv[4],"w",stdout);
        ast->printMips();
        fclose(stdout);
        return 0;
    }
    else std::cerr << "invalid input format" << std::endl;
    return -1;
}
#include "../include/ast.hpp"

extern Node *parseAST();


int main(int argc, char* argv[]){
    if(argc != 5){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    if(std::string(argv[1]) =="--translate"){
        Node* ast = parseAST(/*filename?*/); 
        freopen(argv[4],"w",stdout);
        pyContext context;
        ast->printPy(context);
        fclose(stdout);
        return 0;
    }
    else if(std::string(argv[1]) == "-S"){
        Node* ast = parseAST(/*filename?*/);
        freopen(argv[4],"w",stdout);
        ast->printMips();
        fclose(stdout);
        return 0;
    }
    else std::cerr << "invalid input format" << std::endl;
    return -1;
}
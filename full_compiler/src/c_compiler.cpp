#include "../include/ast.hpp"



int main(int argc, char* argv[]){
    if(argc != 5){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    if(std::string(argv[1]) =="--translate"){
        Node* ast = parseAST(/*filename?*/); 
        pyContext context;
        std::ostream* os = &std::cout;
        std::ofstream stream;
        stream.open(argv[4]);
        os = &stream;
        ast->printPy(context, *os);
        stream.close();
        return 0;
    }
    else if(std::string(argv[1]) == "-S"){
        Node* ast = parseAST(/*filename?*/);
        ast->printMips();
        return 0;
    }
    else std::cerr << "invalid input format" << std::endl;
    return -1;
}
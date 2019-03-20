#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>


class Node;
typedef Node* NodePtr; //never use any member functions for this class

struct DeclaratorContext{
    std::string id;
    bool initliased = false;
    //int destReg; //should be an enum.
    int size; //declaration specifier determines this
    int elements = 1; // usually for arrays, set to 1 by default for normal declaration
    int offset;

    int totSize();
    void purge();
    void nextElement();
};

struct LoopContext{ //needed for continue and break
    std::string cont, brk ;
    LoopContext(std::string _cont, std::string _brk): cont(_cont), brk(_brk){}
};

struct varData{
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    //NodePtr typedefLoc = NULL; //points to the declaration specifiers the typedef contains

    bool global;
    int elements = 1;
    int offset; //used to specifiy how far this variable is from the stack pointer(frame pointer)? idk
    varData(){}
    varData(int _offset, int _elements, int _size, bool _global); //let declarator increment $sp
};

struct scope{
    std::map<std::string, varData> bindings; 
    int stackOffset;

    scope(std::map<std::string, varData> _bindings, int _stackOffset);
    void addToBindings(std::string id, int offset, int elements, int size, bool global);
};

struct funcScope{
    int scopeLevel = 0;

    std::vector<scope> scopes;
    std::map<std::string, varData> parameters;
    std::map<std::string, varData> globalVars;
    std::vector<LoopContext> LoopsLabels;

    int memUsed = 0; //should be incremented as you add new bindings
    void incScope();
    void decScope(std::ostream& stream);
    funcScope(std::ostream& stream, std::map<std::string, varData> _globalVars);
     //the function definition node should pack the info correctly
};  //for a function with parameters.


struct compilerContext{
    
    std::vector<funcScope> functions;
    std::map<std::string, varData> globalVars;

    void setup(std::ostream& stream); //NOTE $fp should point to previous functions last element, this makes it possible to do $fp + memUsed to go back to the start address.
    void endFunc(std::ostream& stream);
    bool funcDef = false;
    bool funcCall = false;
    bool globalDefs = false;
    bool getAddr = false;
    std::string funcName; //used for .end flag at the end of assembly

    int labelGen = 0;
    std::string generateUniqueLabel();
    std::string generateLabel(std::string s);

    bool freeRegs[32];

    std::map<std::string, varData>* currentBindings();
    scope* currentScope();
    funcScope* currentFunc();
    void addToStack(int size, std::ostream& stream);
    void removeFromStack(int size, std::ostream& stream);

    DeclaratorContext tempDeclarator; //can be used by declarators to keep track of info needed to add to bindings.
    
};

static compilerContext comCtx;


 //------------------------------------------------------------------------------------------------------------//

struct lexContext{
    std::vector<std::vector<std::string> > type_defs = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;
    bool declaration = false;

    void incScope();
    void decScope();
};

struct pyContext{
    int scopeLevel = 0;
    std::vector<std::string> pythonBindings;

    void incScope();
    void decScope();
};

static lexContext ctx;


#endif
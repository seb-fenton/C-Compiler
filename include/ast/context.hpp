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

class Node;
typedef Node* NodePtr; //never use any member functions for this class



struct varData{
    bool isArray = false;
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    //NodePtr typedefLoc = NULL; //points to the declaration specifiers the typedef contains

    int offset; //used to specifiy how far this variable is from the stack pointer(frame pointer)? idk
    //varData(int _size, int _offset) figure out constructor
};

struct scope{
    std::map<std::string, varData> bindings;  

    scope(std::map<std::string, varData>& _bindings);
};

struct funcScope{
    int scopeLevel = 0;
    int returnData; //might not be needed

    std::vector<scope> scopes;
    std::map<std::string, varData> parameters;

    int memUsed = 0; //should be incremented as you add new bindings
    void incScope();
    funcScope(){};
    funcScope(std::map<std::string, varData>& _parameters): parameters(_parameters) {} //the function definition node should pack the info correctly
};


struct compilerContext{
    
    std::vector<funcScope> functions;
    std::map<std::string, varData> globalVars;

    void newFunc(); //NOTE $fp should point to previous functions last element, this makes it possible to do $fp + memUsed to go back to the start address.
    void endFunc();

    bool freeRegs[32];

    std::map<std::string, varData>* currentBindings();
};


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
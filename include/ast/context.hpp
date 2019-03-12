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
    int val;

    bool isArray = false;
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    //NodePtr typedefLoc = NULL; //points to the declaration specifiers the typedef contains

    int offset; //used to specifiy how far this variable is from the stack pointer(frame pointer)? idk
    //varData(int _val, int _size, int _offset,) figure out constructor
};

struct scope{
    std::map<std::string, varData> bindings;

    bool isFunc;    //true if in the highest scope of a function.
    int returnData; //should only be used when isFunc is true.

    scope(std::map<std::string, varData> _bindings);
};

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

struct compilerContext{
    int scopeLevel = 0;
    std::vector<scope> scopes;
    std::map<std::string, varData> globalVars;

    void incScope();
    void functionCall();
};


static lexContext ctx;

#endif
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

#include "ast_base_nodes.hpp"

struct varData{
    int val;

    bool isArray = false;
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    //NodePtr typedefLoc = NULL; //points to the declaration specifiers the typedef contains

    int offset; //used to specifiy how far this variable is from the stack pointer(frame pointer)? idk
    //varData(int _val, int _size, int _offset,)
};

struct scope{
    std::map<std::string, varData> bindings;

    bool isFunc;    //true if in the highest scope of a function.
    int returnData; //should only be used when isFunc is true.

    scope(std::map<std::string, varData> _bindings): bindings(_bindings){}
};

struct lexContext{
    std::vector<std::vector<std::string> > type_defs = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;
    bool declaration = false;

    void incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

    void decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }
};

struct pyContext{
    int scopeLevel = 0;
    std::vector<std::string> pythonBindings;

    void incScope(){
        scopeLevel++;
    }

    void decScope(){
        scopeLevel--;
    }
};

struct compilerContext{
    int scopeLevel = 0;
    std::vector<scope> scopes;
    std::map<std::string, varData> globalVars;

    void incScope(){
        scopes.push_back(scope(scopes[scopeLevel].bindings)); //when you enter a new scope, take the old scope bindings and put them into the new one
        scopeLevel++;
    }

    void functionCall(){
        scopes.push_back(globalVars); //when a function call occurs, only give it the global variables and not the previous scopes bindings
        scopeLevel++;
    }

};


static lexContext ctx;

#endif
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
    bool isArray = false;

    int totSize();
    void purge();
    void nextElement();
};

struct WhileContext{ //needed for continue and break
    std::string start, end;
    WhileContext(std::string _start, std::string _end): start(_start), end(_end){}
};

struct varData{
    bool isArray = false;
    int size; //used mainly for arrays but we can initlialise it for normal integers, to be used with the SizeOf command

    bool isTypdef = false;
    //NodePtr typedefLoc = NULL; //points to the declaration specifiers the typedef contains

    int elements = 1;
    int offset; //used to specifiy how far this variable is from the stack pointer(frame pointer)? idk
    varData(){}
    varData(int _offset, int _elements, bool _isArray); //let declarator increment $sp
};

struct scope{
    std::map<std::string, varData> bindings; 
    int stackOffset;

    scope(std::map<std::string, varData> _bindings, int _stackOffset);
    void addToBindings(std::string id, int offset, int elements, bool isArray);
};

struct funcScope{
    int scopeLevel = 0;

    std::vector<scope> scopes;
    std::map<std::string, varData> parameters;
    std::vector<WhileContext> whileLoops;

    int memUsed = 0; //should be incremented as you add new bindings
    void incScope();
    void decScope(std::ostream& stream);
    funcScope(std::ostream& stream);
     //the function definition node should pack the info correctly
};  //for a function with parameters.


struct compilerContext{
    
    std::vector<funcScope> functions;
    std::map<std::string, varData> globalVars;

    void setup(std::ostream& stream); //NOTE $fp should point to previous functions last element, this makes it possible to do $fp + memUsed to go back to the start address.
    void endFunc(std::ostream& stream);
    bool funcDef = false;

    int labelGen = 0;
    std::string generateUniqueLabel();
    std::string generateLabel(std::string s);

    bool freeRegs[32];

    std::map<std::string, varData>* currentBindings();
    scope* currentScope();
    funcScope* currentFunc();
    void addToStack(int size, std::ostream& stream);

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
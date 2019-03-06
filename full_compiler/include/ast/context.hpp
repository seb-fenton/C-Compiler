#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>
#include <algorithm>

struct context{
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

    void incScope(){
        scopeLevel++;
    }

    void decScope(){
        scopeLevel--;
    }
};

static context ctx;

#endif
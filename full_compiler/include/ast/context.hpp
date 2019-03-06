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
    std::vector<std::vector<std::string> > enums = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;

    void incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        enums.push_back(enums[scopeLevel]);
        scopeLevel++;
    }

    void decScope(){
        type_defs.pop_back();
        enums.pop_back();
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
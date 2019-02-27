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
    std::vector<std::vector<std::string>> type_defs = {{}};
    int scopeLevel = 0;
    std::string temp_typedef;

    void incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

    void decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }
};

static context ctx;

#endif
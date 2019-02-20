#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>

struct binding{
    //add way of storing value
    std::string var_name;
    bool is_numeric = false;
    bool is_boolean = false;
    bool is_string = false;

};

struct context{
    std::vector<binding> bindings; //stores all bindings

};

#endif
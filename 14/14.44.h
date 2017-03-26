//
// Created by lianlian on 16-10-31.
//

#ifndef CLINE_14_44_H
#define CLINE_14_44_H

#include <map>
#include <string>
#include <functional>

struct divides{
    int operator()(int i, int j){
        if(j != 0)
            return i / j;
        else{
            return 0;
        }
    }
};

int add(int i , int j){
    return i + j;
}
auto mod = [](int i, int j){return i % j;};
std::map<std::string, std::function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"/", divides()},
    {"*", [](int i, int j){return i * j;}},
    {"%", mod}
};


#endif

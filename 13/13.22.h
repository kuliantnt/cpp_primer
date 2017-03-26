//
// Created by lianlian on 16-9-27.
//

#ifndef CLINE_13_22_H
#define CLINE_13_22_H

#include <string>
using std::string;

class HasPtr_value{
public:
    HasPtr_value(const std::string &s = std::string()): ps(new std::string(s)),i(0){}
    HasPtr_value(const HasPtr_value& hp): ps(new std::string(hp.ps)), i(hp.i){}
    HasPtr_value& operator= (HasPtr_value& oldHasPtr)
    {
        std::string *p_new = new string(*oldHasPtr.ps);
        delete ps;
        ps = p_new;
        i = oldHasPtr.i;
        return *this;

    }
    ~HasPtr_value(){
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

#endif //CLINE_13_22__H

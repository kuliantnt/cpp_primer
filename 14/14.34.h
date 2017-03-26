//
// Created by lianlian on 16-10-27.
//

#ifndef CLINE_14_34_H
#define CLINE_14_34_H

#include <iostream>
#include <string>
class If_then_else{
public:
    void operator() (int, std::string, std::string);
};

void If_then_else::operator()(int i, std::string lhs, std::string rhs) {
    std::ostream& os = std::cout;
    if(i){
        os << lhs;
    }else{
        os << rhs;
    }
    return;
}

#endif //CLINE_14_34_H

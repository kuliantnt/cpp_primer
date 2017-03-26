//
// Created by lianlian on 16-10-28.
//

#ifndef CLINE_14_38_H
#define CLINE_14_38_H

#include <string>
class lambda{
    bool operator() (std::string& str,std::size_t size) const{
        return str.size() == size;
    }
};
#endif //CLINE_14_38_H

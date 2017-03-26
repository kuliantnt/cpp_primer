//
// Created by lianlian on 16-11-8.
//

#ifndef CLINE_16_5_H
#define CLINE_16_5_H

#include <iostream>
template <typename T>
void print(const T &t){
    for(const auto iter : t){
        std::cout << iter << std::endl;
    }
};
#endif //CLINE_16_5_H

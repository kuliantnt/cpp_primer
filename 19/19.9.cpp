/*
//
// Created by lianlian on 17-3-24.
//

#include <typeinfo>
#include "19.6/Query_base.h"
int main(int argc, char**argv){
    int array[10];
    AndQuery aq;
    Query_base *_pQb = &aq;
    std::cout << typeid(array).name() << std::endl
              << typeid(42).name() << std::endl
              << typeid(BinaryQuery).name() << std::endl
              << typeid(std::string).name() << std::endl
              << typeid(aq).name() << std::endl
              << typeid(*_pQb).name() << std::endl
              << typeid(_pQb).name() << std::endl;

}
*/

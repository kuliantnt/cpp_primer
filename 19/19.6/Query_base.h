//
// Created by lianlian on 17-3-24.
//

#ifndef CLINE_QUERY_BASE_H
#define CLINE_QUERY_BASE_H

#include <iostream>

class Query_base{
public:
    Query_base(){
        std::cout << "using Query_base" << std::endl;
    }
    virtual void print(){
        std::cout << "is Query_base" << std::endl;
    }
};


class BinaryQuery:public Query_base{
public:
    BinaryQuery(){
        std::cout << "using BinaryQuery" << std::endl;
    }
    void print(){

        std::cout << "is BinaryQuery" << std::endl;
    }
};

class AndQuery:public BinaryQuery{
public:
    AndQuery(){
        std::cout << "using AndQuery" << std::endl;
    }
    void print(){
        std::cout << "is AndQuery" << std::endl;
    }
};

class OrQuery:public BinaryQuery{
public:
    OrQuery(){

        std::cout << "using OrQuery" << std::endl;
    }
    void print(){
        std::cout << "is OrQuery" << std::endl;
    }
};
#endif //CLINE_QUERY_BASE_H

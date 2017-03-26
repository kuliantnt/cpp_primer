/*
//
// Created by lianlian on 17-3-24.
//

#include <typeinfo>
#include "Query_base.h"
void cast(Query_base &qb){
    try{
        AndQuery aq = dynamic_cast<AndQuery&>(qb);
        std::cout << "is successful" << std::endl;
    }catch(std::bad_cast& e) {
        std::cout << e.what() << std::endl;
    }
}
int main(int argc, char** argv){
    //19.6
    Query_base *_qQue = new AndQuery;
    if(AndQuery *_qAnd = dynamic_cast<AndQuery*> (_qQue)){
        std::cout << "is successful" << std::endl;
    }else{
        std::cout << "is invalid" << std::endl;
    }
    delete _qQue;

    //19.7
    Query_base *pb1 = new AndQuery();
    cast(*pb1);

    //19.8
    Query_base *pb2 = new AndQuery();
    if(typeid(*pb1) == typeid(*pb2))
        std::cout << "is == " << std::endl;
    else{
        std::cout << "is != " << std::endl;
    }

    if(typeid(*pb1) == typeid(AndQuery))
        std::cout << "is == " << std::endl;
    else {
        std::cout << "is != " << std::endl;
    }

    delete pb1;
    delete pb2;
}*/

//
// Created by lianlian on 17-2-14.
//

#include <iostream>
namespace Exercise{
    int ivar = 0;
    double dver = 0;
    const int limit =1000;
}
int ivar = 0;
using Exercise::dver;
using Exercise::limit;
void manip(){
    //位置２;
    double dver = 3.1415;
    int iobj = limit + 1;
    ++Exercise::ivar;
    ++::ivar;
    std::cout << ivar << "\t " << iobj << "\t" << Exercise::ivar << "\t " << ::ivar;
}

/*
int main(int argc,char * argv[]){
    manip();
}*/

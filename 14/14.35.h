//
// Created by lianlian on 16-10-27.
//

#ifndef CLINE_14_35_H
#define CLINE_14_35_H

#include <string>
#include <iostream>
class PrintString{
public:
    PrintString(std::ostream&,std::istream&);
    void operator() ();
private:
    std::ostream& os;
    std::istream& is;
    std::string str;
};

PrintString::PrintString(std::ostream &o, std::istream &i) : os(o) ,is(i){

}

void PrintString::operator()() {
    os << "please enter a string" << std::endl;
    is >> str ;
    if(is){
        os << str;
    }else{
        os << "";
    }
    return;

}

#endif //CLINE_14_35_H

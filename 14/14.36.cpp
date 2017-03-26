//
// Created by lianlian on 16-10-28.
//

#include "14.36.h"

StringToVector::StringToVector() : StringToVector(std::cin, std::cout){

}

StringToVector::StringToVector(std::istream &i, std::ostream &o) : is (i), os(o){

}
/**
 * @brief 重载运算符（） 用于标准输入
 */
void StringToVector::operator()() {
    os << "please enter any string!"<< std::endl;
    while(is >> str) {
        strVec.push_back(str);
        if(str == "exit")
            break;

    }
}

void StringToVector::print() {
    for(std::string string: strVec){
        os << string << std::endl;
    }
}

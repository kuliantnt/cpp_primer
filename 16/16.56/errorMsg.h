//
// Created by lianlian on 16-11-29.
//

#ifndef CLINE_ERRORMSG_H
#define CLINE_ERRORMSG_H
#include <iostream>
#include <sstream>
template <typename T>
std::string debug(T &t){
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
std::string debug(T *p){
    if(p){
        return debug(*p);
    }
    std::string str= "不存在函数";
    return str;
}

template <typename T>
std::ostream& print (std::ostream& os , const T &t){
    os << t;
    return os;
}

template <typename T,typename ...Arg>
std::ostream& print (std::ostream& os,const T& t, const Arg&... arg) {
    os << t << ", ";
    return print(os, arg...);
}

template <typename ...Arg>
std::ostream& errorMsg(std::ostream& os, const Arg&... args){
    print(os,debug(args)...);
}
#endif //CLINE_ERRORMSG_H

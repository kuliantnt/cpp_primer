//
// Created by lianlian on 16-11-28.
//

#include <iostream>
#include <string>

template <typename T>
std::ostream& print(std::ostream &os, const T& t){
    os << t;
}
template <typename T, typename ...Args>
std::ostream& print(std::ostream &os, const T& t, const Args&... args){
    os << t << ", ";
    return print(os, args...);
}


//int main(int argc, char **argv) {
//    int i = 3;
//    std::string s = "int i ";
//    print(std::cout, s, i, 43);
//}

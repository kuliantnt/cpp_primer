//
// Created by lianlian on 16-10-28.
//

#ifndef CLINE_14_36_H
#define CLINE_14_36_H

#include <iostream>
#include <vector>
#include <string>
class StringToVector{
public:
    StringToVector(); //默认构造函数
    StringToVector(std::istream&, std::ostream&); //构造函数
    void print(); //输出并打印...
    void operator() ();
private:
    std::vector<std::string> strVec;
    std::string str;
    std::istream& is;
    std::ostream& os;
};
#endif //CLINE_14_36_H

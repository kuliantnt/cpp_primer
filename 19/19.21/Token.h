#pragma once 
#include <iostream>
#include <string>
class Token
{
public:
    // ���캯��
    Token();
    ~Token();
private:
    enum { INT, CHAR, DLB, STR }tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };
    void copyUnion(const Token&);
};
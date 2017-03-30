#pragma once 
#include <iostream>
#include <string>
class Token
{
public:
    // 构造函数
    Token();
    //析构函数
    ~Token();
    //移动构造函数
    Token(Token &&t);
    //拷贝构造函数
    Token(const Token &t) : tok(t.tok)
    {
        copyUnion(t);
    }
    //移动赋值运算符
    Token& operator=(Token&&);
    //拷贝赋值运算符
    Token& operator= (const Token&);
    // 赋值运算符
    Token& operator= (int i);
    Token& operator= (char c);
    Token& operator= (double d);
    Token& operator= (std::string str);

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
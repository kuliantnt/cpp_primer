#pragma once 
#include <iostream>
#include <string>
#include "Sales_date.h"
class Token
{
public:
    // 构造函数
    Token();
    //析构函数
    ~Token();
    //移动构造函数
    Token(Token &&t)
    {
        using std::move;
        if (t.tok == STR) {
            sval = move(t.sval);
        }
        else if (t.tok == SD) {
            sdval = move(t.sdval);
        }
        else
        {
            switch (t.tok) {
            case INT:
                ival = move(t.ival);
                break;
            case DLB:
                dval = move(t.dval);
                break;
            case CHAR:
                cval = move(t.cval);
                break;
            }
        }
    }
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
    Token& operator= (Sales_date sd);

private:
    enum { INT, CHAR, DLB, STR, SD }tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_date sdval;
    };
    void copyUnion(const Token&);
    void moveUnion(Token&&);
};
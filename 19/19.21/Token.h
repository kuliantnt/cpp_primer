#pragma once 
#include <iostream>
#include <string>
class Token
{
public:
    // ���캯��
    Token();
    //��������
    ~Token();
    //�ƶ����캯��
    Token(Token &&t);
    //�������캯��
    Token(const Token &t) : tok(t.tok)
    {
        copyUnion(t);
    }
    //�ƶ���ֵ�����
    Token& operator=(Token&&);
    //������ֵ�����
    Token& operator= (const Token&);
    // ��ֵ�����
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
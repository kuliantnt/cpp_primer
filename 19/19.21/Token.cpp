#include "Token.h"


Token::Token() : tok(INT), ival(0) {}

Token::~Token()
{
    if (tok == STR) {
        sval.~basic_string();
    }
    else if (tok == SD) {
        sdval.~Sales_date();
    }
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok) {
    case Token::INT:
        ival = t.ival;
        break;
    case Token::CHAR:
        cval = t.cval;
        break;
    case Token::DLB:
        dval = t.dval;
        break;
    case Token::STR:
        new(&sval) std::string(t.sval);
        break;

    case Token::SD:
        new(&sdval) Sales_date(t.sdval);
        break;
    }
}

void Token::moveUnion(Token &&t)
{
    using std::move;
    switch (t.tok) {
    case Token::INT:
        ival = move(t.ival);
        break;
    case Token::CHAR:
        cval = move(t.cval);
        break;
    case Token::DLB:
        dval = move(t.dval);
        break;
    case Token::STR:
        new(&sval) std::string(move(t.sval));
        break;

    case Token::SD:
        new(&sdval) Sales_date(move(t.sdval));
        break;
    }
}

Token & Token::operator=(Token &&t)
{
    if (&tok == &t.tok) {
        return *this;
    }
    else
    {
        using std::move;
        if (tok == STR && t.tok != STR) {
            sval.~basic_string();
        }
        if (tok != STR && t.tok == STR) {
            new (&sval) std::string(move(t.sval));
        }
        else {
            moveUnion(move(t));
        }
        return *this;
    }
}

Token & Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR) {
        sval.~basic_string();
    }
    if (tok == STR && t.tok == STR) {
        sval = t.sval;
    }
    else
    {
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}

Token & Token::operator=(int i)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    else if (tok == SD) {
        sdval.~Sales_date();
    }
    ival = i;
    tok = INT;
    return *this;
}

Token & Token::operator=(char c)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    else if (tok == SD) {
        sdval.~Sales_date();
    }
    tok = CHAR;
    cval = c;
    return *this;
}

Token & Token::operator=(double d)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    else if (tok == SD) {
        sdval.~Sales_date();
    }
    tok = DLB;
    dval = d;
    return *this;
}

Token & Token::operator=(std::string str)
{
    if (tok == STR) {
        sval = str;
    }
    else if (tok == SD) {
        sdval.~Sales_date();
    }
    else
    {
        new(&sval) std::string(str);
    }
    tok = STR;
    return *this;
}

Token & Token::operator=(Sales_date sd)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    else if (tok == SD) {
        sdval = sd;
    }
    else{
        new(&sdval) Sales_date(sd);
    }
}

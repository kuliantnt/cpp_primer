#include "Token.h"


Token::Token() : tok(INT), ival(0) {}

Token::~Token()
{
    if (tok == STR) {
        sval.~basic_string();
    }
}

Token::Token(Token && t)
{
    using std::move;
    if (t.tok == STR) {
        sval = move(t.sval);
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
    ival = i;
    tok = INT;
    return *this;
}

Token & Token::operator=(char c)
{
    if (tok == STR) {
        sval.~basic_string();
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
    tok = DLB;
    dval = d;
    return *this;
}

Token & Token::operator=(std::string str)
{
    if (tok == STR) {
        sval = str;
    }
    else
    {
        new(&sval) std::string(str);
    }
    tok = STR;
    return *this;
}

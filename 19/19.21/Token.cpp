#include "Token.h"


Token::Token() : tok(INT), ival(0) {}

Token::~Token()
{
    if (tok == STR) {
        sval.~basic_string();
    }
}

void Token::copyUnion(const Token &)
{
}

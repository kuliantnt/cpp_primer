//
// Created by lianlian on 16-11-6.
//

#ifndef CLINE_BINARYQUERY_H
#define CLINE_BINARYQUERY_H


#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}

    //抽象类：BinaryQuery 不定义eval
    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs; //左侧和右侧运算对象
    std::string opSym; //运算符名字;
};


#endif //CLINE_BINARYQUERY_H

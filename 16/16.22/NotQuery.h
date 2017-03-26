//
// Created by lianlian on 16-11-6.
//

#ifndef CLINE_NOTQUERY_H
#define CLINE_NOTQUERY_H


#include "Query_base.h"
#include "Query.h"


class NotQuery : public Query_base {
    friend Query operator~(const Query &);

    NotQuery(const Query &q) : query(q) {}

    //具体的类：NotQuery 将定义所有继承而来的虚函数
    std::string rep() const {
        return "~{" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery &) const;

    Query query;
};
inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif //CLINE_NOTQUERY_H

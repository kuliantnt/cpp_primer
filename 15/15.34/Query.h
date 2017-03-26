//
// Created by lianlian on 16-11-6.
//

#ifndef CLINE_QUERY_H
#define CLINE_QUERY_H

#include "Query_base.h"
#include "WordQuery.h"
#include <memory>
class Query {
    friend Query operator~ (const Query &operand);
    friend Query operator| (const Query &lhs, const Query & rhs);
    friend Query operator& (const Query &lhs, const Query & rhs);
public:
    Query(const std::string&); //构建一个新的WordQuery
    // 接口函数：调用相对应的Query_base操作
    QueryResult eval (const TextQuery & t) const {
        return q -> eval(t);
    }
    std::string rep() const {
        return q -> rep();
    }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {};
    std::shared_ptr<Query_base> q;
};

std::ostream & operator << (std::ostream& os, const Query &query);

#endif //CLINE_QUERY_H

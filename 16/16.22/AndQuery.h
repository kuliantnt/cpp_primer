//
// Created by lianlian on 16-11-6.
//

#ifndef CLINE_ANDQUERY_H
#define CLINE_ANDQUERY_H


#include "Query.h"
#include "BinaryQuery.h"

class AndQuery  : public  BinaryQuery {
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") {};

    QueryResult eval(const TextQuery &) const;
};
inline Query operator& (const Query &lhs, const Query &rhs){
    return std::shared_ptr<Query_base> (new AndQuery(lhs , rhs));
}



#endif //CLINE_ANDQUERY_H

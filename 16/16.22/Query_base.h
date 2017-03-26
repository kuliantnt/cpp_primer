//
// Created by lianlian on 16-11-6.
//

#ifndef CLINE_QUERY_BASE_H
#define CLINE_QUERY_BASE_H

#include <string>
#include "QueryResult.h"
#include "TextQuery.h"

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};


#endif //CLINE_QUERY_BASE_H

//
// Created by lianlian on 16-11-6.
//

#include "NotQuery.h"
QueryResult NotQuery::eval(const TextQuery &text) const {
    //通过Query运算对象,对eval 进行虚调用
    auto result = query.eval(text);
    //开始的时候set为空
    auto ret_lines = std::make_shared<std::set<line_no >>();
    //我们必须要在运算对象出现的所有行中进行迭代
    auto beg = result.begin(), end = result.end();
    //对于输入文件的每一行,如果该行不在result中,则将其添加到result_line;
    StrBlob::size_type sz = result.get_file().size();
    for (size_t n = 0; n != sz; ++n) {
        if(beg == end || *beg != n) {
            ret_lines->insert(n);
        }
        else if(beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}


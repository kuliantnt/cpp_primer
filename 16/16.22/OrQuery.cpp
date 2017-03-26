//
// Created by lianlian on 16-11-6.
//

#include "OrQuery.h"
QueryResult OrQuery::eval(const TextQuery & text) const {
    //通过Query成员lhs,rhs进行的虚调用
    // 调用eval返回每个运算符对象的QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    //插入右侧对象所得的行号
    ret_lines-> insert(right.begin(),right.end());
    //返回一个新的QueryResult,表示lhs和rhs的并集
    return QueryResult(rep(),ret_lines, left.get_file());
}

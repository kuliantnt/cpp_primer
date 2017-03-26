//
// Created by lianlian on 16-11-6.
//

#include "Query.h"

std::ostream & operator << (std::ostream& os, const Query &query){
    return os << query.rep();
}
/**
 * @brief 构造函数
 * @param s string
 * @return
 */
inline Query::Query(const std::string &s) : q(new WordQuery(s),DebugDelete()){

}



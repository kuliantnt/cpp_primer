//
// Created by lianlian on 16-12-8.
//

#ifndef CLINE_FIND_BOOK_H
#define CLINE_FIND_BOOK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include "Sales_data.h"
bool compareISBN(const Sales_data& lhs, const Sales_data& rhs){
    return lhs.isbn() < rhs.isbn();
}
//typedef std::tuple <std::vector<Sales_data>::size_type,
//        std::vector<Sales_data>::const_iterator,
//        std::vector<Sales_data>::const_iterator> matches;
//std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book) {
//    std::vector <matches> ret; //初始化为空vector
//    //对每家书店，查找与给定书记匹配的记录范围（如果存在的话）
//    for (auto it = files.cbegin(); it != files.cend(); ++it){
//        auto found = std::equal_range(it ->cbegin(),it -> cend(), book, compareISBN);
//        if(found.first != found.second)
//            ret.push_back(std::make_tuple(it - files.cbegin(),found.first,found.second));
//    }
//    return ret;
//}
typedef std::pair<std::size_t,
        std::pair<std::vector<Sales_data>::const_iterator,
        std::vector<Sales_data>::const_iterator>>
matches;
std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> & files, const std::string book) {
    std::vector <matches> ret; //初始化位空的vector
    for (auto it = files.cbegin(); it != files.cend(); ++it){
        auto found = std::equal_range(it -> cbegin(), it ->cend(), book , compareISBN);
        if (found.first != found.second){
            std::pair<std::vector<Sales_data>::const_iterator,
            std::vector<Sales_data>::const_iterator> pair2{found.first,found.second};
            matches pair = {it - files.cbegin(),pair2};
            ret.push_back(pair);
            return ret;
        }
    }
}


#endif //CLINE_FIND_BOOK_H

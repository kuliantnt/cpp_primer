//
// Created by lianlian on 16-11-7.
//

#ifndef CLINE_FIND_H
#define CLINE_FIND_H
template <typename Iterator, typename Value>
Iterator find(const Iterator& first, const Iterator& end, const Value& val) {
    for (auto iter = first ; iter != end; iter++){
        if (*iter == val){
            return iter;
        }
    }
    return end;

//    auto iter = first;
//    while(*iter != val && iter != end){
//        ++iter;
//    }
//    return iter;
};
#endif //CLINE_FIND_H

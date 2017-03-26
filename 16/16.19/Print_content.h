//
// Created by lianlian on 16-11-13.
//

#ifndef CLINE_PRINT_CONTENT_H
#define CLINE_PRINT_CONTENT_H

#include <iostream>
template <typename T> class Print_content ;
template <typename v>
std::ostream& operator<< (std::ostream& os, const Print_content<v>& pc) ;

template <typename T>
class Print_content {

public:
    template<typename V>
    friend std::ostream &operator<<(std::ostream &os, const Print_content<V> &);

    Print_content() = default;

    Print_content(T c) : content(c) {}

private:
    T content;
};

template <typename V>
std::ostream& operator<< (std::ostream& os, const Print_content<V>& pc) {
    for (auto element : pc.content) {
        os << element << "\t";
    }
    return os;
}
#endif //CLINE_PRINT_CONTENT_H

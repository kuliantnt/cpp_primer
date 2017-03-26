//
// Created by lianlian on 16-12-2.
//

#include <cstddef>
#include <vector>
#include <iostream>
#include <cstring>

template <typename T>
std::size_t count(const T t, const std::vector<T> &vector);

//template <>
//std::size_t count(const char*, const std::vector<const char*>&);
//int main(int argc, char * argv[]) {
//
//    std::vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 1, 1, 1, 1};
//    std::vector<double> vd = {1.1, 1.1, 2.3, 4};
//    std::cout << count(1, vi) << std::endl;
//    std::cout << count(1.1, vd) << std::endl;
//
//    std::vector<const char *> vcc = {"alan", "alan", "alan", "alan", "moophy"};
//    std::cout << count("alan", vcc);
//    return 0;
//}
template <typename T>
std::size_t count(const T t, const std::vector<T> &vector) {
    std::size_t size = 0;
    for (auto i : vector) {
        if (i == t) {
            ++size;
        }
    }
    return size;
}


template <>
std::size_t count (const char* t,const std::vector<const char*> &vector) {
    std::size_t size = 0;
    for (auto &iter : vector) {
        if (!strcmp(iter, t)) {
            size++;
        }
    }
    return size;
}

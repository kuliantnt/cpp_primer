#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
//
// Created by lianlian on 17-1-17.
//


class intArray {
public:
    intArray() : p(nullptr) {};

    explicit intArray(std::size_t size) : p(new int[size]) {};

    ~intArray() {
        delete p;
    }

private:
    int *p;


};

void exercise(int *b, int *e) {
    std::vector<int> vec(b, e);
    intArray array(vec.size());
    std::shared_ptr<int> p(new int[vec.size()], [](int *p) { delete[] p; });
    std::ifstream in("ints");

}
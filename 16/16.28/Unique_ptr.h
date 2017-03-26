//
// Created by lianlian on 16-11-16.
//

#ifndef CLINE_UNIQUE_PTR_H
#define CLINE_UNIQUE_PTR_H

#include "DebugDelete.h"
template <typename T,typename D>
class Unique_ptr;

template <typename T, typename D>
void swap(Unique_ptr<T,D>&, Unique_ptr<T,D>&);

template <typename T, typename D>
class Unique_ptr {
    template<typename T, typename D>
    friend
    void swap(Unique_ptr<T, D> &, Unique_ptr<T, D>&);

public:
    Unique_ptr(const Unique_ptr &) = delete;

    Unique_ptr &operator=(const Unique_ptr &) = delete;

    Unique_ptr() = default;

    Unique_ptr(T *p) : ptr(p) {}
    Unique_ptr(Unique_ptr &&up) : ptr(up.ptr), deleter(up.deleter) {};

    Unique_ptr &operator=(Unique_ptr &&) noexcept;


    T* relese();

    ~Unique_ptr(){
        delete ptr;
    }
private:
    T *ptr = nullptr;

    D deleter = D();
};

template <typename T,typename D>
Unique_ptr &Unique_ptr<T,D>::operator=(Unique_ptr &&up) {
    delete ptr;
    ptr = up.ptr;
    deleter = std::move(deleter);
    up.ptr = nullptr;
}

template <typename T,typename D>
T *Unique_ptr<T,D>::relese() {
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}

template<typename T, typename D>
void swap(Unique_ptr<T, D> &lhs, Unique_ptr<T, D>&rhs) {
    using std::swap;
    swap(lhs.deleter, rhs.deleter);
    swap(lhs.ptr, rhs.ptr);
}

#endif //CLINE_UNIQUE_PTR_H

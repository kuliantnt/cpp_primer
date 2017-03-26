//
// Created by lianlian on 16-11-16.
//

#ifndef CLINE_SHARED_PTR_H
#define CLINE_SHARED_PTR_H

#include <functional>
#include <cstddef>
#include "DebugDelete.h"

template <typename T>
void swap(Shared_ptr<T>& lhs, Shared_ptr<T>& rhs);

template <typename T>
class Shared_ptr {
    friend template<typename T> void swap(Shared_ptr<T>&, Shared_ptr<T>&);
public:
    //constructor
    Shared_ptr() = default;

    explicit Shared_ptr(T *sp, std::function<void(T *)> d = DebugDelete()) :
            p(sp), deleter(d), ptrCount(new std::size_t(1)) {}

    //copy constructor
    Shared_ptr(const Shared_ptr &sp) : p(sp.p), deleter(sp.deleter), ptrCount(sp.ptrCount) {
        ++*ptrCount;
    }

    Shared_ptr(Shared_ptr &&sp) noexcept;

    Shared_ptr &operator=(const Shared_ptr &rhs);

    Shared_ptr &operator=(Shared_ptr &&rhs) noexcept;

    operator bool() {
        return p ? true : false;
    }

    T &operator*() {
        return *p;
    }

    T *operator->() {
        return &this->operator*();
    }

    std::size_t use_count() const {
        return *ptrCount;
    }

    bool unique() {
        return *ptrCount == 1;
    }

    void swap(Shared_ptr &rhs) {
        std::swap(*this, rhs);
    }

    void reset(T *p) {
        if (p != this->p) {
            decrement_n_destroy();
            this->p = p;
            ptrCount = new std::size_t(1);
        }
    }

    void reset(T *p, std::function<void(T*)> & del) {
        reset(p);
        deleter = del;
    }

    ~Shared_ptr(){
        decrement_n_destroy();
    }
private:
    T *p = nullptr;
    std::size_t *ptrCount = new std::size_t(0);
    std::function<void(T *)> deleter{
            DebugDelete()
    };

    void decrement_n_destroy();
};

template <typename T>
inline
void Shared_ptr::decrement_n_destroy() {
    if(p){
        if(--*ptrCount == 0){
            delete ptrCount;
            delete(p);
        }
        p = nullptr;
        ptrCount = nullptr;
    }
}

template <typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr &&sp) : p(sp.p), deleter(std::move(sp.deleter)), ptrCount(sp.ptrCount){
    sp.p = nullptr;
    sp.ptrCount = nullptr;

}

template <typename T>
inline
Shared_ptr &Shared_ptr<T>::operator=(const Shared_ptr &rhs) {
    ++*ptrCount;
    decrement_n_destroy();
    p = rhs.p;
    ptrCount = rhs.ptrCount;
    deleter = rhs.deleter;
    return *this;
}

template <typename T>
inline
Shared_ptr &Shared_ptr<T>::operator=( Shared_ptr &&rhs) noexcept {
    decrement_n_destroy();

    std::move(rhs);

    return *this;

}

template<typename T>
inline
void swap(Shared_ptr<T>& lhs, Shared_ptr<T> &rhs) {
    using std::swap;
    swap(lhs->p, rhs->p);
    swap(lhs->ptrCount, rhs->prtCount);
    swap(lhs->deleter, rhs->deleter);
}



#endif //CLINE_SHARED_PTR_H

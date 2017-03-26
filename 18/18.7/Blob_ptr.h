//
// Created by lianlian on 17-1-22.
//

#ifndef CLINE_BLOB_PTR_H
#define CLINE_BLOB_PTR_H

#include <memory>
#include <stdexcept>
#include <vector>
#include "Blob.h"
template <typename T> class Blob_ptr;

template <typename T>
bool operator==(Blob_ptr<T>& lhs, Blob_ptr<T>& rhs);

template <typename T>
bool operator < (const Blob_ptr<T>& lhs, const Blob_ptr<T>& rhs);


template <typename T> class Blob_ptr {
    friend bool operator== <T>(const Blob_ptr<T> &lhs, const Blob_ptr<T> &rhs);

    friend bool operator< <T>(const Blob_ptr<T> &lhs, const Blob_ptr<T> &rhs);
public:

    Blob_ptr() : curr(0) {}

    void handle_out_of_memory(std::bad_alloc &alloc);

    Blob_ptr(Blob<T> &blob, std::size_t size = 0) try : wptr(blob.data), curr(size) {

    } catch (std::bad_alloc &e) {
        handle_out_of_memory(e);
    }

    T& operator[](std::size_t i);

private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};




template <typename T>
bool operator== (const Blob_ptr<T>& lhs, const Blob_ptr<T>& rhs) {
    if (lhs.wptr.lock() == rhs.wptr.lock()) {
        return lhs.curr == rhs.curr;
    } else {
        throw std::runtime_error("Don't compare default element!" );
    }
}

template <typename T>
bool operator <(const Blob_ptr<T>& lhs, const Blob_ptr<T>& rhs) {
    if(lhs.wptr.lock() == rhs.wptr.lock())
        return lhs.curr < rhs.curr;
    else{
        throw std::runtime_error("Don't compare default element!" );
    }
}

template <typename T>
void Blob_ptr<T>::handle_out_of_memory(std::bad_alloc &alloc) {
    std::cerr << alloc.what() << std::endl;
}

#endif //CLINE_BLOB_PTR_H

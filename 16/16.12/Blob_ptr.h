#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <memory>
#include <vector>

friend class Blob_Ptr<T>;
using namespace std;
template <typename> class Blob_Ptr;

template <typename T>
bool operator ==(const Blob_Ptr<T>& lhs, const Blob_Ptr<T>& rhs);

template <typename T>
bool operator < (const Blob_Ptr<T>& lhs, const Blob_Ptr<T>& rhs);


template<typename T> class Blob_Ptr
{
    friend bool operator ==<T>
            (const Blob_Ptr<T>& lhs, const Blob_Ptr<T>& rhs);

    friend bool operator < <T>
            (const Blob_Ptr<T>& lhs, const Blob_Ptr<T>& rhs);

public:
    Blob_Ptr() : curr(0) { }
    Blob_Ptr(Blob<T>& a, std::size_t sz = 0) :
            wptr(a.data), curr(sz) { }

    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    //! prefix
    Blob_Ptr& operator++();
    Blob_Ptr& operator--();

    //! postfix
    Blob_Ptr operator ++(int);
    Blob_Ptr operator --(int);

private:
    //! returns  a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};

//! prefix ++
template<typename T>
Blob_Ptr<T>& Blob_Ptr<T>::operator ++()
{
    //! if curr already points past the end of the container, can't increment it
    check(curr,"increment past end of StrBlob");
    ++curr;
    return *this;
}

//! prefix --
template<typename T>
Blob_Ptr<T>& Blob_Ptr<T>::operator --()
{
    -- curr;
    check(curr,"decrement past begin of Blob_Ptr");

    return *this;
}


//! postfix ++
template<typename T>
Blob_Ptr<T> Blob_Ptr<T>::operator ++(int)
{
    Blob_Ptr ret = *this;
    ++*this;

    return ret;
}

//! postfix --
template<typename T>
Blob_Ptr<T> Blob_Ptr<T>::operator --(int)
{
    Blob_Ptr ret = *this;
    --*this;

    return ret;
}

template<typename T> bool operator==(const Blob_Ptr<T> &lhs, const Blob_Ptr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.curr == rhs.curr;
}

template<typename T> bool operator< (const Blob_Ptr<T> &lhs, const Blob_Ptr<T> &rhs) {
    if (lhs.wptr.lock() != lhs.wptr.lock()) {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.curr < rhs.curr;
}

template <typename T>
std::shared_ptr<std::vector<T>> Blob_Ptr<T>::check(std::size_t i, const std::string & msg) const {
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size()){
        throw out_of_range(msg);
    }
    return ret;
}

#endif // BLOBPTR_H

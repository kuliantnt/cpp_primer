#ifndef CLINE_BLOB_H
#define CLINE_BLOB_H


#include <initializer_list>
#include <memory>
#include <new>
#include <vector>
#include <iostream>

//
// Created by lianlian on 17-1-20.
//

template <typename T>
class Blob_ptr;

template<typename T>
class Blob {
public:
    friend class Blob_ptr<T>;

    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;


    //!construct function
    Blob();

    Blob(std::initializer_list<std::vector<T>> ls) try : data(std::make_shared(std::vector<T>(ls.begin(), ls.end()))) {

    } catch (std::bad_alloc &e) {
        handle_out_of_memory(e);
    }

    //! size?
    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    //! add & deleter element
    void push_back(T &rhs) {
        data->push_back(rhs);
    }

    void push_back(T &&rhs) {
        data->push_back(std::move(rhs));
    }

    void pop_back();

    T &back();

    T &operator[](size_t i);

    const T &operator[](Blob::size_type i) const;

    void handle_out_of_memory(std::bad_alloc &e) {
        std::cout << e.what();
    }

private:
    void check(std::size_t size, std::string msg) const;

    std::shared_ptr<std::vector<T>> data;
};

template <typename T>
Blob<T>::Blob() : data(std::shared_ptr<std::vector<T>>()) {

}


template <typename T>
void Blob<T>::check(size_t i, std::string msg) const {
    if(data -> size() < i){
        throw std::out_of_range(msg);
    }
}

template <typename T>
void Blob<T> ::pop_back() {
    check(0,"not pop zero element");
    data -> pop_back();
}

template <typename T>
T &Blob<T>::back() {
    check(0, "not pop zero element");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_t i) {
    check(i, "no element");
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](Blob::size_type i) const {
    check(i, "no element");
    return (*data)[i];
}

#endif
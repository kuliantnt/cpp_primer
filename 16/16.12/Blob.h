//
// Created by lianlian on 16-11-9.
//

#ifndef CLINE_BLOB_H
#define CLINE_BLOB_H


#include <vector>
#include <string>
#include <memory>

template <typename T>
class Blob {
public:
    friend class Blob_ptr<T>;

    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    //struct function
    Blob();

    Blob(std::initializer_list<T> li);

    //Blob element number
    size_type size() const {
        return data->size();
    }

    bool emply() const {
        return data->empty();
    }

    //添加和删除元素
    void push_back(const T &t) {
        data->push_back(t);
    }

    void push_back(T &&t) {
        data->push_back(std::move(t));
    }

    void pop_back();

    T &back();

    T &operator[](size_type i);

    const T operator[](Blob::size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type i, const std::string) const;
};

template <typename T>
void Blob<T>::pop_back() {
    check(0, "不能pop一个空的数组");
    data->pop_back();
}

template <typename T>
T &Blob<T>::back() {
    check(0, "不能返回一个空的元素");
    data->back();
}

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) : data(std::make_shared(std::vector<T>(li.begin(),li.end()))){}

template <typename T>
void Blob<T>::check(Blob::size_type i, const std::string msg)const {
    if (data->size() <= i) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T &Blob<T>::operator[](Blob<T>::size_type i) {
    check(i, "out of range");
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](Blob<T>::size_type i) const  {
    check(i, "out of range");
    return (*data)[i];
}

#endif //CLINE_BLOB_H

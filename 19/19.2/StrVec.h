#ifndef H13_39_H_
#define H13_39_H_
#include <iostream>
#include <string>
#include <memory> //allocator
#include <utility>    //move
#include <initializer_list>
#include <algorithm>  //for_each
class StrVec
{
    std::allocator<std::string> alloc;//为所有StrVec对象分配内存用
    void chk_n_alloc()      //如果剩余空间为0就分配新空间
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b, const std::string *e);//创建一个内容为b到e之间的元素的对象，并返回这个对象的一对头尾指针
    void free();//释放所有alloc分配的所有内存
    void reallocate();//移动当前对象的元素到2倍对象大小的新对象里
    std::string *elements;
    std::string *first_free;
    std::string *cap;
public:
    StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> il);
    StrVec(const StrVec &s);
    StrVec(StrVec &&s);//13.49
    StrVec &operator=(StrVec &&s);//13.49
    StrVec &operator=(const StrVec &s);
    ~StrVec();
    void push_back(const std::string &s);//把string添加到尾后指针
    size_t size()const
    {
        return first_free - elements;
    }
    size_t capacity()const
    {
        return cap - elements;
    }
    std::string *begin()const
    {
        return elements;
    }
    std::string *end()const
    {
        return first_free;
    }
};


#endif
//
// Created by lianlian on 17-3-23.
//

#include "StrVec.h"
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();//确保空间剩余
    alloc.construct(first_free++, s);//在尾后构建一个s（s的拷贝构造函数构造），并把尾后指针first_free指向下一个
}
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);//分配并返回n个string对象的地址 string *
    return{ data, std::uninitialized_copy(b, e, data) };//uninit_copy返回尾后指针string *
    //把l~r之间的元素拷贝到data开始的地址，并返回data尾后，然后使用data(begin)和返回值(end)构建一个pair<string *,string *>
}
void StrVec::free()
{
    if (elements)//如果不为空
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);//从最后一个元素开始向前摧毁，调用p的析构函数
        //for_each(elements, first_free, [this](std::string *s){alloc.destroy(s); });//13.43
        alloc.deallocate(elements, cap - first_free);//释放elements开始的n的string对象的内存
    }
}
StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());//创建一个s的副本 值
    elements = newdata.first;//把头指向新创建的副本的头
    first_free = cap = newdata.second;//把尾后和内存尾指向副本的尾（以后调用会调用chk_n_alloc，不用担心剩余空间大小）
}
StrVec::StrVec(StrVec &&s) :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec &StrVec::operator=(StrVec &&s)
{
    if (this == &s)
        return *this;
    free();
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
    return *this;
}
StrVec::~StrVec()
{
    free();//清理当前对象alloc分配的内存
}
StrVec &StrVec::operator=(const StrVec &s)
{
    if (this == &s)
        return *this;
    auto data = alloc_n_copy(s.elements, s.first_free);
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1; //当前空间的两倍大小
    auto newdata = alloc.allocate(newcapacity); //分配并返回newcapacity个string对象大小的空间
    auto dest = newdata;
    auto elem = elements;//指向当前对象的头
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));//move会让elem指向的string对象放弃自己的内存管理权并返回，然后construct使用string的移动构造函数构建dest指向的地址
    }                                               //接受dest会指向newdata的尾后
    free();             //移动完后释放当前对象指向的内存
    elements = newdata; //指向新头
    first_free = dest;  //指向新尾后
    cap = elements + newcapacity;   //指向内存尾
}
//
// Created by lianlian on 16-10-19.
//

#ifndef CLINE_13_39_H
#define CLINE_13_39_H

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>


class StrVec{
    friend bool operator== (StrVec&, StrVec&) const;
    friend bool operator!= (StrVec&, StrVec&) const;
public:
    StrVec():  //allocator成员进行初始化
     elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    void range_initialized(const std::string*,const std::string*);
    StrVec(const StrVec&); //拷贝构造函数
    StrVec(StrVec&&); //移动构造函数
    /**
     * @brief operator overload
     * @return
     */
    StrVec &operator= (const StrVec&); //拷贝赋值运算符
    StrVec &operator= (StrVec&&); //拷贝赋值运算符
    StrVec &operator= (std::initializer_list<std::string>);
    std::string &operator[] (std::size_t);
    const std::string &operator[] (std::size_t) const;
    ~StrVec(); //析构函数
    void push_back(const std::string&); //尾后添加元素
    void push_back(std::string&&) ; //尾后添加元素的右值版本
    /**
     * @brief StrVec数组的大小
     * @return size_t 类型
     */
    size_t size() const {
        return first_free - elements;
    }

    /**
     * @brief 容器的大小
     * @return size_t 尺寸
     */
    size_t capacity()const {
        return cap - elements;
    }

    std::string * begin() const {
        return elements;
    }

    std::string * end() const{
        return first_free;
    }
private:
    static std ::allocator<std::string> alloc; //设定容器
    /**
     * @brief 被添加元素的函数所使用
     */
    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }
    /**
     * @brief 工具函数,被拷贝构造函数,赋值运算函符,析构函数所使用.
     * @return
     */
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free(); //释放元素
    void reallocate(); //得到更多内存
    std::string *elements; //指向首元素的指针
    std::string *first_free; //指向数字第一个空闲元素的指针
    std::string *cap; //指向数组尾后位置的指针
};

StrVec::StrVec(const StrVec &s) {
    //调用alloc_n_copy 分配空间以容纳和s一样多的元素
    auto newdate = alloc_n_copy(s.begin(), s.end());
    elements = newdate.first;
    first_free = cap = newdate.second;
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc(); //确保有空间容纳新元素
    alloc.construct(first_free++,s);
}

std::pair<std::string *, std::string *>
    StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    //分配空间保存给定范围内的元素
    auto data = alloc.allocate(e - b);
    //初始化并返回一个pair,该pair有date 和uninitialized_copy 的返回值构成
    return {data, std::uninitialized_copy(b, e, data)};
}

StrVec & StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
StrVec::~StrVec() {
    free();
}

void StrVec::free() {
    //不能传递deallocate 一个空指针,如果elements 为0,函数什么都不做
    if(elements) {
        //逆序销毁旧元素
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    //分配新内存
    auto first = alloc.allocate(newcapacity);
    //将数据从旧内存移动到新内存
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),std::make_move_iterator(end()),first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

StrVec::StrVec(std::initializer_list<std::string> il){
   range_initialized(il.begin(),il.end());
}

void StrVec::range_initialized(const std::string *beg, const std::string *end) {
    auto data = alloc_n_copy(beg, end);
    elements = data.first;
    first_free = cap = data.second;

}
/**
 * @brief 移动赋值运算符
 * @param rhs
 * @return
 */
StrVec::StrVec(StrVec &&rhs) : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap){
    elements = first_free = cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) {
    if(this != &rhs){
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        elements = first_free = cap = nullptr;
    }
    return *this;
}

void StrVec::push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s));
}
/**
 * @brief 比较函数 operator== overload
 * @param lhs left value
 * @param rhs right value
 * @return bool
 */
bool operator== (StrVec& lhs, StrVec& rhs)const{
    return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free &&
            lhs.cap == rhs.cap;
}
/**
 * @brief operator!= overload
 * @param lhs left value
 * @param rhs right value
 * @return bool
 */
bool operator!=(StrVec &lhs, StrVec &rhs) const {
    return !(lhs == rhs);
}
/**
 * @brief operator = overload of initlializer_list
 * @param il a initializer_list<string>
 * @return this
 */
StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(),il.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
    return *this;
}

std::string &StrVec::operator[](std::size_t n) {
    return elements[n];
}

const std::string &StrVec::operator[](std::size_t n) const {
    return elements[n];
}

#endif //CLINE_13_39_H

//
// Created by lianlian on 16-10-20.
//
#include "13.44.h"

/**
 * @brief 默认构造函数
 * @return
 */

String::~String() {
    free();
}
/**
 * @brief 得到String 字符串的大小
 * @return 字符串大小
 */
size_t String::size() {
    return first_free - element;
}

/**
 * @brief 构造函数(char*)
 * @param ch_arr char*
 * @return
 */
String::String(const char* ch_arr) {
//    free();
    char* lc = const_cast<char*> (ch_arr);
    while(*lc)++lc;
    auto newStr = alloc_n_copy(ch_arr,++lc);
    element = newStr.first;
    first_free = cap = newStr.second;
    std::cout << "using char* construct" << std::endl;
}
void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    element = newstr.first;
    first_free = cap = newstr.second;
}
/**
 * @brief 内存分配
 * @param b 开始的指针
 * @param e 结束的指针
 * @return
 */
std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b,e,data)};
}
/**
 * @brief 拷贝构造函数
 * @param s 原String
 * @return
 */
String::String(const String &s) {
    auto newData = alloc_n_copy(s.element, s.first_free);
    element = newData.first;
    cap = first_free = newData.second;
    std::cout << "using copy construct" << std::endl;
}

void String::reallocate() {
    auto newCapacity = size() ? 2 *size() : 1;
    auto newData = alloc.allocate(newCapacity);
    auto dest = newData;
    auto elem = element;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++,std::move(*elem++));
    free();
    element = newData;
    first_free = dest;
    cap = element + newCapacity;
}

/**
 * @brief 清空占用的内存空间
 */
void String::free() {
    if(element){
        for(auto p = first_free; p != element;)
            alloc.destroy(--p);
        alloc.deallocate(element,cap - element);
    }
}

/**
 * @brief 拷贝赋值运算符
 * @param rhs 原函数
 * @return 这个函数
 */
String& String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.element,rhs.first_free);
    free();
    element = data.first;
    cap = first_free = data.second;
    std::cout << "using copy  operation= " << std::endl;
    return *this;
}

void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free++,c);
}

void String::chk_n_alloc() {
    if(size() == capacity())
        reallocate();
}

/**
 * @brief 移动构造函数
 * @return
 */
String::String(String &&rhs) : element(rhs.element), first_free(rhs.first_free), cap(rhs.cap){
    rhs.element = rhs.first_free = rhs.cap = nullptr;
}

/**
 * @brief 移动赋值运算符
 * @param rhs 右值引用
 * @return
 */
String& String::operator=(String &&rhs) {
    if(this != &rhs){
        free();
        element = rhs.element;
        cap = rhs.cap;
        first_free = rhs.first_free;
        element = cap = first_free = nullptr;
    }
    return *this;
}
/**
 * @brief　overload operator<< output
 * @return
 */
std::ostream &operator<<(std::ostream &os, const String &str) {
    char* c = const_cast<char*> (str.begin());
    while(*c){
        os << *c++;
    }
    return os;
}
/**
 * @brief overload operator==
 * @param lhs left value
 * @param rhs right value
 * @return
 */
bool operator==(const String &lhs, const String& rhs) {
    return lhs.element == rhs.element || lhs.first_free == rhs.first_free||
        lhs.cap || rhs.cap;
}
/**
 * @brief overload operator!=
 * @param lhs left value
 * @param rhs right value
 * @return
 */
bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}


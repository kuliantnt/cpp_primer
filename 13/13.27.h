//
// Created by lianlian on 16-9-28.
//

#ifndef CLINE_13_27_H
#define CLINE_13_27_H

#include <string>
class HasPtr{
public:
    /**
     * @brief 构析函数 分配新的string 和新的计数器，将计数器置为1
     * @param s
     * @return
     */
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)){}
    /**
     * @brief 拷贝三个数据成员，递增计数器
     * @param hp
     * @return
     */
    HasPtr(const HasPtr &hp) : ps(hp.ps), use(hp.use){++*use;}
    HasPtr& operator= (const HasPtr&);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use; //使用了多少次
};
/**
 * @brief 析构函数，删除pointer string 和 use所占用的内存
 */
HasPtr::~HasPtr() {
    delete ps;
    delete use;
}
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

#endif
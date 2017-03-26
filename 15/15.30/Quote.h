//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_QUEOTE_H
#define CLINE_QUEOTE_H

#include <string>

class Quote {
public:
    /**
     * @brief 三五法则
     * @return
     */
    Quote(); //默认初始化
    Quote(const std::string&, double); //参数初始化
    Quote(const Quote& ) noexcept ; //对成员依次拷贝
    Quote(Quote&&); //对成员依次拷贝
    Quote& operator= (const Quote&); //拷贝赋值
    Quote& operator= (Quote&&); //移动赋值
    virtual double net_price(std::size_t) const ;
    //打印BookNo
    std::string isbn() const {
        return bookNo;
    }
    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() &&{
        return new Quote(std::move(*this));
    }
    virtual ~Quote(); //析构函数
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
//打印范围内的合计价格
double print_total(std::ostream &os,const Quote &item, size_t n);

#endif //CLINE_QUEOTE_H

//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_BULK_QUOTE_H
#define CLINE_BULK_QUOTE_H

#include <iostream>
#include "Quote.h"
class Bulk_quote : public Quote{
public:
    Bulk_quote() = default; //默认初始化
    Bulk_quote(const std::string& book, double price, std::size_t pty, double dise) :
            Quote(book, price), discount(dise), quantity(pty) {} //参数初始化
    Bulk_quote(const Bulk_quote &bulk_quote); //拷贝赋值
    Bulk_quote(Bulk_quote&&) noexcept; //移动赋值
    Bulk_quote &operator= (const Bulk_quote&); //传值赋值
    Bulk_quote &operator= (Bulk_quote&&); //引用赋值
    ~Bulk_quote(){
//        std::cout << "using ~Bulk_quote" << std::endl;
    };
    double net_price(std::size_t) const override;

private:
    double discount;
    std::size_t quantity;
};

double Bulk_quote::net_price(std::size_t cnt) const {
    return  cnt * (1 - discount) * price;
}
/**
 * @brief 拷贝赋值函数
 * @param rhs 另一个Bulk_quote对象
 * @return
 */
Bulk_quote::Bulk_quote(const Bulk_quote &rhs) : Quote(rhs), discount(rhs.discount), quantity(rhs.quantity) {

}
/**
 * @brief 移动赋值函数
 * @param rhs right
 * @return
 */
Bulk_quote::Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(std::move(rhs)), discount(std::move(rhs.discount))
        , quantity(std::move(rhs.quantity)){

}

/**
 * @brief 拷贝赋值运算符
 * @param rhs right
 * @return *this
 */
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs) {
    Quote::operator=(rhs);
    Bulk_quote temp = rhs;
    discount = temp.discount;
    quantity = temp.quantity;
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) {
    Quote::operator=(rhs);
    if(this != &rhs){
        using std::move;
        discount = move(rhs.discount);
        quantity = move(rhs.quantity);
    }
    return *this;
}

#endif //CLINE_BULK_QUOTE_H

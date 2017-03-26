//
// Created by lianlian on 16-11-5.
//
#include "Bulk_quote.h"

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

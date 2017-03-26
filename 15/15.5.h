//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_15_5_H
#define CLINE_15_5_H

#include <iostream>

class Quote{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price): bookNo(book), price(sales_price){}
    std::string isbn() const {return bookNo;};
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
/**
 * @brief 子类构造函数
 * @param book isbn
 * @param sales_price 售价
 * @param qty 最低售卖量
 * @param dise 折扣
 * @return
 */
Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double dise):
        Quote(book,sales_price), min_qty(qty), discount(dise) { }

double Bulk_quote::net_price(std::size_t cnt) const {
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif //CLINE_15_5_H

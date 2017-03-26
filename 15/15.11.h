//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_15_11_H
#define CLINE_15_11_H

#include <iostream>
#include <string>
class Quote{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price): bookNo(book), price(sales_price){}
    std::string isbn() const {return bookNo;};
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual void debug() const ;
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
/**
 * @brief 打印成员信息
 */
void Quote::debug() const {
    std::cout << "print debug prison\n"
              << " bookNo = " << bookNo << " price = " << price << std::endl;
}

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug() const override;
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

void Bulk_quote::debug() const {
    std::cout << "print debug prison \n"
              << " bookNo = " << this -> isbn() << " price = " << price
              << " min_qty = " << min_qty << " discount = " << discount << std::endl;
}

class Max_bulk_quote final: public Bulk_quote{
public:
    Max_bulk_quote() = default;
    Max_bulk_quote(const std::string&,double,std::size_t,std::size_t, double);
    double net_price(std::size_t cnt) const override;
    void debug() const override;
private:
    size_t size_max;
};

Max_bulk_quote::Max_bulk_quote(const std::string & book, double sales_price, std::size_t s_max, std::size_t
qte, double dise) : Bulk_quote(book, sales_price,qte,dise), size_max(s_max) { }

double Max_bulk_quote::net_price(std::size_t cnt) const {
    if(cnt < min_qty || cnt >= size_max)
        return cnt * price;
    else if(cnt >= min_qty && cnt < size_max)
        return  cnt * (1 - discount) * price;
}

void Max_bulk_quote::debug() const {
    std::cout << "print debug prison \n"
              << " bookNo = " << this -> isbn() << " price = " << price
              << " min_qty = " << min_qty << " discount = " << discount
              << " size_max = " << size_max << std::endl;
}

#endif //CLINE_15_11_H

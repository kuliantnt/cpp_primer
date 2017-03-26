//
// Created by lianlian on 16-11-1.
//

#ifndef CLINE_15_2_H
#define CLINE_15_2_H

#include <iostream>
class Quote {
public:
    Quote() = default;

    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo };

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
#endif //CLINE_15_2_H

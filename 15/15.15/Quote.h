//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_QUEOTE_H
#define CLINE_QUEOTE_H

#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string&, double);
    virtual double net_price(std::size_t) const ;
    virtual ~Quote();
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
double Quote::net_price(std::size_t cnt) const {
    return price * cnt;
}

#endif //CLINE_QUEOTE_H

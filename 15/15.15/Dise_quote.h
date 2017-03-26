//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_DISE_QUOTE_H
#define CLINE_DISE_QUOTE_H

#include "Quote.h"
#include <string>

class Dise_quote : public Quote{
public:
    Dise_quote () = default;
    Dise_quote(const std::string&, double, std::size_t,double);
    virtual double net_price(std::size_t) const = 0;
protected:
    double discount;
    std::size_t quantity;
};

Dise_quote::Dise_quote(const std::string & book, double price,
                       std::size_t qty, double dise) : Quote(book, price), quantity(qty), discount(dise){ }


#endif //CLINE_DISE_QUOTE_H

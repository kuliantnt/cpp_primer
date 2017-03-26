//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_SALES_QUOTE_H
#define CLINE_SALES_QUOTE_H

#include "Dise_quote.h"
class Sales_quote : public Dise_quote{
public:
    Sales_quote() = default;
    Sales_quote(const std::string&, double, std::size_t, double, std::size_t );
    double net_price(size_t) const override ;
private:
    std::size_t max_size;

};

double Sales_quote::net_price(size_t cnt) const {
    if(cnt > max_size || cnt < quantity)
        return size_t * price;
    else
        return size_t * (1 - discount);
}

Sales_quote::Sales_quote(const std::string & book, double price, std::size_t pty, double dise,
                         std::size_t ms) : Dise_quote(book, price, pty, dise) , max_size(ms){

}

#endif //CLINE_SALES_QUOTE_H

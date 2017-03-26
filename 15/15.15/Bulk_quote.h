//
// Created by lianlian on 16-11-2.
//

#ifndef CLINE_BULK_QUOTE_H
#define CLINE_BULK_QUOTE_H

#include "Dise_quote.h"
class Bulk_quote : public Dise_quote{
    Bulk_quote(const std::string& book, double price, std::size_t pty, double dise) : Dise_quote(book, price, pty, dise) {}
    double net_price(std::size_t) const override;

};

double Bulk_quote::net_price(std::size_t cnt) const {
    return  cnt * (1 - discount) * price;
}
#endif //CLINE_BULK_QUOTE_H

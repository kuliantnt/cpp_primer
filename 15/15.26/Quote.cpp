//
// Created by lianlian on 16-11-3.
//

#include <iostream>
#include "Quote.h"

Quote::Quote() {
//    std::cout << "using default Quote" << std::endl;
}

double Quote::net_price(std::size_t cnt) const {
    return price * cnt;
}

Quote::Quote(const std::string &book, double p) : bookNo(book), price(p) {
//    std::cout << "using list Quote" << std::endl;
}

Quote::Quote(const Quote &rhs) noexcept: bookNo(rhs.bookNo), price(rhs.price){
//    std::cout << "using copy initialization Quote" << std::endl;
}

Quote::Quote(Quote&&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)){
//    std::cout << "using move initialization" << std::endl;
}

Quote& Quote::operator=(const Quote &rhs) {
    Quote temp = rhs;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote& Quote::operator=(Quote &&rhs) {
    if(this != &rhs){
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }
    return *this;
}

Quote::~Quote() {
//    std::cout << "using ~Quote" << std::endl;
}

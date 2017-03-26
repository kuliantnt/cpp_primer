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
    Bulk_quote *clone() const &{
        return new Bulk_quote(*this);
    }
    Bulk_quote *clone() &&{
        return new Bulk_quote(std::move(*this));
    }

private:
    double discount;
    std::size_t quantity;
};



#endif //CLINE_BULK_QUOTE_H

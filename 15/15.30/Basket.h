//
// Created by lianlian on 16-11-4.
//

#ifndef CLINE_BASKET_H
#define CLINE_BASKET_H

#include "Bulk_quote.h"
#include <memory>
#include <set>

class Basket {
public:
    /**
     * @brief a lot of default struct function
     */
    Basket () = default;
    Basket (const Basket&) = default;
    Basket (Basket&&) = default;
    Basket &operator= (const Basket&) = default;
    Basket &operator= (Basket&&) = default;
    ~Basket() = default;

    void add_item(const Quote &sale){
        items.insert (std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale){
        items.insert (std::shared_ptr<Quote>(sale.clone()));
    }

    double total_receipt(std::ostream&) const;

private:
    /**
     * @brief compare Isbn
     * @param lhs left parament
     * @param rhs right parament
     * @return lhs < rhs
     */
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs -> isbn() < rhs -> isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)(*)> items{compare};
};


#endif //CLINE_BASKET_H

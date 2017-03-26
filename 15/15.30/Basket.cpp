//
// Created by lianlian on 16-11-4.
//

#include "Basket.h"


double Basket::total_receipt(std::ostream & os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));  //ERROR
    }
}

//
// Created by lianlian on 17-3-27.
//

#include <iostream>
#include "Sales_date.h"

Sales_date::Sales_date(const std::string &bookNo, unsigned unit_sold, double price) : bookNo(bookNo), units_sold(unit_sold)
        ,revenue(unit_sold*price) {
}

void print(std::ostream &os, Sales_date &sd) {
    os << sd.bookNo << "\t" << sd.units_sold << "\t" << sd.revenue << std::endl;
}



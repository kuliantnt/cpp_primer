//
// Created by lianlian on 17-3-27.
//

#ifndef CLINE_SALES_DATE_H
#define CLINE_SALES_DATE_H

#include <string>

class Sales_date {
    friend void print(std::ostream &os, Sales_date &sd);

public:
    Sales_date() = default;

    Sales_date(const std::string &bookNo, unsigned unit_sold, double price);


    static const std::string Sales_date::*date(){
        return &Sales_date::bookNo;
    };

private:
    std::string bookNo;      // implicitly initialized to the empty string
    unsigned units_sold = 0; // explicitly initialized
    double revenue = 0.0;
};


#endif //CLINE_SALES_DATE_H

//
// Created by lianlian on 16-11-7.
//

#ifndef CLINE_SALES_DATA_H
#define CLINE_SALES_DATA_H


#include <ostream>
#include <istream>
#include <string>
#include "user_define_error.h"

inline namespace Sales_date {
    class Sales_data {
        friend std::ostream &operator<<(std::ostream &, const Sales_data &); // output
        friend std::istream &operator>>(std::istream &is, Sales_data &rhs);

        friend Sales_data operator+(Sales_data &, Sales_data &);

        explicit operator std::string() const {
            return bookNo;
        };

        explicit operator double() const {
            return revenue;
        };
    public:
        Sales_data() = default;

        Sales_data &operator+=(const Sales_data &);

        std::string isbn() const {
            return this->bookNo;
        }


        Sales_data &combine(const Sales_data &rhs);

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

        double average() const {
            if (units_sold)
                return revenue / units_sold;
            else {
                return 0;
            }
        }
    };

    std::ostream &operator<<(std::ostream &, const Sales_data &); // output
    std::istream &operator>>(std::istream &is, Sales_data &rhs);

    Sales_data operator+(Sales_data &, Sales_data &);

}
#endif //CLINE_SALES_DATA_H

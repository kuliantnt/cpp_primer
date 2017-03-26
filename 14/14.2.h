//
// Created by lianlian on 16-10-25.
//

#ifndef CLINE_14_2_H
#define CLINE_14_2_H

#include <ostream>
#include <istream>
#include <string>
class Sales_data {
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
    friend std::istream& operator>>(std::istream& is, Sales_data& rhs);
    friend Sales_data operator+ (Sales_data&, Sales_data&) const;
public:
    Sales_data& operator+= (const Sales_data&);

    std::string isbn() const {
        return this->bookNo;
    }


    Sales_data &combine(const Sales_data &rhs) ;
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

std::ostream & operator<<(std::ostream& os, const Sales_data& rhs) {
    os << rhs.isbn() << rhs.units_sold << rhs.revenue << rhs.average();
    return os;
}

std::istream& operator>>(std::istream& is, Sales_data& rhs) {
    double price = 0.0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    if(is)
        rhs.revenue = price * rhs.units_sold;
    else
        rhs = Sales_data();
    return is;
}
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    this-> revenue += rhs.revenue;
    this -> units_sold += rhs.units_sold;
    return *this;
}
Sales_data operator+ (Sales_data& lhs, Sales_data& rhs) const{
    Sales_data result = lhs;
    result.combine(rhs);
    return result;
}
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
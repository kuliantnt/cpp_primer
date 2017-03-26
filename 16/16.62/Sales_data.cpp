//
// Created by lianlian on 16-11-7.
//

#include "Sales_data.h"

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
    this->revenue += rhs.revenue;
    this -> units_sold += rhs.units_sold;
    return *this;
}
Sales_data operator+ (Sales_data& lhs, Sales_data& rhs) {
    Sales_data result = lhs;
    result.combine(rhs);
    return result;
}
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

namespace std {
    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<std::string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}
#pragma once
#include <string>
class Sales_date
{
public:
    Sales_date();
    Sales_date(std::string isbn, unsigned number, double price);
    Sales_date(const Sales_date& sd);
    Sales_date(Sales_date&& sd);
    Sales_date& operator=(const Sales_date&);
    Sales_date& operator=(Sales_date&&);
    ~Sales_date();
    Sales_date& move(Sales_date&&);
private:
    std::string isbn;
    unsigned number = 0;
    double revenus = 0.0;
};


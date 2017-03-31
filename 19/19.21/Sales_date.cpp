#include "Sales_date.h"



Sales_date::Sales_date()
{
}

Sales_date::Sales_date(std::string isbn, unsigned number, double price) : isbn(isbn), number(number),revenus(number * price)
{
}

Sales_date::Sales_date(const Sales_date & sd)
{
    isbn = sd.isbn;
    number = sd.number;
    revenus = sd.revenus;
}


Sales_date::Sales_date(Sales_date && sd)
{
    using std::move;
    isbn = move(sd.isbn);
    number = move(sd.number);
    revenus = move(sd.revenus);
}

Sales_date & Sales_date::operator=(const Sales_date &sd)
{
    if (this != &sd) {
        isbn = sd.isbn;
        number = sd.number;
        revenus = sd.revenus;
    }
    return *this;
}

Sales_date & Sales_date::operator=(Sales_date &&sd)
{
    using std::move;
    isbn = move(sd.isbn);
    number = move(sd.number);
    revenus = move(sd.number);
    return *this;
}

Sales_date::~Sales_date()
{
    isbn.~basic_string();
}

Sales_date & Sales_date::move(Sales_date &&sd)
{
    if (this != &sd) {
        using std::move;
        isbn = move(sd.isbn);
        number = move(sd.number);
        revenus = move(sd.revenus);
    }
    return *this;
}

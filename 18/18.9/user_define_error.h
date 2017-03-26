//!
//! class name "用户自定义错误"
//! C++ primer 695 page
//! Created by lianlian on 17-2-4.
//!

#ifndef USER_DEFINE_ERROR_H
#define USER_DEFINE_ERROR_H
#include <stdexcept>
#include <string>
inline namespace user_define_error {


    class out_of_stock : public std::runtime_error {
    public:
        explicit out_of_stock(const std::string &string) : std::runtime_error(string) {}
    };

    class isbn_mismatch : public std::logic_error {
    public:
        explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}

        isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) :
                std::logic_error(s), left(lhs), right(rhs) {}

        const std::string left, right;
    };
}
#endif //USER_DEFINE_ERROR_H
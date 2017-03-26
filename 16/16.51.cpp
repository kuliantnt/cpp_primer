#include<iostream>

/**
 * @brief 16.41.cpp
 * @author lianlian
 * @version v1.0
 * @date 2016年11月25日14:59:33
 */

 template <typename T, typename...Argc>
         void foo (const T &t, const Argc& ... rest) {
    std::cout << sizeof...(Argc) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
};
//int main(int argc, char *argv[]) {
//    int i = 0;
//    double d = 3.14;
//    std::string s = "how now brown cow";
//    foo(i, s, 42, d);
//    foo(s, 42, "hi");
//    foo(d, s);
//    foo("hi");
//};

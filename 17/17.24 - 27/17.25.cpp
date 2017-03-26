#include <iostream>
#include <string>
#include <regex>

//
// Created by lianlian on 16-12-22.
//

/*int main(int argc, char * argv[]) {
    std::string phone = "(\\()?(\\d{3})(\\))?([-, ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(phone);
    std::string s;
    std::string fmt = "$2.$5.$7";
    while (getline(std::cin, s)) {
        using namespace std::regex_constants;
        std::string phone2 = "\\d{3}.\\d{3}.\\d{4}";
        std::regex r2(phone2);
        std::smatch m;
        std::string str = std::regex_replace(s, r, fmt, format_first_only);
        std::regex_search(str, m, r2);
        std::cout << m.str() << std::endl;
    }

}*/

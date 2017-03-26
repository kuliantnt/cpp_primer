#include <iostream>
#include <string>
#include <regex>

//
// Created by lianlian on 16-12-19.
//
void match(std::ostream& os, const std::string& str) {
//    std::string patten = "[^c]ie";
//    patten = "[[:alpha:]]" + patten + "[[:alpha:]]";
//    std::regex r(patten, std::regex::icase);
    try {
        std::regex r("[^c]ie", std::regex::icase);

        std::smatch result;
        if (std::regex_search(str, result, r)) {
            os << "is\n";
            os << result.str() << std::endl;
        } else {
            os << "not match\n";
        }
    } catch (std::regex_error e) {
        std::cout << e.what() << " \ncode: " << e.code() << std::endl;
    }
}

std::string input(std::istream& is){
    std::string str2;
    std::getline(is, str2);
    return str2;
}

//int main(int argc,char * argv[]){
//    std::cout << "Enter any word, please!\n";
//    std::string str;
//    str = input(std::cin);
//    match(std::cout, str);
//}
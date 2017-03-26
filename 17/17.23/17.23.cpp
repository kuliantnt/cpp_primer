//
// Created by lianlian on 16-12-22.
//

#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch& m);
void match(std::string& str){
    std::string patten = "(\\d{4})?([- ])?(\\d{5})";
    std::regex r(patten);
    for(std::sregex_iterator it(str.begin(),str.end(),r), end_it; it != end_it; ++it) {
        if (valid(*it)) {
            std::cout << "valid: " << it->str() << std::endl;
        } else {
            std::cout << "not valid: " << it->str() << std::endl;
        }
    }
}
bool valid(const std::smatch& m) {
    return m[1].matched ? m[2].matched : !m[2].matched;
}
/*
int main(int argc, char *argv[]){
    std::string str;
    while(getline(std::cin, str)){
        match(str);
    }
    return 0;
}*/

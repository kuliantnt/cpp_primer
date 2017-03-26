//
// Created by lianlian on 16-12-21.
//

#include <fstream>
#include <string>
#include <iostream>
#include <regex>
bool valid(const std::smatch& it);
void match(std::ifstream& ifs){
    try {
        std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(phone);
        std::smatch m;
        std::string s;
        while (getline(ifs, s)) {
            for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
                if (valid(*it)) {
                    std::cout << "valid: " << it->str() << std::endl;
                } else {
                    std::cout << "not valid: " << it->str() << std::endl;
                }
            }
        }
    }catch(std::regex_error e){
        std::cout << e.code() << "\n\t" << e.what();
    }
}
bool valid(const std::smatch& m) {
    if (m[1].matched) {
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    } else {
        return !m[3].matched && m[4].str() == m[6].str();
    }
}

/*int main(int argc, char *argv[]) {
    std::ifstream ifs;
    if (argc) {
        ifs.open(argv[1], std::ifstream::in);
    } else {
        ifs.open("files.txt", std::ifstream::in);
    }
    if (ifs) {
        match(ifs);
    }else{
        std::cerr << "open files error";
    }
}*/

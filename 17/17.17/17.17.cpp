//
// Created by lianlian on 16-12-21.
//

#include <regex>
#include <string>
#include <iostream>
#include <fstream>

std::ostream &print(std::ostream& os, std::string str);

void find(std::string & file) {
    std::string patten = "[^c]ei";
    patten = "[[:alpha:]]+" + patten + "[[:alpha:]]";
    std::regex r(patten, std::regex::icase);
    for(std::sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
        print(std::cout, it->str());
    }
}

std::ostream &print(std::ostream& os, std::string str) {
    os << str << "\n";
    return os;
}
/*
int main(int argc, char *argv[]) {
    std::ifstream ifs;\
    if (argc) {
        ifs.open(argv[1], std::fstream::in);

    } else {
        ifs.open("test.txt", std::fstream::in);
    }
    if(ifs) {
        std::string file;
        ifs >> file;
        ifs.close();
        find(file);
    }else{
        std::cout << " Stream's close !\n";
    }
}*/

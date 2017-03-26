//
// Created by lianlian on 16-10-28.
//

#ifndef READ_IN_FILES
#define READ_IN_FILES

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
/**
 * @brief　从文件中读取 提取单词,并返回vector<string>
 */
class read_in_files{
public:
    read_in_files(std::ifstream&);
    std::vector<std::string>& toVector();
private:
    std::string word; //储存临时变量
    std::vector<std::string> strVec; //用来存储单词
    std::ifstream& fs;
};


read_in_files::read_in_files(std::ifstream&s): fs(s){
    while(fs >> word)
        strVec.push_back(word);
}

std::vector<std::string>& read_in_files::toVector() {
    return strVec;
}


#endif //CLINE_14_38_H

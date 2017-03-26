/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//
// Created by lianlian on 17-1-16.
//
int main(int argc,char *argv[]){
    std::fstream inOut("/home/lianlian/文档/cline/release/17/17.37/text.txt",
                       std::fstream::ate | std::fstream::in| std::fstream::out);
     if(!inOut){
         std::cerr << "Unable to open file!" << std::endl;
         return EXIT_FAILURE;
     }
    //inOut 以ate 模式打开,因此一开始就定义其文件尾
    std::fstream::pos_type end_make = inOut.tellg();
    inOut.seekg(0,std::fstream::beg);
    size_t cnt = 0;
    std::string line;
    while(inOut && inOut.tellg() != end_make && getline(inOut, line)) {
        cnt += line.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, std::fstream::end);
        inOut << cnt;
        if (mark != end_make) {
            inOut << " ";
        }
        inOut.seekg(mark);

    }
    inOut.seekg(0,std::fstream::end);
    inOut<< "\n";
    return 0;
}
*/


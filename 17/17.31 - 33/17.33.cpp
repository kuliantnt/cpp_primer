#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <random>

//
// Created by lianlian on 17-1-1.
//
const std::string & transform(std::string word, const std::unordered_map<int, std::string> &m, int& max_size);

std::unordered_map<int, std::string> buildMap(std::ifstream &map_file, int& i);

void world_transform(std::ifstream& map_file, std::ifstream &input) {
    int max_size = 0;
    auto trans_map = buildMap(map_file , max_size);
    std::string text;
    while(getline(input, text)){
        std::istringstream stream(text);
        std::string word;
        bool firstWorld = true;
        while(stream >> word){
            if(firstWorld)
                firstWorld = false;
            else{
                std::cout << " " ;
            }
            std::cout << transform(word, trans_map, max_size);
        }
    }
}
std::unordered_map<int, std::string> buildMap(std::ifstream &map_file, int & i) {
    std::unordered_map<int, std::string> uMap;
    std::string str;
    //把随机数统计写入uMap中,不要问脸脸为什么只用前10个数字
    while (map_file >> str) {
        uMap[i] = str;
        i++;
    }
    return uMap;
}

const std::string & transform(std::string word, const std::unordered_map<int, std::string> &m, int & max_size){
    std::default_random_engine engine((unsigned long) time(0));
    std::uniform_int_distribution<int> distribution(0,max_size);
    auto map_it = m.find(distribution(engine));
    return map_it -> second;
}

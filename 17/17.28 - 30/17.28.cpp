#include <random>
#include <iostream>
#include <map>
#include <ctime>

//
// Created by lianlian on 16-12-26.
//
std::map<int,int> random_dome() {
    std::map<int, int> map1;
    std::default_random_engine e(time (0));
    std::uniform_int_distribution<unsigned int> u(0, 100);
    for (int i = 0; i != 100; ++i) {

        ++map1[u(e)];
    }
    return map1;
}

unsigned long random_dome2() {
    std::cout << "Enter a seed, please" << std::endl;
    int seed;
    std::cin >> seed;
    std::default_random_engine e;
    e.seed(seed);
    unsigned long i = e();
    std::cout << "e's = " << i << std::endl;
    return i;
}

unsigned long random_dome3(){
    std::cout << "Enter max and min size :" << std::endl;
    int max, min;
    std::cin >> max >> min;
    if(min > max)
        std::swap(max, min);
    std::default_random_engine e(time(0));
    std::uniform_int_distribution<int> u(min, max);
    std::cout << u(e) << std::endl;
}
//int main(int argc, char * argv[]) {
//    std::map<int,int> map1 = random_dome();
//    for (auto map_iter : map1) {
//        std::cout << map_iter.first << "\t" << map_iter.second << std::endl;
//    }
//    random_dome2();
//    random_dome3();
//}

#include <iostream>
#include <random>
#include <string>
//
// Create       d by lianlian on 16-12-29.
//
bool compare(int, int);
bool play (bool first){
    std::default_random_engine e(time(0));
    std::uniform_int_distribution<int> uniform(1,6);
    unsigned play;
    unsigned com ;
    do {
        if (first) {
            com = (unsigned int) uniform(e);
            std::cout << "Computer push number is: " << com << std::endl;
            std::cout << "Enter any key, please!" << std::endl;
            std::getchar();
            play = (unsigned int) uniform(e);
            std::cout << "Your push number is: " << play << std::endl;
        } else {
            std::cout << "Enter any key, please!" << std::endl;
            std::getchar();
            play = (unsigned int) uniform(e);
            std::cout << "Your push number is: " << play << std::endl;
            com = (unsigned int) uniform(e);
            std::cout << "Computer push number is: " << com << std::endl;
        }
    }while(compare(com, play));
    return play < com;

}

bool compare(int com, int play) {
    if (com == play) {
        std::cout << "Equals again, please!" << std::endl;
    }
    return com == play;
}

//int main(int argc, char *argv[])
//{
//    std::string resp;
//    std::default_random_engine e;
//    std::bernoulli_distribution b;
//    do{
//        bool first = b(e);
//        std::cout << (first? "We go first" : "you get to go first") << std::endl;
//        std::cout << ((play(first)) ? "sorry, you lost " : "Congrate, you win") << std::endl;
//    }while(std::cin >> resp && resp[0] == 'y');
//    std::cout << "Game over" << std::endl;
//}

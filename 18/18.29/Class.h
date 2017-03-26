//
// Created by lianlian on 17-3-21.
//

#ifndef CLINE_CLASS_H
#define CLINE_CLASS_H

#include <iostream>

class Class{
public:
    Class();
    Class(Class& cl);
    Class(int);
};

Class::Class() {
    std::cout << "using Class default construct" << std::endl;
}

Class::Class(Class &cl) {
    std::cout << "using Class copy construct" << std::endl;
}

Class::Class(int) {
    std::cout << "using Class int construct " << std::endl;

}

#endif //CLINE_CLASS_H

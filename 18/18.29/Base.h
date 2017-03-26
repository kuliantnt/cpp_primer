//
// Created by lianlian on 17-3-21.
//

#ifndef CLINE_BASE_H
#define CLINE_BASE_H

#include "Class.h"
class Base : public Class{
public:
    Base();
    Base(Base& cl);
    Base(int);
};

Base::Base() {
    std::cout << "using base default construct" << std::endl;
}

Base::Base(Base &cl) {
    std::cout << "using base copy construct" << std::endl;
}

Base::Base(int) {
    std::cout << "using base int construct " << std::endl;

}
#endif //CLINE_BASE_H

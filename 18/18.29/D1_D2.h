//
// Created by lianlian on 17-3-21.
//

#ifndef CLINE_D1_D2_H
#define CLINE_D1_D2_H

#include "Base.h"
class D1 : virtual public Base{
public:
    D1();
    D1(D1& cl);
    D1(int);
};

D1::D1() {
    std::cout << "using D1 default construct" << std::endl;
}

D1::D1(D1 &cl) {
    std::cout << "using D1 copy construct" << std::endl;
}

D1::D1(int) {
    std::cout << "using D1 int construct " << std::endl;

}
class D2 : virtual public Base{
public:
    D2();
    D2(D2& cl);
    D2(int);
};

D2::D2() {
    std::cout << "using D2 default construct" << std::endl;
}

D2::D2(D2 &cl) {
    std::cout << "using D2 copy construct" << std::endl;
}

D2::D2(int) {
    std::cout << "using D2 int construct " << std::endl;

}
#endif //CLINE_D1_D2_H

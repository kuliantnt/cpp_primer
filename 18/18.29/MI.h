//
// Created by lianlian on 17-3-21.
//

#ifndef CLINE_MI_H
#define CLINE_MI_H

#include "D1_D2.h"
class MI : public D1, public D2{
public:
    MI();
    MI(MI& cl);
    MI(int);
};

MI::MI() {
    std::cout << "using MI default construct" << std::endl;
}

MI::MI(MI &cl) {
    std::cout << "using MI copy construct" << std::endl;
}

MI::MI(int) {
    std::cout << "using MI int construct " << std::endl;

}
#endif //CLINE_MI_H

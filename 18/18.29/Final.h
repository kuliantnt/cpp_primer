//
// Created by lianlian on 17-3-21.
//

#ifndef CLINE_FINAL_H
#define CLINE_FINAL_H

#include "MI.h"
class Final : public MI,public Class{
public:
    Final();
    Final(Final& cl);
    Final(int);
};

Final::Final() {
    std::cout << "using Final default construct" << std::endl;
}

Final::Final(Final &cl) {
    std::cout << "using Final copy construct" << std::endl;
}

Final::Final(int) {
    std::cout << "using Final int construct " << std::endl;

}

#endif //CLINE_FINAL_H

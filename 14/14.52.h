//
// Created by lianlian on 16-11-1.
//

#ifndef CLINE_14_52_H
#define CLINE_14_52_H

struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
#endif //CLINE_14_52_H

//
// Created by lianlian on 16-11-7.
//

#ifndef CLINE_16_2_H
#define CLINE_16_2_H

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2)
        return -1;
    else if (v2 < v1)
        return 1;
    else
        return 0;
}
#endif //CLINE_16_2_H

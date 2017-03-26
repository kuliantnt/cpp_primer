//
// Created by lianlian on 16-11-15.
//

#ifndef CLINE_DEBUGDELETE_H
#define CLINE_DEBUGDELETE_H

#include <iostream>
class DebugDelete{
public:
    DebugDelete(std::ostream& s = std::cerr) : os(s) {};
    template <typename T> void operator() (T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};
#endif //CLINE_DEBUGDELETE_H

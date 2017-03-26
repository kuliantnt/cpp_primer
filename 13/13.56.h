//
// Created by lianlian on 16-10-25.
//

#ifndef CLINE_13_56_H
#define CLINE_13_56_H

#include <vector>
#include <algorithm>

class Foo{
public:
    Foo sorted() const &;
    Foo sorted() &&;
private:
    std::vector<int> data;

};
Foo Foo::sorted() const {
    Foo ret(*this);
    sort(ret.data.begin(),ret.data.end());
    return ret;
}

Foo Foo::sorted() {

}

#endif //CLINE_13_56_H

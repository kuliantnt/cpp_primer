//
// Created by lianlian on 17-3-27.
//

#ifndef CLINE_SCREEN_H
#define CLINE_SCREEN_H

#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    char get_cursor() const{
        return contents[cursor];
    }
    char get() const;
    char get(pos ht, pos wd) const;

private:
    std::string contents;
    pos cursor;
    pos height, width;
};
#endif //CLINE_SCREEN_H

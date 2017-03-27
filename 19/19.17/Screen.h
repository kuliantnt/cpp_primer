//Screen.h
#ifndef CLINE_SCREEN_H
#define CLINE_SCREEN_H
#include <string>
class Screen {
public:
    static const pos Screen::*data() {//19.12
        return &Screen::cursor;
    }
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get_cursor() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

private:
    typedef std::string::size_type pos;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
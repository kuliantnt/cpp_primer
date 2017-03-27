//Screen.h
#ifndef CLINE_SCREEN_H
#define CLINE_SCREEN_H
#include <string>
class Screen {
public:
    typedef std::string::size_type pos;
    using Action = Screen &(Screen::*)();

    Screen &home();

    Screen &forward();

    Screen &back();

    Screen &up();

    Screen &down();

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

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
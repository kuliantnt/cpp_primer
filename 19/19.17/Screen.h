//Screen.h
#ifndef CLINE_SCREEN_H
#define CLINE_SCREEN_H
#include <string>
class Screen {
public:
    typedef std::string::size_type pos;
    using Action = Screen &(Screen::*)();

    enum Directions {
        HOME,
        FORWARD,
        BACK,
        UP,
        DOWN
    };

    Screen &home();

    Screen &forward();

    Screen &back();

    Screen &up();

    Screen &down();

    static const pos Screen::*data() {//19.12
        return &Screen::cursor;
    }

    //construct function
    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    //get function
    char get() const { return contents[cursor]; }

    char get_cursor() const { return contents[cursor]; }

    inline char get(pos ht, pos wd) const;

    //move function
    Screen &move(pos r, pos c);
    Screen &move(Directions cm);

private:
    static Action Menu[];
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
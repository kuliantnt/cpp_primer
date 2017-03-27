#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

template <unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;

    using Action = Screen&(Screen::*)();

    enum Directions{
        HOME,
        FORWORD,
        BACK,
        UP,
        DOWN
    };

    Screen() = default;

    Screen(char c) : contents(H * W, c) {}

    Screen &move(pos, pos);

    Screen &operator<<(const char c);

    Screen &operator>>(char &c);

    //cursor move function
    Screen &home();

    Screen &forward();

    Screen &back();

    Screen &up();

    Screen &down();

    //out print
    friend std::ostream &operator<<(std::ostream &os, const Screen &c) {
        for (int i = 0; i != H; i++) {
            os << c.contents.substr(0, W) << std::endl;
        }
        return os;
    }

    //in print
    friend std::istream operator>>(std::istream &is, Screen &c) {
        char temp;
        is >> temp;
        c.contents = std::string(H * W, temp);
        return is;
    }

    //get char must inline
    char get() const {
        return this->contents[cursor];
    }

private:
    pos height = H, width = W;
    pos cursor = 0;
    std::string contents;
};


#endif

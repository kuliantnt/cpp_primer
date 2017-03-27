#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

template <unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;

    using Action = Screen& (Screen::*)();
    Screen() = default;

    Screen(char c) : contents(H * W, c) {}

    Screen &move(pos, pos);

    Screen &operator<<(const char c);

    Screen &operator>>(char &c);

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

    pos get_cursor const {
        return this->cursor;
    }

private:
    pos height = H, width = W;
    pos cursor = 0;
    std::string contents;
};

template <unsigned H, unsigned W>
inline
Screen<H,W>& Screen<H,W>::move(pos h, pos w) {
    auto temp = contents;
    contents += h * width + w;
};

template <unsigned H, unsigned W>
Screen<H,W> &Screen<H,W>::operator>>(char &c) {
    c = this->contents[cursor];
    return *this;
};

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::operator<<(const char c) {
    this->contents[cursor];
    return *this;
}

#endif

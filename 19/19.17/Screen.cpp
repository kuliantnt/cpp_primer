//
// Created by lianlian on 17-3-27.
//

#include "Screen.h"

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::home() {
    this->cursor = 0;
    return *this;
}

Screen &Screen::forward() {
    this->cursor += width;
    return *this;
}

Screen &Screen::back() {
    this->cursor -= width;
    return *this;
}

Screen &Screen::up() {
    ++this->cursor;
    return *this;
}

Screen &Screen::down() {
    --this->cursor;
    return *this;
}

Screen::Action Screen::Menu[] = {
        &Screen::home,
        &Screen::forward,
        &Screen::back,
        &Screen::up,
        &Screen::down
};

Screen &Screen::move(Screen::Directions cm) {
    return (this->* Menu[cm])();
}

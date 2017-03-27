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

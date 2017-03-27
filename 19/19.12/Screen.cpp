//
// Created by lianlian on 17-3-27.
//
#include "Screen.h"


char Screen::get() const {
    return contents[cursor];
}

char Screen::get(Screen::pos ht, Screen::pos wd) const {
    return contents[ht * width + wd];
}

const Screen::pos Screen::* Screen::date() {
    return &Screen::cursor;
}

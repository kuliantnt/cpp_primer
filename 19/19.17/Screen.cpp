//
// Created by lianlian on 17-3-27.
//

#include "Screen.h"

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

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::home() {
    return <#initializer#>;
}

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::forward()  {
    return <#initializer#>;
}

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::back() {
    return <#initializer#>;
}

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::up() {
    return <#initializer#>;
}

template <unsigned H,unsigned W>
Screen<H,W> &Screen<H,W>::down() {
    return <#initializer#>;
}

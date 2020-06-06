//
// Created by vlado on 5/6/20.
//

#include <conio.h>
#include "input.h"

input::keys input::pressed_key = none;

int getch_noblock();

void input::update() {
    int k = getch_noblock();
    pressed_key = static_cast<keys>(k);
}
bool input::get_key(input::keys key) {
    return pressed_key == key;
}

int getch_noblock() {
    if (_kbhit()) {
        return _getch();
    } else
        return -1;
}


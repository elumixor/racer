//
// Created by vlado on 5/6/20.
//

#include <printing.h>
#include "input.h"
#include "async_input.h"

input::keys pressed_key = input::keys::none;

void input::update() {
    int k = async_keypress();
    pressed_key = static_cast<keys>(k);
}

bool input::get_key(input::keys key) {
    return pressed_key == key;
}

void input::initialize() {
    set_conio_terminal_mode();
}



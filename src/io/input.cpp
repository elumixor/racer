//
// Created by vlado on 5/6/20.
//

#include "input.h"
#include "async_input.h"

input::Keys pressed_key = input::Keys::none;

void input::initialize() {
    set_conio_terminal_mode();
}

void input::update() {
    // Calls this *magic* function, that either returns they key pressed, or -1, if no key was pressed.
    int k = async_keypress();

    // Assign pressed key, cast to our enum
    pressed_key = static_cast<Keys>(k);
}

bool input::key_pressed(input::Keys key) {
    return pressed_key == key;
}

//
// Created by vlado on 5/6/20.
//

#ifndef RACER_INPUT_H
#define RACER_INPUT_H

namespace input {
    enum keys {
        w = 'w', a  = 'a', s = 's', d = 'd',
        left, right, up, down, // these produce two keystrokes... (complicated)
        esc = 27,
        none = -1
    };

    extern keys pressed_key;

    bool get_key(keys key);
    void update();
}

#endif //RACER_INPUT_H

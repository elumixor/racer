//
// Created by vlado on 5/6/20.
//

#ifndef RACER_INPUT_H
#define RACER_INPUT_H

namespace input {
    enum class keys {
        w = 'w', a  = 'a', s = 's', d = 'd', e = 'e',
        left, right, up, down, // these produce two keystrokes... (complicated)
        escape = 27, enter = 13,
        none = -1
    };
    bool get_key(keys key);
    void update();
    void initialize();
}


#endif //RACER_INPUT_H

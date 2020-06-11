//
// Created by vlado on 5/6/20.
//

#ifndef RACER_INPUT_H
#define RACER_INPUT_H

namespace input {
    /// Keys, that can be pressed. Initialized with chars to ease conversions.
    enum class Keys {
        w = 'w', a  = 'a', s = 's', d = 'd', e = 'e',
//        left, right, up, down, // todo: these produce two keystrokes, when pressed.
        escape = 27, enter = 13,
        none = -1
    };

    /// Initializes required terminal mode. See https://stackoverflow.com/a/448982/4932128 (non-blocking Linux input)
    void initialize();

    /// Gets current data from stdin, updates the currently pressed key.
    void update();

    /// Returns true if that key was pressed during the last update.
    bool key_pressed(Keys key);
}


#endif //RACER_INPUT_H

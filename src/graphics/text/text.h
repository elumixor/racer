//
// Created by vlado on 9/6/20.
//

#ifndef RACER_TEXT_H
#define RACER_TEXT_H

#include <graphics.h>

namespace text {
    void initialize();
    void free();
    void render(const char *string, const Point &top_left, color::type color1, color::type color2, int size);
}

#endif //RACER_TEXT_H

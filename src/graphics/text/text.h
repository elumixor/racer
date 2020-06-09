//
// Created by vlado on 9/6/20.
//

#ifndef RACER_TEXT_H
#define RACER_TEXT_H

#include <graphics.h>

namespace text {
    constexpr auto glyph_size = 8;

    struct Style {
        int font_size;
        color::type color_outline;
        color::type color_fill;
    };

    void initialize();

    void free();

    void render(const char *string, const Point &top_left, const text::Style& style);
}

#endif //RACER_TEXT_H

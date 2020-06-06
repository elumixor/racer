//
// Created by vlado on 5/6/20.
//

#ifndef RACER_RENDERER_H
#define RACER_RENDERER_H

#include "graphics/graphics.h"

namespace renderer {
    void initialize();

    void set_pixel(int x, int y, const Color &color);
    void clear_framebuffer(const Color &color = Color::clear);
    void set_rect(const Rect &rect, const Color &color);
    void set_text(const char* string, const Rect & rect);
    void render();
}
#endif //RACER_RENDERER_H

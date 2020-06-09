//
// Created by vlado on 5/6/20.
//

#ifndef RACER_RENDERER_H
#define RACER_RENDERER_H


#include <graphics.h>

namespace renderer {
    void initialize();

    void set_pixel(int x, int y, color::type color);
    void clear_framebuffer(color::type color = color::clear);
    void set_rect(const Rect &rect, color::type color);
    void set_glyph(char c, int x, int y, color::type color1, color::type color2, int size);
    void set_text(const char *string, const Point &top_left, color::type color1, color::type color2, int size);
    void render_frame();
    void on_exit();
}
#endif //RACER_RENDERER_H

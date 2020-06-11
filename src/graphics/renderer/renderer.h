//
// Created by vlado on 5/6/20.
//

#ifndef RACER_RENDERER_H
#define RACER_RENDERER_H


#include <graphics.h>

namespace renderer {
    /// Initializes framebuffer and setups low-lever lcd display registers.
    void initialize();

    /// Sets all framebuffer's pixels to the same (clear) color.
    void clear_framebuffer(color::type color = color::clear);

    /// Sets a single pixel in framebuffer to the specified color.
    void set_pixel(int x, int y, color::type color);

    /// Sets a rectangle in framebuffer to the specified color.
    void set_rect(const Rect &rect, color::type color);

    /// Renders current framebuffer's contents to display.
    void render_frame();

    /// Clears display and frees framebuffer.
    void on_exit();
}
#endif //RACER_RENDERER_H

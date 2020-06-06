//
// Created by vlado on 5/6/20.
//

#include "renderer.h"
#include "../io/screen.h"
#include "../output/printing.h"

// unsigned short: 16 bits
// R: 5 (15..11)
// G: 6 (10..5)
// B: 5 (4..0)
t_color *framebuffer;

void renderer::set_pixel(int x, int y, const Color &color) {
    framebuffer[x + y * screen::width] = color.value;
}

void renderer::set_rect(const Rect &rect, const Color &color) {
    int top = rect.top();
    int right = rect.right();

    for (int y = rect.bottom(); y < top; y++)
        for (int x = rect.left(); x < right; x++)
            set_pixel(x, y, color);
}

void renderer::clear_framebuffer(const Color &color) {
    for (int y = 0; y < screen::height; y++)
        for (int x = 0; x < screen::height; x++)
            set_pixel(x, y, color);
}

void renderer::initialize() {
    framebuffer = new t_color[screen::width * screen::height];
    clear_framebuffer();
}

void render() {
    // this will contain system-specific stuff
}


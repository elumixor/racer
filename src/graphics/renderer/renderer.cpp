//
// Created by vlado on 5/6/20.
//

#include "renderer.h"
#include "../../io/screen.h"
#include "printing.h"

#include "mzapo_regs.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include <math.h>
#include <c++/9/cstdio>

color::type *framebuffer;
unsigned char *parlcd_mem_base;

void renderer::set_pixel(int x, int y, color::type c) {
    framebuffer[x + y * screen::width] = c;
}

void renderer::set_rect(const Rect &rect, color::type c) {
    auto bottom = min(rect.bottom(), screen::height);
    auto right = min(rect.right(), screen::width);
    auto top = max(rect.top(), 0);
    auto left = max(rect.left(), 0);

    for (int y = top; y < bottom; y++)
        for (int x = left; x < right; x++)
            set_pixel(x, y, c);
}

void renderer::clear_framebuffer(color::type c) {
    for (int y = 0; y < screen::height; y++)
        for (int x = 0; x < screen::width; x++)
            set_pixel(x, y, c);
}

void renderer::initialize() {
    framebuffer = new color::type[screen::width * screen::height];
    clear_framebuffer();

    parlcd_mem_base = (unsigned char *) map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
}

void renderer::render_frame() {
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (int i = 0; i < 320 * 480; i++)
        parlcd_write_data(parlcd_mem_base, framebuffer[i]);
}

void renderer::on_exit() {
    clear_framebuffer();
    render_frame();
    delete[] framebuffer;
}


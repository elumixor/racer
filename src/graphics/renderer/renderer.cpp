//
// Created by vlado on 5/6/20.
//

#include "renderer.h"
#include "printing.h"

#include "mzapo_regs.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include <math.h>
#include <c++/9/cstdio>
#include <game_data.h>

color::type *framebuffer;
unsigned char *parlcd_mem_base;

void renderer::set_pixel(int x, int y, color::type color) {
    // No clamping as a design choice to increase performance. Do not render pixels outside the screen!
    // todo: this should be done with assertion and different build types
    framebuffer[x + y * game_data::SCREEN_WIDTH] = color;
}

void renderer::set_rect(const Rect &rect, color::type color) {
    // Clamp to prevent drawing outside the screen.
    // This is rather cheap, so we can do this here. Plus, this lets us easily draw partially-displayed objects.
    auto bottom = min(rect.bottom(), game_data::SCREEN_HEIGHT);
    auto right = min(rect.right(), game_data::SCREEN_WIDTH);
    auto top = max(rect.top(), 0);
    auto left = max(rect.left(), 0);

    // Draw all the pixels of given rectangle
    for (int y = top; y < bottom; y++)
        for (int x = left; x < right; x++)
            set_pixel(x, y, color);
}

void renderer::clear_framebuffer(color::type c) {
    // Set all pixels of framebuffer to the same color.
    for (int y = 0; y < game_data::SCREEN_HEIGHT; y++)
        for (int x = 0; x < game_data::SCREEN_WIDTH; x++)
            set_pixel(x, y, c);
}

void renderer::initialize() {
    framebuffer = new color::type[game_data::SCREEN_WIDTH * game_data::SCREEN_HEIGHT];

    // Initialize framebuffer's pixels to the clear color
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


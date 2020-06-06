//
// Created by vlado on 5/6/20.
//

#include "renderer.h"
#include "../io/screen.h"
#include "../output/printing.h"

#include "mzapo_regs.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"

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
        for (int x = 0; x < screen::width; x++)
            set_pixel(x, y, color);
}
unsigned char *parlcd_mem_base;

void renderer::initialize() {
    framebuffer = new t_color[screen::width * screen::height];
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
    delete [] framebuffer;
}


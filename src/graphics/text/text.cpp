//
// Created by vlado on 9/6/20.
//

#include <renderer/renderer.h>
#include <c++/9/cstdio>
#include "text.h"


constexpr auto glyph_size = 8;
constexpr auto num_letters = 'z' - 'a' + 1;
constexpr auto num_digits = '9' - '0' + 1;
constexpr auto num_special = 3; // '!' '.' '-'
constexpr auto num_alphanumeric = num_letters + num_digits;
constexpr auto num_total = num_alphanumeric + num_special;


constexpr int get_index(char c) {
    switch (c) {
        case '!':
            return num_alphanumeric;
        case '.':
            return num_alphanumeric + 1;
        case '-':
            return num_alphanumeric + 2;
        default:
            break;
    }

    if (c >= 'a')
        return c - 'a';

    // assume only numbers are left
    return c - '0' + num_letters;
}

struct Glyph {
    Point *pixels_color1{nullptr};
    Point *pixels_color2{nullptr};
    int num_pixels_color1{-1};
    int num_pixels_color2{-1};

    ~Glyph() {
        delete[] pixels_color1;
        delete[] pixels_color2;
    }
};

Glyph *glyphs;

void render_scaled_pixels(const Point *pixels, int length, int x, int y, color::type color, int size) {
    for (int i = 0; i < length; ++i) {
        auto p = pixels + i;

        int p_x = p->x * size + x;
        int p_y = p->y * size + y;

        // render scaled pixes, which is a rect
        for (int s_x = 0; s_x < size; ++s_x)
            for (int s_y = 0; s_y < size; ++s_y)
                renderer::set_pixel(p_x + s_x, p_y + s_y, color);
    }
}

void render_glyph(char c, int x, int y, color::type color1, color::type color2, int size) {
    auto g = glyphs + get_index(c);

    render_scaled_pixels(g->pixels_color1, g->num_pixels_color1, x, y, color1, size);
    render_scaled_pixels(g->pixels_color2, g->num_pixels_color2, x, y, color2, size);
}

void text::render(const char *string, const Point &top_left, color::type color1, color::type color2, int size) {
    auto x = top_left.x;
    auto y = top_left.y;
    int i = 0;
    for (const char *k = string; *k != '\0'; ++k) {

        if (*k == ' ') {
            ++i;
            continue;
        }

        if (*k == '\n') {
            i = 0;
            y += size * glyph_size;
            continue;
        }

        render_glyph(*k, x + i * glyph_size * size, y, color1, color2, size);
        ++i;
    }
}

void text::initialize() {
    glyphs = new Glyph[num_total];

    auto ptr = fopen("./textures/glyphs", "rb");

    int x;
    int y;

    for (int i{0}; i < num_total; ++i) {
        auto g = glyphs + i;

        fread(&g->num_pixels_color1, sizeof(int), 1, ptr);
        g->pixels_color1 = new Point[g->num_pixels_color1];

        for (int j{0}; j < g->num_pixels_color1; ++j) {
            fread(&x, sizeof(int), 1, ptr);
            fread(&y, sizeof(int), 1, ptr);

            auto point = g->pixels_color1 + j;

            point->x = x;
            point->y = y;
        }

        fread(&g->num_pixels_color2, sizeof(int), 1, ptr);
        g->pixels_color2 = new Point[g->num_pixels_color2];

        for (int j{0}; j < g->num_pixels_color2; ++j) {
            fread(&x, sizeof(int), 1, ptr);
            fread(&y, sizeof(int), 1, ptr);

            auto point = g->pixels_color2 + j;

            point->x = x;
            point->y = y;
        }
    }

    fclose(ptr);
}

void text::free() {
    delete[] glyphs;
}

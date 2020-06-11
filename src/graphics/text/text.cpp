//
// Created by vlado on 9/6/20.
//

#include <renderer/renderer.h>
#include <c++/9/cstdio>
#include <game_data.h>
#include "text.h"


constexpr auto num_letters = 'z' - 'a' + 1;
constexpr auto num_digits = '9' - '0' + 1;
constexpr auto num_special = 3; // '!' '.' '-'
constexpr auto num_alphanumeric = num_letters + num_digits;
constexpr auto num_total = num_alphanumeric + num_special;

// Returns the index of the glyph, corresponding to the char.
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
    Point *pixels_outline{nullptr};
    Point *pixels_fill{nullptr};
    int num_pixels_outline{-1};
    int num_pixels_fill{-1};

    ~Glyph() {
        delete[] pixels_outline;
        delete[] pixels_fill;
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
            for (int s_y = 0; s_y < size; ++s_y) {
                int x1 = p_x + s_x;
                int y1 = p_y + s_y;

                if (x1 >= 0 && x1 < game_data::SCREEN_WIDTH && y1 >= 0 && y1 < game_data::SCREEN_HEIGHT)
                    renderer::set_pixel(x1, y1, color);
            }
    }
}

void render_glyph(char c, int x, int y, const text::Style &style) {
    auto g = glyphs + get_index(c);

    render_scaled_pixels(g->pixels_outline, g->num_pixels_outline, x, y, style.color_outline, style.font_size);
    render_scaled_pixels(g->pixels_fill, g->num_pixels_fill, x, y, style.color_fill, style.font_size);
}

void text::render(const char *string, const Point &top_left, const text::Style &style) {
    auto y = top_left.y;
    int i = 0;

    for (const char *k = string; *k != '\0'; ++k) {
        // Special case where we receive a space. We simply skip this char.
        if (*k == ' ') {
            ++i;
            continue;
        }

        // Special case where we receive a space. We add to y coordinate of the starting point of new glyphs.
        if (*k == '\n') {
            i = 0;
            y += style.font_size * glyph_size;
            continue;
        }

        render_glyph(*k, top_left.x + i * glyph_size * style.font_size, y, style);
        ++i;
    }
}

void text::initialize() {
    // Create glyph storage
    glyphs = new Glyph[num_total];

    // We will create glyphs, where each glyph is comprised of two colors.
    // We first read the number of outline pixels, then locations of those pixels.
    // Then, we will read the number of fill pixels, and locations of those pixels.

    auto ptr = fopen("./textures/glyphs", "rb");

    int x;
    int y;

    for (int i{0}; i < num_total; ++i) {
        // Pointer to the current glyph
        auto g = glyphs + i;

        // Read pixels of the outline color
        fread(&g->num_pixels_outline, sizeof(int), 1, ptr);
        g->pixels_outline = new Point[g->num_pixels_outline];

        for (int j{0}; j < g->num_pixels_outline; ++j) {
            fread(&x, sizeof(int), 1, ptr);
            fread(&y, sizeof(int), 1, ptr);

            auto point = g->pixels_outline + j;

            point->x = x;
            point->y = y;
        }

        // Read pixels of the fill color
        fread(&g->num_pixels_fill, sizeof(int), 1, ptr);
        g->pixels_fill = new Point[g->num_pixels_fill];

        for (int j{0}; j < g->num_pixels_fill; ++j) {
            fread(&x, sizeof(int), 1, ptr);
            fread(&y, sizeof(int), 1, ptr);

            auto point = g->pixels_fill + j;

            point->x = x;
            point->y = y;
        }
    }

    fclose(ptr);
}

void text::free() {
    delete[] glyphs;
}

//
// Created by vlado on 9/6/20.
//

#ifndef RACER_TEXT_H
#define RACER_TEXT_H

#include <graphics.h>

namespace text {
    constexpr auto glyph_size = 8;

    /// Defines how the text will be rendered. Our font comprises two colors: outline and fill.
    struct Style {
        /// resulting glyph will have a size of glyph_size, multiplied by this size
        int font_size;

        /// Color of the outline (black in font image)
        color::type color_outline;

        /// Color of the fill (red in font image)
        color::type color_fill;

        /// Returns the glyph size in pixels, wrt font size
        inline int glyph_size() const { return font_size * text::glyph_size; }
    };

    /// Reads font file and loads glyphs into memory.
    void initialize();

    /// Frees loaded glyphs
    void free();

    /// Renders a string at position, using provided style
    void render(const char *string, const Point &top_left, const text::Style &style);
}

#endif //RACER_TEXT_H

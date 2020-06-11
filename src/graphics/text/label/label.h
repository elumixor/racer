//
// Created by vlado on 9/6/20.
//

#ifndef RACER_LABEL_H
#define RACER_LABEL_H


#include <graphics.h>
#include <text/text.h>
#include <game_data.h>
#include <c++/9/cstring>

namespace AnchorX {
    enum AnchorX {
        left,
        center,
        right
    };
}

namespace AnchorY {
    enum AnchorY {
        top,
        center,
        bottom
    };
}

/// Label encapsulates rendering given text with given style.
struct Label {
    /// Text to be rendered
    const char *string;

    /// Style to render with
    text::Style style;

    /// Length of the strings in pixels (wrt current style)
    inline int width() const { return style.glyph_size() * strlen(string); }

    /// Renders current label at position using specified anchoring within the string
    /// which determines where does the *position* point to within this string.
    void render(const Point &position, AnchorX::AnchorX anchor_x = AnchorX::left, AnchorY::AnchorY anchor_y = AnchorY::top) const;

    // constexpr everything!
    inline constexpr Label(const char *string, const text::Style &style) : string{string}, style{style} {}
};


#endif //RACER_LABEL_H

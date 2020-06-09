//
// Created by vlado on 9/6/20.
//

#ifndef RACER_LABEL_H
#define RACER_LABEL_H


#include <graphics.h>
#include <text/text.h>
#include <game_data.h>

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

struct Label {
    const char *string;
    text::Style style;
    int glyph_size() const;


    void render(const Point &position, AnchorX::AnchorX anchor_x = AnchorX::left, AnchorY::AnchorY anchor_y = AnchorY::top) const;

    inline constexpr Label(const char *string, const text::Style &style) : string{string}, style{style} {}
};


#endif //RACER_LABEL_H

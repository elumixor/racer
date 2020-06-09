//
// Created by vlado on 9/6/20.
//

#include "label.h"
#include <text/text.h>
#include <screen.h>

void Label::render(const Point &position, AnchorX::AnchorX anchor_x, AnchorY::AnchorY anchor_y) const {
    auto height = glyph_size();
    auto width = strlen(string) * height;
//    auto ax = anchor_x == AnchorX::left ? 0 : anchor_x == AnchorX::center ? 1 : 2;
//    auto ay = anchor_y == AnchorY::top ? 0 : anchor_y == AnchorY::center ? 1 : 2;
    const Point pos{position.x - (int) (anchor_x * width / 2), position.y - (int) (anchor_y * height / 2)};
    text::render(string, pos, style);
}

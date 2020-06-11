//
// Created by vlado on 9/6/20.
//

#include "label.h"

void Label::render(const Point &position, AnchorX::AnchorX anchor_x, AnchorY::AnchorY anchor_y) const {
    const Point pos{position.x - (int) (anchor_x * width() / 2), position.y - (int) (anchor_y * style.glyph_size() / 2)};
    text::render(string, pos, style);
}

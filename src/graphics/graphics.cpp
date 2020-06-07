//
// Created by vlado on 6/6/20.
//

#include <renderer/renderer.h>
#include <printing.h>
#include "graphics.h"

void Texture::render(const Point &top_left) const {
    for (int r{0}; r < num_rectangles; ++r) {
        const Rect &rectangle = rectangles[r];
        auto color = colors[r];
        renderer::set_rect(rectangle + top_left, color);
    }
}

Texture::~Texture() {
    delete colors;
    delete rectangles;
}

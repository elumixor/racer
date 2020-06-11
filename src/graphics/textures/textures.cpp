//
// Created by vlado on 7/6/20.
//

#include <c++/9/cstdio>
#include <printing.h>
#include <renderer/renderer.h>
#include "textures.h"

const Texture *textures::player_slow;
const Texture *textures::player_medium;
const Texture *textures::player_fast;
const Texture *textures::rival_slow;
const Texture *textures::rival_medium;
const Texture *textures::rival_fast;
const Texture *textures::box_small;
const Texture *textures::box_big;
const Texture *textures::box_wide_small;
const Texture *textures::box_wide_big;

const Texture *read_texture_file(const char *file_path) {
    auto ptr = fopen(file_path, "rb");

    // Each Texture is an array of colored rectangles. We read the file as:
    //
    //   read number of rectangles
    //   (for each rectangle):
    //      read color
    //      read rectangle (left, top, width, height)
    //
    // Format is different (i.e. from (top left point, right bottom point)) due to designer specification.

    unsigned char num_rectanles;
    int top, left, height, width;

    fread(&num_rectanles, sizeof(unsigned char), 1, ptr);

    auto rectangles = new Rect[num_rectanles];
    auto colors = new color::type[num_rectanles];

    for (int r = 0; r < num_rectanles; ++r) {
        fread(colors + r, sizeof(color::type), 1, ptr);

        fread(&left, sizeof(int), 1, ptr);
        fread(&top, sizeof(int), 1, ptr);
        fread(&width, sizeof(int), 1, ptr);
        fread(&height, sizeof(int), 1, ptr);

        auto rect = rectangles + r;

        rect->top_(top);
        rect->left_(left);
        rect->bottom_(top + height);
        rect->right_(left + width);
    }

    auto t = new Texture(rectangles, colors, num_rectanles);
    fclose(ptr);
    return t;
}

void textures::initialize() {
    // here we initialize all textures (not that many) from files into memory
    player_slow = read_texture_file("./textures/player_slow");
    player_medium = read_texture_file("./textures/player_medium");
    player_fast = read_texture_file("./textures/player_fast");
    rival_slow = read_texture_file("./textures/rival_slow");
    rival_medium = read_texture_file("./textures/rival_medium");
    rival_fast = read_texture_file("./textures/rival_fast");
    box_small = read_texture_file("./textures/box_small");
    box_big = read_texture_file("./textures/box_big");
    box_wide_small = read_texture_file("./textures/box_wide_small");
    box_wide_big = read_texture_file("./textures/box_wide_big");
}
void textures::free() {
    // here we free all the textures
    delete player_slow;
    delete player_medium;
    delete player_fast;
    delete rival_slow;
    delete rival_medium;
    delete rival_fast;
    delete box_small;
    delete box_big;
    delete box_wide_small;
    delete box_wide_big;
}


void Texture::render(const Point &top_left) const {
    for (int r{0}; r < num_rectangles; ++r) {
        const Rect &rectangle = rectangles[r];
        auto color = colors[r];
        renderer::set_rect(rectangle + top_left, color);
    }
}

Texture::~Texture() {
    delete[] colors;
    delete[] rectangles;
}

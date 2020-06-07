//
// Created by vlado on 7/6/20.
//

#include <c++/9/cstdio>
#include <printing.h>
#include "textures.h"

const Texture *textures::player_slow;
const Texture *textures::player_medium;
const Texture *textures::player_fast;
const Texture *textures::rival_slow;
const Texture *textures::rival_medium;
const Texture *textures::rival_fast;
const Texture *textures::obstacle_small;
const Texture *textures::obstacle_big;
const Texture *textures::obstacle_wide_small;
const Texture *textures::obstacle_wide_big;

const Texture *from_bitmap(const char *file_path) {
    // todo: create .tex files
    // todo: read from binary files: heigth, width, pixels
//    unsigned char buffer[10];
    FILE *ptr;
    ptr = fopen(file_path, "rb");  // r for read, b for binary

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

void textures::load() {
    // here we load all textures (not that many) from files into memory
    player_slow = from_bitmap("./textures/player_slow.texture");
    player_medium = from_bitmap("./textures/player_medium.texture");
    player_fast = from_bitmap("./textures/player_fast.texture");
    rival_slow = from_bitmap("./textures/rival_slow.texture");
    rival_medium = from_bitmap("./textures/rival_medium.texture");
    rival_fast = from_bitmap("./textures/rival_fast.texture");
    obstacle_small = from_bitmap("./textures/obstacle_small.texture");
    obstacle_big = from_bitmap("./textures/obstacle_big.texture");
    obstacle_wide_small = from_bitmap("./textures/obstacle_wide_small.texture");
    obstacle_wide_big = from_bitmap("./textures/obstacle_wide_big.texture");
}
void textures::free() {
    // here we free all the textures
    delete player_slow;
    delete player_medium;
    delete player_fast;
    delete rival_slow;
    delete rival_medium;
    delete rival_fast;
    delete obstacle_small;
    delete obstacle_big;
    delete obstacle_wide_small;
    delete obstacle_wide_big;
}


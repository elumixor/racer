//
// Created by vlado on 7/6/20.
//

#ifndef RACER_TEXTURES_H
#define RACER_TEXTURES_H

#include <graphics.h>

namespace textures {
    extern const Texture *player_slow;
    extern const Texture *player_medium;
    extern const Texture *player_fast;

    extern const Texture *rival_slow;
    extern const Texture *rival_medium;
    extern const Texture *rival_fast;

    extern const Texture *box_small;
    extern const Texture *box_big;
    extern const Texture *box_wide_small;
    extern const Texture *box_wide_big;

    void load();
    void free();
}

#endif //RACER_TEXTURES_H

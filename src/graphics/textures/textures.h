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

    extern const Texture *obstacle_small;
    extern const Texture *obstacle_big;
    extern const Texture *obstacle_wide_small;
    extern const Texture *obstacle_wide_big;

    void load();
    void free();
}

#endif //RACER_TEXTURES_H

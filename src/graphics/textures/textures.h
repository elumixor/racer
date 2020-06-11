//
// Created by vlado on 7/6/20.
//

#ifndef RACER_TEXTURES_H
#define RACER_TEXTURES_H

#include <graphics.h>

/// For us, texture is simply an array of colored rectangles.
/// (internally two arrays of rectangles and colors)
struct Texture {
    const Rect *rectangles;
    const color::type *colors;
    const int num_rectangles;
public:
    inline Texture(const Rect *rectangles, const color::type *colors, int num_rectangles) :
            rectangles{rectangles}, colors{colors}, num_rectangles{num_rectangles} {}
    void render(const Point &top_left) const;

    ~Texture();
};

namespace textures {
    /* Images of cars and obstacles, loaded into memory */

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

    /// Reads binary texture data, creates textures and loads them into memory
    void initialize();

    /// Frees texture data
    void free();
}


#endif //RACER_TEXTURES_H

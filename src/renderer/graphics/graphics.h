//
// Created by vlado on 6/6/20.
//

#ifndef RACER_GRAPHICS_H
#define RACER_GRAPHICS_H

// unsigned short: 16 bits
// R: 5 (15..11)
// G: 6 (10..5)
// B: 5 (4..0)

constexpr unsigned RED_BITS{5u};
constexpr unsigned GREEN_BITS{6u};
constexpr unsigned BLUE_BITS{5u};

constexpr unsigned RED_MAX{(1u << RED_BITS) - 1};
constexpr unsigned GREEN_MAX{(1u << GREEN_BITS) - 1};
constexpr unsigned BLUE_MAX{(1u << BLUE_BITS) - 1};

using t_color = unsigned short;

struct Color {
    t_color value;

    explicit Color(t_color = 0u);
    Color(float r, float g, float b);

    static Color clear;
};

struct Point {
    int x, y;
};

struct Rect {
    Point top_left;
    Point bottom_right;

    inline int top() const { return top_left.y; }
    inline int bottom() const { return bottom_right.y; }
    inline int left() const { return top_left.x; }
    inline int right() const { return bottom_right.x; }
};

#endif //RACER_GRAPHICS_H

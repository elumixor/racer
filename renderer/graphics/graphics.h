//
// Created by vlado on 6/6/20.
//

#ifndef RACER_GRAPHICS_H
#define RACER_GRAPHICS_H

using t_color = unsigned short;

struct Color {
    static Color clear;

    t_color value;
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

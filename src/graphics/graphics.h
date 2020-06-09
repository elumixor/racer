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

namespace color {
    using type = unsigned short;

    constexpr type rgb(float r, float g, float b) {
        return static_cast<color::type>(static_cast<color::type>(b * BLUE_MAX) +
                                        (static_cast<color::type>(g * GREEN_MAX) << BLUE_BITS) +
                                        (static_cast<color::type>(r * RED_MAX) << (BLUE_BITS + GREEN_BITS)));
    }

    constexpr type white = rgb(1, 1, 1);
    constexpr type black = rgb(0, 0, 0);
    constexpr type red = rgb(1, 0, 0);
    constexpr type green = rgb(0, 1, 0);
    constexpr type blue = rgb(0, 0, 1);

    constexpr type clear = black;
    constexpr color::type saturate(color::type color, float factor) {
        return static_cast<color::type>(static_cast<float>(color) * factor);
    }
}

struct Point;
using Vector = Point;

struct Point {
    int x{0}, y{0};

    inline constexpr Point() = default;
    inline constexpr Point(int x, int y) : x{x}, y{y} {}

    inline Point operator+(const Vector &translation) const { return {x + translation.x, y + translation.y}; }
};


struct Rect {
    Point top_left{};
    Point bottom_right{};

    inline int top() const { return top_left.y; }
    inline int bottom() const { return bottom_right.y; }
    inline int left() const { return top_left.x; }
    inline int right() const { return bottom_right.x; }

    inline void top_(int y) { top_left.y = y; }
    inline void bottom_(int y) { bottom_right.y = y; }
    inline void left_(int x) { top_left.x = x; }
    inline void right_(int x) { bottom_right.x = x; }

    inline Rect() = default;

    inline constexpr Rect(const Point &top_left, const Point &bottom_right) : top_left{top_left}, bottom_right{bottom_right} {}
    inline Rect operator+(const Vector &translation) const { return {top_left + translation, bottom_right + translation}; }
};

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

void render_text(const char *string, const Point &top_left, int size = 1);

#endif //RACER_GRAPHICS_H

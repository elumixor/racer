//
// Created by vlado on 7/6/20.
//

#ifndef RACER_MATH_H
#define RACER_MATH_H

template<typename T>
constexpr T max(const T &a, const T &b) {
    return a > b ? a : b;
}

template<typename T>
constexpr T min(const T &a, const T &b) {
    return a <= b ? a : b;
}

template<typename T>
constexpr T clamp(const T &a, const T &min, const T &max) {
    return a < min ? min : (a > max ? max : a);
}

#endif //RACER_MATH_H

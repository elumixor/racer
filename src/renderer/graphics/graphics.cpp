//
// Created by vlado on 6/6/20.
//

#include "graphics.h"
#include "../../output/printing.h"

Color Color::clear = Color();

Color::Color(t_color c) : value{c} {}
Color::Color(float r, float g, float b) :
        value{static_cast<t_color>(static_cast<t_color>(b * BLUE_MAX) +
                                   (static_cast<t_color>(g * GREEN_MAX) << BLUE_BITS) +
                                   (static_cast<t_color>(r * RED_MAX) << (BLUE_BITS + GREEN_BITS)))} {}

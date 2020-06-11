//
// Created by vlado on 6/6/20.
//

#include <c++/9/cmath>
#include "player.h"
#include "../../io/input.h"

void Player::update() {
    if (input::key_pressed(input::Keys::w) && line > 0) {
        --line;
    } else if (input::key_pressed(input::Keys::s) && line < 2) {
        ++line;
    }

    speed += 0.1f * acceleration / sqrt(speed);
    render();
}

Rect Player::get_collider() const {
    auto top = game_data::LINE_MARGIN + line * game_data::LINE_SIZE;
    auto left = game_data::LINE_MARGIN;
    auto right = left + width;
    auto bottom = top + game_data::CAR_HEIGHT;

    return {{left,  top},
            {right, bottom}};
}

void Player::render() {
    auto top = game_data::LINE_MARGIN + line * game_data::LINE_SIZE;
    auto left = game_data::LINE_MARGIN;

    texture->render({left, top});
}

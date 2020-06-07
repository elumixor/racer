//
// Created by vlado on 6/6/20.
//

#include <c++/9/cmath>
#include "obstacle.h"
#include "../../game_data/game_data.h"

void Obstacle::on_update() {
    x -= speed;

    render();
}

void Obstacle::render() {
    auto top = game_data::LINE_MARGIN + line * game_data::LINE_SIZE;
    auto left = (int) lround(x);

    texture->render({left, top});
}
bool Obstacle::out_of_view() const {
    return (int) lround(x) + width < 0;
}

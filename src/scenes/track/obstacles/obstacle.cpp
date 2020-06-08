//
// Created by vlado on 6/6/20.
//

#include <c++/9/cmath>
#include "obstacle.h"
#include "rival.h"
#include "box_obstacle.h"

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

constexpr bool is_box(game_data::ObstacleType type) {
    return type == game_data::ObstacleType::box_small ||
           type == game_data::ObstacleType::box_wide_small ||
           type == game_data::ObstacleType::box_big ||
           type == game_data::ObstacleType::box_wide_big;
}

Obstacle *Obstacle::from_type(game_data::ObstacleType type, float player_speed) {
    if (is_box(type))
        return new BoxObstacle(type, player_speed);

    return new Rival(type, player_speed);
}

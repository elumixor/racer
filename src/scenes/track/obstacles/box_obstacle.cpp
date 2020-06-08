//
// Created by Vladyslav Yazykov on 08/06/2020.
//

#include <stdlib.h>
#include "box_obstacle.h"
#include "textures/textures.h"

int get_random_line(game_data::ObstacleType type) {
    switch (type) {
        case game_data::ObstacleType::box_small:
        case game_data::ObstacleType::box_wide_small:
            return rand() % 3;
        default:
            return rand() % 2;
    }
}
constexpr int get_width(game_data::ObstacleType type) {
    switch (type) {
        case game_data::ObstacleType::box_small:
        case game_data::ObstacleType::box_wide_small:
            return 80;
        default:
            return 120;
    }
}

BoxObstacle::BoxObstacle(game_data::ObstacleType type, float player_speed) :
        Obstacle{get_random_line(type), 0, player_speed, game_data::get_texture(type), get_width(type)} {}

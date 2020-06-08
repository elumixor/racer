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
            return rand() % game_data::NUM_LINES;
        default:
            return rand() % (game_data::NUM_LINES - 1);
    }
}
constexpr int get_width(game_data::ObstacleType type) {
    switch (type) {
        case game_data::ObstacleType::box_small:
        case game_data::ObstacleType::box_wide_small:
            return game_data::OBSTACLE_WIDTH;
        default:
            return game_data::OBSTACLE_WIDTH_BIG;
    }
}
constexpr int get_height(game_data::ObstacleType type) {
    switch (type) {
        case game_data::ObstacleType::box_small:
        case game_data::ObstacleType::box_big:
            return game_data::OBSTACLE_HEIGHT;
        default:
            return game_data::OBSTACLE_WIDE_HEIGHT;
    }
}

BoxObstacle::BoxObstacle(game_data::ObstacleType type, float player_speed) :
        Obstacle{get_random_line(type), 0, player_speed, game_data::get_texture(type), get_width(type), get_height(type)} {}

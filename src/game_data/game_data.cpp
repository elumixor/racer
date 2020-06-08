//
// Created by vlado on 7/6/20.
//

#include <stdlib.h>
#include <exceptions.h>
#include "game_data.h"
#include "textures/textures.h"

game_data::CarType game_data::selected_car = game_data::DefaultCar;
const Texture *game_data::get_texture(game_data::CarType car_type) {
    switch (car_type) {
        case game_data::CarType::slow:
            return textures::player_slow;
        case game_data::CarType::medium:
            return textures::player_medium;
        case game_data::CarType::fast:
            return textures::player_fast;
    }

    throw InvalidArgumentException("Invalid car type");
}
game_data::ObstacleType game_data::get_random_obstacle_type() {
    auto r = rand() % game_data::NUM_OBSTACLE_TYPES;
    return game_data::ObstacleType(r);
}
const Texture *game_data::get_texture(game_data::ObstacleType obstacle_type) {
    switch (obstacle_type) {
        case ObstacleType::box_small:
            return textures::box_small;
        case ObstacleType::box_wide_small:
            return textures::box_wide_small;
        case ObstacleType::box_big:
            return textures::box_big;
        case ObstacleType::box_wide_big:
            return textures::box_wide_big;
        case ObstacleType::rival_slow:
            return textures::rival_slow;
        case ObstacleType::rival_medium:
            return textures::rival_medium;
        case ObstacleType::rival_fast:
            return textures::rival_fast;
    }

    throw InvalidArgumentException("Invalid obstacle type");
}

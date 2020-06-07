//
// Created by vlado on 7/6/20.
//

#include "game_data.h"
#include "textures/textures.h"

game_data::CarType game_data::selected_car = game_data::DefaultCar;
const Texture *game_data::get_player_car(game_data::CarType car_type) {
    switch (car_type) {
        case game_data::CarType::slow:
            return textures::player_slow;
        case game_data::CarType::medium:
            return textures::player_medium;
        case game_data::CarType::fast:
        default:
            return textures::player_fast;
    }
}

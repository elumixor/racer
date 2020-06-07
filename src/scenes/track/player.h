//
// Created by vlado on 6/6/20.
//

#ifndef RACER_PLAYER_H
#define RACER_PLAYER_H


#include <component.h>
#include <graphics.h>
#include "../../game_data/game_data.h"

class Player : public Component {
    float acceleration;
    const Texture *texture;
    int line{1};

    void render();
public:
    float speed{game_data::CAR_BASE_SPEED};

    explicit inline Player(game_data::CarType car_type) :
            acceleration{game_data::get_acceleration(car_type)},
            texture{game_data::get_player_car(car_type)} {}

    void on_update() override;
};


#endif //RACER_PLAYER_H

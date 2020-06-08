//
// Created by vlado on 6/6/20.
//

#ifndef RACER_PLAYER_H
#define RACER_PLAYER_H


#include <component.h>
#include <graphics.h>
#include <game_data.h>

class Player : public Component {
    float acceleration;
    const Texture *texture;
    int line{game_data::PLAYER_STARTING_LINE};
    int width;
    void render();
public:
    float speed;

    Rect get_collider() const;

    explicit inline Player(game_data::CarType car_type) :
            acceleration{game_data::get_acceleration(car_type)},
            texture{game_data::get_texture(car_type)},
            width{game_data::get_width(car_type)},
            speed{game_data::get_speed(car_type)} {}

    void on_update() override;

};


#endif //RACER_PLAYER_H

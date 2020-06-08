//
// Created by Vladyslav Yazykov on 08/06/2020.
//

#include <stdlib.h>
#include <exceptions.h>
#include "rival.h"

constexpr game_data::CarType get_car_type(game_data::ObstacleType type) {
    switch (type) {
        case game_data::ObstacleType::rival_slow:
            return game_data::CarType::slow;
        case game_data::ObstacleType::rival_medium:
            return game_data::CarType::medium;
        case game_data::ObstacleType::rival_fast:
            return game_data::CarType::fast;
        default:
            throw BaseException();
    }
}

int get_random_line() { return rand() % game_data::NUM_LINES; }
constexpr float get_speed(game_data::ObstacleType type) {
    return game_data::get_speed(get_car_type(type));
}
constexpr int get_width(game_data::ObstacleType type) {
    return game_data::get_width(get_car_type(type));
}

Rival::Behaviour get_behaviour(int line) {
    return Rival::bounce;
    if (line == 1)
        return static_cast<Rival::Behaviour>(rand() % 4);
    auto r = rand() % 3;
    switch (r) {
        case 0:
            return Rival::Behaviour::straight;
        case 1:
            return line == 0 ? Rival::Behaviour::switch_top : Rival::Behaviour::switch_bottom;
        case 2:
        default:
            return Rival::Behaviour::bounce;
    }
}

Rival::Rival(game_data::ObstacleType type, float player_speed) :
        Obstacle{get_random_line(), 0, player_speed + get_speed(type), game_data::get_texture(type), get_width(type),
                 game_data::CAR_HEIGHT}, l{line}, behaviour{get_behaviour(line)} {
}
void Rival::on_update() {
    if (frames_from_last_change == 0) {
        frames_from_last_change = change_frame;
        change_line();
    }

    --frames_from_last_change;

    Obstacle::on_update();
}
void Rival::change_line() {
    if (behaviour == Behaviour::straight) return;

    l++;
    if (behaviour == Behaviour::switch_top) {
        line = l % 2;
        return;
    }

    if (behaviour == Behaviour::switch_bottom) {
        line = 1 + (l % 2);
        return;
    }

    if (behaviour == Behaviour::bounce) {
        auto l1 = l % (game_data::NUM_LINES + 1);
        if (l1 == 3) line = 1;  // hardcoded...
        else line = l1;
    }
}

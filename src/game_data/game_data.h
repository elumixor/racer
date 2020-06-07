//
// Created by vlado on 7/6/20.
//

#ifndef RACER_GAME_DATA_H
#define RACER_GAME_DATA_H

#include <graphics.h>

namespace game_data {
    constexpr int LINE_MARGIN = 10;
    constexpr int LINE_SIZE = 100;

    constexpr auto CAR_WIDTH_SLOW = 60;
    constexpr auto CAR_WIDTH_MEDIUM = 80;
    constexpr auto CAR_WIDTH_FAST = 120;

    constexpr auto OBSTACLE_WIDTH = 80;
    constexpr auto OBSTACLE_WIDTH_BIG = 120;

    constexpr auto CAR_HEIGHT = 80;

    constexpr auto OBSTACLE_HEIGHT = 80;
    constexpr auto OBSTACLE_WIDE_HEIGHT = 2 * (OBSTACLE_HEIGHT + LINE_MARGIN);

    constexpr auto CAR_BASE_SPEED = 5.f;

    constexpr auto CAR_ACCELERATION_SLOW = 0.1f;
    constexpr auto CAR_ACCELERATION_MEDIUM = 0.25f;
    constexpr auto CAR_ACCELERATION_FAST = 0.5f;

    constexpr color::type BACKGROUND_COLOR = color::rgb(.6, 0.58, 0.2);

    enum class CarType {
        slow,
        medium,
        fast
    };

    extern CarType selected_car;
    constexpr CarType DefaultCar = CarType::medium;

    constexpr float get_acceleration(CarType type) {
        if (type == CarType::slow)
            return CAR_ACCELERATION_SLOW;

        if (type == CarType::medium)
            return CAR_ACCELERATION_MEDIUM;

        return CAR_ACCELERATION_FAST;
    }

    constexpr float get_width(CarType type) {
        if (type == CarType::slow)
            return CAR_WIDTH_SLOW;

        if (type == CarType::medium)
            return CAR_WIDTH_SLOW;

        return CAR_WIDTH_SLOW;
    }
    const Texture *get_player_car(CarType car_type);
}

#endif //RACER_GAME_DATA_H

//
// Created by vlado on 7/6/20.
//

#ifndef RACER_GAME_DATA_H
#define RACER_GAME_DATA_H

#include <graphics.h>

namespace game_data {
    constexpr int NUM_LINES = 3;

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

    constexpr auto CAR_SPEED_SLOW = 7.5f;
    constexpr auto CAR_SPEED_MEDIUM = 5.f;
    constexpr auto CAR_SPEED_FAST = 2.5f;

    constexpr auto CAR_ACCELERATION_SLOW = 0.1f;
    constexpr auto CAR_ACCELERATION_MEDIUM = 0.25f;
    constexpr auto CAR_ACCELERATION_FAST = 0.5f;

    constexpr int PLAYER_STARTING_LINE = 1;

    constexpr int RIVAL_CHANGE_FREQUENCY = 15;

    constexpr color::type BACKGROUND_COLOR = color::rgb(.6, 0.58, 0.2);

    enum class CarType {
        slow,
        medium,
        fast
    };

    extern CarType selected_car;
    constexpr CarType DefaultCar = CarType::medium;

    constexpr float get_speed(CarType type) {
        switch (type) {
            case CarType::slow:
                return CAR_SPEED_SLOW;
            case CarType::medium:
                return CAR_SPEED_MEDIUM;
            case CarType::fast:
                return CAR_SPEED_FAST;
        }
    }

    constexpr float get_acceleration(CarType type) {
        switch (type) {
            case CarType::slow:
                return CAR_ACCELERATION_SLOW;
            case CarType::medium:
                return CAR_ACCELERATION_MEDIUM;
            case CarType::fast:
                return CAR_ACCELERATION_FAST;
        }
    }
    constexpr int get_width(CarType type) {
        if (type == CarType::slow)
            return CAR_WIDTH_SLOW;

        if (type == CarType::medium)
            return CAR_WIDTH_SLOW;

        return CAR_WIDTH_SLOW;
    }

    enum class ObstacleType {
        box_small,
        box_wide_small,

        box_big,
        box_wide_big,

        rival_slow,
        rival_medium,
        rival_fast
    };
    constexpr int NUM_OBSTACLE_TYPES = 2 + 2 + 3;
    ObstacleType get_random_obstacle_type();


    const Texture *get_texture(CarType car_type);
    const Texture *get_texture(ObstacleType obstacle_type);
}

#endif //RACER_GAME_DATA_H

//
// Created by vlado on 7/6/20.
//

#ifndef RACER_GAME_DATA_H
#define RACER_GAME_DATA_H

#include <graphics.h>
#include <exceptions.h>
#include <text/text.h>

namespace game_data {
    constexpr int NUM_LINES = 3;

    constexpr int LINE_MARGIN = 10;
    constexpr int LINE_SIZE = 100;

    /* Objects dimensions (for Track) */
    constexpr auto CAR_WIDTH_SLOW = 60;
    constexpr auto CAR_WIDTH_MEDIUM = 80;
    constexpr auto CAR_WIDTH_FAST = 120;

    constexpr auto OBSTACLE_WIDTH = 80;
    constexpr auto OBSTACLE_WIDTH_BIG = 120;

    constexpr auto CAR_HEIGHT = 80;

    constexpr auto OBSTACLE_HEIGHT = 80;
    constexpr auto OBSTACLE_WIDE_HEIGHT = 2 * (OBSTACLE_HEIGHT + LINE_MARGIN);

    /* Cars speed and acceleration */
    constexpr auto CAR_SPEED_SLOW = 7.5f;
    constexpr auto CAR_SPEED_MEDIUM = 5.f;
    constexpr auto CAR_SPEED_FAST = 2.5f;

    constexpr auto CAR_ACCELERATION_SLOW = 0.1f;
    constexpr auto CAR_ACCELERATION_MEDIUM = 0.25f;
    constexpr auto CAR_ACCELERATION_FAST = 0.5f;

    constexpr int PLAYER_STARTING_LINE = 1;
    constexpr int RIVAL_CHANGE_FREQUENCY = 15;

    constexpr text::Style TEXT_TITLE{6, color::black, color::red};
    constexpr text::Style TEXT_OPTION{4, color::black, color::red};
    constexpr text::Style TEXT_OPTION_HIGHLIGHTED{4, color::black, color::white};
    constexpr text::Style TEXT_SCORE_SMALL{2, color::black, color::red};

    constexpr int TITLE_MARGIN_TOP = 45;
    constexpr int TITLE_MARGIN_BOTTOM = 35;
    constexpr int OPTION_MARGIN = 15;
    constexpr int SCORE_MARGIN = 10;

    constexpr color::type BACKGROUND_COLOR = color::rgb(.6, 0.58, 0.2);

    extern int score;

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

        throw InvalidArgumentException("Invalid car type");
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

        throw InvalidArgumentException("Invalid car type");
    }
    constexpr int get_width(CarType type) {
        switch (type) {
            case CarType::slow:
                return CAR_WIDTH_SLOW;
            case CarType::medium:
                return CAR_WIDTH_MEDIUM;
            case CarType::fast:
                return CAR_WIDTH_FAST;
        }

        throw InvalidArgumentException("Invalid car type");
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

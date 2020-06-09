//
// Created by vlado on 7/6/20.
//

#ifndef RACER_GAME_DATA_H
#define RACER_GAME_DATA_H

#include <graphics.h>
#include <exceptions.h>
#include <text/text.h>

#define game_parameter constexpr auto

namespace game_data {
    extern int score;

    enum CarType {
        slow,
        medium,
        fast
    };

    extern CarType selected_car;

    game_parameter NUM_LINES = 3;

    game_parameter LINE_MARGIN = 10;
    game_parameter LINE_SIZE = 100;

    /* Objects dimensions (for Track) */
    game_parameter CAR_WIDTH_SLOW = 60;
    game_parameter CAR_WIDTH_MEDIUM = 80;
    game_parameter CAR_WIDTH_FAST = 120;

    game_parameter OBSTACLE_WIDTH = 80;
    game_parameter OBSTACLE_WIDTH_BIG = 120;

    game_parameter CAR_HEIGHT = 80;

    game_parameter OBSTACLE_HEIGHT = 80;
    game_parameter OBSTACLE_WIDE_HEIGHT = 2 * (OBSTACLE_HEIGHT + LINE_MARGIN);

    /* Cars speed and acceleration */
    game_parameter CAR_SPEED_SLOW = 7.5f;
    game_parameter CAR_SPEED_MEDIUM = 5.f;
    game_parameter CAR_SPEED_FAST = 2.5f;

    game_parameter CAR_ACCELERATION_SLOW = 0.1f;
    game_parameter CAR_ACCELERATION_MEDIUM = 0.25f;
    game_parameter CAR_ACCELERATION_FAST = 0.5f;

    game_parameter NUM_CARS = 3;

    game_parameter PLAYER_STARTING_LINE = 1;
    game_parameter RIVAL_CHANGE_FREQUENCY = 15;

    game_parameter TEXT_TITLE = text::Style{6, color::black, color::red};
    game_parameter TEXT_OPTION = text::Style{4, color::black, color::red};
    game_parameter TEXT_OPTION_HIGHLIGHTED = text::Style{4, color::black, color::white};
    game_parameter TEXT_SCORE_SMALL = text::Style{2, color::black, color::red};
    game_parameter TEXT_SCORE_TRACK = text::Style{2, color::white, color::black};

    game_parameter TITLE_MARGIN_TOP = 45;
    game_parameter TITLE_MARGIN_BOTTOM = 35;
    game_parameter OPTION_MARGIN = 15;
    game_parameter SCORE_MARGIN = 10;

    game_parameter BACKGROUND_COLOR = color::rgb(.6, 0.58, 0.2);
    game_parameter DefaultCar = CarType::medium;

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

    game_parameter NUM_OBSTACLE_TYPES = 2 + 2 + 3;

    ObstacleType get_random_obstacle_type();

    const Texture *get_texture(CarType car_type);
    const Texture *get_texture(ObstacleType obstacle_type);
}

#endif //RACER_GAME_DATA_H

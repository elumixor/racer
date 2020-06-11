//
// Created by vlado on 5/6/20.
//

#include "car_selection.h"
#include <game_data.h>
#include <renderer/renderer.h>
#include <textures.h>
#include <input.h>

constexpr auto part = 480 / (game_data::NUM_CARS + 1);
constexpr auto spacing = 20;

constexpr auto slow = part - spacing;
constexpr auto medium = part * 2;
constexpr auto fast = part * 3 + spacing;

constexpr auto padding = 10;
constexpr auto max_width = game_data::CAR_WIDTH_FAST; // and height

constexpr auto top = game_data::SCREEN_HEIGHT / 2 - max_width / 2 - padding;
constexpr auto bottom = top + max_width + 2 * padding;

constexpr auto get_left(int l) { return l - max_width / 2 - padding; }
constexpr auto get_right(int l) { return l + max_width / 2 + padding; }

constexpr auto get_rect(int l) {
    return Rect{{get_left(l),  top},
                {get_right(l), bottom}};
}

// Now we have our selection rectangles
constexpr auto rect_slow{get_rect(slow)};
constexpr auto rect_medium{get_rect(medium)};
constexpr auto rect_fast{get_rect(fast)};

constexpr auto get_inner_rect(const Rect &r) {
    return Rect{{r.left() + 5,  r.top() + 5},
                {r.right() - 5, r.bottom() - 5}};
}

constexpr auto inner_slow{get_inner_rect(rect_slow)};
constexpr auto inner_medium{get_inner_rect(rect_medium)};
constexpr auto inner_fast{get_inner_rect(rect_fast)};


// Which we can pick based on the current selection
const Rect &selection_rect() {
    switch (game_data::selected_car) {
        case game_data::CarType::slow:
            return rect_slow;
        case game_data::CarType::medium:
            return rect_medium;
        case game_data::CarType::fast:
        default:
            return rect_fast;
    }
}

// Which we can pick based on the current selection
const Rect &inner_selection_rect() {
    switch (game_data::selected_car) {
        case game_data::CarType::slow:
            return inner_slow;
        case game_data::CarType::medium:
            return inner_medium;
        case game_data::CarType::fast:
        default:
            return inner_fast;
    }
}

// We also need top left points to render cars
constexpr auto car_top = game_data::SCREEN_HEIGHT / 2 - game_data::CAR_HEIGHT / 2;

constexpr auto player_slow = Point{slow - game_data::CAR_WIDTH_SLOW / 2, car_top};
constexpr auto player_medium = Point{medium - game_data::CAR_WIDTH_MEDIUM / 2, car_top};
constexpr auto player_fast = Point{fast - game_data::CAR_WIDTH_FAST / 2, car_top};

void scenes::CarSelection::update() {
    renderer::clear_framebuffer(game_data::BACKGROUND_COLOR);

    auto rect = selection_rect();
    renderer::set_rect(rect, color::black);
    renderer::set_rect(inner_selection_rect(), game_data::BACKGROUND_COLOR);

    textures::player_slow->render(player_slow);
    textures::player_medium->render(player_medium);
    textures::player_fast->render(player_fast);

    if (input::key_pressed(input::Keys::a) && game_data::selected_car > 0)
        game_data::selected_car = static_cast<game_data::CarType>(game_data::selected_car - 1);
    else if (input::key_pressed(input::Keys::d) && game_data::selected_car < 2)
        game_data::selected_car = static_cast<game_data::CarType>(game_data::selected_car + 1);
    else if (input::key_pressed(input::Keys::enter) || input::key_pressed(input::Keys::e))
        scene::load<Track>();
}

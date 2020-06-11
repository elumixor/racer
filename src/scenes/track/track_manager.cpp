//
// Created by vlado on 6/6/20.
//

#include <math.h>
#include <printing.h>
#include <c++/9/cmath>
#include <text/label/label.h>
#include <c++/9/cstdio>
#include <renderer/renderer.h>
#include "track_manager.h"
#include "../scenes.h"

Obstacle *current_obstacle{nullptr};

TrackManager::TrackManager(const Player *player) : player{player} {}

bool collide(const Rect &a, const Rect &b) {
    return (min(a.right(), b.right()) - max(a.left(), b.left())) >= 0 &&
           (min(a.bottom(), b.bottom()) - max(a.top(), b.top())) >= 0;
}

float distance{0};
Label *score_label;

constexpr Rect score_rect{{game_data::SCREEN_WIDTH - (game_data::TEXT_SCORE_TRACK.font_size * text::glyph_size * 3 + 10), 0},
                          {game_data::SCREEN_WIDTH,       game_data::TEXT_SCORE_TRACK.font_size * text::glyph_size + 10}};

void TrackManager::update() {
    if (current_obstacle == nullptr) {
        current_obstacle = instantiate_obstacle();
    }

    distance += player->speed;
    game_data::score = (int) lround(distance / 100.f);
    printf("Distance: %.2f Score: %i\n\r", distance, game_data::score);

    auto str = new char[5];
    sprintf(str, "%i", game_data::score);
    score_label->string = str;

    renderer::set_rect(score_rect, color::black);
    score_label->render({game_data::SCREEN_WIDTH, 5}, AnchorX::right, AnchorY::top);

    current_obstacle->update();


    if (current_obstacle->out_of_view()) {
        delete current_obstacle;
        current_obstacle = nullptr;
    } else if (collide(current_obstacle->get_collider(), player->get_collider())) {
        printf("Game Over! You crashed at %im!\n\r", game_data::score);
        scene::load<scenes::GameOver>();
    }

}

void TrackManager::on_init() {
    distance = 0;
    game_data::score = 0;
    auto str = new char[5];
    sprintf(str, "%i", game_data::score);
    score_label = new Label(str, game_data::TEXT_SCORE_TRACK);
}

Obstacle *TrackManager::instantiate_obstacle() const {
    auto obstacle_type = game_data::get_random_obstacle_type();
    auto obstacle = Obstacle::from_type(obstacle_type, player->speed);
    obstacle->x = game_data::SCREEN_WIDTH;
    return obstacle;
}

void TrackManager::on_destroy() {
    if (current_obstacle != nullptr) {
        delete current_obstacle;
        current_obstacle = nullptr;
    }

    delete[] score_label->string;
    delete score_label;
}


//
// Created by vlado on 5/6/20.
//

#include <renderer/renderer.h>
#include <c++/9/cstdio>
#include "track.h"
#include "../application/application.h"

constexpr Rect top_rect{{0,             0},
                        {game_data::SCREEN_WIDTH, game_data::LINE_MARGIN}};
constexpr Rect bottom_rect{{0,             game_data::SCREEN_HEIGHT - game_data::LINE_MARGIN},
                           {game_data::SCREEN_WIDTH, game_data::SCREEN_HEIGHT}};

void scenes::Track::update() {
    renderer::clear_framebuffer(game_data::BACKGROUND_COLOR);

    renderer::set_rect(top_rect, color::black);
    renderer::set_rect(bottom_rect, color::black);

    player->update();
    track_manager->update();
}

void scenes::Track::on_init() {
    auto selected_car = game_data::selected_car;

    player = new Player(selected_car);
    track_manager = new TrackManager(player);

    track_manager->on_init();
}

void scenes::Track::on_destroy() {
    track_manager->on_destroy();

    delete player;
    delete track_manager;

    player = nullptr;
    track_manager = nullptr;
}

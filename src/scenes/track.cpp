//
// Created by vlado on 5/6/20.
//

#include <renderer/renderer.h>
#include <c++/9/cstdio>
#include <screen.h>
#include "track.h"
#include "../application/application.h"

constexpr Rect top_rect{{0,             0},
                        {screen::width, game_data::LINE_MARGIN}};
constexpr Rect bottom_rect{{0,             screen::height - game_data::LINE_MARGIN},
                           {screen::width, screen::height}};

void scenes::Track::on_update() {
    renderer::clear_framebuffer(game_data::BACKGROUND_COLOR);

    renderer::set_rect(top_rect, color::black);
    renderer::set_rect(bottom_rect, color::black);

    player->on_update();
    track_manager->on_update();
}

void scenes::Track::on_init() {
    auto selected_car = game_data::selected_car;

    player = new Player(selected_car);
    track_manager = new TrackManager(player);

    player->on_init();
    track_manager->on_init();
}

void scenes::Track::on_destroy() {
    player->on_destroy();
    track_manager->on_destroy();

    delete player;
    delete track_manager;

    player = nullptr;
    track_manager = nullptr;
}

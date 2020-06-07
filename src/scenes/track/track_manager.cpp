//
// Created by vlado on 6/6/20.
//

#include <printing.h>
#include "track_manager.h"
#include "obstacle.h"
#include "textures/textures.h"
#include "../../io/screen.h"

Obstacle *current_obstacle{nullptr};

TrackManager::TrackManager(const Player *player) : player{player} {}

void TrackManager::on_update() {
    if (current_obstacle == nullptr) {
        current_obstacle = new Obstacle(0, screen::width, player->speed, textures::obstacle_small, game_data::OBSTACLE_WIDTH);
    }

    current_obstacle->on_update();

    if (current_obstacle->out_of_view()) {
        current_obstacle->on_destroy();
        delete current_obstacle;
        current_obstacle = nullptr;
    }
}


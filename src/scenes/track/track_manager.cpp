//
// Created by vlado on 6/6/20.
//

#include <printing.h>
#include "track_manager.h"
#include "obstacles/obstacle.h"
#include "../../io/screen.h"

Obstacle *current_obstacle{nullptr};

TrackManager::TrackManager(const Player *player) : player{player} {}

void TrackManager::on_update() {
    if (current_obstacle == nullptr) {
        current_obstacle = instantiate_obstacle();
    }

    current_obstacle->on_update();

    if (current_obstacle->out_of_view()) {
        current_obstacle->on_destroy();
        delete current_obstacle;
        current_obstacle = nullptr;
    }
}
void TrackManager::on_destroy() {
    if (current_obstacle != nullptr) {
        current_obstacle->on_destroy();
        delete current_obstacle;
    }
}
Obstacle *TrackManager::instantiate_obstacle() const {
    auto obstacle_type = game_data::get_random_obstacle_type();
    auto obstacle = Obstacle::from_type(obstacle_type, player->speed);
    obstacle->x = screen::width;
    return obstacle;
}


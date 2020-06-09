//
// Created by vlado on 6/6/20.
//

#include <math.h>
#include <printing.h>
#include <c++/9/cmath>
#include "track_manager.h"
#include "../../io/screen.h"
#include "../scenes.h"

Obstacle *current_obstacle{nullptr};

TrackManager::TrackManager(const Player *player) : player{player} {}

bool collide(const Rect &a, const Rect &b) {
    return (min(a.right(), b.right()) - max(a.left(), b.left())) >= 0 &&
           (min(a.bottom(), b.bottom()) - max(a.top(), b.top())) >= 0;
}

float distance{0};

void TrackManager::on_update() {
    if (current_obstacle == nullptr) {
        current_obstacle = instantiate_obstacle();
    }

    distance += player->speed;
    game_data::score = (int) lround(distance / 5.f);

    current_obstacle->on_update();

    if (current_obstacle->out_of_view()) {
        current_obstacle->on_destroy();
        delete current_obstacle;
        current_obstacle = nullptr;
    } else if (collide(current_obstacle->get_collider(), player->get_collider())) {
        print("Game Over!");
        scene::load<scenes::GameOver>();
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


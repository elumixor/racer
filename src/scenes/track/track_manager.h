//
// Created by vlado on 6/6/20.
//

#ifndef RACER_TRACK_MANAGER_H
#define RACER_TRACK_MANAGER_H


#include <component.h>
#include "player.h"
#include "obstacles/obstacle.h"

class TrackManager : public Component {
    const Player *player; // will track current speed and pass it to constructed enemies.
public:
    explicit TrackManager(const Player *player);

    void on_init() override ;
    void on_update() override;
    void on_destroy() override;

    Obstacle *instantiate_obstacle() const;
};

#endif //RACER_TRACK_MANAGER_H

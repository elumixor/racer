//
// Created by vlado on 6/6/20.
//

#ifndef RACER_TRACK_MANAGER_H
#define RACER_TRACK_MANAGER_H


#include "player.h"
#include "obstacles/obstacle.h"

class TrackManager  {
    const Player *player; // will track current speed and pass it to constructed enemies.
public:
    explicit TrackManager(const Player *player);

    void on_init() ;
    void update();
    void on_destroy();

    Obstacle *instantiate_obstacle() const;
};

#endif //RACER_TRACK_MANAGER_H

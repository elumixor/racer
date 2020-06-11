//
// Created by vlado on 5/6/20.
//

#ifndef RACER_TRACK_H
#define RACER_TRACK_H


#include "scenes.h"
#include "track/track_manager.h"
#include "track/player.h"

class scenes::Track : public scenes::Scene {
    Player *player{nullptr};
    TrackManager *track_manager{nullptr};

    void update() override;
    void on_init() override;
    void on_destroy() override;
};


#endif //RACER_TRACK_H

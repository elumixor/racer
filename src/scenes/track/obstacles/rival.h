//
// Created by Vladyslav Yazykov on 08/06/2020.
//

#ifndef RACER_RIVAL_H
#define RACER_RIVAL_H


#include "obstacle.h"

class Rival : public Obstacle {

    int frames_from_last_change{0};
    int change_frame{game_data::RIVAL_CHANGE_FREQUENCY};
    int l;
public:
    enum Behaviour {
        straight,
        switch_top,
        switch_bottom,
        bounce
    };
private:
    Behaviour behaviour;
public:
    Rival(game_data::ObstacleType type, float player_speed);
    void on_update() override;
    void change_line();

};


#endif //RACER_RIVAL_H

//
// Created by Vladyslav Yazykov on 08/06/2020.
//

#ifndef RACER_BOX_OBSTACLE_H
#define RACER_BOX_OBSTACLE_H


#include "obstacle.h"

class BoxObstacle : public Obstacle {

public:
    BoxObstacle(game_data::ObstacleType type, float player_speed);
};


#endif //RACER_BOX_OBSTACLE_H

//
// Created by vlado on 6/6/20.
//

#ifndef RACER_OBSTACLE_H
#define RACER_OBSTACLE_H


#include <component.h>
#include <graphics.h>
#include "../game_data/game_data.h"

class Obstacle : public Component {
    int line;
    float x;
    float speed;
    const Texture *texture;
    int width;

    void render();
public:
    inline Obstacle(int line, float x, float speed, const Texture *texture, int width) :
            line{line}, x{x}, speed{speed}, texture{texture}, width{width} {}

    void on_update() override;
    bool out_of_view() const;
};


#endif //RACER_OBSTACLE_H

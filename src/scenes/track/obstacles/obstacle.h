//
// Created by vlado on 6/6/20.
//

#ifndef RACER_OBSTACLE_H
#define RACER_OBSTACLE_H


#include <component.h>
#include <graphics.h>
#include <game_data.h>

class Obstacle : public Component {
protected:
    int line;
public:
    float x;
private:
    float speed;
    const Texture *texture;
    int width;
    int height;

    void render();
public:
    Rect get_collider() const;

    inline Obstacle(int line, float x, float speed, const Texture *texture, int width, int height) :
            line{line}, x{x}, speed{speed}, texture{texture}, width{width}, height{height} {}

    void on_update() override;
    bool out_of_view() const;

    static Obstacle *from_type(game_data::ObstacleType type, float player_speed);
};


#endif //RACER_OBSTACLE_H

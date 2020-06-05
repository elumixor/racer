//
// Created by vlado on 5/6/20.
//

#ifndef RACER_SCENES_H
#define RACER_SCENES_H

#include "../behaviour.h"

namespace scenes {

    class Scene;

    class MainMenu;

    class CarSelection;

    class Track;

    class GameOver;

}
namespace scene {
    template<typename T>
    T *get();

    void change(scenes::Scene *);

    extern scenes::Scene *current;

    using StartingScene = scenes::MainMenu;
}

class scenes::Scene : public Behaviour {
};

#endif //RACER_SCENES_H

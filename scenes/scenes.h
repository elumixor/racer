//
// Created by vlado on 5/6/20.
//

#ifndef RACER_SCENES_H
#define RACER_SCENES_H

#include "../behaviour.h"

namespace scenes {

    class Scene;

    class MainMenuScene;

    class CarSelectionScene;

    class TrackScene;

    class GameOverScene;

    template<typename T>
    T *get();

    void change_scene(Scene *);

    extern Scene* current;

    using StartingScene = MainMenuScene;
}

class scenes::Scene : public Behaviour {

};

#endif //RACER_SCENES_H

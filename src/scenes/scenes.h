//
// Created by vlado on 5/6/20.
//

#ifndef RACER_SCENES_H
#define RACER_SCENES_H

#include <component.h>

namespace scenes {

    class Scene : public Component {
    };

    class MainMenu;

    class CarSelection;

    class Track;

    class GameOver;

}

namespace scene {
    template<typename T>
    T *get();

    extern scenes::Scene *current;

    void load(scenes::Scene *);

    template<typename T>
    void load() {
        auto instance = (scenes::Scene *) scene::get<T>();
        load(instance);
    }

    using StartingScene = scenes::MainMenu;
}


#endif //RACER_SCENES_H

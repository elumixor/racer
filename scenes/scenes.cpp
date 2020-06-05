//
// Created by vlado on 5/6/20.
//

#include "scenes.h"
#include "../scenes/main_menu/MainMenuScene.h"

scenes::Scene* scenes::current = nullptr;

namespace scenes {
    template<>
    MainMenuScene *get<MainMenuScene>() {
        static MainMenuScene instance = MainMenuScene();
        return &instance;
    }

    void change_scene(Scene *new_scene) {
        if (current != nullptr) {
            current->on_destroy();
        }

        current = new_scene;
        current->on_init();
    }
}
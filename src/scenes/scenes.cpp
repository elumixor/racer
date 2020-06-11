//
// Created by vlado on 5/6/20.
//

#include "scenes.h"
#include "main_menu.h"
#include "car_selection.h"
#include "track.h"
#include "game_over.h"

scenes::Scene *scene::current = nullptr;

void scenes::Scene::update() {}
void scenes::Scene::on_init() {}
void scenes::Scene::on_destroy() {}

namespace scene {
    template<>
    scenes::MainMenu *get<scenes::MainMenu>() {
        static scenes::MainMenu instance = scenes::MainMenu();
        return &instance;
    }

    template<>
    scenes::CarSelection *get<scenes::CarSelection>() {
        static scenes::CarSelection instance = scenes::CarSelection();
        return &instance;
    }

    template<>
    scenes::Track *get<scenes::Track>() {
        static scenes::Track instance = scenes::Track();
        return &instance;
    }

    template<>
    scenes::GameOver *get<scenes::GameOver>() {
        static scenes::GameOver instance = scenes::GameOver();
        return &instance;
    }

    void load(scenes::Scene *new_scene) {
        // call on_destroy on the currently loaded scene
        if (current != nullptr) {
            current->on_destroy();
        }

        // load selected scene
        current = new_scene;
        current->on_init();
    }
}

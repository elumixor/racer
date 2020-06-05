//
// Created by vlado on 5/6/20.
//

#include "MainMenuScene.h"
#include "../../input/input.h"
#include "../../application/application.h"

void scenes::MainMenuScene::on_update() {
    if (input::get_key(input::keys::w)) {
        application::should_exit = true;
    }
}

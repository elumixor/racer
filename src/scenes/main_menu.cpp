//
// Created by vlado on 5/6/20.
//

#include "main_menu.h"
#include "../io/input.h"
#include "../application/application.h"

void scenes::MainMenu::on_init() {
    scene::load<Track>();
}

void scenes::MainMenu::on_update() {
    if (input::get_key(input::keys::w)) {
        application::should_exit = true;
    }
}

//
// Created by vlado on 5/6/20.
//

#include "application.h"
#include "../scenes/scenes.h"
#include "../input/input.h"

bool application::should_exit = false;

void application::initialize() {
    auto starting_scene = (scenes::Scene *) scenes::get<scenes::StartingScene>();
    scenes::change_scene(starting_scene);
}

void application::process_logic() {
    scenes::current->on_update();
}
void application::draw_frame() {

}
void application::pull_events() {
    // if key pressed, assign to input
    input::update();
}
void application::exit() {

}

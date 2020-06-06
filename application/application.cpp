//
// Created by vlado on 5/6/20.
//

#include "application.h"
#include "../scenes/scenes.h"
#include "../io/input.h"
#include "../renderer/renderer.h"

bool application::should_exit = false;


void application::initialize() {
    renderer::initialize();

    auto starting_scene = (scenes::Scene *) scene::get<scene::StartingScene>();
    scene::change(starting_scene);
}

void application::process_logic() {
    scene::current->on_update();
}

void application::draw_frame() {
    renderer::render();
}

void application::pull_events() {
    // if key pressed, assign to io
    input::update();
}

void application::on_exit() {

}

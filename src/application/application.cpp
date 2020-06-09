//
// Created by vlado on 5/6/20.
//

#include <cstdlib>
#include <ctime>

#include <renderer/renderer.h>
#include <textures/textures.h>
#include <text/text.h>
#include <c++/9/cstdlib>
#include <c++/9/cstdio>

#include "application.h"
#include "../scenes/scenes.h"
#include "../io/input.h"

bool application::should_exit = false;


void application::initialize() {
    // seed random generator https://stackoverflow.com/a/13446015/4932128
    srand((unsigned) time(nullptr));

    renderer::initialize();
    input::initialize();
    textures::initialize();
    text::initialize();

    auto starting_scene = (scenes::Scene *) scene::get<scene::StartingScene>();
    scene::load(starting_scene);
}

void application::process_logic() {
    if (input::get_key(input::keys::escape))
        application::should_exit = true;

    scene::current->on_update();
}

void application::draw_frame() {
    renderer::render_frame();
}

void application::pull_events() {
    // if key pressed, assign to io
    input::update();
}

void application::on_exit() {
    renderer::on_exit();
    textures::free();
    text::free();
}

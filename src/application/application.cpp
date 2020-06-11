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
    // seed random generator, just for fun. https://stackoverflow.com/a/13446015/4932128
    srand((unsigned) time(nullptr));

    // initialize submodules
    renderer::initialize();
    input::initialize();
    textures::initialize();
    text::initialize();

    // load starting scene
    scene::load<scenes::StartingScene>();
}

void application::process_logic() {
    // At any given point, we can exit by pressing escape key
    if (input::key_pressed(input::Keys::escape))
        application::should_exit = true;

    // Call update() on the current scene
    scene::current->update();
}

void application::render_frame() {
    // Delegates to renderer. Design choice
    renderer::render_frame();
}

void application::pull_events() {
    // Delegates to input. Design choice
    input::update();
}

void application::on_exit() {
    renderer::on_exit();
    textures::free();
    text::free();
}

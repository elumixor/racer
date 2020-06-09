//
// Created by vlado on 5/6/20.
//

#include <text/text.h>
#include "main_menu.h"
#include "../io/input.h"
#include "../application/application.h"
#include <renderer/renderer.h>
#include <c++/9/cstdlib>
#include <c++/9/cstdio>

void scenes::MainMenu::on_init() {}

void scenes::MainMenu::on_update() {
    renderer::clear_framebuffer();
    text::render("hello\nkek", {}, color::black, color::saturate(color::white, 0.3), 8);

    if (input::get_key(input::keys::w)) {
        scene::load<Track>();
    }
}

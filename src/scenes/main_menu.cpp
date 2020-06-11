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
#include <game_data.h>
#include <text/label/label.h>

constexpr auto title = Label("racer", game_data::TEXT_TITLE);
constexpr auto option_start = Label("start game", game_data::TEXT_OPTION);
constexpr auto option_start_highlighted = Label("start game", game_data::TEXT_OPTION_HIGHLIGHTED);
constexpr auto option_select = Label("select car", game_data::TEXT_OPTION);
constexpr auto option_select_highlighted = Label("select car", game_data::TEXT_OPTION_HIGHLIGHTED);
constexpr auto option_exit = Label("exit", game_data::TEXT_OPTION);
constexpr auto option_exit_highlighted = Label("exit", game_data::TEXT_OPTION_HIGHLIGHTED);


void scenes::MainMenu::select_option() {
    switch (focused_option) {
        case start_game:
            scene::load<Track>();
            break;
        case select_car:
            scene::load<CarSelection>();
            break;
        case exit:
            application::should_exit = true;
            break;
    }
}


void scenes::MainMenu::update() {
    renderer::clear_framebuffer(game_data::BACKGROUND_COLOR);

    auto start = focused_option == start_game ? option_start_highlighted : option_start;
    auto select = focused_option == select_car ? option_select_highlighted : option_select;
    auto exit = focused_option == MainMenu::exit ? option_exit_highlighted : option_exit;

    auto top = game_data::TITLE_MARGIN_TOP;
    title.render({game_data::SCREEN_WIDTH / 2, game_data::TITLE_MARGIN_TOP}, AnchorX::center);

    top += title.style.glyph_size() + game_data::TITLE_MARGIN_BOTTOM;
    start.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);

    top += start.style.glyph_size() + game_data::OPTION_MARGIN;
    select.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);

    top += select.style.glyph_size() + game_data::OPTION_MARGIN;
    exit.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);

    if (input::key_pressed(input::Keys::w) && focused_option > 0)
        focused_option = static_cast<Options>(focused_option - 1);
    else if (input::key_pressed(input::Keys::s) && focused_option < 2)
        focused_option = static_cast<Options>(focused_option + 1);

    else if (input::key_pressed(input::Keys::enter) || input::key_pressed(input::Keys::e))
        select_option();
}
void scenes::MainMenu::on_init() {
    focused_option = start_game;
}

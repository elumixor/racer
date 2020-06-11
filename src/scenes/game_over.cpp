//
// Created by vlado on 5/6/20.
//

#include <game_data.h>
#include <text/label/label.h>
#include <input.h>
#include <renderer/renderer.h>
#include <c++/9/cstdio>
#include "game_over.h"
#include "../application/application.h"

constexpr auto title = Label("crashed!", game_data::TEXT_TITLE);

constexpr auto option_retry = Label("retry", game_data::TEXT_OPTION);
constexpr auto option_retry_highlighted = Label("retry", game_data::TEXT_OPTION_HIGHLIGHTED);

constexpr auto option_change_car = Label("change car", game_data::TEXT_OPTION);
constexpr auto option_change_car_highlighted = Label("change car", game_data::TEXT_OPTION_HIGHLIGHTED);

constexpr auto option_exit = Label("exit", game_data::TEXT_OPTION);
constexpr auto option_exit_highlighted = Label("exit", game_data::TEXT_OPTION_HIGHLIGHTED);

void scenes::GameOver::select_option() {
    switch (focused_option) {
        case retry:
            scene::load<Track>();
            break;
        case change_car:
            scene::load<CarSelection>();
            break;
        case exit:
            application::should_exit = true;
            break;
    }
}

Label *score;

void scenes::GameOver::update() {
    renderer::clear_framebuffer(game_data::BACKGROUND_COLOR);

    auto retry = focused_option == GameOver::retry ? option_retry_highlighted : option_retry;
    auto change_car = focused_option == GameOver::change_car ? option_change_car_highlighted : option_change_car;
    auto exit = focused_option == GameOver::exit ? option_exit_highlighted : option_exit;

    auto top = game_data::TITLE_MARGIN_TOP;

    title.render({game_data::SCREEN_WIDTH / 2, game_data::TITLE_MARGIN_TOP}, AnchorX::center);
    top += title.style.glyph_size() + game_data::SCORE_MARGIN;

    score->render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);
    top += score->style.glyph_size() + game_data::OPTION_MARGIN;

    retry.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);
    top += retry.style.glyph_size() + game_data::OPTION_MARGIN;

    change_car.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);
    top += change_car.style.glyph_size() + game_data::OPTION_MARGIN;

    exit.render({game_data::SCREEN_WIDTH / 2, top}, AnchorX::center);

    if (input::key_pressed(input::Keys::w) && focused_option > 0)
        focused_option = static_cast<Options>(focused_option - 1);
    else if (input::key_pressed(input::Keys::s) && focused_option < 2)
        focused_option = static_cast<Options>(focused_option + 1);

    else if (input::key_pressed(input::Keys::enter) || input::key_pressed(input::Keys::e))
        select_option();
}
void scenes::GameOver::on_init() {
    char *s = new char[20];
    sprintf(s, "...at %im!", game_data::score);

    score = new Label(s, game_data::TEXT_SCORE_SMALL);
    focused_option = retry;
}
void scenes::GameOver::on_destroy() {
    delete[] score->string;
    delete score;
}

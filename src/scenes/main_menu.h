//
// Created by vlado on 5/6/20.
//

#ifndef RACER_MAIN_MENU_H
#define RACER_MAIN_MENU_H


#include <text/label/label.h>
#include "scenes.h"

namespace scenes {
    class MainMenu : public Scene {
        enum Options {
            start_game,
            select_car,
            exit
        };
        Options focused_option{start_game};
        void select_option();
        void on_update() override;
        void on_init() override;
    };
}


#endif //RACER_MAIN_MENU_H

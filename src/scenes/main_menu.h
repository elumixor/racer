//
// Created by vlado on 5/6/20.
//

#ifndef RACER_MAIN_MENU_H
#define RACER_MAIN_MENU_H


#include "scenes.h"

namespace scenes {
    class MainMenu : public Scene {
        void on_init() override;
        void on_update() override;
    };
}


#endif //RACER_MAIN_MENU_H

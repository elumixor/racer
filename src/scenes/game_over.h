//
// Created by vlado on 5/6/20.
//

#ifndef RACER_GAME_OVER_H
#define RACER_GAME_OVER_H


#include "scenes.h"

namespace scenes {
    class GameOver : public Scene {
        enum Options {
            retry,
            change_car,
            exit
        };
        Options focused_option{retry};
//        const Label* title{nullptr};
        void select_option();
        void on_update() override;
        void on_init() override;
        void on_destroy() override;
    };
}


#endif //RACER_GAME_OVER_H

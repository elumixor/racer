//
// Created by vlado on 5/6/20.
//

#include "track.h"
#include "../io/input.h"
#include "../application/application.h"

void scenes::Track::on_update() {
    if (input::get_key(input::keys::w)) {
        application::should_exit = true;
    }
}

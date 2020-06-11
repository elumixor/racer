//
// Created by vlado on 4/6/20.
//

#include "application/application.h"
#include <game_data.h>
#include <c++/9/cstdio>

// Application entry point
int main() {
    printf("Game is running! Take a look at the board!\n");
    printf("Use 'w' 'a' 's' 'd' to navigate and 'Enter' or 'e' to select.\n");
    printf("Press 'Esc' to exit the game at any time.\n");

    application::initialize();

    // Start main loop
    while (!application::should_exit) {
        application::process_logic();
        application::render_frame();
        application::pull_events();
    }

    printf("Exiting Racer...");
    application::on_exit();
    return 0;
}
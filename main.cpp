//
// Created by vlado on 4/6/20.
//
#include "application/application.h"
#include <conio.h>
#include <cstdio>


int main(int argc, char **argv) {
    application::initialize();

    // Start main loop
    while (!application::should_exit) {
        application::process_logic();
        application::draw_frame();
        application::pull_events();
    }

    application::exit();

    return 0;
}
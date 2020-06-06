//
// Created by vlado on 5/6/20.
//

#ifndef RACER_APPLICATION_H
#define RACER_APPLICATION_H

#endif //RACER_APPLICATION_H


namespace application {
    void initialize();

    extern bool should_exit;

    void process_logic();
    void draw_frame();
    void pull_events();

    void on_exit();
}
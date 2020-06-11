//
// Created by vlado on 5/6/20.
//

#ifndef RACER_APPLICATION_H
#define RACER_APPLICATION_H

#endif //RACER_APPLICATION_H


namespace application {
    /// Performs all the necessary initialization. Runs once at the start of the application.
    void initialize();

    /// Flag, that is checked on every update(). If set to false, the application will exit.
    extern bool should_exit;

    // Main loop of the application

    /// Processes global logic, and calls update() on the currently loaded scene.
    void process_logic();

    /// Renders a frame. Calls renderer::render_frame() internally.
    /// \see renderer::render_frame()
    void render_frame();

    /// Pulls input events. Calls input::update() internally.
    /// \see input::update()
    void pull_events();

    /// Performs all the necessary cleanup. Runs once at the end of the application.
    void on_exit();
}
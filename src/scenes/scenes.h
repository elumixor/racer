//
// Created by vlado on 5/6/20.
//

#ifndef RACER_SCENES_H
#define RACER_SCENES_H

namespace scenes {
    /// Abstract base class for the scenes.
    /// Lets us place whichever scene we want as a current scene and use virtual update() calls in the application::process_logic()
    struct Scene {
        /// on_init() is called when the scene is loaded
        virtual void on_init();

        /// update() is called every update, from application::process_logic()
        virtual void update();

        /// on_destroy() is called when the scene is unloaded
        virtual void on_destroy();
    };

    /// Lets us start the game, change car or exit
    class MainMenu;

    /// Lets us select a new car (from 3 options available)
    class CarSelection;

    /// Main game scene. Here we ride our car and try hard not to crash.
    class Track;

    /// This is displayed when the player crashed, we can start over, switch to a different car, or exit
    class GameOver;

    /// This scene is loaded in application::initialize()
    using StartingScene = scenes::MainMenu;
}

namespace scene {
    /// Retrieves an instance of the scene. Note that every scene is treated as a singleton.
    template<typename T>
    T *get();

    /// Currently loaded scene.
    extern scenes::Scene *current;

    /// Loads selected scene. This should not be called directly. Use scene::load<...>() instead
    void load(scenes::Scene *);

    /// Loads selected scene.
    template<typename T>
    void load() {
        auto instance = (scenes::Scene *) scene::get<T>();
        load(instance);
    }
}


#endif //RACER_SCENES_H

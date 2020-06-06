cmake_minimum_required(VERSION 3.16)
project(racer CXX)

#set(CMAKE_C_STANDARD 99)

add_executable(racer
        main.cpp
        behaviour/behaviour.h behaviour/behaviour.cpp
        output/printing.cpp output/printing.h
        scenes/main_menu.cpp scenes/main_menu.h
        scenes/car_selection.cpp scenes/car_selection.h
        scenes/scenes.cpp scenes/scenes.h
        application/application.cpp application/application.h
        io/input.h io/input.cpp
        scenes/track.cpp scenes/track.h scenes/game_over.cpp scenes/game_over.h
        renderer/renderer.cpp renderer/renderer.h io/screen.cpp io/screen.h renderer/graphics/graphics.cpp renderer/graphics/graphics.h)

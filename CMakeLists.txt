cmake_minimum_required(VERSION 3.16)
project(racer CXX)

#set(CMAKE_C_STANDARD 99)

add_executable(racer
        main.cpp
        behaviour.h behaviour.cpp
        output/printing.cpp output/printing.h
        common/types.h
        scenes/main_menu/MainMenuScene.cpp scenes/main_menu/MainMenuScene.h
        scenes/scenes.cpp scenes/scenes.h
        application/application.cpp application/application.h
        input/input.h input/input.cpp)

cmake_minimum_required(VERSION 3.11)
project(OOP_indie_studio_2018)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include("FindIrrlicht.cmake")

add_executable(bomberman
        src/main.cpp
        src/Game/Ai.cpp
        src/Game/Ai.hpp
        src/Game/Game.cpp
        src/Game/Game.hpp
        src/Game/Player.cpp
        src/Game/Player.hpp
        src/Game/Wall.cpp
        src/Game/Wall.hpp
        src/Game/Bomb.cpp
        src/Game/Bomb.hpp
        src/Graphics/Graphics.cpp
        src/Graphics/Graphics.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp
        src/Menu/GameMenu.cpp
        src/Menu/GameMenu.hpp)

target_link_libraries(bomberman
        Irrlicht
        sfml-audio)

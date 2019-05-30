cmake_minimum_required(VERSION 3.14)
project(OOP_indie_studio_2018)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include("FindIrrlicht.cmake")

add_executable(bomberman
        src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.hpp
        src/Game/Player.cpp
        src/Game/Player.hpp
        src/Game/Wall.cpp
        src/Game/Wall.hpp
        src/Graphics/Graphics.cpp
        src/Graphics/Graphics.hpp
        src/Menu/Menu.cpp
        src/Menu/Menu.hpp)

target_link_libraries(bomberman
        Irrlicht)

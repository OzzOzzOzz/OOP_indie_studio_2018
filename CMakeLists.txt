cmake_minimum_required(VERSION 3.14)
project(OOP_indie_studio_2018)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include("FindIrrlicht.cmake")

add_executable(bomberman
        src/Game.cpp
        src/Game.hpp
        src/Graphics.cpp
        src/Graphics.hpp
        src/main.cpp
        src/Menu.cpp
        src/Menu.hpp)

target_link_libraries(bomberman
        Irrlicht)

cmake_minimum_required(VERSION 3.14)
project(Indie_Studio)

set(CMAKE_CXX_STANDARD 14)

include("FindIrrlicht.cmake")

add_executable(bomberman
        src/main.cpp)

target_link_libraries(bomberman
                Irrlicht)

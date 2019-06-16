/*
 EPITECH PROJECT, 2018
 File Name: Bomb.hpp
 File description:
 Mathieu Gery
*/
#ifndef OOP_INDIE_STUDIO_2018_BOMB_HPP
#define OOP_INDIE_STUDIO_2018_BOMB_HPP

#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include "irrlicht/irrlicht.h"
#include "Map.hpp"

#define BOMB_SIZE irr::core::vector3df(0.3f, 0.3f, 0.3f)
#define BOMB_TIMER 2

class Bomb {
public:
    Bomb(irr::IrrlichtDevice *window, Map *map, const irr::core::vector3df& vector, int range);
    ~Bomb();

    std::vector<irr::core::vector2di> update();
    std::vector<irr::core::vector2di> bombRay(const irr::core::vector2di& dir);
    bool isExploded() const;

private:
    irr::IrrlichtDevice *_window;
    irr::scene::IAnimatedMeshSceneNode *_bomb;
    irr::scene::IAnimatedMesh *_mesh;
    irr::core::vector2di _txtPos;

    Map *_map;
    std::time_t _spawnTime;
    bool _exploded;

    int _range;
};


#endif //OOP_INDIE_STUDIO_2018_BOMB_HPP

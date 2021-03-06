/*
** EPITECH PROJECT, 2018
** File Name : Map.hpp
** File description:
** Ozz
*/

#ifndef OOP_INDIE_STUDIO_2018_MAP_HPP
#define OOP_INDIE_STUDIO_2018_MAP_HPP
#include <string>
#include <iostream>
#include <vector>
#include "Wall.hpp"


#define MAP_SIZE 21.0f
#define CUBE_SIZE 20.0f
#define WALL_PCT 70
#define VOID '0'
#define WALL '1'
#define BEDROCK '2'

class Bomb;

class Map {
public:
    Map(irr::IrrlichtDevice *window);
    Map(irr::IrrlichtDevice *window, std::vector<std::string> txtMap);

    void spawnBomb(irr::core::vector3df pos, int range);

    std::vector<irr::core::vector2di> update();

    const std::vector<std::string> &getTxtMap() const;
    const char getTxtMapItem(const irr::core::vector2di& pos) const;
    const std::vector<Wall *> &getWalls() const;
    void deleteMapWall(const irr::core::vector2di& pos);

private:
    std::vector<std::string> gen_sub_map();
    void gen_txt_map();
    void createMap();

    irr::IrrlichtDevice *_window;

    std::vector<std::string> _txtMap;
    std::vector <Wall *> _walls;
    std::vector <Wall *> _floor;
    std::vector <Bomb *> _bombs;
};



#endif
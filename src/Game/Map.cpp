#include <utility>

/*
** EPITECH PROJECT, 2018
** File Name : Map.cpp
** File description:
** Ozz
*/
#include <string>
#include <iostream>
#include "Map.hpp"
#include "Bomb.hpp"

Map::Map(irr::IrrlichtDevice *window) : _window(window)
{
    gen_txt_map();
    createMap();
}

Map::Map(irr::IrrlichtDevice *window, std::vector<std::string> txtMap) : _window(window), _txtMap(std::move(txtMap))
{
    createMap();
}

const std::vector<std::string> &Map::getTxtMap() const
{
    return _txtMap;
}

const std::vector<Wall *> &Map::getWalls() const
{
    return _walls;
}

std::vector<std::string> Map::gen_sub_map()
{
    int x_len = static_cast<int>(ceil(MAP_SIZE / 2));
    int y_len = static_cast<int>(floor(MAP_SIZE / 2));
    std::vector<std::string> sub_map;

    for (int x = 0; x < x_len; x++) {
        sub_map.emplace_back(y_len, VOID);
        for (int y = 0; y < y_len; y++) {
            if ((x == 1 && y == 1) || (x == 2 && y == 1) ||
                (x == 1 && y == 2))
                sub_map[x][y] = VOID;
            else if (x == 0 || y == 0 || (x % 2 == 0 && y % 2 == 0))
                sub_map[x][y] = BEDROCK;
            else if (std::rand() % 100 < WALL_PCT)
                sub_map[x][y] = WALL;
            else
                sub_map[x][y] = VOID;
        }
    }
    return (sub_map);
}

void Map::gen_txt_map()
{
    std::vector<std::string> sub_map = gen_sub_map();
    int x_len = static_cast<int>(sub_map.size());
    int y_len = static_cast<int>(sub_map[0].size());

    for (int x = 0; x < MAP_SIZE; x++)
        _txtMap.emplace_back(MAP_SIZE, VOID);
    for (int x = 0; x < x_len; x++)
        for (int y = 0; y <= y_len; y++) {
            _txtMap[x][y] = sub_map[x][y];
            _txtMap[y][MAP_SIZE - 1 - x] = sub_map[x][y];
            _txtMap[MAP_SIZE - 1 - x][MAP_SIZE - 1 - y] = sub_map[x][y];
            _txtMap[MAP_SIZE - 1 - y][x] = sub_map[x][y];
        }
    _txtMap[static_cast<int>(ceil(MAP_SIZE / 2) - 1)][static_cast<int>(ceil(MAP_SIZE / 2) - 1)] = BEDROCK;
}

void Map::createMap()
{
    for (int x = 0; x <= MAP_SIZE; x++)
        for (int y = 0; y <= MAP_SIZE; y++)
            _floor.push_back(new Wall(_window, true, irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, -CUBE_SIZE), "assets/game/floor.png"));
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            if (_txtMap[x][y] == BEDROCK)
                _walls.push_back(new Wall(_window, false, irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, 0.0f), "assets/game/bedrock.png"));
            else if (_txtMap[x][y] == WALL)
                _walls.push_back(new Wall(_window, true, irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, 0.0f), "assets/game/planks.png"));
        }
    }
}

void Map::deleteMapWall(int x, int y)
{
    for (int i = 0; i < _walls.size(); i++)
        if (_walls[i]->getTxtPos().X == pos.X && _walls[i]->getTxtPos().Y == pos.Y) {
            _walls[i]->getNode()->remove();
            _walls.erase(_walls.begin() + i);
        }
}

void Map::spawnBomb(irr::core::vector3df pos, int range)
{
    int playerX = static_cast<int>(pos.X / CUBE_SIZE);
    int playerY = static_cast<int>(pos.Y / CUBE_SIZE);

    pos = irr::core::vector3df(playerX * CUBE_SIZE, playerY * CUBE_SIZE, 0.0f);
    _bombs.emplace_back(new Bomb(_window, this, pos, range));
//    for (int x = playerX - range < 0 ? 0 : playerX - range; x <= (playerX + range > MAP_SIZE ? MAP_SIZE : playerX + range); x++)
//        if (_txtMap[x][playerY] == WALL) {
//            _txtMap[x][playerY] = VOID;
//            deleteMapWall(x, playerY);
//        }
//    for (int y = playerY - range < 0 ? 0 : playerY - range; y <= (playerY + range > MAP_SIZE ? MAP_SIZE : playerY + range); y++)
//        if (_txtMap[playerX][y] == WALL) {
//			_txtMap[playerX][y] = VOID;
//			deleteMapWall(playerX, y);
//		}
}

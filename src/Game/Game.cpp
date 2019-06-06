/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "Wall.hpp"

Game::Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver,
    int nbplayers, int nbai)
{
    _nbai = nbai;
    _nbplayers = nbplayers;
    _window = window;
    _video = _window->getVideoDriver();
    _sceneManager = _window->getSceneManager();
    _sceneManager->addCameraSceneNode(0,
        irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE,
            (MAP_SIZE / 3) * CUBE_SIZE, (MAP_SIZE) * CUBE_SIZE),
        irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE,
            (MAP_SIZE / 2) * CUBE_SIZE, 0));
    createMap();
    _player = new Player(_window, receiver, 100, 100, false, _map);
    if (nbplayers == 2)
        _player2 = new Player(_window, receiver, 0, 0, true, _map);
}

Game::~Game()
{
}

int Game::gameHandling(int whichGame)
{
    _video->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
    _sceneManager->drawAll();
    _video->endScene();
    return 2;
}

bool Game::is_spawn_area(int x, int y)
{
    if ((x == 1 && y == 1)
        || (x == 2 && y == 1)
        || (x == 1 && y == 2))
        return true;
    else if ((x == 1 && y == MAP_SIZE - 2)
        || (x == 2 && y == MAP_SIZE - 2)
        || (x == 1 && y == MAP_SIZE - 3))
        return true;
    else if ((x == MAP_SIZE - 2 && y == 1)
        || (x == MAP_SIZE - 3 && y == 1)
        || (x == MAP_SIZE - 2 && y == 2))
        return true;
    else if ((x == MAP_SIZE - 2 && y == MAP_SIZE - 2)
        || (x == MAP_SIZE - 3 && y == MAP_SIZE - 2)
        || (x == MAP_SIZE - 2 && y == MAP_SIZE - 3))
        return true;
    return false;
}

std::vector<std::string> Game::gen_sub_map()
{
    int x_len = static_cast<int>(ceil(MAP_SIZE / 2));
    int y_len = static_cast<int>(floor(MAP_SIZE / 2));
    std::vector<std::string> sub_map;

    std::cout << "submap:" << std::endl;
    for (int x = 0; x < x_len; x++) {
        sub_map.emplace_back(y_len, VOID);
        for (int y = 0; y < y_len; y++) {
            if ((x == 1 && y == 1) || (x == 2 && y == 1) ||
                (x == 1 && y == 2)) {
                sub_map[x][y] = VOID;
            } else if (x == 0 || y == 0 || (x % 2 == 0 && y % 2 == 0)) {
                sub_map[x][y] = BEDROCK;
            } else if (std::rand() % 100 < WALL_PCT) {
                sub_map[x][y] = WALL;
            } else {
                sub_map[x][y] = VOID;
            }
        }
    }
    return sub_map;
}

void Game::gen_txt_map()
{
    std::vector<std::string> sub_map = gen_sub_map();
    int x_len = static_cast<int>(sub_map.size());
    int y_len = static_cast<int>(sub_map[0].size());

    for (int x = 0; x < MAP_SIZE; x++) {
        _txt_map.emplace_back(MAP_SIZE, VOID);
    }
    for (int x = 0; x < x_len; x++) {

        for (int y = 0; y <= y_len; y++) {
            _txt_map[x][y] = sub_map[x][y];
            _txt_map[y][MAP_SIZE - 1 - x] = sub_map[x][y];
            _txt_map[MAP_SIZE - 1 - x][MAP_SIZE - 1 - y] = sub_map[x][y];
            _txt_map[MAP_SIZE - 1 - y][x] = sub_map[x][y];
        }
    }
    _txt_map[static_cast<int>(ceil(MAP_SIZE / 2) - 1)]
            [static_cast<int>(ceil(MAP_SIZE / 2) - 1)] = 'x';
}

void Game::createMap()
{
    for (int x = 0; x <= MAP_SIZE; x++)
        for (int y = 0; y <= MAP_SIZE; y++)
            _floor.push_back(new Wall(_window, true,
                irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, -CUBE_SIZE),
                "assets/game/floor.png"));
    gen_txt_map();
    for (int x = 0; x < MAP_SIZE; x++)
        for (int y = 0; y < MAP_SIZE; y++) {
            if (_txt_map[x][y] == BEDROCK) {
                _map.push_back(new Wall(_window, false, irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, 0.0f), "assets/game/bedrock.png"));
            } else if(_txt_map[x][y] == WALL) {
                _map.push_back(new Wall(_window, true, irr::core::vector3df(x * CUBE_SIZE, y * CUBE_SIZE, 0.0f), "assets/game/planks.png"));

            }
        }
}

void Game::MovePlayer()
{
    _player->Move(1);
    if (_nbplayers == 2)
        _player2->Move(2);
}

/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/
#include <dirent.h>
#include "Game.hpp"
#include "Wall.hpp"

Game::Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int nbplayers, int nbai)
{
    _nbai = nbai;
    _nbplayers = nbplayers;
    _window = window;
    _video = _window->getVideoDriver();
    _sceneManager = _window->getSceneManager();
    _background = _video->getTexture("assets/game/game_background.png");
    _sceneManager->addCameraSceneNode(0,
        irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE,
            (MAP_SIZE / 3) * CUBE_SIZE, (MAP_SIZE) * CUBE_SIZE),
        irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE,
            (MAP_SIZE / 2) * CUBE_SIZE, 0));
	_player = new Player(_window, receiver, 20, 20, false);
    _gameMenu = new GameMenu(_window);
    if (nbplayers == 2)
        _player2 = new Player(_window, receiver, 380, 380, true);
}

Game::~Game()
{
}

void Game::gameLoop()
{
	int ret;

	while(_window->run()) {
		if (_player->getEventReceiver()->IsKeyDown(irr::KEY_ESCAPE)) {
			ret = _gameMenu->gameMenuHandling();
			if (ret == 2)
				saveGame();
		}
		gameHandling(0);
		MovePlayer(_map, _bombs);
	}
	_window->drop();
}

int Game::gameHandling(int whichGame)
{
    _video->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
    _video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
    _sceneManager->drawAll();
    _video->endScene();
    return 2;
}

int Game::saveGame()
{
	std::vector<std::string> files = getFilesfromFolder("./saves");

	for (int i = 0; i < files.size(); i++)
		std::cout << files.at(i) << std::endl;
	return (0);
}

std::vector<std::string> Game::getFilesfromFolder(const char *folderName)
{
	DIR *dir = opendir(folderName);
	struct dirent *ent;
	std::vector<std::string> files;

	if (!dir) {
		std::cerr << "Could not open saves directory" << std::endl;
		exit (84);
	}
	ent = readdir(dir);
	while (ent != nullptr) {
		if (ent->d_name[0] != '.')
			files.emplace_back(ent->d_name);
		ent = readdir(dir);
	}
	closedir(dir);
	return (files);
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

void Game::MovePlayer(std::vector <Wall *> map, std::vector <Bomb *> bombs)
{
    _player->Move(1, map, bombs);
    if (_nbplayers == 2)
        _player2->Move(2, map, bombs);
}

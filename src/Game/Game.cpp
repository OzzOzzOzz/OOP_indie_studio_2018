/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "Wall.hpp"

Game::Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int nbplayers, int nbai)
{
    _nbai = nbai;
    _nbplayers = nbplayers;
	_window = window;
	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();
	_sceneManager->addCameraSceneNode(0, irr::core::vector3df(0.0f, 250.0f, -150.0f), irr::core::vector3df(0, -500.0f, 150.0f));
    _player = new Player(_window, receiver, 100, 100, false);

    _metaselector = _sceneManager->createMetaTriangleSelector();


    irr::scene::ITriangleSelector *_selector = 0;

    _selector = _sceneManager->createOctreeTriangleSelector(_player->getMesh(), _player->getNode());
    _player->getNode()->setTriangleSelector(_selector);
    _metaselector->addTriangleSelector(_selector);





    if (nbplayers == 2)
        _player2 = new Player(_window, receiver, 0, 0, true);
}

Game::~Game()
{
}

int Game::gameHandling(int whichGame)
{
	_video->beginScene(true, true, irr::video::SColor(255,200,200,200));
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

void Game::gen_txt_map()
{
	for (int x = 0; x <= MAP_SIZE; x++) {
		_txt_map.emplace_back(MAP_SIZE, VOID);
		for (int y = 0; y <= MAP_SIZE; y++) {
		    //std::cout << "pos:[" << x << "][" << y << "]" << std::endl;
			if (x == 0 || x == MAP_SIZE - 1 || y == 0 || y == MAP_SIZE - 1) {
				_txt_map[x][y] = BEDROCK;
			} else if(x % 2 == 0 && y % 2 == 0) {
				_txt_map[x][y] = BEDROCK;
			} else if(is_spawn_area(x, y)) {
				_txt_map[x][y] = 'X';
			} else if(std::rand() % 100 < WALL_PCT) {
				_txt_map[x][y] = WALL;
			} else {
				_txt_map[x][y] = VOID;
			}
		}
	}
	for(int i = 0; i < MAP_SIZE; i++)
		std::cout << _txt_map[i] << std::endl;
}

void Game::createMap()
{
//	for (int x = 0; x <= MAP_SIZE; x++)
//		for (int y = 0; y <= MAP_SIZE; y++)
//		    _floor.push_back(new Wall(_window, true, irr::core::vector3df(y * CUBE_SIZE, 0.0f, x * CUBE_SIZE), "assets/game/floor.png"));
	gen_txt_map();
	for (int x = 0; x <= MAP_SIZE; x++)
		for (int y = 0; y <= MAP_SIZE; y++) {
			if (_txt_map[x][y] != VOID)
			_map.push_back(new Wall(_window, false, irr::core::vector3df(y * CUBE_SIZE, -CUBE_SIZE, x * CUBE_SIZE), "assets/game/planks.png"));
		}
}

void Game::MovePlayer(int id)
{
    _player->Move(1);
    if (_nbplayers == 2)
        _player2->Move(2);
}
/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "Wall.hpp"

Game::Game(irr::IrrlichtDevice *window)
{
	_window = window;
	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();
	_sceneManager->addCameraSceneNode(0, irr::core::vector3df(0.0f, 200.0f, -300.0f), irr::core::vector3df(0.0f, -500.0f, 300.0f));
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

void Game::createMap()
{
	for (int x = -5; x < 6; x++)
		for (int i = -5; i < 6; i++)
			_floor.push_back(new Wall(_window, true, irr::core::vector3df(i * 40.0f, 0.0f, x * 40.0f), "assets/game/planks.png"));
	for (int x = -10; x < 12; x++)
		for (int i = -10; i < 12; i++)
			_map.push_back(new Wall(_window, true, irr::core::vector3df(i * 20.0f, -20.0f, x * 20.0f), "assets/game/floor.png"));
}
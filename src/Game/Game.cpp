/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game(irr::IrrlichtDevice *window)
{
	_window = window;
	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();
	_sceneManager->addCameraSceneNode(0, irr::core::vector3df((10) * 5.0f, 0.0f, -60.0f), irr::core::vector3df(-50.0f, 5.0f, 0.0f));
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
	_cube = _sceneManager->addCubeSceneNode(30.0f, 0, -1, irr::core::vector3df(0.0f, 0.0f, 20.0f));
	_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_cube->setMaterialTexture(0, _video->getTexture("assets/game/planks.png"));
}
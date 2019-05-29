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
}

Game::~Game()
{
}

int Game::gameHandling(int whichGame)
{
	_video->beginScene(true, true, irr::video::SColor(255,200,200,200));
	_sceneManager->drawAll();
	_video->endScene();
	return 0;
}

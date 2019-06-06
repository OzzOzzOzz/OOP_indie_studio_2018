/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** GameMenu
*/

#include "GameMenu.hpp"

GameMenu::GameMenu(irr::IrrlichtDevice *window)
{
	_window = window;
	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();
	_background = _video->getTexture("assets/menu/ingame_menu.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));
}

GameMenu::~GameMenu()
{
}

void GameMenu::gameMenuHandling()
{
	_sceneManager->clear();
	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_sceneManager->drawAll();
		_video->endScene();
	}
}

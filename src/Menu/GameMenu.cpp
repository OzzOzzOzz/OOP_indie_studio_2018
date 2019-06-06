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
	_htpBackground = _video->getTexture("assets/menu/how_to_play.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));
}

GameMenu::~GameMenu()
{
}

void GameMenu::initializeButtons()
{
	int size = 340;

	for (int i = 0; i < 4; i++, size += 170)
		_mainButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(710, size, 710 + 500, size + 120), nullptr, 0, L""));
	_howToPlayBack = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(75, 70, 75 + 220, 70 + 120), nullptr, 0, L"");
}

int GameMenu::gameMenuHandling()
{
	int ret = 0;
	initializeButtons();

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		ret = buttonsHandling();
		if (ret == 1 || ret == 2) {
			_mainButtons.clear();
			return ret;
		}
		_video->endScene();
	}
	_mainButtons.clear();
	return(ret);
}

int GameMenu::buttonsHandling()
{
	if (_mainButtons[0]->isPressed())
		return (1);
	if (_mainButtons[1]->isPressed())
		return (2);
	if (_mainButtons[2]->isPressed())
		howToPlay();
	if (_mainButtons[3]->isPressed())
		exit (0);
	return (0);
}

void GameMenu::howToPlay()
{
	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_htpBackground, irr::core::position2d<irr::s32>(0, 0));
		if (_howToPlayBack->isPressed())
			return;
		_video->endScene();
	}
}

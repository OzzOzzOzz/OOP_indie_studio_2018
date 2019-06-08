/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphics.cpp
*/

#include "Graphics.hpp"

Graphics::Graphics()
{
	_receiver = new MyEventReceiver();
	_window = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, _receiver);
	_menu = new Menu(_window);
	_window->setWindowCaption(L"Indie Studio");
}

Graphics::~Graphics()
{
}

void Graphics::gameSettings()
{
	int players = 1;
	int bots = 0;

	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();

	_background = _video->getTexture("assets/menu/choose_players_menu.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));
	_startButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(735, 910, 735 + 500, 910 + 120), nullptr, 0, L"START");

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_sceneManager->drawAll();
		if (_startButton->isPressed()) {
			_game = new Game(_window, _receiver, players, bots);
			return;
		}
		_video->endScene();
	}
}
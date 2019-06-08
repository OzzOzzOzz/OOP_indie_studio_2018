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
	_players = 1;
	_bots = 0;
}

Graphics::~Graphics()
{
}

void Graphics::buttonsInitialize()
{
	_startButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(735, 910, 735 + 500, 910 + 120), nullptr, 0, L"START");
}

void Graphics::gameSettings()
{
	int ret = 0;

	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();

	_background = _video->getTexture("assets/menu/choose_players_menu.png");
	_firstBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_secondBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_thirdBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));

	buttonsInitialize();
	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_firstBox, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_secondBox, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_thirdBox, irr::core::position2d<irr::s32>(0, 0));
		_sceneManager->drawAll();
//		ret = buttonsHandling();
		if (ret == 1) {
			_game = new Game(_window, _receiver, _players, _bots);
			return;
		}
		_video->endScene();
	}
}

int Graphics::buttonsHandling()
{
	if (_startButton->isPressed())
		return 1;

	if (_plusButtons[0]->isPressed()) {
		_firstBox = _video->getTexture("assets/menu/buttons/player2_rectangle.png");
		_players++;
		//disable the button
	}

	if (_choosePlayerOrAI->isPressed()) {
		if (_players == 2) {
			_players--;
			_bots++;
			_firstBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
		} else {
			_players++;
			_bots--;
			_firstBox = _video->getTexture("assets/menu/buttons/player2_rectangle.png");
		}
	}

	if (_plusButtons[1]->isPressed()) {
		if (_bots == 0)
			_secondBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
		else
			_secondBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
		_bots++;
		//disable the button
	}

	if (_plusButtons[2]->isPressed()) {
		if (_bots == 1)
			_thirdBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
		else
			_thirdBox = _video->getTexture("assets/menu/buttons/AI3_rectangle.png");
		_bots++;
		//disable the button
	}
}
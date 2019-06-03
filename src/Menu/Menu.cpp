/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *window)
{
    _window = window;
    _video = _window->getVideoDriver();
    _sceneManager = _window->getSceneManager();
    _background = _video->getTexture("assets/menu/main_menu.png");
    _video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));
    initializeButtons();
}

Menu::~Menu()
{
}

void Menu::initializeButtons()
{
	int size = 350;

	for (int i = 0; i < 4; i++, size+= 170)
		_mainButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(330, size, 330 + 500, size + 120), nullptr, 0, L""));
}

int Menu::menuHandling()
{
	int ret = 0;

	_video->beginScene(true, true, irr::video::SColor(255,100,101,140));
	_window->getGUIEnvironment()->drawAll();
	_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
	_sceneManager->drawAll();
	ret = buttonHandling();
	_video->endScene();
    	return (ret);
}

int Menu::buttonHandling()
{
	if (_mainButtons[0]->isPressed())
		return (1);
	if (_mainButtons[1]->isPressed())
		std::cout << "Load Game pressed" << std::endl;
	if (_mainButtons[2]->isPressed())
		std::cout << "Settings button pressed" << std::endl;
	if (_mainButtons[3]->isPressed())
		exit (0);
	return 0;
}
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
	_background = _video->getTexture("assets/menu/menu.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));
	initializeButtons();
}

Menu::~Menu()
{
}

void Menu::initializeButtons()
{
	int size = 450;
	std::vector<wchar_t *> buttonsText = {L"Play", L"Load Game", L"Settings", L"Exit"};

	for (int i = 0; i < 4; i++) {
		_buttons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1500, size, 1500 + 400, size + 100), nullptr, 0, buttonsText[i]));
		size += 150;
	}
}

int Menu::menuHandling()
{
	int ret = 0;
	_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
	_sceneManager->drawAll();
	_window->getGUIEnvironment()->drawAll();
	ret = buttonHandling();
	_video->endScene();
    return (ret);
}

int Menu::buttonHandling()
{
	if (_buttons[0]->isPressed()) {
		std::cout << "Play button pressed" << std::endl;
		return (1);
	}
	if (_buttons[1]->isPressed())
		std::cout << "Load Game pressed" << std::endl;
	if (_buttons[2]->isPressed())
		std::cout << "Settings button pressed" << std::endl;
	if (_buttons[3]->isPressed())
		exit (0);
}
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
	if (!_clickBuffer.loadFromFile("assets/sounds/mouse_click.ogg")) {
		std::cerr << "Error while loading mouse_click.ogg" << std::endl;
		exit (84);
	}
	_clickSound.setBuffer(_clickBuffer);
}

Menu::~Menu()
{
}

void Menu::initializeButtons()
{
	int size = 350;
	std::vector<const wchar_t *> buttonsText = {L"", L"", L"", L""};

	for (int i = 0; i < 4; i++) {
		_mainButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(330, size, 330 + 500, size + 120), nullptr, 0, buttonsText[i]));
		size += 170;
	}
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
	if (_mainButtons[0]->isPressed()) {
		_clickSound.play();
		return (1);
	}
	if (_mainButtons[1]->isPressed())
		std::cout << "Load Game pressed" << std::endl;
	if (_mainButtons[2]->isPressed())
		std::cout << "Settings button pressed" << std::endl;
	if (_mainButtons[3]->isPressed()) {
		_clickSound.play();
		exit (0);
	}
	return 0;
}
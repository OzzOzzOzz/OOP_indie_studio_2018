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
	_background = _video->getTexture("../assets/menu.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0,0));
}

Menu::~Menu()
{
}

int Menu::menuHandling()
{
        _sceneManager->drawAll();
	_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0,0));
	_video->endScene();
        return 0;
}

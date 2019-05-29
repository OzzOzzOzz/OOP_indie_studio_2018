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
}

Menu::~Menu()
{
}

int Menu::menuHandling()
{
        _video->beginScene(true, true, irr::video::SColor(255,100,101,140));
        _sceneManager->drawAll();
        _video->endScene();
        return 0;
}

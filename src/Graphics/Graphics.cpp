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
	_game = new Game(_window);
	_player = new Player(_window, _receiver, 0, 0);
    _window->setWindowCaption(L"Indie Studio");
}

Graphics::~Graphics()
{
}

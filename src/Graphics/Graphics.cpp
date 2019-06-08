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

	_game = new Game(_window, _receiver, players, bots);
}
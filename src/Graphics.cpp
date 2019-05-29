/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphics.cpp
*/

#include "Graphics.hpp"

Graphics::Graphics()
{
	_window = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, nullptr);
	_menu = new Menu(_window);
	_game = new Game(_window);
}

Graphics::~Graphics()
{
}

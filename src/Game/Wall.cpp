/*
** EPITECH PROJECT, 2018
** File Name: Wall.cpp
** File description:
** Rémi Bisson
*/
#include "Wall.hpp"

Wall::Wall(bool isBreakable)
{
	_isBreakable = isBreakable;
	if (!_isBreakable)
		_sprite = "NOT BREAKABLE";
	else
		_sprite = "BREAKABLE";
}

Wall::~Wall()
{
}

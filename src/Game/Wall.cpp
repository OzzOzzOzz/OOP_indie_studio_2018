/*
** EPITECH PROJECT, 2018
** File Name: Wall.cpp
** File description:
** Rémi Bisson
*/
#include <iostream>
#include "Wall.hpp"

Wall::Wall(irr::IrrlichtDevice *window, bool isBreakable, irr::core::vector3df pos, std::string _texture)
{
	_cube = window->getSceneManager()->addCubeSceneNode(WALL_SIZE, 0, -1, pos);
	_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_cube->setMaterialTexture(0, window->getVideoDriver()->getTexture(_texture.c_str()));
    _txtPos.X = static_cast<int>(pos.X / WALL_SIZE);
    _txtPos.Y = static_cast<int>(pos.Y / WALL_SIZE);
	_isBreakable = isBreakable;
}

Wall::~Wall()
{
}
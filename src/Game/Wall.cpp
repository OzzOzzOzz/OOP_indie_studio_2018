/*
** EPITECH PROJECT, 2018
** File Name: Wall.cpp
** File description:
** Rémi Bisson
*/
#include "Wall.hpp"

Wall::Wall(irr::IrrlichtDevice *window, bool isBreakable, irr::core::vector3df vector, std::string _texture)
{
	_cube = window->getSceneManager()->addCubeSceneNode(WALL_SIZE, 0, -1, vector);
	_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_cube->setMaterialTexture(0, window->getVideoDriver()->getTexture(_texture.c_str()));

	_isBreakable = isBreakable;
}

Wall::~Wall()
{
}

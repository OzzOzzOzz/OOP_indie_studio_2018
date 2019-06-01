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

	//_cube = _sceneManager->addCubeSceneNode(10.0f, 0, -1, irr::core::vector3df(0.0f, 0.0f, 0.0f));
	//_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	//_cube->setMaterialTexture(0, _video->getTexture("assets/game/planks.png"));
}

Wall::~Wall()
{
}

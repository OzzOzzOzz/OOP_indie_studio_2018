/*
 EPITECH PROJECT, 2018
 File Name: Bomb.cpp
 File description:
Mathieu Gery
*/

#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice *window, irr::core::vector3df vector, std::string _texture)
{
    _bomb = window->getSceneManager()->addCubeSceneNode(BOMB_SIZE, 0, -1, vector);
    _bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _bomb->setMaterialTexture(0, window->getVideoDriver()->getTexture(_texture.c_str()));
}

Bomb::~Bomb()
{
}

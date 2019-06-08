/*
 EPITECH PROJECT, 2018
 File Name: Bomb.cpp
 File description:
Mathieu Gery
*/

#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice *window, irr::core::vector3df vector, std::string _texture)
{
    _mesh = window->getSceneManager()->getMesh("assets/game/bomb.3DS");
    _bomb = window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _bomb->setMD2Animation(irr::scene::EMAT_STAND);
    _bomb->setPosition(vector);
    _bomb->setScale(irr::core::vector3df(0.3f, 0.3f, 0.3f));
    _bomb->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/game/bomb.png"));
    //_bomb->setMaterialTexture(0, window->getVideoDriver()->getTexture(_texture.c_str()));
}

Bomb::~Bomb()
{
}

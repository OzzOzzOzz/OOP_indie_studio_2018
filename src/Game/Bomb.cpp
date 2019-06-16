/*
 EPITECH PROJECT, 2018
 File Name: Bomb.cpp
 File description:
Mathieu Gery
*/

#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice *window, Map *map, const irr::core::vector3df &pos, int range) :
    _window(window),
    _map(map),
    _range(range),
    _spawnTime(std::time(nullptr)),
    _exploded(false)
{
    _txtPos.X = static_cast<int>(pos.X / CUBE_SIZE);
    _txtPos.Y = static_cast<int>(pos.Y / CUBE_SIZE);
    _mesh = window->getSceneManager()->getMesh("assets/game/bomb.3DS");
    _bomb = window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _bomb->setMD2Animation(irr::scene::EMAT_STAND);
    _bomb->setPosition(pos);
    _bomb->setScale(BOMB_SIZE);
    _bomb->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/game/bomb.png"));
}

Bomb::~Bomb()
{
}

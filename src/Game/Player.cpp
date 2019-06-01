/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include <Graphics/Graphics.hpp>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y)
{
    _receiver = receiver;
    _window = window;
    _mesh = _window->getSceneManager()->getMesh("assets/game/sydney.md2");
    _player1 = _window->getSceneManager()->addAnimatedMeshSceneNode( _mesh );
    _player1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _player1->setMD2Animation(irr::scene::EMAT_STAND);
    _player1->setMaterialTexture( 0, _window->getVideoDriver()->getTexture("assets/game/sydney.bmp") );
}

Player::~Player()
{
}

void Player::Move()
{
    irr::core::vector3df nodePosition = _player1->getPosition();
    if(_receiver->IsKeyDown(irr::KEY_KEY_Z))
        nodePosition.Z += 2.0f;
    else if(_receiver->IsKeyDown(irr::KEY_KEY_S))
        nodePosition.Z -= 2.0f;
    if(_receiver->IsKeyDown(irr::KEY_KEY_Q))
        nodePosition.X -= 2.0f;
    else if(_receiver->IsKeyDown(irr::KEY_KEY_D))
        nodePosition.X += 2.0f;
    if(_receiver->IsKeyDown(irr::KEY_ESCAPE))
        exit (0);
    _player1->setPosition(nodePosition);
}

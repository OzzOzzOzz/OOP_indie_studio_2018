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
    _mesh = _window->getSceneManager()->getMesh("assets/game/ziggs.md3");
    _player1 = _window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _player1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _player1->setMD2Animation(irr::scene::EMAT_STAND);
    _player1->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/game/ziggs.png"));
    _player1->setFrameLoop(0, 95);
}

Player::~Player()
{
}

void Player::Move()
{
    irr::core::vector3df nodePosition = _player1->getPosition();
    if(_receiver->IsKeyDown(irr::KEY_KEY_Z)) {
        _player1->setRotation(irr::core::vector3df(0.0f, 180.0f, 0.0f));
        nodePosition.Z += 2.0f;
    }
    else if(_receiver->IsKeyDown(irr::KEY_KEY_S)) {
        nodePosition.Z -= 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
    }
    if(_receiver->IsKeyDown(irr::KEY_KEY_Q)) {
        nodePosition.X -= 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 90.0f, 0.0f));
    }
    else if(_receiver->IsKeyDown(irr::KEY_KEY_D)) {
        nodePosition.X += 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 270.0f, 0.0f));
    }
    if(_receiver->IsKeyDown(irr::KEY_ESCAPE))
        exit (0);
    _player1->setPosition(nodePosition);
}

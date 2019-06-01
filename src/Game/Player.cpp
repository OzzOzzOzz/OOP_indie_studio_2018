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
	_position.push_back(x);
	_position.push_back(y);
    _gamer = window->getSceneManager()->addCubeSceneNode(20.0f, 0, -1, irr::core::vector3df(20.0f, 0.0f, 20.0f));
    _gamer->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _gamer->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/game/stone.png"));
}

Player::~Player()
{
}

void Player::Move()
{
    irr::core::vector3df nodePosition = _gamer->getPosition();
    if(_receiver->IsKeyDown(irr::KEY_KEY_Z))
        nodePosition.Z += 2.0f;
    else if(_receiver->IsKeyDown(irr::KEY_KEY_S))
        nodePosition.Z -= 2.0f;

    if(_receiver->IsKeyDown(irr::KEY_KEY_Q))
        nodePosition.X -= 2.0f;
    else if(_receiver->IsKeyDown(irr::KEY_KEY_D))
        nodePosition.X += 2.0f;
    _gamer->setPosition(nodePosition);
}

std::vector<int> Player::getPosition()
{
	return (_position);
}

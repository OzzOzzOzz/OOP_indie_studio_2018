/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include "Player.hpp"

Player::Player(int x, int y)
{
	_position.push_back(x);
	_position.push_back(y);
}

Player::~Player()
{
}

void Player::setPosition(int x, int y)
{
	_position[0] = x;
	_position[1] = y;
}

std::vector<int> Player::getPosition()
{
	return (_position);
}

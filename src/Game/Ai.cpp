/*
** EPITECH PROJECT, 2018
** File Name: Ai.cpp
** File description:
** Rémi Bisson
*/
#include <zconf.h>
#include "Ai.hpp"

AI::AI(irr::IrrlichtDevice *window, int x, int y)
{
	_window = window;
	_mesh = _window->getSceneManager()->getMesh("assets/game/ziggs.md3");
	_ai = _window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
	_ai->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_ai->setMD2Animation(irr::scene::EMAT_STAND);
	_ai->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/game/ziggs.png"));
	_ai->setFrameLoop(96, 96 + 96);
	_ai->setPosition(irr::core::vector3df(x, y, 0.0f));
	_ai->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
	_ai->setScale(irr::core::vector3df(0.9f, 0.9f, 0.9f));
	_bombNumber = 1;
	_range = 2;
	_dir = rand() % 4 + 1;
}

AI::~AI()
{
}

void AI::moveRight()
{
	irr::core::vector3df nodePosition = _ai->getPosition();

	_ai->setRotation(irr::core::vector3df(90.0f, 0.0f, 90.0f));
	nodePosition.X -= SPEED;
	_ai->setPosition(nodePosition);
	_dir = RIGHT;
}

void AI::move()
{
	if (_dir == UP)
		moveUp();
	if (_dir == DOWN)
		moveDown();
	if (_dir == LEFT)
		moveLeft();
	if (_dir == RIGHT)
		moveRight();
}

void AI::moveLeft()
{
	irr::core::vector3df nodePosition = _ai->getPosition();

	_ai->setRotation(irr::core::vector3df(90.0f, 0.0f, -90.0f));
	nodePosition.X += SPEED;
	_ai->setPosition(nodePosition);
	_dir = LEFT;
}

void AI::moveUp()
{
	irr::core::vector3df nodePosition = _ai->getPosition();

	_ai->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
	nodePosition.Y += SPEED;
	_ai->setPosition(nodePosition);
	_dir = UP;
}

void AI::moveDown()
{
	irr::core::vector3df nodePosition = _ai->getPosition();

	_ai->setRotation(irr::core::vector3df(-90.0f, 180.0f, 0.0f));
	nodePosition.Y -= SPEED;
	_ai->setPosition(nodePosition);
	_dir = DOWN;
}

int AI::collision(std::vector <Wall *> &map)
{
	for (auto const &map : map) {
		if (_dir == UP && _ai->getPosition().Y + PLAYER_SIZE + SPEED >= map->getPosition().Y && _ai->getPosition().Y + SPEED <= map->getPosition().Y + PLAYER_SIZE && ((_ai->getPosition().X + PLAYER_SIZE >= map->getPosition().X && _ai->getPosition().X <= map->getPosition().X + PLAYER_SIZE)))
			return (-1);
		else if (_dir == LEFT && _ai->getPosition().X + PLAYER_SIZE + SPEED >= map->getPosition().X  && _ai->getPosition().X + SPEED <= map->getPosition().X + PLAYER_SIZE && ((_ai->getPosition().Y + PLAYER_SIZE >= map->getPosition().Y && _ai->getPosition().Y <= map->getPosition().Y + PLAYER_SIZE)))
			return (-1);
		else if (_dir == RIGHT && _ai->getPosition().Y <= map->getPosition().Y + PLAYER_SIZE && _ai->getPosition().Y + PLAYER_SIZE >= map->getPosition().Y && ((_ai->getPosition().X  - SPEED + PLAYER_SIZE >= map->getPosition().X && _ai->getPosition().X - SPEED <= map->getPosition().X + PLAYER_SIZE)))
			return (-1);
		else if (_dir == DOWN && _ai->getPosition().X <= map->getPosition().X + PLAYER_SIZE && _ai->getPosition().X + PLAYER_SIZE >= map->getPosition().X && ((_ai->getPosition().Y  - SPEED + PLAYER_SIZE >= map->getPosition().Y && _ai->getPosition().Y - SPEED <= map->getPosition().Y + PLAYER_SIZE)))
			return (-1);
	}
	return (0);
}

void AI::checkForBombs(std::vector <Wall *> &map)
{
	if (collision(map) != 0)
		_dir = rand() % 4 + 1;
	move();
}

void AI::findNearestPlayer()
{

}

void AI::tryToKill()
{

}

void AI::placeBomb()
{

}

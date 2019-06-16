/*
** EPITECH PROJECT, 2018
** File Name: Ai.cpp
** File description:
** Rémi Bisson
*/
#include <zconf.h>
#include "Ai.hpp"

AI::AI(irr::IrrlichtDevice *window, Map &map, int x, int y) : _map(map)
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

int AI::collision()
{
	auto aiX = _ai->getPosition().X;
	auto aiY = _ai->getPosition().Y;

	for (auto const &wall : _map.getWalls()) {
		auto wallX = wall->getPosition().X;
		auto wallY = wall->getPosition().Y;

		if (_dir == UP && aiY + PLAYER_SIZE + SPEED >= wallY &&
			aiY + SPEED <= wallY + PLAYER_SIZE &&
			((aiX + PLAYER_SIZE >= wallX && aiX <= wallX + PLAYER_SIZE))) {
			if (wall->isWallBreakable())
				nearBedrock = false;
			return (1);
		} else if (_dir == LEFT && aiX + PLAYER_SIZE + SPEED >= wallX &&
				   aiX + SPEED <= wallX + PLAYER_SIZE &&
				   ((aiY + PLAYER_SIZE >= wallY &&
					 aiY <= wallY + PLAYER_SIZE))) {
			if (wall->isWallBreakable())
				nearBedrock = false;
			return (1);
		} else if (_dir == RIGHT && aiY <= wallY + PLAYER_SIZE &&
				   aiY + PLAYER_SIZE >= wallY &&
				   ((aiX - SPEED + PLAYER_SIZE >= wallX &&
					 aiX - SPEED <= wallX + PLAYER_SIZE))) {
			if (wall->isWallBreakable())
				nearBedrock = false;
			return (1);
		} else if (_dir == DOWN && aiX <= wallX + PLAYER_SIZE &&
				   aiX + PLAYER_SIZE >= wallX &&
				   ((aiY - SPEED + PLAYER_SIZE >= wallY &&
					 aiY - SPEED <= wallY + PLAYER_SIZE))) {
			if (wall->isWallBreakable())
				nearBedrock = false;
			return (1);
		}
	}
	return (0);
}

void AI::checkForBombs()
{
	if (collision() != 0) {
		if (nearBedrock)
			_dir = rand() % 4 + 1;
		else
			placeBomb();
	}
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
	_map.spawnBomb(_ai->getPosition(), _range);
}

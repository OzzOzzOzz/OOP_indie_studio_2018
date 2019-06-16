/*
** EPITECH PROJECT, 2018
** File Name: Ai.hpp
** File description:
** Rémi Bisson
*/
#ifndef OOP_INDIE_STUDIO_2018_AI_HPP
#define OOP_INDIE_STUDIO_2018_AI_HPP

#include <irrlicht/irrlicht.h>
#include <vector>
#include "Wall.hpp"
#include "Map.hpp"

#define SPEED 1.0f
#define PLAYER_SIZE 15.0f

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

class AI {
public:
	AI(irr::IrrlichtDevice *window, Map *map, int x, int y);
	~AI();

	void move();
	void move(int direction);
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	irr::core::vector3df getPosition(){return _ai->getPosition();}
	irr::core::vector2di getTxtPos(){return _txtPos;}

	void checkForBombs();
	int collision(int direction);
	int oppositeDirection(int direction);
	void findNearestPlayer();
	void tryToKill();
	void placeBomb();

private:
	irr::IrrlichtDevice *_window;
	irr::scene::IAnimatedMesh *_mesh;
	irr::scene::IAnimatedMeshSceneNode *_ai;

	irr::core::vector3df _nearestPlayer;

	int _bombNumber;
	int _range;
	int _dir;
	int _goalPositionX;
	int _goalPositionY;

	bool nearBedrock;
	irr::core::vector2di _txtPos;

	Map *_map;
};

#endif
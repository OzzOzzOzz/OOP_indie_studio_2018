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

#define SPEED 1.0f
#define PLAYER_SIZE 15.0f

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

class AI {
public:
	AI(irr::IrrlichtDevice *window, int x, int y);
	~AI();

	void move();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void checkForBombs(std::vector <Wall *> &map);
	int collision(std::vector <Wall *> &map);
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
};

#endif
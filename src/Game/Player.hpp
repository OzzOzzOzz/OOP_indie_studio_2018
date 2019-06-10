/*
** EPITECH PROJECT, 2018
** File Name: Player.hpp
** File description:
** Rémi Bisson
*/
#ifndef OOP_INDIE_STUDIO_2018_PLAYER_HPP
#define OOP_INDIE_STUDIO_2018_PLAYER_HPP

#include <vector>
#include <iostream>
#include <irrlicht/irrlicht.h>
#include "../Graphics/eventreceiver.hpp"

#define PLAYER_SIZE 15.0f
#define SPEED 1.0f


#define K_UP_ID 0
#define K_DOWN_ID 1
#define K_RIGHT_ID 2
#define K_LEFT_ID 3
#define K_BOMB_ID 4

class Player {
public:
	Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y, bool j1orj2);
	~Player();

	int Move(int id, std::vector <Wall *> &map, std::vector<Bomb *> &bombs);
	int Collision(std::vector <Wall *> &map, irr::EKEY_CODE key);
	void bombHandling(std::vector <Bomb *> &bombs, irr::core::vector3df nodePosition, std::vector<Wall *> &map);

	irr::core::vector3df getPosition() {return _player1->getAbsolutePosition();}
    irr::scene::IAnimatedMesh *getMesh() {return _mesh;}
    irr::scene::IAnimatedMeshSceneNode *getNode() {return _player1;}
	MyEventReceiver *getEventReceiver() {return _receiver;}

private:
    irr::IrrlichtDevice *_window;
    irr::scene::IAnimatedMesh *_mesh;
	irr::scene::IAnimatedMeshSceneNode *_player1;
	std::vector<irr::EKEY_CODE> _keys;

	MyEventReceiver *_receiver;
};

#endif
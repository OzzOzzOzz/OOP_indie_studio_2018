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
#include "Map.hpp"

#define PLAYER_SIZE 15.0f
#define PLAYERSPEED 5.0f

#define K_UP_ID 0
#define K_DOWN_ID 1
#define K_RIGHT_ID 2
#define K_LEFT_ID 3
#define K_BOMB_ID 4

class Player {
public:
	Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, Map *map, int x, int y, bool j1orj2);
	~Player();

	int Move(int id);
	int Collision(irr::EKEY_CODE key);

	irr::core::vector3df getPosition() {return _player1->getAbsolutePosition();}
    irr::scene::IAnimatedMesh *getMesh() {return _mesh;}
    irr::scene::IAnimatedMeshSceneNode *getNode() {return _player1;}
	MyEventReceiver *getEventReceiver() {return _receiver;}
	int getBombNumber() {return _bombNumber;}
    irr::core::vector2di getTxtPos(){return _txtPos;}

private:

    irr::IrrlichtDevice *_window;
    irr::scene::IAnimatedMesh *_mesh;
	irr::scene::IAnimatedMeshSceneNode *_player1;
	std::vector<irr::EKEY_CODE> _keys;
	int _bombNumber;
    irr::core::vector2di _txtPos;

	Map *_map;

	int _range;
	MyEventReceiver *_receiver;
	irr::u32 _now;
	irr::u32 _then;
	irr::f32 _framedeltatime;
};

#endif
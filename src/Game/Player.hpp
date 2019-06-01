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

class Player {
public:
	Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y);
	~Player();
	void Move();
private:
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
    irr::scene::IAnimatedMesh *_mesh;
    irr::scene::IAnimatedMeshSceneNode *_player1;

};

#endif
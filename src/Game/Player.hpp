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
	std::vector<int> getPosition();
	void Move();
private:
	std::vector<int> _position;
    irr::scene::IMeshSceneNode* _gamer;
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
};

#endif
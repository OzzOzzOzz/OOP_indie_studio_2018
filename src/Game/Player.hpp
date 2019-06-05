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
	Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y, bool j1orj2, 	std::vector <Wall *> map);
	~Player();
	int Move(int id);
	int colision();
	irr::core::vector3df getPosition() {return _player1->getAbsolutePosition();}
    irr::scene::IAnimatedMesh *getMesh() {return _mesh;}
    irr::scene::IAnimatedMeshSceneNode *getNode() {return _player1;}
    irr::EKEY_CODE _previous_dir;
private:
    irr::IrrlichtDevice *_window;
    MyEventReceiver *_receiver;
    irr::scene::IAnimatedMesh *_mesh;
    irr::scene::IAnimatedMeshSceneNode *_player1;
    std::vector<irr::EKEY_CODE> _keys;
    std::vector <Wall *> _map;
};

#endif
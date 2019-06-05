/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>
#include <vector>
#include <cstdlib>
#include "Wall.hpp"
#include "Player.hpp"

class Game {
	public:
		Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int nbplayers, int nbai);
		~Game();
		int gameHandling(int whichGame);
		void createMap();
        void MovePlayer();
        int colision();
        Player *_player;
        Player *_player2;
        irr::EKEY_CODE _key;
	protected:
	private:
		irr::IrrlichtDevice *_window;
		irr::video::IVideoDriver *_video;
		irr::scene::ISceneManager *_sceneManager;
		std::vector <Wall *> _map;
		std::vector <Wall *> _floor;
		irr::scene::IMetaTriangleSelector *_metaselector;
		int _nbplayers;
		int _nbai;

};

#endif /* !GAME_HPP_ */

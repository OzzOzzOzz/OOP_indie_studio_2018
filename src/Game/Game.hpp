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

#define MAP_SIZE 21.0f
#define CUBE_SIZE 20.0f
#define WALL_PCT 70
#define VOID '0'
#define WALL '1'
#define BEDROCK '2'

class Game {
	public:
		Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int nbplayers, int nbai);
		~Game();
		int gameHandling(int whichGame);
		void createMap();
        void MovePlayer(std::vector <Wall *> map);
        std::vector<Wall *> getMap() {return _map;}
        Player *_player;
        Player *_player2;
        irr::EKEY_CODE _key;
	protected:
	private:
        std::vector<std::string> gen_sub_map();
		void gen_txt_map();
	    bool is_spawn_area(int ,int);

		irr::IrrlichtDevice *_window;
		irr::video::IVideoDriver *_video;
		irr::scene::ISceneManager *_sceneManager;
		std::vector <Wall *> _map;
		std::vector <Wall *> _floor;
		std::vector<std::string> _txt_map;
		irr::scene::IMetaTriangleSelector *_metaselector;
		int _nbplayers;
		int _nbai;

};

#endif /* !GAME_HPP_ */

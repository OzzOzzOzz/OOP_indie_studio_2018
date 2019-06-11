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
#include "Bomb.hpp"
#include "Player.hpp"
#include "../Menu/GameMenu.hpp"

#define MAP_SIZE 21.0f
#define CUBE_SIZE 20.0f
#define WALL_PCT 70
#define VOID '0'
#define WALL '1'
#define BEDROCK '2'

class Game {
public:
	Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int nbplayers, int nbai, int musicVolume, int soundEffectsVolume);
	~Game();

	void gameLoop();
	int gameHandling();

	void createMap();
	std::vector<std::string> gen_sub_map();
	void gen_txt_map();
	bool is_spawn_area(int ,int);

	void MovePlayer(std::vector <Wall *> &map, std::vector<Bomb *> &bombs, std::vector<std::string> &_txt_map);

	std::vector<std::string> getFilesfromFolder(const char *folderName);
	int saveGame();

	std::vector<Wall *> getMap() {return _map;}
	MyEventReceiver *getEventReceiver() {return _player->getEventReceiver();}

	void setPlayerNumber(int player) {_playersNumber = player;}
	void setAINumber(int ai) {_botsNumber = ai;}
private:

	irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;
	irr::video::ITexture *_background;
	irr::scene::IMetaTriangleSelector *_metaselector;
	irr::EKEY_CODE _key;

	std::vector <Wall *> _map;
	std::vector <Wall *> _floor;
	std::vector <Bomb *> _bombs;

	GameMenu *_gameMenu;

	sf::SoundBuffer _bombBuffer;
	sf::Sound _bombSound;
	sf::Music _gameMusic;

	Player *_player2;
	Player *_player;

	int _playersNumber;
	int _botsNumber;
	std::vector<std::string> _txtMap;
};

#endif

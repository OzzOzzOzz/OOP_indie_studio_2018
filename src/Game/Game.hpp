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
#include "Map.hpp"
#include "../Menu/GameMenu.hpp"
#include "Ai.hpp"

#define CODE_ERR_EXIT 84

#define MAP_SIZE 21.0f
#define CUBE_SIZE 20.0f
#define WALL_PCT 70
#define VOID '0'
#define WALL '1'
#define BEDROCK '2'

class Game {
public:
	Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int playerNumber, int aiNumber, int musicVolume, int soundEffectsVolume);
    Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int playersNumber, int aiNumber, int musicVolume, int soundEffectsVolume, const irr::core::vector2di &player1Pos, const irr::core::vector2di &player2Pos, std::vector<std::string> &txtMap);
	void gameConstructor(irr::IrrlichtDevice *window, int playerNumber, int aiNumber, int musicVolume, int soundEffectsVolume);
	~Game();

	void gameLoop();
	int gameHandling();

	void AIHandling();

	void MovePlayer();

	std::vector<std::string> getFilesfromFolder(const char *folderName);
	int saveGame();
	void displaySaveGameImage(std::string);
private:

	irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;
	irr::video::ITexture *_background;
	irr::video::ITexture *_savedGame;
	irr::scene::IMetaTriangleSelector *_metaselector;
	irr::EKEY_CODE _key;

    Map *_map;

	GameMenu *_gameMenu;

	sf::SoundBuffer _bombBuffer;
	sf::Sound _bombSound;
	sf::Music _gameMusic;

	Player *_player2;
	Player *_player;

	std::vector<AI *> _ai;

	int _playersNumber;
	int _botsNumber;
};

#endif

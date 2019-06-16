/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/
#include <dirent.h>
#include <fstream>
#include <chrono>
#include <chrono>
#include "Game.hpp"
#include "Wall.hpp"

Game::Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int playerNumber, int aiNumber, int musicVolume, int soundEffectsVolume)
{
	_map = new Map(window);
	gameConstructor(window, playerNumber, aiNumber, musicVolume, soundEffectsVolume);

	_player = new Player(_window, receiver, _map, 20, 20, false);
	if (playerNumber == 2)
		_player2 = new Player(_window, receiver, _map, 380, 380, true);
}

Game::Game(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int playerNumber, int aiNumber, int musicVolume, int soundEffectsVolume, const irr::core::vector2di &player1Pos, const irr::core::vector2di &player2Pos, std::vector<std::string> &txtMap)
{
	_map = new Map(window, txtMap);
	gameConstructor(window, playerNumber, aiNumber, musicVolume, soundEffectsVolume);

	_player = new Player(_window, receiver, _map, player1Pos.X, player1Pos.Y, false);
	if (playerNumber == 2)
		_player2 = new Player(_window, receiver, _map, player2Pos.X, player2Pos.Y, true);
}

void Game::gameConstructor(irr::IrrlichtDevice *window, int playerNumber, int aiNumber, int musicVolume, int soundEffectsVolume)
{
	int aiSpawnPosX = 380;
	int aiSpawnPosY = 20;

	_window = window;
	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();
	_background = _video->getTexture("assets/game/game_background.png");
	_sceneManager->addCameraSceneNode(0, irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE, (MAP_SIZE / 3) * CUBE_SIZE, (MAP_SIZE) * CUBE_SIZE), irr::core::vector3df((MAP_SIZE / 2) * CUBE_SIZE, (MAP_SIZE / 2) * CUBE_SIZE, 0));

	_gameMenu = new GameMenu(_window);

	for (int i = 0; i < aiNumber; i++) {
		if (i == 1) {
			aiSpawnPosX = 20;
			aiSpawnPosY = 380;
		} else if (i == 2) {
			aiSpawnPosX = 380;
			aiSpawnPosY = 380;
		}
		_ai.push_back(new AI(_window, _map, aiSpawnPosX, aiSpawnPosY));
	}

	if (!_bombBuffer.loadFromFile("assets/sounds/bomb_explosion.ogg")) {
		std::cerr << "Error while loading bomb_explosion.ogg" << std::endl;
		exit (CODE_ERR_EXIT);
	}
	_bombSound.setBuffer(_bombBuffer);
	_bombSound.setVolume(soundEffectsVolume);

	if (!_gameMusic.openFromFile("assets/sounds/game_music.ogg")) {
		std::cerr << "Error while loading game_music.ogg" << std::endl;
		exit (CODE_ERR_EXIT);
	}
	_gameMusic.setLoop(true);
	_gameMusic.setVolume(musicVolume);
	//_gameMusic.play();

	_botsNumber = aiNumber;
	_playersNumber = playerNumber;
}

Game::~Game()
{
	delete(_gameMenu);
	delete(_player);
	if (_playersNumber == 2)
		delete(_player2);
	for (int i = 0; i < _botsNumber; i++)
		delete(_ai[i]);
}

void Game::playerBombCollision(const std::vector<irr::core::vector2di>& hits)
{
    std::vector<irr::core::vector2di> playersPos;

    playersPos.reserve(_botsNumber + _playersNumber);
    for (int i = 0; i < _botsNumber; i++)
        playersPos.emplace_back(_ai[i]->getTxtPos());
    playersPos.emplace_back(_player->getTxtPos());
    if (_playersNumber == 2)
        playersPos.emplace_back(_player2->getTxtPos());

    for (int i_hits = 0; i_hits < hits.size(); i_hits++) {
        for (int i_player = 0; i_player < hits.size(); i_player++) {
            if (hits[i_hits].X == playersPos[i_player].X && hits[i_hits].Y == playersPos[i_player].Y)
                std::cout << "PLAYER " << i_player << "IS DEAD" << std::endl;
        }
    }
}

void Game::gameLoop()
{
    int ret = 0;

	while (_window->run()) {
		if (_player->getEventReceiver()->IsKeyDown(irr::KEY_ESCAPE)) {
			ret = _gameMenu->gameMenuHandling();
			if (ret == 2)
				saveGame();
		}
		playerBombCollision(_map->update());
		gameHandling();
		MovePlayer();
		AIHandling();
	}
	_window->drop();
}

void Game::AIHandling()
{
	for (int i = 0; i < _botsNumber; i++)
		_ai[i]->checkForBombs();
}


int Game::gameHandling()
{
    _video->beginScene(true, true, 0);
    _video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
    _sceneManager->drawAll();
    _video->endScene();
    return (2);
}

std::vector<std::string> Game::getFilesfromFolder(const char *folderName)
{
	DIR *dir = opendir(folderName);
	struct dirent *ent;
	std::vector<std::string> files;

	if (!dir) {
		std::cerr << "Could not open saves directory" << std::endl;
		exit (CODE_ERR_EXIT);
	}
	ent = readdir(dir);
	while (ent != nullptr) {
		if (ent->d_name[0] != '.' && strlen(ent->d_name) == 5)
			files.emplace_back(ent->d_name);
		ent = readdir(dir);
	}
	closedir(dir);
	return (files);
}

int Game::saveGame()
{
	std::vector<std::string> files = getFilesfromFolder("./saves");
	std::string newFileName = "save1";
	std::ofstream file;
	int i = 0;
	std::string gameSave = "assets/menu/game_saved_popup";

	while (i <= files.size())
		i++;
	if (i <= 5) {
		newFileName = "save" + std::to_string(i);
		gameSave = gameSave + std::to_string(i) + ".png";
	} else
		gameSave = gameSave + "1.png";
	file.open("./saves/" + newFileName);
	for (int i = 0; i < _map->getTxtMap().size(); i++)
		file << _map->getTxtMap().at(i) << std::endl;

	file << "P "  << _player->getBombNumber() << " " << _player->getPosition().X << " " << _player->getPosition().Y << std::endl;
	if (_playersNumber == 2)
		file << "P "  << _player2->getBombNumber() << " " << _player2->getPosition().X << " " << _player2->getPosition().Y << std::endl;

	for (int i = 0; i < _botsNumber; i++)
		file << "A " << "1" << " " << "0" << " " << "0" << std::endl;
	file.close();
	displaySaveGameImage(gameSave);
	return (0);
}

void Game::displaySaveGameImage(std::string fileName)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;

	_savedGame = _video->getTexture(fileName.c_str());
	while (1) {
		end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		if (elapsed.count() >= 3000.0)
			break;
		_video->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
		_video->draw2DImage(_savedGame, irr::core::position2d<irr::s32>(0, 0));
		_video->endScene();
	}
}

void Game::MovePlayer()
{
    _player->Move(1);
    if (_playersNumber == 2)
        _player2->Move(2);
}

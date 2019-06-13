/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphics.cpp
*/
#include <sstream>
#include <fstream>
#include "Graphics.hpp"

Graphics::Graphics()
{
	_receiver = new MyEventReceiver();
	_window = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, _receiver);
	_menu = new Menu(_window);
	_window->setWindowCaption(L"Indie Studio");
}

Graphics::~Graphics()
{
	_window->closeDevice();
	delete(_game);
	delete(_menu);
}

void Graphics::setGame()
{
	_game = new Game(_window, _receiver, _menu->getPlayers(), _menu->getIA(), _menu->getMusicVolume(), _menu->getSoundEffectVolume());
}

std::vector<std::string> Graphics::getFileContent(std::string fileName)
{
	std::vector<std::string> fileContent;
	std::ifstream file(fileName);
	std::string line;

	if (!file.is_open())
		return (fileContent);
	while (getline(file, line)) {
		fileContent.emplace_back(line);
	}
	file.close();
	return (fileContent);
}

irr::core::vector2di getPlayerPosition(const std::string line)
{
	std::istringstream tokenStream(line);
	std::vector<std::string> tokens;
	irr::core::vector2di pos;
	std::string token;

	while (std::getline(tokenStream, token, ' '))
		tokens.push_back(token);
	pos.X = std::atoi(tokens[2].c_str());
	pos.Y = std::atoi(tokens[3].c_str());
	return (pos);
}

void Graphics::loadGame(int SaveFileNumber)
{
	std::vector<std::string> fileContent = getFileContent("./saves/save" + std::to_string(SaveFileNumber));
	std::vector<std::string> map;
	irr::core::vector2di player1Pos;
	irr::core::vector2di player2Pos;
	int i = 0;
	int playerNumber = 0;
	int aiNumber = 0;

	for (i; i < fileContent.size(); i++) {
		if (fileContent[i][0] == 'P') {
			if (playerNumber == 0)
				player1Pos = getPlayerPosition(fileContent[i]);
			else
				player2Pos = getPlayerPosition(fileContent[i]);
			playerNumber += 1;
		} else if (fileContent[i][0] == 'A') {
			aiNumber += 1;
		} else {
			map.push_back(fileContent[i]);
		}
	}
	_game = new Game(_window, _receiver, map, playerNumber, aiNumber, player1Pos, player2Pos, _menu->getMusicVolume(), _menu->getSoundEffectVolume());
	_menu->stopMusic();
}
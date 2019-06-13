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
	_players = 1;
	_bots = 1;
	_firstButtonActivated = false;
	_secondButtonActivated = false;
	_thirdButtonActivated = false;
}

Graphics::~Graphics()
{
	delete(_game);
	delete(_menu);
}

void Graphics::buttonsInitialize()
{
	int size = 580;

	_startButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(735, 910, 735 + 500, 910 + 120), nullptr, 0, L"START");
	for (int i = 0; i < 3; i++, size += 450)
		_plusButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(size, 410, size + 250, 410 + 220), nullptr, 0, L"PLUS"));
}

void Graphics::gameSettings()
{
	int ret = 0;

	_video = _window->getVideoDriver();
	_sceneManager = _window->getSceneManager();

	_background = _video->getTexture("assets/menu/choose_players_menu.png");
	_firstBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_secondBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_thirdBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));

	buttonsInitialize();
	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_firstBox, irr::core::position2d<irr::s32>(500, 325), irr::core::rect<irr::s32>(0, 0, 800, 600), 0, irr::video::SColor(255, 255, 255, 255), true);
		_video->draw2DImage(_secondBox, irr::core::position2d<irr::s32>(950, 325), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		_video->draw2DImage(_thirdBox, irr::core::position2d<irr::s32>(1400, 325), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		_sceneManager->drawAll();
		ret = buttonsHandling();
		if (ret == 1) {
			_menu->stopMusic();
			_game = new Game(_window, _receiver, _players, _bots, _menu->getMusicVolume(), _menu->getSoundEffectVolume());
			return;
		}
		_video->endScene();
	}
}

int Graphics::buttonsHandling()
{
	if (_startButton->isPressed()) {
		_menu->playClickSound();
		return (1);
	}
	if (_plusButtons[0]->isPressed()) {
		_menu->playClickSound();
		if (!_firstButtonActivated) {
			_players++;
			_bots--;
			_firstBox = _video->getTexture("assets/menu/buttons/player2_rectangle.png");
			_firstButtonActivated = true;
			if (_secondButtonActivated)
				_secondBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
			if (_thirdButtonActivated)
				_thirdBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
		} else {
			_players--;
			_bots++;
			_firstBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
			_firstButtonActivated = false;
			if (_secondButtonActivated)
				_secondBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
			if (_thirdButtonActivated)
				_thirdBox = _video->getTexture("assets/menu/buttons/AI3_rectangle.png");
		}
	}

	if (_plusButtons[1]->isPressed()) {
		_menu->playClickSound();
		if (!_secondButtonActivated) {
			if (_bots == 0)
				_secondBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
			if (_bots == 1)
				_secondBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
			_bots++;
			_secondButtonActivated = true;
		} else {
			if (_thirdButtonActivated) {
				if (_bots == 0)
					_secondBox = _video->getTexture("assets/menu/buttons/AI1_rectangle.png");
				if (_bots == 1)
					_secondBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
				_thirdBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
				_thirdButtonActivated = false;
			} else {
				_secondBox = _video->getTexture(
						"assets/menu/buttons/add_player_plus_sign.png");
				_secondButtonActivated = false;
			}
			_bots--;
		}
	}

	if (_plusButtons[2]->isPressed()) {
		_menu->playClickSound();
		if (!_thirdButtonActivated) {
			if (_bots == 1)
				_thirdBox = _video->getTexture("assets/menu/buttons/AI2_rectangle.png");
			if (_bots == 2)
				_thirdBox = _video->getTexture("assets/menu/buttons/AI3_rectangle.png");
			_bots++;
			_thirdButtonActivated = true;
		} else {
			_thirdBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
			_bots--;
			_thirdButtonActivated = false;
		}
	}

	_startButton->setPressed(false);
	for (int i = 0; i < 3; i++)
		_plusButtons[i]->setPressed(false);
	return (0);
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
	std::vector<std::string> tokens;
	irr::core::vector2di pos;
	std::string token;
	std::istringstream tokenStream(line);

	while (std::getline(tokenStream, token, ' '))
		tokens.push_back(token);
	pos.X = std::atoi(tokens[2].c_str());
	pos.Y = std::atoi(tokens[3].c_str());
	std::cerr << pos.X << " " << pos.Y << std::endl;
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
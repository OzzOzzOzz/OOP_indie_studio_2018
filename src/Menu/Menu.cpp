/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <string>

Menu::Menu(irr::IrrlichtDevice *window)
{
    _window = window;
    _video = _window->getVideoDriver();
    _sceneManager = _window->getSceneManager();

    _background = _video->getTexture("assets/menu/main_menu.png");
    _settingsBackground = _video->getTexture("assets/menu/settings_menu.png");
    _musicVolumeBackground = _video->getTexture("assets/menu/volume_bar_100.png");
    _soundEffectBackground = _video->getTexture("assets/menu/volume_bar_100.png");

    _video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));

    initializeButtons();
    if (!_clickBuffer.loadFromFile("assets/sounds/mouse_click.ogg")) {
		std::cerr << "Error while loading mouse_click.ogg" << std::endl;
		exit (84);
    }
    if (!_mainMenuMusic.openFromFile("assets/sounds/main_menu_music.ogg")) {
		std::cerr << "Error while loading main_menu_music.ogg" << std::endl;
		exit (84);
    }
    _mainMenuMusic.setLoop(true);
    _mainMenuMusic.play();
    _clickSound.setBuffer(_clickBuffer);
}

Menu::~Menu()
{
}

void Menu::initializeButtons()
{
	int size = 350;

	for (int i = 0; i < 4; i++, size += 170)
		_mainButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(330, size, 330 + 500, size + 120), nullptr, 0, L""));
	_settingsButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(75, 70, 75 + 220, 70 + 120), nullptr, 0, L""));
	_musicLessButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(500, 440, 500 + 180, 440 + 50), nullptr, 0, L"");
	_musicPlusButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1330, 400, 1330 + 130, 400 + 120), nullptr, 0, L"");
	_soundLessButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(500, 755, 500 + 180, 755 + 50), nullptr, 0, L"");
	_soundPlusButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1330, 715, 1330 + 130, 715 + 120), nullptr, 0, L"");
}

void Menu::menuHandling()
{
	int ret = 0;

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_sceneManager->drawAll();
		ret = buttonHandling();
		if (ret == 1)
			return;
		_video->endScene();
	}
}

int Menu::buttonHandling()
{
	if (_mainButtons[0]->isPressed()) {
		_clickSound.play();
		_mainMenuMusic.setAttenuation(10);
		_mainMenuMusic.stop();
		return (1);
	}
	if (_mainButtons[1]->isPressed()) {
		_clickSound.play();
		std::cout << "Load Game pressed" << std::endl;
	}
	if (_mainButtons[2]->isPressed()) {
		_clickSound.play();
		settings();
	}
	if (_mainButtons[3]->isPressed()) {
		_clickSound.play();
		exit (0);
	}
	return (0);
}

void Menu::settings()
{
	int ret = 0;

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_settingsBackground, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_musicVolumeBackground, irr::core::position2d<irr::s32>(706, 393));
		_video->draw2DImage(_soundEffectBackground, irr::core::position2d<irr::s32>(706, 725));
		_sceneManager->drawAll();
		ret = settingsButtonsHandling();
		if (ret == 1)
			return;
		_video->endScene();
	}
}

int Menu::settingsButtonsHandling()
{
	static int music = 100;
	static int soundEffect = 100;
	std::string file;

	if (_settingsButtons[0]->isPressed())
		return 1;
	if (_musicLessButton->isPressed() && music >= 25) {
		music -= 25;
		file = "assets/menu/volume_bar"+std::to_string(music)+".png";
		_musicVolumeBackground = _video->getTexture(file.c_str());
	}
	if (_musicPlusButton->isPressed() && music <= 75) {
		music += 25;
		file = "assets/menu/volume_bar"+std::to_string(music)+".png";
		_musicVolumeBackground = _video->getTexture(file.c_str());
	}
	if (_soundLessButton->isPressed() && soundEffect >= 25) {
		soundEffect -= 25;
		file = "assets/menu/volume_bar_"+std::to_string(soundEffect)+".png";
		_soundEffectBackground = _video->getTexture(file.c_str());
	}
	if (_soundPlusButton->isPressed() && soundEffect <= 75) {
		soundEffect += 25;
		file = "assets/menu/volume_bar_"+std::to_string(soundEffect)+".png";
		_soundEffectBackground = _video->getTexture(file.c_str());
	}
	return 0;
}
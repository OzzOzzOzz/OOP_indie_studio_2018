/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *window)
{
    std::string file;

    _window = window;
    _video = _window->getVideoDriver();
    _sceneManager = _window->getSceneManager();
    _background = _video->getTexture("assets/menu/main_menu.png");
    _loadGamesBackground = _video->getTexture("assets/menu/empty_load_game_menu.png");
    _settingsBackground = _video->getTexture("assets/menu/settings_menu.png");
    _musicVolumeBackground = _video->getTexture("assets/menu/volume_bar_100.png");
    _soundEffectBackground = _video->getTexture("assets/menu/volume_bar_100.png");
    for (int i = 0; i < getFilesfromFolder("./saves").size(); i++) {
    	file = "assets/menu/buttons/save"+std::to_string(i+1)+"_button.png";
		_savedGames.push_back(_video->getTexture(file.c_str()));
    }
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

	_players = 1;
	_bots = 1;
	_firstButtonActivated = false;
	_secondButtonActivated = false;
	_thirdButtonActivated = false;
}

Menu::~Menu()
{
}

std::vector<std::string> Menu::getFilesfromFolder(const char *folderName)
{
	DIR *dir = opendir(folderName);
	struct dirent *ent;
	std::vector<std::string> files;

	if (!dir) {
		std::cerr << "Could not open saves directory" << std::endl;
		exit (84);
	}
	ent = readdir(dir);
	while (ent != nullptr) {
		if (ent->d_name[0] != '.')
			files.emplace_back(ent->d_name);
		ent = readdir(dir);
	}
	closedir(dir);
	return (files);
}

void Menu::initializeButtons()
{
	int size = 350;

	for (int i = 0; i < 4; i++, size += 170)
		_mainButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(330, size, 330 + 500, size + 120), nullptr, 0, L""));
	_loadGamesButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(70, 900, 70 + 250, 900 + 120), nullptr, 0, L""));
}

int Menu::menuHandling()
{
	int ret = 0;

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_background, irr::core::position2d<irr::s32>(0, 0));
		_sceneManager->drawAll();
		ret = buttonHandling();
		if (ret == -42) {
			if (gameSettings() == -42)
				return -42;
		}
		else if (ret != 0)
			return (ret);
		_video->endScene();
	}
	return (-1);
}

int Menu::buttonHandling()
{
	if (_mainButtons[0]->isPressed()) {
		_mainButtons[0]->setPressed(false);
		_clickSound.play();
		return (-42);
	}
	if (_mainButtons[1]->isPressed()) {
		_mainButtons[1]->setPressed(false);
		_clickSound.play();
		return (loadGames());
	}
	if (_mainButtons[2]->isPressed()) {
		_mainButtons[2]->setPressed(false);
		_clickSound.play();
		settings();
	}
	if (_mainButtons[3]->isPressed()) {
		_mainButtons[3]->setPressed(false);
		_clickSound.play();
		exit(0);
	}
	return (0);
}

int Menu::loadGames()
{
	int game = 0;
	int height = 350;
	int size = 400;
	std::vector<std::string> saveFiles = getFilesfromFolder("./saves");

	for (int i = 0; i < saveFiles.size(); i++, size += 170)
		_loadGamesButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1000, size, 1000 + 450, size + 120), nullptr, 0, L""));
	_settingsButtonExit = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(75, 70, 75 + 220, 70 + 120), nullptr, 0, L"");

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_loadGamesBackground, irr::core::position2d<irr::s32>(0, 0));
		for (std::size_t i = 0; i < _savedGames.size(); i++, height += 170)
			_video->draw2DImage(_savedGames[i], irr::core::position2d<irr::s32>(1000, height), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		height = 400;
		_sceneManager->drawAll();
		game = loadGamesButtonsHandling();
		if (game != 0)
			return (game);
		_video->endScene();
	}
	return (0);
}

int Menu::loadGamesButtonsHandling()
{
	if (_loadGamesButtons[0]->isPressed()) {
		_loadGamesButtons[0]->setPressed(false);
		return -1;
	}
	for (std::size_t i = 0; i < _loadGamesButtons.size(); i++)
		if (_loadGamesButtons[i]->isPressed()) {
			_loadGamesButtons[i]->setPressed(false);
			_clickSound.play();
			return (i);
		}
	return (0);
}

void Menu::settings()
{
	int ret = 0;

	_musicLessButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(500, 440, 500 + 180, 440 + 50), nullptr, 0, L"");
	_musicPlusButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1330, 400, 1330 + 130, 400 + 120), nullptr, 0, L"");
	_soundLessButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(500, 755, 500 + 180, 755 + 50), nullptr, 0, L"");
	_soundPlusButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(1330, 715, 1330 + 130, 715 + 120), nullptr, 0, L"");

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_settingsBackground, irr::core::position2d<irr::s32>(0, 0));
		if (_soundEffectVolume != 0)
			_video->draw2DImage(_soundEffectBackground, irr::core::position2d<irr::s32>(706, 725), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		if (_musicVolume != 0)
			_video->draw2DImage(_musicVolumeBackground, irr::core::position2d<irr::s32>(706, 393), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
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

	if (_settingsButtonExit->isPressed()) {
		_clickSound.play();
		_settingsButtonExit->setPressed(false);
		_musicVolume = music;
		_soundEffectVolume = soundEffect;
		return (1);
	}
	if (_musicLessButton->isPressed() && music >= 25) {
		_clickSound.play();
		music -= 25;
		if (music != 0) {
			file = "assets/menu/volume_bar_" + std::to_string(music) + ".png";
			_musicVolumeBackground = _video->getTexture(file.c_str());
		}
	}
	if (_musicPlusButton->isPressed() && music <= 75) {
		_clickSound.play();
		music += 25;
		file = "assets/menu/volume_bar_" + std::to_string(music) + ".png";
		_musicVolumeBackground = _video->getTexture(file.c_str());
	}
	if (_soundLessButton->isPressed() && soundEffect >= 25) {
		_clickSound.play();
		soundEffect -= 25;
		if (soundEffect != 0) {
			file = "assets/menu/volume_bar_" + std::to_string(soundEffect) + ".png";
			_soundEffectBackground = _video->getTexture(file.c_str());
		}
	}
	if (_soundPlusButton->isPressed() && soundEffect <= 75) {
		_clickSound.play();
		soundEffect += 25;
		file = "assets/menu/volume_bar_" + std::to_string(soundEffect) + ".png";
		_soundEffectBackground = _video->getTexture(file.c_str());
	}
	_mainMenuMusic.setVolume(music);
	_clickSound.setVolume(soundEffect);
	_musicLessButton->setPressed(false);
	_musicPlusButton->setPressed(false);
	_soundLessButton->setPressed(false);
	_soundPlusButton->setPressed(false);
	_musicVolume = music;
	_soundEffectVolume = soundEffect;

	return (0);
}

void Menu::stopMusic()
{
	_mainMenuMusic.stop();
}

void Menu::playClickSound()
{
	_clickSound.play();
}

int Menu::gameSettings()
{
	int ret = 0;
	int size = 580;

	_gamesSettingsBackground = _video->getTexture("assets/menu/choose_players_menu.png");
	_firstBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_secondBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_thirdBox = _video->getTexture("assets/menu/buttons/add_player_plus_sign.png");
	_returnArrow = _video->getTexture("assets/menu/buttons/back_arrow.png");
	_video->makeColorKeyTexture(_background, irr::core::position2d<irr::s32>(0, 0));

	_startButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(735, 910, 735 + 500, 910 + 120), nullptr, 0, L"START");
	for (int i = 0; i < 3; i++, size += 450)
		_plusButtons.push_back(_window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(size, 410, size + 250, 410 + 220), nullptr, 0, L"PLUS"));
	_returnButton = _window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(100, 50, 100 + 280, 50 + 130), nullptr, 0, L"BACK");

	while (_window->run()) {
		_video->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_window->getGUIEnvironment()->drawAll();
		_video->draw2DImage(_gamesSettingsBackground, irr::core::position2d<irr::s32>(0, 0));
		_video->draw2DImage(_firstBox, irr::core::position2d<irr::s32>(500, 325), irr::core::rect<irr::s32>(0, 0, 800, 600), 0, irr::video::SColor(255, 255, 255, 255), true);
		_video->draw2DImage(_secondBox, irr::core::position2d<irr::s32>(950, 325), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		_video->draw2DImage(_thirdBox, irr::core::position2d<irr::s32>(1400, 325), irr::core::rect<irr::s32>(0, 0, 700, 400), 0, irr::video::SColor(255, 255, 255, 255), true);
		_video->draw2DImage(_returnArrow, irr::core::position2d<irr::s32>(100, 50), irr::core::rect<irr::s32>(0, 0, 800, 600), 0, irr::video::SColor(255, 255, 255, 255), true);
		_sceneManager->drawAll();
		ret = gamesSettingsButtonsHandling();
		if (ret == 1) {
			stopMusic();
			return (-42);
		}
		if (ret == -1)
			return (0);
		_video->endScene();
	}
	return (0);
}

int Menu::gamesSettingsButtonsHandling()
{
	if (_startButton->isPressed()) {
		playClickSound();
		return (1);
	}
	if (_returnButton->isPressed())
		return (-1);

	if (_plusButtons[0]->isPressed()) {
		playClickSound();
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
		playClickSound();
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
		playClickSound();
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

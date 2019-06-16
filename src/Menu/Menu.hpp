/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <string>
#include "../Game/Game.hpp"

#define MENU_PLAY 0
#define MENU_LOAD 1
#define MENU_SETTINGS 2
#define MENU_EXIT 3
#define PLAY_CODE -42
#define CODE_ERR_EXIT 84

class Menu {
public:
	Menu(irr::IrrlichtDevice *);
	~Menu();

	std::vector<std::string> getFilesfromFolder(const char *folderName);

	int menuHandling();
	int buttonHandling();
    void initializeButtons();

    int loadGames();
    int loadGamesButtonsHandling();

    void settings();
    int settingsButtonsHandling();

	int gameSettings();
	int gamesSettingsButtonsHandling();

	int getPlayers() {return _players;}
	int getIA() {return _bots;}

    int getMusicVolume() {return _musicVolume;}
    int getSoundEffectVolume() {return _soundEffectVolume;}
    void playClickSound();
    void stopMusic();

private:
	irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;

	irr::video::ITexture *_background;
	irr::video::ITexture *_loadGamesBackground;
	std::vector<irr::video::ITexture *> _savedGames;
	irr::video::ITexture *_settingsBackground;
	irr::video::ITexture *_musicVolumeBackground;
	irr::video::ITexture *_soundEffectBackground;
	irr::video::ITexture *_gamesSettingsBackground;
	irr::video::ITexture *_returnArrow;
	irr::video::ITexture *_firstBox;
	irr::video::ITexture *_secondBox;
	irr::video::ITexture *_thirdBox;

	std::vector<irr::gui::IGUIButton *> _mainButtons;
	std::vector<irr::gui::IGUIButton *> _loadGamesButtons;
	irr::gui::IGUIButton *_settingsButtonExit;
	irr::gui::IGUIButton * _musicPlusButton;
	irr::gui::IGUIButton * _musicLessButton;
	irr::gui::IGUIButton *_soundPlusButton;
	irr::gui::IGUIButton * _soundLessButton;
	irr::gui::IGUIButton * _startButton;
	irr::gui::IGUIButton * _returnButton;
	std::vector<irr::gui::IGUIButton *> _plusButtons;

	sf::SoundBuffer _clickBuffer;
	sf::Sound _clickSound;
	sf::Music _mainMenuMusic;
	int _musicVolume;

	Game *_game;

	int _soundEffectVolume;
	int _players;
	int _bots;

	bool _firstButtonActivated;
	bool _secondButtonActivated;
	bool _thirdButtonActivated;
};

#endif

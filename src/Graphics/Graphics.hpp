/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphics.hpp
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include "Menu/Menu.hpp"
#include "Game/Game.hpp"

#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>
#include <vector>

class Graphics {
public:
	Graphics();
	~Graphics();

    Menu *getMenu() {return _menu;}
    Game *getGame() {return _game;}

	void gameSettings();
	int buttonsHandling();
	void buttonsInitialize();

	void loadGame(int SaveFileNumber);
	std::vector<std::string> getFileContent(std::string fileName);

private:
    irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;

	irr::video::ITexture *_background;
	irr::video::ITexture *_firstBox;
	irr::video::ITexture *_secondBox;
	irr::video::ITexture *_thirdBox;

	irr::gui::IGUIButton * _startButton;
	irr::gui::IGUIButton * _choosePlayerOrAI;
	std::vector<irr::gui::IGUIButton *> _plusButtons;

    Menu *_menu;
    Game *_game;
    MyEventReceiver *_receiver;

	int _players;
	int _bots;

	bool _firstButtonActivated;
	bool _secondButtonActivated;
	bool _thirdButtonActivated;
};

#endif

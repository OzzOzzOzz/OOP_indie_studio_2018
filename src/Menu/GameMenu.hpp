/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** GameMenu
*/

#ifndef GAMEMENU_HPP_
#define GAMEMENU_HPP_

#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

class GameMenu {
public:
	GameMenu(irr::IrrlichtDevice *);
	~GameMenu();

	int gameMenuHandling();
	void initializeButtons();
	int buttonsHandling();
	void howToPlay();
private:
	irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;
	irr::video::ITexture *_background;
	irr::video::ITexture *_htpBackground;
	std::vector<irr::gui::IGUIButton *> _mainButtons;
	irr::gui::IGUIButton *_howToPlayBack;
	sf::SoundBuffer _clickBuffer;
	sf::Sound _clickSound;
};

#endif

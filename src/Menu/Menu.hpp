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
#include <iostream>

#include <vector>
#include <algorithm>

class Menu {
public:
	Menu(irr::IrrlichtDevice *);
	~Menu();

    int menuHandling();
    int buttonHandling();
    void initializeButtons();

private:
	irr::IrrlichtDevice *_window;
    	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;
	irr::video::ITexture *_background;

	std::vector<irr::gui::IGUIButton *> _mainButtons;
	std::vector<irr::gui::IGUIButton *> _newGameButtons;
	std::vector<irr::gui::IGUIButton *> _loadGameButtons;
	std::vector<irr::gui::IGUIButton *> _settingsButtons;
};

#endif /* !MENU_HPP_ */

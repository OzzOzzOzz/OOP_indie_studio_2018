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

    void setGame();

	void loadGame(int SaveFileNumber);
	std::vector<std::string> getFileContent(std::string fileName);

private:
    irr::IrrlichtDevice *_window;
	irr::video::IVideoDriver *_video;
	irr::scene::ISceneManager *_sceneManager;

	Menu *_menu;
	Game *_game;
	MyEventReceiver *_receiver;
};

#endif

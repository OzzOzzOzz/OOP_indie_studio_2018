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
#include <iostream>

class GameMenu {
	public:
		GameMenu(irr::IrrlichtDevice *);
		~GameMenu();

		void gameMenuHandling();
	protected:

		irr::IrrlichtDevice *_window;
		irr::video::IVideoDriver *_video;
		irr::scene::ISceneManager *_sceneManager;
		irr::video::ITexture *_background;
	private:
};

#endif /* !GAMEMENU_HPP_ */

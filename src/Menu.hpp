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

class Menu {
	public:
		Menu(irr::IrrlichtDevice *);
		~Menu();

                int menuHandling();
	protected:
	private:
                irr::IrrlichtDevice *_window;
                irr::video::IVideoDriver *_video;
                irr::scene::ISceneManager *_sceneManager;
};

#endif /* !MENU_HPP_ */

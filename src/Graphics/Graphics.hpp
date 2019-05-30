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

                irr::IrrlichtDevice *getWindow() {return _window;}
                Menu *getMenu() {return _menu;}
		Game *getGame() {return _game;}
		bool getStatus() {return _inMenu;}

		void setStatus(bool newStatus) {_inMenu = newStatus;}
	protected:
	private:
                irr::IrrlichtDevice *_window;
                Menu *_menu;
                Game *_game;

                bool _inMenu;
};

#endif /* !GRAPHICS_HPP_ */

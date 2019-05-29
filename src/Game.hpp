/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>

class Game {
	public:
		Game(irr::IrrlichtDevice *window);
		~Game();

                int gameHandling(int whichGame);
	protected:
	private:
		irr::IrrlichtDevice *_window;
		irr::video::IVideoDriver *_video;
		irr::scene::ISceneManager *_sceneManager;
};

#endif /* !GAME_HPP_ */

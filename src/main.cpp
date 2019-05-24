/*
** EPITECH PROJECT, 2018
** File Name : main.cpp
** File description:
** Maïssa Nouhaud
*/

#include <iostream>
#include <irrlicht/irrlicht.h>
#include <irrlicht/IrrlichtDevice.h>

int main()
{
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, 0);
	irr::video::IVideoDriver* video = device->getVideoDriver();
	irr::scene::ISceneManager* sceneManager = device->getSceneManager();

	while(device->run()) {
		video->beginScene(true, true, irr::video::SColor(0,0,0,0));
		sceneManager->drawAll();
		video->endScene();
	}
	device->drop();
	return 0;
}
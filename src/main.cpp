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

	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL);
	irr::video::IVideoDriver* video = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();

	while(device->run() && device) {
		video->beginScene(true, true, irr::video::SColor(0,0,0,0));
		smgr->drawAll();
		video->endScene();
	}
}
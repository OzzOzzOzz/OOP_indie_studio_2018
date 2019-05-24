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
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<__U32_TYPE>(640, 480), 16, true, false, false, 0);

	if (!device)
		return -1;
	return 0;
}
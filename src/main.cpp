/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include "Graphics/Graphics.hpp"
#include "Game/Game.hpp"
#include <iostream>

int main()
{
	Graphics *bomberman = new Graphics();

	bomberman->getMenu()->menuHandling();
	bomberman->getGame()->createMap();
	bomberman->getGame()->gameLoop();
	return 0;
}

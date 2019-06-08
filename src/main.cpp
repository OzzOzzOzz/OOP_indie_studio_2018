/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/
#include <iostream>
#include "Graphics/Graphics.hpp"
#include "Game/Game.hpp"

int main()
{
	Graphics *bomberman = new Graphics();

	bomberman->getMenu()->menuHandling();
	bomberman->gameSettings();
	bomberman->getGame()->createMap();
	bomberman->getGame()->gameLoop();
	return 0;
}

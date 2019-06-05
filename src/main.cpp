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
	while (bomberman->getWindow()->run()) {
		bomberman->getGame()->gameHandling(0);
		bomberman->getGame()->MovePlayer(0);
	}
	bomberman->getWindow()->drop();
    return 0;
}
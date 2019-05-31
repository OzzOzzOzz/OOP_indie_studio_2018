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
	int game = 0;

	while(bomberman->getWindow()->run()) {
			game = bomberman->getMenu()->menuHandling();
			if (game == 1)
				break;
	}
	bomberman->getGame()->createMap();
	while(bomberman->getWindow()->run()) {
		game = bomberman->getGame()->gameHandling(0);
	}
	bomberman->getWindow()->drop();
    return 0;
}
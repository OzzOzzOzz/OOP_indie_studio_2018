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
		std::cout << game << std::endl;
		if (game == 1)
		    bomberman->getGame()->gameHandling(0);
	}
	bomberman->getWindow()->drop();
    return 0;
}
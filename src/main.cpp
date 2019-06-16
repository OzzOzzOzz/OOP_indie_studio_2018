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
    auto bomberman = new Graphics();
	int menu_return = bomberman->getMenu()->menuHandling();

	if (menu_return == -1)
		return (0);
	srand(time(nullptr));
	if (menu_return != PLAY_CODE) {
		bomberman->loadGame(menu_return);
	} else {
		bomberman->setGame();
	}
	bomberman->getGame()->gameLoop();
	delete(bomberman);
	return (0);
}

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
	int menu_return = bomberman->getMenu()->menuHandling();

	if (menu_return == -1) {
		return (84);
	}
	if (menu_return != -42) {
		bomberman->loadGame(menu_return);
	} else {
		bomberman->gameSettings();
		bomberman->getGame()->gen_txt_map();
	}
	bomberman->getGame()->createMap();
	bomberman->getGame()->gameLoop();
	return (0);
}

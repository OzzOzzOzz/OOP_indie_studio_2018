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
	int game;

	while(bomberman->getWindow()->run()) {
		game = bomberman->getMenu()->menuHandling();
	}
	bomberman->getWindow()->drop();
    return 0;
}
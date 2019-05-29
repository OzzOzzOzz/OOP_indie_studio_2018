/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include "Graphics.hpp"
#include "Game.hpp"
#include <iostream>

int main()
{
	Graphics *bomberman = new Graphics();
	int game;

        while(bomberman->getWindow()->run()) {
        	if (bomberman->getStatus()) {
			game = bomberman->getMenu()->menuHandling();
			bomberman->setStatus(false);
		}
        	else
        		bomberman->getGame()->gameHandling(game);
        }
        bomberman->getWindow()->drop();
        return 0;
}
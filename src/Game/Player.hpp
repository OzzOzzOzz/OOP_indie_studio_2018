/*
** EPITECH PROJECT, 2018
** File Name: Player.hpp
** File description:
** Rémi Bisson
*/
#ifndef OOP_INDIE_STUDIO_2018_PLAYER_HPP
#define OOP_INDIE_STUDIO_2018_PLAYER_HPP

#include <vector>
#include <iostream>

class Player {
public:
	Player(int x, int y);
	~Player();
	void setPosition(int x, int y);
	std::vector<int> getPosition();
private:
	std::vector<int> _position;
	std::string _sprite;
};

#endif
/*
** EPITECH PROJECT, 2018
** File Name: Wall.hpp
** File description:
** Rémi Bisson
*/
#ifndef OOP_INDIE_STUDIO_2018_WALL_HPP
#define OOP_INDIE_STUDIO_2018_WALL_HPP

#include <string>

class Wall {
public:
	Wall(bool isBreakable);
	~Wall();
private:
	bool _isBreakable;
	std::string _sprite;
	//irr::scene::IMeshSceneNode* _cube;
};

#endif
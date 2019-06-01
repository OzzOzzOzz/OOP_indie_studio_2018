/*
** EPITECH PROJECT, 2018
** File Name: Wall.hpp
** File description:
** Rémi Bisson
*/
#ifndef OOP_INDIE_STUDIO_2018_WALL_HPP
#define OOP_INDIE_STUDIO_2018_WALL_HPP

#include <string>
#include <irrlicht/irrlicht.h>

#define WALL_SIZE 20.0f

class Wall{
public:
	Wall(irr::IrrlichtDevice *window, bool isBreakable, irr::core::vector3df vector, std::string texture);
	~Wall();
private:
	bool _isBreakable;
	std::string _sprite;
	irr::scene::IMeshSceneNode* _cube;
};

#endif
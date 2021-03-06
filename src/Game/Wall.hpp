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

#define WALL_SIZE 20

class Wall{
public:
	Wall(irr::IrrlichtDevice *window, bool isBreakable, irr::core::vector3df pos, std::string texture);
	~Wall();

	irr::core::vector3df getPosition() {return _cube->getAbsolutePosition();}
    irr::scene::ISceneNode* getNode() {return _cube;}
	bool isWallBreakable() {return _isBreakable;}
    const irr::core::vector2di &getTxtPos() const {return _txtPos;}

private:
	irr::scene::ISceneNode* _cube;
    irr::core::vector2di _txtPos;
	bool _isBreakable;
};

#endif

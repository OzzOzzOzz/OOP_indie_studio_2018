/*
 EPITECH PROJECT, 2018
 File Name: Bomb.hpp
 File description:
 Mathieu Gery
*/
#ifndef OOP_INDIE_STUDIO_2018_BOMB_HPP
#define OOP_INDIE_STUDIO_2018_BOMB_HPP

#include <string>
#include "irrlicht/irrlicht.h"

#define BOMB_SIZE 25.0f

class Bomb {
    public:
        Bomb(irr::IrrlichtDevice *window, irr::core::vector3df vector, std::string _texture);
        ~Bomb();
        irr::scene::IAnimatedMeshSceneNode* getNode() {return _bomb;}
    private:
        irr::scene::IAnimatedMeshSceneNode *_bomb;
        irr::scene::IAnimatedMesh *_mesh;
};


#endif //OOP_INDIE_STUDIO_2018_BOMB_HPP

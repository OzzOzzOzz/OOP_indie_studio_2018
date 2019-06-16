/*
** EPITECH PROJECT, ${PROMO}
** OOP_indie_studio_2018
** File description:
** Created by mgery,
*/

#include <string>
#include "PowerUp.hpp"

PowerUp::PowerUp(irr::IrrlichtDevice *window, irr::core::vector3df pos, int id)
{
    std::string texture;

    if (id == 0)
        texture = "assets/game/powerup/speed.png";
    _powerup = window->getSceneManager()->addCubeSceneNode(15, 0, -1, pos, irr::core::vector3df(0, 0, 0), irr::core::vector3df(1, 1, 0.1));
    _powerup->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _powerup->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
    _powerup->setMaterialTexture(0, window->getVideoDriver()->getTexture(texture.c_str()));
    _id = id;
}

PowerUp::~PowerUp()
{

}

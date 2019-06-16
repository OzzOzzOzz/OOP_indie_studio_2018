/*
** EPITECH PROJECT, 2022
** OOP_indie_studio_2018
** File description:
** Created by mgery,
*/

#include <irrlicht/irrlicht.h>

#define POWERUP_SPEED 0;
#define  POWERUP_RANGE 1;
#define  POWERUP_BOMBS 2;

class PowerUp {
    public:
        PowerUp(irr::IrrlichtDevice *window, irr::core::vector3df vector, int range);
        ~PowerUp();
    private:
        irr::IrrlichtDevice *_window;
        irr::scene::ISceneNode *_powerup;
        int _id;
};
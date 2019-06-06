/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include <Graphics/Graphics.hpp>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y, bool j1orj2)
{
    _receiver = receiver;
    _window = window;
    _mesh = _window->getSceneManager()->getMesh("assets/game/ziggs.md3");
    _player1 = _window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _player1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _player1->setMD2Animation(irr::scene::EMAT_STAND);
    _player1->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/game/ziggs.png"));
    _player1->setFrameLoop(0, 96);
    _player1->setPosition(irr::core::vector3df(x, 0.0f, y));
    if (j1orj2 == true)
        _keys = {irr::KEY_KEY_Z,
             irr::KEY_KEY_S,
             irr::KEY_KEY_Q,
             irr::KEY_KEY_D};
    else
        _keys = {irr::KEY_UP,
                 irr::KEY_DOWN,
                 irr::KEY_LEFT,
                 irr::KEY_RIGHT};
}

Player::~Player()
{
}

int Player::Move(int id, std::vector <Wall *> map)
{
    static int i = 0;
    static int n = 0;

    irr::core::vector3df nodePosition = _player1->getPosition();
    if(_receiver->IsKeyDown(_keys[0])  && !colision(map) && _previous_dir != _keys[0]) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        _player1->setRotation(irr::core::vector3df(0.0f, 180.0f, 0.0f));
        nodePosition.Z += 2.0f;
        _player1->setPosition(nodePosition);
        _previous_dir = _keys[0];
        return (0);
    }
    else if(_receiver->IsKeyDown(_keys[1])  && !colision(map) && _previous_dir != _keys[1]) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.Z -= 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
        _player1->setPosition(nodePosition);
        _previous_dir = _keys[1];
        return (0);
    }
    if(_receiver->IsKeyDown(_keys[2])  && !colision(map) && _previous_dir != _keys[2]) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.X -= 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 90.0f, 0.0f));
        _player1->setPosition(nodePosition);
        _previous_dir = _keys[2];
        return (0);
    }
    else if(_receiver->IsKeyDown(_keys[3]) && !colision(map) && _previous_dir != _keys[3]) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.X += 2.0f;
        _player1->setRotation(irr::core::vector3df(0.0f, 270.0f, 0.0f));
        _player1->setPosition(nodePosition);
        _previous_dir = _keys[3];
        return (0);
    }
    if(_receiver->IsKeyDown(irr::KEY_ESCAPE))
        exit (0);
    _player1->setPosition(nodePosition);
    if (i == 1 && id == 1) {
        _player1->setFrameLoop(0, 95);
        i = 0;
    }
    if (n == 1 && id == 2) {
        _player1->setFrameLoop(0, 95);
        n = 0;
    }
    return (0);
}

int Player::colision(std::vector <Wall *> map)
{
    for (int i = 0; map.size() > i; i++) {
        if (_player1->getPosition().X < map[i]->getPosition().X + 20 &&
            _player1->getPosition().X  + 20 > map[i]->getPosition().X  &&
            _player1->getPosition().Z  < map[i]->getPosition().Z + 20 &&
            20 + _player1->getPosition().Z > map[i]->getPosition().Z) {
            std::cout << "colision" << std::endl;
            return 1;
        }
    }
    return 0;
}
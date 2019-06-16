/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include <utility>
#include <Graphics/Graphics.hpp>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, Map *map, int x, int y, bool player1) : _map(map)
{
    _txtPos.X = static_cast<int>(x / CUBE_SIZE);
    _txtPos.Y = static_cast<int>(y / CUBE_SIZE);
	_window = window;
	_receiver = receiver;
    _mesh = _window->getSceneManager()->getMesh("assets/game/ziggs.md3");
    _player1 = _window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _player1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _player1->setMD2Animation(irr::scene::EMAT_STAND);
    _player1->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/game/ziggs.png"));
    _player1->setFrameLoop(0, 96);
    _player1->setPosition(irr::core::vector3df(x, y, 0.0f));
    _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
    _player1->setScale(irr::core::vector3df(0.9f, 0.9f, 0.9f));
	_bombNumber = 1;

    if (player1)
        _keys = {irr::KEY_KEY_Z, irr::KEY_KEY_S, irr::KEY_KEY_D, irr::KEY_KEY_Q, irr::KEY_KEY_C};
    else
        _keys = {irr::KEY_UP, irr::KEY_DOWN, irr::KEY_RIGHT, irr::KEY_LEFT, irr::KEY_KEY_N};
    _range = 2;
}

Player::~Player()
{
}

int Player::Move(int id)
{
    static int i = 0;
    static int n = 0;
    irr::core::vector3df nodePosition = _player1->getPosition();

    if(_receiver->IsKeyDown(_keys[K_BOMB_ID]))
        _map->spawnBomb(nodePosition, _range);
    if(_receiver->IsKeyDown(_keys[K_UP_ID]) && Collision(_keys[K_UP_ID]) == 0) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
        nodePosition.Y += SPEED;
        _player1->setPosition(nodePosition);
        return (0);
    } else if (_receiver->IsKeyDown(_keys[K_DOWN_ID])  && Collision(_keys[K_DOWN_ID]) == 0) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.Y -= SPEED;
        _player1->setRotation(irr::core::vector3df(-90.0f, 180.0f, 0.0f));
        _player1->setPosition(nodePosition);
        return (0);
    }
    if(_receiver->IsKeyDown(_keys[K_RIGHT_ID]) && Collision(_keys[K_RIGHT_ID]) == 0) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.X -= SPEED;
        _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, 90.0f));
        _player1->setPosition(nodePosition);
        return (0);
    }
    else if(_receiver->IsKeyDown(_keys[K_LEFT_ID]) && Collision(_keys[K_LEFT_ID]) == 0) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        nodePosition.X += SPEED;
        _player1->setPosition(nodePosition);
        _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, -90.0f));
        return (0);
    }
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

int Player::Collision(irr::EKEY_CODE key)
{
    auto playerX = _player1->getPosition().X;
    auto playerY = _player1->getPosition().Y;
    for (auto const &wall : _map->getWalls()) {
        auto wallX = wall->getPosition().X;
        auto wallY = wall->getPosition().Y;
        if (key == _keys[K_UP_ID] && playerY + PLAYER_SIZE + SPEED>= wallY && playerY + SPEED<= wallY + PLAYER_SIZE && ((playerX + PLAYER_SIZE>= wallX && playerX <= wallX + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_LEFT_ID] && playerX + PLAYER_SIZE + SPEED>= wallX  && playerX + SPEED<= wallX + PLAYER_SIZE && ((playerY + PLAYER_SIZE>= wallY && playerY <= wallY + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_RIGHT_ID] && playerY <= wallY + PLAYER_SIZE && playerY + PLAYER_SIZE >= wallY && ((playerX  - SPEED + PLAYER_SIZE >= wallX && playerX - SPEED <= wallX + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_DOWN_ID] && playerX <= wallX + PLAYER_SIZE && playerX + PLAYER_SIZE>= wallX && ((playerY  - SPEED + PLAYER_SIZE >= wallY && playerY - SPEED <= wallY + PLAYER_SIZE)))
            return 1;
    }
    return 0;
}
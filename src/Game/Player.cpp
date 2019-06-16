/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include <utility>
#include <Graphics/Graphics.hpp>
#include "Player.hpp"
#include "PowerUp.hpp"

Player::Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, Map &map, int x, int y, bool player1) : _map(map)
{
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
	_then = window->getTimer()->getTime();

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
    _now = _window->getTimer()->getTime();
    const irr::f32 frameDeltaTime = (irr::f32)(_now - _then) / 100.f;
    _framedeltatime = frameDeltaTime;
    _then = _now;

    if(_receiver->IsKeyDown(_keys[K_BOMB_ID]))
        _map.spawnBomb(nodePosition, _range);
    if(_receiver->IsKeyDown(irr::KEY_KEY_X))
        new PowerUp(_window, irr::core::vector3df(100, 100, 0), 0);
    if(_receiver->IsKeyDown(_keys[K_UP_ID]) && Collision(_keys[K_UP_ID]) == 0) {
        if (i == 0 && id == 1) {
            _player1->setFrameLoop(96, 96 + 96);
            i = 1;
        } else if (n == 0 && id == 2) {
            _player1->setFrameLoop(96, 96 + 96);
            n = 1;
        }
        _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
        nodePosition.Y += PLAYERSPEED * frameDeltaTime;
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
        nodePosition.Y -= PLAYERSPEED* frameDeltaTime;
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
        nodePosition.X -= PLAYERSPEED * frameDeltaTime;
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
        nodePosition.X += PLAYERSPEED * frameDeltaTime;
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
    for (auto const &wall : _map.getWalls()) {
        if (key == _keys[K_UP_ID] && _player1->getPosition().Y + PLAYER_SIZE + PLAYERSPEED * _framedeltatime>= wall->getPosition().Y && _player1->getPosition().Y + PLAYERSPEED * _framedeltatime<= wall->getPosition().Y + PLAYER_SIZE && ((_player1->getPosition().X + PLAYER_SIZE>= wall->getPosition().X && _player1->getPosition().X <= wall->getPosition().X + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_LEFT_ID] && _player1->getPosition().X + PLAYER_SIZE + PLAYERSPEED * _framedeltatime>= wall->getPosition().X  && _player1->getPosition().X + PLAYERSPEED * _framedeltatime<= wall->getPosition().X + PLAYER_SIZE && ((_player1->getPosition().Y + PLAYER_SIZE>= wall->getPosition().Y && _player1->getPosition().Y <= wall->getPosition().Y + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_RIGHT_ID] && _player1->getPosition().Y <= wall->getPosition().Y + PLAYER_SIZE && _player1->getPosition().Y + PLAYER_SIZE >= wall->getPosition().Y && ((_player1->getPosition().X  - PLAYERSPEED * _framedeltatime + PLAYER_SIZE >= wall->getPosition().X && _player1->getPosition().X - PLAYERSPEED  * _framedeltatime<= wall->getPosition().X + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_DOWN_ID] && _player1->getPosition().X <= wall->getPosition().X + PLAYER_SIZE && _player1->getPosition().X + PLAYER_SIZE>= wall->getPosition().X && ((_player1->getPosition().Y  - PLAYERSPEED * _framedeltatime + PLAYER_SIZE >= wall->getPosition().Y && _player1->getPosition().Y - PLAYERSPEED  * _framedeltatime<= wall->getPosition().Y + PLAYER_SIZE)))
            return 1;
    }
    return 0;
}
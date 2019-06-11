/*
** EPITECH PROJECT, 2018
** File Name: Player.cpp
** File description:
** Rémi Bisson
*/
#include <utility>
#include <Graphics/Graphics.hpp>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, MyEventReceiver *receiver, int x, int y, bool player1)
{
    _receiver = receiver;
    _window = window;
    _mesh = _window->getSceneManager()->getMesh("assets/game/ziggs.md3");
    _player1 = _window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _player1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _player1->setMD2Animation(irr::scene::EMAT_STAND);
    _player1->setMaterialTexture(0, _window->getVideoDriver()->getTexture("assets/game/ziggs.png"));
    _player1->setFrameLoop(0, 96);
    _player1->setPosition(irr::core::vector3df(x, y, 0.0f));
    _player1->setRotation(irr::core::vector3df(90.0f, 0.0f, 0.0f));
    _player1->setScale(irr::core::vector3df(0.9f, 0.9f, 0.9f));
    if (player1)
        _keys = {irr::KEY_KEY_Z,
             irr::KEY_KEY_S,
             irr::KEY_KEY_D,
             irr::KEY_KEY_Q,
             irr::KEY_KEY_C};
    else
        _keys = {irr::KEY_UP,
                 irr::KEY_DOWN,
                 irr::KEY_RIGHT,
                 irr::KEY_LEFT,
                 irr::KEY_KEY_N};
}

Player::~Player()
{
}

int Player::Move(int id, std::vector <Wall *> &map, std::vector <Bomb *> &bombs, std::vector<std::string> _txtMap)
{
    static int i = 0;
    static int n = 0;
    irr::core::vector3df nodePosition = _player1->getPosition();

    if(_receiver->IsKeyDown(_keys[K_BOMB_ID]))
    	bombHandling(bombs, nodePosition, map, _txtMap);
    if(_receiver->IsKeyDown(_keys[K_UP_ID]) && Collision(map, _keys[K_UP_ID]) == 0) {
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
    }
    else if(_receiver->IsKeyDown(_keys[K_DOWN_ID])  && Collision(map, _keys[K_DOWN_ID]) == 0) {
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
    if(_receiver->IsKeyDown(_keys[K_RIGHT_ID]) && Collision(map, _keys[K_RIGHT_ID]) == 0) {
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
    else if(_receiver->IsKeyDown(_keys[K_LEFT_ID]) && Collision(map, _keys[K_LEFT_ID]) == 0) {
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

int Player::Collision(std::vector<Wall *> &map, irr::EKEY_CODE key)
{
    for (auto const &map : map) {
        if (key == _keys[K_UP_ID] && _player1->getPosition().Y + PLAYER_SIZE + SPEED>= map->getPosition().Y && _player1->getPosition().Y + SPEED<= map->getPosition().Y + PLAYER_SIZE && ((_player1->getPosition().X + PLAYER_SIZE>= map->getPosition().X && _player1->getPosition().X <= map->getPosition().X + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_LEFT_ID] && _player1->getPosition().X + PLAYER_SIZE + SPEED>= map->getPosition().X  && _player1->getPosition().X + SPEED<= map->getPosition().X + PLAYER_SIZE && ((_player1->getPosition().Y + PLAYER_SIZE>= map->getPosition().Y && _player1->getPosition().Y <= map->getPosition().Y + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_RIGHT_ID] && _player1->getPosition().Y <= map->getPosition().Y + PLAYER_SIZE && _player1->getPosition().Y + PLAYER_SIZE >= map->getPosition().Y && ((_player1->getPosition().X  - SPEED + PLAYER_SIZE >= map->getPosition().X && _player1->getPosition().X - SPEED <= map->getPosition().X + PLAYER_SIZE)))
            return 1;
        else if (key == _keys[K_DOWN_ID] && _player1->getPosition().X <= map->getPosition().X + PLAYER_SIZE && _player1->getPosition().X + PLAYER_SIZE>= map->getPosition().X && ((_player1->getPosition().Y  - SPEED + PLAYER_SIZE >= map->getPosition().Y && _player1->getPosition().Y - SPEED <= map->getPosition().Y + PLAYER_SIZE)))
            return 1;
    }
    return 0;
}

void Player::bombHandling(std::vector <Bomb *> &bombs, irr::core::vector3df nodePosition, std::vector <Wall *> &map, std::vector<std::string> &_txtMap)
{

	bombs.push_back(new Bomb(_window, irr::core::vector3df(
	    static_cast<int>(static_cast<int>(nodePosition.X) / CUBE_SIZE) * CUBE_SIZE,
	    static_cast<int>(static_cast<int>(nodePosition.Y) / CUBE_SIZE) * CUBE_SIZE,
	    0.0f), "assets/game/bomb.png"));

	for (int i = 0; i < map.size(); i++) {
		if ((nodePosition.X - CUBE_SIZE <= map[i]->getPosition().X && map[i]->getPosition().X <= nodePosition.X + CUBE_SIZE)
		&& (nodePosition.Y - CUBE_SIZE <= map[i]->getPosition().Y && map[i]->getPosition().Y <= nodePosition.Y + CUBE_SIZE)
		&& map[i]->isWallBreakable()) {
//			removeBombsAround(map[i]->getPosition(), map);
            _txtMap[map[i]->getTxtPos().X][map[i]->getTxtPos().Y] = VOID;
			map[i]->getNode()->remove();
			map.erase(map.begin() + i);
		}
	}
//	std::cout << "EXPLODE :" << std::endl;
//    for(int i = 0; i < MAP_SIZE; i++) {
//        std::cout << _txtMap[i] << std::endl;
//    }
//	removing the bombs when they explode but have to implement a timer first
//	bombs[0]->getNode()->remove();
//	bombs.erase(bombs.begin() + 0);
}

void Player::removeBombsAround(irr::core::vector3df nodePosition, std::vector<Wall *> &map)
{
	for (int i = 0; i < map.size(); i++) {
		if (map[i]->getPosition().X == nodePosition.X + CUBE_SIZE)
			std::cout << "HEY" << std::endl;
	}
}

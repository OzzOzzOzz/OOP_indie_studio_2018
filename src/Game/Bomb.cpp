/*
 EPITECH PROJECT, 2018
 File Name: Bomb.cpp
 File description:
Mathieu Gery
*/

#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice *window, Map *map, const irr::core::vector3df &pos, int range) :
    _window(window),
    _map(map),
    _range(range),
    _spawnTime(std::time(nullptr)),
    _exploded(false)
{
    _txtPos.X = static_cast<int>(pos.X / CUBE_SIZE);
    _txtPos.Y = static_cast<int>(pos.Y / CUBE_SIZE);
    _mesh = window->getSceneManager()->getMesh("assets/game/bomb.3DS");
    _bomb = window->getSceneManager()->addAnimatedMeshSceneNode(_mesh);
    _bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _bomb->setMD2Animation(irr::scene::EMAT_STAND);
    _bomb->setPosition(pos);
    _bomb->setScale(BOMB_SIZE);
    _bomb->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/game/bomb.png"));
}

Bomb::~Bomb()
{
}

bool Bomb::isExploded() const
{
    return _exploded;
}

std::vector<irr::core::vector2di> Bomb::bombRay(const irr::core::vector2di& dir)
{
    std::vector<irr::core::vector2di> hits;
    for (int i = 0; i <= _range; i++) {
        if (_map->getTxtMapItem(_txtPos + (dir * i)) == WALL) {
            _map->deleteMapWall(_txtPos + (dir * i));
            hits.emplace_back(_txtPos + (dir * i));
        }
        else if (_map->getTxtMapItem(_txtPos + (dir * i)) == BEDROCK)
            return hits;
    }
    return hits;
}

std::vector<irr::core::vector2di> Bomb::update()
{
    std::vector<irr::core::vector2di> hits;
    std::vector<irr::core::vector2di> tmp;

    if (std::time(nullptr) - _spawnTime > BOMB_TIMER) {
        _exploded = true;
        tmp = (bombRay(irr::core::vector2di(0, 0)));
        hits.insert(hits.end(), tmp.begin(), tmp.end());
        tmp = (bombRay(irr::core::vector2di(1, 0)));
        hits.insert(hits.end(), tmp.begin(), tmp.end());
        tmp = (bombRay(irr::core::vector2di(0, 1)));
        hits.insert(hits.end(), tmp.begin(), tmp.end());
        tmp = (bombRay(irr::core::vector2di(1, 1)));
        hits.insert(hits.end(), tmp.begin(), tmp.end());
        _bomb->remove();

    }
    return hits;
}

//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/door.h"
Door::Door(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values)
        : StaticObject(texture, position, tileSize, type, values){}

void Door::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Door::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Door::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
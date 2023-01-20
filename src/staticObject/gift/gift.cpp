//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/gift/gift.h"


Gift::Gift(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values)
            : StaticObject(texture, position, tileSize, type, values) {}

void Gift::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Gift::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Gift::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
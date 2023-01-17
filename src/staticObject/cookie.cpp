//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/cookie.h"

Cookie::Cookie(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type): StaticObject(texture, position, tileSize, type){}

void Cookie::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Cookie::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Cookie::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
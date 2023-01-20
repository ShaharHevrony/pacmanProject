//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/cookie.h"

Cookie::Cookie(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type, Values& values)
        : StaticObject(texture, position, tileSize, type, values){}

void Cookie::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Cookie::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Cookie::handleCollision(Demon& demon) {
    //FIXME save the cookie in temp and when the demon moved to another place return her
    demon.handleCollision(*this);
}
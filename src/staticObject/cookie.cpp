//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/cookie.h"

Cookie::Cookie(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type): StaticObject(texture, position, tileSize, type){}

void Cookie::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Cookie::handleCollision(Pacman& pacman) {
    if (m_sprite.getGlobalBounds().intersects(pacman.getSprite().getGlobalBounds())) {
        setIsDeleteTrue();
    }
    pacman.handleCollision(*this);
}

void Cookie::handleCollision(Demon& demon) {
    if (m_sprite.getGlobalBounds().intersects(demon.getSprite().getGlobalBounds())) {
        setIsDeleteTrue();
    }//FIXME save the cookie in temp and when the demon mived to another place retern her
    demon.handleCollision(*this);
}
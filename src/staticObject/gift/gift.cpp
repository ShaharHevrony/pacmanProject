//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/gift/gift.h"


Gift::Gift(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type): StaticObject(texture, position, tileSize, type) {}

void Gift::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Gift::handleCollision(Pacman& pacman) {
    if (m_sprite.getGlobalBounds().intersects(pacman.getSprite().getGlobalBounds())) {
        setDelete();
    }
    pacman.handleCollision(*this);
}

void Gift::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
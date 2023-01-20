//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/key.h"

Key::Key(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values)
        : StaticObject(texture, position, tileSize, type, values) {}

void Key::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Key::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Key::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
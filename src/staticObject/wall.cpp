
#include "staticObject/wall.h"

Wall::Wall(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values)
        : StaticObject(texture, position, tileSize, type, values) {}

void Wall::handleCollision(Object& object) {
    object.handleCollision(*this);
}

void Wall::handleCollision(Pacman& pacman) {
    pacman.handleCollision(*this);
}

void Wall::handleCollision(Demon& demon) {
    demon.handleCollision(*this);
}
//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/wall.h"

Wall::Wall(sf::Texture* texture, const sf::Vector2f& position, char type) : StaticObject(texture, position, type) {}
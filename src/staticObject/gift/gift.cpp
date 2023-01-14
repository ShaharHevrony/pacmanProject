//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "staticObject/gift/gift.h"

Gift::Gift(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type): StaticObject(texture, position, tileSize, type) {}
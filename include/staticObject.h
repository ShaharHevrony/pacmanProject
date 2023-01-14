#pragma once
#include "object.h"
class StaticObject: public Object{
public:
    StaticObject(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type);

private:
};
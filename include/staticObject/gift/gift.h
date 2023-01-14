#pragma once
#include "staticObject.h"
class Gift: public StaticObject{
public:
    Gift(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

private:
};
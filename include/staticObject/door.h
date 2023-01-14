#pragma once
#include "staticObject.h"
#include <SFML/Graphics.hpp>
class Door :public StaticObject{
public:
    Door(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

private:
};

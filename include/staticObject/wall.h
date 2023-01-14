#pragma once
#include "staticObject.h"
#include <SFML/Graphics.hpp>
class Wall :public StaticObject{
public:
    Wall(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

private:
};

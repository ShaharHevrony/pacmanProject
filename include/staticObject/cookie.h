#pragma once
#include "staticObject.h"
#include <SFML/Graphics.hpp>
class Cookie :public StaticObject{
public:
    Cookie(sf::Texture* texture, const sf::Vector2f& position, char type);

private:
};

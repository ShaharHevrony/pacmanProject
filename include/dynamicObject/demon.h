
#pragma once
#include <SFML/Graphics.hpp>
#include "dynamicObject.h"

class Demon: public DynamicObject{
public:
    Demon(sf::Texture* texture, const sf::Vector2f& position, char type);

private:
};
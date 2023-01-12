
#pragma once
#include <SFML/Graphics.hpp>
#include "dynamicObject.h"

class Pacman: public DynamicObject{
public:
    Pacman(sf::Texture* texture, const sf::Vector2f&, char type);

private:
};


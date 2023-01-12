
#pragma once
#include "staticObject.h"
#include <SFML/Graphics.hpp>
class Key :public StaticObject{
public:
    Key(sf::Texture* texture, const sf::Vector2f& position, char type);

private:
};

#pragma once
#include "staticObject.h"
class Gift: public StaticObject{
public:
    Gift(sf::Texture* texture, const sf::Vector2f& position, char type);

private:
};
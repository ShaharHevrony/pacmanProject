
#pragma once
#include <SFML/Graphics.hpp>
#include "dynamicObject.h"

class Demon: public DynamicObject{
public:
    Demon(sf::Texture* texture, const sf::Vector2f& position, float tileSize ,char type);

    virtual void move(float time, sf::Vector2f pacLocation);

    virtual void handleCollision(Object& object);

    virtual void handleCollision(Door& door);

    virtual void handleCollision(Pacman& pacman) {}

    virtual void handleCollision(Demon& demon) {}

    virtual void handleCollision(Cookie& cookie) {}

    virtual void handleCollision(Gift& gift) {}

    virtual void handleCollision(Key& key) {}

    virtual void handleCollision(Wall &wall);
private:
};

#pragma once
#include <SFML/Graphics.hpp>
#include "staticObject.h"
#include "demon.h"
#include "pacman.h"

class Wall :public StaticObject{
public:
    Wall(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values);

    virtual void handleCollision(Object& object);

    virtual void handleCollision(Pacman& pacman);

    virtual void handleCollision(Demon& demon);
private:
};

#pragma once
#include "staticObject.h"
#include "demon.h"
#include "pacman.h"

class Gift: public StaticObject{
public:
    Gift(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

    virtual void handleCollision(Object& object);

    virtual void handleCollision(Pacman& pacman);

    virtual void handleCollision(Demon& demon);
private:
};
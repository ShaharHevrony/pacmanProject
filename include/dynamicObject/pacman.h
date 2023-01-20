#pragma once
#include <SFML/Graphics.hpp>
#include "dynamicObject.h"
#include "values.h"

class Pacman: public DynamicObject{
public:
    Pacman(sf::Texture* texture, const sf::Vector2f&, float tileSize, char type, Values& values);

    virtual void move(float time, sf::Vector2f pacLocation);

    virtual void handleCollision(Object& object);

    virtual void handleCollision(Pacman& pacman);

    virtual void handleCollision(Demon& demon);

    virtual void handleCollision(Cookie& cookie);

    virtual void handleCollision(Door& door);

    virtual void handleCollision(Gift& gift);

    virtual void handleCollision(Key& key);

    virtual void handleCollision(Wall &wall);

    bool checkIfSuper() const;

    void makeSuper();

    void makeRegular();

private:
    bool m_isSuper = false;
};


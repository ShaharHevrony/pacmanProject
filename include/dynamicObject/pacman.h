
#pragma once
#include <SFML/Graphics.hpp>
#include "dynamicObject.h"
#include "keyBoard.h"


class Pacman: public DynamicObject{
public:
    Pacman(sf::Texture* texture, const sf::Vector2f&, float tileSize, char type);

    virtual void move(float time, sf::Vector2f pacLocation);


private:
    Keyboard* m_key;

};


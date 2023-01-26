#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "values.h"
#include "resourcesManager.h"

class Pacman;
class Demon;
class Wall;
class Key;
class Door;
class Cookie;
class Gift;

class Object {
public:
    //constructor of default position
    Object( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type, Values& value);

    virtual ~Object() = default;

    virtual void handleCollision(Object& object)                   = 0;

    virtual void handleCollision(Pacman& pacman)                   = 0;

    virtual void handleCollision(Demon& demon)                     = 0;

    virtual void handleCollision(Cookie& cookie)                   = 0;

    virtual void handleCollision(Door& door)                       = 0;

    virtual void handleCollision(Key& key)                         = 0;

    virtual void handleCollision(Wall& wall)                       = 0;

    virtual void handleCollision(Gift& gift)                       = 0;

    //set the sprite of the object
    void setSprite(sf::Sprite sprite);

    //get the char of the object
    char getType() const;

    //get the sprite of the object
    sf::Sprite& getSprite() const;

    //draw the object on the board
    void draw(sf::RenderWindow& m_window);

    //get the values of the game
    Values getVal() const;

protected:
    sf::Sprite m_sprite;

    Values& m_values;

private:
    bool is_delete = false;

    char m_type;

    int m_row;

    int m_col;
};

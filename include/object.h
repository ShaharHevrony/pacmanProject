#pragma once
#include <SFML/Graphics.hpp>

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
    Object( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type);

    virtual void handleCollision(Object& object) = 0;

    virtual void handleCollision(Pacman& pacman) = 0;

    virtual void handleCollision(Demon& demon)   = 0;

    virtual void handleCollision(Cookie& cookie) = 0;

    virtual void handleCollision(Door& door)     = 0;

    virtual void handleCollision(Gift& gift)     = 0;

    virtual void handleCollision(Key& key)       = 0;

    virtual void handleCollision(Wall& wall)     = 0;

    //set sprite
    void setSprite(sf::Sprite sprite);

    char getType();

    //return sprite
    sf::Sprite& getSprite() const;

    void setRow(int row);

    int getRow() const;

    void setCol(int col);

    int getCol() const;

    void draw(sf::RenderWindow& m_window);

protected:

    sf::Sprite m_sprite;

private:
    bool is_delete = false;

    char m_type;

    int m_row;

    int m_col;
};

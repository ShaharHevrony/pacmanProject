#pragma once
#include <SFML/Graphics.hpp>
/*
class Wall;
class Key;
class Demon;
class Door;
class Cookie;
class Gift;
class Pacman;
*/

class Object {
public:
    //constructor of default position
    Object( sf::Texture* texture, const sf::Vector2f& position, char type);

//set sprite
    void setSprite(sf::Sprite sprite);

    //return sprite
    sf::Sprite& getSprite() const;

    void setType(char type);

    char getType() const;

    void setRow(int row);

    int getRow() const;

    void setCol(int col);

    int getCol() const;

private:
    sf::Sprite m_sprite;

    char m_type;

    int m_row;

    int m_col;
};

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
    Object( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type);

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
    char m_type;

    int m_row;

    int m_col;
};

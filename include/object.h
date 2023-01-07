#pragma once
#include <SFML/Graphics.hpp>

class Object {
public:
    //constructor of default position
    Object();

    //set texture
    void setTexture(sf::Texture* texture);

    //get texture
    sf::Texture* getTexture() const;

    //set sprite
    void setSprite(sf::Sprite sprite);

    //return sprite
    sf::Sprite getSprite() const;

    //set position
    void setPosition(sf::Vector2f position);

    //return position
    sf::Vector2f getPosition() const;

    void setType(char type);

    char getType() const;

private:
    sf::Texture* m_texture;

    sf::Sprite m_sprite;

    sf::Vector2f m_position;

    char m_type;
};

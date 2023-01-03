#pragma once
//#include <SFML/Graphics.hpp>

class Object {
public:
    Object();

    //void setPositoin (sf::Vector2f);

    //sf::Vector2f getPosotion () const;

    void setType (char type);

    char getType () const;

private:
    //sf::Vector2f m_position;

    char m_type;
};
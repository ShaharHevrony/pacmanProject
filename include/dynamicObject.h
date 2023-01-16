#pragma once
#include "object.h"

class DynamicObject: public Object {
public:
    DynamicObject(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

    virtual void move(float time, sf::Vector2f pacLocation) = 0;

    void moving(sf::Vector2f direction, float time, sf::Vector2f pacLocation);

    void moveObject();

    bool validMove(int direction, char type);

    void setNextPosition (int direction, float &x , float &y);

    sf::Vector2f getNextPosition() const;

    int getNextRow() const;

    int getNextCol() const;

private:
    sf::Vector2f m_nextPosition;

    int m_nextRow;

    int m_nextCol;
};
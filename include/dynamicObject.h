#pragma once
#include "object.h"

class DynamicObject: public Object {
public:
    DynamicObject();

    void moveObject();

    bool validMove(int direction, char type);

    void setNextPosition (int direction);

    sf::Vector2f getNextPosition() const;

    int getNextRow() const;

    int getNextCol() const;

private:
    sf::Vector2f m_nextPosition;

    int m_nextRow;

    int m_nextCol;
};
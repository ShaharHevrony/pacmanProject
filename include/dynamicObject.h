#pragma once
#include "object.h"

class DynamicObject: public Object {
public:
    DynamicObject();

    void moveObject();

    bool validMove(int direction, int row, int col, int type);

    void setNextLocation (int direction);

    sf::Vector2f getNextLocation() const;

private:
    sf::Vector2f m_nextPosition;
};
//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "dynamicObject.h"
#include "board.h"

DynamicObject::DynamicObject(){}

bool DynamicObject::validMove(int direction, int row, int col, int type){
    //check what is in the next location
    setNextPosition(direction);
    int x = m_nextPosition.x;
    int y = m_nextPosition.y;
    //check if the location is in the board boarder
    if (x >= 0 && x < col && y >= 0 && y < row && type == SPACE_S){
        return true;
    } else {
        return false;
    }
}

void DynamicObject::setNextPosition(int direction){
    int x = getPosition().x;
    int y = getPosition().y;

    switch (direction)
    {
        case sf::Keyboard::Left:{
            m_nextPosition.y = y;
            m_nextPosition.x = x - 1;
            break;
        }
        case sf::Keyboard::Right:{
            m_nextPosition.y = y;
            m_nextPosition.x = x + 1;
            break;
        }
        case sf::Keyboard::Down:{
            m_nextPosition.y = y + 1;
            m_nextPosition.x = x;
            break;
        }
        case sf::Keyboard::Up:{
            m_nextPosition.y = y - 1;
            m_nextPosition.x = x;
            break;
        }
        default:
            break;
    }
}

sf::Vector2f DynamicObject::getNextLocation() const{
    return m_nextPosition;
}

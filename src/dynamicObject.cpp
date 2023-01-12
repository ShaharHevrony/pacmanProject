//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "dynamicObject.h"
#include "board.h"

DynamicObject::DynamicObject(sf::Texture* texture,const sf::Vector2f& position, char type): Object(texture, position, type) {}

/*
bool DynamicObject::validMove(int direction, char type){
    //check what is in the next location
    setNextPosition(direction);
    int x = m_nextPosition.x;
    int y = m_nextPosition.y;

    //check if the location is in the board boarder
    if (this->getSprite().getGlobalBounds().contains(m_nextPosition) && type == SPACE_S){
        return true;
    } else {
        return false;
    }
}
*/

void DynamicObject::setNextPosition(int direction){
    //float x = getSprite().getPosition().x;
    //float y = getSprite().getPosition().y;

    switch (direction)
    {
        case sf::Keyboard::Left:{
            m_nextRow = getRow();
            m_nextCol = getCol() - 1;

            //m_nextPosition.x = x;
            //m_nextPosition.y = y - 1;
            break;
        }
        case sf::Keyboard::Right:{
            m_nextRow = getRow();
            m_nextCol = getCol() + 1;

            //m_nextPosition.x = x;
            //m_nextPosition.y = y + 1;
            break;
        }
        case sf::Keyboard::Down:{
            m_nextRow = getRow() + 1;
            m_nextCol = getCol();

            //m_nextPosition.x = x + 1;
            //m_nextPosition.y = y;
            break;
        }
        case sf::Keyboard::Up:{
            m_nextRow = getRow() - 1;
            m_nextCol = getCol();

            //m_nextPosition.x = x - 1;
            //m_nextPosition.y = y;
            break;
        }
        default:
            break;
    }
}

sf::Vector2f DynamicObject::getNextPosition() const{
    return m_nextPosition;
}

int DynamicObject::getNextRow() const {
    return m_nextRow;
}

int DynamicObject::getNextCol() const {
    return m_nextCol;
}

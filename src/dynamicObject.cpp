//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "dynamicObject.h"
#include "board.h"

DynamicObject::DynamicObject(const Board* board):m_board(board){}

bool DynamicObject::validMove(int direction){
    //check what is in the next location
    changeLocation(direction);
    int x = m_nextPosition.x;
    int y = m_nextPosition.y;
    //check if the location is in the board boarder
    if (x >= 0 && x < m_board->getCol() && y >= 0 && y < m_board->getRow() &&
        //check what is the symbol in the next location
        m_board->getObject(x, y) == SPACE_S){
        return true;
    } else {
        return false;
    }
}

void DynamicObject::changeLocation(int direction){
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

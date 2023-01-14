//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "dynamicObject.h"
#include "board.h"

DynamicObject::DynamicObject(sf::Texture* texture,const sf::Vector2f& position, float tileSize,char type): Object(texture, position, tileSize, type) {}

void DynamicObject::moving(sf::Vector2f direction, float time) {
    m_sprite.move(direction * time * 120.f);
}

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



int DynamicObject::getNextRow() const {
    return m_nextRow;
}

int DynamicObject::getNextCol() const {
    return m_nextCol;
}

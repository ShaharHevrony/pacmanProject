//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "staticObject.h"

StaticObject::StaticObject( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : Object(texture, position, tileSize, type) {}

sf::Rect<float> StaticObject::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}

bool StaticObject::getIsDelete() const {
    return m_isDelete;
}

void StaticObject::setIsDeleteTrue() {
    m_isDelete = true ;
}

void StaticObject::setIsDeleteFalse() {
    m_isDelete = false;
}

void StaticObject::setDeleteDoorTrue() {
    m_deleteDoor = true;
}

void StaticObject::setDeleteDoorFalse() {
    m_deleteDoor = false;
}

bool StaticObject::getIsDeleteDoor(){
    return m_deleteDoor;
}
//
// Created by Shahar Hevrony on 29/12/2022.
//
#include "dynamicObject.h"
#include "wall.h"

DynamicObject::DynamicObject(sf::Texture* texture,const sf::Vector2f& position, float tileSize,char type, Values& values)
            :Object(texture, position, tileSize, type, values), m_lastPosition(position), m_originPosition(position){}

void DynamicObject::moving(sf::Vector2f direction, float time , sf::Vector2f pacLocation) {
    m_sprite.move(direction * time * 120.f);
}

int DynamicObject::getNextRow() const {
    return m_nextRow;
}

int DynamicObject::getNextCol() const {
    return m_nextCol;
}

sf::Vector2f DynamicObject::getPosition() const {
    return m_sprite.getPosition();
}

void DynamicObject::setPosition(sf::Vector2f position) {
    m_sprite.setPosition(position);
}

sf::Vector2f DynamicObject::getLastPosition() const {
    return m_lastPosition;
}

sf::Rect<float> DynamicObject::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}

void DynamicObject::setLastPosition(sf::Vector2f position) {
    m_lastPosition = position;
}

void DynamicObject::handleCollision(Wall& wall) {
    if(m_sprite.getGlobalBounds().intersects(wall.getSprite().getGlobalBounds()))
        m_sprite.setPosition(m_lastPosition);
}

sf::Vector2f DynamicObject::getOriginPosition() {
    return m_originPosition;
}

bool DynamicObject::getCollided() const {
    return m_collided;
}

void DynamicObject::setCollided() {
    m_collided = !m_collided ;
}

bool DynamicObject::getReastarDemon() const {
    return m_restarDemon;
}

void DynamicObject::setRestarDemon() {
    m_restarDemon = !m_restarDemon;
}
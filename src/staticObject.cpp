//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "staticObject.h"

StaticObject::StaticObject( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type, Values& values)
        : Object(texture, position, tileSize, type, values) {}

sf::Rect<float> StaticObject::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}

bool StaticObject::getDelete() const {
    return m_isDelete;
}

void StaticObject::setDelete() {
    m_isDelete = !m_isDelete;
}

bool StaticObject::getIfDraw() const {
    return m_ifDraw;
}

void StaticObject::setIfDraw(bool draw) {
    m_ifDraw = draw;
}

bool StaticObject::getFreeze() const {
    return m_isFreeze;
}

void StaticObject::setFreeze() {
    m_isFreeze = !m_isFreeze;
}
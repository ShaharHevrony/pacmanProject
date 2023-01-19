//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "staticObject.h"

StaticObject::StaticObject( sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : Object(texture, position, tileSize, type) {}

sf::Rect<float> StaticObject::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}

bool StaticObject::getDelete() const {
    return m_isDelete;
}

void StaticObject::setDelete() {
    m_isDelete = !m_isDelete;
}

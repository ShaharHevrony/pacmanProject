#include <SFML/Graphics.hpp>
#include "object.h"

//constructor of default position
Object::Object(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values)
    : m_values(values), m_type(type){
    if(texture != nullptr){
        m_sprite.setTexture(*texture);
    }
    m_sprite.setPosition(position);
    m_sprite.setScale(tileSize / 2000, tileSize / 2000);
}

//set sprite
void Object::setSprite(sf::Sprite sprite) {
    m_sprite = sprite;
}

//return sprite
sf::Sprite& Object::getSprite() const {
    return (sf::Sprite&) m_sprite;
}

char Object::getType() {
    return m_type;
}

void Object::draw(sf::RenderWindow& m_window) {
    m_window.draw(m_sprite);
}

Values Object::getVal() const {
    return m_values;
}
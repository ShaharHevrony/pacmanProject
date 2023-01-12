#include <SFML/Graphics.hpp>
#include <vector>

#include "object.h"
#include "values.h"

//constructor of default position
Object::Object(sf::Texture* texture, const sf::Vector2f& position, char type): m_type(type){
    if(texture != nullptr){
        m_sprite.setTexture(*texture);
    }
    m_sprite.setPosition(position);
}

//set sprite
void Object::setSprite(sf::Sprite sprite) {
    m_sprite = sprite;
}

//return sprite
sf::Sprite& Object::getSprite() const {
    return (sf::Sprite&) m_sprite;
}

void Object::setType(char type){
    m_type = type;
}

char Object::getType() const {
    return m_type;
}

void Object::setRow(int row) {
    m_row = row;
}

void Object::setCol(int col) {
    m_col = col;
}

int Object::getRow() const{
    return m_row;
}

int Object::getCol() const{
    return m_col;
}

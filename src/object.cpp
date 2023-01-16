#include <SFML/Graphics.hpp>
#include <vector>

#include "object.h"
#include "values.h"

//constructor of default position
Object::Object(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type){
    if(texture != nullptr){
        m_sprite.setTexture(*texture);
    }
    m_sprite.setPosition(position);
    m_sprite.setScale(tileSize / 2000, tileSize / 2000);
    m_sprite.setOrigin(tileSize / 2, tileSize / 2);
    m_type = type;
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

void Object::draw(sf::RenderWindow& m_window) {
    m_window.draw(m_sprite);
}

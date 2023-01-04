#include <SFML/Graphics.hpp>
#include <vector>

#include "object.h"
#include "values.h"

//constructor of defult position
Object::Object(): m_position(sf::Vector2f(-1, -1)), m_texture(NULL), m_type(' ') {}

//set texter
void Object::setTexture(sf::Texture* texture) {
    m_texture = texture;
}

//return texeter
sf::Texture* Object::getTexture() const {
    return m_texture;
}

//set sprite
void Object::setSprite(sf::Sprite sprite) {
    m_sprite = sprite;
}

//return sprite
sf::Sprite Object::getSprite() const {
    return m_sprite;
}

//set position
void Object::setPosition(sf::Vector2f position) {
    m_position = position;
}

//get position
sf::Vector2f Object::getPosition() const {
    return m_position;
}

void Object::setType(char type){
    m_type = type;
}

char Object::getType() const {
    return m_type;
}


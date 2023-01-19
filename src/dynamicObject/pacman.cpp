//
// Created by Shahar Hevrony on 10/01/2023.
//
#include <iostream>

#include "dynamicObject/pacman.h"
#include <SFML/Graphics.hpp>
#include "cookie.h"
#include "key.h"
#include "gift.h"
#include "door.h"

Pacman::Pacman(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type)
        :DynamicObject(texture, position, tileSize, type) {
    m_sprite.setOrigin(sf::Vector2f (m_sprite.getTexture()->getSize()/2u));
}

void Pacman::move(float time, sf::Vector2f pacLocation) {
    setLastPosition(getPosition());
	pacLocation = getLastPosition();
	sf::Vector2f direction(0,0);
	sf::Sprite pac;
	int angle = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_sprite.setRotation(-90);
		direction.x = 0;
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_sprite.setRotation(90);
		direction.x = 0;
		direction.y = +1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_sprite.setRotation(-180);
		direction.x =-1;
		direction.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_sprite.setRotation(0);
		direction.x = +1;
		direction.y = 0;
	}
	moving(direction, time, pacLocation);
}

void Pacman::handleCollision(Object& object) {
    if(&object == this){
        return;
    } else {
        object.handleCollision(*this);
    }
}

void Pacman::handleCollision(Pacman& pacman) {
    //printf("pac with pac!!!!\n");
}

void Pacman::handleCollision(Demon& demon) {
    if(demon.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        setPosition(getOriginPosition());
		setRestarDemond();
		//demon.setPosition(demon.getOriginPosition());
        setCollided();
    }
}

void Pacman::handleCollision(Cookie& cookie) {}

void Pacman::handleCollision(Door& door) {
    if(m_sprite.getGlobalBounds().intersects(door.getSprite().getGlobalBounds()) && !m_isSuper)
        m_sprite.setPosition(getLastPosition());
}

void Pacman::handleCollision(Gift& gift) {}

void Pacman::handleCollision(Key& key) {}

void Pacman::handleCollision(Wall &wall) {
    DynamicObject::handleCollision(wall);
}

bool Pacman::checkIfSuper() const {
    return m_isSuper;
}

void Pacman::makeSuper() {
    m_isSuper = true;
}

void Pacman::makeRegular() {
    m_isSuper = false;
}

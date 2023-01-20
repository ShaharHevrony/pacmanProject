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

Pacman::Pacman(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type, Values& values)
        :DynamicObject(texture, position, tileSize, type, values) {
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

void Pacman::handleCollision(Pacman& pacman) {}

void Pacman::handleCollision(Demon& demon) {
    if(demon.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        setPosition(getOriginPosition());
        setRestarDemon();
        setCollided();
        m_values.setLife(DEC);
    }
}

void Pacman::handleCollision(Cookie& cookie) {
    if (cookie.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_values.setScore(2);
        m_values.setNumOfCookie(DEC);
        cookie.setDelete();
    }
}

void Pacman::handleCollision(Door& door) {
    if(door.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_sprite.setPosition(getLastPosition());
    }
}

void Pacman::handleCollision(Gift& gift) {
    if (gift.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_values.setScore(5);
        gift.setDelete();
        int chooseGift = m_values.getNumOfGift() % 4;
        switch (chooseGift) {
            case 0:{
                //giftFreeze
                gift.setFreeze();
                break;
            }
            case 1:{
                //giftLife
                m_values.setLife(INC);
                break;
            }
            case 2:{
                //giftSuper
                m_values.setLife(INC);
                break;
            }
            default:{
                //giftTime
                m_values.setTime(15);
                break;
            }
        }
        m_values.setNumOfGift(DEC);
    }
}

void Pacman::handleCollision(Key& key) {
    if (key.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_values.setScore(7);
        m_values.setNumOfKey(DEC);
        key.setDelete();
    }
}

void Pacman::handleCollision(Wall &wall) {
    DynamicObject::handleCollision(wall);
}
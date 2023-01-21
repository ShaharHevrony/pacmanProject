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
    m_eat.setBuffer(ResourcesManager::inctance().getEatCookie());
    m_pacmanDeath.setBuffer(ResourcesManager::inctance().getSoundDeath());
    m_pacmanState = std::make_unique<RegularPacman>(values);
}

void Pacman::move(float time, sf::Vector2f pacLocation) {

    if(m_pacmanState->getSuperState() && m_superClock.getElapsedTime().asSeconds() > 5){
        makeRegular();
    }
    setLastPosition(getPosition());
	pacLocation = getLastPosition();
	sf::Vector2f direction(0,0);

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
        m_pacmanState->handleCollision(*this, demon);
        //sound death pacman
        if (m_values.getLife() == 0) {
            m_pacmanDeath.play();
        }
    }
}

void Pacman::handleCollision(Cookie& cookie) {
    if (cookie.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_values.setScore(2);
        m_values.setNumOfCookie(DEC);
        cookie.setDelete();
        //sound eat cookie
        m_eat.play();

    }
}

void Pacman::handleCollision(Door& door) {
    if(door.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_pacmanState->handleCollision(*this, door);
    }
}

void Pacman::handleCollision(Gift& gift) {
    if (gift.getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds())) {
        m_values.setScore(5);
        gift.setDelete();
        m_eat.play();
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
                makeSuper();
                m_superClock.restart().asSeconds();
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

void Pacman::makeSuper() {
    m_pacmanState.reset(new SuperPacman(m_values));
    m_sprite.setTexture(*ResourcesManager::inctance().getSuperPacmanObj());
}

void Pacman::makeRegular() {
    m_pacmanState.reset(new RegularPacman(m_values));
    m_sprite.setTexture(*ResourcesManager::inctance().getPacmanObj());
}

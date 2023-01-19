//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "dynamicObject/demon.h"
#include "pacman.h"
#include "door.h"

Demon::Demon(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : DynamicObject(texture, position, tileSize, type), m_lastDirection(sf::Vector2f(1,0)) {}

void Demon::move(float time, sf::Vector2f pacLocation) {
    sf::Vector2f direction;
    sf::Vector2f dirArray[4] = {sf::Vector2f (1,0), sf::Vector2f (-1,0), sf::Vector2f (0,1), sf::Vector2f (0, -1)};

    int random = rand() % 4;
    bool findDirection = false;
    while (!findDirection){
        switch(random) {
            case 0: { //random - right
                if (pacLocation.x > getPosition().x && getLastDirection() != dirArray[random]) {
                    direction = dirArray[0];
                    findDirection = true;
                }
                break;
            }
            case 1:{ //random -left
                if (pacLocation.x <= getPosition().x && getLastDirection() != dirArray[random]) {
                    direction = dirArray[1];
                    findDirection = true;
                }
                break;
            }
            case 2:{ //random - dawn
                if (pacLocation.y > getPosition().y && getLastDirection() != dirArray[random]) {
                    direction = dirArray[2];
                    findDirection = true;
                }
                break;
            }
            case 3:{ //random - up
                if (pacLocation.y <= getPosition().y && getLastDirection() != dirArray[random]) {
                    direction = dirArray[3];
                    findDirection = true;
                }
            }
            default:
                break;
        }
        random = rand() % 4;
    }
    setLastPosition(m_sprite.getPosition());
    moving(direction, time, pacLocation);
    setLastDirection(direction);
}

void Demon::handleCollision(Object& object) {
    if(&object == this){
        return;
    } else {
        object.handleCollision(*this);
    }
}


void Demon::handleCollision(Door &door) {
    if(m_sprite.getGlobalBounds().intersects(door.getSprite().getGlobalBounds()))
        setPosition(getLastPosition());
}

void Demon::handleCollision(Wall &wall) {
    DynamicObject::handleCollision(wall);
}

sf::Vector2f Demon::getLastDirection() const {
    return m_lastDirection;
}

void Demon::setLastDirection(sf::Vector2f direction) {
    m_lastDirection = direction;
}

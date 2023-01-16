//
// Created by Shahar Hevrony on 10/01/2023.
//

#include "dynamicObject/demon.h"

Demon::Demon(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : DynamicObject(texture, position, tileSize, type) {}

void Demon::move(float time, sf::Vector2f pacLocation) {
    auto x_pac = pacLocation.x;
    auto y_pac = pacLocation.y;

    sf::Vector2f direction;

    auto x_demon = m_sprite.getPosition().x;
    auto y_demon = m_sprite.getPosition().y;
    //FIXME add valid for each move;

    switch (rand() % 4) {
    case 0: {
        //go left
        if (x_pac < x_demon) {
            direction.x = -1;
            direction.y = 0;
            break;
        }
    }
    case 1: {
        // go right
        if (x_pac > x_demon) {
            direction.x = +1;
            direction.y = 0;
            break;
        }
    }
    case 2: {
        //go dwon
        if (y_pac < y_demon) {
            direction.x = 0;
            direction.y = +1;
            break;
        }
    }
    case 3: {
        if (y_pac > y_demon) {
            direction.x = 0;
            direction.y = -1;
            break;
        }
    }
    default: {
    }//FIXME what to do when the demon got to default - mining didnt move 

    }
    moving(direction, time, pacLocation);
}



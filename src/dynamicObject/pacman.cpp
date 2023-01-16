//
// Created by Shahar Hevrony on 10/01/2023.
//
#include <iostream>

#include "dynamicObject/pacman.h"
#include <SFML/Graphics.hpp>
#include "values.h"


Pacman::Pacman(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : DynamicObject(texture, position, tileSize, type) {
}

void Pacman::move(float time, sf::Vector2f pacLocation) {
	pacLocation = m_sprite.getPosition();
	sf::Vector2f direction;
	sf::Sprite pac;
	int angle = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//m_sprite.setRotation(-90);
		direction.x = 0;
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//m_sprite.setRotation(90);
		direction.x = 0;
		direction.y = +1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//m_sprite.setRotation(-180);
		direction.x =-1;
		direction.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//m_sprite.setRotation(0);
		direction.x = +1;
		direction.y = 0;
	}
	moving(direction, time, pacLocation);

}


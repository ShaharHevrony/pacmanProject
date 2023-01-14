//
// Created by Shahar Hevrony on 10/01/2023.
//
#include <iostream>

#include "dynamicObject/pacman.h"
#include <SFML/Graphics.hpp>


Pacman::Pacman(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type) : DynamicObject(texture, position, tileSize, type) {
}

void Pacman::move(float time) {
	sf::Vector2f direction;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.x = 0;
		direction.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.x = 0;
		direction.y = +1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x =-1;
		direction.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = +1;
		direction.y = 0;
	}
	std::cout << direction.y << " " << direction.x << " \n";
	moving(direction, time);

}

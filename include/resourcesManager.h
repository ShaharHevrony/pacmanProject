//
// Created by Shahar Hevrony on 03/01/2023.
//
#pragma once

#include "values.h"
#include <SFML/Graphics.hpp>


class ResourcesManager {
public:
	ResourcesManager();

	sf::Font getFont();

	sf::Sprite getbackground();

	sf::Texture getTexture();

private:

	sf::Font m_font;

	sf::Sprite m_backgroundSprite;

	sf::Texture m_backgroundTexture;


	sf::Texture m_texture[17];
};

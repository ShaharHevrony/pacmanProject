//
// Created by Shahar Hevrony on 03/01/2023.
//
#pragma once

#include "values.h"
#include <SFML/Graphics.hpp>

class ResourcesManager {
public:
	static ResourcesManager& inctance();

	sf::Font& getFont();

	sf::Sprite &getBackGround();

	sf::Texture SuperPacmanText();

	sf::Sprite& SuperPacmanSprite();
	
	sf::Texture backButtonTexture();

	sf::Sprite& backButtonSprite();

	sf::Texture getTextureBack();

	sf::Texture getTextureMenuStart(int index);

    sf::Texture& getObject(int index) const;

private:

    ResourcesManager();

	sf::Font m_font;

	sf::Texture m_backButtonTexture;

	sf::Sprite m_backButtonSprite;

	sf::Sprite m_backgroundSprite;

	sf::Texture m_backgroundTexture;

	sf::Texture m_superPacmanTexture;

	sf::Sprite m_superPacmanSprite;

	sf::Texture m_textureMenuStart[4];

    sf::Texture* m_object[NUM_OF_OBJECTS];

	sf::Texture m_imagNames[10];
};

//
// Created by Shahar Hevrony on 03/01/2023.
//
#pragma once

#include "values.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourcesManager {
public:
	static ResourcesManager& inctance();

	sf::Font& getFont();

	sf::Sprite &getMenuBackGround();

    sf::Sprite &getPlayBackGround();

    sf::Sprite& soundButtonSprite();

    sf::Texture* soundButtonTexture();

    sf::Sprite& noSoundButtonSprite();

    sf::Texture* noSoundButtonTexture();

    sf::Sprite& backButtonSprite();

	sf::Texture getTextureBack();

	sf::Texture getTextureMenuStart(int index);

    sf::Texture& getObject(int index) const;

	sf::SoundBuffer& getSoundDeath();

	sf::SoundBuffer& getEatCookie();

	sf::SoundBuffer& getSoundTouch();

	sf::Sprite& getHelpWallSprite();

	sf::Texture getHelpWallTexture();

    sf::Texture* getSuperPacmanObj ();

    sf::Texture* getPacmanObj ();
private:

    ResourcesManager();

	sf::Font m_font;

    sf::Texture m_backButtonTexture;

    sf::Texture m_soundButtonTexture;

    sf::Texture m_noSoundButtonTexture;

    sf::Sprite m_backButtonSprite;

    sf::Sprite m_soundButtonSprite;

    sf::Sprite m_noSoundButtonSprite;

    sf::Texture m_menuBackgroundTexture;

	sf::Sprite m_menuBackgroundSprite;

    sf::Texture m_playBackgroundTexture;

    sf::Sprite m_playBackgroundSprite;

	sf::Sprite m_backgroundSprite;

	sf::Texture m_backgroundTexture;

	sf::Texture m_superPacmanTexture;

	sf::Sprite m_superPacmanSprite;

	sf::Texture m_textureMenuStart[4];

    sf::Texture* m_object[NUM_OF_OBJECTS];

	sf::Texture m_imagNames[10];

	sf::SoundBuffer m_soundDeath;

	sf::SoundBuffer m_soundEatCookie;

	sf::SoundBuffer m_soundTouch;

	sf::Texture m_helpWallTexture;

    sf::Sprite m_soundButton;

	sf::Sprite m_helpWallSprite;

    sf::Texture* m_superPacmanObj;

    sf::Texture* m_pacmanObj;
};

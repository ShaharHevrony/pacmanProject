//
// Created by Shahar Hevrony on 03/01/2023.
//

#include "resourcesManager.h"
#include "board.h"
#include "values.h"
ResourcesManager::ResourcesManager() {

    for (int index = 0; index < 4; index++) {
        m_textureMenuStart[index].loadFromFile(PATH + m_names[index]);
    }

    for (int index = 0; index < 10; index++) {
        m_imagNames[index].loadFromFile(PATH + imagNames[index]);
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(PATH + "menuBackground.png")) {
        // Error loading image
    }
    m_backgroundTexture = backgroundTexture;
    m_backgroundSprite.setTexture(m_backgroundTexture);

    sf::Texture superPacmanTexture;
    if (!superPacmanTexture.loadFromFile(PATH + "SuperPacman.png")) {
        // Error loading image
    }
    m_superPacmanTexture = superPacmanTexture;
    m_superPacmanSprite.setTexture(m_superPacmanTexture);
    
    for(int object = 0; object < NUM_OF_OBJECTS; object++){
        sf::Texture* temp = new sf::Texture;
        temp->loadFromFile(PATH + imagNames[object]);
        m_object[object] = temp;
    }
    m_pacmanObj = m_object[0];

    //load the front 
    sf::Font title;
    title.loadFromFile(PATH + "HappyMonkey.ttf");
    m_font = title;

    //load the back button 
    sf::Texture backButtonTexture;
    if (!backButtonTexture.loadFromFile(PATH + "backButton.png")) {
        // Error loading image
    }
    m_backButtonTexture = backButtonTexture;
    sf::Sprite backButtonSprite;
    backButtonSprite.setTexture(m_backButtonTexture);
    m_backButtonSprite = backButtonSprite;

    //load pacman death sound 
    sf::SoundBuffer soundDeath;
    if (!soundDeath.loadFromFile(PATH + "pacmanDeath.wav")) {
        // Error loading sound file
    }
    m_soundDeath = soundDeath;

    //load sound eat cookie
    sf::SoundBuffer soundCookieEat;
    if (!soundCookieEat.loadFromFile(PATH + "cookieEat.wav")) {
        // Error loading sound file
    }
    m_soundEatCookie = soundCookieEat;

    //load sound tuch button
    sf::SoundBuffer soundTuch;
    if (!soundTuch.loadFromFile(PATH + "bottunTuch.wav")) {
        // Error loading sound file
    }
    m_soundTuch = soundTuch;

    //load help wall
    sf::Texture helpWallTexture;
    if (!helpWallTexture.loadFromFile(PATH + "helpWall.png")) {
        // Error loading image
    }
    m_helpWallTexture = helpWallTexture;
    m_helpWallSprite.setTexture(m_helpWallTexture);

    sf::Texture* superPacmanObjTexture = new sf::Texture;
    if (!superPacmanObjTexture->loadFromFile(PATH + "superPacmanObj.png")) {
        // Error loading sound file
    }
    m_superPacmanObj = superPacmanObjTexture;
}


ResourcesManager &ResourcesManager::inctance() {
    static ResourcesManager m_instance;
    return m_instance;
}

sf::Font& ResourcesManager::getFont() {
    return m_font;
}

sf::Texture ResourcesManager::getTextureBack() {
    return m_backgroundTexture;
}

sf::Sprite &ResourcesManager::getBackGround(){
    return m_backgroundSprite; 
}

sf::Texture ResourcesManager::getHelpWallTexture() {
    return m_helpWallTexture;
}

sf::Sprite& ResourcesManager::getHelpWallSprite() {
    return m_helpWallSprite;
}

sf::Texture ResourcesManager::SuperPacmanText() {
    return m_superPacmanTexture;
}

sf::Sprite &ResourcesManager::SuperPacmanSprite() {
    return m_superPacmanSprite;
}

sf::Texture ResourcesManager::getTextureMenuStart(int index) {
    return  m_textureMenuStart[index];
}

sf::Texture& ResourcesManager::getObject(int index) const {
    return *m_object[index];
}
//
sf::Texture ResourcesManager::backButtonTexture() {
    return m_backButtonTexture;
}

sf::Sprite& ResourcesManager::backButtonSprite() {
    return m_backButtonSprite;
}

sf::SoundBuffer& ResourcesManager::getSoundDeath() {
    return m_soundDeath;
}

sf::SoundBuffer& ResourcesManager::getEatCookie() {
    return m_soundEatCookie;
}

sf::SoundBuffer& ResourcesManager::getSoundTuch() {
    return m_soundTuch;
}

sf::Texture* ResourcesManager::getSuperPacmanObj() {
    return m_superPacmanObj;
}

sf::Texture* ResourcesManager::getPacmanObj() {
    return m_pacmanObj;
}

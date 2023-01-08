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
    m_backgroundSprite = sf::Sprite(m_backgroundTexture);
    m_backgroundSprite.setScale(BACHGRAUND_SCALE, BACHGRAUND_SCALE);


    sf::Font title;
    title.loadFromFile(PATH + "HappyMonkey.ttf");
    m_font = title;
}

sf::Font ResourcesManager::getFont() {
    return m_font;
}

sf::Texture ResourcesManager::getTextureBack() {
    return m_backgroundTexture;
}


sf::Sprite ResourcesManager::getbackground(){
    return m_backgroundSprite; 
}

sf::Texture ResourcesManager::getTextureMenuStart(int index) {
    return  m_textureMenuStart[index];
}

sf::Sprite getSpriteMenuStart();
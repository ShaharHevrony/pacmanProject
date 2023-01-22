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

    sf::Texture menuBackgroundTexture;
    if (!menuBackgroundTexture.loadFromFile(PATH + "menuBackground.png")) {
        // Error loading image
    }
    m_menuBackgroundTexture = menuBackgroundTexture;
    m_menuBackgroundSprite.setTexture(m_menuBackgroundTexture);

    sf::Texture playBackgroundTexture;
    if (!playBackgroundTexture.loadFromFile(PATH + "playBackground.png")) {
        // Error loading image
    }
    m_playBackgroundTexture = playBackgroundTexture;
    m_playBackgroundSprite.setTexture(m_playBackgroundTexture);


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

    //load the sound button
    sf::Texture soundButtonTexture;
    if (!soundButtonTexture.loadFromFile(PATH + "sound.png")) {
        // Error loading image
    }
    m_soundButtonTexture = soundButtonTexture;
    sf::Sprite soundButtonSprite;
    soundButtonSprite.setTexture(m_soundButtonTexture);
    m_soundButtonSprite = soundButtonSprite;

    //load the no sound button
    sf::Texture noSoundButtonTexture;
    if (!noSoundButtonTexture.loadFromFile(PATH + "noSound.png")) {
        // Error loading image
    }
    m_noSoundButtonTexture = noSoundButtonTexture;
    sf::Sprite noSoundButtonSprite;
    noSoundButtonSprite.setTexture(m_noSoundButtonTexture);
    m_noSoundButtonSprite = noSoundButtonSprite;

    //load the bird music
    //sf::Music birsMusic;
    //if (!birsMusic.openFromFile("bird.wav")) {
    //    // Error loading music file
    //}
    //m_birsMusic = birsMusic;

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

    //load sound touch button
    sf::SoundBuffer soundTouch;
    if (!soundTouch.loadFromFile(PATH + "bottunTouch.wav")) {
        // Error loading sound file
    }
    m_soundTouch = soundTouch;

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

    //game over backround
    sf::Texture gameOverTexture;
    if (!gameOverTexture.loadFromFile(PATH + "gameOver.png")) {
        // Error loading image
    }
    m_gameOverTextur = gameOverTexture;
    m_gameOverSprite.setTexture(m_gameOverTextur);

    //game done backround
    sf::Texture gameDoneTexture;
    if (!gameDoneTexture.loadFromFile(PATH + "congratulations.png")) {
        // Error loading image
    }
    m_getsecssesTextur = gameDoneTexture;
    m_getsecssesSprite.setTexture(m_getsecssesTextur);

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

sf::Sprite &ResourcesManager::getMenuBackGround(){
    return m_menuBackgroundSprite;
}

sf::Sprite &ResourcesManager::getPlayBackGround(){
    return m_playBackgroundSprite;
}

sf::Texture ResourcesManager::getHelpWallTexture() {
    return m_helpWallTexture;
}

sf::Sprite& ResourcesManager::getHelpWallSprite() {
    return m_helpWallSprite;
}

sf::Texture ResourcesManager::getTextureMenuStart(int index) {
    return  m_textureMenuStart[index];
}

sf::Texture& ResourcesManager::getObject(int index) const {
    return *m_object[index];
}

sf::Sprite& ResourcesManager::soundButtonSprite() {
    return m_soundButtonSprite;
}

sf::Texture* ResourcesManager::soundButtonTexture() {
    return &m_soundButtonTexture;
}

sf::Sprite& ResourcesManager::noSoundButtonSprite() {
    return m_noSoundButtonSprite;
}

sf::Texture* ResourcesManager::noSoundButtonTexture() {
    return &m_noSoundButtonTexture;
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

sf::SoundBuffer& ResourcesManager::getSoundTouch() {
    return m_soundTouch;
}

sf::Texture* ResourcesManager::getSuperPacmanObj() {
    return m_superPacmanObj;
}

sf::Texture* ResourcesManager::getPacmanObj() {
    return m_pacmanObj;
}

sf::Sprite& ResourcesManager::getGameOverSprite() {
    return m_gameOverSprite;
}

sf::Texture ResourcesManager::getGameOverTexture() {
    return m_gameOverTextur;
}

sf::Sprite& ResourcesManager::getSecssesSprite() {
    return m_getsecssesSprite;
}

sf::Texture ResourcesManager::getSecssesTexture() {
    return m_getsecssesTextur;
}
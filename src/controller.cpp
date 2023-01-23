#include "controller.h"
#include <string.h>

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman"){
    create();
}

void Controller::run() {

    //load the bird music
    if (!m_music.openFromFile(PATH + "bird.wav")) {
        // Error loading music file
    }
    m_music.play();
    while (m_window.isOpen()){
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: {
                m_window.close();
                return ;
            }
             //if the user clicks on the window
            case sf::Event::MouseButtonReleased: {
                m_music.stop();
                handleMouseButton(event.mouseButton);

            }
            case sf::Event::MouseMoved: {
                handleMouseMoved(event.mouseMove);
            }
            }
        }
        create();
    }
}
     

void Controller::create() {
    //m_window.clear();

    sf::Sprite m_backgroundSprite;
    m_backgroundSprite = ResourcesManager::inctance().getMenuBackGround();
    m_window.draw(m_backgroundSprite);

    for (int index = 0; index < 3; index++) {
        m_texture[index] = ResourcesManager::inctance().getTextureMenuStart(index);
    }

    sf::Sprite sprite;
    for (int i = 0; i < 3; i++) {
        sf::Texture* tempText = &m_texture[i];
        sprite.setTexture(*tempText);
        sprite.setPosition(MENU_CENTER, i * MENU_GAP + MENU_START_ROW);

        sprite.setOrigin(MENU_PIC_WIDTH / 2, MENU_PIC_HEIGHT / 2);
        m_menu.push_back(sprite);
    }
    for (int i = 0; i < 3; i++) {
        m_window.draw(m_menu[i]);
    }
    m_window.display();
}

//function that handel the case in a mouse button
void Controller::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    //get the location of the click
    auto location = m_window.mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user click on one of them
    for (int index = 0; index < 3; index++) {
        //if the user click on the button
        if (m_menu[index].getGlobalBounds().contains(location)) {
            switch (index) {
                //if click on eraser
            case playButton: {
                m_level = 1;
                PlayGame* play = new PlayGame(m_window, m_level, m_sound, m_val);
                while (!(play->getEndAllLevels())) {
                    PlayGame* play = new PlayGame(m_window, m_level, m_sound, m_val);
                    play->playLevel(m_val);
                    if (play->getEndAllLevels()) {
                        play->gameOver(1);
                        break;
                    }
                    else if (play->getBack()) {
                        play->setBack();
                        break;
                    }
                    if (!play->timeOver()) {
                        m_level++;
                        m_val.setScore(m_val.getNumOfDemon()*2 + 50);
                    }
                    else {
                        m_val.setScore(0);
                    }
                }
                m_val.resetVal();
                break;
            }
            break;
            case helpButton: {
                Help help = Help(m_window);
                help.run();
                break;
            }
            case exitButton: {
                m_window.close();
                break;
            }
            default:
                break;
            }
        }
    }
}

void Controller::handleMouseMoved(sf::Event::MouseMoveEvent& event) {
    m_menu[m_tempButton].setScale(1, 1);
    auto location = m_window.mapPixelToCoords({ event.x, event.y });
    for (int row = 0; row < 4; row++){
        if (m_menu[row].getGlobalBounds().contains(location)) {
            m_soundTuch.setBuffer(ResourcesManager::inctance().getSoundTouch());
            m_soundTuch.play();
            m_menu[row].setScale(1.15, 1.15);
            m_tempButton = row;
        }
    }
}
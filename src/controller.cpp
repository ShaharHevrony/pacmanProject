#include "controller.h"
#include <string.h>

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman") ,m_playGame(m_window){
    create();
}

void Controller::run() {
    sf::Music music;
    if (!music.openFromFile(PATH + "bird.wav")) {
        // Error loading music file
    }
    music.play();
    while (m_window.isOpen()){
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: {
                m_window.close();
                return ;
            }
             //if the user clicks on the window
            case sf::Event::MouseButtonReleased: {
                handleMouseButton(event.mouseButton);

            }
            case sf::Event::MouseMoved: {
                 music.stop();
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
    m_backgroundSprite = ResourcesManager::inctance().getBackGround();
    m_window.draw(m_backgroundSprite);

    sf::Texture titleTexture;
    sf::Sprite titleSprite;
    titleSprite = ResourcesManager::inctance().SuperPacmanSprite();
    titleSprite.setScale(0.5, 0.5);
    titleSprite.setPosition(MENU_ROW-120, MENU_COL-100);

    for (int index = 0; index < 4; index++) {
        m_texture[index] = ResourcesManager::inctance().getTextureMenuStart(index);
    }

    sf::Sprite sprite;
    for (int i = 0; i < 4; i++) {
        sf::Texture* tempText = &m_texture[i];
        sprite.setTexture(*tempText);
        sprite.setPosition(MENU_CENTER, i * MENU_GAP + MENU_START_ROW);

        sprite.setOrigin(MENU_PIC_WIDTH / 2, MENU_PIC_HEIGHT / 2);
        m_menu.push_back(sprite);
    }
    for (int i = 0; i < 4; i++) {
        m_window.draw(m_menu[i]);
    }
    m_window.draw(titleSprite);
    m_window.display();
}


//function that handel the case in a mouse button
void Controller::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    //get the location of the click
    auto location = m_window.mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user click on one of them
    for (int index = 0; index < 4; index++) {
        //if the user click on the button
        if (m_menu[index].getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y }))) {
            switch (index) {
                //if click on eraser
            case playButton:
                m_playGame.play();
                break;
            case helpButton: {
                Help help = Help(m_window);
                help.run();
            }
                break;
            case newMapButton: {
                CreateLevel createLevel = CreateLevel(m_window);
                createLevel.run();
                break;
            }
            case exitButton:
                m_window.close();
                break;
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
            m_soundTuch.setBuffer(ResourcesManager::inctance().getSoundTuch());

            m_soundTuch.play();
            m_menu[row].setScale(1.15, 1.15);
            m_tempButton = row;
        }
    }
}
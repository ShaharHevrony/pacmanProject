#include "controller.h"
#include <string.h>

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman") ,m_playGame(m_window){
    create();
}

void Controller::run() {
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
                 handleMouseMoved(event.mouseMove);
            }
            }
        }
        create();
    }
}
     

void Controller::create() {
    //m_window.clear();

    sf::Texture m_backgroundTexture;
    m_backgroundTexture = ResourcesManager::inctance().getTextureBack();

    sf::Sprite m_backgroundSprite;
    m_backgroundSprite = ResourcesManager::inctance().getBackGround();
    m_window.draw(m_backgroundSprite);

    sf::Texture titleTexture;
    titleTexture = ResourcesManager::inctance().SuperPacmanText();
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
        sprite.setScale(MENU_SCALE, MENU_SCALE);
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
    //get the location of the klik
    auto location = m_window.mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user cklik on one of them
    for (int index = 0; index < 4; index++) {
        //if the user click on the button
        if (m_menu[index].getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y }))) {
            switch (index) {
                //if click on eraser
            case playBotton:
                m_playGame.play();
                break;
            case helpBotton:
                break;
            case newMapBotton: {
                CreateLevel createLevel = CreateLevel(m_window);
                createLevel.run();
                break;
            }
            case exitBotton:
                m_window.close();
                break;
            default:
                break;
            }
        }
    }
}
void Controller::handleMouseMoved(sf::Event::MouseMoveEvent& event) {
      m_menu[m_tempButton].setScale(MENU_SCALE, MENU_SCALE);
      auto location = m_window.mapPixelToCoords({ event.x, event.y });
    for (int row = 0; row < 4; row++){
        if (m_menu[row].getGlobalBounds().contains(location)) {
            m_menu[row].setScale(MENU_SCALE * 1.15, MENU_SCALE * 1.15);
            m_tempButton = row;
        }
    }
}
#include "controller.h"
#include <string.h>

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman"){
    create();
}

void Controller::run() {
    //sf::Music m_birdMusic;
    //m_birdMusic = ResourcesManager::inctance().getBirdMusic();
       //load the bird music
    sf::Music birsMusic;
    if (!birsMusic.openFromFile("bird.wav")) {
        // Error loading music file
    }
    birsMusic.play();
    while (m_window.isOpen()){
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: {
                m_window.close();
                return ;
            }
             //if the user clicks on the window
            case sf::Event::MouseButtonReleased: {
                birsMusic.stop();
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
    m_window.display();
}

//function that handel the case in a mouse button
void Controller::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    //get the location of the click
    auto location = m_window.mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user click on one of them
    for (int index = 0; index < 4; index++) {
        //if the user click on the button
        if (m_menu[index].getGlobalBounds().contains(location)) {
            switch (index) {
                //if click on eraser
            case playButton:
                m_level = 1;
                for (m_level; m_level <= 3; m_level++) { //FIXME: num of levels is not set.
                    PlayGame* play = new PlayGame(m_window, m_level);
                    play->playLevel(m_level);
                    if (m_level == 3) {
                        play->gameOv(1);
                    }
                }
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
            m_soundTuch.setBuffer(ResourcesManager::inctance().getSoundTouch());
            m_soundTuch.play();
            m_menu[row].setScale(1.15, 1.15);
            m_tempButton = row;
        }
    }
}
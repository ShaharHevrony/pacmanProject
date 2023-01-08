//
// Created by Shahar Hevrony on 29/12/2022.
//
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "values.h"

Menu::Menu(sf::RenderWindow& window, ResourcesManager& reso): m_window(&window), m_reso(&reso){}

int Menu::run() {
    int tempRow = 0;
    while (m_window->isOpen()){
        m_window->clear();
        create();
        print(tempRow);
        m_window->display();

        if (auto event = sf::Event{}; m_window->waitEvent(event)){
            switch (event.type) {
                case sf::Event::Closed: {
                    m_window->close();
                    return -1;
                }
                //if the user clicks on the window
                case sf::Event::MouseButtonReleased: {
                    int buttonPressed = handleMouseButton(event.mouseButton);
                    return buttonPressed;
                }
                case sf::Event::MouseMoved: {
                    m_inBounds = handleMouseMoved(tempRow);
                }
            }
        }
    }
}

void Menu::print(int row) {
    for (int i = 0; i < 4; i++){
        m_window->draw(m_menu[i]);
    }

    if (m_inBounds) {
        sf::Sprite sprite = m_menu[row];
        sprite.setScale(MENU_SCALE*1.15, MENU_SCALE*1.15);
        m_window->draw(sprite);
    }
}

void Menu::create() {

    sf::Font font;
    font = m_reso->getFont();
    sf::Text text("Super Pacman", font, MENU_TEXT_SIZE);
    text.setFillColor(sf::Color(255, 253, 208));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(255, 253, 208));
    text.setPosition(MENU_ROW, MENU_COL);

    sf::Texture backgroundTexture;
    backgroundTexture = m_reso->getTextureBack();
    sf::Sprite backgroundSprite;
    backgroundSprite = m_reso->getbackground();
    m_window->draw(backgroundSprite);

    for (int index = 0; index < 4; index++) {
        m_texture[index] = m_reso->getTextureMenuStart(index);
    }

    sf::Sprite sprite;
    for(int i = 0; i < 4; i++) {
        sf::Texture* tempText = &m_texture[i];
        sprite.setTexture(*tempText);
        sprite.setPosition(MENU_CENTER, i * MENU_GAP + MENU_START_ROW);
        sprite.setScale(MENU_SCALE, MENU_SCALE);
        sprite.setOrigin(MENU_PIC_WIDTH/2, MENU_PIC_HEIGHT/2);
        m_menu.push_back(sprite);
    }
    m_window->draw(text);
}

bool Menu::handleMouseMoved(int& row) {
    sf::Vector2f location = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
    for (row = 0; row < 4; row++) {
        if (m_menu[row].getGlobalBounds().contains(location)) {
            return true;
        }
    }
    return false;
}


//function that handel the case in a mouse button
int Menu::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    //get the location of the klik
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user cklik on one of them
    for (int index = 0; index < 4 ; index++) {
        //if the user click on the button
        if (m_menu[index].getGlobalBounds().contains(m_window->mapPixelToCoords({ event.x, event.y }))) {
            m_window->clear();
            switch (index) {
                //if click on eraser
                case playBotton:
                    return playBotton;
                case helpBotton:
                    return helpBotton;
                case newMapBotton:
                    return newMapBotton;
                case exitBotton:
                    return exitBotton;
                default:
                    break;
            }
        }
    }
}

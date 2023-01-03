//
// Created by Shahar Hevrony on 29/12/2022.
//
#include <SFML/Graphics.hpp>

#include "menu.h"
#include "values.h"
Menu::Menu():m_window(sf::RenderWindow(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "menu")) {
    //sf::Font font;
    //font.loadFromFile("../../../Title.ttf");
    //sf::String title("Super Pacman", font, 50);

    run();
}

void Menu::run() {
    int tempRow = 0;
    while (m_window.isOpen()){
        m_window.clear(sf::Color(250, 230, 215));
        create();
        print(tempRow);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event)){
            switch (event.type) {
                case sf::Event::Closed: {
                    m_window.close();
                    break;
                }
                //if the user clicks on the window
                //case sf::Event::MouseButtonReleased: {
                    //handleMouseButton(event.mouseButton);
                //    break;
                //}
                case sf::Event::MouseMoved: {
                    m_inBounds = handleMouseMoved(tempRow);
                }
            }
        }
    }
}

void Menu::print(int row) {
    for (int i = 0; i < 4; i++){
        m_window.draw(m_menu[i]);
    }

    if (m_inBounds) {
        sf::Sprite sprite = m_menu[row];
        sprite.setScale(0.7, 0.7);
        m_window.draw(sprite);
    }
}

void Menu::create() {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("backGame.png")) {
        // Error loading image
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    for (int index = 0; index < 4; index++) {
        m_texture[index].loadFromFile( m_names[index]);
    }

    sf::Sprite sprite;
    for(int i = 0; i < 4; i++) {
        sf::Texture* tempText = &m_texture[i];
        sprite.setTexture(*tempText);
        sprite.setPosition(MENU_CENTER, i * MENU_GAP + MENU_START_ROW);
        sprite.setScale(MENU_SCALE, MENU_SCALE);
        sprite.setOrigin(MENU_PIC_WIDTH / 2, MENU_PIC_HEIGHT / 2);
        m_menu.push_back(sprite);
    }
    m_window.draw(backgroundSprite);


}

bool Menu::handleMouseMoved(int& row) {
    sf::Vector2f location = (sf::Vector2f)sf::Mouse::getPosition(m_window);
    for (row = 0; row < 4; row++) {
        if (m_menu[row].getGlobalBounds().contains(location)) {
            return true;
        }
    }
    return false;
}

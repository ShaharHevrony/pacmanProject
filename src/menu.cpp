//
// Created by Shahar Hevrony on 29/12/2022.
//
#include <SFML/Graphics.hpp>

#include "menu.h"
#include "values.h"
Menu::Menu():m_window(sf::RenderWindow(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "menu")) {
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
    for (int i = 0; i < 5; i++){
        m_window.draw(m_menu[i]);
    }

    if (m_inBounds) {
        sf::Sprite sprite = m_menu[row];
        sprite.setScale(1.07, 1.07);
        m_window.draw(sprite);
    }
}

void Menu::create() {
    /*
    sf::RectangleShape rectangle;
    for(int i = 0; i < 4; i++) {
        rectangle.setSize(sf::Vector2f(700, 150));
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color(85, 93, 80));
        rectangle.setFillColor(sf::Color(192, 194, 201));
        rectangle.setPosition(700, i* 200 + 600);
        //m_menu.push_back(rectangle);
    }
    */

    for (int index = 0; index < 5; index++) {
        m_texture[index].loadFromFile("../../../" + m_names[index]);
    }

    sf::Sprite sprite;
    for(int i = 0; i < 4; i++) {
        sf::Texture* tempText = &m_texture[i];
        sprite.setTexture(*tempText);
        sprite.setPosition(1200, i* 200 + 600);
        sprite.setScale(1, 1);
        m_menu.push_back(sprite);
    }

    sf::Texture* tempText = &m_texture[4];
    sprite.setTexture(*tempText);
    sprite.setPosition(0, 0);
    sprite.setScale(2, 2);
    m_menu.push_back(sprite);
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

#include "help.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Help::Help(sf::RenderWindow& window) : m_window(&window) {}

void Help::run()
{
    m_backButton = ResourcesManager::inctance().backButtonSprite();
    m_backButton.setPosition(1700, 950);
    m_backButton.setScale(0.05, 0.05);
    m_backButton.setOrigin(1000, 1000);

    print();

    sf::Music music;
    if (!music.openFromFile("bird.wav")) {
        // Error loading music file
    }
    music.play();

    while (m_window->isOpen()) {
        if (auto event = sf::Event{}; m_window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                m_window->close();
                break;
            }
            if (event.type == sf::Event::MouseMoved) {
                handleMouseMoved(event.mouseMove);
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                handleMouseButton(event.mouseButton);
            }
        }
        print();
        if (m_back) {
            return;
        }
    }
}

void Help::print( ) {
    m_window->clear();

    sf::Sprite helpWall;
    helpWall = ResourcesManager::inctance().getHelpWallSprite();
    m_window->draw(helpWall);

    m_window->draw(m_backButton);
    m_window->display();
}

void Help::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    if (m_backButton.getGlobalBounds().contains(location)) {
        m_back = true;
        return;
    }
}

void Help::handleMouseMoved(sf::Event::MouseMoveEvent& event) {
    m_backButton.setScale(0.05, 0.05);
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    if (m_backButton.getGlobalBounds().contains(location)) {
        m_backButton.setScale(0.06, 0.06);
    }
}
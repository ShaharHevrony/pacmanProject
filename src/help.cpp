#include "help.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Help::Help(sf::RenderWindow& window) : m_window(&window) {}

void Help::run()
{
    m_window->clear();

    sf::Sprite helpWall;
    helpWall = ResourcesManager::inctance().getHelpWallSprite();
    m_window->draw(helpWall);
    m_window->display();
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
        }
    }
}

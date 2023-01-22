#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameOver::GameOver(sf::RenderWindow& m_window) : m_window(&m_window) {}

void GameOver::run(int i)
{
    m_window->clear();

    sf::Sprite gameOver;
    if (i = 0) {
        gameOver = ResourcesManager::inctance().getGameOverSprite();
    }
    else {
        gameOver = ResourcesManager::inctance().getsecssesSprite();
    }
    m_window->draw(gameOver);
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

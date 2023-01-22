#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameOver::GameOver(sf::RenderWindow& m_window) : m_window(&m_window) {}

void GameOver::run(int i)
{
    m_backButton = ResourcesManager::inctance().backButtonSprite();
    m_backButton.setPosition(1700, 950);
    m_backButton.setScale(0.05, 0.05);
    m_backButton.setOrigin(1000, 1000);
    print(i);

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
        if (m_back) {
            return;
        }
        print(i);
    }
    return;
}

void GameOver::print(int i) {
    m_window->clear();

    sf::Sprite gameOver;
    if (i == 0) {
        gameOver = ResourcesManager::inctance().getGameOverSprite();
    }
    else {
        gameOver = ResourcesManager::inctance().getsecssesSprite();
    }
    m_window->draw(gameOver);

    m_window->draw(m_backButton);
    m_window->display();
}

void GameOver::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    if (m_backButton.getGlobalBounds().contains(location)) {
        m_back = true;
        return;
    }
}

void GameOver::handleMouseMoved(sf::Event::MouseMoveEvent& event) {
    m_backButton.setScale(0.05, 0.05);
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    if (m_backButton.getGlobalBounds().contains(location)) {
        m_backButton.setScale(0.06, 0.06);
    }
}
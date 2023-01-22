#pragma once
#include "resourcesManager.h"


class GameOver {
public:
    GameOver(sf::RenderWindow& m_window);

    void run(int i);

    void print(int i);

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    void handleMouseMoved(sf::Event::MouseMoveEvent& event);



private:
    bool m_sound;

    bool m_back = false;

    sf::RenderWindow* m_window;

    sf::Sprite m_backButton;
};
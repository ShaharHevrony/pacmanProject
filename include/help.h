#pragma once
#include "resourcesManager.h"


class Help {
public:
    Help(sf::RenderWindow& window);

    void run();

    void print();

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    void handleMouseMoved(sf::Event::MouseMoveEvent& event);

private:
    
    bool  m_back = false;;

    sf::RenderWindow* m_window;

    sf::Sprite m_backButton;

};
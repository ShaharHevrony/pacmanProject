#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();

    void create();

    void run();

    void print(int row);

    bool handleMouseMoved(int& row);

private:
    sf::RenderWindow m_window;

    std::vector<sf::Sprite> m_menu;

    sf::Texture m_texture[5];

    bool m_inBounds = false;
};
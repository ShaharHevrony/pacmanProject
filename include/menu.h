#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "resourcesManager.h"

class Menu {
public:
    Menu(sf::RenderWindow& window, ResourcesManager& reso);

    void create();

    int run();

    void print(int row);

    //function that handel the case in a mouse button
    int handleMouseButton(sf::Event::MouseButtonEvent& event);

    bool handleMouseMoved(int& row);

private:
    sf::RenderWindow* m_window;

    std::vector<sf::Sprite> m_menu;

    sf::Texture m_texture[4];

    bool m_inBounds = false;

    ResourcesManager* m_reso;
};

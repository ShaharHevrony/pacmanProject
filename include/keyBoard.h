#pragma once
#include <SFML/Graphics.hpp>

class Keyboard {
public:
    //constructor set the direction by the keyboard
    Keyboard(sf::RenderWindow& window);

    //function that get the keyboard from the user
    int getKey();

private:
    sf::RenderWindow* m_window;
};
#pragma once
#include <SFML/Graphics.hpp>

class Keyboard {
public:
    //constructor set the direction by the key board
    Keyboard();

    //function that get the key board from the user
    int getKey();

    //function that get the key board from the user
    int handleRegularKey(int code);

    //function that handel the direction keys
    int handleSpecialKey(int code);

private:
    sf::RenderWindow m_window;
};
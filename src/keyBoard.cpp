//
// Created by Shahar Hevrony on 29/12/2022.
//
#include "keyBoard.h"
#include <iostream>
//constructor set the direction by the key board
Keyboard::Keyboard():m_window(){}

//function that get the key board from the user
int Keyboard::getKey(){
    sf::Event event;
    while(m_window.pollEvent(event) == true) {
        if(event.type == sf::Event::Closed) {
            m_window.close();
        }
        if(event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Left:
                case sf::Keyboard::Right:
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                    //function that handel the direction keys
                    return handleSpecialKey(event.key.code);
                default:
                    //function that deal with the unknown keys
                    return handleRegularKey(event.key.code);
            }
        }
    }
}

//function that deal with the unknown keys
int Keyboard::handleRegularKey(int code){
    switch (code)
    {
        case sf::Keyboard::Escape:
            std::cout << "Escape pressed. Exiting...\n";
            exit(EXIT_SUCCESS);
        case sf::Keyboard::Space:
            return sf::Keyboard::Space;
        default:
            std::cout << "Unknown regular key pressed (code = " << code << ")\n";
            return -1;
    }
}

//function that handel the direction keys
int Keyboard::handleSpecialKey(int code){
    switch (code) {
        case sf::Keyboard::Left:
            return sf::Keyboard::Left;
        case sf::Keyboard::Right:
            return sf::Keyboard::Right;
        case sf::Keyboard::Down:
            return sf::Keyboard::Down;
        case sf::Keyboard::Up:
            return sf::Keyboard::Up;
        default:
            std::cout << "Unknown special key pressed (code = " << code << ")\n";
            return -1;
    }
}
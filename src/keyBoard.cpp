//
// Created by Shahar Hevrony on 29/12/2022.
//
#include "keyBoard.h"
#include <iostream>
//constructor set the direction by the keyboard
Keyboard::Keyboard(sf::RenderWindow& window):m_window(&window){}

//function that get the keyboard from the user
int Keyboard::getKey(){
    sf::Event event;
    while(m_window->pollEvent(event)) {
        //std::cout << "***inside getKey, type is: "  << event.type << std::endl;
        if(event.type == sf::Event::Closed) {
            m_window->close();
        }
        if(event.type == sf::Event::KeyPressed) {
            //std::cout << "***inside getKey, code is: "  << event.key.code << std::endl;
            switch (event.key.code) {
                case sf::Keyboard::Left:
                case sf::Keyboard::Right:
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                case sf::Keyboard::Space:
                    return event.key.code;
                case sf::Keyboard::Escape:
                    std::cout << "Escape pressed. Exiting...\n";
                    exit(EXIT_SUCCESS);
                default:
                    std::cout << "Unknown regular key pressed (code = " << event.key.code << ")\n";
                    return -1;
            }
        }
    }
    return EXIT_FAILURE;
}
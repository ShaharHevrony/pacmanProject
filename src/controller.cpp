#include <SFML/Graphics.hpp>
#include "controller.h"
#include "values.h"
#include "menu.h"
#include "createLevel.h"
Controller::Controller():m_window(sf::RenderWindow(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman")){}

void Controller::run() {
    Menu menu(m_window);
    int buttonPressed = menu.run();
    m_window.clear();
    switch (buttonPressed) {
        case playBotton:{
            break;
        }
        case helpBotton:{
            break;
        }
        case newMapBotton:{
            CreateLevel createLevel = CreateLevel(m_window);
            createLevel.run();
            break;
        }
        case exitBotton:{
            m_window.close();
            break;
        }
    }
}
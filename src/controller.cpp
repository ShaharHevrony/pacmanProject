#include <SFML/Graphics.hpp>
#include "controller.h"
#include "values.h"
#include "menu.h"
#include "createLevel.h"
#include "resourcesManager.h"

Controller::Controller():m_window(sf::RenderWindow(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Pacman")),
        m_playGame(m_window){}

void Controller::run() {
    ResourcesManager reso = ResourcesManager();
    Menu menu(m_window, reso);
    int buttonPressed = menu.run();
    m_window.clear();
    switch (buttonPressed) {
        case playBotton:{
            m_playGame.play();
            break;
        }
        case helpBotton:{
            break;
        }
        case newMapBotton:{
            CreateLevel createLevel = CreateLevel(m_window, reso);
            createLevel.run();
            break;
        }
        case exitBotton:{
            m_window.close();
            break;
        }
    }
}


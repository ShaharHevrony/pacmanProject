#pragma once

//#include "window.h"
#include "playGame.h"

class Controller {
public:
    Controller();

    void run();

private:
    sf::RenderWindow m_window;

    //PlayGame m_playGame;
};


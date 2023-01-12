#pragma once
#include "playGame.h"
#include "resourcesManager.h"

class Controller {
public:
    Controller();

    void run();

private:
    sf::RenderWindow m_window;

    PlayGame m_playGame;
};


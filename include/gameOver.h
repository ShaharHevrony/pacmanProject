#pragma once
#include "resourcesManager.h"


class GameOver {
public:
    GameOver(sf::RenderWindow& m_window);

    void run(int i);

private:
    sf::RenderWindow* m_window;
};
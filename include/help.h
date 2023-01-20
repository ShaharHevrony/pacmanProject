#pragma once
#include "resourcesManager.h"


class Help {
public:
    Help(sf::RenderWindow& window);

    void run();

private:
    sf::RenderWindow* m_window;
};
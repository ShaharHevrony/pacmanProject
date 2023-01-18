#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "resourcesManager.h"
#include "values.h"

class Bar{
public:
    Bar(int startTime);

    void draw(sf::RenderWindow& window, const Values& val);

private:
    sf::Clock m_timer;

    sf::Text m_text[3];

    sf::Text m_bar[3];

    int m_startTime;
};
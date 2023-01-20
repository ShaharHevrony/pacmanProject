#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "resourcesManager.h"
#include "values.h"

class Bar{
public:
    Bar(Values& values);

    void draw(sf::RenderWindow& window, const Values& val);

private:
    sf::Clock m_timer;

    Values& m_val;

    sf::Text m_text[3];

    sf::Text m_bar[3];
};
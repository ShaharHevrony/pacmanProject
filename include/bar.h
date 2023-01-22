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

    bool timeUp() const;

private:
    sf::Clock m_timer;

    bool m_timeUp = false;

    Values& m_val;

    sf::Text m_text[4];

    sf::Text m_bar[4];
};
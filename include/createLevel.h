#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "controller.h"
//
// Created by Shahar Hevrony on 03/01/2023.
//

class CreateLevel {
public:
    CreateLevel();

    void run();

    void print(int row, int col);

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    bool handleMouseMoved(int& row, int& col) const;

    void outLine(int index);

    bool isValid();

    void saveLevel();
private:

    //Board m_board;

    std::vector<sf::Sprite> m_menu;

    sf::RenderWindow m_window;

    int m_currObj;

    int m_rowCurr;

    int m_colCurr;

    bool m_inBounds = false;
};
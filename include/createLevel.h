#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "resourcesManager.h"


#include "controller.h"
#include "board.h"
#include "values.h"
//
// Created by Shahar Hevrony on 03/01/2023.
//

class CreateLevel {
public:
    CreateLevel(sf::RenderWindow& window, ResourcesManager& reso);

    void run();

    void print(int row, int col);

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    bool handleMouseMoved(int& row, int& col) const;

    void outLine(int index);

    bool isValid();

    void saveLevel();

    void getRowAndCol ();
private:

    Board m_board;

    std::vector<sf::Sprite> m_menu;

    sf::RenderWindow* m_window;

    ResourcesManager* m_reso;


    int m_currObj;

    int m_rowCurr;

    int m_colCurr;

    bool m_inBounds = false;
};
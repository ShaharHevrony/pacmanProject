#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum Symbols {
    pacman,
    demon,
    door,
    key,
    wall,
    cookie,
    gift,
    eraser,
    restart,
    save,
};

enum Buttons{
    playBotton,
    helpBotton,
    newMapBotton,
    exitBotton,
};
struct Location
{
    explicit Location(int row, int col) : row(row), col(col) {}
    int row;
    int col;
};

const std::string m_names[4] = {"PlayButton.png", "HelpButton.png", "CreateButton.png",
                                "ExitButton.png"};
const std::string imagNames[10] = {"Pacman.png", "Demon.png", "Door.png", "Key.png",
                                   "Wall.png", "cookie.png", "Gift.png", "Eraser.png",
                                   "Restart.png", "Save.png"};

const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
const int WINDOW_WIDTH  = sf::VideoMode::getDesktopMode().width;


//const int WINDOW_HEIGHT = 1800;
//const int WINDOW_WIDTH  = 2000;
const int MENU_CENTER    = WINDOW_WIDTH / 2;
const int MENU_START_ROW = WINDOW_HEIGHT / 2.2;
const float MENU_SCALE   = 0.0003* WINDOW_WIDTH;
const int MENU_GAP       = MENU_SCALE * 200;
const int MENU_PIC_WIDTH = 508;
const int MENU_PIC_HEIGHT = 161;
const int MENU_TEXT_SIZE = WINDOW_HEIGHT / 8.5;
const int MENU_ROW = WINDOW_WIDTH / 4;
const int MENU_COL = WINDOW_HEIGHT / 4.7;



const int BOARD_WIDTH = 7*WINDOW_HEIGHT/8;
const int MENU_WIDTH    = WINDOW_HEIGHT/15;
const int START_ROW     = 150;
const int START_COL     = 200;
//const int MENU_ROW      = WINDOW_HEIGHT/15;
//const int MENU_COL      = 3*WINDOW_WIDTH/4;
const int OBJECT        = 10;
const int SPACE_SIZE    = 150;
const int TILE_SIZE     = 2070;
const float SCALE_SIZE  = 0.065;
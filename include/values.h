#pragma once

struct Location
{
    explicit Location(int row, int col) : row(row), col(col) {}
    int row;
    int col;
};

const std::string m_names[5] = { "PlayButton.png", "HelpButton.png", "CreateButton.png",
                                "ExitButton.png" , "backGame.png"};

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
const int BOARD_WIDTH   = 1700;
const int MENU_WIDTH    = 300;
const int START_ROW     = 150;
const int START_COL     = 200;
const int MENU_ROW      = 1700;
const int MENU_COL      = 100;
const int OBJECT        = 10;
const int SPACE_SIZE    = 150;
const int TILE_SIZE     = 2070;
const float SCALE_SIZE  = 0.05;

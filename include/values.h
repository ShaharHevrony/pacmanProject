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
//const std::string PATH = "../../../";
const std::string PATH = "";
const std::string m_names[4] = {"PlayButton.png", "HelpButton.png", "CreateButton.png",
                                "ExitButton.png"};
const std::string imagNames[10] = {"Pacman.png", "Demon.png", "Door.png", "Key.png",
                                   "Wall.png", "cookie.png", "Gift.png", "Eraser.png",
                                   "Restart.png", "Save.png"};

const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
const int WINDOW_WIDTH  = sf::VideoMode::getDesktopMode().width;
const int BACHGRAUND_SCALE = WINDOW_HEIGHT/(2*508); //FIXME

const int MENU_CENTER    = WINDOW_WIDTH / 2;
const int MENU_START_ROW = WINDOW_HEIGHT / 2.2;
const float MENU_SCALE   = 0.0003* WINDOW_WIDTH;
const int MENU_GAP       = MENU_SCALE * 200;
const int MENU_PIC_WIDTH = 508;
const int MENU_PIC_HEIGHT = 161;
const int MENU_TEXT_SIZE = WINDOW_HEIGHT / 8.5;
const int MENU_ROW = WINDOW_WIDTH / 4;
const int MENU_COL = WINDOW_HEIGHT / 4.7;

const int BOARD_WIDTH = WINDOW_HEIGHT;
const int BOARD_HEIGHT = 7 * WINDOW_HEIGHT / 8;

const int MENU_SIZE     = WINDOW_HEIGHT / 9.5;
const int MENU_WIDTH    = WINDOW_HEIGHT/15;
const int START_ROW     = WINDOW_HEIGHT / 9.5;
const int START_COL     = WINDOW_HEIGHT / 10;
const int OBJ_ROW       = WINDOW_HEIGHT/5;
const int OBJ_COL       = 2.5*WINDOW_WIDTH/4;
const int OBJECT        = 10;
const int SPACE_SIZE    = WINDOW_HEIGHT / 9.5;
const int TILE_SIZE     = 2070;
const float OBJ_SCALE_SIZE  = 0.00002 * WINDOW_WIDTH;
const float SCALE_SIZE  = 0.00002 * WINDOW_WIDTH;

const int NUM_OF_OBJECTS = 7  ;
const int WALL_S         = '#';
const int SPACE_S        = ' ';
const int PACMAN_S       = 'a';
const int SUPER_PACMAN_S = '@';
const int DEMON_S        = '&';
const int DOOR_S         = 'D';
const int KEY_S          = '%';
const int COOKIE_S       = '*';
const int GIFT_S         = '$';
const int SKIP_TURN      = 100;
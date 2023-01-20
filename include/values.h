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
    playButton,
    helpButton,
    newMapButton,
    exitButton,
};


struct BoardLimits {
    sf::Vector2f topLeft;
    sf::Vector2f bottomRight;
    float tileSize;
};

//const std::string PATH = "../../../";
const std::string PATH = "";
const std::string m_names[4] = {"PlayButton.png", "HelpButton.png", "CreateButton.png",
                                "ExitButton.png"};
const std::string imagNames[10] = {"Pacman.png", "Demon.png", "Door.png", "Key.png",
                                   "Wall.png", "cookie.png", "Gift.png", "Eraser.png",
                                   "Restart.png", "Save.png"};
const std::string gameBar[3] = {"Time: ", "Points: ", "Life: "};

const int WINDOW_HEIGHT = 1068;
const int WINDOW_WIDTH  = 1898;

const int MENU_CENTER    = WINDOW_WIDTH / 2;
const int MENU_START_ROW = WINDOW_HEIGHT / 2;
const int MENU_GAP       = 150;
const int MENU_PIC_WIDTH = 420;
const int MENU_PIC_HEIGHT = 133;
const int MENU_TEXT_SIZE = WINDOW_HEIGHT / 8.5;
const int MENU_ROW = 600;
const int MENU_COL = 308;

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

const int INC = 1;
const int DEC = -1;

class Values {
public:
    int getLife() const {return m_life;}
    int getScore() const {return m_score;}
    int getNumOfPacman() const {return m_numOfPacman;}
    int getNumOfDemon() const {return m_numOfDemon;}
    int getNumOfCookie() const {return m_numOfCookie;}
    int getNumOfDoor() const {return m_numOfDoor;}
    int getNumOfKey() const {return m_numOfKey;}
    int getNumOfGift() const {return m_numOfGift;}
    int getTime() const {return m_time;}

    void setLife(int life) { m_life += life;}
    void setScore(int add) {m_score+= add;}
    void setNumOfPacman(int num) {m_numOfPacman+= num;}
    void setNumOfDemon(int num) {m_numOfDemon+= num;}
    void setNumOfCookie(int num) {m_numOfCookie+= num;}
    void setNumOfDoor(int num) {m_numOfDoor+= num;}
    void setNumOfKey(int num) {m_numOfKey+= num;}
    void setNumOfGift(int num){ m_numOfGift+= num;}
    void setTime(int time) {m_time+= time;}

private:
    int m_life        = 3;
    int m_score       = 0;
    int m_numOfDemon  = 0;
    int m_numOfCookie = 0;
    int m_numOfDoor   = 0;
    int m_numOfKey    = 0;
    int m_numOfPacman = 0;
    int m_numOfGift   = 0;
    int m_time        = 60;
};
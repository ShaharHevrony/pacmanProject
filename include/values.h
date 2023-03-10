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
};

enum Buttons{
    playButton,
    helpButton,
    exitButton,
};

//const std::string PATH = "../../../";
const std::string PATH = "";
const std::string m_names[3] = {"PlayButton.png", "HelpButton.png", "ExitButton.png"};
const std::string imagNames[10] = {"Pacman.png", "Demon.png", "Door.png", "Key.png",
                                   "Wall.png", "cookie.png", "Gift.png"};
const std::string gameBar[4] = {"Level: ","Time: ", "Points: ", "Life: "};

const int WINDOW_HEIGHT = 1068;
const int WINDOW_WIDTH  = 1898;
const int BOARD_WIDTH   = 1100;
const int START_ROW     = 60;
const int START_COL     = 60;

const int MENU_CENTER    = WINDOW_WIDTH / 2;
const int MENU_START_ROW = WINDOW_HEIGHT / 2;
const int MENU_GAP       = 150;
const int MENU_PIC_WIDTH = 420;
const int MENU_PIC_HEIGHT = 133;
const int TILE_SIZE     = 2070;

const int NUM_OF_OBJECTS =  7 ;
const int WALL_S         = '#';
const int PACMAN_S       = 'a';
const int DEMON_S        = '&';
const int DOOR_S         = 'D';
const int KEY_S          = '%';
const int COOKIE_S       = '*';
const int GIFT_S         = '$';

const int INC = 1;
const int DEC = -1;

class Values {
public:
    int getLife() const {return m_life;}
    int getScore() const {return m_score;}
    int getLevel() const {return m_level;}
    int getNumOfDemon() const {return m_numOfDemon;}
    int getNumOfCookie() const {return m_numOfCookie;}
    int getNumOfGift() const {return m_numOfGift;}
    int getTime() const {return m_time;}

    void setLife(int life) { m_life += life;}
    void setScore(int score) {m_score+= score;}
    void resetScore() { m_score = 0; }
    void setLevel(int level) {m_level+= level;}
    void setNumOfPacman(int num) {m_numOfPacman+= num;}
    void setNumOfDemon(int num) {m_numOfDemon+= num;}
    void setNumOfCookie(int num) {m_numOfCookie+= num;}
    void setNumOfDoor(int num) {m_numOfDoor+= num;}
    void setNumOfKey(int num) {m_numOfKey+= num;}
    void setNumOfGift(int num){ m_numOfGift+= num;}
    void setTime(int time) {m_time+= time;}

    void resetVal(){
         m_life = 3;
         m_score = 0;
         m_level = 1;
         m_numOfDemon = 0;
         m_numOfCookie = 0;
         m_numOfDoor = 0;
         m_numOfKey = 0;
         m_numOfPacman = 0;
         m_numOfGift = 0;
         m_time = 60;
    }

private:
    int m_life        = 3;
    int m_score       = 0;
    int m_level       = 1;
    int m_numOfDemon  = 0;
    int m_numOfCookie = 0;
    int m_numOfDoor   = 0;
    int m_numOfKey    = 0;
    int m_numOfPacman = 0;
    int m_numOfGift   = 0;
    int m_time        = 60;
};
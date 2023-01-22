//
// Created by Shahar Hevrony on 29/12/2022.
//
#include <thread>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <SFML/Graphics.hpp>

#include <dynamicObject/pacman.h>
#include <dynamicObject/demon.h>

#include <staticObject/key.h>
#include <staticObject/cookie.h>
#include <staticObject/door.h>
#include <staticObject/wall.h>
#include <staticObject/gift/gift.h>

#include "board.h"

//constructor that put in the default member and load the sprites
Board::Board(Values& val) :m_row(0), m_col(0) ,m_boardWidth(0), m_boardHight(0), m_val(val) {
    //load the level from a file is exist
    if (std::filesystem::exists("Board.txt")) {
        std::ifstream m_boardFile;
        m_boardFile.open("Board.txt");
        if (!m_boardFile) {
            exit(EXIT_FAILURE);
        }
        int i = 1;
        while (i != m_val.getLevel()) {
            m_boardFile >> m_row >> m_col;
            m_boardFile.get();
            std::string str;
            for (int height = 0; height < m_row; height++) {
                std::getline(m_boardFile, str);
            }
            m_boardFile.get();
            i++;
        }
        m_map.clear();
        m_boardFile >> m_row >> m_col;
        m_boardFile.get();
        m_map = std::vector<std::string>(m_row);

        //load from the file to the str
        for (int row = 0; row < m_row; row++) {
            std::string tempStr;
            std::getline(m_boardFile, tempStr);
            m_map[row] = tempStr;
        }

        if (m_boardFile.eof()) {
            m_endAllLevel = true;
        }
        //m_boardFile.get(); //skip the \n
        createBoard();
        m_boardFile.close();
    }
}


//function that creat the board
void Board::createBoard(){
    m_objects.clear();
    m_matrix.clear();
    std::vector<std::vector<sf::RectangleShape>> tempMatrix;
    m_tileSize = (BOARD_WIDTH - START_ROW * 2) / std::max(m_row, m_col);
    m_boardWidth = m_tileSize * (float)m_col;
    m_boardHight = m_tileSize * (float)m_row;

    //create the board by each rectangle
    m_objects.resize(m_row);
    for (int i = 0; i < m_row; i++) {
        std::vector <sf::RectangleShape> tempRec;
        for (int j = 0; j < m_col; j++) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(m_tileSize, m_tileSize));
            rectangle.setPosition(j * m_tileSize + START_ROW, i * m_tileSize + START_COL);
            //rectangle.setOutlineThickness(0.5);
            rectangle.setOutlineColor(sf::Color(192, 93, 150));
            rectangle.setFillColor(sf::Color(192, 194, 201));
            tempRec.push_back(rectangle);
        }
        tempMatrix.push_back(tempRec);
        m_objects[i].resize(m_col);
    }
    m_matrix = tempMatrix;
}

// function that return the vector
std::vector<sf::RectangleShape> Board::getVector(int index) const{
    return m_matrix[index];
}

//function that return the rectangle
sf::RectangleShape Board::getRectangle(int row, int col) const{
    return m_matrix[row][col];
}

//return the row number
int Board::getRow() const {
    return m_row;
}

//return the col number
int Board::getCol() const {
    return m_col;
}

//return the texter
sf::Texture* Board::getTexture(int index){
    return &m_texture[index];
}

//set row
void Board::setRow(int row) {
    m_row = row;
}

//set col
void Board::setCol(int col) {
    m_col = col;
}

//function that handel the object we click on
void Board::handleObj(int type, sf::Event::MouseButtonEvent& currMove, sf::RenderWindow& window) {
    ResourcesManager reso = ResourcesManager::inctance();
    for (int row = 0; row < m_row; row++) {
        for (int col = 0; col < m_col; col++) {
            //if click on the current rectangle
            if (m_matrix[row][col].getGlobalBounds().contains(window.mapPixelToCoords({ currMove.x, currMove.y }))) {
                //if there is already texture in the rectangle
                if (m_objects[row][col]->getSprite().getTexture() != nullptr) {
                    if ((type == pacman && m_val.getNumOfPacman() != 1) || (type != pacman)) {
                        eraserObj(row, col);
                    }
                }

                switch (type) {
                case pacman: {
                    //if there is no other pacman on the board
                    if (m_val.getNumOfPacman() == 0) {
                        m_objects[row][col] = std::make_unique<Pacman>(&reso.getObject(pacman), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                        m_val.setNumOfPacman(INC);
                    }
                    break;
                }
                case demon: {
                    //put the object on the rectangle
                    m_objects[row][col] = std::make_unique<Demon>(&reso.getObject(demon), m_matrix[row][col].getPosition(),m_tileSize, indexToChar(type), m_val);
                    m_val.setNumOfDemon(INC);
                    break;
                }
                case door: {
                    //put the object on the rectangle
                    m_objects[row][col] = std::make_unique<Door>(&reso.getObject(door), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                    m_val.setNumOfDoor(INC);
                    break;
                }
                case key: {
                    //put the object on the rectangle
                    m_objects[row][col] = std::make_unique<Key>(&reso.getObject(key), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                    m_val.setNumOfKey(INC);
                    break;
                }
                case wall:
                    m_objects[row][col] = std::make_unique<Wall>(&reso.getObject(wall), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                    break;
                case cookie:
                    m_objects[row][col] = std::make_unique<Cookie>(&reso.getObject(cookie), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                    m_val.setNumOfCookie(INC);
                    break;
                case gift: {
                    //put the object on the rectangle
                    m_objects[row][col] = std::make_unique<Gift>(&reso.getObject(gift), m_matrix[row][col].getPosition(), m_tileSize, indexToChar(type), m_val);
                    m_val.setNumOfGift(INC);
                    break;
                }
                case eraser: {
                    break;
                }
                }
            }
        }
    }
}

//function  that erase the object on the current rectangle
void Board::eraserObj(int row, int col){ //FIXME: fix the count of other object on the screen
    //if erase pacman
    if (m_objects[row][col]->getSprite().getTexture() == &m_texture[0]) {
        m_val.setNumOfPacman(DEC);
        //if erase door
    } else if (m_objects[row][col]->getSprite().getTexture() == &m_texture[2]) {
        m_val.setNumOfDoor(DEC);
        //if erase key
    } else if (m_objects[row][col]->getSprite().getTexture() == &m_texture[3]) {
        m_val.setNumOfKey(DEC);
    } else if(m_objects[row][col]->getSprite().getTexture() == &m_texture[5]){
        m_val.setNumOfCookie(DEC);
    }
    //m_objects[row][col] = std::make_unique<Object>(nullptr, m_matrix[row][col].getPosition(), m_tileSize, ' ');
}

//return tile
float Board::getTile() const{
    return m_tileSize;
}

sf::Texture* Board::changeCharToTexture(char c) {
    switch (c) {
        case 'a':
            return &m_texture[pacman];
        case '&':
            return &m_texture[demon];
        case 'D':
            return &m_texture[door];
        case '%':
            return &m_texture[key];
        case '#':
            return &m_texture[wall];
        case '*':
            return &m_texture[cookie];
        case '$':
            return &m_texture[gift];
        default:
            return nullptr;
    }
}

char Board::indexToChar(int index) const{
    switch (index)
    {
        case pacman:
            return 'a';
        case demon:
            return '&';
        case door:
            return 'D';
        case key:
            return '%';
        case wall:
            return '#';
        case cookie:
            return '*';
        case gift:
            return '$';
        default:
            return ' ';
    }
}

Object& Board::getTileObj(int i, int j) const{
    return *m_objects[i][j];
}

float Board::getBoardWidth() const{
    return m_boardWidth;
}

float Board::getBoardHight() const {
    return m_boardHight;
}


std::vector<std::string> Board::getMap(){
    return m_map;
}

bool Board::getEndAllLevels() {
    return m_endAllLevel;
}

void Board::setEndAllLevels() {
    m_endAllLevel = !m_endAllLevel;
}
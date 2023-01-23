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
        while (i != val.getLevel()) {
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
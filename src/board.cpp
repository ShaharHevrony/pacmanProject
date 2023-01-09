//
// Created by Shahar Hevrony on 29/12/2022.
//
#include <thread>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <SFML/Graphics.hpp>
#include "board.h"

//constructor that put in the default member and load the sprites
Board::Board(int level) :m_row(0), m_col(0), m_doorCount(0), m_keyCount(0), m_pacmanCount(0) {
    //loop that load the sprite one by one
    for (int index = 0; index < 10; index++) {
        m_texture[index].loadFromFile(PATH + imagNames[index]);
    }

    if (std::filesystem::exists("Board.txt")) {
        std::ifstream boardFile;
        boardFile.open("Board.txt");
        if (!boardFile){
            exit(EXIT_FAILURE);
        }
        int i = 1;
        while(i != level){
            boardFile >> m_row >> m_col;
            boardFile.get();
            std::string str;
            for (int row = 0; row < m_row; row++) {
                std::getline(boardFile, str);
            }
            boardFile.get();
            i++;
        }
        boardFile >> m_row >> m_col;
        if (m_row == 0 || m_col == 0) {
            std::cout << "Not a valid file, the num of row and col must be grater then 0./n";
        }
        boardFile.get(); //skip the \n
        createBoard();
        LoadFile(boardFile);
        boardFile.close();
    } else {
        //put in the col and row number
        //std::cout << "Enter a row and col numbers:" << std::endl;
        //std::cin >> m_row >> m_col;
        m_col = 10;
        m_row = 10;
        createBoard();
    }
}

void Board::LoadFile(std::ifstream& boardFile) {
    for (int row = 0; row < m_row; row++) {
        for (int col = 0; col < m_col; col++) {
            char type;
            type = boardFile.get();
            if (type != ' ') {
                Object temp;
                temp.setPosition(m_matrix[row][col].getPosition());
                temp.setTexture(changeCharToTexture(type));
                temp.setSprite(sf::Sprite(*temp.getTexture()));
                temp.setType(type);
                m_objects[row][col] = temp;
                std::cout << "**in LoadFile, type = " << type << " and the position: ("
                << temp.getPosition().x  << "," << temp.getPosition().y  << ")" << std::endl;
                if (type == 'a') {
                    m_pacmanCount++;
                    m_pacman = (DynamicObject *)(&temp);
                } else if (type == '%') {
                    m_keyCount++;
                } else if (type == 'D') {
                    m_doorCount++;
                } else if (type == '*'){
                    m_cookieCount++;
                } else if (type == '&'){
                    m_demonCount++;
                }
            }
        }
        boardFile.get(); //skip the \n
    }
}

//function that creat the board
void Board::createBoard(){
    m_objects.clear();
    m_matrix.clear();
    std::vector<std::vector<sf::RectangleShape>> tempMatrix;
    m_tileSize = (BOARD_WIDTH - START_ROW * 2) / std::max(m_row, m_col);

    m_objects.resize(m_row);
    //create the board by each rectangle
    for (int i = 0; i < m_row; i++) {
        std::vector <sf::RectangleShape> tempRec;
        for (int j = 0; j < m_col; j++) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(m_tileSize, m_tileSize));
            rectangle.setPosition(j * m_tileSize + START_ROW, i * m_tileSize + START_COL);
            rectangle.setOutlineThickness(1);
            rectangle.setOutlineColor(sf::Color(85, 93, 80));
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

//set object
void Board::setTileObj(int row, int col, Object object){
    m_objects[row][col] = object;
}

//function that handel the object we click on
void Board::handleObj(int index, sf::Event::MouseButtonEvent& currMove, sf::RenderWindow& window){
    for (int row = 0; row < m_row; row++) {
        for (int col = 0; col < m_col; col++) {
            //if click on the current rectangel
            if(m_matrix[row][col].getGlobalBounds().contains(window.mapPixelToCoords({ currMove.x, currMove.y}))){
                Object temp;
                temp.setPosition(m_matrix[row][col].getPosition());
                temp.setTexture(&m_texture[index]);
                temp.setSprite(sf::Sprite(*temp.getTexture()));
                temp.setType(indexToChar(index));

                //if there is already texture in the rectangle
                if (m_objects[row][col].getTexture() != NULL) {
                    if (index == pacman && m_pacmanCount != 1) {
                        eraserObj(row, col);
                    } else if (index != pacman) {
                        eraserObj(row, col);
                    }
                }
                switch (index) {
                    case pacman: {
                        //if there is no other pacman on the board
                        if (m_pacmanCount == 0) {
                            m_objects[row][col] = temp;
                            m_pacmanCount++;
                        }
                        break;
                    }
                    case demon: {
                        //put the object on the rectangle
                        m_objects[row][col] = temp;
                        break;
                    }
                    case door: {
                        //put the object on the rectangle
                        m_objects[row][col] = temp;
                        m_doorCount++;
                        break;
                    }
                    case key: {
                        //put the object on the rectangle
                        m_objects[row][col] = temp;
                        m_keyCount++;
                        break;
                    }
                    case wall:
                    case cookie:
                    case gift: {
                        //put the object on the rectangle
                        m_objects[row][col] = temp;
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
//return the object
std::vector<std::vector<Object>> Board::getObj(){
    return m_objects;
}

sf::Texture* Board::getTextureObj(int i, int j) const {
    return m_objects[i][j].getTexture();
}

//function  that earase the object on the current rectangel
void Board::eraserObj(int row, int col){
    //if earese pacman
    if (m_objects[row][col].getTexture() == &m_texture[0]) {
        m_pacmanCount--;
        //if earese door
    } else if (m_objects[row][col].getTexture() == &m_texture[2]) {
        m_doorCount--;
        //if earese key
    } else if (m_objects[row][col].getTexture() == &m_texture[3]) {
        m_keyCount--;
    } else if(m_objects[row][col].getTexture() == &m_texture[5]){
        m_cookieCount--;
    }
    m_objects[row][col].setPosition(sf::Vector2f(INT_MAX, INT_MAX));
    m_objects[row][col].setTexture(NULL);
}

//return tile
float Board::getTile() const{
    return m_tileSize;
}

//return pacman count
int Board::getPacmanCount() const{
    return m_pacmanCount;
}

//return door count
int Board::getDoorCount() const{
    return m_doorCount;
}

//return key count
int Board::getKeyCount() const{
    return m_keyCount;
}

int Board::getCookieCount() const{
    return m_cookieCount;
}

int Board::getDemonCount() const{
    return m_demonCount;
}

//set pacman count
void Board::setPacmanCount() {
    m_pacmanCount = 0;
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
            return NULL;
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

Object Board::getTileObj(int i, int j) const {
    return m_objects[i][j];
}

DynamicObject* Board::getPacman() const {
    return m_pacman;
}

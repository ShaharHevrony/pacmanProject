#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "object.h"
#include "values.h"
#include "dynamicObject.h"
#include "staticObject.h"
#include "resourcesManager.h"
#include "dynamicObject/pacman.h"

class Board {
public:

    //constructor that put in the default member and load the sprites
    Board(Values& val);
   
    //function that creat the board
    void createBoard();

    //function that return the vector
    std::vector<sf::RectangleShape> getVector(int index) const;

    //function that return the rectangle
    sf::RectangleShape getRectangle(int row, int col) const;

    //function that return the texter
    sf::Texture* getTexture(int index);

    //return the row number
    int getRow() const;

    //return the col number
    int getCol() const;

    //set row
    void setRow(int row);

    //sset col
    void setCol(int col);

    //return tile
    float getTile() const;

    float getBoardWidth() const;

    float getBoardHight() const;

    sf::Texture* changeCharToTexture(char c);

    char indexToChar(int index) const;

    Object& getTileObj(int i, int j) const;

    std::vector<std::string> getMap();

    bool getEndAllLevels() const;

    void setEndAllLevels();

private:
    int m_row;

    int m_col;

    bool  m_endAllLevel = false;

    float m_tileSize;

    float m_boardWidth;

    float m_boardHight;

    std::vector<std::string> m_map;

    std::vector<std::vector<sf::RectangleShape>> m_matrix;

    std::vector<std::vector<std::unique_ptr<Object>>> m_objects;

    sf::Texture m_texture[10];

    sf::RenderWindow* m_window;

    Values m_val;

};

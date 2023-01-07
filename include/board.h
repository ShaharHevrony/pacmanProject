#pragma once
#include <SFML/Graphics.hpp>
#include "object.h"
#include "values.h"
#include "dynamicObject.h"
class Board {
public:
    //constructor that put in the defulte member and load the sprites
    Board(int level);

    void LoadFile(std::ifstream& boardFile);

    //function that creat the board
    void create();

    // function that return the vector
    std::vector<sf::RectangleShape> getVector (int index) const;

    //function that return the rectangle
    sf::RectangleShape getRectangle (int row, int col) const;

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

    //set object
    void setObj(Object obj);

    //function that handel the object we click on
    void handleObj(int index, sf::Event::MouseButtonEvent& currMove, sf::RenderWindow& window);

    //return the object
    std::vector<std::vector<Object>> getObj();

    sf::Texture* getTextureObj(int i, int j) const;

    //function  that earase the object on the current rectangel
    void eraserObj(int row, int col);

    //return tile
    float getTile() const;

    //return pacman count
    int getPacmanCount() const;

    //return door count
    int getDoorCount() const;

    //return key count
    int getKeyCount() const;

    int getCookieCount() const;

    //set pacman count to zero
    void setCountPac();

    sf::Texture* changeCharToTexture(char c);

    char indexToChar(int index) const;

    int charToIndex(char c) const;

    Object getTileObj(int i, int j) const;

    char getObject (int x, int y) const;

    DynamicObject* getPacman() const;
private:
    int m_row;

    int m_col;

    int m_pacmanCount;

    int m_doorCount;

    int m_keyCount;

    int m_cookieCount;

    float m_tileSize;

    DynamicObject* m_pacman;

    std::vector<std::vector<sf::RectangleShape>> m_matrix;

    std::vector<std::vector<Object>> m_objects;

    sf::Texture m_texture[10];
};

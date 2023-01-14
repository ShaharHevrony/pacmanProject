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
    Board();

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

    //set object
    void setTileObj(int row, int col, char type);

    //function that handel the object we click on
    void handleObj(int index, sf::Event::MouseButtonEvent& currMove, sf::RenderWindow& window);

    //function  that erase the object on the current rectangle
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

    int getDemonCount() const;

    float getBoardWidth() const;

    float getBoardHight() const;

    //set pacman count to zero
    void setPacmanCount();

    void setCookieCount();

    sf::Texture* changeCharToTexture(char c);

    char indexToChar(int index) const;

    Object& getTileObj(int i, int j) const;

    //DynamicObject* getPacman() const;

    std::vector<std::string> getMap();

    std::vector<std::vector<sf::RectangleShape>> getMatrix();


private:
    int m_row;

    int m_col;

    float m_tileSize;

    float m_boardWidth;

    float m_boardHight;

    int m_pacmanCount;

    int m_doorCount;

    int m_keyCount;

    int m_demonCount;

    int m_cookieCount;


    std::vector<std::string> m_map;

    Pacman* m_pacman;

    ResourcesManager* m_reso;

    std::vector<std::vector<sf::RectangleShape>> m_matrix;

    std::vector<std::vector<std::unique_ptr<Object>>> m_objects;

    sf::Texture m_texture[10];

    sf::RenderWindow* m_window;

};

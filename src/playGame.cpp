//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "playGame.h"
#include "values.h"
#include <SFML/Graphics.hpp>

PlayGame::PlayGame(sf::RenderWindow& window):m_window(&window), m_catchCookie(0), m_score(0), m_level(1), m_life(3){
    m_key = new Keyboard(window);
}

void PlayGame::play() {
    for (m_level; m_level <= 1; m_level++){ //FIXME: num of levels is not set.
        //if i'm still alive then:
        if (m_life > 0){
            playLevel();
        } else{
            gameOver();
        }
    }
}

void PlayGame::playLevel() {
    m_board = new Board(m_level);
    //make a board
    print();
    m_window->display();
    bool endLevel = false;
    //loop that control the game until the end
    while(!endLevel){
        //get the direction from the user
        int direction = m_key->getKey();
        //check if the direction is valid

        while (!validKey(direction) ||(direction != sf::Keyboard::Space && !validMove(direction))){
            direction = m_key->getKey();
        }

        //if the user decided to skip his turn
        if (direction != sf::Keyboard::Space) {
            m_board->getPacman()->setNextPosition(direction);
            int nextRow = m_board->getPacman()->getNextRow();
            int nextCol = m_board->getPacman()->getNextCol();

            //Save the sprite and the texture to do swap
            sf::Texture* currTexture = m_board->getTileObj(m_board->getPacman()->getRow(),
                                                          m_board->getPacman()->getCol()).getTexture();
            sf::Sprite currSprite = m_board->getTileObj(m_board->getPacman()->getRow(),
                                                         m_board->getPacman()->getCol()).getSprite();
            char currType = m_board->getTileObj(m_board->getPacman()->getRow(),
                                                m_board->getPacman()->getCol()).getType();
            sf::Texture* nextTexture = m_board->getTileObj(m_board->getPacman()->getNextRow(),
                                                           m_board->getPacman()->getNextCol()).getTexture();
            sf::Sprite nextSprite = m_board->getTileObj(m_board->getPacman()->getNextRow(),
                                                        m_board->getPacman()->getNextCol()).getSprite();
            char nextType = m_board->getTileObj(m_board->getPacman()->getNextRow(),
                                                m_board->getPacman()->getNextCol()).getType();
            //Swap
            Object currTemp = m_board->getTileObj(m_board->getPacman()->getRow(), m_board->getPacman()->getCol());
            currTemp.setTexture(nextTexture);
            currTemp.setSprite(nextSprite);
            currTemp.setType(currType);
            m_board->setTileObj(m_board->getPacman()->getRow(), m_board->getPacman()->getCol(), currTemp);
            Object nextTemp = m_board->getTileObj(m_board->getPacman()->getNextRow(), m_board->getPacman()->getNextCol());
            nextTemp.setTexture(currTexture);
            nextTemp.setSprite(currSprite);
            currTemp.setType(nextType);

            m_board->setTileObj(m_board->getPacman()->getNextRow(), m_board->getPacman()->getNextCol(), nextTemp);

            //Change position of m_pacman
            m_board->getPacman()->setPosition(m_board->getTileObj(nextRow, nextCol).getPosition());
            m_board->getPacman()->setRow(nextRow);
            m_board->getPacman()->setCol(nextCol);

            if (comparePosition()) {
                /*
                char symbol = deleteObject(((Object *) m_board->getPacman())->getPosition());
                if (symbol != SPACE_S) {
                    //respondToSymbol(symbol); //FIXME
                }
                */
                //print the new board

                print();
                m_window->display();
                //if the pacman ate all the cookies
                if (m_catchCookie == m_board->getCookieCount()) {
                    endLevel = true;
                    break;
                }
            }
        }
    }
}

void PlayGame::gameOver() {

}

char PlayGame::deleteObject(sf::Vector2f position) {
    char type = SPACE_S;
    Object temp = m_board->getTileObj(position.x, position.y);
    if(temp.getPosition().y == position.y && temp.getPosition().x == position.x) {
        if (temp.getType() != DOOR_S) {
            type = temp.getType();
            temp.setTexture(NULL);
            temp.setType(SPACE_S);
            return type;
        } else if(((Object *)m_board->getPacman())->getType() == SUPER_PACMAN_S) {
            type = temp.getType();
            temp.setTexture(NULL);
            temp.setType(SPACE_S);
            return type;
        }
    }
    return type;
}

bool PlayGame::validKey(int key) const {
    return (key == sf::Keyboard::Space || key == sf::Keyboard::Up || key == sf::Keyboard::Down
            || key == sf::Keyboard::Left || key == sf::Keyboard::Right);
}

void PlayGame::print() {
    sf::Texture backgroundTexture;
    backgroundTexture = m_reso->getTextureBack();
    sf::Sprite backgroundSprite;
    backgroundSprite = m_reso->getbackground();
    m_window->draw(backgroundSprite);

    for (int i = 0; i < m_board->getRow(); i++) {
        for (int j = 0; j < m_board->getCol(); j++) {
            m_window->draw(m_board->getRectangle(i, j));
        }
    }

    std::vector<std::vector<Object>> object = m_board->getObj();
    float tileSize = m_board->getTile();
    tileSize /= TILE_SIZE;
    //draw the sprite
    for (int row = 0; row < object.size(); row++) {
        for (int col = 0; col < object[row].size(); col++) {
            auto sprite = object[row][col].getSprite();
            sprite.setScale(tileSize, tileSize);
            sprite.setPosition(object[row][col].getPosition());
            m_window->draw(sprite);
        }
    }

    sf::Font font;
    font.loadFromFile(PATH + "HappyMonkey.ttf");
    sf::Text text("play", font, MENU_TEXT_SIZE-20);
    text.setFillColor(sf::Color(500, 160, 28));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(600, 100, 28));
    text.setPosition(1000, 20);
    m_window->draw(text);
}

bool PlayGame::comparePosition() {
    float checkRow = m_board->getPacman()->getRow();
    float checkCol = m_board->getPacman()->getCol();
    if(m_board->getTileObj(checkRow, checkCol).getType() == DEMON_S){
        return false;
    }
    return true;
}

void PlayGame::demonMove() {
    for (int i = 0; i < m_board->getRow(); i++) {
        for (int j = 0; j < m_board->getCol(); j++) {
            if(m_board->getTileObj(i, j).getType() == DEMON_S){
                //FIXME: demon algorithm
            }
        }
    }
    print();
}

bool PlayGame::validMove(int direction){
    //check what is in the next location
    m_board->getPacman()->setNextPosition(direction);
    int nextRow = m_board->getPacman()->getNextRow();
    int nextCol = m_board->getPacman()->getNextCol();

    if(nextRow >=0 && nextRow <= m_board->getRow() && nextCol >= 0 && nextCol <= m_board->getCol()
        && m_board->getTileObj(nextRow, nextCol).getType() == SPACE_S){
        return true;
    }else {
        return false;
    }
}
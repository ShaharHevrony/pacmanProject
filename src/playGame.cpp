//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "playGame.h"
#include "values.h"
#include <SFML/Graphics.hpp>

PlayGame::PlayGame(sf::RenderWindow& window):m_window(&window), m_catchCookie(0), m_score(0), m_level(1), m_life(3){
    m_reso = new ResourcesManager();
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
    bool endLevel = false;
    //loop that control the game until the end
    while(!endLevel){
        //get the direction from the user
        int direction = m_key->getKey();

        //check if the direction is valid
        while (!validKey(direction) || !validMove(direction)){
            direction = m_key->getKey();
        }

        //if the user decided to skip his turn
        if (direction != sf::Keyboard::Space) {
            m_board->getPacman()->setNextPosition(direction);
            int row = m_board->getPacman()->getRow();
            int col = m_board->getPacman()->getCol();
            int nextRow = m_board->getPacman()->getNextRow();
            int nextCol = m_board->getPacman()->getNextCol();

            //Save the sprite and the texture to do swap
            sf::Sprite nextSprite = m_board->getTileObj(nextRow,nextCol).getSprite();

            //Swap
            Object* pacman = (Object*)m_board->getPacman();
            Object nextTemp = m_board->getTileObj(nextRow, nextCol);
            Object currTemp = m_board->getTileObj(row, col);

            pacman->getSprite().setPosition(m_board->getTileObj(nextRow, nextCol).getSprite().getPosition());

            m_board->setTileObj(row, col, nextTemp.getType());
            m_board->setTileObj(nextRow, nextCol, pacman->getType());

            nextTemp.setSprite(pacman->getSprite());
            currTemp.setSprite(nextSprite);

            currTemp.setType(m_board->getTileObj(nextRow,nextCol).getType());
            nextTemp.setType(pacman->getType());

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

/*
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
*/
bool PlayGame::validKey(int key) const {
    return (key == sf::Keyboard::Space || key == sf::Keyboard::Up || key == sf::Keyboard::Down
            || key == sf::Keyboard::Left || key == sf::Keyboard::Right);
}

void PlayGame::print() {
    m_window->clear();

    sf::Sprite backgroundSprite;
    backgroundSprite = m_reso->getbackground();
    m_window->draw(backgroundSprite);

    for (int i = 0; i < m_board->getRow(); i++) {
        for (int j = 0; j < m_board->getCol(); j++) {
            m_window->draw(m_board->getRectangle(i, j));
        }
    }

    float tileSize = m_board->getTile();
    tileSize /= TILE_SIZE;
    //draw the sprite
    for (int row = 0; row < m_board->getRow(); row++) {
        for (int col = 0; col < m_board->getCol(); col++) {
            Object& temp = m_board->getTileObj(row, col);
            if(temp.getType() != PACMAN_S){
                temp.getSprite().setScale(tileSize, tileSize);
                m_window->draw(temp.getSprite());
            } else {
                m_board->getPacman()->getSprite().setScale(tileSize, tileSize);
                m_window->draw(m_board->getPacman()->getSprite());
            }
        }
    }

    sf::Font font;
    font = m_reso->getFont();
    sf::Text text("play", font, MENU_TEXT_SIZE-20);
    text.setFillColor(sf::Color(500, 160, 28));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(600, 100, 28));
    text.setPosition(1000, 20);
    m_window->draw(text);
    m_window->display();
}

bool PlayGame::comparePosition() {
    int checkRow = m_board->getPacman()->getRow();
    int checkCol = m_board->getPacman()->getCol();
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
}

bool PlayGame::validMove(int direction){
    //check what is in the next location
    m_board->getPacman()->setNextPosition(direction);
    int nextRow = m_board->getPacman()->getNextRow();
    int nextCol = m_board->getPacman()->getNextCol();

    //float nextPositionX = m_board->getPacman()->getNextPosition().x;
    //float nextPosotionY = m_board->getPacman()->getNextPosition().y;

    /*
    if(nextRow >=0 && nextRow <= m_board->getBoardHight() && nextCol >= 0 && nextCol <= m_board->getBoardWidth()
       && m_board->getTileObj(nextRow, nextCol).getType() == SPACE_S){
        return true;
    }else {
        return false;
    }
     */

    if(nextRow >=0 && nextRow <= m_board->getRow() && nextCol >= 0 && nextCol <= m_board->getCol()
        && m_board->getTileObj(nextRow, nextCol).getType() == SPACE_S){
        return true;
    }else {
        return false;
    }
}
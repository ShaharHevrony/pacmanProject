//
// Created by Shahar Hevrony on 29/12/2022.
//
/*
#include "playGame.h"
#include "values.h"
#include <SFML/Graphics.hpp>

PlayGame::PlayGame():m_catchCookie(0), m_score(0), m_level(1), m_life(3),m_key() {}

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
    //loop that go on each level
    //make a board
    //print(); //FIXME: print the level
    bool endLevel = false;
    //loop that control the game until the end
    while(!endLevel){
        //get the direction from the user
        int direction = m_key->getKey();
        //check if the direction is valid
        while (!validKey(direction) ||
            (direction != sf::Keyboard::Space && !m_board->getPacman()->validMove(direction))){
            direction = m_key->getKey();
        }

        //if the user decided to skip his turn
        if (direction != SKIP_TURN) {
            m_board->getPacman()->changeLocation(direction);
            //if the pacman and demon on the same cell
            if (compareLocation()){
                char symbol = deleteObject(((Object *)m_board->getPacman())->getPosition());
                if (symbol != SPACE_S) {
                    //respondToSymbol(symbol); //FIXME
                }
                //print the new board
                //printLevelData(); //FIXME
                //if the pacman ate all the cookies
                if (m_catchCookie == m_board->getCookieCount()) {
                    endLevel = true;
                    break;
                }
            }
        }
        //function that move all the demon
        demonTurn();
    }
    //m_score += 2*(m_board->demonCount); //FIXME
    //delete the allocate of the old board
    delete m_board;
    m_catchCookie = 0;
    m_score += 50;
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
*/
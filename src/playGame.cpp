//
// Created by Shahar Hevrony on 29/12/2022.
//

#include "playGame.h"
#include "values.h"
#include <SFML/Graphics.hpp>

#include <dynamicObject/pacman.h>
#include <dynamicObject/demon.h>

#include <staticObject/key.h>
#include <staticObject/cookie.h>
#include <staticObject/door.h>
#include <staticObject/wall.h>
#include <staticObject/gift/gift.h>

PlayGame::PlayGame(sf::RenderWindow& window) :m_window(&window), m_catchCookie(0), m_score(0), m_level(1), m_life(3) {
    m_board = new Board();
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
    //make a board
    LoadFile(m_board->getMap());
    print();
    bool endLevel = false;
    sf::Clock timer;
    while (m_window->isOpen()) {
        if (auto event = sf::Event{}; m_window->pollEvent(event)) {

            if (sf::Event::Closed) {
                m_window->close();
                break;
            }
        }
        float time = timer.restart().asSeconds();
        for (int i = 0; i < m_dynamicObj.size(); i++) {
            m_dynamicObj[i]->move(time);
        }

        print();

    }
}

/*

    //loop that control the game until the end
    while(!endLevel){
        //get the direction from the user
        int direction = m_key->getKey();

        //if the user decided to skip his turn
        if (direction != sf::Keyboard::Space) {
            m_board->getPacman()->setNextPosition(direction);
            int nextRow = m_board->getPacman()->getNextRow();
            int nextCol = m_board->getPacman()->getNextCol();

            m_board->getPacman()->setRow(nextRow);
            m_board->getPacman()->setCol(nextCol);

            if (comparePosition()) {
                /*
                char symbol = deleteObject(((Object *) m_board->getPacman())->getPosition());
                if (symbol != SPACE_S) {
                    //respondToSymbol(symbol); //FIXME
                }
                

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
*/

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
            //if(temp.getType() != PACMAN_S){
                //temp.getSprite().setScale(tileSize, tileSize);
                //m_window->draw(temp.getSprite());
            // else {
                //m_board->getPacman()->getSprite().setScale(tileSize, tileSize);
                //m_window->draw(m_board->getPacman()->getSprite());
            
        }
    }

    for (int i = 0; i < m_dynamicObj.size(); i++) {
        m_dynamicObj[i]->draw(*m_window);
    }
    for (int i = 0; i < m_staticObj.size(); i++) {
        m_staticObj[i]->draw(*m_window);
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
/*
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

bool PlayGame::validMove(int direction) {
    //check what is in the next location
    m_board->getPacman()->setNextPosition(direction);
    int nextRow = m_board->getPacman()->getNextRow();
    int nextCol = m_board->getPacman()->getNextCol();

    //float nextPositionX = m_board->getPacman()->getNextPosition().x;
    //float nextPosotionY = m_board->getPacman()->getNextPosition().y;


    if (nextRow >= 0 && nextRow <= m_board->getBoardHight() && nextCol >= 0 && nextCol <= m_board->getBoardWidth()
        && m_board->getTileObj(nextRow, nextCol).getType() == SPACE_S) {
        return true;
    }
    else {
        return false;
    }


    if (nextRow >= 0 && nextRow <= m_board->getRow() && nextCol >= 0 && nextCol <= m_board->getCol()
        && m_board->getTileObj(nextRow, nextCol).getType() == SPACE_S) {
        return true;
    }
    else {
        return false;
    }
}*/


void PlayGame::LoadFile(std::vector<std::string> ) {
    float tileSize = m_board->getTile();
    //tileSize /= TILE_SIZE;
    std::vector<std::string> map = m_board->getMap();
    for (int row = 0; row < m_board->getRow(); row++) {
        for (int col = 0; col < m_board->getCol(); col++) {
            auto loc = m_board->getRectangle(row,col);
            char type;
            type = map[row][col];

            switch (type) {
            case PACMAN_S: {
                m_dynamicObj.push_back(std::make_unique<Pacman>(&m_reso->getObject(pacman),loc.getPosition(), tileSize,type));
                break;
            }
            case DEMON_S: {
                m_dynamicObj.push_back(std::make_unique<Demon>(&m_reso->getObject(demon),loc.getPosition(), tileSize, type));
                break;
            }
            case DOOR_S: {
               m_staticObj.push_back(std::make_unique<Door>(&m_reso->getObject(door), loc.getPosition(), tileSize, type));
                break;
            }
            case KEY_S: {
                m_staticObj.push_back( std::make_unique<Key>(&m_reso->getObject(key), loc.getPosition(), tileSize, type));
                break;
            }
            case WALL_S: {
                m_staticObj.push_back(std::make_unique<Wall>(&m_reso->getObject(wall), loc.getPosition(), tileSize, type));
                break;
            }
            case COOKIE_S: {
                m_staticObj.push_back(std::make_unique<Cookie>(&m_reso->getObject(cookie), loc.getPosition(), tileSize, type));
                m_board->setCookieCount();
                break;
            }
            case GIFT_S: {
                m_staticObj.push_back( std::make_unique<Gift>(&m_reso->getObject(gift), loc.getPosition(), tileSize, type));
                break;
            }
            default:
                break;
            }
        }
    }
}
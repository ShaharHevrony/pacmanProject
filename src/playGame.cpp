
#include "playGame.h"
#include "values.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include <dynamicObject/pacman.h>
#include <dynamicObject/demon.h>

#include <staticObject/key.h>
#include <staticObject/cookie.h>
#include <staticObject/door.h>
#include <staticObject/wall.h>
#include <staticObject/gift/gift.h>

PlayGame::PlayGame(sf::RenderWindow& window) : m_window(&window), m_level(1), m_bar(60), m_val() {
    m_board = new Board(m_val);
    m_key   = new Keyboard(window);
}

void PlayGame::play() {
    for (m_level; m_level <= 1; m_level++){ //FIXME: num of levels is not set.
        //if i'm still alive then:
        if (m_val.getLife() > 0){
            playLevel();
        } else{
            gameOver();
        }
    }
}

void PlayGame::playLevel() {
    //int countDelete = 0;
    //make a board
    LoadFile(m_board->getMap());
    print();
    bool endLevel = false;
    sf::Clock timer;
    while (m_window->isOpen()) {
        if (auto event = sf::Event{}; m_window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                m_window->close();
                break;
            }
        }
        float time = timer.restart().asSeconds();
        //move dynamic object
        for (int i = 0; i < m_dynamicObj.size(); i++) {
            m_dynamicObj[i]->move(time, m_dynamicObj[0]->getSprite().getPosition());
        }
        //deal with collision
        for (int i = 0; i < m_dynamicObj.size(); i++) {
            for (int j = 0; j < m_dynamicObj.size(); j++) {
                m_dynamicObj[i]->handleCollision(*m_dynamicObj[j]);
                if(m_dynamicObj[i]->getIsDelete()){
                    m_val.setLife(DEC);
                }
                m_dynamicObj[i]->setDelete();
            }
            for (int j = 0; j < m_staticObj.size(); j++) {
                m_dynamicObj[i]->handleCollision(*m_staticObj[j]);
                if (m_staticObj[j]->getIsDelete()) {
                    if (m_staticObj[j]->getIsDeleteDoor()) {
                        //delete first door
                        deleteFirstDoor();
                        m_val.setNumOfDoor(DEC);
                        m_val.setNumOfKey(DEC);
                        m_val.setScore(7);
                    } else {
                        m_val.setNumOfCookie(DEC);
                        m_val.setScore(2);
                    }
                    m_staticObj[j]->setIsDeleteFalse();
                    //m_staticObj.erase(remove(m_staticObj.begin(),m_staticObj.end(), m_staticObj[j]));
                    //m_staticObj.erase(m_staticObj.begin() + j);
                    //std::remove(m_staticObj.begin(),m_staticObj.end(), m_staticObj[j]);
                    //std::erase_if(m_staticObj, [](const auto& object){return object->getIsDelete();});
                }
            }
        }
        print();
    }
}

void PlayGame::deleteFirstDoor() {
    for (int z = 0; z < m_staticObj.size(); z++) {
        if (m_staticObj[z]->getType() == 'D') {
            //m_staticObj.erase(m_staticObj.begin() + z);
            break;
        }
        m_staticObj[z]->setDeleteDoorFalse();
    }
}

void PlayGame::gameOver() {
    //FIXME;
}

bool PlayGame::validKey(int key) const {
    return (key == sf::Keyboard::Space || key == sf::Keyboard::Up || key == sf::Keyboard::Down
            || key == sf::Keyboard::Left || key == sf::Keyboard::Right);
}

void PlayGame::print() {
    m_window->clear();
    sf::Sprite backgroundSprite;
    backgroundSprite = ResourcesManager::inctance().getBackGround();
    m_window->draw(backgroundSprite);
    
    sf::Texture m_backButtonTexture;
    if (!m_backButtonTexture.loadFromFile(PATH + "backButton.png")) {
        // Error loading image
    }

    sf::Sprite backButtonSprite;
    backButtonSprite.setTexture(m_backButtonTexture);
    backButtonSprite.setPosition(1670, 770);
    backButtonSprite.setScale(0.1, 0.1);

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
        }
    }

    for (int i = 0; i < m_dynamicObj.size(); i++) {
        m_dynamicObj[i]->draw(*m_window);
    }
    for (int i = 0; i < m_staticObj.size(); i++) {
        m_staticObj[i]->draw(*m_window);
    }

    sf::Text text("play", ResourcesManager::inctance().getFont(), MENU_TEXT_SIZE-20);
    text.setFillColor(sf::Color(500, 160, 28));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(600, 100, 28));
    text.setPosition(1000, 20);
    m_window->draw(text);
    m_bar.draw(*m_window, m_val);
    m_window->draw(backButtonSprite);
    m_window->display();
}

void PlayGame::LoadFile(std::vector<std::string> ) {
    float tileSize = m_board->getTile()*0.95;
    //tileSize /= TILE_SIZE;
    std::vector<std::string> map = m_board->getMap();
    ResourcesManager reso = ResourcesManager::inctance();
    for (int row = 0; row < m_board->getRow(); row++) {
        for (int col = 0; col < m_board->getCol(); col++) {
            auto loc = m_board->getRectangle(row,col);
            char type;
            type = map[row][col];

            switch (type) {
            case PACMAN_S: {
                m_dynamicObj.push_back(std::make_unique<Pacman>(&reso.getObject(pacman),loc.getPosition(), tileSize*0.75,type));
                if (m_dynamicObj.size() != 0) {
                    m_dynamicObj[0].swap((m_dynamicObj[m_dynamicObj.size()-1]));
                    m_pacLocation = loc.getPosition();
                }
                m_val.setNumOfPacman(INC);
                break;
            }
            case DEMON_S: {
                m_dynamicObj.push_back(std::make_unique<Demon>(&reso.getObject(demon),loc.getPosition(), tileSize, type));
                m_val.setNumOfDemon(INC);
                break;
            }
            case DOOR_S: {
                m_staticObj.push_back(std::make_unique<Door>(&reso.getObject(door), loc.getPosition(), tileSize, type));
                m_val.setNumOfDoor(INC);
                break;
            }
            case KEY_S: {
                m_staticObj.push_back(std::make_unique<Key>(&reso.getObject(key), loc.getPosition(), tileSize, type));
                m_val.setNumOfKey(INC);
                break;
            }
            case WALL_S: {
                m_staticObj.push_back(std::make_unique<Wall>(&reso.getObject(wall), loc.getPosition(), tileSize, type));
                break;
            }
            case COOKIE_S: {
                m_staticObj.push_back(std::make_unique<Cookie>(&reso.getObject(cookie), loc.getPosition(), tileSize, type));
                m_val.setNumOfCookie(INC);
                break;
            }
            case GIFT_S: {
                m_staticObj.push_back( std::make_unique<Gift>(&reso.getObject(gift), loc.getPosition(), tileSize, type));
                break;
            }
            default:
                break;
            }
        }
    }
}
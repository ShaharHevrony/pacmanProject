#pragma once
#include "keyBoard.h"
#include "values.h"
#include "board.h"

class PlayGame {
public:
    PlayGame(sf::RenderWindow& window);

    void play();

    void print();

    char deleteObject(sf::Vector2f position);

    void demonTurn();

    bool compareLocation();

    void reloadLevel();

    void playLevel();

    void gameOver();

    bool validKey(int key) const;

private:
    int m_level;

    int m_score;

    int m_life;

    int m_catchCookie;

    Board* m_board;

    sf::RenderWindow* m_window;

    DynamicObject* m_pacman;

    Keyboard* m_key;
};


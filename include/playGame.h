#pragma once
#include "keyBoard.h"
#include "values.h"
class PlayGame {
public:
    PlayGame();

    void play();

    void demonTurn();

    bool validMove(int direction, Location location, char symbol);

    Location changePosition(int direction, Location location);

    bool compareLocation();

    void reloadLevel();

    void playLevel();

    void gameOver();

    bool validKey(int key) const;

private:
    int m_level;

    int m_score;

    int m_life ;

    int m_catchCookie;

    //Board* m_board;

    Keyboard* m_key;
};


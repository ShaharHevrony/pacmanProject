#pragma once
#include "keyBoard.h"
#include "values.h"
#include "board.h"
#include "resourcesManager.h"

class PlayGame {
public:
    PlayGame(sf::RenderWindow& window);

    void play();

    void print();

    char deleteObject(sf::Vector2f position);

    void demonMove();

    bool comparePosition();

    void respondToSymbol(char symbol);

    void reloadLevel();

    void playLevel();

    void gameOver();

    bool validKey(int key) const;

    void LoadFile(std::vector<std::string>);

    bool validMove(int direction);

    void deleteFirstDoor();


private:
    int m_level;

    int m_score;

    int m_life;

    int m_catchCookie;

    BoardLimits m_boardLimits;

    Cookie *m_cookie;

    std::vector<std::unique_ptr<StaticObject>> m_staticObj;

    std::vector<std::unique_ptr<DynamicObject>> m_dynamicObj;

    Board* m_board;

    sf::RenderWindow* m_window;

    ResourcesManager* m_reso;

    Keyboard* m_key;

    sf::Vector2f m_pacLocation;
};


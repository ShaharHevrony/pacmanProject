#pragma once
#include <vector>
#include <memory>

#include "keyBoard.h"
#include "values.h"
#include "board.h"
#include "resourcesManager.h"
#include "bar.h"
class PlayGame {
public:
    PlayGame(sf::RenderWindow& window);

    void play();

    void print();

    void playLevel();

    void gameOver();

    bool validKey(int key) const;

    void LoadFile(std::vector<std::string>);

    void deleteFirstDoor();

    int getLife() const;

    void setLife(int life);

    void dealWithCollision();


private:
    int m_level;

    BoardLimits m_boardLimits;

    Cookie *m_cookie;

    std::vector<std::unique_ptr<StaticObject>> m_staticObj;

    std::vector<std::unique_ptr<DynamicObject>> m_dynamicObj;

    Board* m_board;

    sf::RenderWindow* m_window;

    Bar m_bar;

    Keyboard* m_key;

    sf::Vector2f m_pacLocation;

    Values m_val;
};

